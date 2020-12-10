#ifndef TEST_CELL_GETVISIBLETEXT_H
#define TEST_CELL_GETVISIBLETEXT_H

#include <QObject>
#include <QTest>

class Test_Cell_GetVisibleText : public QObject {
    Q_OBJECT
public:
    Test_Cell_GetVisibleText() = default;

private slots:
    void SimpleTest();
    void BigExpressionTest();
    void ALotOfSpaceTest();
    void InvalidExpression();
};

#endif // TEST_CELL_GETVISIBLETEXT_H
