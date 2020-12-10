#include "test_cell_getvisibletext.h"
#include "cell.h"

void Test_Cell_GetVisibleText::SimpleTest(){
    Cell new_cell;
    new_cell.ChangeText("2+2");
    QCOMPARE(new_cell.GetVisibleText(),"4");
}

void Test_Cell_GetVisibleText::BigExpressionTest(){
    Cell new_cell;
    new_cell.ChangeText("((2^8)*((412^(B5^3)/1))+inc(2)+3+dec(2323*2)-2321+A2");
    QCOMPARE(new_cell.GetVisibleText(),"2586");
}


void Test_Cell_GetVisibleText::ALotOfSpaceTest(){
    Cell new_cell;
    new_cell.ChangeText("  -  23 + 2         /     8*  A3 ^ 3");
    QCOMPARE(new_cell.GetVisibleText(),"-23");
}

void Test_Cell_GetVisibleText::InvalidExpression(){
    Cell new_cell;
    new_cell.ChangeText("2+2)+r");
    QCOMPARE(new_cell.GetVisibleText(),"#####");
}
