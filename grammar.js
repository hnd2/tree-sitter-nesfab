module.exports = grammar({
  name: "nesfab",

  rules: {
    source_file: ($) => repeat($.line),
    line: ($) => seq($.hello, $.identifier),
    hello: ($) => "hello",
    identifier: ($) => /[a-z_][a-z0-9_]*/,
  },
});
