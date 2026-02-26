#ifndef PARSER_H
#define PARSER_H

#include "stdbool.h"
#include "token.h"
#include "token_type.h"

/*
 *
expression     → literal
               | unary
               | binary
               | grouping ;

literal        → NUMBER | STRING | "true" | "false" | "nil" ;
grouping       → "(" expression ")" ;
unary          → ( "-" | "!" ) expression ;
binary         → expression operator expression ;
operator       → "==" | "!=" | "<" | "<=" | ">" | ">="
               | "+"  | "-"  | "*" | "/" ;
 *
 * */

typedef enum {
  EXPR,
  LITERAL,
  GROUPING,
  UNARY,
  BINARY,
  OPERATOR
} GrammarRuleType;

typedef struct {
  GrammarRuleType type;
  Token *token;
} ASTNode;

typedef struct {
  ASTNode *root;
  ASTNode children[];
} ASTTree;

void expr(Token *token);
void literal(Token *token);
void grouping(Token *token);
void binary(Token *token);
void unary(Token *token);
void op(Token *token);

#endif // PARSER_H
