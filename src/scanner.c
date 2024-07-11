#include "tree_sitter/parser.h"
#include <wctype.h>

enum TokenType {
  INDENT,
  DEDENT,
};

bool tree_sitter_nesfab_external_scanner_scan(void *payload, TSLexer *lexer,
                                              const bool *valid_symbols) {
  bool found_indent = false;
  bool found_dedent = false;

  if (valid_symbols[INDENT] || valid_symbols[DEDENT]) {
    while (iswspace(lexer->lookahead)) {
      if (lexer->lookahead == '\n') {
        lexer->advance(lexer, true);
        while (iswspace(lexer->lookahead)) {
          if (lexer->lookahead == ' ') {
            found_indent = true;
          } else if (lexer->lookahead == '\t') {
            found_indent = true;
          }
          lexer->advance(lexer, false);
        }
        if (valid_symbols[INDENT] && found_indent) {
          lexer->result_symbol = INDENT;
          return true;
        } else if (valid_symbols[DEDENT]) {
          lexer->result_symbol = DEDENT;
          return true;
        }
      } else {
        lexer->advance(lexer, true);
      }
    }
  }

  return false;
}

unsigned tree_sitter_nesfab_external_scanner_serialize(void *payload,
                                                       char *buffer) {
  return 0;
}

void tree_sitter_nesfab_external_scanner_deserialize(void *payload,
                                                     const char *buffer,
                                                     unsigned length) {}

void *tree_sitter_nesfab_external_scanner_create() { return NULL; }

void tree_sitter_nesfab_external_scanner_destroy(void *payload) {}
