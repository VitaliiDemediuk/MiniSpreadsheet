#include "test_lexer.h"
#include "lexer.h"

void Test_Lexer::SimpleTest(){
    QCOMPARE(Lexer::GetTokens("2+2"),
             QVector<Token>(
                 {Token(TokenType::kNumber, "2"),
                  Token(TokenType::kOperator1, "+"),
                  Token(TokenType::kNumber, "2")})
             );
}

void Test_Lexer::BigExpressionTest(){
    QCOMPARE(Lexer::GetTokens("-2^41*(412^B5^3/1)+inc(2)+3+dec(2323*2)-2321+A2"),
             QVector<Token>(
                 {
                    Token(TokenType::kOperator1, "-"),
                    Token(TokenType::kNumber, "2"),
                    Token(TokenType::kOperator3, "^"),
                    Token(TokenType::kNumber, "41"),
                    Token(TokenType::kOperator2, "*"),
                    Token(TokenType::kLeftBracket, "("),
                    Token(TokenType::kNumber, "412"),
                    Token(TokenType::kOperator3, "^"),
                    Token(TokenType::kCellReference, "B5"),
                    Token(TokenType::kOperator3, "^"),
                    Token(TokenType::kNumber, "3"),
                    Token(TokenType::kOperator2, "/"),
                    Token(TokenType::kNumber, "1"),
                    Token(TokenType::kRightBracket, ")"),
                    Token(TokenType::kOperator1, "+"),
                    Token(TokenType::kInc, "inc"),
                    Token(TokenType::kLeftBracket, "("),
                    Token(TokenType::kNumber, "2"),
                    Token(TokenType::kRightBracket, ")"),
                    Token(TokenType::kOperator1, "+"),
                    Token(TokenType::kNumber, "3"),
                    Token(TokenType::kOperator1, "+"),
                    Token(TokenType::kDec, "dec"),
                    Token(TokenType::kLeftBracket, "("),
                    Token(TokenType::kNumber, "2323"),
                    Token(TokenType::kOperator2, "*"),
                    Token(TokenType::kNumber, "2"),
                    Token(TokenType::kRightBracket, ")"),
                    Token(TokenType::kOperator1, "-"),
                    Token(TokenType::kNumber, "2321"),
                    Token(TokenType::kOperator1, "+"),
                    Token(TokenType::kCellReference, "A2")})
             );
}


void Test_Lexer::ALotOfSpaceTest(){
    QCOMPARE(Lexer::GetTokens("  -  23 + 2         /     8*  A3 ^ 3"),
             QVector<Token>(
                 {
                    Token(TokenType::kOperator1, "-"),
                    Token(TokenType::kNumber, "23"),
                    Token(TokenType::kOperator1, "+"),
                    Token(TokenType::kNumber, "2"),
                    Token(TokenType::kOperator2, "/"),
                    Token(TokenType::kNumber, "8"),
                    Token(TokenType::kOperator2, "*"),
                    Token(TokenType::kCellReference, "A3"),
                    Token(TokenType::kOperator3, "^"),
                    Token(TokenType::kNumber, "3"),})
             );
}

void Test_Lexer::InvalidToken(){
    QCOMPARE(Lexer::GetTokens("2qwe+2"),
             QVector<Token>(
                 {Token(TokenType::kInvalidToken, "")})
             );
}
