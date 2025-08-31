#include "../include/token.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *tokenToString(Token *token) {
  if (token == NULL) return "\0";
  size_t len = snprintf(NULL, 0, "%d %s %s", token->type, token->lexeme, token->literal);
  char *str = malloc(len + 1); // +1 for null terminator
  if (str == NULL) {
      return NULL;
  }
  sprintf(str, "%d %s %s", token->type, token->lexeme, token->literal);
  return str;
}
