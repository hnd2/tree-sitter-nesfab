#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 42
#define LARGE_STATE_COUNT 28
#define SYMBOL_COUNT 65
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
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
  sym_program = 41,
  sym_statement = 42,
  sym_literal = 43,
  sym_string_literal = 44,
  sym_type = 45,
  sym_scalar_type = 46,
  sym_integer_type = 47,
  sym_unit_fractional_type = 48,
  sym_fixed_point_type = 49,
  sym_numeric_constant_type = 50,
  sym_quantity_type = 51,
  sym_pointer_type = 52,
  sym_address_type = 53,
  sym_array_type = 54,
  sym_typed_element_array_type = 55,
  sym_vector_type = 56,
  sym_pointer_addressable_array_type = 57,
  sym_single_quoted_string = 58,
  sym_double_quoted_string = 59,
  sym_backtick_quoted_string = 60,
  aux_sym_program_repeat1 = 61,
  aux_sym_single_quoted_string_repeat1 = 62,
  aux_sym_double_quoted_string_repeat1 = 63,
  aux_sym_backtick_quoted_string_repeat1 = 64,
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
  [40] = 40,
  [41] = 41,
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
      if (eof) ADVANCE(64);
      if (lookahead == '\r') SKIP(62);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '$') ADVANCE(11);
      if (lookahead == '%') ADVANCE(12);
      if (lookahead == '\'') ADVANCE(139);
      if (lookahead == '.') ADVANCE(51);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == 'A') ADVANCE(14);
      if (lookahead == 'B') ADVANCE(37);
      if (lookahead == 'C') ADVANCE(16);
      if (lookahead == 'F') ADVANCE(85);
      if (lookahead == 'I') ADVANCE(35);
      if (lookahead == 'M') ADVANCE(19);
      if (lookahead == 'P') ADVANCE(21);
      if (lookahead == 'R') ADVANCE(27);
      if (lookahead == 'S') ADVANCE(79);
      if (lookahead == 'U') ADVANCE(73);
      if (lookahead == 'V') ADVANCE(38);
      if (lookahead == '[') ADVANCE(122);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == ']') ADVANCE(123);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'f') ADVANCE(23);
      if (lookahead == 't') ADVANCE(42);
      if (lookahead == '{') ADVANCE(49);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('D' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(161);
      END_STATE();
    case 2:
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == 'U') ADVANCE(60);
      if (lookahead == 'u') ADVANCE(56);
      if (lookahead == 'x') ADVANCE(54);
      if ((!eof && lookahead == 00) ||
          lookahead == '\n') ADVANCE(161);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(160);
      END_STATE();
    case 3:
      if (lookahead == '\r') ADVANCE(1);
      if ((!eof && lookahead == 00) ||
          lookahead == '\n') ADVANCE(161);
      END_STATE();
    case 4:
      if (lookahead == '\r') ADVANCE(140);
      if (lookahead == '\'') ADVANCE(139);
      if (lookahead == '/') ADVANCE(141);
      if (lookahead == '\\') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(140);
      if (lookahead != 0) ADVANCE(145);
      END_STATE();
    case 5:
      if (lookahead == '\r') ADVANCE(154);
      if (lookahead == '/') ADVANCE(155);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '`') ADVANCE(153);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(154);
      if (lookahead != 0) ADVANCE(159);
      END_STATE();
    case 6:
      if (lookahead == '\r') ADVANCE(147);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '/') ADVANCE(148);
      if (lookahead == '\\') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(147);
      if (lookahead != 0) ADVANCE(152);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(163);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(8);
      if (lookahead == '/') ADVANCE(162);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 11:
      if (lookahead == '.') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(68);
      END_STATE();
    case 12:
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(69);
      END_STATE();
    case 13:
      if (lookahead == '.') ADVANCE(44);
      END_STATE();
    case 14:
      if (lookahead == 'A') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 15:
      if (lookahead == 'A') ADVANCE(118);
      END_STATE();
    case 16:
      if (lookahead == 'C') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 17:
      if (lookahead == 'C') ADVANCE(106);
      END_STATE();
    case 18:
      if (lookahead == 'F') ADVANCE(95);
      END_STATE();
    case 19:
      if (lookahead == 'M') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 20:
      if (lookahead == 'M') ADVANCE(110);
      END_STATE();
    case 21:
      if (lookahead == 'P') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 22:
      if (lookahead == 'P') ADVANCE(114);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(34);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(33);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(103);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(46);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 31:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(99);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(45);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 37:
      if (lookahead == 'o') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 38:
      if (lookahead == 'o') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 39:
      if (lookahead == 'o') ADVANCE(31);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead == 'r') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 44:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 45:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 46:
      if (lookahead == 't') ADVANCE(121);
      END_STATE();
    case 47:
      if (lookahead == 't') ADVANCE(97);
      END_STATE();
    case 48:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 49:
      if (lookahead == '}') ADVANCE(124);
      END_STATE();
    case 50:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(70);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(160);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 55:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 56:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
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
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 62:
      if (eof) ADVANCE(64);
      if (lookahead == '\r') SKIP(62);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '$') ADVANCE(11);
      if (lookahead == '%') ADVANCE(12);
      if (lookahead == '\'') ADVANCE(139);
      if (lookahead == '.') ADVANCE(51);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == 'A') ADVANCE(14);
      if (lookahead == 'B') ADVANCE(37);
      if (lookahead == 'C') ADVANCE(16);
      if (lookahead == 'F') ADVANCE(85);
      if (lookahead == 'I') ADVANCE(35);
      if (lookahead == 'M') ADVANCE(19);
      if (lookahead == 'P') ADVANCE(21);
      if (lookahead == 'R') ADVANCE(27);
      if (lookahead == 'S') ADVANCE(79);
      if (lookahead == 'U') ADVANCE(73);
      if (lookahead == 'V') ADVANCE(38);
      if (lookahead == '[') ADVANCE(122);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == ']') ADVANCE(123);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'f') ADVANCE(23);
      if (lookahead == 't') ADVANCE(42);
      if (lookahead == '{') ADVANCE(49);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('D' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 63:
      if (eof) ADVANCE(64);
      if (lookahead == '\r') SKIP(63);
      if (lookahead == '"') ADVANCE(146);
      if (lookahead == '$') ADVANCE(11);
      if (lookahead == '%') ADVANCE(12);
      if (lookahead == '\'') ADVANCE(139);
      if (lookahead == '.') ADVANCE(51);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == 'A') ADVANCE(15);
      if (lookahead == 'B') ADVANCE(41);
      if (lookahead == 'C') ADVANCE(17);
      if (lookahead == 'F') ADVANCE(86);
      if (lookahead == 'I') ADVANCE(36);
      if (lookahead == 'M') ADVANCE(20);
      if (lookahead == 'P') ADVANCE(22);
      if (lookahead == 'R') ADVANCE(30);
      if (lookahead == 'S') ADVANCE(80);
      if (lookahead == 'U') ADVANCE(74);
      if (lookahead == 'V') ADVANCE(39);
      if (lookahead == '[') ADVANCE(122);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '`') ADVANCE(153);
      if (lookahead == 'f') ADVANCE(24);
      if (lookahead == 't') ADVANCE(43);
      if (lookahead == '{') ADVANCE(49);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(63);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_boolean_literal);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_boolean_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(70);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_U);
      if (lookahead == 'F') ADVANCE(91);
      if (lookahead == 'U') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_U);
      if (lookahead == 'F') ADVANCE(92);
      if (lookahead == 'U') ADVANCE(76);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_UU);
      if (lookahead == 'U') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_UU);
      if (lookahead == 'U') ADVANCE(77);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_UUU);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_UUU);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_S);
      if (lookahead == 'S') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_S);
      if (lookahead == 'S') ADVANCE(82);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_SS);
      if (lookahead == 'F') ADVANCE(94);
      if (lookahead == 'S') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_SS);
      if (lookahead == 'F') ADVANCE(93);
      if (lookahead == 'S') ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_SSS);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_SSS);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_F);
      if (lookahead == 'F') ADVANCE(87);
      if (lookahead == 'n') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_F);
      if (lookahead == 'F') ADVANCE(88);
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_FF);
      if (lookahead == 'F') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_FF);
      if (lookahead == 'F') ADVANCE(89);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_FFF);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_FFF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_UF);
      if (lookahead == 'F') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_UF);
      if (lookahead == 'F') ADVANCE(18);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_SSF);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_SSF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_UFFF);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_UFFF);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_Int);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_Int);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_Real);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_Real);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_bool_type);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_bool_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_void_type);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_void_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_CC);
      if (lookahead == 'C') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_CC);
      if (lookahead == 'C') ADVANCE(107);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_CCC);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_CCC);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_MM);
      if (lookahead == 'M') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_MM);
      if (lookahead == 'M') ADVANCE(111);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_MMM);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_MMM);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_PP);
      if (lookahead == 'P') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_PP);
      if (lookahead == 'P') ADVANCE(115);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_PPP);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_PPP);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_AA);
      if (lookahead == 'A') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_AA);
      if (lookahead == 'A') ADVANCE(119);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_AAA);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_AAA);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_function_pointer_type);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_LBRACE_RBRACE);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '\r') ADVANCE(140);
      if (lookahead == '/') ADVANCE(141);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(143);
      if (lookahead == '/') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == '/') ADVANCE(145);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(9);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(9);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(163);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(145);
      if (lookahead != 0) ADVANCE(144);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '\r') ADVANCE(147);
      if (lookahead == '/') ADVANCE(148);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(152);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(150);
      if (lookahead == '/') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(152);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(149);
      if (lookahead == '/') ADVANCE(152);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(9);
      if (lookahead != 0) ADVANCE(150);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(149);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(9);
      if (lookahead != 0) ADVANCE(150);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(163);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(152);
      if (lookahead != 0) ADVANCE(151);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(152);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '\r') ADVANCE(154);
      if (lookahead == '/') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(159);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(157);
      if (lookahead == '/') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(159);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == '/') ADVANCE(159);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(9);
      if (lookahead != 0) ADVANCE(157);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(9);
      if (lookahead != 0) ADVANCE(157);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(163);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(159);
      if (lookahead != 0) ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_line_continuation);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(163);
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
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 63},
  [2] = {.lex_state = 63},
  [3] = {.lex_state = 63},
  [4] = {.lex_state = 63},
  [5] = {.lex_state = 63},
  [6] = {.lex_state = 63},
  [7] = {.lex_state = 63},
  [8] = {.lex_state = 63},
  [9] = {.lex_state = 63},
  [10] = {.lex_state = 63},
  [11] = {.lex_state = 63},
  [12] = {.lex_state = 63},
  [13] = {.lex_state = 63},
  [14] = {.lex_state = 63},
  [15] = {.lex_state = 63},
  [16] = {.lex_state = 63},
  [17] = {.lex_state = 63},
  [18] = {.lex_state = 63},
  [19] = {.lex_state = 63},
  [20] = {.lex_state = 63},
  [21] = {.lex_state = 63},
  [22] = {.lex_state = 63},
  [23] = {.lex_state = 63},
  [24] = {.lex_state = 63},
  [25] = {.lex_state = 63},
  [26] = {.lex_state = 63},
  [27] = {.lex_state = 63},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 5},
  [30] = {.lex_state = 6},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 6},
  [34] = {.lex_state = 5},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 6},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
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
  },
  [1] = {
    [sym_program] = STATE(39),
    [sym_statement] = STATE(3),
    [sym_literal] = STATE(16),
    [sym_string_literal] = STATE(17),
    [sym_type] = STATE(16),
    [sym_scalar_type] = STATE(4),
    [sym_integer_type] = STATE(9),
    [sym_unit_fractional_type] = STATE(9),
    [sym_fixed_point_type] = STATE(9),
    [sym_numeric_constant_type] = STATE(9),
    [sym_quantity_type] = STATE(4),
    [sym_pointer_type] = STATE(12),
    [sym_address_type] = STATE(12),
    [sym_array_type] = STATE(18),
    [sym_typed_element_array_type] = STATE(19),
    [sym_vector_type] = STATE(19),
    [sym_pointer_addressable_array_type] = STATE(19),
    [sym_single_quoted_string] = STATE(13),
    [sym_double_quoted_string] = STATE(13),
    [sym_backtick_quoted_string] = STATE(13),
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
  },
  [2] = {
    [sym_statement] = STATE(2),
    [sym_literal] = STATE(16),
    [sym_string_literal] = STATE(17),
    [sym_type] = STATE(16),
    [sym_scalar_type] = STATE(4),
    [sym_integer_type] = STATE(9),
    [sym_unit_fractional_type] = STATE(9),
    [sym_fixed_point_type] = STATE(9),
    [sym_numeric_constant_type] = STATE(9),
    [sym_quantity_type] = STATE(4),
    [sym_pointer_type] = STATE(12),
    [sym_address_type] = STATE(12),
    [sym_array_type] = STATE(18),
    [sym_typed_element_array_type] = STATE(19),
    [sym_vector_type] = STATE(19),
    [sym_pointer_addressable_array_type] = STATE(19),
    [sym_single_quoted_string] = STATE(13),
    [sym_double_quoted_string] = STATE(13),
    [sym_backtick_quoted_string] = STATE(13),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym_boolean_literal] = ACTIONS(45),
    [sym_numeric_literal] = ACTIONS(45),
    [anon_sym_U] = ACTIONS(48),
    [anon_sym_UU] = ACTIONS(48),
    [anon_sym_UUU] = ACTIONS(51),
    [anon_sym_S] = ACTIONS(48),
    [anon_sym_SS] = ACTIONS(48),
    [anon_sym_SSS] = ACTIONS(51),
    [anon_sym_F] = ACTIONS(54),
    [anon_sym_FF] = ACTIONS(54),
    [anon_sym_FFF] = ACTIONS(57),
    [anon_sym_UF] = ACTIONS(60),
    [anon_sym_SSF] = ACTIONS(63),
    [anon_sym_UFFF] = ACTIONS(63),
    [anon_sym_Int] = ACTIONS(66),
    [anon_sym_Real] = ACTIONS(66),
    [sym_bool_type] = ACTIONS(69),
    [sym_void_type] = ACTIONS(69),
    [anon_sym_CC] = ACTIONS(72),
    [anon_sym_CCC] = ACTIONS(75),
    [anon_sym_MM] = ACTIONS(72),
    [anon_sym_MMM] = ACTIONS(75),
    [anon_sym_PP] = ACTIONS(72),
    [anon_sym_PPP] = ACTIONS(75),
    [anon_sym_AA] = ACTIONS(78),
    [anon_sym_AAA] = ACTIONS(81),
    [sym_function_pointer_type] = ACTIONS(84),
    [anon_sym_LBRACK] = ACTIONS(87),
    [anon_sym_SQUOTE] = ACTIONS(90),
    [anon_sym_DQUOTE] = ACTIONS(93),
    [anon_sym_BQUOTE] = ACTIONS(96),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [3] = {
    [sym_statement] = STATE(2),
    [sym_literal] = STATE(16),
    [sym_string_literal] = STATE(17),
    [sym_type] = STATE(16),
    [sym_scalar_type] = STATE(4),
    [sym_integer_type] = STATE(9),
    [sym_unit_fractional_type] = STATE(9),
    [sym_fixed_point_type] = STATE(9),
    [sym_numeric_constant_type] = STATE(9),
    [sym_quantity_type] = STATE(4),
    [sym_pointer_type] = STATE(12),
    [sym_address_type] = STATE(12),
    [sym_array_type] = STATE(18),
    [sym_typed_element_array_type] = STATE(19),
    [sym_vector_type] = STATE(19),
    [sym_pointer_addressable_array_type] = STATE(19),
    [sym_single_quoted_string] = STATE(13),
    [sym_double_quoted_string] = STATE(13),
    [sym_backtick_quoted_string] = STATE(13),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(99),
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
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(101),
    [sym_boolean_literal] = ACTIONS(101),
    [sym_numeric_literal] = ACTIONS(101),
    [anon_sym_U] = ACTIONS(103),
    [anon_sym_UU] = ACTIONS(103),
    [anon_sym_UUU] = ACTIONS(101),
    [anon_sym_S] = ACTIONS(103),
    [anon_sym_SS] = ACTIONS(103),
    [anon_sym_SSS] = ACTIONS(101),
    [anon_sym_F] = ACTIONS(103),
    [anon_sym_FF] = ACTIONS(103),
    [anon_sym_FFF] = ACTIONS(101),
    [anon_sym_UF] = ACTIONS(103),
    [anon_sym_SSF] = ACTIONS(101),
    [anon_sym_UFFF] = ACTIONS(101),
    [anon_sym_Int] = ACTIONS(101),
    [anon_sym_Real] = ACTIONS(101),
    [sym_bool_type] = ACTIONS(101),
    [sym_void_type] = ACTIONS(101),
    [anon_sym_CC] = ACTIONS(103),
    [anon_sym_CCC] = ACTIONS(101),
    [anon_sym_MM] = ACTIONS(103),
    [anon_sym_MMM] = ACTIONS(101),
    [anon_sym_PP] = ACTIONS(103),
    [anon_sym_PPP] = ACTIONS(101),
    [anon_sym_AA] = ACTIONS(103),
    [anon_sym_AAA] = ACTIONS(101),
    [sym_function_pointer_type] = ACTIONS(101),
    [anon_sym_LBRACK] = ACTIONS(105),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(107),
    [anon_sym_SQUOTE] = ACTIONS(101),
    [anon_sym_DQUOTE] = ACTIONS(101),
    [anon_sym_BQUOTE] = ACTIONS(101),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(109),
    [sym_boolean_literal] = ACTIONS(109),
    [sym_numeric_literal] = ACTIONS(109),
    [anon_sym_U] = ACTIONS(111),
    [anon_sym_UU] = ACTIONS(111),
    [anon_sym_UUU] = ACTIONS(109),
    [anon_sym_S] = ACTIONS(111),
    [anon_sym_SS] = ACTIONS(111),
    [anon_sym_SSS] = ACTIONS(109),
    [anon_sym_F] = ACTIONS(111),
    [anon_sym_FF] = ACTIONS(111),
    [anon_sym_FFF] = ACTIONS(109),
    [anon_sym_UF] = ACTIONS(111),
    [anon_sym_SSF] = ACTIONS(109),
    [anon_sym_UFFF] = ACTIONS(109),
    [anon_sym_Int] = ACTIONS(109),
    [anon_sym_Real] = ACTIONS(109),
    [sym_bool_type] = ACTIONS(109),
    [sym_void_type] = ACTIONS(109),
    [anon_sym_CC] = ACTIONS(111),
    [anon_sym_CCC] = ACTIONS(109),
    [anon_sym_MM] = ACTIONS(111),
    [anon_sym_MMM] = ACTIONS(109),
    [anon_sym_PP] = ACTIONS(111),
    [anon_sym_PPP] = ACTIONS(109),
    [anon_sym_AA] = ACTIONS(111),
    [anon_sym_AAA] = ACTIONS(109),
    [sym_function_pointer_type] = ACTIONS(109),
    [anon_sym_LBRACK] = ACTIONS(109),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(109),
    [anon_sym_SQUOTE] = ACTIONS(109),
    [anon_sym_DQUOTE] = ACTIONS(109),
    [anon_sym_BQUOTE] = ACTIONS(109),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(113),
    [sym_boolean_literal] = ACTIONS(113),
    [sym_numeric_literal] = ACTIONS(113),
    [anon_sym_U] = ACTIONS(115),
    [anon_sym_UU] = ACTIONS(115),
    [anon_sym_UUU] = ACTIONS(113),
    [anon_sym_S] = ACTIONS(115),
    [anon_sym_SS] = ACTIONS(115),
    [anon_sym_SSS] = ACTIONS(113),
    [anon_sym_F] = ACTIONS(115),
    [anon_sym_FF] = ACTIONS(115),
    [anon_sym_FFF] = ACTIONS(113),
    [anon_sym_UF] = ACTIONS(115),
    [anon_sym_SSF] = ACTIONS(113),
    [anon_sym_UFFF] = ACTIONS(113),
    [anon_sym_Int] = ACTIONS(113),
    [anon_sym_Real] = ACTIONS(113),
    [sym_bool_type] = ACTIONS(113),
    [sym_void_type] = ACTIONS(113),
    [anon_sym_CC] = ACTIONS(115),
    [anon_sym_CCC] = ACTIONS(113),
    [anon_sym_MM] = ACTIONS(115),
    [anon_sym_MMM] = ACTIONS(113),
    [anon_sym_PP] = ACTIONS(115),
    [anon_sym_PPP] = ACTIONS(113),
    [anon_sym_AA] = ACTIONS(115),
    [anon_sym_AAA] = ACTIONS(113),
    [sym_function_pointer_type] = ACTIONS(113),
    [anon_sym_LBRACK] = ACTIONS(113),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(113),
    [anon_sym_SQUOTE] = ACTIONS(113),
    [anon_sym_DQUOTE] = ACTIONS(113),
    [anon_sym_BQUOTE] = ACTIONS(113),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(117),
    [sym_boolean_literal] = ACTIONS(117),
    [sym_numeric_literal] = ACTIONS(117),
    [anon_sym_U] = ACTIONS(119),
    [anon_sym_UU] = ACTIONS(119),
    [anon_sym_UUU] = ACTIONS(117),
    [anon_sym_S] = ACTIONS(119),
    [anon_sym_SS] = ACTIONS(119),
    [anon_sym_SSS] = ACTIONS(117),
    [anon_sym_F] = ACTIONS(119),
    [anon_sym_FF] = ACTIONS(119),
    [anon_sym_FFF] = ACTIONS(117),
    [anon_sym_UF] = ACTIONS(119),
    [anon_sym_SSF] = ACTIONS(117),
    [anon_sym_UFFF] = ACTIONS(117),
    [anon_sym_Int] = ACTIONS(117),
    [anon_sym_Real] = ACTIONS(117),
    [sym_bool_type] = ACTIONS(117),
    [sym_void_type] = ACTIONS(117),
    [anon_sym_CC] = ACTIONS(119),
    [anon_sym_CCC] = ACTIONS(117),
    [anon_sym_MM] = ACTIONS(119),
    [anon_sym_MMM] = ACTIONS(117),
    [anon_sym_PP] = ACTIONS(119),
    [anon_sym_PPP] = ACTIONS(117),
    [anon_sym_AA] = ACTIONS(119),
    [anon_sym_AAA] = ACTIONS(117),
    [sym_function_pointer_type] = ACTIONS(117),
    [anon_sym_LBRACK] = ACTIONS(117),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(117),
    [anon_sym_SQUOTE] = ACTIONS(117),
    [anon_sym_DQUOTE] = ACTIONS(117),
    [anon_sym_BQUOTE] = ACTIONS(117),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(121),
    [sym_boolean_literal] = ACTIONS(121),
    [sym_numeric_literal] = ACTIONS(121),
    [anon_sym_U] = ACTIONS(123),
    [anon_sym_UU] = ACTIONS(123),
    [anon_sym_UUU] = ACTIONS(121),
    [anon_sym_S] = ACTIONS(123),
    [anon_sym_SS] = ACTIONS(123),
    [anon_sym_SSS] = ACTIONS(121),
    [anon_sym_F] = ACTIONS(123),
    [anon_sym_FF] = ACTIONS(123),
    [anon_sym_FFF] = ACTIONS(121),
    [anon_sym_UF] = ACTIONS(123),
    [anon_sym_SSF] = ACTIONS(121),
    [anon_sym_UFFF] = ACTIONS(121),
    [anon_sym_Int] = ACTIONS(121),
    [anon_sym_Real] = ACTIONS(121),
    [sym_bool_type] = ACTIONS(121),
    [sym_void_type] = ACTIONS(121),
    [anon_sym_CC] = ACTIONS(123),
    [anon_sym_CCC] = ACTIONS(121),
    [anon_sym_MM] = ACTIONS(123),
    [anon_sym_MMM] = ACTIONS(121),
    [anon_sym_PP] = ACTIONS(123),
    [anon_sym_PPP] = ACTIONS(121),
    [anon_sym_AA] = ACTIONS(123),
    [anon_sym_AAA] = ACTIONS(121),
    [sym_function_pointer_type] = ACTIONS(121),
    [anon_sym_LBRACK] = ACTIONS(121),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(121),
    [anon_sym_SQUOTE] = ACTIONS(121),
    [anon_sym_DQUOTE] = ACTIONS(121),
    [anon_sym_BQUOTE] = ACTIONS(121),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(125),
    [sym_boolean_literal] = ACTIONS(125),
    [sym_numeric_literal] = ACTIONS(125),
    [anon_sym_U] = ACTIONS(127),
    [anon_sym_UU] = ACTIONS(127),
    [anon_sym_UUU] = ACTIONS(125),
    [anon_sym_S] = ACTIONS(127),
    [anon_sym_SS] = ACTIONS(127),
    [anon_sym_SSS] = ACTIONS(125),
    [anon_sym_F] = ACTIONS(127),
    [anon_sym_FF] = ACTIONS(127),
    [anon_sym_FFF] = ACTIONS(125),
    [anon_sym_UF] = ACTIONS(127),
    [anon_sym_SSF] = ACTIONS(125),
    [anon_sym_UFFF] = ACTIONS(125),
    [anon_sym_Int] = ACTIONS(125),
    [anon_sym_Real] = ACTIONS(125),
    [sym_bool_type] = ACTIONS(125),
    [sym_void_type] = ACTIONS(125),
    [anon_sym_CC] = ACTIONS(127),
    [anon_sym_CCC] = ACTIONS(125),
    [anon_sym_MM] = ACTIONS(127),
    [anon_sym_MMM] = ACTIONS(125),
    [anon_sym_PP] = ACTIONS(127),
    [anon_sym_PPP] = ACTIONS(125),
    [anon_sym_AA] = ACTIONS(127),
    [anon_sym_AAA] = ACTIONS(125),
    [sym_function_pointer_type] = ACTIONS(125),
    [anon_sym_LBRACK] = ACTIONS(125),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(125),
    [anon_sym_SQUOTE] = ACTIONS(125),
    [anon_sym_DQUOTE] = ACTIONS(125),
    [anon_sym_BQUOTE] = ACTIONS(125),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(129),
    [sym_boolean_literal] = ACTIONS(129),
    [sym_numeric_literal] = ACTIONS(129),
    [anon_sym_U] = ACTIONS(131),
    [anon_sym_UU] = ACTIONS(131),
    [anon_sym_UUU] = ACTIONS(129),
    [anon_sym_S] = ACTIONS(131),
    [anon_sym_SS] = ACTIONS(131),
    [anon_sym_SSS] = ACTIONS(129),
    [anon_sym_F] = ACTIONS(131),
    [anon_sym_FF] = ACTIONS(131),
    [anon_sym_FFF] = ACTIONS(129),
    [anon_sym_UF] = ACTIONS(131),
    [anon_sym_SSF] = ACTIONS(129),
    [anon_sym_UFFF] = ACTIONS(129),
    [anon_sym_Int] = ACTIONS(129),
    [anon_sym_Real] = ACTIONS(129),
    [sym_bool_type] = ACTIONS(129),
    [sym_void_type] = ACTIONS(129),
    [anon_sym_CC] = ACTIONS(131),
    [anon_sym_CCC] = ACTIONS(129),
    [anon_sym_MM] = ACTIONS(131),
    [anon_sym_MMM] = ACTIONS(129),
    [anon_sym_PP] = ACTIONS(131),
    [anon_sym_PPP] = ACTIONS(129),
    [anon_sym_AA] = ACTIONS(131),
    [anon_sym_AAA] = ACTIONS(129),
    [sym_function_pointer_type] = ACTIONS(129),
    [anon_sym_LBRACK] = ACTIONS(129),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(129),
    [anon_sym_SQUOTE] = ACTIONS(129),
    [anon_sym_DQUOTE] = ACTIONS(129),
    [anon_sym_BQUOTE] = ACTIONS(129),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(133),
    [sym_boolean_literal] = ACTIONS(133),
    [sym_numeric_literal] = ACTIONS(133),
    [anon_sym_U] = ACTIONS(135),
    [anon_sym_UU] = ACTIONS(135),
    [anon_sym_UUU] = ACTIONS(133),
    [anon_sym_S] = ACTIONS(135),
    [anon_sym_SS] = ACTIONS(135),
    [anon_sym_SSS] = ACTIONS(133),
    [anon_sym_F] = ACTIONS(135),
    [anon_sym_FF] = ACTIONS(135),
    [anon_sym_FFF] = ACTIONS(133),
    [anon_sym_UF] = ACTIONS(135),
    [anon_sym_SSF] = ACTIONS(133),
    [anon_sym_UFFF] = ACTIONS(133),
    [anon_sym_Int] = ACTIONS(133),
    [anon_sym_Real] = ACTIONS(133),
    [sym_bool_type] = ACTIONS(133),
    [sym_void_type] = ACTIONS(133),
    [anon_sym_CC] = ACTIONS(135),
    [anon_sym_CCC] = ACTIONS(133),
    [anon_sym_MM] = ACTIONS(135),
    [anon_sym_MMM] = ACTIONS(133),
    [anon_sym_PP] = ACTIONS(135),
    [anon_sym_PPP] = ACTIONS(133),
    [anon_sym_AA] = ACTIONS(135),
    [anon_sym_AAA] = ACTIONS(133),
    [sym_function_pointer_type] = ACTIONS(133),
    [anon_sym_LBRACK] = ACTIONS(133),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(133),
    [anon_sym_SQUOTE] = ACTIONS(133),
    [anon_sym_DQUOTE] = ACTIONS(133),
    [anon_sym_BQUOTE] = ACTIONS(133),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(137),
    [sym_boolean_literal] = ACTIONS(137),
    [sym_numeric_literal] = ACTIONS(137),
    [anon_sym_U] = ACTIONS(139),
    [anon_sym_UU] = ACTIONS(139),
    [anon_sym_UUU] = ACTIONS(137),
    [anon_sym_S] = ACTIONS(139),
    [anon_sym_SS] = ACTIONS(139),
    [anon_sym_SSS] = ACTIONS(137),
    [anon_sym_F] = ACTIONS(139),
    [anon_sym_FF] = ACTIONS(139),
    [anon_sym_FFF] = ACTIONS(137),
    [anon_sym_UF] = ACTIONS(139),
    [anon_sym_SSF] = ACTIONS(137),
    [anon_sym_UFFF] = ACTIONS(137),
    [anon_sym_Int] = ACTIONS(137),
    [anon_sym_Real] = ACTIONS(137),
    [sym_bool_type] = ACTIONS(137),
    [sym_void_type] = ACTIONS(137),
    [anon_sym_CC] = ACTIONS(139),
    [anon_sym_CCC] = ACTIONS(137),
    [anon_sym_MM] = ACTIONS(139),
    [anon_sym_MMM] = ACTIONS(137),
    [anon_sym_PP] = ACTIONS(139),
    [anon_sym_PPP] = ACTIONS(137),
    [anon_sym_AA] = ACTIONS(139),
    [anon_sym_AAA] = ACTIONS(137),
    [sym_function_pointer_type] = ACTIONS(137),
    [anon_sym_LBRACK] = ACTIONS(137),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(137),
    [anon_sym_SQUOTE] = ACTIONS(137),
    [anon_sym_DQUOTE] = ACTIONS(137),
    [anon_sym_BQUOTE] = ACTIONS(137),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(141),
    [sym_boolean_literal] = ACTIONS(141),
    [sym_numeric_literal] = ACTIONS(141),
    [anon_sym_U] = ACTIONS(143),
    [anon_sym_UU] = ACTIONS(143),
    [anon_sym_UUU] = ACTIONS(141),
    [anon_sym_S] = ACTIONS(143),
    [anon_sym_SS] = ACTIONS(143),
    [anon_sym_SSS] = ACTIONS(141),
    [anon_sym_F] = ACTIONS(143),
    [anon_sym_FF] = ACTIONS(143),
    [anon_sym_FFF] = ACTIONS(141),
    [anon_sym_UF] = ACTIONS(143),
    [anon_sym_SSF] = ACTIONS(141),
    [anon_sym_UFFF] = ACTIONS(141),
    [anon_sym_Int] = ACTIONS(141),
    [anon_sym_Real] = ACTIONS(141),
    [sym_bool_type] = ACTIONS(141),
    [sym_void_type] = ACTIONS(141),
    [anon_sym_CC] = ACTIONS(143),
    [anon_sym_CCC] = ACTIONS(141),
    [anon_sym_MM] = ACTIONS(143),
    [anon_sym_MMM] = ACTIONS(141),
    [anon_sym_PP] = ACTIONS(143),
    [anon_sym_PPP] = ACTIONS(141),
    [anon_sym_AA] = ACTIONS(143),
    [anon_sym_AAA] = ACTIONS(141),
    [sym_function_pointer_type] = ACTIONS(141),
    [anon_sym_LBRACK] = ACTIONS(141),
    [anon_sym_SQUOTE] = ACTIONS(141),
    [anon_sym_DQUOTE] = ACTIONS(141),
    [anon_sym_BQUOTE] = ACTIONS(141),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(145),
    [sym_boolean_literal] = ACTIONS(145),
    [sym_numeric_literal] = ACTIONS(145),
    [anon_sym_U] = ACTIONS(147),
    [anon_sym_UU] = ACTIONS(147),
    [anon_sym_UUU] = ACTIONS(145),
    [anon_sym_S] = ACTIONS(147),
    [anon_sym_SS] = ACTIONS(147),
    [anon_sym_SSS] = ACTIONS(145),
    [anon_sym_F] = ACTIONS(147),
    [anon_sym_FF] = ACTIONS(147),
    [anon_sym_FFF] = ACTIONS(145),
    [anon_sym_UF] = ACTIONS(147),
    [anon_sym_SSF] = ACTIONS(145),
    [anon_sym_UFFF] = ACTIONS(145),
    [anon_sym_Int] = ACTIONS(145),
    [anon_sym_Real] = ACTIONS(145),
    [sym_bool_type] = ACTIONS(145),
    [sym_void_type] = ACTIONS(145),
    [anon_sym_CC] = ACTIONS(147),
    [anon_sym_CCC] = ACTIONS(145),
    [anon_sym_MM] = ACTIONS(147),
    [anon_sym_MMM] = ACTIONS(145),
    [anon_sym_PP] = ACTIONS(147),
    [anon_sym_PPP] = ACTIONS(145),
    [anon_sym_AA] = ACTIONS(147),
    [anon_sym_AAA] = ACTIONS(145),
    [sym_function_pointer_type] = ACTIONS(145),
    [anon_sym_LBRACK] = ACTIONS(145),
    [anon_sym_SQUOTE] = ACTIONS(145),
    [anon_sym_DQUOTE] = ACTIONS(145),
    [anon_sym_BQUOTE] = ACTIONS(145),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [15] = {
    [ts_builtin_sym_end] = ACTIONS(149),
    [sym_boolean_literal] = ACTIONS(149),
    [sym_numeric_literal] = ACTIONS(149),
    [anon_sym_U] = ACTIONS(151),
    [anon_sym_UU] = ACTIONS(151),
    [anon_sym_UUU] = ACTIONS(149),
    [anon_sym_S] = ACTIONS(151),
    [anon_sym_SS] = ACTIONS(151),
    [anon_sym_SSS] = ACTIONS(149),
    [anon_sym_F] = ACTIONS(151),
    [anon_sym_FF] = ACTIONS(151),
    [anon_sym_FFF] = ACTIONS(149),
    [anon_sym_UF] = ACTIONS(151),
    [anon_sym_SSF] = ACTIONS(149),
    [anon_sym_UFFF] = ACTIONS(149),
    [anon_sym_Int] = ACTIONS(149),
    [anon_sym_Real] = ACTIONS(149),
    [sym_bool_type] = ACTIONS(149),
    [sym_void_type] = ACTIONS(149),
    [anon_sym_CC] = ACTIONS(151),
    [anon_sym_CCC] = ACTIONS(149),
    [anon_sym_MM] = ACTIONS(151),
    [anon_sym_MMM] = ACTIONS(149),
    [anon_sym_PP] = ACTIONS(151),
    [anon_sym_PPP] = ACTIONS(149),
    [anon_sym_AA] = ACTIONS(151),
    [anon_sym_AAA] = ACTIONS(149),
    [sym_function_pointer_type] = ACTIONS(149),
    [anon_sym_LBRACK] = ACTIONS(149),
    [anon_sym_SQUOTE] = ACTIONS(149),
    [anon_sym_DQUOTE] = ACTIONS(149),
    [anon_sym_BQUOTE] = ACTIONS(149),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(153),
    [sym_boolean_literal] = ACTIONS(153),
    [sym_numeric_literal] = ACTIONS(153),
    [anon_sym_U] = ACTIONS(155),
    [anon_sym_UU] = ACTIONS(155),
    [anon_sym_UUU] = ACTIONS(153),
    [anon_sym_S] = ACTIONS(155),
    [anon_sym_SS] = ACTIONS(155),
    [anon_sym_SSS] = ACTIONS(153),
    [anon_sym_F] = ACTIONS(155),
    [anon_sym_FF] = ACTIONS(155),
    [anon_sym_FFF] = ACTIONS(153),
    [anon_sym_UF] = ACTIONS(155),
    [anon_sym_SSF] = ACTIONS(153),
    [anon_sym_UFFF] = ACTIONS(153),
    [anon_sym_Int] = ACTIONS(153),
    [anon_sym_Real] = ACTIONS(153),
    [sym_bool_type] = ACTIONS(153),
    [sym_void_type] = ACTIONS(153),
    [anon_sym_CC] = ACTIONS(155),
    [anon_sym_CCC] = ACTIONS(153),
    [anon_sym_MM] = ACTIONS(155),
    [anon_sym_MMM] = ACTIONS(153),
    [anon_sym_PP] = ACTIONS(155),
    [anon_sym_PPP] = ACTIONS(153),
    [anon_sym_AA] = ACTIONS(155),
    [anon_sym_AAA] = ACTIONS(153),
    [sym_function_pointer_type] = ACTIONS(153),
    [anon_sym_LBRACK] = ACTIONS(153),
    [anon_sym_SQUOTE] = ACTIONS(153),
    [anon_sym_DQUOTE] = ACTIONS(153),
    [anon_sym_BQUOTE] = ACTIONS(153),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [17] = {
    [ts_builtin_sym_end] = ACTIONS(157),
    [sym_boolean_literal] = ACTIONS(157),
    [sym_numeric_literal] = ACTIONS(157),
    [anon_sym_U] = ACTIONS(159),
    [anon_sym_UU] = ACTIONS(159),
    [anon_sym_UUU] = ACTIONS(157),
    [anon_sym_S] = ACTIONS(159),
    [anon_sym_SS] = ACTIONS(159),
    [anon_sym_SSS] = ACTIONS(157),
    [anon_sym_F] = ACTIONS(159),
    [anon_sym_FF] = ACTIONS(159),
    [anon_sym_FFF] = ACTIONS(157),
    [anon_sym_UF] = ACTIONS(159),
    [anon_sym_SSF] = ACTIONS(157),
    [anon_sym_UFFF] = ACTIONS(157),
    [anon_sym_Int] = ACTIONS(157),
    [anon_sym_Real] = ACTIONS(157),
    [sym_bool_type] = ACTIONS(157),
    [sym_void_type] = ACTIONS(157),
    [anon_sym_CC] = ACTIONS(159),
    [anon_sym_CCC] = ACTIONS(157),
    [anon_sym_MM] = ACTIONS(159),
    [anon_sym_MMM] = ACTIONS(157),
    [anon_sym_PP] = ACTIONS(159),
    [anon_sym_PPP] = ACTIONS(157),
    [anon_sym_AA] = ACTIONS(159),
    [anon_sym_AAA] = ACTIONS(157),
    [sym_function_pointer_type] = ACTIONS(157),
    [anon_sym_LBRACK] = ACTIONS(157),
    [anon_sym_SQUOTE] = ACTIONS(157),
    [anon_sym_DQUOTE] = ACTIONS(157),
    [anon_sym_BQUOTE] = ACTIONS(157),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(101),
    [sym_boolean_literal] = ACTIONS(101),
    [sym_numeric_literal] = ACTIONS(101),
    [anon_sym_U] = ACTIONS(103),
    [anon_sym_UU] = ACTIONS(103),
    [anon_sym_UUU] = ACTIONS(101),
    [anon_sym_S] = ACTIONS(103),
    [anon_sym_SS] = ACTIONS(103),
    [anon_sym_SSS] = ACTIONS(101),
    [anon_sym_F] = ACTIONS(103),
    [anon_sym_FF] = ACTIONS(103),
    [anon_sym_FFF] = ACTIONS(101),
    [anon_sym_UF] = ACTIONS(103),
    [anon_sym_SSF] = ACTIONS(101),
    [anon_sym_UFFF] = ACTIONS(101),
    [anon_sym_Int] = ACTIONS(101),
    [anon_sym_Real] = ACTIONS(101),
    [sym_bool_type] = ACTIONS(101),
    [sym_void_type] = ACTIONS(101),
    [anon_sym_CC] = ACTIONS(103),
    [anon_sym_CCC] = ACTIONS(101),
    [anon_sym_MM] = ACTIONS(103),
    [anon_sym_MMM] = ACTIONS(101),
    [anon_sym_PP] = ACTIONS(103),
    [anon_sym_PPP] = ACTIONS(101),
    [anon_sym_AA] = ACTIONS(103),
    [anon_sym_AAA] = ACTIONS(101),
    [sym_function_pointer_type] = ACTIONS(101),
    [anon_sym_LBRACK] = ACTIONS(101),
    [anon_sym_SQUOTE] = ACTIONS(101),
    [anon_sym_DQUOTE] = ACTIONS(101),
    [anon_sym_BQUOTE] = ACTIONS(101),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(161),
    [sym_boolean_literal] = ACTIONS(161),
    [sym_numeric_literal] = ACTIONS(161),
    [anon_sym_U] = ACTIONS(163),
    [anon_sym_UU] = ACTIONS(163),
    [anon_sym_UUU] = ACTIONS(161),
    [anon_sym_S] = ACTIONS(163),
    [anon_sym_SS] = ACTIONS(163),
    [anon_sym_SSS] = ACTIONS(161),
    [anon_sym_F] = ACTIONS(163),
    [anon_sym_FF] = ACTIONS(163),
    [anon_sym_FFF] = ACTIONS(161),
    [anon_sym_UF] = ACTIONS(163),
    [anon_sym_SSF] = ACTIONS(161),
    [anon_sym_UFFF] = ACTIONS(161),
    [anon_sym_Int] = ACTIONS(161),
    [anon_sym_Real] = ACTIONS(161),
    [sym_bool_type] = ACTIONS(161),
    [sym_void_type] = ACTIONS(161),
    [anon_sym_CC] = ACTIONS(163),
    [anon_sym_CCC] = ACTIONS(161),
    [anon_sym_MM] = ACTIONS(163),
    [anon_sym_MMM] = ACTIONS(161),
    [anon_sym_PP] = ACTIONS(163),
    [anon_sym_PPP] = ACTIONS(161),
    [anon_sym_AA] = ACTIONS(163),
    [anon_sym_AAA] = ACTIONS(161),
    [sym_function_pointer_type] = ACTIONS(161),
    [anon_sym_LBRACK] = ACTIONS(161),
    [anon_sym_SQUOTE] = ACTIONS(161),
    [anon_sym_DQUOTE] = ACTIONS(161),
    [anon_sym_BQUOTE] = ACTIONS(161),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(165),
    [sym_boolean_literal] = ACTIONS(165),
    [sym_numeric_literal] = ACTIONS(165),
    [anon_sym_U] = ACTIONS(167),
    [anon_sym_UU] = ACTIONS(167),
    [anon_sym_UUU] = ACTIONS(165),
    [anon_sym_S] = ACTIONS(167),
    [anon_sym_SS] = ACTIONS(167),
    [anon_sym_SSS] = ACTIONS(165),
    [anon_sym_F] = ACTIONS(167),
    [anon_sym_FF] = ACTIONS(167),
    [anon_sym_FFF] = ACTIONS(165),
    [anon_sym_UF] = ACTIONS(167),
    [anon_sym_SSF] = ACTIONS(165),
    [anon_sym_UFFF] = ACTIONS(165),
    [anon_sym_Int] = ACTIONS(165),
    [anon_sym_Real] = ACTIONS(165),
    [sym_bool_type] = ACTIONS(165),
    [sym_void_type] = ACTIONS(165),
    [anon_sym_CC] = ACTIONS(167),
    [anon_sym_CCC] = ACTIONS(165),
    [anon_sym_MM] = ACTIONS(167),
    [anon_sym_MMM] = ACTIONS(165),
    [anon_sym_PP] = ACTIONS(167),
    [anon_sym_PPP] = ACTIONS(165),
    [anon_sym_AA] = ACTIONS(167),
    [anon_sym_AAA] = ACTIONS(165),
    [sym_function_pointer_type] = ACTIONS(165),
    [anon_sym_LBRACK] = ACTIONS(165),
    [anon_sym_SQUOTE] = ACTIONS(165),
    [anon_sym_DQUOTE] = ACTIONS(165),
    [anon_sym_BQUOTE] = ACTIONS(165),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [21] = {
    [ts_builtin_sym_end] = ACTIONS(169),
    [sym_boolean_literal] = ACTIONS(169),
    [sym_numeric_literal] = ACTIONS(169),
    [anon_sym_U] = ACTIONS(171),
    [anon_sym_UU] = ACTIONS(171),
    [anon_sym_UUU] = ACTIONS(169),
    [anon_sym_S] = ACTIONS(171),
    [anon_sym_SS] = ACTIONS(171),
    [anon_sym_SSS] = ACTIONS(169),
    [anon_sym_F] = ACTIONS(171),
    [anon_sym_FF] = ACTIONS(171),
    [anon_sym_FFF] = ACTIONS(169),
    [anon_sym_UF] = ACTIONS(171),
    [anon_sym_SSF] = ACTIONS(169),
    [anon_sym_UFFF] = ACTIONS(169),
    [anon_sym_Int] = ACTIONS(169),
    [anon_sym_Real] = ACTIONS(169),
    [sym_bool_type] = ACTIONS(169),
    [sym_void_type] = ACTIONS(169),
    [anon_sym_CC] = ACTIONS(171),
    [anon_sym_CCC] = ACTIONS(169),
    [anon_sym_MM] = ACTIONS(171),
    [anon_sym_MMM] = ACTIONS(169),
    [anon_sym_PP] = ACTIONS(171),
    [anon_sym_PPP] = ACTIONS(169),
    [anon_sym_AA] = ACTIONS(171),
    [anon_sym_AAA] = ACTIONS(169),
    [sym_function_pointer_type] = ACTIONS(169),
    [anon_sym_LBRACK] = ACTIONS(169),
    [anon_sym_SQUOTE] = ACTIONS(169),
    [anon_sym_DQUOTE] = ACTIONS(169),
    [anon_sym_BQUOTE] = ACTIONS(169),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [22] = {
    [ts_builtin_sym_end] = ACTIONS(173),
    [sym_boolean_literal] = ACTIONS(173),
    [sym_numeric_literal] = ACTIONS(173),
    [anon_sym_U] = ACTIONS(175),
    [anon_sym_UU] = ACTIONS(175),
    [anon_sym_UUU] = ACTIONS(173),
    [anon_sym_S] = ACTIONS(175),
    [anon_sym_SS] = ACTIONS(175),
    [anon_sym_SSS] = ACTIONS(173),
    [anon_sym_F] = ACTIONS(175),
    [anon_sym_FF] = ACTIONS(175),
    [anon_sym_FFF] = ACTIONS(173),
    [anon_sym_UF] = ACTIONS(175),
    [anon_sym_SSF] = ACTIONS(173),
    [anon_sym_UFFF] = ACTIONS(173),
    [anon_sym_Int] = ACTIONS(173),
    [anon_sym_Real] = ACTIONS(173),
    [sym_bool_type] = ACTIONS(173),
    [sym_void_type] = ACTIONS(173),
    [anon_sym_CC] = ACTIONS(175),
    [anon_sym_CCC] = ACTIONS(173),
    [anon_sym_MM] = ACTIONS(175),
    [anon_sym_MMM] = ACTIONS(173),
    [anon_sym_PP] = ACTIONS(175),
    [anon_sym_PPP] = ACTIONS(173),
    [anon_sym_AA] = ACTIONS(175),
    [anon_sym_AAA] = ACTIONS(173),
    [sym_function_pointer_type] = ACTIONS(173),
    [anon_sym_LBRACK] = ACTIONS(173),
    [anon_sym_SQUOTE] = ACTIONS(173),
    [anon_sym_DQUOTE] = ACTIONS(173),
    [anon_sym_BQUOTE] = ACTIONS(173),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [23] = {
    [ts_builtin_sym_end] = ACTIONS(177),
    [sym_boolean_literal] = ACTIONS(177),
    [sym_numeric_literal] = ACTIONS(177),
    [anon_sym_U] = ACTIONS(179),
    [anon_sym_UU] = ACTIONS(179),
    [anon_sym_UUU] = ACTIONS(177),
    [anon_sym_S] = ACTIONS(179),
    [anon_sym_SS] = ACTIONS(179),
    [anon_sym_SSS] = ACTIONS(177),
    [anon_sym_F] = ACTIONS(179),
    [anon_sym_FF] = ACTIONS(179),
    [anon_sym_FFF] = ACTIONS(177),
    [anon_sym_UF] = ACTIONS(179),
    [anon_sym_SSF] = ACTIONS(177),
    [anon_sym_UFFF] = ACTIONS(177),
    [anon_sym_Int] = ACTIONS(177),
    [anon_sym_Real] = ACTIONS(177),
    [sym_bool_type] = ACTIONS(177),
    [sym_void_type] = ACTIONS(177),
    [anon_sym_CC] = ACTIONS(179),
    [anon_sym_CCC] = ACTIONS(177),
    [anon_sym_MM] = ACTIONS(179),
    [anon_sym_MMM] = ACTIONS(177),
    [anon_sym_PP] = ACTIONS(179),
    [anon_sym_PPP] = ACTIONS(177),
    [anon_sym_AA] = ACTIONS(179),
    [anon_sym_AAA] = ACTIONS(177),
    [sym_function_pointer_type] = ACTIONS(177),
    [anon_sym_LBRACK] = ACTIONS(177),
    [anon_sym_SQUOTE] = ACTIONS(177),
    [anon_sym_DQUOTE] = ACTIONS(177),
    [anon_sym_BQUOTE] = ACTIONS(177),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [24] = {
    [ts_builtin_sym_end] = ACTIONS(181),
    [sym_boolean_literal] = ACTIONS(181),
    [sym_numeric_literal] = ACTIONS(181),
    [anon_sym_U] = ACTIONS(183),
    [anon_sym_UU] = ACTIONS(183),
    [anon_sym_UUU] = ACTIONS(181),
    [anon_sym_S] = ACTIONS(183),
    [anon_sym_SS] = ACTIONS(183),
    [anon_sym_SSS] = ACTIONS(181),
    [anon_sym_F] = ACTIONS(183),
    [anon_sym_FF] = ACTIONS(183),
    [anon_sym_FFF] = ACTIONS(181),
    [anon_sym_UF] = ACTIONS(183),
    [anon_sym_SSF] = ACTIONS(181),
    [anon_sym_UFFF] = ACTIONS(181),
    [anon_sym_Int] = ACTIONS(181),
    [anon_sym_Real] = ACTIONS(181),
    [sym_bool_type] = ACTIONS(181),
    [sym_void_type] = ACTIONS(181),
    [anon_sym_CC] = ACTIONS(183),
    [anon_sym_CCC] = ACTIONS(181),
    [anon_sym_MM] = ACTIONS(183),
    [anon_sym_MMM] = ACTIONS(181),
    [anon_sym_PP] = ACTIONS(183),
    [anon_sym_PPP] = ACTIONS(181),
    [anon_sym_AA] = ACTIONS(183),
    [anon_sym_AAA] = ACTIONS(181),
    [sym_function_pointer_type] = ACTIONS(181),
    [anon_sym_LBRACK] = ACTIONS(181),
    [anon_sym_SQUOTE] = ACTIONS(181),
    [anon_sym_DQUOTE] = ACTIONS(181),
    [anon_sym_BQUOTE] = ACTIONS(181),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [25] = {
    [ts_builtin_sym_end] = ACTIONS(185),
    [sym_boolean_literal] = ACTIONS(185),
    [sym_numeric_literal] = ACTIONS(185),
    [anon_sym_U] = ACTIONS(187),
    [anon_sym_UU] = ACTIONS(187),
    [anon_sym_UUU] = ACTIONS(185),
    [anon_sym_S] = ACTIONS(187),
    [anon_sym_SS] = ACTIONS(187),
    [anon_sym_SSS] = ACTIONS(185),
    [anon_sym_F] = ACTIONS(187),
    [anon_sym_FF] = ACTIONS(187),
    [anon_sym_FFF] = ACTIONS(185),
    [anon_sym_UF] = ACTIONS(187),
    [anon_sym_SSF] = ACTIONS(185),
    [anon_sym_UFFF] = ACTIONS(185),
    [anon_sym_Int] = ACTIONS(185),
    [anon_sym_Real] = ACTIONS(185),
    [sym_bool_type] = ACTIONS(185),
    [sym_void_type] = ACTIONS(185),
    [anon_sym_CC] = ACTIONS(187),
    [anon_sym_CCC] = ACTIONS(185),
    [anon_sym_MM] = ACTIONS(187),
    [anon_sym_MMM] = ACTIONS(185),
    [anon_sym_PP] = ACTIONS(187),
    [anon_sym_PPP] = ACTIONS(185),
    [anon_sym_AA] = ACTIONS(187),
    [anon_sym_AAA] = ACTIONS(185),
    [sym_function_pointer_type] = ACTIONS(185),
    [anon_sym_LBRACK] = ACTIONS(185),
    [anon_sym_SQUOTE] = ACTIONS(185),
    [anon_sym_DQUOTE] = ACTIONS(185),
    [anon_sym_BQUOTE] = ACTIONS(185),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [26] = {
    [ts_builtin_sym_end] = ACTIONS(189),
    [sym_boolean_literal] = ACTIONS(189),
    [sym_numeric_literal] = ACTIONS(189),
    [anon_sym_U] = ACTIONS(191),
    [anon_sym_UU] = ACTIONS(191),
    [anon_sym_UUU] = ACTIONS(189),
    [anon_sym_S] = ACTIONS(191),
    [anon_sym_SS] = ACTIONS(191),
    [anon_sym_SSS] = ACTIONS(189),
    [anon_sym_F] = ACTIONS(191),
    [anon_sym_FF] = ACTIONS(191),
    [anon_sym_FFF] = ACTIONS(189),
    [anon_sym_UF] = ACTIONS(191),
    [anon_sym_SSF] = ACTIONS(189),
    [anon_sym_UFFF] = ACTIONS(189),
    [anon_sym_Int] = ACTIONS(189),
    [anon_sym_Real] = ACTIONS(189),
    [sym_bool_type] = ACTIONS(189),
    [sym_void_type] = ACTIONS(189),
    [anon_sym_CC] = ACTIONS(191),
    [anon_sym_CCC] = ACTIONS(189),
    [anon_sym_MM] = ACTIONS(191),
    [anon_sym_MMM] = ACTIONS(189),
    [anon_sym_PP] = ACTIONS(191),
    [anon_sym_PPP] = ACTIONS(189),
    [anon_sym_AA] = ACTIONS(191),
    [anon_sym_AAA] = ACTIONS(189),
    [sym_function_pointer_type] = ACTIONS(189),
    [anon_sym_LBRACK] = ACTIONS(189),
    [anon_sym_SQUOTE] = ACTIONS(189),
    [anon_sym_DQUOTE] = ACTIONS(189),
    [anon_sym_BQUOTE] = ACTIONS(189),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
  [27] = {
    [ts_builtin_sym_end] = ACTIONS(193),
    [sym_boolean_literal] = ACTIONS(193),
    [sym_numeric_literal] = ACTIONS(193),
    [anon_sym_U] = ACTIONS(195),
    [anon_sym_UU] = ACTIONS(195),
    [anon_sym_UUU] = ACTIONS(193),
    [anon_sym_S] = ACTIONS(195),
    [anon_sym_SS] = ACTIONS(195),
    [anon_sym_SSS] = ACTIONS(193),
    [anon_sym_F] = ACTIONS(195),
    [anon_sym_FF] = ACTIONS(195),
    [anon_sym_FFF] = ACTIONS(193),
    [anon_sym_UF] = ACTIONS(195),
    [anon_sym_SSF] = ACTIONS(193),
    [anon_sym_UFFF] = ACTIONS(193),
    [anon_sym_Int] = ACTIONS(193),
    [anon_sym_Real] = ACTIONS(193),
    [sym_bool_type] = ACTIONS(193),
    [sym_void_type] = ACTIONS(193),
    [anon_sym_CC] = ACTIONS(195),
    [anon_sym_CCC] = ACTIONS(193),
    [anon_sym_MM] = ACTIONS(195),
    [anon_sym_MMM] = ACTIONS(193),
    [anon_sym_PP] = ACTIONS(195),
    [anon_sym_PPP] = ACTIONS(193),
    [anon_sym_AA] = ACTIONS(195),
    [anon_sym_AAA] = ACTIONS(193),
    [sym_function_pointer_type] = ACTIONS(193),
    [anon_sym_LBRACK] = ACTIONS(193),
    [anon_sym_SQUOTE] = ACTIONS(193),
    [anon_sym_DQUOTE] = ACTIONS(193),
    [anon_sym_BQUOTE] = ACTIONS(193),
    [sym_line_continuation] = ACTIONS(3),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(197), 1,
      anon_sym_SQUOTE,
    ACTIONS(199), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(201), 1,
      sym_escape_sequence,
    STATE(32), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [17] = 5,
    ACTIONS(205), 1,
      anon_sym_BQUOTE,
    ACTIONS(207), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(209), 1,
      sym_escape_sequence,
    STATE(34), 1,
      aux_sym_backtick_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [34] = 5,
    ACTIONS(211), 1,
      anon_sym_DQUOTE,
    ACTIONS(213), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(215), 1,
      sym_escape_sequence,
    STATE(33), 1,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [51] = 5,
    ACTIONS(217), 1,
      anon_sym_SQUOTE,
    ACTIONS(219), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(222), 1,
      sym_escape_sequence,
    STATE(31), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [68] = 5,
    ACTIONS(225), 1,
      anon_sym_SQUOTE,
    ACTIONS(227), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(229), 1,
      sym_escape_sequence,
    STATE(31), 1,
      aux_sym_single_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [85] = 5,
    ACTIONS(231), 1,
      anon_sym_DQUOTE,
    ACTIONS(233), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(236), 1,
      sym_escape_sequence,
    STATE(33), 1,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [102] = 5,
    ACTIONS(239), 1,
      anon_sym_BQUOTE,
    ACTIONS(241), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(244), 1,
      sym_escape_sequence,
    STATE(34), 1,
      aux_sym_backtick_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [119] = 5,
    ACTIONS(247), 1,
      anon_sym_BQUOTE,
    ACTIONS(249), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(251), 1,
      sym_escape_sequence,
    STATE(29), 1,
      aux_sym_backtick_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [136] = 5,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    ACTIONS(255), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(257), 1,
      sym_escape_sequence,
    STATE(30), 1,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(203), 2,
      sym_line_continuation,
      sym_comment,
  [153] = 3,
    ACTIONS(259), 1,
      sym_numeric_literal,
    ACTIONS(261), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [164] = 2,
    ACTIONS(263), 1,
      sym_numeric_literal,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [172] = 2,
    ACTIONS(265), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [180] = 2,
    ACTIONS(267), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
  [188] = 2,
    ACTIONS(269), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_line_continuation,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(28)] = 0,
  [SMALL_STATE(29)] = 17,
  [SMALL_STATE(30)] = 34,
  [SMALL_STATE(31)] = 51,
  [SMALL_STATE(32)] = 68,
  [SMALL_STATE(33)] = 85,
  [SMALL_STATE(34)] = 102,
  [SMALL_STATE(35)] = 119,
  [SMALL_STATE(36)] = 136,
  [SMALL_STATE(37)] = 153,
  [SMALL_STATE(38)] = 164,
  [SMALL_STATE(39)] = 172,
  [SMALL_STATE(40)] = 180,
  [SMALL_STATE(41)] = 188,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_type, 1, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_type, 1, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unit_fractional_type, 1, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unit_fractional_type, 1, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fixed_point_type, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fixed_point_type, 1, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_numeric_constant_type, 1, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_numeric_constant_type, 1, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scalar_type, 1, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scalar_type, 1, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pointer_type, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pointer_type, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_address_type, 1, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_address_type, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_type, 1, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quantity_type, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 1, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 1, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector_type, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector_type, 2, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typed_element_array_type, 4, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typed_element_array_type, 4, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 1, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_type, 1, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typed_element_array_type, 3, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typed_element_array_type, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_backtick_quoted_string, 3, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_backtick_quoted_string, 3, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pointer_addressable_array_type, 3, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pointer_addressable_array_type, 3, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_backtick_quoted_string, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_backtick_quoted_string, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0),
  [219] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [222] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0),
  [233] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [236] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0),
  [241] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [244] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [255] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [265] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
