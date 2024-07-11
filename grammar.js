const decimalDigits = /\d+/;
const hexDigits = /[\da-fA-F]+/;
const binaryDigits = /[01]+/;

module.exports = grammar({
  name: "nesfab",

  extras: ($) => [$.comment, $.line_continuation, /\s|\r?\n/],
  inline: ($) => [],
  conflicts: ($) => [],
  externals: ($) => [],
  word: ($) => $.identifier,

  rules: {
    program: ($) => seq(repeat($.statement)),

    statement: ($) => choice($.type, $.literal),

    expression: ($) => choice(),

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
    pointer_addressable_array_type: ($) => seq("[", $.numeric_literal, "]"),

    // etc
    identifier: ($) => /[a-zA-Z_]\w+/,
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

    line_continuation: (_) =>
      token(seq("\\", choice(seq(optional("\r"), "\n"), "\0"))),
    comment: (_) =>
      token(
        choice(
          seq("//", /[^\r\n\u2028\u2029]*/),
          seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"),
        ),
      ),
    // source_file: ($) => repeat($._definition),

    // _definition: ($) =>
    //   choice(
    //     $.function_definition,
    //     // TODO: other kinds of definitions
    //   ),

    // function_definition: ($) =>
    //   seq("func", $.identifier, $.parameter_list, $._type, $.block),

    // parameter_list: ($) =>
    //   seq(
    //     "(",
    //     // TODO: parameters
    //     ")",
    //   ),

    // _type: ($) => choice($.primitive_type, $.array_type, $.pointer_type),

    // primitive_type: ($) => choice("bool", "int"),
    // array_type: ($) => seq("[", "]", $._type),
    // pointer_type: ($) => seq("*", $._type),

    // block: ($) => seq("{", repeat($._statement), "}"),

    // _statement: ($) =>
    //   choice(
    //     $.return_statement,
    //     // TODO: other kinds of statements
    //   ),

    // return_statement: ($) => seq("return", $._expression, ";"),

    // _expression: ($) =>
    //   choice(
    //     $.identifier,
    //     $.number,
    //     // TODO: other kinds of expressions
    //   ),

    // identifier: ($) => /[a-z]+/,

    // number: ($) => /\d+/,
  },
});
