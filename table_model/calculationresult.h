#ifndef CALCULATIONRESULT_H
#define CALCULATIONRESULT_H

#include <boost/multiprecision/cpp_int.hpp>
#include <QString>

class CalculationResult{
public:
    CalculationResult(boost::multiprecision::cpp_int number,
                      bool is_correct_calculation = true,
                      QString message = "");
    boost::multiprecision::cpp_int GetNumber() const;
    bool IsCorrectCalculation() const;
    QString GetMessage() const;
    CalculationResult operator+(const CalculationResult& right) const;
    CalculationResult operator-(const CalculationResult& right) const;
    CalculationResult operator*(const CalculationResult& right) const;
    CalculationResult operator/(const CalculationResult& right) const;
    CalculationResult& operator++();
    CalculationResult& operator--();
    CalculationResult operator-();
    CalculationResult operator+();
private:
    boost::multiprecision::cpp_int number_;
    bool is_correct_calculation_;
    QString message_;
};

#endif // CALCULATIONRESULT_H
