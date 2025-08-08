#include <"../include/token_type.h">

typedef struct {
  TokenType type;
  char *lexeme;
  void *literal;
  int line;
} Token;

char *token_to_string(Token token) {
  if (token == NULL)
    return "";
  return token->type + " " + token->lexeme + " " + token->literal;
}
