#ifndef RPN_CALCULATOR_BASE
#define RPN_CALCULATOR_BASE

#include <vector>

namespace Bob
{
    enum RpnCalculator_Status : uint16_t {
        STATUS_NORMAL,
        STATUS_STACK_OVERFLOW,
        STATUS_NO_ENOUGH_ARGS,
        STATUS_NUMBER_OVERFLOW,
        STATUS_OP_UNKNOWN
    };

    template<typename T, typename OP>
    class RpnCalculatorBase {
    public:
        void init() {
            stack.clear();
        }

        RpnCalculator_Status pushNumber(T element) {
            if (false) {
                return STATUS_STACK_OVERFLOW;
            } else {
                stack.emplace_back(element);
                return STATUS_NORMAL;
            }
        }

        virtual RpnCalculator_Status operate(OP operatorType) = 0;

        RpnCalculator_Status swapXY() {
            if (stack.size() < 2) {
                return STATUS_NO_ENOUGH_ARGS;
            } else {
                T y = stack.at(stack.size() - 2);
                stack.erase(stack.begin() + (stack.size() - 2));
                stack.emplace_back(y);
                return STATUS_NORMAL;
            }
        }

        RpnCalculator_Status tryGetY(T& result) const {
            if (stack.size() < 2) {
                return STATUS_NO_ENOUGH_ARGS;
            } else {
                result = stack.at(stack.size() - 2);
                return STATUS_NORMAL;
            }
        }

        RpnCalculator_Status tryGetX(T& result) const {
            if (stack.size() < 1) {
                return STATUS_NO_ENOUGH_ARGS;
            } else {
                result = stack.back();
                return STATUS_NORMAL;
            }
        }
    
    protected:
        bool canBinaryOperate() const {
            return stack.size() >= 2;
        }

        T pop() {
            T result = stack.back();
            stack.pop_back();
            return result;
        }

    protected:
        std::vector<T> stack;
    };

}
#endif