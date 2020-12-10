#ifndef TEST_LEXER_H
#define TEST_LEXER_H

#include <QObject>
#include <QTest>

class Test_Lexer : public QObject {
    Q_OBJECT
public:
    Test_Lexer() = default;

private slots:
    void SimpleTest();
    void BigExpressionTest();
    void ALotOfSpaceTest();
    void InvalidToken();
};

#endif // TEST_LEXER_H
