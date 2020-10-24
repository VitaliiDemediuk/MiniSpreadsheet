#include "lexer.h"
#include <QRegExp>
#include <QSet>
#include <utility>
#include <exception>

QVector<Token> Lexer::GetTokens(const QString& line){
    QVector<Token> tokens;
    QString token_value;
    for(const QChar& ch : line){
        if(IsWhitespace(ch) or IsBracket(ch) or IsOperator(ch)){
            if(!token_value.isEmpty()){
                TokenType token_type = GetTokenType(token_value);
                tokens.append(Token(token_type,
                              std::move(token_value)));
            }
            if(ch == '('){
                tokens.append(Token(TokenType::kLeftBracket, ch));
            }else if(ch == ')'){
                tokens.append(Token(TokenType::kRightBracket, ch));
            }else if(IsOperator(ch)){
                tokens.append(Token(TokenType::kOperator, ch));
            }

        }else{
            token_value.append(ch);
        }
    }
    if(!token_value.isEmpty()){
        TokenType token_type = GetTokenType(token_value);
        tokens.append(Token(token_type,
                      std::move(token_value)));
    }
    return tokens;
}

TokenType Lexer::GetTokenType(const QString& token_value){
    static const QRegExp cell_link_reg_exp("[A-Z]+[1-9][0-9]*");
    static const QRegExp number_reg_exp("[1-9][0-9]*");
    if(token_value == "inc"){
        return TokenType::kInc;
    }else if(token_value == "dec"){
        return TokenType::kDec;
    }else if(cell_link_reg_exp.exactMatch(token_value)){
        return TokenType::kCellLink;
    }else if(number_reg_exp.exactMatch(token_value)){
        return TokenType::kNumber;
    }else{
        throw std::invalid_argument(token_value.toStdString() +
                                    " incorrect token!");
    }
}

bool Lexer::IsWhitespace(const QChar& ch){
    static const QSet<QChar> whitespaces_set{' ', '\t', '\n'};
    return whitespaces_set.contains(ch);
}

bool Lexer::IsOperator(const QChar& ch){
    static const QSet<QChar> operators_set{'+', '-', '*', '/', '^'};
    return operators_set.contains(ch);
}

bool Lexer::IsBracket(const QChar& ch){
    return ch == '(' or ch == ')';
}
