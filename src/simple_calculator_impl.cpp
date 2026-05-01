#include "simple_calculator_impl.h"


// Private impl — holds ALL state (Qt-typed and std-typed alike)
// so the public header stays pure C++. Method bodies access these
// uniformly via d->m_<name>.
class SimpleCalculatorImpl::Private {
public:
    double m_lastResult{ 0.0 };
};

SimpleCalculatorImpl::SimpleCalculatorImpl()
    : d(new Private())
{}

SimpleCalculatorImpl::~SimpleCalculatorImpl() {
    delete d;
}

double SimpleCalculatorImpl::add(double a, double b)
{
    // Adds two numbers and stores the result.
    d->m_lastResult = a + b; return d->m_lastResult;
}

double SimpleCalculatorImpl::subtract(double a, double b)
{
    // Subtracts the second number from the first and stores the result.
    d->m_lastResult = a - b; return d->m_lastResult;
}

double SimpleCalculatorImpl::multiply(double a, double b)
{
    // Multiplies two numbers and stores the result.
    d->m_lastResult = a * b; return d->m_lastResult;
}

double SimpleCalculatorImpl::divide(double a, double b)
{
    // Divides the first number by the second and stores the result. Returns 0 if divisor is 0.
    if (b == 0) return 0.0; d->m_lastResult = a / b; return d->m_lastResult;
}
