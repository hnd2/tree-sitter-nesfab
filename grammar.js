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
  binary_member_access: 5, // .
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

  // call: 22,
  // subscript: 21,
};

module.exports = grammar({
  name: "nesfab",

  extras: ($) => [$.comment, $.line_continuation, /\s|\r?\n/],
  inline: ($) => [],
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

    identifier: ($) => /[a-zA-Z_]\w+/,
    group_identifier: ($) => seq("/", $.identifier),
    block: ($) => seq($.indent, repeat($._statement), $.dedent),
    _statement: ($) => choice($._simple_statement, $._compound_statement),

    // simple statement
    _simple_statement: ($) =>
      choice(
        $.expression,
        $.break_statement,
        $.continue_statement,
        $.goto_statement,
        // $.return_statement,
        $.swap_statement,
        $.fence_statement,
        $.nmi_statement,
        // $.irq_statement,
      ),
    break_statement: (_) => "break",
    continue_statement: (_) => "continue",
    goto_statement: ($) => seq("goto", $.identifier),
    return_statement: ($) => seq("return", optional($.expression)),
    swap_statement: ($) => seq("swap", $.identifier, ",", $.identifier),
    fence_statement: (_) => "fence",
    nmi_statement: (_) => "nmi",
    irq_statement: ($) => seq("irq", optional($.expression)),

    // compound statement
    _compound_statement: ($) =>
      choice(
        $.group_statement,
        $.if_statement,
        $.while_statement,
        $.for_statement,
        $.goto_mode_statement,
        $.label_statement,
        $.switch_statement,
        $.function_definition,
      ),
    group_statement: ($) =>
      seq(
        choice("vars", seq(optional("omni"), "data")),
        $.group_identifier,
        $.indent,
        repeat(seq($.type, $.identifier)),
        $.dedent,
      ),
    if_statement: ($) =>
      seq(
        "if",
        $.expression,
        $.block,
        repeat($.else_if_clause),
        optional($.else_clause),
      ),
    else_if_clause: ($) => seq("else if", $.expression, $.block),
    else_clause: ($) => seq("else", $.block),
    while_statement: ($) =>
      seq(
        optional("do"),
        "while",
        $.expression,
        field("loop_modifiers", repeat(seq(":", $.loop_modifier))),
        $.block,
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
        $.block,
      ),
    loop_modifier: (_) => choice("-unroll", "+unroll", "+unloop"),
    switch_statement: ($) => seq("switch", $.expression, $.switch_body),
    switch_body: ($) =>
      seq($.indent, repeat(choice($.case_clause, $.default_clause)), $.dedent),
    case_clause: ($) =>
      seq("case", field("value", $.expression), optional($.block)),
    default_clause: ($) => seq("default", optional($.block)),
    goto_mode_statement: ($) =>
      seq(
        "goto",
        "mode",
        $.identifier,
        "(",
        // args
        ")",
        ":",
        "preserves",
        optional($.group_identifier),
      ),
    label_statement: ($) => seq("label", $.identifier, optional($.block)),
    function_definition: ($) =>
      seq(
        choice(
          "fn",
          seq("ct", optional("fn")),
          "mode",
          // "nmi",
          // "irq"
        ),
        $.identifier,
        "(",
        optional(commaSeparated($.function_argument)),
        ")",
        optional(field("return_type", $.type)),
        optional(
          field("function_modifiers", repeat(seq(":", $.function_modifier))),
        ),
        $.block,
      ),
    // asm_function_definition: ($) =>
    function_argument: ($) =>
      seq(choice($.type, seq($.type, $.group_identifier)), $.identifier),
    function_modifier: ($) =>
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

    // expression
    expression: ($) =>
      choice(
        $.primary_expression,
        $.unary_expression,
        $.binary_expression,
        $.hardware_expression,
        $.call,
      ),
    primary_expression: ($) =>
      choice($.identifier, $.literal, $.subscript_expression),
    unary_expression: ($) =>
      choice(
        ...[
          ["@", PREC.unary_pointer],
          ["&", PREC.unary_hardware_address],
          ["+", PREC.unary_plus],
          ["-", PREC.unary_negate],
          ["~", PREC.unary_bitwise_not],
          ["!", PREC.unary_logical_not],
        ].map(([operator, precedence]) =>
          prec.left(precedence, seq(field("operator", operator), $.expression)),
        ),
      ),
    binary_expression: ($) =>
      choice(
        ...[
          [".", PREC.binary_member_access, "left"],
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
          ["<", PREC.binary_less_than, "left"],
          ["<=", PREC.binary_less_than_or_equal, "left"],
          [">", PREC.binary_greater_than, "left"],
          [">=", PREC.binary_greater_than_or_equal, "left"],
          ["==", PREC.binary_equal_to, "left"],
          ["!=", PREC.binary_not_equal_to, "left"],
          ["&&", PREC.binary_logical_and, "left"],
          ["||", PREC.binary_logical_or, "left"],
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
          ["=", PREC.binary_assign, "right"],
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
    subscript_expression: ($) =>
      seq(
        $.expression,
        choice($.u_indexed_expression, $.uu_indexed_expression),
      ),
    u_indexed_expression: ($) =>
      seq("[", optional(commaSeparated($.primary_expression)), "]"),
    uu_indexed_expression: ($) =>
      seq("{", optional(commaSeparated($.primary_expression)), "}"),
    hardware_expression: ($) =>
      seq(
        $.uu_indexed_expression,
        "(",
        commaSeparated($.primary_expression),
        ")",
      ),
    call: ($) => seq($.primary_expression, $.parameters),
    parameters: ($) =>
      seq("(", optional(commaSeparated($.primary_expression)), ")"),

    // literals
    literal: ($) =>
      choice(
        $.boolean_literal,
        $.numeric_literal,
        $.string_literal,
        $.system_literal,
        $.ppu_literal,
      ),
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
    string_literal: ($) =>
      choice(
        $.single_quoted_string,
        $.double_quoted_string,
        $.backtick_quoted_string,
      ),
    single_quoted_string: ($) =>
      seq(
        "'",
        repeat(choice(token.immediate(/[^'\\]+/), $.escape_sequence)),
        "'",
      ),
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

function commaSeparated(rule) {
  return seq(rule, repeat(seq(",", rule)));
}
