#include "../include/scanner.h"
#include "../include/token.h"
#include "../lib/ut/uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int start = 0;
int current = 0;
int line = 1;

void scanTokens(Scanner *scanner) {
  while (!isAtEnd(scanner)) {
    start = current;
    scanToken(scanner);
  }

  addToken(scanner, TKN_EOF);
}

void scanToken(Scanner *scanner) {
  char c = advance(scanner);
  switch (c) {
  case '(':
    addToken(scanner, LEFT_PAREN);
    break;
  case ')':
    addToken(scanner, RIGHT_PAREN);
    break;
  case '{':
    addToken(scanner, LEFT_BRACE);
    break;
  case '}':
    addToken(scanner, RIGHT_BRACE);
    break;
  case ',':
    addToken(scanner, COMMA);
    break;
  case '.':
    addToken(scanner, DOT);
    break;
  case '-':
    addToken(scanner, MINUS);
    break;
  case '+':
    addToken(scanner, PLUS);
    break;
  case ';':
    addToken(scanner, SEMICOLON);
    break;
  case '/':
    if (peek(scanner) == '/') {
      while (peek(scanner) != '\n' && !isAtEnd(scanner))
        current++;
    } else {
      addToken(scanner, SLASH);
    }
    break;
  case '*':
    addToken(scanner, STAR);
    break;
  case '!':
    if (match(scanner, '=')) {
      addToken(scanner, BANG_EQUAL);
    } else {
      addToken(scanner, BANG);
    }
    break;
  case '=':
    if (match(scanner, '=')) {
      addToken(scanner, EQUAL_EQUAL);
    } else {
      addToken(scanner, EQUAL);
    }
    break;
  case '>':
    if (match(scanner, '=')) {
      addToken(scanner, GREATER_EQUAL);
    } else {
      addToken(scanner, GREATER);
    }
    break;
  case '<':
    if (match(scanner, '=')) {
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
  case '"':
    string(scanner);
    break;
  default:
    if (isDigit(c)) {
      number(scanner);
    } else if (isAlpha(c)) {
      keyword(scanner);
    } else {
    }
    break;
  }
}

char advance(Scanner *scanner) { return scanner->source[current++]; }

void addToken(Scanner *scanner, TokenType type) {
  TokenLiteral *literal = malloc(sizeof(TokenLiteral));
  *literal = (TokenLiteral){
    .type = TL_NULL
  };
  addTokenLiteral(scanner, type, literal);
}

void addTokenLiteral(Scanner *scanner, TokenType type, TokenLiteral *literal) {
  char *substr = NULL;
  
  if(type != TKN_EOF) {
    substr = substring(scanner->source, start, current-1);
  } 

  Token token = {
      .type = type, .lexeme = substr, .literal = literal, .line = line};
  utarray_push_back(scanner->tokens, &token);
}

bool isAtEnd(Scanner *scanner) {
  int len = strlen(scanner->source);
  return current >= len;
}

char *substring(const char *src, int start, int end) {
  if (!src) {
    return NULL;
  }

  int len = strlen(src);

  if (start < 0 || end < 0 || start > end || start >= len || end >= len) {
    return NULL;
  }

  int substrLen = (end - start) + 1; // +1 for null terminator
  char *substr = (char *)malloc(substrLen + 1);

  if (!substr) {
    printf("%s", "Malloc Failed");
    return NULL;
  }

  strncpy(substr, src + start, substrLen);

  return substr;
}

void string(Scanner *scanner) {
  while (peek(scanner) != '"' && !isAtEnd(scanner)) {
    if (peek(scanner) == '\n')
      line++;
    advance(scanner);
  }

  if (isAtEnd(scanner)) {
    printf("%s", "String unterminated\n");
    return;
  }

  advance(scanner);
  
  char *substr = substring(scanner->source, start+1, current - 2);
  
  TokenLiteral *literal = malloc(sizeof(TokenLiteral));

  *literal = (TokenLiteral){
    .value.s = substr,
    .type = TL_STRING
  };

  addTokenLiteral(scanner, STRING, literal);
}

void number(Scanner *scanner) {
  while (isDigit(peek(scanner))) {
    advance(scanner);
  }

  if (scanner->source[current] == '.' && isDigit(peekNext(scanner))) {
    while (isDigit(peek(scanner))) {
      advance(scanner);
    }
  }
  char *substr = substring(scanner->source, start, current-1);
  double n = strtod(substr, NULL);

  TokenLiteral *literal = malloc(sizeof(TokenLiteral)); 
  *literal = (TokenLiteral){
    .value.d = n,
    .type = TL_DOUBLE
  };

  addTokenLiteral(scanner, NUMBER, literal);
}

void keyword(Scanner *scanner) {
  while (isAlphaNumeric(peek(scanner)) && !isAtEnd(scanner)) {
    advance(scanner);
  };

  TokenType type;
  char *substr = substring(scanner->source, start, current - 1);

  if (strcmp(substr, "and") == 0) {
    type = AND;
  } else if (strcmp(substr, "class") == 0) {
    type = CLASS;
  } else if (strcmp(substr, "else") == 0) {
    type = ELSE;
  } else if (strcmp(substr, "false") == 0) {
    type = FALSE;
  } else if (strcmp(substr, "fun") == 0) {
    type = FUN;
  } else if (strcmp(substr, "for") == 0) {
    type = FOR;
  } else if (strcmp(substr, "if") == 0) {
    type = IF;
  } else if (strcmp(substr, "nil") == 0) {
    type = NIL;
  } else if (strcmp(substr, "or") == 0) {
    type = OR;
  } else if (strcmp(substr, "print") == 0) {
    type = PRINT;
  } else if (strcmp(substr, "return") == 0) {
    type = RETURN;
  } else if (strcmp(substr, "super") == 0) {
    type = SUPER;
  } else if (strcmp(substr, "this") == 0) {
    type = THIS;
  } else if (strcmp(substr, "true") == 0) {
    type = TRUE;
  } else if (strcmp(substr, "var") == 0) {
    type = VAR;
  } else if (strcmp(substr, "while") == 0) {
    type = WHILE;
  } else {
    type = IDENTIFIER;
  }

  addToken(scanner, type);
}

bool isAlphaNumeric(char c) { return isDigit(c) || isAlpha(c); }

bool isAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '-');
}

bool isDigit(char c) { return c >= '0' && c <= '9'; }

bool match(Scanner *scanner, char expected) {
  if (isAtEnd(scanner))
    return false;
  if (!(scanner->source[current] == expected))
    return false;

  current++;
  return true;
}

char peek(Scanner *scanner) {
  if (isAtEnd(scanner))
    return '\0';
  return scanner->source[current];
}

char peekNext(Scanner *scanner) {
  if (isAtEnd(scanner))
    return '\0';
  return scanner->source[current + 1];
}
