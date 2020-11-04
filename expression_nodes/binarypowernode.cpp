#include "binarypowernode.h"

BinaryPowerNode::BinaryPowerNode(QSharedPointer<Node> left_expr,
                                 QSharedPointer<Node> right_expr):
                                 BinaryOperatorNode(left_expr, right_expr) {}

CalculationResult BinaryPowerNode::Calculate() const{
    return bin_pow(left_expr_->Calculate(), right_expr_->Calculate());
}

CalculationResult BinaryPowerNode::bin_pow(const CalculationResult& base, const CalculationResult& index) const{
    if(index.GetNumber() < 0){
        return CalculationResult(0, false, "Incorrect expression!");
    } else if(index.GetNumber() == 0){
        return CalculationResult(1);
    } else if(index.GetNumber() == 1){
        return base;
    } else if(index.GetNumber() % 2 == 0){
        return sqrt(bin_pow(base, index/CalculationResult(2)));
    } else{
        return base*bin_pow(base, index-CalculationResult(1));
    }
}

CalculationResult BinaryPowerNode::sqrt(const CalculationResult& base) const{
    return base*base;
}
