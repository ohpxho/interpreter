#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include "../lib/ut/utarray.h"
#include "token.h"

typedef struct {
  char *source;
  UT_array *tokens; 
} Scanner;

void scanTokens(Scanner *scanner);
void scanToken(Scanner *scanner);
char advance(Scanner *scanner);
void addToken(Scanner *scanner, TokenType type);
void addTokenLiteral(Scanner *scanner, TokenType type, void *literal);
bool isAtEnd(Scanner *scanner);
char *substring(char *src, int start, int end);
bool match(Scanner *scanner, char *expected);
bool isDigit(char c);
bool isAlpha(char c);
bool isAlphaNumeric(char c);
char peek(Scanner *scanner);
char peekNext(Scanner *scanner);
void string(Scanner *scanner);
void number(Scanner *scanner);
void keyword(Scanner *scanner);


#endif
