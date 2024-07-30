const decimalDigits = /\d+/;
const hexDigits = /[\da-fA-F]+/;
const binaryDigits = /[01]+/;

const PREC = {
  binary_assign: 10, // =
  binary_assign_by_bitwise_or: 10, // |=
  binary_assign_by_bitwise_xor: 10, // ^=
  binary_assign_by_bitwise_and: 10, // &=
  binary_assign_by_shift_right: 10, // >>=
  binary_assign_by_shift_left: 10, // <<=
  binary_assign_by_subtract: 10, // -=
  binary_assign_by_add: 10, // +=
  binary_assign_by_multiply: 10, // *=
  binary_assign_by_rotate_right: 11, // >=>,
  binary_assign_by_rotate_left: 12, // <=<
  binary_logical_or: 19, // ||
  binary_logical_and: 20, // &&
  binary_not_equal_to: 21, // !=
  binary_equal_to: 21, // ==
  binary_greater_than_or_equal: 22, // >=
  binary_greater_than: 22, // >
  binary_less_than_or_equal: 22, // <=
  binary_less_than: 22, // <
  binary_bitwize_or: 23, // |
  binary_bitwise_xor: 24, // ^
  binary_bitwise_and: 25, // &
  binary_shift_right: 26, // >>
  binary_shift_left: 26, // <<
  binary_rotate_right: 27, // >->
  binary_rotate_left: 28, // <-<
  binary_subtract: 29, // -
  binary_add: 29, // *
  binary_multiply: 30, // *
  unary_logical_not: 32, // !
  unary_bitwise_not: 32, // ~
  unary_negate: 32, // -
  unary_plus: 32, // +
  unary_hardware_address: 32, //&
  unary_pointer: 36, // @
  call: 40,
  subscript: 41,
};

module.exports = grammar({
  name: "nesfab",

  extras: ($) => [$.comment, $.line_continuation, /\s|\r?\n/],
  inline: ($) => [],
  conflicts: ($) => [
    [$.expression, $.typed_element_array_type],
    [$.data_definition],
    [$.file_expression],
  ],
  externals: ($) => [$._indent, $._dedent, $._newline],
  word: ($) => $.identifier,
  supertypes: ($) => [],

  rules: {
    module: ($) => repeat($._statement),

    identifier: (_) => /[_\p{XID_Start}][_\p{XID_Continue}]*/,
    group_identifier: ($) => seq("/", $.identifier),
    _statement: ($) => choice($._simple_statements, $._compound_statement),

    _simple_statements: ($) => seq($._simple_statement, $._newline),
    _simple_statement: ($) =>
      choice(
        $.expression,
        $.break_statement,
        $.continue_statement,
        $.goto_statement,
        $.return_statement,
        $.swap_statement,
        $.fence_statement,
        $.nmi_statement,
        $.irq_statement,
        $.write,
        $.hardware_write,
      ),
    _compound_statement: ($) =>
      choice(
        $.variable_definition,
        $.struct_definition,
        $.vars_definition,
        $.data_definition,
        $.charmap_definition,
        $.function_definition,
        $.if_statement,
        $.while_statement,
        $.for_statement,
        $.switch_statement,
        $.goto_mode_statement,
        $.label_statement,
        $.chrrom_definition,
      ),

    break_statement: (_) => "break",
    continue_statement: (_) => "continue",
    goto_statement: ($) => seq("goto", $.identifier),
    return_statement: ($) => seq("return", optional($.expression)),
    swap_statement: ($) => seq("swap", $.identifier, ",", $.identifier),
    fence_statement: (_) => "fence",
    nmi_statement: (_) => "nmi",
    irq_statement: ($) => seq("irq", optional($.boolean_literal)),

    // expression
    expression: ($) =>
      choice(
        $.identifier,
        $.boolean_literal,
        $.numeric_literal,
        $.character_literal,
        $.string_literal,
        $.system_literal,
        $.ppu_literal,
        $.parenthesized_expression,
        $.unary_operator,
        $.binary_operator,
        $.comparison_operator,
        $.assignment,
        $.augumented_assignment,
        $.member_access,
        $.u_indexed_subscript,
        $.uu_indexed_subscript,
        $.call,
        $.sizeof_expression,
        $.len_expression,
        $.abs_expression,
        $.minmax_expression,
        $.type_cast_or_initialization,
        $.banked_pointer_initialization,
        $.read,
        $.hardware_read,
        $.ready,
        $.nmi_counter,
        $.file_expression,
        $.macro_expression,
        $.mapfab_expression,
        $.audio_expression,
      ),

    // literals
    boolean_literal: (_) => token(choice("true", "false")),
    numeric_literal: (_) => {
      const decimalLiteral = seq(
        optional(choice("-", "+")),
        choice(
          seq(optional(decimalDigits), ".", decimalDigits),
          seq(decimalDigits, ".", optional(decimalDigits)),
          decimalDigits,
        ),
      );
      const hexLiteral = seq(
        "$",
        choice(
          seq(optional(hexDigits), ".", hexDigits),
          seq(hexDigits, ".", optional(hexDigits)),
          hexDigits,
        ),
      );
      const binaryLiteral = seq(
        "%",
        choice(
          seq(optional(binaryDigits), ".", binaryDigits),
          seq(binaryDigits, ".", optional(binaryDigits)),
          binaryDigits,
        ),
      );

      return token(choice(decimalLiteral, binaryLiteral, hexLiteral));
    },
    character_literal: ($) =>
      seq("'", choice(token.immediate(/[^'\\]+/), $.escape_sequence), "'"),
    string_literal: ($) =>
      choice($.double_quoted_string, $.backtick_quoted_string),
    double_quoted_string: ($) =>
      seq(
        '"',
        repeat(choice(token.immediate(/[^"\\]+/), $.escape_sequence)),
        '"',
      ),
    backtick_quoted_string: ($) =>
      seq(
        "`",
        repeat(choice(token.immediate(/[^`\\]+/), $.escape_sequence)),
        "`",
      ),
    sharp_quoted_string: ($) =>
      seq(
        "#",
        repeat(choice(token.immediate(/[^`\\]+/), $.escape_sequence)),
        "#",
      ),
    escape_sequence: ($) =>
      token.immediate(
        seq(
          "\\",
          choice(
            /[0abtnvfr'"`\\\/]/,
            /x[\da-fA-F]{2}/,
            /u[\da-fA-F]{4}/,
            /U[\da-fA-F]{8}/,
          ),
        ),
      ),
    system_literal: (_) =>
      choice("SYSTEM_NTSC", "SYSTEM_PAL", "SYSTEM_DENDY", "SYSTEM_REGISTER"),
    ppu_literal: (_) =>
      choice(
        "PPUCTRL",
        "PPUMASK",
        "PPUSTATUS",
        "OAMADDR",
        "OAMDATA",
        "PPUSCROLL",
        "PPUADDR",
        "PPUDATA",
        "OAMDMA",
      ),

    // operator
    assignment: ($) =>
      prec.right(PREC.binary_assign, seq($.expression, "=", $.expression)),
    augumented_assignment: ($) =>
      choice(
        ...[
          ["<=<", PREC.binary_assign_by_rotate_left, "right"],
          [">=>", PREC.binary_assign_by_rotate_right, "left"],
          ["*=", PREC.binary_assign_by_multiply, "right"],
          ["+=", PREC.binary_assign_by_add, "right"],
          ["-=", PREC.binary_assign_by_subtract, "right"],
          ["<<=", PREC.binary_assign_by_shift_left, "right"],
          [">>=", PREC.binary_assign_by_shift_right, "right"],
          ["&=", PREC.binary_assign_by_bitwise_and, "right"],
          ["^=", PREC.binary_assign_by_bitwise_xor, "right"],
          ["|=", PREC.binary_assign_by_bitwise_or, "right"],
        ].map(([operator, precedence, associativity]) =>
          (associativity == "right" ? prec.right : prec.left)(
            precedence,
            seq($.expression, operator, $.expression),
          ),
        ),
      ),
    parenthesized_expression: ($) => seq("(", $.expression, ")"),
    unary_operator: ($) =>
      choice(
        ...[
          ["@", PREC.unary_pointer],
          ["&", PREC.unary_hardware_address],
          ["+", PREC.unary_plus],
          ["-", PREC.unary_negate],
          ["~", PREC.unary_bitwise_not],
          ["!", PREC.unary_logical_not],
        ].map(([operator, precedence]) =>
          prec.left(precedence, seq(operator, $.expression)),
        ),
      ),
    binary_operator: ($) =>
      choice(
        ...[
          ["*", PREC.binary_multiply, "left"],
          ["+", PREC.binary_add, "left"],
          ["-", PREC.binary_subtract, "left"],
          ["<-<", PREC.binary_rotate_left, "left"],
          [">->", PREC.binary_rotate_right, "right"],
          ["<<", PREC.binary_shift_left, "left"],
          [">>", PREC.binary_shift_right, "left"],
          ["&", PREC.binary_bitwise_and, "left"],
          ["^", PREC.binary_bitwise_xor, "left"],
          ["|", PREC.binary_bitwize_or, "left"],
        ].map(([operator, precedence, associativity]) =>
          (associativity == "right" ? prec.right : prec.left)(
            precedence,
            seq($.expression, operator, $.expression),
          ),
        ),
      ),
    comparison_operator: ($) =>
      choice(
        ...[
          ["<", PREC.binary_less_than],
          ["<=", PREC.binary_less_than_or_equal],
          [">", PREC.binary_greater_than],
          [">=", PREC.binary_greater_than_or_equal],
          ["==", PREC.binary_equal_to],
          ["!=", PREC.binary_not_equal_to],
          ["&&", PREC.binary_logical_and],
          ["||", PREC.binary_logical_or],
        ].map(([operator, precedence, associativity]) =>
          prec.left(precedence, seq($.expression, operator, $.expression)),
        ),
      ),
    member_access: ($) =>
      prec.left(PREC.subscript, seq($.expression, ".", $.identifier)),
    u_indexed_subscript: ($) =>
      prec.left(PREC.subscript, seq($.expression, "[", $.expression, "]")),
    uu_indexed_subscript: ($) =>
      prec.left(PREC.subscript, seq($.expression, "{", $.expression, "}")),
    call: ($) =>
      prec.left(
        PREC.call,
        seq($.identifier, "(", optional(commaSep1($.expression)), ")"),
      ),
    type_cast_or_initialization: ($) =>
      seq($.type, "(", optional(commaSep1($.expression)), ")"),
    banked_pointer_initialization: ($) =>
      seq(
        $.type,
        $.group_identifier,
        "(",
        $.expression,
        ",",
        $.expression,
        ")",
      ),
    read: ($) => seq("read", $.type, "(", $.expression, ")"),
    write: ($) =>
      seq("write", $.type, "(", $.expression, ",", $.expression, ")"),
    hardware_read: ($) => seq("{", commaSep1($.expression), "}", "()"),
    hardware_write: ($) =>
      seq("{", commaSep1($.expression), "}", "(", commaSep1($.expression), ")"),
    ready: (_) => "ready",
    nmi_counter: (_) => "nmi_counter",
    file_expression: ($) =>
      seq(
        "file",
        "(",
        $.file_target,
        ",",
        $.string_literal,
        ")",
        repeat($.modifier),
      ),
    macro_expression: ($) =>
      seq("macro", "(", commaSep1($.string_literal), ")"),
    mapfab_expression: ($) =>
      seq(
        "mapfab",
        "(",
        $.mapfab_target,
        optional(seq(",", commaSep1($.string_literal))),
        ")",
      ),
    audio_expression: ($) =>
      seq(
        "audio",
        "(",
        $.audio_target,
        optional(seq(",", commaSep1($.string_literal))),
        ")",
      ),
    file_target: (_) => choice("chr", "raw", "fmt", "pbz", "donut", "rlz"),
    mapfab_target: ($) => choice("raw", "pbz", "rlz", "mmt_32"),
    audio_target: (_) => choice("puf1_sfx", "puf1_music"),
    sizeof_expression: ($) =>
      prec.right(
        PREC.call,
        choice(seq("sizeof", $.type), seq("sizeof", "(", $.expression, ")")),
      ),
    len_expression: ($) =>
      prec.right(
        PREC.call,
        choice(seq("len", $.type), seq("len", "(", $.expression, ")")),
      ),
    abs_expression: ($) => seq("abs", "(", $.expression, ")"),
    minmax_expression: ($) =>
      seq(choice("min", "max"), "(", commaSep1($.expression), ")"),

    // compound statement
    variable_definition_block: ($) =>
      seq($._indent, repeat(seq($.variable_definition, $._newline)), $._dedent),
    statement_block: ($) => seq($._indent, repeat($._statement), $._dedent),
    variable_definition: ($) =>
      seq(
        optional("ct"),
        choice($.type, $.identifier),
        optional($.group_identifier),
        $.identifier,
        optional(seq("=", $.expression)),
      ),
    struct_definition: ($) =>
      seq("struct", $.identifier, $.variable_definition_block),
    vars_definition: ($) =>
      seq(
        "vars",
        optional($.group_identifier),
        repeat($.modifier),
        seq(
          $._indent,
          repeat(seq($.variable_definition, repeat($.modifier))),
          $._dedent,
        ),
      ),
    data_definition: ($) =>
      seq(
        optional("omni"),
        "data",
        $.group_identifier,
        repeat($.constant_definition),
      ),
    charmap_definition: ($) =>
      seq(
        "charmap",
        $.identifier,
        "(",
        $.string_literal,
        optional(seq(",", $.character_literal)),
        ")",
      ),
    chrrom_definition: ($) =>
      seq("chrrom", optional($.expression), $.byte_block),
    function_definition: ($) =>
      seq(
        choice(seq(optional("ct"), "fn"), "mode", "nmi", "irq"),
        $.identifier,
        "(",
        optional(commaSep1($.function_argument)),
        ")",
        optional($.type),
        repeat($.modifier),
        $.statement_block,
      ),
    function_argument: ($) =>
      seq($.type, optional($.group_identifier), $.identifier),
    if_statement: ($) =>
      seq(
        "if",
        $.expression,
        $.statement_block,
        repeat($.else_if_clause),
        optional($.else_clause),
      ),
    else_if_clause: ($) => seq("else", "if", $.expression, $.statement_block),
    else_clause: ($) => seq("else", $.statement_block),
    while_statement: ($) =>
      seq(
        optional("do"),
        "while",
        $.expression,
        repeat($.loop_modifier),
        optional($.statement_block),
      ),
    for_statement: ($) =>
      seq(
        optional("do"),
        "for",
        optional(choice($.expression, $.variable_definition)),
        ";",
        optional($.expression),
        ";",
        optional($.expression),
        repeat($.loop_modifier),
        $.statement_block,
      ),
    switch_statement: ($) =>
      seq(
        "switch",
        $.expression,
        $._indent,
        repeat(choice($.case_clause, $.default_clause)),
        $._dedent,
      ),
    case_clause: ($) => seq("case", $.expression, optional($.statement_block)),
    default_clause: ($) => seq("default", optional($.statement_block)),
    goto_mode_statement: ($) =>
      seq(
        "goto",
        "mode",
        $.identifier,
        "(",
        optional($.expression),
        ")",
        repeat($.goto_mode_modifier),
      ),
    goto_mode_modifier: ($) =>
      seq(":", "preserves", optional($.group_identifier)),
    label_statement: ($) =>
      seq("label", $.identifier, optional($.statement_block)),
    modifier: ($) =>
      seq(
        ":",
        choice(
          "+inline",
          "-inline",
          "+align",
          "+zero_page",
          "-zero_page",
          "+sram",
          "-sram",
          "+spr_8x16",
          "+graphviz",
          "+info",
          "+dpcm",
          "+static",
          "palette_3",
          "palette_25",
          "+sloppy",
          "-sloppy",
          "+fork_scope",
          "+solo_interrupt",
          seq("nmi", $.identifier),
          seq("irq", $.identifier),
          seq("stow", optional("omni"), $.group_identifier),
          seq("employs", optional($.group_identifier)),
          seq("employs vars", optional($.group_identifier)),
          seq("employs data", optional($.group_identifier)),
          seq("preserves", $.group_identifier),
          seq("data", $.group_identifier),
        ),
      ),
    loop_modifier: (_) => seq(":", choice("-unroll", "+unroll", "+unloop")),

    // byte block
    constant_definition: ($) =>
      seq(
        "[",
        optional($.expression),
        "]",
        $.identifier,
        $.byte_block,
        repeat($.modifier),
      ),
    byte_block: ($) =>
      seq(
        $._indent,
        // typed_data is same as type_cast
        repeat(
          choice($.type_cast_or_initialization, $.untyped_data, $.op_statement),
        ),
        $._dedent,
      ),
    untyped_data: ($) => seq("(", $.expression, ")"),
    op_statement: ($) =>
      seq(
        $.op_code,
        choice(
          $.op_operand,
          seq("(", $.op_operand, ")"),
          seq($.op_operand, ",", choice("x", "y")),
          seq("(", $.op_operand, ")", ",", choice("x", "y")),
          seq("(", $.op_operand, ",", choice("x", "y"), ")"),
        ),
      ),
    op_operand: ($) =>
      choice(seq(optional("#"), $.numeric_literal), $.identifier),
    op_code: (_) =>
      choice(
        "adc",
        "and",
        "asl",
        "bcc",
        "bcs",
        "beq",
        "bit",
        "bmi",
        "bne",
        "bpl",
        "brk",
        "bvc",
        "bvs",
        "clc",
        "cld",
        "cli",
        "clv",
        "cmp",
        "cpx",
        "cpy",
        "dec",
        "dex",
        "dey",
        "eor",
        "inc",
        "inx",
        "iny",
        "jmp",
        "jsr",
        "lda",
        "ldx",
        "ldy",
        "lsr",
        "nop",
        "ora",
        "pha",
        "php",
        "pla",
        "plp",
        "rol",
        "ror",
        "rti",
        "rts",
        "sbc",
        "sec",
        "sed",
        "sei",
        "sta",
        "stx",
        "sty",
        "tax",
        "tay",
        "tsx",
        "txa",
        "txs",
        "tya",
        "lax",
        "axs",
        "anc",
        "alr",
        "arr",
        "sax",
        "skb",
        "ign",
        "dcp",
        "isc",
        "rla",
        "rra",
        "slo",
        "sre",
      ),

    // types
    type: ($) =>
      prec.left(
        choice($.scalar_type, $.quantity_type, $.array_type, $.identifier),
      ),
    scalar_type: ($) =>
      choice(
        $.integer_type,
        $.unit_fractional_type,
        $.fixed_point_type,
        $.numeric_constant_type,
        $.bool_type,
        $.void_type,
      ),
    integer_type: (_) => choice("U", "UU", "UUU", "S", "SS", "SSS"),
    unit_fractional_type: (_) => choice("F", "FF", "FFF"),
    fixed_point_type: (_) =>
      choice(
        "UF",
        "SF",
        "UUF",
        "SSF",
        "UUUF",
        "SSSF",
        "UFF",
        "SFF",
        "UUFF",
        "SSFF",
        "UUUFF",
        "SSSFF",
        "UFFF",
        "SFFF",
        "UUFFF",
        "SSFFF",
        "UUUFFF",
        "SSSFFF",
      ),
    numeric_constant_type: (_) => choice("Int", "Real"),
    bool_type: (_) => "Bool",
    void_type: (_) => "Void",

    quantity_type: ($) =>
      choice($.pointer_type, $.address_type, $.function_pointer_type),
    pointer_type: (_) => choice("CC", "CCC", "MM", "MMM", "PP", "PPP"),
    address_type: (_) => choice("AA", "AAA"),
    function_pointer_type: (_) => "Fn.set",

    array_type: ($) =>
      choice(
        $.typed_element_array_type,
        $.vector_type,
        $.pointer_addressable_array_type,
      ),
    typed_element_array_type: ($) =>
      seq(
        choice($.scalar_type, $.quantity_type, $.identifier),
        "[",
        optional(choice($.numeric_literal, $.identifier)),
        "]",
      ),
    vector_type: ($) =>
      seq(choice($.scalar_type, $.quantity_type, $.identifier), "{}"),
    pointer_addressable_array_type: ($) =>
      seq("[", optional(choice($.numeric_literal, $.identifier)), "]"),

    // etc
    line_continuation: (_) =>
      token(seq("\\", choice(seq(optional("\r"), "\n"), "\0"))),
    comment: (_) =>
      token(
        choice(
          seq("//", /[^\r\n]*/),
          seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"),
        ),
      ),
  },
});

function commaSep1(rule) {
  return sep1(rule, ",");
}
function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}
