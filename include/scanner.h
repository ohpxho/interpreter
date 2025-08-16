

#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include "./token_type.h"
#include "../lib/ut/utarray.h"

typedef struct {
  char *source;
  UT_array *tokens; 
} Scanner;

UT_array scanToken(Scanner *scanner);
char advance(Scanner *scanner);
void addToken(Scanner *scanner, TokenType type);
void addTokenLiteral(Scanner *scanner, TokenType type, void *literal);
bool isAtEnd(Scanner *scanner);


#endif
