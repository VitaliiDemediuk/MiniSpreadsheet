#ifndef TOKEN_H
#define TOKEN_H

#include <QString>

enum class TokenType{
    kNumber = 0,
    kCellReference,
    kInc,
    kDec,
    kOperator1,
    kOperator2,
    kOperator3,
    kLeftBracket,
    kRightBracket,
    kInvalidToken
};

class Token
{
public:
    explicit Token(TokenType type, QString value);
    TokenType GetTokenType() const;
    const QString& GetValue() const;
    bool operator== (const Token& right) const;
private:
    TokenType token_type_;
    QString value_;
};

#endif // TOKEN_H
