#include "calculator_impl.h"

// Qt headers auto-detected from method bodies / state.
#include <QString>
#include <QStringList>

// Private impl — holds ALL state (Qt-typed and std-typed alike)
// so the public header stays pure C++. Method bodies access these
// uniformly via d->m_<name>.
class CalculatorImpl::Private {
public:
    QString m_lastResult{ QStringLiteral("0") };
};

CalculatorImpl::CalculatorImpl()
    : d(new Private())
{}

CalculatorImpl::~CalculatorImpl() {
    delete d;
}

std::string CalculatorImpl::calculate(const std::string& input)
{
    // Calculates the result of an arithmetic expression.
    try {
        double result = std::stod(QString::fromStdString(input).toUtf8().constData());
        d->m_lastResult = QString::number(result, 'f', 2);
        return d->m_lastResult.toStdString();
    } catch (std::exception& e) {
        return "Error";
    }
}

std::string CalculatorImpl::lastCalculation()
{
    // Returns the last calculated result.
    return d->m_lastResult.toStdString();
}
