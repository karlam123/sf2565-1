#include <vector>
#include "horner.hpp"
#include "mathtrig.hpp"

// Returns the coefficients in the taylor expansion of sin x up to term x^(2N-1)
std::vector<double> sinCoeff(const int N, const double x) {
    std::vector<double> coeff(2*N, 0);
    coeff[1]=x;
    for(int i=3; i < 2*N; i+=2) {
        coeff[i] = -x*x*coeff[i-2]/(i*(i-1));
    }
    return coeff;
}

// Returns the coefficients in the Taylor expansion of cos x up to term x^(2N-1)
// Note that the last coefficient is 0
std::vector<double> cosCoeff(const int N, const double x) {
    std::vector<double> coeff(2*N, 0);
    coeff[0]=1;
    for (int i=2; i < 2*N; i+=2) {
        coeff[i] = -x*x*coeff[i-2]/(i*(i-1));
    }
    return coeff;
}

// Calculates the sum of the first N terms in the Taylor expansion of sin x
double sinTaylor(const int N, const double x) {
    return horner(sinCoeff(N,x), 1);
}

// Calculates the sum of the first N terms in the Taylor expansion of cos x
double cosTaylor(const int N, const double x) {
    return horner(cosCoeff(N,x), 1);
}

// Returns the (N+1)-term in the taylor series of śin x, i.e. the coefficient x^(2N+3)
double sinBounded(const int N, const double x) {
    const std::vector<double> coeff = sinCoeff(N+1,x);
    return *(coeff.end()-1);
}

// Returns the (N+1)-term in the taylor series of cos x
double cosBounded(const int N, const double x) {
    const std::vector<double> coeff = cosCoeff(N+1,x);
    return *(coeff.end()-2);  // Last coefficient zero
}
