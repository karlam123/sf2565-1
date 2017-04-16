#include <vector>
#include "horner.hpp"

double horner(const std::vector<double> &coeff, const double x)
{
    double b = *(coeff.rbegin());
    for (auto i = coeff.rbegin()+1; i != coeff.rend(); ++i) {
        b = b*x+ *i;
    }
    return b;
}
