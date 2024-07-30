const decimalDigits = /\d+/;
const hexDigits = /[\da-fA-F]+/;
const binaryDigits = /[01]+/;

const PREC = {
  parenthesized_expression: 1,
  unary_pointer: 4, // @
  unary_hardware_address: 8, //&
  unary_plus: 8, // +
  unary_negate: 8, // -
  unary_bitwise_not: 8, // ~
  unary_logical_not: 8, // !
  binary_multiply: 10, // *
  binary_add: 11, // *
  binary_subtract: 11, // -
  binary_rotate_left: 12, // <-<
  binary_rotate_right: 13, // >->
  binary_shift_left: 14, // <<
  binary_shift_right: 14, // >>
  binary_bitwise_and: 15, // &
  binary_bitwise_xor: 16, // ^
  binary_bitwize_or: 17, // |
  binary_less_than: 18, // <
  binary_less_than_or_equal: 18, // <=
  binary_greater_than: 18, // >
  binary_greater_than_or_equal: 18, // >=
  binary_equal_to: 19, // ==
  binary_not_equal_to: 19, // !=
  binary_logical_and: 20, // &&
  binary_logical_or: 21, // ||
  binary_assign_by_rotate_left: 28, // <=<
  binary_assign_by_rotate_right: 29, // >=>,
  binary_assign_by_multiply: 30, // *=
  binary_assign_by_add: 30, // +=
  binary_assign_by_subtract: 30, // -=
  binary_assign_by_shift_left: 30, // <<=
  binary_assign_by_shift_right: 30, // >>=
  binary_assign_by_bitwise_and: 30, // &=
  binary_assign_by_bitwise_xor: 30, // ^=
  binary_assign_by_bitwise_or: 30, // |=
  binary_assign: 30, // =
  label: 1,
  call: 5,
  subscript: 6,
};

module.exports = grammar({
  name: "nesfab",

  extras: ($) => [$.comment, $.line_continuation, /\s|\r?\n/],
  inline: ($) => [],
  conflicts: ($) => [],
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
        // $.data_definition,
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

    break_statement: (_) => prec.left("break"),
    continue_statement: (_) => prec.left("continue"),
    goto_statement: ($) => prec.right(PREC.label, seq("goto", $.identifier)),
    return_statement: ($) => seq("return", optional($.expression)),
    swap_statement: ($) =>
      seq(
        "swap",
        field("left", $.identifier),
        ",",
        field("right", $.identifier),
      ),
    fence_statement: (_) => prec.left("fence"),
    nmi_statement: (_) => prec.left("nmi"),
    irq_statement: ($) => seq("irq", optional($.boolean_literal)),

    // expression
    expression: ($) =>
      choice(
        $.primary_expression,
        $.comparison_operator,
        $.file_expression,
        $.macro_expression,
        $.mapfab_expression,
        $.audio_expression,
        $.assignment,
        $.augumented_assignment,
      ),

    primary_expression: ($) =>
      choice(
        $.identifier,
        $.boolean_literal,
        $.numeric_literal,
        $.character_literal,
        $.string_literal,
        $.system_literal,
        $.ppu_literal,
        // $.array,
        $.parenthesized_expression,
        $.unary_operator,
        $.binary_operator,
        $.member_access,
        $.u_indexed_subscript,
        $.uu_indexed_subscript,
        $.call,
        $.sizeof_expression,
        $.len_expression,
        $.abs_expression,
        $.minmax_expression,
        $.type_cast,
        $.zero_initialization,
        $.array_initialization,
        $.banked_pointer_initialization,
        $.read,
        $.hardware_read,
        $.ready,
        $.nmi_counter,
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
      prec.right(
        PREC.binary_assign,
        seq(
          field("left", $.expression),
          field("operator", "="),
          field("right", $.expression),
        ),
      ),
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
            seq(
              field("left", $.expression),
              field("operator", operator),
              field("right", $.expression),
            ),
          ),
        ),
      ),
    parenthesized_expression: ($) =>
      prec.left(PREC.parenthesized_expression, seq("(", $.expression, ")")),
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
          prec.left(
            precedence,
            seq(
              field("operator", operator),
              field("argument", $.primary_expression),
            ),
          ),
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
            seq(
              field("left", $.primary_expression),
              field("operator", operator),
              field("right", $.primary_expression),
            ),
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
          prec.left(
            precedence,
            seq(
              field("left", $.expression),
              field("operator", operator),
              field("right", $.expression),
            ),
          ),
        ),
      ),
    member_access: ($) =>
      prec.left(
        PREC.call,
        seq(
          field("left", $.expression),
          field("operator", "."),
          field("right", $.expression),
        ),
      ),
    u_indexed_subscript: ($) =>
      prec.left(
        PREC.subscript,
        seq(
          field("value", $.primary_expression),
          "[",
          field("index", $.expression),
          "]",
        ),
      ),
    uu_indexed_subscript: ($) =>
      prec.left(
        PREC.subscript,
        seq(
          field("value", $.primary_expression),
          "{",
          field("index", $.expression),
          "}",
        ),
      ),
    call: ($) =>
      prec.left(
        PREC.call,
        seq(
          field("function_name", $.identifier),
          "(",
          optional(field("arguments", commaSep1($.primary_expression))),
          ")",
        ),
      ),
    type_cast: ($) =>
      prec.left(
        PREC.call,
        seq(
          field("type", $.type),
          "(",
          field("value", $.primary_expression),
          ")",
        ),
      ),
    zero_initialization: ($) => prec.left(PREC.call, seq($.type, "()")),
    array_initialization: ($) =>
      prec.left(
        PREC.call,
        seq($.array_type, "(", commaSep1($.primary_expression), ")"),
      ),
    banked_pointer_initialization: ($) =>
      prec.left(
        PREC.call,
        seq(
          $.type,
          $.group_identifier,
          "(",
          field("address", $.primary_expression),
          ",",
          field("bank", $.primary_expression),
          ")",
        ),
      ),
    read: ($) =>
      seq("read", $.type, "(", field("pointer", $.primary_expression), ")"),
    write: ($) =>
      seq(
        "write",
        $.type,
        "(",
        field("pointer", $.primary_expression),
        ",",
        field("value", $.primary_expression),
        ")",
      ),
    hardware_read: ($) =>
      prec.left(
        PREC.call,
        seq("{", field("address", commaSep1($.expression)), "}", "()"),
      ),
    hardware_write: ($) =>
      prec.left(
        PREC.call,
        seq(
          "{",
          field("address", commaSep1($.expression)),
          "}",
          "(",
          field("value", commaSep1($.expression)),
          ")",
        ),
      ),
    ready: (_) => prec.left("ready"),
    nmi_counter: (_) => prec.left("nmi_counter"),
    file_expression: ($) =>
      prec.left(
        PREC.call,
        seq(
          field("function_name", alias("file", $.identifier)),
          "(",
          field("target", $.file_target),
          ",",
          $.string_literal,
          ")",
          repeat($.modifier),
        ),
      ),
    macro_expression: ($) =>
      prec.left(
        PREC.call,
        seq(
          field("function_name", alias("macro", $.identifier)),
          "(",
          commaSep1($.string_literal),
          ")",
        ),
      ),
    mapfab_expression: ($) =>
      prec.left(
        PREC.call,
        seq(
          field("function_name", alias("mapfab", $.identifier)),
          "(",
          field("target", $.mapfab_target),
          optional(seq(",", commaSep1($.string_literal))),
          ")",
        ),
      ),
    audio_expression: ($) =>
      prec.left(
        PREC.call,
        seq(
          field("function_name", alias("audio", $.identifier)),
          "(",
          field("target", $.audio_target),
          optional(seq(",", commaSep1($.string_literal))),
          ")",
        ),
      ),
    file_target: (_) => choice("chr", "raw", "fmt", "pbz", "donut", "rlz"),
    mapfab_target: ($) => choice("raw", "pbz", "rlz", "mmt_32"),
    audio_target: (_) => choice("puf1_sfx", "puf1_music"),
    sizeof_expression: ($) =>
      prec.left(
        PREC.call,
        choice(
          seq("sizeof", $.type),
          seq("sizeof", "(", $.primary_expression, ")"),
        ),
      ),
    len_expression: ($) =>
      prec.left(
        PREC.call,
        choice(seq("len", $.type), seq("len", "(", $.primary_expression, ")")),
      ),
    abs_expression: ($) =>
      prec.left(PREC.call, seq("abs", "(", $.primary_expression, ")")),
    minmax_expression: ($) =>
      prec.left(
        PREC.call,
        seq(choice("min", "max"), "(", commaSep1($.primary_expression), ")"),
      ),

    // compound statement
    variable_definition_block: ($) =>
      seq($._indent, repeat(seq($.variable_definition, $._newline)), $._dedent),
    statement_block: ($) => seq($._indent, repeat($._statement), $._dedent),
    variable_definition: ($) =>
      seq(
        optional("ct"),
        field("type", choice($.type, $.identifier)),
        optional($.group_identifier),
        field("name", $.identifier),
        optional(seq("=", field("value", $.expression))),
      ),
    struct_definition: ($) =>
      seq("struct", $.identifier, $.variable_definition_block),
    vars_definition: ($) =>
      seq(
        "vars",
        optional(field("name", $.group_identifier)),
        seq(
          $._indent,
          repeat(seq($.variable_definition, repeat($.modifier))),
          $._dedent,
        ),
      ),
    data_definition: ($) =>
      seq(optional("omni"), "data", $.group_identifier, $.byte_block),
    typed_data: ($) => seq($.type, "(", commaSep1($.numeric_literal), ")"),
    untyped_data: ($) => seq("(", ")"),
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
      seq("chrrom", optional($.primary_expression), $.byte_block),
    function_definition: ($) =>
      seq(
        choice(seq(optional("ct"), "fn"), "mode", "nmi", "irq"),
        field("function_name", $.identifier),
        "(",
        optional(field("arguments", commaSep1($.function_argument))),
        ")",
        optional(field("return_type", $.type)),
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
        repeat(alias($.loop_modifier, $.modifier)),
        optional($.statement_block),
      ),
    for_statement: ($) =>
      seq(
        optional("do"),
        "for",
        optional(
          field("initialization", choice($.expression, $.variable_definition)),
        ),
        ";",
        optional(field("condition", $.expression)),
        ";",
        optional(field("iteration", $.expression)),
        repeat(alias($.loop_modifier, $.modifier)),
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
    case_clause: ($) =>
      seq("case", field("value", $.expression), optional($.statement_block)),
    default_clause: ($) => seq("default", optional($.statement_block)),
    goto_mode_statement: ($) =>
      prec.right(
        PREC.label,
        seq(
          "goto",
          "mode",
          field("function_name", $.identifier),
          "(",
          optional($.expression),
          ")",
          repeat(alias($.goto_mode_modifier, $.modifier)),
        ),
      ),
    goto_mode_modifier: ($) =>
      seq(":", "preserves", optional($.group_identifier)),
    label_statement: ($) =>
      prec.right(
        PREC.label,
        seq("label", $.identifier, optional($.statement_block)),
      ),
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
    byte_block: ($) =>
      seq($._indent, repeat($._byte_block_statement), $._dedent),
    _byte_block_statement: ($) => choice($.file_expression),

    // types
    type: ($) => choice($.scalar_type, $.quantity_type, $.array_type),
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
      prec.left(
        PREC.subscript,
        seq(
          choice($.scalar_type, $.quantity_type, $.identifier),
          "[",
          optional($.numeric_literal),
          "]",
        ),
      ),
    vector_type: ($) =>
      prec.left(
        PREC.subscript,
        seq(choice($.scalar_type, $.quantity_type, $.identifier), "{}"),
      ),
    pointer_addressable_array_type: ($) =>
      prec.left(PREC.subscript, seq("[", optional($.numeric_literal), "]")),

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
