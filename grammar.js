const decimalDigits = /\d+/;
const hexDigits = /[\da-fA-F]+/;
const binaryDigits = /[01]+/;
const PREC = {
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
  call: 5,
};

module.exports = grammar({
  name: "nesfab",

  extras: ($) => [$.comment, $.line_continuation, /\s|\r?\n/],
  inline: ($) => [
    // $._simple_statement,
    // $._compound_statement,
    // $.indent,
    // $.dedent,
    // $.newline,
  ],
  conflicts: ($) => [
    // [$.function_definition, $.function_modifier],
    // [$.function_definition, $._statement],
  ],
  externals: ($) => [$.indent, $.dedent, $.newline],
  word: ($) => $.identifier,
  // supertypes: ($) => [
  //   $._simple_statement,
  //   $._compound_statement,
  //   $.expression,
  //   $.primary_expression,
  // ],

  rules: {
    module: ($) => repeat($._statement),

    identifier: (_) => /[_\p{XID_Start}][_\p{XID_Continue}]*/,
    group_identifier: ($) => seq("/", $.identifier),
    _statement: ($) => choice($._simple_statements, $._compound_statement),

    _simple_statements: ($) => seq($._simple_statement, $.newline),
    _simple_statement: ($) =>
      choice(
        $.expression_statement,
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
        // $.chrrom_definition,
        $.function_definition,
        $.if_statement,
        $.while_statement,
        $.for_statement,
        $.switch_statement,
        $.goto_mode_statement,
        $.label_statement,
      ),

    expression_statement: ($) =>
      choice($.expression, $.assignment, $.augumented_assignment),
    break_statement: (_) => "break",
    continue_statement: (_) => "continue",
    goto_statement: ($) => seq("goto", $.identifier),
    return_statement: ($) => seq("return", optional($.expression)),
    swap_statement: ($) =>
      seq(
        "swap",
        field("left", $.identifier),
        ",",
        field("right", $.identifier),
      ),
    fence_statement: (_) => "fence",
    nmi_statement: (_) => "nmi",
    irq_statement: ($) => seq("irq", optional($.boolean_literal)),

    // expression
    expression: ($) =>
      choice($.primary_expression, $.comparison_operator, $.file_expression),

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
        $.unary_operator,
        $.binary_operator,
        $.member_access,
        $.u_indexed_subscript,
        $.uu_indexed_subscript,
        $.call,
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
            seq(field("operator", operator), field("argument", $.expression)),
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
              field("left", $.expression),
              field("operator", operator),
              field("right", $.expression),
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
        PREC.call,
        seq(
          field("value", $.primary_expression),
          "[",
          field("index", $.expression),
          "]",
        ),
      ),
    uu_indexed_subscript: ($) =>
      prec.left(
        PREC.call,
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
          field("function", $.primary_expression),
          "(",
          optional(field("arguments", commaSep1($.primary_expression))),
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
    ready: ($) => "ready",
    nmi_counter: ($) => "nmi_counter",
    file_expression: ($) =>
      prec.left(
        PREC.call,
        seq(
          "file",
          "(",
          field(
            "target",
            // choice("chr", "raw", "fmt", "pbz", "donut", "rlz")
            $.identifier,
          ),
          ",",
          $.string_literal,
          ")",
          optional($.modifier),
        ),
      ),

    // compound statement
    variable_definition_block: ($) =>
      seq($.indent, repeat(seq($.variable_definition, $.newline)), $.dedent),
    statement_block: ($) => seq($.indent, repeat($._statement), $.dedent),
    variable_definition: ($) =>
      seq(
        optional("ct"),
        $.type,
        $.identifier,
        optional(seq("=", field("value", $.expression))),
        $.newline,
      ),
    struct_definition: ($) =>
      seq("struct", $.identifier, $.variable_definition_block),
    vars_definition: ($) =>
      seq("vars", $.group_identifier, $.variable_definition_block),
    /*
      data_definition: ($) =>
      seq(
        optional("omni"),
        "data",
        $.group_identifier,
        $.data_constant_definition_block,
      ),
    byte_block_definition: ($) =>
      seq(
        "[",
        optional($.numeric_literal),
        "]",
        $.identifier,
        $.indent,
        repeat(choice($.typed_data, $.untyped_data)),
        $.dedent,
      ),
    typed_data: ($) => seq($.type, "(", commaSep1($.numeric_literal), ")"),
    untyped_data: ($) => seq("(", ")"),
    */
    charmap_definition: ($) =>
      seq(
        "charmap",
        $.identifier,
        "(",
        $.string_literal,
        optional(seq(",", $.character_literal)),
        ")",
      ),
    // chrrom_definition: ($) =>
    //   seq("chrrom", $.numeric_literal, $.indent, repeat(), $.dedent),
    function_definition: ($) =>
      seq(
        choice(seq(optional("ct"), "fn"), "mode", "nmi", "irq"),
        $.identifier,
        "(",
        optional(field("arguments", commaSep1($.function_argument))),
        ")",
        optional(field("return_type", $.type)),
        repeat(seq(":", $.modifier)),
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
        field("loop_modifiers", repeat(seq(":", $.loop_modifier))),
        $.statement_block,
      ),
    for_statement: ($) =>
      seq(
        optional("do"),
        "for",
        optional(field("initialization", $.expression)),
        ";",
        optional(field("condition", $.expression)),
        ";",
        optional(field("iteration", $.expression)),
        field("loop_modifiers", repeat(seq(":", $.loop_modifier))),
        $.statement_block,
      ),
    switch_statement: ($) =>
      seq(
        "switch",
        $.expression,
        $.indent,
        repeat(choice($.case_clause, $.default_clause)),
        $.dedent,
      ),
    case_clause: ($) =>
      seq("case", field("value", $.expression), optional($.statement_block)),
    default_clause: ($) => seq("default", optional($.statement_block)),
    goto_mode_statement: ($) =>
      seq(
        "goto",
        "mode",
        $.identifier,
        "(",
        optional($.expression),
        ")",
        optional(seq(":", "preserves", optional($.group_identifier))),
      ),
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
          seq("employs", optional(choice("vars", "data")), $.group_identifier),
          seq("preserves", $.group_identifier),
          seq("data", $.group_identifier),
        ),
      ),
    loop_modifier: (_) => choice("-unroll", "+unroll", "+unloop"),

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
    fixed_point_type: (_) => choice("UF", "SSF", "UFFF"),
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
        choice($.scalar_type, $.quantity_type),
        "[",
        optional($.numeric_literal),
        "]",
      ),
    vector_type: ($) => seq(choice($.scalar_type, $.quantity_type), "{}"),
    pointer_addressable_array_type: ($) =>
      seq("[", optional($.numeric_literal), "]"),

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
