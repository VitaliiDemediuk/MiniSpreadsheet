#include "token.h"
#include <utility>

Token::Token(TokenType token_type, QString value) :
                    token_type_(token_type), value_(std::move(value)){}

TokenType Token::GetTokenType() const{
    return token_type_;
}

const QString& Token::GetValue() const{
    return value_;
}
