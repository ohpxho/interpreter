
#ifndef TOKEN_H
#define TOKEN_H

#include "token_type.h"

typedef enum {
  TL_NULL, TL_INTEGER, TL_DOUBLE, TL_STRING
} TokenLiteralType;

typedef struct {
  union {
    char *s;
    double d;
    int i;
  } value;
  TokenLiteralType type;
} TokenLiteral;

typedef struct {
  TokenType type;
  char *lexeme;
  TokenLiteral *literal; 
  int line;
} Token;

char *tokenToString(Token *token);

#endif

