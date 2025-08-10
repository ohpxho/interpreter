

#ifndef SCANNER_H
#defined SCANNER_H

include "./token_type.h";

typedef struct {


} as Scanner

void scanToken();
char advance();
void addToken(TokenType token);
void addToken(TokenType token, void *literal);


#endif
