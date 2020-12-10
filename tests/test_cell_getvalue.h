#ifndef TEST_CELL_GETVALUE_H
#define TEST_CELL_GETVALUE_H

#include <QObject>
#include <QTest>

class Test_Cell_GetValue : public QObject {
    Q_OBJECT
public:
    Test_Cell_GetValue() = default;

private slots:
    void SimpleTest();
    void BigExpressionTest();
    void ALotOfSpaceTest();
    void InvalidExpression();
};

#endif // TEST_CELL_GETVALUE_H
