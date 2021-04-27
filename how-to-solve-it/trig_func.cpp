// C++ LIBRARIES
#include <iostream>
#include <iomanip>

/*
  sin(x) = x/1! - x^3/3! + x^5/5! - x^7/7! + ...
*/
double sin(double x) {

    double result = 0.0, eps = 1e-9;
    int index  = 1, sign = 1;

    while (true) {
        double term  = 1;
        for (int i = 1; i <= index; i++) {
            term = term * (x / i);
        }

        if (term < eps) {
            break;
        }

        result += sign * term;
        index += 2;
        sign *= -1;
    }

    return result;
}


/*
  cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
*/
double cos(double x) {

    double result = 0.0, eps = 1e-9;
    int index  = 1, sign = 1;

    while (true) {
        double term  = 1;
        for (int i = 1; i < index; i++) {
            term = term * (x / i);
        }

        if (term < eps) {
            break;
        }

        result += sign * term;
        index += 2;
        sign *= -1;
    }

    return result;
}

    
int main(void) {
    printf("sin(x) = %lf\n", sin(5));
    printf("cos(x) = %lf\n", cos(5));
}
