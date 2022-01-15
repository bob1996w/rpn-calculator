#include <iostream>
#include "MyRpnCalculator.hpp"

int main() {
    Bob::MyRpnCalculator calc;
    calc.pushNumber(5);
    calc.pushNumber(10);
    calc.operate(Bob::PLUS);
    double res;
    Bob::RpnCalculator_Status status = calc.tryGetX(res);
    std::cout << (int)status << " " << res << "\n";
    return 0;
}