#include "token.h"
#include <utility>

Token::Token(TokenType token_type, QString value) :
                    token_type_(token_type),
                    value_(token_type == TokenType::kInvalidToken ? "" : std::move(value)){}

TokenType Token::GetTokenType() const{
    return token_type_;
}

const QString& Token::GetValue() const{
    return value_;
}

bool Token::operator== (const Token& right) const{
    return (this->token_type_ == right.token_type_ and this->value_ == right.value_);
}
