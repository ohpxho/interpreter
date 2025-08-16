#define "../include/token.h"

char *token_to_string(Token token) {
  if (token == NULL)
    return "";
  return token->type + " " + token->lexeme + " " + token->literal;
}
