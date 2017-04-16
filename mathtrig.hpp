#ifndef MATHTRIG_HPP
#define MATHTRIG_HPP

// Returns the coefficients in the taylor expansion of sin x up to term x^(2N+1)
std::vector<double> sinCoeff(const int N, const double x);

// Returns the coefficients in the Taylor expansion of cos x up to term x^(2N)
std::vector<double> cosCoeff(const int N, const double x);

// Calculates the sum of the first N terms in the Taylor expansion of sin x
double sinTaylor(const int N, const double x);

// Calculates the sum of the first N terms in the Taylor expansion of cos x
double cosTaylor(const int N, const double x);

// Returns the (N+1)-term in the taylor series of śin x, i.e. the coefficient x^(2N+3)
double sinBounded(const int N, const double x);

// Returns the (N+1)-term in the taylor series of cos x
double cosBounded(const int N, const double x);

#endif // MATHTRIG_HPP
