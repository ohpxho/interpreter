#include "../include/token.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *tokenToString(Token *token) {
  if (token == NULL) return "\0";
  
  size_t len =  0;

  if(token->literal->type == TL_STRING) {
    len = snprintf(NULL, 0, "token: %d\nlexeme: %s\nliteral: %s\nline: %d\n", token->type, token->lexeme, token->literal->value.s, token->line);
  } else if(token->literal->type == TL_DOUBLE) {
    len = snprintf(NULL, 0, "token: %d\nlexeme: %s\nliteral: %f\nline: %d\n", token->type, token->lexeme, token->literal->value.d, token->line);
  } else {
    len = snprintf(NULL, 0, "token: %d\nlexeme: %s\nline: %d\n", token->type, token->lexeme, token->line);
  }

  char *str = malloc(len + 1); // +1 for null terminator
  if (str == NULL) {
      return NULL;
  }

  if(token->literal->type == TL_STRING) {
    sprintf(str, "token: %d\nlexeme: %s\nliteral: %s\nline: %d\n", token->type, token->lexeme, token->literal->value.s, token->line);
  } else if(token->literal->type == TL_DOUBLE) {
    sprintf(str, "token: %d\nlexeme: %s\nliteral: %f\nline: %d\n", token->type, token->lexeme, token->literal->value.d, token->line);
  } else {
    sprintf(str, "token: %d\nlexeme: %s\nline: %d\n", token->type, token->lexeme, token->line);
  }
  return str;

}
