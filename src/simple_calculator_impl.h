#ifndef SIMPLE_CALCULATOR_IMPL_H
#define SIMPLE_CALCULATOR_IMPL_H

// Universal module — public API uses only standard C++ types
// (std::string, double, bool, void). All Qt usage is hidden in the
// .cpp behind a private pimpl, so logos-cpp-generator can parse this
// header to emit the QML/IPC glue.

#include <cstdint>
#include <string>

class SimpleCalculatorImpl {
public:
    SimpleCalculatorImpl();
    ~SimpleCalculatorImpl();

    // Adds two numbers and stores the result.
    double add(double a, double b);
    // Subtracts the second number from the first and stores the result.
    double subtract(double a, double b);
    // Multiplies two numbers and stores the result.
    double multiply(double a, double b);
    // Divides the first number by the second and stores the result. Returns 0 if divisor is 0.
    double divide(double a, double b);

private:
    class Private;
    Private* d;
};

#endif // SIMPLE_CALCULATOR_IMPL_H
