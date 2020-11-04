#include "calculationresult.h"

using boost::multiprecision::cpp_int;

CalculationResult::CalculationResult(cpp_int number, bool is_correct_calculation, QString message) :
                                     number_(number),
                                     is_correct_calculation_(is_correct_calculation),
                                     message_(message){}

cpp_int CalculationResult::GetNumber() const {
    return number_;
}

bool CalculationResult::IsCorrectCalculation() const {
    return  is_correct_calculation_;
}

QString CalculationResult::GetMessage() const {
    return message_;
}

CalculationResult CalculationResult::operator+(const CalculationResult& right) const {
    CalculationResult result(0);
    if(this->IsCorrectCalculation() and right.IsCorrectCalculation()){
        result = CalculationResult(this->GetNumber()+right.GetNumber());
    }else if(!this->IsCorrectCalculation() and !right.IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage() + "\n" + right.GetMessage());
    }else if(!this->IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage());
    }else{
        result = CalculationResult(0, false, right.GetMessage());
    }
    return result;
}

CalculationResult CalculationResult::operator-(const CalculationResult& right) const {
    CalculationResult result(0);
    if(this->IsCorrectCalculation() and right.IsCorrectCalculation()){
        result = CalculationResult(this->GetNumber()-right.GetNumber());
    }else if(!this->IsCorrectCalculation() and !right.IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage() + "\n" + right.GetMessage());
    }else if(!this->IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage());
    }else{
        result = CalculationResult(0, false, right.GetMessage());
    }
    return result;
}

CalculationResult CalculationResult::operator*(const CalculationResult& right) const {
    CalculationResult result(0);
    if(this->IsCorrectCalculation() and right.IsCorrectCalculation()){
        result = CalculationResult(this->GetNumber()*right.GetNumber());
    }else if(!this->IsCorrectCalculation() and !right.IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage() + "\n" + right.GetMessage());
    }else if(!this->IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage());
    }else{
        result = CalculationResult(0, false, right.GetMessage());
    }
    return result;
}

CalculationResult CalculationResult::operator/(const CalculationResult& right) const {
    CalculationResult result(0);
    if(this->IsCorrectCalculation() and right.IsCorrectCalculation()){
        if(right.GetNumber() != 0){
            result = CalculationResult(this->GetNumber()/right.GetNumber());
        }else{
            result = CalculationResult(0, false, "Division by zero!");
        }
    }else if(!this->IsCorrectCalculation() and !right.IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage() + "\n" + right.GetMessage());
    }else if(!this->IsCorrectCalculation()){
        result = CalculationResult(0, false, this->GetMessage());
    }else{
        result = CalculationResult(0, false, right.GetMessage());
    }
    return result;
}

CalculationResult& CalculationResult::operator++(){
    ++number_;
    return *this;
}

CalculationResult& CalculationResult::operator--(){
    --number_;
    return *this;
}

CalculationResult CalculationResult::operator-(){
    return CalculationResult(-this->GetNumber());
}

CalculationResult CalculationResult::operator+(){
    return CalculationResult(this->GetNumber());
}
