const decimalDigits = /\d+/;
const hexDigits = /[\da-fA-F]+/;
const binaryDigits = /[01]+/;

module.exports = grammar({
  name: "nesfab",

  extras: ($) => [$.comment, $.line_continuation, /\s|\r?\n/],
  inline: ($) => [],
  conflicts: ($) => [],
  externals: ($) => [$.indent, $.dedent, $.newline],
  word: ($) => $.identifier,

  rules: {
    program: ($) => seq(repeat($._statement)),

    _statement: ($) => choice($._simple_statement, $._compound_statement),
    _simple_statement: ($) =>
      choice($.expression, $.break_statement, $.continue_statement),
    _compound_statement: ($) =>
      choice(
        $.group_statement,
        $.if_statement,
        $.while_statement,
        $.for_statement,
        $.switch_statement,
        $.function_definition,
      ),

    identifier: ($) => /[a-zA-Z_]\w+/,
    group_identifier: ($) => seq("/", $.identifier),
    block: ($) => seq($.indent, repeat($._statement), $.dedent),
    expression: ($) => choice("expression", $.fence),
    fence: (_) => "fence",

    // simple statement
    break_statement: (_) => "break",
    continue_statement: (_) => "continue",

    // compound statement
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
    function_definition: ($) =>
      seq(
        optional($.function_keyword),
        "fn",
        $.identifier,
        "(",
        optional(
          seq($.function_argument, repeat(seq(",", $.function_argument))),
        ),
        ")",
        field("return_type", $.type),
        field("function_modifiers", repeat(seq(":", $.function_modifier))),
        $.block,
      ),
    function_keyword: (_) => choice("ct", "mode", "nmi", "irq", "asm"),
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

    // literals
    literal: ($) =>
      choice($.boolean_literal, $.numeric_literal, $.string_literal),
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
      prec(
        1,
        seq(
          choice($.scalar_type, $.quantity_type),
          "[",
          optional($.numeric_literal),
          "]",
        ),
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
