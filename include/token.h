
#ifndef TOKEN_H
#define TOKEN_H

#include "token_type.h"

typedef struct {
  TokenType type;
  char *lexeme;
  void *literal;
  int line;
} Token;

char *tokenToString(Token *token);

#endif

