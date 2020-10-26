#include "parser.h"
#include <utility>
#include <exception>

#include "lexer.h"

#include "node.h"
#include "binaryoperatornode.h"
#include "binaryplusnode.h"
#include "binaryminusnode.h"
#include "binarymultiplynode.h"
#include "binarydividenode.h"
#include "binarypowernode.h"
#include "unaryoperatornode.h"
#include "unaryplusnode.h"
#include "unaryminusnode.h"
#include "functionnode.h"
#include "incfunctionnode.h"
#include "decfunctionnode.h"
#include "numbernode.h"
#include "cellreferencenode.h"

QSharedPointer<Node> Parser::GetTree(const QString& text){
    int pos = 0;
    QVector<Token> tokens = Lexer::GetTokens(text);
    return ExpressionParse(tokens, pos);
}

QSharedPointer<Node> Parser::ExpressionParse(const QVector<Token>& tokens, int& pos){
    QSharedPointer<Node> result;
    QSharedPointer<Node> left_expr = MultiplicationParse(tokens, pos);
    if(pos+1 < tokens.size() and tokens[pos+1].GetTokenType() == TokenType::kOperator1){
        ++pos;
        QString operator_value = tokens[pos] .GetValue();
        QSharedPointer<Node> right_expr = ExpressionParse(tokens, ++pos);
        if(operator_value == "+"){
            result = QSharedPointer<Node>(new BinaryPlusNode(left_expr, right_expr));
        }else if(operator_value == "-"){
            result = QSharedPointer<Node>(new BinaryMinusNode(left_expr, right_expr));
        }else{
            throw std::invalid_argument("Incorrect expression!");
        }
    }else{
        result = left_expr;
    }
    return result;
}

QSharedPointer<Node> Parser::MultiplicationParse(const QVector<Token>& tokens, int& pos){
    QSharedPointer<Node> result;
    QSharedPointer<Node> left_expr = PowerParse(tokens, pos);
    if(pos+1 < tokens.size() and tokens[pos+1].GetTokenType() == TokenType::kOperator2){
        ++pos;
        QString operator_value = tokens[pos] .GetValue();
        QSharedPointer<Node> right_expr = MultiplicationParse(tokens, ++pos);
        if(operator_value == "*"){
            result = QSharedPointer<Node>(new BinaryMultiplyNode(left_expr, right_expr));
        }else if(operator_value == "/"){
            result = QSharedPointer<Node>(new BinaryDivideNode(left_expr, right_expr));
        }else{
            throw std::invalid_argument("Incorrect expression!");
        }
    }else{
        result = left_expr;
    }
    return result;
}

QSharedPointer<Node> Parser::PowerParse(const QVector<Token>& tokens, int& pos){
    QSharedPointer<Node> result;
    QSharedPointer<Node> left_expr = TermParse(tokens, pos);
    if(pos+1 < tokens.size() and tokens[pos+1].GetTokenType() == TokenType::kOperator3){
        ++pos;
        QString operator_value = tokens[pos].GetValue();
        QSharedPointer<Node> right_expr = PowerParse(tokens, ++pos);
        if(operator_value == "^"){
            result = QSharedPointer<Node>(new BinaryPowerNode(left_expr, right_expr));
        }else{
            throw std::invalid_argument("Incorrect expression!");
        }
    }else{
        result = left_expr;
    }
    return result;
}

QSharedPointer<Node> Parser::TermParse(const QVector<Token>& tokens, int& pos){
    QSharedPointer<Node> result;
    if(pos < tokens.size() and tokens[pos].GetTokenType() == TokenType::kNumber){
        result = QSharedPointer<Node>(new NumberNode(tokens[pos].GetValue()));
    }else if(pos < tokens.size() and tokens[pos].GetTokenType() == TokenType::kCellReference){
        result = QSharedPointer<Node>(new CellReferenceNode(tokens[pos].GetValue()));
    }else if(pos < tokens.size() and tokens[pos].GetTokenType() == TokenType::kOperator1){
        QString operator_value = tokens[pos].GetValue();
        QSharedPointer<Node> expr = TermParse(tokens, ++pos);
        if(operator_value == "+"){
            result = QSharedPointer<Node>(new UnaryPlusNode(expr));
        }else if(operator_value == "-"){
            result = QSharedPointer<Node>(new UnaryMinusNode(expr));
        }else{
            throw std::invalid_argument("Incorrect expression!");
        }
    }else if(pos < tokens.size() and tokens[pos].GetTokenType() == TokenType::kInc){
        QSharedPointer<Node> expr = ExpressionWithBracketsParse(tokens, ++pos);
        result = QSharedPointer<Node>(new IncFunctionNode(expr));
    }else if(pos < tokens.size() and tokens[pos].GetTokenType() == TokenType::kDec){
        QSharedPointer<Node> expr = ExpressionWithBracketsParse(tokens, ++pos);
        result = QSharedPointer<Node>(new DecFunctionNode(expr));
    }else{
        result = ExpressionWithBracketsParse(tokens, pos);
    }
    return result;
}

QSharedPointer<Node> Parser::ExpressionWithBracketsParse(const QVector<Token>& tokens, int& pos){
    QSharedPointer<Node> result;
    if(pos < tokens.size() and tokens[pos].GetTokenType() == TokenType::kLeftBracket){
        result = ExpressionParse(tokens, ++pos);
        if(tokens[++pos].GetTokenType() != TokenType::kRightBracket){
            throw std::invalid_argument("Incorrect expression!");
        }
    }else{
        throw std::invalid_argument("Incorrect expression!");
    }
    return result;
}
