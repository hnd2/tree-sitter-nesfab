#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 68
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 72
#define ALIAS_COUNT 0
#define TOKEN_COUNT 46
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_identifier = 1,
  sym_boolean_literal = 2,
  sym_numeric_literal = 3,
  anon_sym_U = 4,
  anon_sym_UU = 5,
  anon_sym_UUU = 6,
  anon_sym_S = 7,
  anon_sym_SS = 8,
  anon_sym_SSS = 9,
  anon_sym_F = 10,
  anon_sym_FF = 11,
  anon_sym_FFF = 12,
  anon_sym_UF = 13,
  anon_sym_SSF = 14,
  anon_sym_UFFF = 15,
  anon_sym_Int = 16,
  anon_sym_Real = 17,
  sym_bool_type = 18,
  sym_void_type = 19,
  anon_sym_CC = 20,
  anon_sym_CCC = 21,
  anon_sym_MM = 22,
  anon_sym_MMM = 23,
  anon_sym_PP = 24,
  anon_sym_PPP = 25,
  anon_sym_AA = 26,
  anon_sym_AAA = 27,
  sym_function_pointer_type = 28,
  anon_sym_LBRACK = 29,
  anon_sym_RBRACK = 30,
  anon_sym_LBRACE_RBRACE = 31,
  anon_sym_SQUOTE = 32,
  aux_sym_single_quoted_string_token1 = 33,
  anon_sym_DQUOTE = 34,
  aux_sym_double_quoted_string_token1 = 35,
  anon_sym_BQUOTE = 36,
  aux_sym_backtick_quoted_string_token1 = 37,
  sym_escape_sequence = 38,
  sym_line_continuation = 39,
  sym_comment = 40,
  anon_sym_fn = 41,
  anon_sym_LPAREN_RPAREN = 42,
  anon_sym_bar = 43,
  sym__indent = 44,
  sym__dedent = 45,
  sym_program = 46,
  sym_statement = 47,
  sym_literal = 48,
  sym_string_literal = 49,
  sym_type = 50,
  sym_scalar_type = 51,
  sym_integer_type = 52,
  sym_unit_fractional_type = 53,
  sym_fixed_point_type = 54,
  sym_numeric_constant_type = 55,
  sym_quantity_type = 56,
  sym_pointer_type = 57,
  sym_address_type = 58,
  sym_array_type = 59,
  sym_typed_element_array_type = 60,
  sym_vector_type = 61,
  sym_pointer_addressable_array_type = 62,
  sym_single_quoted_string = 63,
  sym_double_quoted_string = 64,
  sym_backtick_quoted_string = 65,
  sym_function_definition = 66,
  sym_block = 67,
  aux_sym_program_repeat1 = 68,
  aux_sym_single_quoted_string_repeat1 = 69,
  aux_sym_double_quoted_string_repeat1 = 70,
  aux_sym_backtick_quoted_string_repeat1 = 71,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [sym_boolean_literal] = "boolean_literal",
  [sym_numeric_literal] = "numeric_literal",
  [anon_sym_U] = "U",
  [anon_sym_UU] = "UU",
  [anon_sym_UUU] = "UUU",
  [anon_sym_S] = "S",
  [anon_sym_SS] = "SS",
  [anon_sym_SSS] = "SSS",
  [anon_sym_F] = "F",
  [anon_sym_FF] = "FF",
  [anon_sym_FFF] = "FFF",
  [anon_sym_UF] = "UF",
  [anon_sym_SSF] = "SSF",
  [anon_sym_UFFF] = "UFFF",
  [anon_sym_Int] = "Int",
  [anon_sym_Real] = "Real",
  [sym_bool_type] = "bool_type",
  [sym_void_type] = "void_type",
  [anon_sym_CC] = "CC",
  [anon_sym_CCC] = "CCC",
  [anon_sym_MM] = "MM",
  [anon_sym_MMM] = "MMM",
  [anon_sym_PP] = "PP",
  [anon_sym_PPP] = "PPP",
  [anon_sym_AA] = "AA",
  [anon_sym_AAA] = "AAA",
  [sym_function_pointer_type] = "function_pointer_type",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE_RBRACE] = "{}",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_single_quoted_string_token1] = "single_quoted_string_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_double_quoted_string_token1] = "double_quoted_string_token1",
  [anon_sym_BQUOTE] = "`",
  [aux_sym_backtick_quoted_string_token1] = "backtick_quoted_string_token1",
  [sym_escape_sequence] = "escape_sequence",
  [sym_line_continuation] = "line_continuation",
  [sym_comment] = "comment",
  [anon_sym_fn] = "fn",
  [anon_sym_LPAREN_RPAREN] = "()",
  [anon_sym_bar] = "bar",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym_program] = "program",
  [sym_statement] = "statement",
  [sym_literal] = "literal",
  [sym_string_literal] = "string_literal",
  [sym_type] = "type",
  [sym_scalar_type] = "scalar_type",
  [sym_integer_type] = "integer_type",
  [sym_unit_fractional_type] = "unit_fractional_type",
  [sym_fixed_point_type] = "fixed_point_type",
  [sym_numeric_constant_type] = "numeric_constant_type",
  [sym_quantity_type] = "quantity_type",
  [sym_pointer_type] = "pointer_type",
  [sym_address_type] = "address_type",
  [sym_array_type] = "array_type",
  [sym_typed_element_array_type] = "typed_element_array_type",
  [sym_vector_type] = "vector_type",
  [sym_pointer_addressable_array_type] = "pointer_addressable_array_type",
  [sym_single_quoted_string] = "single_quoted_string",
  [sym_double_quoted_string] = "double_quoted_string",
  [sym_backtick_quoted_string] = "backtick_quoted_string",
  [sym_function_definition] = "function_definition",
  [sym_block] = "block",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_single_quoted_string_repeat1] = "single_quoted_string_repeat1",
  [aux_sym_double_quoted_string_repeat1] = "double_quoted_string_repeat1",
  [aux_sym_backtick_quoted_string_repeat1] = "backtick_quoted_string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym_numeric_literal] = sym_numeric_literal,
  [anon_sym_U] = anon_sym_U,
  [anon_sym_UU] = anon_sym_UU,
  [anon_sym_UUU] = anon_sym_UUU,
  [anon_sym_S] = anon_sym_S,
  [anon_sym_SS] = anon_sym_SS,
  [anon_sym_SSS] = anon_sym_SSS,
  [anon_sym_F] = anon_sym_F,
  [anon_sym_FF] = anon_sym_FF,
  [anon_sym_FFF] = anon_sym_FFF,
  [anon_sym_UF] = anon_sym_UF,
  [anon_sym_SSF] = anon_sym_SSF,
  [anon_sym_UFFF] = anon_sym_UFFF,
  [anon_sym_Int] = anon_sym_Int,
  [anon_sym_Real] = anon_sym_Real,
  [sym_bool_type] = sym_bool_type,
  [sym_void_type] = sym_void_type,
  [anon_sym_CC] = anon_sym_CC,
  [anon_sym_CCC] = anon_sym_CCC,
  [anon_sym_MM] = anon_sym_MM,
  [anon_sym_MMM] = anon_sym_MMM,
  [anon_sym_PP] = anon_sym_PP,
  [anon_sym_PPP] = anon_sym_PPP,
  [anon_sym_AA] = anon_sym_AA,
  [anon_sym_AAA] = anon_sym_AAA,
  [sym_function_pointer_type] = sym_function_pointer_type,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE_RBRACE] = anon_sym_LBRACE_RBRACE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_single_quoted_string_token1] = aux_sym_single_quoted_string_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_double_quoted_string_token1] = aux_sym_double_quoted_string_token1,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_backtick_quoted_string_token1] = aux_sym_backtick_quoted_string_token1,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_line_continuation] = sym_line_continuation,
  [sym_comment] = sym_comment,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_LPAREN_RPAREN] = anon_sym_LPAREN_RPAREN,
  [anon_sym_bar] = anon_sym_bar,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym_program] = sym_program,
  [sym_statement] = sym_statement,
  [sym_literal] = sym_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_type] = sym_type,
  [sym_scalar_type] = sym_scalar_type,
  [sym_integer_type] = sym_integer_type,
  [sym_unit_fractional_type] = sym_unit_fractional_type,
  [sym_fixed_point_type] = sym_fixed_point_type,
  [sym_numeric_constant_type] = sym_numeric_constant_type,
  [sym_quantity_type] = sym_quantity_type,
  [sym_pointer_type] = sym_pointer_type,
  [sym_address_type] = sym_address_type,
  [sym_array_type] = sym_array_type,
  [sym_typed_element_array_type] = sym_typed_element_array_type,
  [sym_vector_type] = sym_vector_type,
  [sym_pointer_addressable_array_type] = sym_pointer_addressable_array_type,
  [sym_single_quoted_string] = sym_single_quoted_string,
  [sym_double_quoted_string] = sym_double_quoted_string,
  [sym_backtick_quoted_string] = sym_backtick_quoted_string,
  [sym_function_definition] = sym_function_definition,
  [sym_block] = sym_block,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_single_quoted_string_repeat1] = aux_sym_single_quoted_string_repeat1,
  [aux_sym_double_quoted_string_repeat1] = aux_sym_double_quoted_string_repeat1,
  [aux_sym_backtick_quoted_string_repeat1] = aux_sym_backtick_quoted_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_numeric_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_U] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UU] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UUU] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_S] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SSS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_F] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FFF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SSF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_UFFF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Real] = {
    .visible = true,
    .named = false,
  },
  [sym_bool_type] = {
    .visible = true,
    .named = true,
  },
  [sym_void_type] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_CC] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CCC] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MMM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PPP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AAA] = {
    .visible = true,
    .named = false,
  },
  [sym_function_pointer_type] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_single_quoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_double_quoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_backtick_quoted_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_line_continuation] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bar] = {
    .visible = true,
    .named = false,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_scalar_type] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_type] = {
    .visible = true,
    .named = true,
  },
  [sym_unit_fractional_type] = {
    .visible = true,
    .named = true,
  },
  [sym_fixed_point_type] = {
    .visible = true,
    .named = true,
  },
  [sym_numeric_constant_type] = {
    .visible = true,
    .named = true,
  },
  [sym_quantity_type] = {
    .visible = true,
    .named = true,
  },
  [sym_pointer_type] = {
    .visible = true,
    .named = true,
  },
  [sym_address_type] = {
    .visible = true,
    .named = true,
  },
  [sym_array_type] = {
    .visible = true,
    .named = true,
  },
  [sym_typed_element_array_type] = {
    .visible = true,
    .named = true,
  },
  [sym_vector_type] = {
    .visible = true,
    .named = true,
  },
  [sym_pointer_addressable_array_type] = {
    .visible = true,
    .named = true,
  },
  [sym_single_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_double_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_backtick_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_single_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_double_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_backtick_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 11,
  [41] = 9,
  [42] = 5,
  [43] = 13,
  [44] = 12,
  [45] = 10,
  [46] = 6,
  [47] = 7,
  [48] = 8,
  [49] = 49,
  [50] = 50,
  [51] = 49,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 19,
  [59] = 20,
  [60] = 15,
  [61] = 14,
  [62] = 30,
  [63] = 29,
  [64] = 53,
  [65] = 65,
  [66] = 55,
  [67] = 56,
};

static TSCharacterRange sym_escape_sequence_character_set_1[] = {
  {'"', '"'}, {'\'', '\''}, {'/', '0'}, {'U', 'U'}, {'\\', '\\'}, {'`', 'b'}, {'f', 'f'}, {'n', 'n'},
  {'r', 'r'}, {'t', 'v'}, {'x', 'x'},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(66);
      if (lookahead == '\r') SKIP(64);
      if (lookahead == '"') ADVANCE(148);
      if (lookahead == '$') ADVANCE(13);
      if (lookahead == '%') ADVANCE(14);
      if (lookahead == '\'') ADVANCE(141);
      if (lookahead == '(') ADVANCE(8);
      if (lookahead == '.') ADVANCE(53);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == 'A') ADVANCE(16);
      if (lookahead == 'B') ADVANCE(39);
      if (lookahead == 'C') ADVANCE(18);
      if (lookahead == 'F') ADVANCE(87);
      if (lookahead == 'I') ADVANCE(37);
      if (lookahead == 'M') ADVANCE(21);
      if (lookahead == 'P') ADVANCE(23);
      if (lookahead == 'R') ADVANCE(29);
      if (lookahead == 'S') ADVANCE(81);
      if (lookahead == 'U') ADVANCE(75);
      if (lookahead == 'V') ADVANCE(40);
      if (lookahead == '[') ADVANCE(124);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == ']') ADVANCE(125);
      if (lookahead == '`') ADVANCE(155);
      if (lookahead == 'f') ADVANCE(25);
      if (lookahead == 't') ADVANCE(44);
      if (lookahead == '{') ADVANCE(51);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(64);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      if (('D' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(163);
      END_STATE();
    case 2:
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == 'U') ADVANCE(62);
      if (lookahead == 'u') ADVANCE(58);
      if (lookahead == 'x') ADVANCE(56);
      if ((!eof && lookahead == 00) ||
          lookahead == '\n') ADVANCE(163);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(162);
      END_STATE();
    case 3:
      if (lookahead == '\r') ADVANCE(1);
      if ((!eof && lookahead == 00) ||
          lookahead == '\n') ADVANCE(163);
      END_STATE();
    case 4:
      if (lookahead == '\r') ADVANCE(149);
      if (lookahead == '"') ADVANCE(148);
      if (lookahead == '/') ADVANCE(150);
      if (lookahead == '\\') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(149);
      if (lookahead != 0) ADVANCE(154);
      END_STATE();
    case 5:
      if (lookahead == '\r') ADVANCE(156);
      if (lookahead == '/') ADVANCE(157);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '`') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(156);
      if (lookahead != 0) ADVANCE(161);
      END_STATE();
    case 6:
      if (lookahead == '\r') ADVANCE(142);
      if (lookahead == '\'') ADVANCE(141);
      if (lookahead == '/') ADVANCE(143);
      if (lookahead == '\\') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(142);
      if (lookahead != 0) ADVANCE(147);
      END_STATE();
    case 7:
      if (lookahead == '\r') SKIP(7);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '\\') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 8:
      if (lookahead == ')') ADVANCE(168);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(165);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(164);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '.') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 13:
      if (lookahead == '.') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(70);
      END_STATE();
    case 14:
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(71);
      END_STATE();
    case 15:
      if (lookahead == '.') ADVANCE(46);
      END_STATE();
    case 16:
      if (lookahead == 'A') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 17:
      if (lookahead == 'A') ADVANCE(120);
      END_STATE();
    case 18:
      if (lookahead == 'C') ADVANCE(107);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 19:
      if (lookahead == 'C') ADVANCE(108);
      END_STATE();
    case 20:
      if (lookahead == 'F') ADVANCE(97);
      END_STATE();
    case 21:
      if (lookahead == 'M') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 22:
      if (lookahead == 'M') ADVANCE(112);
      END_STATE();
    case 23:
      if (lookahead == 'P') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 24:
      if (lookahead == 'P') ADVANCE(116);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(133);
      if (lookahead == 'n') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'n') ADVANCE(166);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(35);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(105);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 33:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(103);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 36:
      if (lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 39:
      if (lookahead == 'o') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(42);
      END_STATE();
    case 44:
      if (lookahead == 'r') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(50);
      END_STATE();
    case 46:
      if (lookahead == 's') ADVANCE(30);
      END_STATE();
    case 47:
      if (lookahead == 's') ADVANCE(32);
      END_STATE();
    case 48:
      if (lookahead == 't') ADVANCE(123);
      END_STATE();
    case 49:
      if (lookahead == 't') ADVANCE(99);
      END_STATE();
    case 50:
      if (lookahead == 'u') ADVANCE(32);
      END_STATE();
    case 51:
      if (lookahead == '}') ADVANCE(126);
      END_STATE();
    case 52:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(72);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(162);
      END_STATE();
    case 55:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(74);
      END_STATE();
    case 56:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 57:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 58:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(58);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 61:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 62:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(61);
      END_STATE();
    case 63:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 64:
      if (eof) ADVANCE(66);
      if (lookahead == '\r') SKIP(64);
      if (lookahead == '"') ADVANCE(148);
      if (lookahead == '$') ADVANCE(13);
      if (lookahead == '%') ADVANCE(14);
      if (lookahead == '\'') ADVANCE(141);
      if (lookahead == '(') ADVANCE(8);
      if (lookahead == '.') ADVANCE(53);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == 'A') ADVANCE(16);
      if (lookahead == 'B') ADVANCE(39);
      if (lookahead == 'C') ADVANCE(18);
      if (lookahead == 'F') ADVANCE(87);
      if (lookahead == 'I') ADVANCE(37);
      if (lookahead == 'M') ADVANCE(21);
      if (lookahead == 'P') ADVANCE(23);
      if (lookahead == 'R') ADVANCE(29);
      if (lookahead == 'S') ADVANCE(81);
      if (lookahead == 'U') ADVANCE(75);
      if (lookahead == 'V') ADVANCE(40);
      if (lookahead == '[') ADVANCE(124);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == ']') ADVANCE(125);
      if (lookahead == '`') ADVANCE(155);
      if (lookahead == 'f') ADVANCE(25);
      if (lookahead == 't') ADVANCE(44);
      if (lookahead == '{') ADVANCE(51);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(64);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      if (('D' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 65:
      if (eof) ADVANCE(66);
      if (lookahead == '\r') SKIP(65);
      if (lookahead == '"') ADVANCE(148);
      if (lookahead == '$') ADVANCE(13);
      if (lookahead == '%') ADVANCE(14);
      if (lookahead == '\'') ADVANCE(141);
      if (lookahead == '.') ADVANCE(53);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == 'A') ADVANCE(17);
      if (lookahead == 'B') ADVANCE(43);
      if (lookahead == 'C') ADVANCE(19);
      if (lookahead == 'F') ADVANCE(88);
      if (lookahead == 'I') ADVANCE(38);
      if (lookahead == 'M') ADVANCE(22);
      if (lookahead == 'P') ADVANCE(24);
      if (lookahead == 'R') ADVANCE(31);
      if (lookahead == 'S') ADVANCE(82);
      if (lookahead == 'U') ADVANCE(76);
      if (lookahead == 'V') ADVANCE(41);
      if (lookahead == '[') ADVANCE(124);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '`') ADVANCE(155);
      if (lookahead == 'f') ADVANCE(26);
      if (lookahead == 't') ADVANCE(45);
      if (lookahead == '{') ADVANCE(51);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_boolean_literal);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_boolean_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(72);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_U);
      if (lookahead == 'F') ADVANCE(93);
      if (lookahead == 'U') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_U);
      if (lookahead == 'F') ADVANCE(94);
      if (lookahead == 'U') ADVANCE(78);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_UU);
      if (lookahead == 'U') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_UU);
      if (lookahead == 'U') ADVANCE(79);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_UUU);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_UUU);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_S);
      if (lookahead == 'S') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_S);
      if (lookahead == 'S') ADVANCE(84);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_SS);
      if (lookahead == 'F') ADVANCE(96);
      if (lookahead == 'S') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_SS);
      if (lookahead == 'F') ADVANCE(95);
      if (lookahead == 'S') ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_SSS);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_SSS);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_F);
      if (lookahead == 'F') ADVANCE(89);
      if (lookahead == 'n') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_F);
      if (lookahead == 'F') ADVANCE(90);
      if (lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_FF);
      if (lookahead == 'F') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_FF);
      if (lookahead == 'F') ADVANCE(91);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_FFF);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_FFF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_UF);
      if (lookahead == 'F') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_UF);
      if (lookahead == 'F') ADVANCE(20);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_SSF);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_SSF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_UFFF);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_UFFF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_Int);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_Int);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_Real);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_Real);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_bool_type);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_bool_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_void_type);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_void_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_CC);
      if (lookahead == 'C') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_CC);
      if (lookahead == 'C') ADVANCE(109);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_CCC);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_CCC);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_MM);
      if (lookahead == 'M') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_MM);
      if (lookahead == 'M') ADVANCE(113);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_MMM);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_MMM);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_PP);
      if (lookahead == 'P') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_PP);
      if (lookahead == 'P') ADVANCE(117);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_PPP);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_PPP);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_AA);
      if (lookahead == 'A') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_AA);
      if (lookahead == 'A') ADVANCE(121);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_AAA);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_AAA);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_function_pointer_type);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_LBRACE_RBRACE);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '\r') ADVANCE(142);
      if (lookahead == '/') ADVANCE(143);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(147);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == '/') ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(147);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(144);
      if (lookahead == '/') ADVANCE(147);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(11);
      if (lookahead != 0) ADVANCE(145);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(144);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(11);
      if (lookahead != 0) ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(165);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(147);
      if (lookahead != 0) ADVANCE(146);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(147);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '\r') ADVANCE(149);
      if (lookahead == '/') ADVANCE(150);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(154);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(152);
      if (lookahead == '/') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(154);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == '/') ADVANCE(154);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(11);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(11);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(165);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(154);
      if (lookahead != 0) ADVANCE(153);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(154);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '\r') ADVANCE(156);
      if (lookahead == '/') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(156);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(161);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(159);
      if (lookahead == '/') ADVANCE(160);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(161);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == '/') ADVANCE(161);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(11);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(11);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(165);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(161);
      if (lookahead != 0) ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(161);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_line_continuation);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(165);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_fn);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(140);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_LPAREN_RPAREN);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == '\r') SKIP(0);
      if (lookahead == 'b') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == 'r') ADVANCE(3);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_bar);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 65},
  [2] = {.lex_state = 65},
  [3] = {.lex_state = 65},
  [4] = {.lex_state = 65},
  [5] = {.lex_state = 65},
  [6] = {.lex_state = 65},
  [7] = {.lex_state = 65},
  [8] = {.lex_state = 65},
  [9] = {.lex_state = 65},
  [10] = {.lex_state = 65},
  [11] = {.lex_state = 65},
  [12] = {.lex_state = 65},
  [13] = {.lex_state = 65},
  [14] = {.lex_state = 65},
  [15] = {.lex_state = 65},
  [16] = {.lex_state = 65},
  [17] = {.lex_state = 65},
  [18] = {.lex_state = 65},
  [19] = {.lex_state = 65},
  [20] = {.lex_state = 65},
  [21] = {.lex_state = 65},
  [22] = {.lex_state = 65},
  [23] = {.lex_state = 65},
  [24] = {.lex_state = 65},
  [25] = {.lex_state = 65},
  [26] = {.lex_state = 65},
  [27] = {.lex_state = 65},
  [28] = {.lex_state = 65},
  [29] = {.lex_state = 65},
  [30] = {.lex_state = 65},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 5},
  [33] = {.lex_state = 4},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 6},
  [37] = {.lex_state = 5},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 6},
  [40] = {.lex_state = 0, .external_lex_state = 2},
  [41] = {.lex_state = 0, .external_lex_state = 2},
  [42] = {.lex_state = 0, .external_lex_state = 2},
  [43] = {.lex_state = 0, .external_lex_state = 2},
  [44] = {.lex_state = 0, .external_lex_state = 2},
  [45] = {.lex_state = 0, .external_lex_state = 2},
  [46] = {.lex_state = 0, .external_lex_state = 2},
  [47] = {.lex_state = 0, .external_lex_state = 2},
  [48] = {.lex_state = 0, .external_lex_state = 2},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0, .external_lex_state = 2},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 7},
  [58] = {.lex_state = 0, .external_lex_state = 2},
  [59] = {.lex_state = 0, .external_lex_state = 2},
  [60] = {.lex_state = 0, .external_lex_state = 2},
  [61] = {.lex_state = 0, .external_lex_state = 2},
  [62] = {.lex_state = 0, .external_lex_state = 2},
  [63] = {.lex_state = 0, .external_lex_state = 2},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 7},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_boolean_literal] = ACTIONS(1),
    [sym_numeric_literal] = ACTIONS(1),
    [anon_sym_U] = ACTIONS(1),
    [anon_sym_UU] = ACTIONS(1),
    [anon_sym_UUU] = ACTIONS(1),
    [anon_sym_S] = ACTIONS(1),
    [anon_sym_SS] = ACTIONS(1),
    [anon_sym_SSS] = ACTIONS(1),
    [anon_sym_F] = ACTIONS(1),
    [anon_sym_FF] = ACTIONS(1),
    [anon_sym_FFF] = ACTIONS(1),
    [anon_sym_UF] = ACTIONS(1),
    [anon_sym_SSF] = ACTIONS(1),
    [anon_sym_UFFF] = ACTIONS(1),
    [anon_sym_Int] = ACTIONS(1),
    [anon_sym_Real] = ACTIONS(1),
    [sym_bool_type] = ACTIONS(1),
    [sym_void_type] = ACTIONS(1),
    [anon_sym_CC] = ACTIONS(1),
    [anon_sym_CCC] = ACTIONS(1),
    [anon_sym_MM] = ACTIONS(1),
    [anon_sym_MMM] = ACTIONS(1),
    [anon_sym_PP] = ACTIONS(1),
    [anon_sym_PPP] = ACTIONS(1),
    [anon_sym_AA] = ACTIONS(1),
    [anon_sym_AAA] = ACTIONS(1),
    [sym_function_pointer_type] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_LPAREN_RPAREN] = ACTIONS(1),
    [anon_sym_bar] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(54),
    [sym_statement] = STATE(3),
    [sym_literal] = STATE(18),
    [sym_string_literal] = STATE(22),
    [sym_type] = STATE(18),
    [sym_scalar_type] = STATE(5),
    [sym_integer_type] = STATE(10),
    [sym_unit_fractional_type] = STATE(10),
    [sym_fixed_point_type] = STATE(10),
    [sym_numeric_constant_type] = STATE(10),
    [sym_quantity_type] = STATE(5),
    [sym_pointer_type] = STATE(13),
    [sym_address_type] = STATE(13),
    [sym_array_type] = STATE(19),
    [sym_typed_element_array_type] = STATE(20),
    [sym_vector_type] = STATE(20),
    [sym_pointer_addressable_array_type] = STATE(20),
    [sym_single_quoted_string] = STATE(21),
    [sym_double_quoted_string] = STATE(21),
    [sym_backtick_quoted_string] = STATE(21),
    [sym_function_definition] = STATE(18),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_boolean_literal] = ACTIONS(7),
    [sym_numeric_literal] = ACTIONS(7),
    [anon_sym_U] = ACTIONS(9),
    [anon_sym_UU] = ACTIONS(9),
    [anon_sym_UUU] = ACTIONS(11),
    [anon_sym_S] = ACTIONS(9),
    [anon_sym_SS] = ACTIONS(9),
    [anon_sym_SSS] = ACTIONS(11),
    [anon_sym_F] = ACTIONS(13),
    [anon_sym_FF] = ACTIONS(13),
    [anon_sym_FFF] = ACTIONS(15),
    [anon_sym_UF] = ACTIONS(17),
    [anon_sym_SSF] = ACTIONS(19),
    [anon_sym_UFFF] = ACTIONS(19),
    [anon_sym_Int] = ACTIONS(21),
    [anon_sym_Real] = ACTIONS(21),
    [sym_bool_type] = ACTIONS(23),
    [sym_void_type] = ACTIONS(23),
    [anon_sym_CC] = ACTIONS(25),
    [anon_sym_CCC] = ACTIONS(27),
    [anon_sym_MM] = ACTIONS(25),
    [anon_sym_MMM] = ACTIONS(27),
    [anon_sym_PP] = ACTIONS(25),
    [anon_sym_PPP] = ACTIONS(27),
    [anon_sym_AA] = ACTIONS(29),
    [anon_sym_AAA] = ACTIONS(31),
    [sym_function_pointer_type] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_SQUOTE] = ACTIONS(37),
    [anon_sym_DQUOTE] = ACTIONS(39),
    [anon_sym_BQUOTE] = ACTIONS(41),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(43),
  },
  [2] = {
    [sym_statement] = STATE(2),
    [sym_literal] = STATE(18),
    [sym_string_literal] = STATE(22),
    [sym_type] = STATE(18),
    [sym_scalar_type] = STATE(5),
    [sym_integer_type] = STATE(10),
    [sym_unit_fractional_type] = STATE(10),
    [sym_fixed_point_type] = STATE(10),
    [sym_numeric_constant_type] = STATE(10),
    [sym_quantity_type] = STATE(5),
    [sym_pointer_type] = STATE(13),
    [sym_address_type] = STATE(13),
    [sym_array_type] = STATE(19),
    [sym_typed_element_array_type] = STATE(20),
    [sym_vector_type] = STATE(20),
    [sym_pointer_addressable_array_type] = STATE(20),
    [sym_single_quoted_string] = STATE(21),
    [sym_double_quoted_string] = STATE(21),
    [sym_backtick_quoted_string] = STATE(21),
    [sym_function_definition] = STATE(18),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_boolean_literal] = ACTIONS(47),
    [sym_numeric_literal] = ACTIONS(47),
    [anon_sym_U] = ACTIONS(50),
    [anon_sym_UU] = ACTIONS(50),
    [anon_sym_UUU] = ACTIONS(53),
    [anon_sym_S] = ACTIONS(50),
    [anon_sym_SS] = ACTIONS(50),
    [anon_sym_SSS] = ACTIONS(53),
    [anon_sym_F] = ACTIONS(56),
    [anon_sym_FF] = ACTIONS(56),
    [anon_sym_FFF] = ACTIONS(59),
    [anon_sym_UF] = ACTIONS(62),
    [anon_sym_SSF] = ACTIONS(65),
    [anon_sym_UFFF] = ACTIONS(65),
    [anon_sym_Int] = ACTIONS(68),
    [anon_sym_Real] = ACTIONS(68),
    [sym_bool_type] = ACTIONS(71),
    [sym_void_type] = ACTIONS(71),
    [anon_sym_CC] = ACTIONS(74),
    [anon_sym_CCC] = ACTIONS(77),
    [anon_sym_MM] = ACTIONS(74),
    [anon_sym_MMM] = ACTIONS(77),
    [anon_sym_PP] = ACTIONS(74),
    [anon_sym_PPP] = ACTIONS(77),
    [anon_sym_AA] = ACTIONS(80),
    [anon_sym_AAA] = ACTIONS(83),
    [sym_function_pointer_type] = ACTIONS(86),
    [anon_sym_LBRACK] = ACTIONS(89),
    [anon_sym_SQUOTE] = ACTIONS(92),
    [anon_sym_DQUOTE] = ACTIONS(95),
    [anon_sym_BQUOTE] = ACTIONS(98),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(101),
  },
  [3] = {
    [sym_statement] = STATE(2),
    [sym_literal] = STATE(18),
    [sym_string_literal] = STATE(22),
    [sym_type] = STATE(18),
    [sym_scalar_type] = STATE(5),
    [sym_integer_type] = STATE(10),
    [sym_unit_fractional_type] = STATE(10),
    [sym_fixed_point_type] = STATE(10),
    [sym_numeric_constant_type] = STATE(10),
    [sym_quantity_type] = STATE(5),
    [sym_pointer_type] = STATE(13),
    [sym_address_type] = STATE(13),
    [sym_array_type] = STATE(19),
    [sym_typed_element_array_type] = STATE(20),
    [sym_vector_type] = STATE(20),
    [sym_pointer_addressable_array_type] = STATE(20),
    [sym_single_quoted_string] = STATE(21),
    [sym_double_quoted_string] = STATE(21),
    [sym_backtick_quoted_string] = STATE(21),
    [sym_function_definition] = STATE(18),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(104),
    [sym_boolean_literal] = ACTIONS(7),
    [sym_numeric_literal] = ACTIONS(7),
    [anon_sym_U] = ACTIONS(9),
    [anon_sym_UU] = ACTIONS(9),
    [anon_sym_UUU] = ACTIONS(11),
    [anon_sym_S] = ACTIONS(9),
    [anon_sym_SS] = ACTIONS(9),
    [anon_sym_SSS] = ACTIONS(11),
    [anon_sym_F] = ACTIONS(13),
    [anon_sym_FF] = ACTIONS(13),
    [anon_sym_FFF] = ACTIONS(15),
    [anon_sym_UF] = ACTIONS(17),
    [anon_sym_SSF] = ACTIONS(19),
    [anon_sym_UFFF] = ACTIONS(19),
    [anon_sym_Int] = ACTIONS(21),
    [anon_sym_Real] = ACTIONS(21),
    [sym_bool_type] = ACTIONS(23),
    [sym_void_type] = ACTIONS(23),
    [anon_sym_CC] = ACTIONS(25),
    [anon_sym_CCC] = ACTIONS(27),
    [anon_sym_MM] = ACTIONS(25),
    [anon_sym_MMM] = ACTIONS(27),
    [anon_sym_PP] = ACTIONS(25),
    [anon_sym_PPP] = ACTIONS(27),
    [anon_sym_AA] = ACTIONS(29),
    [anon_sym_AAA] = ACTIONS(31),
    [sym_function_pointer_type] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_SQUOTE] = ACTIONS(37),
    [anon_sym_DQUOTE] = ACTIONS(39),
    [anon_sym_BQUOTE] = ACTIONS(41),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(43),
  },
  [4] = {
    [sym_type] = STATE(50),
    [sym_scalar_type] = STATE(42),
    [sym_integer_type] = STATE(45),
    [sym_unit_fractional_type] = STATE(45),
    [sym_fixed_point_type] = STATE(45),
    [sym_numeric_constant_type] = STATE(45),
    [sym_quantity_type] = STATE(42),
    [sym_pointer_type] = STATE(43),
    [sym_address_type] = STATE(43),
    [sym_array_type] = STATE(58),
    [sym_typed_element_array_type] = STATE(59),
    [sym_vector_type] = STATE(59),
    [sym_pointer_addressable_array_type] = STATE(59),
    [anon_sym_U] = ACTIONS(106),
    [anon_sym_UU] = ACTIONS(106),
    [anon_sym_UUU] = ACTIONS(108),
    [anon_sym_S] = ACTIONS(106),
    [anon_sym_SS] = ACTIONS(106),
    [anon_sym_SSS] = ACTIONS(108),
    [anon_sym_F] = ACTIONS(110),
    [anon_sym_FF] = ACTIONS(110),
    [anon_sym_FFF] = ACTIONS(112),
    [anon_sym_UF] = ACTIONS(114),
    [anon_sym_SSF] = ACTIONS(116),
    [anon_sym_UFFF] = ACTIONS(116),
    [anon_sym_Int] = ACTIONS(118),
    [anon_sym_Real] = ACTIONS(118),
    [sym_bool_type] = ACTIONS(120),
    [sym_void_type] = ACTIONS(120),
    [anon_sym_CC] = ACTIONS(122),
    [anon_sym_CCC] = ACTIONS(124),
    [anon_sym_MM] = ACTIONS(122),
    [anon_sym_MMM] = ACTIONS(124),
    [anon_sym_PP] = ACTIONS(122),
    [anon_sym_PPP] = ACTIONS(124),
    [anon_sym_AA] = ACTIONS(126),
    [anon_sym_AAA] = ACTIONS(128),
    [sym_function_pointer_type] = ACTIONS(130),
    [anon_sym_LBRACK] = ACTIONS(132),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(138), 1,
      anon_sym_LBRACK,
    ACTIONS(140), 1,
      anon_sym_LBRACE_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(136), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(134), 21,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [47] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(144), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(142), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [90] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(148), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(146), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [133] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(152), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(150), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [176] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(156), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(154), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [219] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(160), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(158), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [262] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(164), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(162), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [305] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(168), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(166), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [348] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(172), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(170), 23,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [391] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(176), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(174), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [433] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(180), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(178), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [475] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(184), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(182), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [517] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(188), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(186), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [559] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(192), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(190), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [601] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(136), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(134), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [643] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(196), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(194), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [685] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(200), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(198), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [727] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(204), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(202), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [769] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(208), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(206), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [811] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(212), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(210), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [853] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(216), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(214), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [895] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(220), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(218), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [937] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(224), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(222), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [979] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(228), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(226), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [1021] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(232), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(230), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [1063] = 3,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(236), 11,
      anon_sym_U,
      anon_sym_UU,
      anon_sym_S,
      anon_sym_SS,
      anon_sym_F,
      anon_sym_FF,
      anon_sym_UF,
      anon_sym_CC,
      anon_sym_MM,
      anon_sym_PP,
      anon_sym_AA,
    ACTIONS(234), 22,
      ts_builtin_sym_end,
      sym_boolean_literal,
      sym_numeric_literal,
      anon_sym_UUU,
      anon_sym_SSS,
      anon_sym_FFF,
      anon_sym_SSF,
      anon_sym_UFFF,
      anon_sym_Int,
      anon_sym_Real,
      sym_bool_type,
      sym_void_type,
      anon_sym_CCC,
      anon_sym_MMM,
      anon_sym_PPP,
      anon_sym_AAA,
      sym_function_pointer_type,
      anon_sym_LBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_BQUOTE,
      anon_sym_fn,
  [1105] = 5,
    ACTIONS(238), 1,
      anon_sym_DQUOTE,
    ACTIONS(240), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(242), 1,
      sym_escape_sequence,
    STATE(38), 1,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1122] = 5,
    ACTIONS(246), 1,
      anon_sym_BQUOTE,
    ACTIONS(248), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(250), 1,
      sym_escape_sequence,
    STATE(37), 1,
      aux_sym_backtick_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1139] = 5,
    ACTIONS(252), 1,
      anon_sym_DQUOTE,
    ACTIONS(254), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(256), 1,
      sym_escape_sequence,
    STATE(31), 1,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1156] = 5,
    ACTIONS(258), 1,
      anon_sym_SQUOTE,
    ACTIONS(260), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(262), 1,
      sym_escape_sequence,
    STATE(39), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1173] = 5,
    ACTIONS(264), 1,
      anon_sym_BQUOTE,
    ACTIONS(266), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(268), 1,
      sym_escape_sequence,
    STATE(32), 1,
      aux_sym_backtick_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1190] = 5,
    ACTIONS(270), 1,
      anon_sym_SQUOTE,
    ACTIONS(272), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(275), 1,
      sym_escape_sequence,
    STATE(36), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1207] = 5,
    ACTIONS(278), 1,
      anon_sym_BQUOTE,
    ACTIONS(280), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(283), 1,
      sym_escape_sequence,
    STATE(37), 1,
      aux_sym_backtick_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1224] = 5,
    ACTIONS(286), 1,
      anon_sym_DQUOTE,
    ACTIONS(288), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(291), 1,
      sym_escape_sequence,
    STATE(38), 1,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1241] = 5,
    ACTIONS(294), 1,
      anon_sym_SQUOTE,
    ACTIONS(296), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(298), 1,
      sym_escape_sequence,
    STATE(36), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(244), 2,
      sym_line_continuation,
      sym_comment,
  [1258] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(162), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1268] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(154), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1278] = 4,
    ACTIONS(134), 1,
      sym__indent,
    ACTIONS(300), 1,
      anon_sym_LBRACK,
    ACTIONS(302), 1,
      anon_sym_LBRACE_RBRACE,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1292] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(170), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1302] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(166), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1312] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(158), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1322] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(142), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1332] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(146), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1342] = 2,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
    ACTIONS(150), 3,
      sym__indent,
      anon_sym_LBRACK,
      anon_sym_LBRACE_RBRACE,
  [1352] = 3,
    ACTIONS(304), 1,
      sym_numeric_literal,
    ACTIONS(306), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1363] = 3,
    ACTIONS(308), 1,
      sym__indent,
    STATE(23), 1,
      sym_block,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1374] = 3,
    ACTIONS(310), 1,
      sym_numeric_literal,
    ACTIONS(312), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1385] = 2,
    ACTIONS(314), 1,
      anon_sym_LPAREN_RPAREN,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1393] = 2,
    ACTIONS(316), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1401] = 2,
    ACTIONS(318), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1409] = 2,
    ACTIONS(320), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1417] = 2,
    ACTIONS(322), 1,
      sym_numeric_literal,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1425] = 2,
    ACTIONS(324), 1,
      anon_sym_bar,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1433] = 2,
    ACTIONS(134), 1,
      sym__indent,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1441] = 2,
    ACTIONS(194), 1,
      sym__indent,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1449] = 2,
    ACTIONS(178), 1,
      sym__indent,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1457] = 2,
    ACTIONS(174), 1,
      sym__indent,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1465] = 2,
    ACTIONS(234), 1,
      sym__indent,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1473] = 2,
    ACTIONS(230), 1,
      sym__indent,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1481] = 2,
    ACTIONS(326), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1489] = 2,
    ACTIONS(328), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1497] = 2,
    ACTIONS(330), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [1505] = 2,
    ACTIONS(332), 1,
      sym_numeric_literal,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 47,
  [SMALL_STATE(7)] = 90,
  [SMALL_STATE(8)] = 133,
  [SMALL_STATE(9)] = 176,
  [SMALL_STATE(10)] = 219,
  [SMALL_STATE(11)] = 262,
  [SMALL_STATE(12)] = 305,
  [SMALL_STATE(13)] = 348,
  [SMALL_STATE(14)] = 391,
  [SMALL_STATE(15)] = 433,
  [SMALL_STATE(16)] = 475,
  [SMALL_STATE(17)] = 517,
  [SMALL_STATE(18)] = 559,
  [SMALL_STATE(19)] = 601,
  [SMALL_STATE(20)] = 643,
  [SMALL_STATE(21)] = 685,
  [SMALL_STATE(22)] = 727,
  [SMALL_STATE(23)] = 769,
  [SMALL_STATE(24)] = 811,
  [SMALL_STATE(25)] = 853,
  [SMALL_STATE(26)] = 895,
  [SMALL_STATE(27)] = 937,
  [SMALL_STATE(28)] = 979,
  [SMALL_STATE(29)] = 1021,
  [SMALL_STATE(30)] = 1063,
  [SMALL_STATE(31)] = 1105,
  [SMALL_STATE(32)] = 1122,
  [SMALL_STATE(33)] = 1139,
  [SMALL_STATE(34)] = 1156,
  [SMALL_STATE(35)] = 1173,
  [SMALL_STATE(36)] = 1190,
  [SMALL_STATE(37)] = 1207,
  [SMALL_STATE(38)] = 1224,
  [SMALL_STATE(39)] = 1241,
  [SMALL_STATE(40)] = 1258,
  [SMALL_STATE(41)] = 1268,
  [SMALL_STATE(42)] = 1278,
  [SMALL_STATE(43)] = 1292,
  [SMALL_STATE(44)] = 1302,
  [SMALL_STATE(45)] = 1312,
  [SMALL_STATE(46)] = 1322,
  [SMALL_STATE(47)] = 1332,
  [SMALL_STATE(48)] = 1342,
  [SMALL_STATE(49)] = 1352,
  [SMALL_STATE(50)] = 1363,
  [SMALL_STATE(51)] = 1374,
  [SMALL_STATE(52)] = 1385,
  [SMALL_STATE(53)] = 1393,
  [SMALL_STATE(54)] = 1401,
  [SMALL_STATE(55)] = 1409,
  [SMALL_STATE(56)] = 1417,
  [SMALL_STATE(57)] = 1425,
  [SMALL_STATE(58)] = 1433,
  [SMALL_STATE(59)] = 1441,
  [SMALL_STATE(60)] = 1449,
  [SMALL_STATE(61)] = 1457,
  [SMALL_STATE(62)] = 1465,
  [SMALL_STATE(63)] = 1473,
  [SMALL_STATE(64)] = 1481,
  [SMALL_STATE(65)] = 1489,
  [SMALL_STATE(66)] = 1497,
  [SMALL_STATE(67)] = 1505,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_type, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_type, 1, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unit_fractional_type, 1, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unit_fractional_type, 1, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fixed_point_type, 1, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fixed_point_type, 1, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_numeric_constant_type, 1, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_numeric_constant_type, 1, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scalar_type, 1, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scalar_type, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pointer_type, 1, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pointer_type, 1, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_address_type, 1, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_address_type, 1, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_type, 1, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quantity_type, 1, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pointer_addressable_array_type, 3, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pointer_addressable_array_type, 3, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector_type, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector_type, 2, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_backtick_quoted_string, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_backtick_quoted_string, 3, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 1, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_type, 1, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 1, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 1, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 5, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_backtick_quoted_string, 2, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_backtick_quoted_string, 2, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typed_element_array_type, 4, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typed_element_array_type, 4, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typed_element_array_type, 3, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typed_element_array_type, 3, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [240] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [244] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [252] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [254] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [266] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0),
  [272] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [275] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0),
  [280] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [283] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0),
  [288] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [291] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [294] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [318] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__indent = 0,
  ts_external_token__dedent = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
};

static const bool ts_external_scanner_states[3][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
  },
  [2] = {
    [ts_external_token__indent] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_nesfab_external_scanner_create(void);
void tree_sitter_nesfab_external_scanner_destroy(void *);
bool tree_sitter_nesfab_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_nesfab_external_scanner_serialize(void *, char *);
void tree_sitter_nesfab_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_nesfab(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_nesfab_external_scanner_create,
      tree_sitter_nesfab_external_scanner_destroy,
      tree_sitter_nesfab_external_scanner_scan,
      tree_sitter_nesfab_external_scanner_serialize,
      tree_sitter_nesfab_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
