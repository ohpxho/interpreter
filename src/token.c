#define "../include/token.h"

char *tokenToString(Token token) {
  if (token == NULL)
    return "";
  return token->type + " " + token->lexeme + " " + token->literal;
}
