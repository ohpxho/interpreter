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
    case '/': 
      if(peek(scanner) == '/') {
        while(peek(scanner) != '\n' && !isAtEnd(scanner)) current++;
      } else {
        addToken(scanner, SLASH);
      }
      break;
    case '*': addToken(scanner, STAR); break;
    case '!': 
      if(match(scanner, '=')) {
        addToken(scanner, BANG_EQUAL) 
      } else { 
        addToken(scanner, BANG);
      }
      break;
    case '=': 
      if(match(scanner, '=') {
        addToken(scanner, EQUAL_EQUAL);
      } else {
        addToken(scanner, EQUAL);
      }
      break;
    case '>': 
      if(match(scanner, '=')) {
        addToken(scanner, GREATER_EQUAL);
      }
      else {
        addToken(scanner, GREATER);
      }
      break;
    case '<': 
      if(match(scanner, '=')) {
        addToken(scanner, LESS_EQUAL);
      } else {
        addToken(scanner, LESS);
      }
      break;
    case ' ':
    case '\t':
    case '\r':
      break;
    case '\n':
      line++;
      break;
    case '"': string(); break;
    default:
      if(isDigit(c)) {
        number(scanner);
      } else {
        pferror("Unexpected character");
      }
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

void string(Scanner *scanner) {
  int strt = current;
  while(peek(scanner) != '"' && !isAtEnd(scanner)) {
    if(peek(scanner) == '\n') line++;
    advance(scanner);
  }
  
  if(isAtEnd(scanner)) {
    perror("String unterminated!");
    return;
  }

  advance(scanner);

  char *substr = substring(scanner->source, strt, current-1);
  addTokenLitral(scanner, STRING, substr);
}

void number(Scanner *scanner) {
  int start = current-1;
  while(isDigit(peek(scanner))) {
    advance(scanner);
  }
  
  if(scanner->source[current] == '.' && isDigit(peekNext(scanner))) {
    while(isDigit(peek(scanner))) {
      advance(scanner);
    }
  }
  char *end;
  char *substr = substring(scanner, start, current-1);
  double n = strtod(substr, &end);

  addTokenLiteral(scanner, NUMBER,  n);
}

bool isDigit(char c) {
  return c >= '0' or c <= '9'; 
}

bool match(Scanner *scanner, char *expected) {
  if(isAtEnd(scanner)) return false;
  if(!scanner->source[current] == expected) return false;

  current++;
  return true;
}

char peek(Scanner *scanner) {
  if(isAtEnd(scanner)) return '\0';
  return scanner->source[current];
}

char peekNext(Scanner *scanner) {
  if(isAtEnd(scanner)) return '\0';
  return scanner->source[current+1];
}
