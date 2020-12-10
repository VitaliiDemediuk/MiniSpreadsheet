#include "test_cell_getvalue.h"
#include <calculationresult.h>
#include "cell.h"

void Test_Cell_GetValue::SimpleTest(){
    Cell new_cell;
    new_cell.ChangeText("2+2");
    QCOMPARE(new_cell.GetValue(), CalculationResult(2, true));
}

void Test_Cell_GetValue::BigExpressionTest(){
    Cell new_cell;
    new_cell.ChangeText("((2^8)*((412^(B5^3)/1))+inc(2)+3+dec(2323*2)-2321+A2");
    QCOMPARE(new_cell.GetValue(), CalculationResult(2586, true));
}


void Test_Cell_GetValue::ALotOfSpaceTest(){
    Cell new_cell;
    new_cell.ChangeText("  -  23 + 2         /     8*  A3 ^ 3");
    QCOMPARE(new_cell.GetValue(), CalculationResult(-23, true));
}

void Test_Cell_GetValue::InvalidExpression(){
    Cell new_cell;
    new_cell.ChangeText("2+2)+r");
    QCOMPARE(new_cell.GetValue(), CalculationResult(0, false));
}
