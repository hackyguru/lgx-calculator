#ifndef CALCULATOR_IMPL_H
#define CALCULATOR_IMPL_H

// Universal module — public API uses only standard C++ types
// (std::string, double, bool, void). All Qt usage is hidden in the
// .cpp behind a private pimpl, so logos-cpp-generator can parse this
// header to emit the QML/IPC glue.

#include <string>

class CalculatorImpl {
public:
    CalculatorImpl();
    ~CalculatorImpl();

    // Calculates the result of an arithmetic expression.
    std::string calculate(const std::string& input);
    // Returns the last calculated result.
    std::string lastCalculation();

private:
    class Private;
    Private* d;
};

#endif // CALCULATOR_IMPL_H
