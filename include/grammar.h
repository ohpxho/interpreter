#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "token.h"
#include "token_type.h"
#include "stdbool.h"

/*
 *expression     → literal
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

typedef struct {
  union {
    Literal *literal;
    Unary *unary;
    Binary *binary;
    Grouping *grouping;
  } value
} Expression;

typedef struct {
  TokenType type;
  bool isLiteral(TokenType type);
  void interpret();
} Literal;

typedef struct {

} Grouping;

typedef struct {

} Binary;

typedef struct {

} Unary;

typedef struct {

} Operator;

