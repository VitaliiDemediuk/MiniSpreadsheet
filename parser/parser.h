#ifndef PARSER_H
#define PARSER_H

#include "node.h"
#include "token.h"
#include <QSharedPointer>
#include <QVector>


class Parser{
public:
    Parser() = delete;
    static QSharedPointer<Node> GetTree(const QString& text);
private:
    static QSharedPointer<Node> ExpressionParse(const QVector<Token>& tokens, int& pos);

    static QSharedPointer<Node> MultiplicationParse(const QVector<Token>& tokens, int& pos);

    static QSharedPointer<Node> PowerParse(const QVector<Token>& tokens, int& pos);

    static QSharedPointer<Node> TermParse(const QVector<Token>& tokens, int& pos);

    static QSharedPointer<Node> ExpressionWithBracketsParse(const QVector<Token>& tokens, int& pos);

};

#endif // PARSER_H
