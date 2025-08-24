#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include "../lib/ut/utarray.h"

typedef struct {
  char *source;
  UT_array *tokens; 
} Scanner;

UT_array *scanTokens(Scanner *scanner);
void scanToken(Scanner *scanner);
char advance(Scanner *scanner);
void addToken(Scanner *scanner, TokenType type);
void addTokenLiteral(Scanner *scanner, TokenType type, void *literal);
bool isAtEnd(Scanner *scanner);
char *substring(char *src, char *desc, int start, int end);
bool match(Scanner *scanner, char *expected);
bool isDigit(char c);
char peek(scanner);
char peekNext(scanner);
void string(Scanner *scanner);
void number(Scanner *scanner);


#endif
