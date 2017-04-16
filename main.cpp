#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "horner.hpp"
#include "mathtrig.hpp"
#include "asi.hpp"
using namespace std;

void comparing();
double fun(double x);

int main()
{
    comparing();
    return 0;
}


void comparing() {

    //Task 1
    cout << "***************** Task 1 ***********************" << endl;
    const int xs[6] = {-1,1,2,3,5,10};
    const int Ns[4] = {5, 10, 20, 40};
    cout << scientific;
    // Compare sin with sinTaylor
    cout << "************* sin ************" << endl << endl;
    for (int N : Ns) {
        cout << "************* N=" << N << " *************" << endl;
        for (int x : xs) {
            cout << x << "     " << abs(sin(x)-sinTaylor(N, x)) << "     " << abs(sinBounded(N, x)) << endl;
        }
        cout << "*******************************" << endl;
    }
    // Compare cos with cosTaylor
    cout << endl;
    cout << "************* cos ************" << endl << endl;
    for (int N : Ns) {
        cout << "************* N=" << N << " *************" << endl;
        for (int x : xs) {
            cout << x << "     " << abs(cos(x)-cosTaylor(N, x)) << "     " << abs(cosBounded(N, x)) << endl;
        }
        cout << "*******************************" << endl;
    }

    // Task 2
    cout << "****************** Task 2 ***********************" << endl;
    double tolerance[3] = {1e-2, 1e-3, 1e-4};
    cout << "Tolerance                   I(f)" << endl;
    cout << "*************************************************" << endl;
    cout << setprecision(8);
    for (double tol : tolerance) {
        cout << tol << "        " << ASI(fun, -1, 1, tol) << endl;
    }
}

double fun(double x) {
    return 1+sin(exp(3*x));
}
