#include "../include/scanner.h"
#include "../include/token.h"

int start = 0;
int current = 0;
int line = 1;

UT_array scanToken(Scanner *scanner) {
  char c = advance(scanner);
  switch(c) {
  }
}

char advance(Scanner *scanner) {
  return scanner->source[current++];
}

void addToken(Scanner *scanner, TokenType type) {
  addTokenLitral(scanner, type, NULL);
}

void addTokenLiteral(Scanner *scanner, TokenType type, void *literal) {

}

bool isAtEnd(Scanner *scanner) {
  
}
