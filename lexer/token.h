#ifndef TOKEN_H
#define TOKEN_H

#include <QString>

enum class TokenType{
    kNumber = 0,
    kCellLink,
    kInc,
    kDec,
    kOperator,
    kLeftBracket,
    kRightBracket
};

class Token
{
public:
    explicit Token(TokenType type, QString value);
    TokenType GetTokenType() const;
    const QString& GetValue() const;
private:
    TokenType token_type_;
    QString value_;
};

#endif // TOKEN_H
