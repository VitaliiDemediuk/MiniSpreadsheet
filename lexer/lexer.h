#ifndef LEXER_H
#define LEXER_H

#include <QVector>
#include "token.h"

class Lexer
{
public:
    static QVector<Token> GetTokens(const QString& line);
    Lexer() = delete;
private:
    static TokenType GetTokenType(const QString& token_value);
    static bool IsWhitespace(const QChar& ch);
    static bool IsOperator(const QChar& ch);
    static bool IsBracket(const QChar& ch);
};

#endif // LEXER_H
