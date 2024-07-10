#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 42
#define LARGE_STATE_COUNT 29
#define SYMBOL_COUNT 64
#define ALIAS_COUNT 0
#define TOKEN_COUNT 40
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_boolean_literal = 1,
  sym_numeric_literal = 2,
  anon_sym_U = 3,
  anon_sym_UU = 4,
  anon_sym_UUU = 5,
  anon_sym_S = 6,
  anon_sym_SS = 7,
  anon_sym_SSS = 8,
  anon_sym_F = 9,
  anon_sym_FF = 10,
  anon_sym_FFF = 11,
  anon_sym_UF = 12,
  anon_sym_SSF = 13,
  anon_sym_UFFF = 14,
  anon_sym_Int = 15,
  anon_sym_Real = 16,
  sym_bool_type = 17,
  sym_void_type = 18,
  anon_sym_CC = 19,
  anon_sym_CCC = 20,
  anon_sym_MM = 21,
  anon_sym_MMM = 22,
  anon_sym_PP = 23,
  anon_sym_PPP = 24,
  anon_sym_AA = 25,
  anon_sym_AAA = 26,
  sym_function_pointer_type = 27,
  anon_sym_LBRACK = 28,
  aux_sym_typed_element_array_type_token1 = 29,
  anon_sym_RBRACK = 30,
  anon_sym_LBRACE_RBRACE = 31,
  anon_sym_SQUOTE = 32,
  aux_sym_single_quoted_string_token1 = 33,
  anon_sym_DQUOTE = 34,
  aux_sym_double_quoted_string_token1 = 35,
  anon_sym_BQUOTE = 36,
  aux_sym_backtick_quoted_string_token1 = 37,
  sym_escape_sequence = 38,
  sym_comment = 39,
  sym_program = 40,
  sym_statement = 41,
  sym_literal = 42,
  sym_string_literal = 43,
  sym_type = 44,
  sym_scalar_type = 45,
  sym_integer_type = 46,
  sym_unit_fractional_type = 47,
  sym_fixed_point_type = 48,
  sym_numeric_constant_type = 49,
  sym_quantity_type = 50,
  sym_pointer_type = 51,
  sym_address_type = 52,
  sym_array_type = 53,
  sym_typed_element_array_type = 54,
  sym_vector_type = 55,
  sym_pointer_addressable_array_type = 56,
  sym_single_quoted_string = 57,
  sym_double_quoted_string = 58,
  sym_backtick_quoted_string = 59,
  aux_sym_program_repeat1 = 60,
  aux_sym_single_quoted_string_repeat1 = 61,
  aux_sym_double_quoted_string_repeat1 = 62,
  aux_sym_backtick_quoted_string_repeat1 = 63,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [aux_sym_typed_element_array_type_token1] = "typed_element_array_type_token1",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE_RBRACE] = "{}",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_single_quoted_string_token1] = "single_quoted_string_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_double_quoted_string_token1] = "double_quoted_string_token1",
  [anon_sym_BQUOTE] = "`",
  [aux_sym_backtick_quoted_string_token1] = "backtick_quoted_string_token1",
  [sym_escape_sequence] = "escape_sequence",
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
  [aux_sym_typed_element_array_type_token1] = aux_sym_typed_element_array_type_token1,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE_RBRACE] = anon_sym_LBRACE_RBRACE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_single_quoted_string_token1] = aux_sym_single_quoted_string_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_double_quoted_string_token1] = aux_sym_double_quoted_string_token1,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_backtick_quoted_string_token1] = aux_sym_backtick_quoted_string_token1,
  [sym_escape_sequence] = sym_escape_sequence,
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
  [aux_sym_typed_element_array_type_token1] = {
    .visible = false,
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

static TSCharacterRange extras_character_set_1[] = {
  {'\t', '\r'}, {' ', ' '}, {0xa0, 0xa0}, {0x1680, 0x1680}, {0x2000, 0x200b}, {0x2028, 0x2029}, {0x202f, 0x202f}, {0x205f, 0x2060},
  {0x3000, 0x3000}, {0xfeff, 0xfeff},
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
      if (eof) ADVANCE(52);
      ADVANCE_MAP(
        '"', 96,
        '$', 7,
        '%', 8,
        '\'', 89,
        '.', 40,
        '/', 3,
        'A', 12,
        'B', 31,
        'C', 13,
        'F', 66,
        'I', 28,
        'M', 15,
        'P', 16,
        'R', 23,
        'S', 63,
        'U', 60,
        'V', 29,
        '[', 85,
        '\\', 17,
        ']', 87,
        '`', 103,
        'f', 18,
        't', 32,
        '{', 38,
        '+', 6,
        '-', 6,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (set_contains(extras_character_set_1, 10, lookahead)) SKIP(50);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(96);
      if (lookahead == '/') ADVANCE(97);
      if (lookahead == '\\') ADVANCE(17);
      if (set_contains(extras_character_set_1, 10, lookahead)) ADVANCE(100);
      if (lookahead != 0) ADVANCE(102);
      END_STATE();
    case 2:
      if (lookahead == '\'') ADVANCE(89);
      if (lookahead == '/') ADVANCE(90);
      if (lookahead == '\\') ADVANCE(17);
      if (set_contains(extras_character_set_1, 10, lookahead)) ADVANCE(93);
      if (lookahead != 0) ADVANCE(95);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(112);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(111);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(39);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(56);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(34);
      END_STATE();
    case 10:
      if (lookahead == '/') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(86);
      if (set_contains(extras_character_set_1, 10, lookahead)) SKIP(10);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(104);
      if (lookahead == '\\') ADVANCE(17);
      if (lookahead == '`') ADVANCE(103);
      if (set_contains(extras_character_set_1, 10, lookahead)) ADVANCE(107);
      if (lookahead != 0) ADVANCE(109);
      END_STATE();
    case 12:
      if (lookahead == 'A') ADVANCE(82);
      END_STATE();
    case 13:
      if (lookahead == 'C') ADVANCE(76);
      END_STATE();
    case 14:
      if (lookahead == 'F') ADVANCE(71);
      END_STATE();
    case 15:
      if (lookahead == 'M') ADVANCE(78);
      END_STATE();
    case 16:
      if (lookahead == 'P') ADVANCE(80);
      END_STATE();
    case 17:
      if (lookahead == 'U') ADVANCE(49);
      if (lookahead == 'u') ADVANCE(45);
      if (lookahead == 'x') ADVANCE(43);
      if (set_contains(sym_escape_sequence_character_set_1, 11, lookahead)) ADVANCE(110);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(27);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(26);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(75);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 24:
      if (lookahead == 'i') ADVANCE(20);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(74);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 28:
      if (lookahead == 'n') ADVANCE(35);
      END_STATE();
    case 29:
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 31:
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(21);
      END_STATE();
    case 34:
      if (lookahead == 's') ADVANCE(22);
      END_STATE();
    case 35:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(84);
      END_STATE();
    case 37:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 38:
      if (lookahead == '}') ADVANCE(88);
      END_STATE();
    case 39:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(57);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(110);
      END_STATE();
    case 42:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(41);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(44);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 50:
      if (eof) ADVANCE(52);
      ADVANCE_MAP(
        '"', 96,
        '$', 7,
        '%', 8,
        '\'', 89,
        '.', 40,
        '/', 3,
        'A', 12,
        'B', 31,
        'C', 13,
        'F', 66,
        'I', 28,
        'M', 15,
        'P', 16,
        'R', 23,
        'S', 63,
        'U', 60,
        'V', 29,
        '[', 85,
        ']', 87,
        '`', 103,
        'f', 18,
        't', 32,
        '{', 38,
        '+', 6,
        '-', 6,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (set_contains(extras_character_set_1, 10, lookahead)) SKIP(50);
      END_STATE();
    case 51:
      if (eof) ADVANCE(52);
      ADVANCE_MAP(
        '"', 96,
        '$', 7,
        '%', 8,
        '\'', 89,
        '.', 40,
        '/', 3,
        'A', 12,
        'B', 31,
        'C', 13,
        'F', 66,
        'I', 28,
        'M', 15,
        'P', 16,
        'R', 23,
        'S', 63,
        'U', 60,
        'V', 29,
        '[', 85,
        '`', 103,
        'f', 18,
        't', 32,
        '{', 38,
        '+', 6,
        '-', 6,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (set_contains(extras_character_set_1, 10, lookahead)) SKIP(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_boolean_literal);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '.') ADVANCE(57);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_numeric_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_U);
      if (lookahead == 'F') ADVANCE(69);
      if (lookahead == 'U') ADVANCE(61);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_UU);
      if (lookahead == 'U') ADVANCE(62);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_UUU);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_S);
      if (lookahead == 'S') ADVANCE(64);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_SS);
      if (lookahead == 'F') ADVANCE(70);
      if (lookahead == 'S') ADVANCE(65);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_SSS);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_F);
      if (lookahead == 'F') ADVANCE(67);
      if (lookahead == 'n') ADVANCE(9);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_FF);
      if (lookahead == 'F') ADVANCE(68);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_FFF);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_UF);
      if (lookahead == 'F') ADVANCE(14);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_SSF);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_UFFF);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_Int);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_Real);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_bool_type);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_void_type);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_CC);
      if (lookahead == 'C') ADVANCE(77);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_CCC);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_MM);
      if (lookahead == 'M') ADVANCE(79);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_MMM);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_PP);
      if (lookahead == 'P') ADVANCE(81);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_PPP);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_AA);
      if (lookahead == 'A') ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_AAA);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_function_pointer_type);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_typed_element_array_type_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_LBRACE_RBRACE);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(92);
      if (lookahead == '/') ADVANCE(94);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(95);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(91);
      if (lookahead == '/') ADVANCE(95);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(92);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '*') ADVANCE(91);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '/') ADVANCE(90);
      if (set_contains(extras_character_set_1, 10, lookahead)) ADVANCE(93);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(95);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead == '\'' ||
          lookahead == '\\') ADVANCE(112);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(95);
      if (lookahead != 0) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_single_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(95);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(99);
      if (lookahead == '/') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(102);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(98);
      if (lookahead == '/') ADVANCE(102);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(99);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '*') ADVANCE(98);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(5);
      if (lookahead != 0) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '/') ADVANCE(97);
      if (set_contains(extras_character_set_1, 10, lookahead)) ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(102);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(112);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(102);
      if (lookahead != 0) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_double_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(102);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(106);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(109);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(105);
      if (lookahead == '/') ADVANCE(109);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(5);
      if (lookahead != 0) ADVANCE(106);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '*') ADVANCE(105);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(5);
      if (lookahead != 0) ADVANCE(106);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '/') ADVANCE(104);
      if (set_contains(extras_character_set_1, 10, lookahead)) ADVANCE(107);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(109);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead == '\\' ||
          lookahead == '`') ADVANCE(112);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == 0x2028 ||
          lookahead == 0x2029) ADVANCE(109);
      if (lookahead != 0) ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_backtick_quoted_string_token1);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(109);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(112);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 51},
  [2] = {.lex_state = 51},
  [3] = {.lex_state = 51},
  [4] = {.lex_state = 51},
  [5] = {.lex_state = 51},
  [6] = {.lex_state = 51},
  [7] = {.lex_state = 51},
  [8] = {.lex_state = 51},
  [9] = {.lex_state = 51},
  [10] = {.lex_state = 51},
  [11] = {.lex_state = 51},
  [12] = {.lex_state = 51},
  [13] = {.lex_state = 51},
  [14] = {.lex_state = 51},
  [15] = {.lex_state = 51},
  [16] = {.lex_state = 51},
  [17] = {.lex_state = 51},
  [18] = {.lex_state = 51},
  [19] = {.lex_state = 51},
  [20] = {.lex_state = 51},
  [21] = {.lex_state = 51},
  [22] = {.lex_state = 51},
  [23] = {.lex_state = 51},
  [24] = {.lex_state = 51},
  [25] = {.lex_state = 51},
  [26] = {.lex_state = 51},
  [27] = {.lex_state = 51},
  [28] = {.lex_state = 51},
  [29] = {.lex_state = 11},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 11},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 11},
  [38] = {.lex_state = 10},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
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
    [aux_sym_typed_element_array_type_token1] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
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
    [sym_quantity_type] = STATE(13),
    [sym_pointer_type] = STATE(12),
    [sym_address_type] = STATE(12),
    [sym_array_type] = STATE(19),
    [sym_typed_element_array_type] = STATE(14),
    [sym_vector_type] = STATE(14),
    [sym_pointer_addressable_array_type] = STATE(14),
    [sym_single_quoted_string] = STATE(21),
    [sym_double_quoted_string] = STATE(21),
    [sym_backtick_quoted_string] = STATE(21),
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
    [sym_quantity_type] = STATE(13),
    [sym_pointer_type] = STATE(12),
    [sym_address_type] = STATE(12),
    [sym_array_type] = STATE(19),
    [sym_typed_element_array_type] = STATE(14),
    [sym_vector_type] = STATE(14),
    [sym_pointer_addressable_array_type] = STATE(14),
    [sym_single_quoted_string] = STATE(21),
    [sym_double_quoted_string] = STATE(21),
    [sym_backtick_quoted_string] = STATE(21),
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
    [sym_quantity_type] = STATE(13),
    [sym_pointer_type] = STATE(12),
    [sym_address_type] = STATE(12),
    [sym_array_type] = STATE(19),
    [sym_typed_element_array_type] = STATE(14),
    [sym_vector_type] = STATE(14),
    [sym_pointer_addressable_array_type] = STATE(14),
    [sym_single_quoted_string] = STATE(21),
    [sym_double_quoted_string] = STATE(21),
    [sym_backtick_quoted_string] = STATE(21),
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
    [anon_sym_LBRACK] = ACTIONS(101),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(105),
    [anon_sym_SQUOTE] = ACTIONS(101),
    [anon_sym_DQUOTE] = ACTIONS(101),
    [anon_sym_BQUOTE] = ACTIONS(101),
    [sym_comment] = ACTIONS(3),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(107),
    [sym_boolean_literal] = ACTIONS(107),
    [sym_numeric_literal] = ACTIONS(107),
    [anon_sym_U] = ACTIONS(109),
    [anon_sym_UU] = ACTIONS(109),
    [anon_sym_UUU] = ACTIONS(107),
    [anon_sym_S] = ACTIONS(109),
    [anon_sym_SS] = ACTIONS(109),
    [anon_sym_SSS] = ACTIONS(107),
    [anon_sym_F] = ACTIONS(109),
    [anon_sym_FF] = ACTIONS(109),
    [anon_sym_FFF] = ACTIONS(107),
    [anon_sym_UF] = ACTIONS(109),
    [anon_sym_SSF] = ACTIONS(107),
    [anon_sym_UFFF] = ACTIONS(107),
    [anon_sym_Int] = ACTIONS(107),
    [anon_sym_Real] = ACTIONS(107),
    [sym_bool_type] = ACTIONS(107),
    [sym_void_type] = ACTIONS(107),
    [anon_sym_CC] = ACTIONS(109),
    [anon_sym_CCC] = ACTIONS(107),
    [anon_sym_MM] = ACTIONS(109),
    [anon_sym_MMM] = ACTIONS(107),
    [anon_sym_PP] = ACTIONS(109),
    [anon_sym_PPP] = ACTIONS(107),
    [anon_sym_AA] = ACTIONS(109),
    [anon_sym_AAA] = ACTIONS(107),
    [sym_function_pointer_type] = ACTIONS(107),
    [anon_sym_LBRACK] = ACTIONS(107),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(107),
    [anon_sym_SQUOTE] = ACTIONS(107),
    [anon_sym_DQUOTE] = ACTIONS(107),
    [anon_sym_BQUOTE] = ACTIONS(107),
    [sym_comment] = ACTIONS(3),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(111),
    [sym_boolean_literal] = ACTIONS(111),
    [sym_numeric_literal] = ACTIONS(111),
    [anon_sym_U] = ACTIONS(113),
    [anon_sym_UU] = ACTIONS(113),
    [anon_sym_UUU] = ACTIONS(111),
    [anon_sym_S] = ACTIONS(113),
    [anon_sym_SS] = ACTIONS(113),
    [anon_sym_SSS] = ACTIONS(111),
    [anon_sym_F] = ACTIONS(113),
    [anon_sym_FF] = ACTIONS(113),
    [anon_sym_FFF] = ACTIONS(111),
    [anon_sym_UF] = ACTIONS(113),
    [anon_sym_SSF] = ACTIONS(111),
    [anon_sym_UFFF] = ACTIONS(111),
    [anon_sym_Int] = ACTIONS(111),
    [anon_sym_Real] = ACTIONS(111),
    [sym_bool_type] = ACTIONS(111),
    [sym_void_type] = ACTIONS(111),
    [anon_sym_CC] = ACTIONS(113),
    [anon_sym_CCC] = ACTIONS(111),
    [anon_sym_MM] = ACTIONS(113),
    [anon_sym_MMM] = ACTIONS(111),
    [anon_sym_PP] = ACTIONS(113),
    [anon_sym_PPP] = ACTIONS(111),
    [anon_sym_AA] = ACTIONS(113),
    [anon_sym_AAA] = ACTIONS(111),
    [sym_function_pointer_type] = ACTIONS(111),
    [anon_sym_LBRACK] = ACTIONS(111),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(111),
    [anon_sym_SQUOTE] = ACTIONS(111),
    [anon_sym_DQUOTE] = ACTIONS(111),
    [anon_sym_BQUOTE] = ACTIONS(111),
    [sym_comment] = ACTIONS(3),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(115),
    [sym_boolean_literal] = ACTIONS(115),
    [sym_numeric_literal] = ACTIONS(115),
    [anon_sym_U] = ACTIONS(117),
    [anon_sym_UU] = ACTIONS(117),
    [anon_sym_UUU] = ACTIONS(115),
    [anon_sym_S] = ACTIONS(117),
    [anon_sym_SS] = ACTIONS(117),
    [anon_sym_SSS] = ACTIONS(115),
    [anon_sym_F] = ACTIONS(117),
    [anon_sym_FF] = ACTIONS(117),
    [anon_sym_FFF] = ACTIONS(115),
    [anon_sym_UF] = ACTIONS(117),
    [anon_sym_SSF] = ACTIONS(115),
    [anon_sym_UFFF] = ACTIONS(115),
    [anon_sym_Int] = ACTIONS(115),
    [anon_sym_Real] = ACTIONS(115),
    [sym_bool_type] = ACTIONS(115),
    [sym_void_type] = ACTIONS(115),
    [anon_sym_CC] = ACTIONS(117),
    [anon_sym_CCC] = ACTIONS(115),
    [anon_sym_MM] = ACTIONS(117),
    [anon_sym_MMM] = ACTIONS(115),
    [anon_sym_PP] = ACTIONS(117),
    [anon_sym_PPP] = ACTIONS(115),
    [anon_sym_AA] = ACTIONS(117),
    [anon_sym_AAA] = ACTIONS(115),
    [sym_function_pointer_type] = ACTIONS(115),
    [anon_sym_LBRACK] = ACTIONS(115),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(115),
    [anon_sym_SQUOTE] = ACTIONS(115),
    [anon_sym_DQUOTE] = ACTIONS(115),
    [anon_sym_BQUOTE] = ACTIONS(115),
    [sym_comment] = ACTIONS(3),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(119),
    [sym_boolean_literal] = ACTIONS(119),
    [sym_numeric_literal] = ACTIONS(119),
    [anon_sym_U] = ACTIONS(121),
    [anon_sym_UU] = ACTIONS(121),
    [anon_sym_UUU] = ACTIONS(119),
    [anon_sym_S] = ACTIONS(121),
    [anon_sym_SS] = ACTIONS(121),
    [anon_sym_SSS] = ACTIONS(119),
    [anon_sym_F] = ACTIONS(121),
    [anon_sym_FF] = ACTIONS(121),
    [anon_sym_FFF] = ACTIONS(119),
    [anon_sym_UF] = ACTIONS(121),
    [anon_sym_SSF] = ACTIONS(119),
    [anon_sym_UFFF] = ACTIONS(119),
    [anon_sym_Int] = ACTIONS(119),
    [anon_sym_Real] = ACTIONS(119),
    [sym_bool_type] = ACTIONS(119),
    [sym_void_type] = ACTIONS(119),
    [anon_sym_CC] = ACTIONS(121),
    [anon_sym_CCC] = ACTIONS(119),
    [anon_sym_MM] = ACTIONS(121),
    [anon_sym_MMM] = ACTIONS(119),
    [anon_sym_PP] = ACTIONS(121),
    [anon_sym_PPP] = ACTIONS(119),
    [anon_sym_AA] = ACTIONS(121),
    [anon_sym_AAA] = ACTIONS(119),
    [sym_function_pointer_type] = ACTIONS(119),
    [anon_sym_LBRACK] = ACTIONS(119),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(119),
    [anon_sym_SQUOTE] = ACTIONS(119),
    [anon_sym_DQUOTE] = ACTIONS(119),
    [anon_sym_BQUOTE] = ACTIONS(119),
    [sym_comment] = ACTIONS(3),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(123),
    [sym_boolean_literal] = ACTIONS(123),
    [sym_numeric_literal] = ACTIONS(123),
    [anon_sym_U] = ACTIONS(125),
    [anon_sym_UU] = ACTIONS(125),
    [anon_sym_UUU] = ACTIONS(123),
    [anon_sym_S] = ACTIONS(125),
    [anon_sym_SS] = ACTIONS(125),
    [anon_sym_SSS] = ACTIONS(123),
    [anon_sym_F] = ACTIONS(125),
    [anon_sym_FF] = ACTIONS(125),
    [anon_sym_FFF] = ACTIONS(123),
    [anon_sym_UF] = ACTIONS(125),
    [anon_sym_SSF] = ACTIONS(123),
    [anon_sym_UFFF] = ACTIONS(123),
    [anon_sym_Int] = ACTIONS(123),
    [anon_sym_Real] = ACTIONS(123),
    [sym_bool_type] = ACTIONS(123),
    [sym_void_type] = ACTIONS(123),
    [anon_sym_CC] = ACTIONS(125),
    [anon_sym_CCC] = ACTIONS(123),
    [anon_sym_MM] = ACTIONS(125),
    [anon_sym_MMM] = ACTIONS(123),
    [anon_sym_PP] = ACTIONS(125),
    [anon_sym_PPP] = ACTIONS(123),
    [anon_sym_AA] = ACTIONS(125),
    [anon_sym_AAA] = ACTIONS(123),
    [sym_function_pointer_type] = ACTIONS(123),
    [anon_sym_LBRACK] = ACTIONS(123),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(123),
    [anon_sym_SQUOTE] = ACTIONS(123),
    [anon_sym_DQUOTE] = ACTIONS(123),
    [anon_sym_BQUOTE] = ACTIONS(123),
    [sym_comment] = ACTIONS(3),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(127),
    [sym_boolean_literal] = ACTIONS(127),
    [sym_numeric_literal] = ACTIONS(127),
    [anon_sym_U] = ACTIONS(129),
    [anon_sym_UU] = ACTIONS(129),
    [anon_sym_UUU] = ACTIONS(127),
    [anon_sym_S] = ACTIONS(129),
    [anon_sym_SS] = ACTIONS(129),
    [anon_sym_SSS] = ACTIONS(127),
    [anon_sym_F] = ACTIONS(129),
    [anon_sym_FF] = ACTIONS(129),
    [anon_sym_FFF] = ACTIONS(127),
    [anon_sym_UF] = ACTIONS(129),
    [anon_sym_SSF] = ACTIONS(127),
    [anon_sym_UFFF] = ACTIONS(127),
    [anon_sym_Int] = ACTIONS(127),
    [anon_sym_Real] = ACTIONS(127),
    [sym_bool_type] = ACTIONS(127),
    [sym_void_type] = ACTIONS(127),
    [anon_sym_CC] = ACTIONS(129),
    [anon_sym_CCC] = ACTIONS(127),
    [anon_sym_MM] = ACTIONS(129),
    [anon_sym_MMM] = ACTIONS(127),
    [anon_sym_PP] = ACTIONS(129),
    [anon_sym_PPP] = ACTIONS(127),
    [anon_sym_AA] = ACTIONS(129),
    [anon_sym_AAA] = ACTIONS(127),
    [sym_function_pointer_type] = ACTIONS(127),
    [anon_sym_LBRACK] = ACTIONS(127),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(127),
    [anon_sym_SQUOTE] = ACTIONS(127),
    [anon_sym_DQUOTE] = ACTIONS(127),
    [anon_sym_BQUOTE] = ACTIONS(127),
    [sym_comment] = ACTIONS(3),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(131),
    [sym_boolean_literal] = ACTIONS(131),
    [sym_numeric_literal] = ACTIONS(131),
    [anon_sym_U] = ACTIONS(133),
    [anon_sym_UU] = ACTIONS(133),
    [anon_sym_UUU] = ACTIONS(131),
    [anon_sym_S] = ACTIONS(133),
    [anon_sym_SS] = ACTIONS(133),
    [anon_sym_SSS] = ACTIONS(131),
    [anon_sym_F] = ACTIONS(133),
    [anon_sym_FF] = ACTIONS(133),
    [anon_sym_FFF] = ACTIONS(131),
    [anon_sym_UF] = ACTIONS(133),
    [anon_sym_SSF] = ACTIONS(131),
    [anon_sym_UFFF] = ACTIONS(131),
    [anon_sym_Int] = ACTIONS(131),
    [anon_sym_Real] = ACTIONS(131),
    [sym_bool_type] = ACTIONS(131),
    [sym_void_type] = ACTIONS(131),
    [anon_sym_CC] = ACTIONS(133),
    [anon_sym_CCC] = ACTIONS(131),
    [anon_sym_MM] = ACTIONS(133),
    [anon_sym_MMM] = ACTIONS(131),
    [anon_sym_PP] = ACTIONS(133),
    [anon_sym_PPP] = ACTIONS(131),
    [anon_sym_AA] = ACTIONS(133),
    [anon_sym_AAA] = ACTIONS(131),
    [sym_function_pointer_type] = ACTIONS(131),
    [anon_sym_LBRACK] = ACTIONS(131),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(131),
    [anon_sym_SQUOTE] = ACTIONS(131),
    [anon_sym_DQUOTE] = ACTIONS(131),
    [anon_sym_BQUOTE] = ACTIONS(131),
    [sym_comment] = ACTIONS(3),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(135),
    [sym_boolean_literal] = ACTIONS(135),
    [sym_numeric_literal] = ACTIONS(135),
    [anon_sym_U] = ACTIONS(137),
    [anon_sym_UU] = ACTIONS(137),
    [anon_sym_UUU] = ACTIONS(135),
    [anon_sym_S] = ACTIONS(137),
    [anon_sym_SS] = ACTIONS(137),
    [anon_sym_SSS] = ACTIONS(135),
    [anon_sym_F] = ACTIONS(137),
    [anon_sym_FF] = ACTIONS(137),
    [anon_sym_FFF] = ACTIONS(135),
    [anon_sym_UF] = ACTIONS(137),
    [anon_sym_SSF] = ACTIONS(135),
    [anon_sym_UFFF] = ACTIONS(135),
    [anon_sym_Int] = ACTIONS(135),
    [anon_sym_Real] = ACTIONS(135),
    [sym_bool_type] = ACTIONS(135),
    [sym_void_type] = ACTIONS(135),
    [anon_sym_CC] = ACTIONS(137),
    [anon_sym_CCC] = ACTIONS(135),
    [anon_sym_MM] = ACTIONS(137),
    [anon_sym_MMM] = ACTIONS(135),
    [anon_sym_PP] = ACTIONS(137),
    [anon_sym_PPP] = ACTIONS(135),
    [anon_sym_AA] = ACTIONS(137),
    [anon_sym_AAA] = ACTIONS(135),
    [sym_function_pointer_type] = ACTIONS(135),
    [anon_sym_LBRACK] = ACTIONS(135),
    [anon_sym_LBRACE_RBRACE] = ACTIONS(135),
    [anon_sym_SQUOTE] = ACTIONS(135),
    [anon_sym_DQUOTE] = ACTIONS(135),
    [anon_sym_BQUOTE] = ACTIONS(135),
    [sym_comment] = ACTIONS(3),
  },
  [13] = {
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
    [anon_sym_LBRACE_RBRACE] = ACTIONS(105),
    [anon_sym_SQUOTE] = ACTIONS(101),
    [anon_sym_DQUOTE] = ACTIONS(101),
    [anon_sym_BQUOTE] = ACTIONS(101),
    [sym_comment] = ACTIONS(3),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(139),
    [sym_boolean_literal] = ACTIONS(139),
    [sym_numeric_literal] = ACTIONS(139),
    [anon_sym_U] = ACTIONS(141),
    [anon_sym_UU] = ACTIONS(141),
    [anon_sym_UUU] = ACTIONS(139),
    [anon_sym_S] = ACTIONS(141),
    [anon_sym_SS] = ACTIONS(141),
    [anon_sym_SSS] = ACTIONS(139),
    [anon_sym_F] = ACTIONS(141),
    [anon_sym_FF] = ACTIONS(141),
    [anon_sym_FFF] = ACTIONS(139),
    [anon_sym_UF] = ACTIONS(141),
    [anon_sym_SSF] = ACTIONS(139),
    [anon_sym_UFFF] = ACTIONS(139),
    [anon_sym_Int] = ACTIONS(139),
    [anon_sym_Real] = ACTIONS(139),
    [sym_bool_type] = ACTIONS(139),
    [sym_void_type] = ACTIONS(139),
    [anon_sym_CC] = ACTIONS(141),
    [anon_sym_CCC] = ACTIONS(139),
    [anon_sym_MM] = ACTIONS(141),
    [anon_sym_MMM] = ACTIONS(139),
    [anon_sym_PP] = ACTIONS(141),
    [anon_sym_PPP] = ACTIONS(139),
    [anon_sym_AA] = ACTIONS(141),
    [anon_sym_AAA] = ACTIONS(139),
    [sym_function_pointer_type] = ACTIONS(139),
    [anon_sym_LBRACK] = ACTIONS(139),
    [anon_sym_SQUOTE] = ACTIONS(139),
    [anon_sym_DQUOTE] = ACTIONS(139),
    [anon_sym_BQUOTE] = ACTIONS(139),
    [sym_comment] = ACTIONS(3),
  },
  [15] = {
    [ts_builtin_sym_end] = ACTIONS(143),
    [sym_boolean_literal] = ACTIONS(143),
    [sym_numeric_literal] = ACTIONS(143),
    [anon_sym_U] = ACTIONS(145),
    [anon_sym_UU] = ACTIONS(145),
    [anon_sym_UUU] = ACTIONS(143),
    [anon_sym_S] = ACTIONS(145),
    [anon_sym_SS] = ACTIONS(145),
    [anon_sym_SSS] = ACTIONS(143),
    [anon_sym_F] = ACTIONS(145),
    [anon_sym_FF] = ACTIONS(145),
    [anon_sym_FFF] = ACTIONS(143),
    [anon_sym_UF] = ACTIONS(145),
    [anon_sym_SSF] = ACTIONS(143),
    [anon_sym_UFFF] = ACTIONS(143),
    [anon_sym_Int] = ACTIONS(143),
    [anon_sym_Real] = ACTIONS(143),
    [sym_bool_type] = ACTIONS(143),
    [sym_void_type] = ACTIONS(143),
    [anon_sym_CC] = ACTIONS(145),
    [anon_sym_CCC] = ACTIONS(143),
    [anon_sym_MM] = ACTIONS(145),
    [anon_sym_MMM] = ACTIONS(143),
    [anon_sym_PP] = ACTIONS(145),
    [anon_sym_PPP] = ACTIONS(143),
    [anon_sym_AA] = ACTIONS(145),
    [anon_sym_AAA] = ACTIONS(143),
    [sym_function_pointer_type] = ACTIONS(143),
    [anon_sym_LBRACK] = ACTIONS(143),
    [anon_sym_SQUOTE] = ACTIONS(143),
    [anon_sym_DQUOTE] = ACTIONS(143),
    [anon_sym_BQUOTE] = ACTIONS(143),
    [sym_comment] = ACTIONS(3),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(147),
    [sym_boolean_literal] = ACTIONS(147),
    [sym_numeric_literal] = ACTIONS(147),
    [anon_sym_U] = ACTIONS(149),
    [anon_sym_UU] = ACTIONS(149),
    [anon_sym_UUU] = ACTIONS(147),
    [anon_sym_S] = ACTIONS(149),
    [anon_sym_SS] = ACTIONS(149),
    [anon_sym_SSS] = ACTIONS(147),
    [anon_sym_F] = ACTIONS(149),
    [anon_sym_FF] = ACTIONS(149),
    [anon_sym_FFF] = ACTIONS(147),
    [anon_sym_UF] = ACTIONS(149),
    [anon_sym_SSF] = ACTIONS(147),
    [anon_sym_UFFF] = ACTIONS(147),
    [anon_sym_Int] = ACTIONS(147),
    [anon_sym_Real] = ACTIONS(147),
    [sym_bool_type] = ACTIONS(147),
    [sym_void_type] = ACTIONS(147),
    [anon_sym_CC] = ACTIONS(149),
    [anon_sym_CCC] = ACTIONS(147),
    [anon_sym_MM] = ACTIONS(149),
    [anon_sym_MMM] = ACTIONS(147),
    [anon_sym_PP] = ACTIONS(149),
    [anon_sym_PPP] = ACTIONS(147),
    [anon_sym_AA] = ACTIONS(149),
    [anon_sym_AAA] = ACTIONS(147),
    [sym_function_pointer_type] = ACTIONS(147),
    [anon_sym_LBRACK] = ACTIONS(147),
    [anon_sym_SQUOTE] = ACTIONS(147),
    [anon_sym_DQUOTE] = ACTIONS(147),
    [anon_sym_BQUOTE] = ACTIONS(147),
    [sym_comment] = ACTIONS(3),
  },
  [17] = {
    [ts_builtin_sym_end] = ACTIONS(151),
    [sym_boolean_literal] = ACTIONS(151),
    [sym_numeric_literal] = ACTIONS(151),
    [anon_sym_U] = ACTIONS(153),
    [anon_sym_UU] = ACTIONS(153),
    [anon_sym_UUU] = ACTIONS(151),
    [anon_sym_S] = ACTIONS(153),
    [anon_sym_SS] = ACTIONS(153),
    [anon_sym_SSS] = ACTIONS(151),
    [anon_sym_F] = ACTIONS(153),
    [anon_sym_FF] = ACTIONS(153),
    [anon_sym_FFF] = ACTIONS(151),
    [anon_sym_UF] = ACTIONS(153),
    [anon_sym_SSF] = ACTIONS(151),
    [anon_sym_UFFF] = ACTIONS(151),
    [anon_sym_Int] = ACTIONS(151),
    [anon_sym_Real] = ACTIONS(151),
    [sym_bool_type] = ACTIONS(151),
    [sym_void_type] = ACTIONS(151),
    [anon_sym_CC] = ACTIONS(153),
    [anon_sym_CCC] = ACTIONS(151),
    [anon_sym_MM] = ACTIONS(153),
    [anon_sym_MMM] = ACTIONS(151),
    [anon_sym_PP] = ACTIONS(153),
    [anon_sym_PPP] = ACTIONS(151),
    [anon_sym_AA] = ACTIONS(153),
    [anon_sym_AAA] = ACTIONS(151),
    [sym_function_pointer_type] = ACTIONS(151),
    [anon_sym_LBRACK] = ACTIONS(151),
    [anon_sym_SQUOTE] = ACTIONS(151),
    [anon_sym_DQUOTE] = ACTIONS(151),
    [anon_sym_BQUOTE] = ACTIONS(151),
    [sym_comment] = ACTIONS(3),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(155),
    [sym_boolean_literal] = ACTIONS(155),
    [sym_numeric_literal] = ACTIONS(155),
    [anon_sym_U] = ACTIONS(157),
    [anon_sym_UU] = ACTIONS(157),
    [anon_sym_UUU] = ACTIONS(155),
    [anon_sym_S] = ACTIONS(157),
    [anon_sym_SS] = ACTIONS(157),
    [anon_sym_SSS] = ACTIONS(155),
    [anon_sym_F] = ACTIONS(157),
    [anon_sym_FF] = ACTIONS(157),
    [anon_sym_FFF] = ACTIONS(155),
    [anon_sym_UF] = ACTIONS(157),
    [anon_sym_SSF] = ACTIONS(155),
    [anon_sym_UFFF] = ACTIONS(155),
    [anon_sym_Int] = ACTIONS(155),
    [anon_sym_Real] = ACTIONS(155),
    [sym_bool_type] = ACTIONS(155),
    [sym_void_type] = ACTIONS(155),
    [anon_sym_CC] = ACTIONS(157),
    [anon_sym_CCC] = ACTIONS(155),
    [anon_sym_MM] = ACTIONS(157),
    [anon_sym_MMM] = ACTIONS(155),
    [anon_sym_PP] = ACTIONS(157),
    [anon_sym_PPP] = ACTIONS(155),
    [anon_sym_AA] = ACTIONS(157),
    [anon_sym_AAA] = ACTIONS(155),
    [sym_function_pointer_type] = ACTIONS(155),
    [anon_sym_LBRACK] = ACTIONS(155),
    [anon_sym_SQUOTE] = ACTIONS(155),
    [anon_sym_DQUOTE] = ACTIONS(155),
    [anon_sym_BQUOTE] = ACTIONS(155),
    [sym_comment] = ACTIONS(3),
  },
  [19] = {
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
    [sym_comment] = ACTIONS(3),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(159),
    [sym_boolean_literal] = ACTIONS(159),
    [sym_numeric_literal] = ACTIONS(159),
    [anon_sym_U] = ACTIONS(161),
    [anon_sym_UU] = ACTIONS(161),
    [anon_sym_UUU] = ACTIONS(159),
    [anon_sym_S] = ACTIONS(161),
    [anon_sym_SS] = ACTIONS(161),
    [anon_sym_SSS] = ACTIONS(159),
    [anon_sym_F] = ACTIONS(161),
    [anon_sym_FF] = ACTIONS(161),
    [anon_sym_FFF] = ACTIONS(159),
    [anon_sym_UF] = ACTIONS(161),
    [anon_sym_SSF] = ACTIONS(159),
    [anon_sym_UFFF] = ACTIONS(159),
    [anon_sym_Int] = ACTIONS(159),
    [anon_sym_Real] = ACTIONS(159),
    [sym_bool_type] = ACTIONS(159),
    [sym_void_type] = ACTIONS(159),
    [anon_sym_CC] = ACTIONS(161),
    [anon_sym_CCC] = ACTIONS(159),
    [anon_sym_MM] = ACTIONS(161),
    [anon_sym_MMM] = ACTIONS(159),
    [anon_sym_PP] = ACTIONS(161),
    [anon_sym_PPP] = ACTIONS(159),
    [anon_sym_AA] = ACTIONS(161),
    [anon_sym_AAA] = ACTIONS(159),
    [sym_function_pointer_type] = ACTIONS(159),
    [anon_sym_LBRACK] = ACTIONS(159),
    [anon_sym_SQUOTE] = ACTIONS(159),
    [anon_sym_DQUOTE] = ACTIONS(159),
    [anon_sym_BQUOTE] = ACTIONS(159),
    [sym_comment] = ACTIONS(3),
  },
  [21] = {
    [ts_builtin_sym_end] = ACTIONS(163),
    [sym_boolean_literal] = ACTIONS(163),
    [sym_numeric_literal] = ACTIONS(163),
    [anon_sym_U] = ACTIONS(165),
    [anon_sym_UU] = ACTIONS(165),
    [anon_sym_UUU] = ACTIONS(163),
    [anon_sym_S] = ACTIONS(165),
    [anon_sym_SS] = ACTIONS(165),
    [anon_sym_SSS] = ACTIONS(163),
    [anon_sym_F] = ACTIONS(165),
    [anon_sym_FF] = ACTIONS(165),
    [anon_sym_FFF] = ACTIONS(163),
    [anon_sym_UF] = ACTIONS(165),
    [anon_sym_SSF] = ACTIONS(163),
    [anon_sym_UFFF] = ACTIONS(163),
    [anon_sym_Int] = ACTIONS(163),
    [anon_sym_Real] = ACTIONS(163),
    [sym_bool_type] = ACTIONS(163),
    [sym_void_type] = ACTIONS(163),
    [anon_sym_CC] = ACTIONS(165),
    [anon_sym_CCC] = ACTIONS(163),
    [anon_sym_MM] = ACTIONS(165),
    [anon_sym_MMM] = ACTIONS(163),
    [anon_sym_PP] = ACTIONS(165),
    [anon_sym_PPP] = ACTIONS(163),
    [anon_sym_AA] = ACTIONS(165),
    [anon_sym_AAA] = ACTIONS(163),
    [sym_function_pointer_type] = ACTIONS(163),
    [anon_sym_LBRACK] = ACTIONS(163),
    [anon_sym_SQUOTE] = ACTIONS(163),
    [anon_sym_DQUOTE] = ACTIONS(163),
    [anon_sym_BQUOTE] = ACTIONS(163),
    [sym_comment] = ACTIONS(3),
  },
  [22] = {
    [ts_builtin_sym_end] = ACTIONS(167),
    [sym_boolean_literal] = ACTIONS(167),
    [sym_numeric_literal] = ACTIONS(167),
    [anon_sym_U] = ACTIONS(169),
    [anon_sym_UU] = ACTIONS(169),
    [anon_sym_UUU] = ACTIONS(167),
    [anon_sym_S] = ACTIONS(169),
    [anon_sym_SS] = ACTIONS(169),
    [anon_sym_SSS] = ACTIONS(167),
    [anon_sym_F] = ACTIONS(169),
    [anon_sym_FF] = ACTIONS(169),
    [anon_sym_FFF] = ACTIONS(167),
    [anon_sym_UF] = ACTIONS(169),
    [anon_sym_SSF] = ACTIONS(167),
    [anon_sym_UFFF] = ACTIONS(167),
    [anon_sym_Int] = ACTIONS(167),
    [anon_sym_Real] = ACTIONS(167),
    [sym_bool_type] = ACTIONS(167),
    [sym_void_type] = ACTIONS(167),
    [anon_sym_CC] = ACTIONS(169),
    [anon_sym_CCC] = ACTIONS(167),
    [anon_sym_MM] = ACTIONS(169),
    [anon_sym_MMM] = ACTIONS(167),
    [anon_sym_PP] = ACTIONS(169),
    [anon_sym_PPP] = ACTIONS(167),
    [anon_sym_AA] = ACTIONS(169),
    [anon_sym_AAA] = ACTIONS(167),
    [sym_function_pointer_type] = ACTIONS(167),
    [anon_sym_LBRACK] = ACTIONS(167),
    [anon_sym_SQUOTE] = ACTIONS(167),
    [anon_sym_DQUOTE] = ACTIONS(167),
    [anon_sym_BQUOTE] = ACTIONS(167),
    [sym_comment] = ACTIONS(3),
  },
  [23] = {
    [ts_builtin_sym_end] = ACTIONS(171),
    [sym_boolean_literal] = ACTIONS(171),
    [sym_numeric_literal] = ACTIONS(171),
    [anon_sym_U] = ACTIONS(173),
    [anon_sym_UU] = ACTIONS(173),
    [anon_sym_UUU] = ACTIONS(171),
    [anon_sym_S] = ACTIONS(173),
    [anon_sym_SS] = ACTIONS(173),
    [anon_sym_SSS] = ACTIONS(171),
    [anon_sym_F] = ACTIONS(173),
    [anon_sym_FF] = ACTIONS(173),
    [anon_sym_FFF] = ACTIONS(171),
    [anon_sym_UF] = ACTIONS(173),
    [anon_sym_SSF] = ACTIONS(171),
    [anon_sym_UFFF] = ACTIONS(171),
    [anon_sym_Int] = ACTIONS(171),
    [anon_sym_Real] = ACTIONS(171),
    [sym_bool_type] = ACTIONS(171),
    [sym_void_type] = ACTIONS(171),
    [anon_sym_CC] = ACTIONS(173),
    [anon_sym_CCC] = ACTIONS(171),
    [anon_sym_MM] = ACTIONS(173),
    [anon_sym_MMM] = ACTIONS(171),
    [anon_sym_PP] = ACTIONS(173),
    [anon_sym_PPP] = ACTIONS(171),
    [anon_sym_AA] = ACTIONS(173),
    [anon_sym_AAA] = ACTIONS(171),
    [sym_function_pointer_type] = ACTIONS(171),
    [anon_sym_LBRACK] = ACTIONS(171),
    [anon_sym_SQUOTE] = ACTIONS(171),
    [anon_sym_DQUOTE] = ACTIONS(171),
    [anon_sym_BQUOTE] = ACTIONS(171),
    [sym_comment] = ACTIONS(3),
  },
  [24] = {
    [ts_builtin_sym_end] = ACTIONS(175),
    [sym_boolean_literal] = ACTIONS(175),
    [sym_numeric_literal] = ACTIONS(175),
    [anon_sym_U] = ACTIONS(177),
    [anon_sym_UU] = ACTIONS(177),
    [anon_sym_UUU] = ACTIONS(175),
    [anon_sym_S] = ACTIONS(177),
    [anon_sym_SS] = ACTIONS(177),
    [anon_sym_SSS] = ACTIONS(175),
    [anon_sym_F] = ACTIONS(177),
    [anon_sym_FF] = ACTIONS(177),
    [anon_sym_FFF] = ACTIONS(175),
    [anon_sym_UF] = ACTIONS(177),
    [anon_sym_SSF] = ACTIONS(175),
    [anon_sym_UFFF] = ACTIONS(175),
    [anon_sym_Int] = ACTIONS(175),
    [anon_sym_Real] = ACTIONS(175),
    [sym_bool_type] = ACTIONS(175),
    [sym_void_type] = ACTIONS(175),
    [anon_sym_CC] = ACTIONS(177),
    [anon_sym_CCC] = ACTIONS(175),
    [anon_sym_MM] = ACTIONS(177),
    [anon_sym_MMM] = ACTIONS(175),
    [anon_sym_PP] = ACTIONS(177),
    [anon_sym_PPP] = ACTIONS(175),
    [anon_sym_AA] = ACTIONS(177),
    [anon_sym_AAA] = ACTIONS(175),
    [sym_function_pointer_type] = ACTIONS(175),
    [anon_sym_LBRACK] = ACTIONS(175),
    [anon_sym_SQUOTE] = ACTIONS(175),
    [anon_sym_DQUOTE] = ACTIONS(175),
    [anon_sym_BQUOTE] = ACTIONS(175),
    [sym_comment] = ACTIONS(3),
  },
  [25] = {
    [ts_builtin_sym_end] = ACTIONS(179),
    [sym_boolean_literal] = ACTIONS(179),
    [sym_numeric_literal] = ACTIONS(179),
    [anon_sym_U] = ACTIONS(181),
    [anon_sym_UU] = ACTIONS(181),
    [anon_sym_UUU] = ACTIONS(179),
    [anon_sym_S] = ACTIONS(181),
    [anon_sym_SS] = ACTIONS(181),
    [anon_sym_SSS] = ACTIONS(179),
    [anon_sym_F] = ACTIONS(181),
    [anon_sym_FF] = ACTIONS(181),
    [anon_sym_FFF] = ACTIONS(179),
    [anon_sym_UF] = ACTIONS(181),
    [anon_sym_SSF] = ACTIONS(179),
    [anon_sym_UFFF] = ACTIONS(179),
    [anon_sym_Int] = ACTIONS(179),
    [anon_sym_Real] = ACTIONS(179),
    [sym_bool_type] = ACTIONS(179),
    [sym_void_type] = ACTIONS(179),
    [anon_sym_CC] = ACTIONS(181),
    [anon_sym_CCC] = ACTIONS(179),
    [anon_sym_MM] = ACTIONS(181),
    [anon_sym_MMM] = ACTIONS(179),
    [anon_sym_PP] = ACTIONS(181),
    [anon_sym_PPP] = ACTIONS(179),
    [anon_sym_AA] = ACTIONS(181),
    [anon_sym_AAA] = ACTIONS(179),
    [sym_function_pointer_type] = ACTIONS(179),
    [anon_sym_LBRACK] = ACTIONS(179),
    [anon_sym_SQUOTE] = ACTIONS(179),
    [anon_sym_DQUOTE] = ACTIONS(179),
    [anon_sym_BQUOTE] = ACTIONS(179),
    [sym_comment] = ACTIONS(3),
  },
  [26] = {
    [ts_builtin_sym_end] = ACTIONS(183),
    [sym_boolean_literal] = ACTIONS(183),
    [sym_numeric_literal] = ACTIONS(183),
    [anon_sym_U] = ACTIONS(185),
    [anon_sym_UU] = ACTIONS(185),
    [anon_sym_UUU] = ACTIONS(183),
    [anon_sym_S] = ACTIONS(185),
    [anon_sym_SS] = ACTIONS(185),
    [anon_sym_SSS] = ACTIONS(183),
    [anon_sym_F] = ACTIONS(185),
    [anon_sym_FF] = ACTIONS(185),
    [anon_sym_FFF] = ACTIONS(183),
    [anon_sym_UF] = ACTIONS(185),
    [anon_sym_SSF] = ACTIONS(183),
    [anon_sym_UFFF] = ACTIONS(183),
    [anon_sym_Int] = ACTIONS(183),
    [anon_sym_Real] = ACTIONS(183),
    [sym_bool_type] = ACTIONS(183),
    [sym_void_type] = ACTIONS(183),
    [anon_sym_CC] = ACTIONS(185),
    [anon_sym_CCC] = ACTIONS(183),
    [anon_sym_MM] = ACTIONS(185),
    [anon_sym_MMM] = ACTIONS(183),
    [anon_sym_PP] = ACTIONS(185),
    [anon_sym_PPP] = ACTIONS(183),
    [anon_sym_AA] = ACTIONS(185),
    [anon_sym_AAA] = ACTIONS(183),
    [sym_function_pointer_type] = ACTIONS(183),
    [anon_sym_LBRACK] = ACTIONS(183),
    [anon_sym_SQUOTE] = ACTIONS(183),
    [anon_sym_DQUOTE] = ACTIONS(183),
    [anon_sym_BQUOTE] = ACTIONS(183),
    [sym_comment] = ACTIONS(3),
  },
  [27] = {
    [ts_builtin_sym_end] = ACTIONS(187),
    [sym_boolean_literal] = ACTIONS(187),
    [sym_numeric_literal] = ACTIONS(187),
    [anon_sym_U] = ACTIONS(189),
    [anon_sym_UU] = ACTIONS(189),
    [anon_sym_UUU] = ACTIONS(187),
    [anon_sym_S] = ACTIONS(189),
    [anon_sym_SS] = ACTIONS(189),
    [anon_sym_SSS] = ACTIONS(187),
    [anon_sym_F] = ACTIONS(189),
    [anon_sym_FF] = ACTIONS(189),
    [anon_sym_FFF] = ACTIONS(187),
    [anon_sym_UF] = ACTIONS(189),
    [anon_sym_SSF] = ACTIONS(187),
    [anon_sym_UFFF] = ACTIONS(187),
    [anon_sym_Int] = ACTIONS(187),
    [anon_sym_Real] = ACTIONS(187),
    [sym_bool_type] = ACTIONS(187),
    [sym_void_type] = ACTIONS(187),
    [anon_sym_CC] = ACTIONS(189),
    [anon_sym_CCC] = ACTIONS(187),
    [anon_sym_MM] = ACTIONS(189),
    [anon_sym_MMM] = ACTIONS(187),
    [anon_sym_PP] = ACTIONS(189),
    [anon_sym_PPP] = ACTIONS(187),
    [anon_sym_AA] = ACTIONS(189),
    [anon_sym_AAA] = ACTIONS(187),
    [sym_function_pointer_type] = ACTIONS(187),
    [anon_sym_LBRACK] = ACTIONS(187),
    [anon_sym_SQUOTE] = ACTIONS(187),
    [anon_sym_DQUOTE] = ACTIONS(187),
    [anon_sym_BQUOTE] = ACTIONS(187),
    [sym_comment] = ACTIONS(3),
  },
  [28] = {
    [ts_builtin_sym_end] = ACTIONS(191),
    [sym_boolean_literal] = ACTIONS(191),
    [sym_numeric_literal] = ACTIONS(191),
    [anon_sym_U] = ACTIONS(193),
    [anon_sym_UU] = ACTIONS(193),
    [anon_sym_UUU] = ACTIONS(191),
    [anon_sym_S] = ACTIONS(193),
    [anon_sym_SS] = ACTIONS(193),
    [anon_sym_SSS] = ACTIONS(191),
    [anon_sym_F] = ACTIONS(193),
    [anon_sym_FF] = ACTIONS(193),
    [anon_sym_FFF] = ACTIONS(191),
    [anon_sym_UF] = ACTIONS(193),
    [anon_sym_SSF] = ACTIONS(191),
    [anon_sym_UFFF] = ACTIONS(191),
    [anon_sym_Int] = ACTIONS(191),
    [anon_sym_Real] = ACTIONS(191),
    [sym_bool_type] = ACTIONS(191),
    [sym_void_type] = ACTIONS(191),
    [anon_sym_CC] = ACTIONS(193),
    [anon_sym_CCC] = ACTIONS(191),
    [anon_sym_MM] = ACTIONS(193),
    [anon_sym_MMM] = ACTIONS(191),
    [anon_sym_PP] = ACTIONS(193),
    [anon_sym_PPP] = ACTIONS(191),
    [anon_sym_AA] = ACTIONS(193),
    [anon_sym_AAA] = ACTIONS(191),
    [sym_function_pointer_type] = ACTIONS(191),
    [anon_sym_LBRACK] = ACTIONS(191),
    [anon_sym_SQUOTE] = ACTIONS(191),
    [anon_sym_DQUOTE] = ACTIONS(191),
    [anon_sym_BQUOTE] = ACTIONS(191),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(195), 1,
      anon_sym_BQUOTE,
    ACTIONS(197), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(199), 1,
      sym_escape_sequence,
    ACTIONS(201), 1,
      sym_comment,
    STATE(35), 1,
      aux_sym_backtick_quoted_string_repeat1,
  [16] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_DQUOTE,
    ACTIONS(205), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(207), 1,
      sym_escape_sequence,
    STATE(33), 1,
      aux_sym_double_quoted_string_repeat1,
  [32] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(211), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(213), 1,
      sym_escape_sequence,
    STATE(32), 1,
      aux_sym_single_quoted_string_repeat1,
  [48] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(215), 1,
      anon_sym_SQUOTE,
    ACTIONS(217), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(220), 1,
      sym_escape_sequence,
    STATE(32), 1,
      aux_sym_single_quoted_string_repeat1,
  [64] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(223), 1,
      anon_sym_DQUOTE,
    ACTIONS(225), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(228), 1,
      sym_escape_sequence,
    STATE(33), 1,
      aux_sym_double_quoted_string_repeat1,
  [80] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(231), 1,
      anon_sym_SQUOTE,
    ACTIONS(233), 1,
      aux_sym_single_quoted_string_token1,
    ACTIONS(235), 1,
      sym_escape_sequence,
    STATE(31), 1,
      aux_sym_single_quoted_string_repeat1,
  [96] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(237), 1,
      anon_sym_BQUOTE,
    ACTIONS(239), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(242), 1,
      sym_escape_sequence,
    STATE(35), 1,
      aux_sym_backtick_quoted_string_repeat1,
  [112] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(245), 1,
      anon_sym_DQUOTE,
    ACTIONS(247), 1,
      aux_sym_double_quoted_string_token1,
    ACTIONS(249), 1,
      sym_escape_sequence,
    STATE(30), 1,
      aux_sym_double_quoted_string_repeat1,
  [128] = 5,
    ACTIONS(201), 1,
      sym_comment,
    ACTIONS(251), 1,
      anon_sym_BQUOTE,
    ACTIONS(253), 1,
      aux_sym_backtick_quoted_string_token1,
    ACTIONS(255), 1,
      sym_escape_sequence,
    STATE(29), 1,
      aux_sym_backtick_quoted_string_repeat1,
  [144] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(257), 1,
      aux_sym_typed_element_array_type_token1,
  [151] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(259), 1,
      ts_builtin_sym_end,
  [158] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(261), 1,
      anon_sym_RBRACK,
  [165] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(263), 1,
      anon_sym_RBRACK,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(29)] = 0,
  [SMALL_STATE(30)] = 16,
  [SMALL_STATE(31)] = 32,
  [SMALL_STATE(32)] = 48,
  [SMALL_STATE(33)] = 64,
  [SMALL_STATE(34)] = 80,
  [SMALL_STATE(35)] = 96,
  [SMALL_STATE(36)] = 112,
  [SMALL_STATE(37)] = 128,
  [SMALL_STATE(38)] = 144,
  [SMALL_STATE(39)] = 151,
  [SMALL_STATE(40)] = 158,
  [SMALL_STATE(41)] = 165,
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
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
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
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_type, 1, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_type, 1, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unit_fractional_type, 1, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unit_fractional_type, 1, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fixed_point_type, 1, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fixed_point_type, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_numeric_constant_type, 1, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_numeric_constant_type, 1, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scalar_type, 1, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scalar_type, 1, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pointer_type, 1, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pointer_type, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_address_type, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_address_type, 1, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantity_type, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quantity_type, 1, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_type, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array_type, 1, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typed_element_array_type, 4, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typed_element_array_type, 4, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_typed_element_array_type, 3, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_typed_element_array_type, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 1, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 1, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_backtick_quoted_string, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_backtick_quoted_string, 3, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pointer_addressable_array_type, 3, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pointer_addressable_array_type, 3, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector_type, 2, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_vector_type, 2, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_backtick_quoted_string, 2, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_backtick_quoted_string, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0),
  [217] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [220] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_single_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0),
  [225] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [228] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0),
  [239] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [242] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_backtick_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [251] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [259] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
