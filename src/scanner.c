#include <stdlib.h>
#include <string.h>
#include "../include/scanner.h"
#include "../include/token.h"

int start = 0;
int current = 0;
int line = 1;

UT_array *scanTokens(Scanner *scanner) {
  while (!isAtEnd(scanner)) {
    start = current;
    scanToken(scanner);  
  } 
  
  Token *token = malloc(sizeof(Token));
  token->type = TKN_EOF;
  token->lexeme  = "";
  token->literal = NULL;
  token->line = line;
}

void scanToken(Scanner *scanner) {
  char c = advance(scanner);
  switch(c) {
    case '(': addToken(scanner, LEFT_PAREN); break;
    case ')': addToken(scanner, RIGHT_PAREN); break;
    case '{': addToken(scanner, LEFT_BRACE); break;
    case '}': addToken(scanner, RIGHT_BRACE); break;
    case ',': addToken(scanner, COMMA); break;
    case '.': addToken(scanner, DOT); break;
    case '-': addToken(scanner, MINUS); break;
    case '+': addToken(scanner, PLUS); break;
    case ';': addToken(scanner, SEMICOLON); break;
    case '/': addToken(scanner, SLASH); break;
    case '*': addToken(scanner, STAR); break;
    default:
      pferror("Unexpected character");
      break;
  }
}

char advance(Scanner *scanner) {
  return scanner->source[current++];
}

void addToken(Scanner *scanner, TokenType type) {
  addTokenLitral(scanner, type, NULL);
}

void addTokenLiteral(Scanner *scanner, TokenType type, void *literal) {
  char *substr = substring(scanner->source, start, current);
  Token *token = malloc(sizeof(Token)); 
  token->type = type;
  token->lexeme = substr;
  utarray_push_back(scanner->tokens, &token);
}

bool isAtEnd(Scanner *scanner) {
  int len = strlen(scanner->source);
  return current >= len;
}

char *substring(char *src, int start, int end) {
  if (!src) {
    return NULL;
  }

  int len = strlen(src); 

  if (start < 0 || end < 0 || start > end || start >= len || end >= len) {
    return NULL;
  }

  int substrLen = (end - start) + 1; // +1 for null terminator 
  char *substr = (char*)malloc(substrLen + 1); 
  
  if (!substr) {
    perror("Malloc Failed!");
    return NULL;
  }
  
  strncpy(substr, src, substrLen);

  return substr;
}
