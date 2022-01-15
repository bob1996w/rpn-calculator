#ifndef MY_RPN_CALCULATOR
#define MY_RPN_CALCULATOR

#include "RpnCalculatorBase.hpp"

namespace Bob
{
    enum MyRpnCalculator_OP : uint16_t {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        SQUARE,
        SQUARE_ROOT,
        POWER
    };

    class MyRpnCalculator : public RpnCalculatorBase<double, MyRpnCalculator_OP> {
    public:
        RpnCalculator_Status operate(MyRpnCalculator_OP operatorType) override {
            switch(operatorType) {
                case PLUS: {
                    if (!canBinaryOperate()) {
                        return STATUS_NO_ENOUGH_ARGS;
                    }   
                    double x, y;
                    y = pop();
                    x = pop();
                    x = x + y;
                    return pushNumber(x);
                }
                case MINUS: {
                    if (!canBinaryOperate()) {
                        return STATUS_NO_ENOUGH_ARGS;
                    }   
                    double x, y;
                    y = pop();
                    x = pop();
                    x = x - y;
                    return pushNumber(x);
                }
                case MULTIPLY: {
                    if (!canBinaryOperate()) {
                        return STATUS_NO_ENOUGH_ARGS;
                    }   
                    double x, y;
                    y = pop();
                    x = pop();
                    x = x * y;
                    return pushNumber(x);
                }
                case DIVIDE: {
                    if (!canBinaryOperate()) {
                        return STATUS_NO_ENOUGH_ARGS;
                    }   
                    double x, y;
                    y = pop();
                    x = pop();
                    x = x / y;
                    return pushNumber(x);
                }
                default: {
                    return STATUS_OP_UNKNOWN;
                }
            }
        }
    };
}

#endif