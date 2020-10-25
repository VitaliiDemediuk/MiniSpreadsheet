#include "binarypowernode.h"

BinaryPowerNode::BinaryPowerNode(QSharedPointer<Node> left_expr,
                                 QSharedPointer<Node> right_expr):
                                 BinaryOperatorNode(left_expr, right_expr) {}

cpp_int BinaryPowerNode::Calculate() const{
    return bin_pow(left_expr_->Calculate(), right_expr_->Calculate());
}

cpp_int BinaryPowerNode::bin_pow(const cpp_int& base, const cpp_int& index) const{
    if(index == 0){
        return 1;
    } else if(index == 1){
        return base;
    }else if(index % 2 == 0){
        return bin_pow(base, index/2);
    }else{
        return base*bin_pow(base, index-1);
    }
}
