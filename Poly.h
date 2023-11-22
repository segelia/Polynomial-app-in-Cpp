#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <map>

class Poly {
public:
    Poly() = default;
    Poly(double constant);

    Poly(int exp, double coef);

    Poly operator+(const Poly& other) const;
    Poly operator+(double constant) const;
    friend Poly operator+(double constant, const Poly& poly);

    Poly operator-(const Poly& other) const;
    Poly operator-(double constant) const;
    friend Poly operator-(double constant, const Poly& poly);
    Poly operator-() const;

    Poly operator*(const Poly& other) const;
    Poly operator*(double constant) const;
    friend Poly operator*(double constant, const Poly& poly);

    double operator()(double x) const;

    friend std::ostream& operator<<(std::ostream& os, const Poly& poly);

    double& operator[](int exp);

private:

	// Zamiast mapy można trzymać dwa wektory: współczynnik i wykładnik.
	// coeff: 		1 2 5 -1
	// exponents:	0 1 2 5 => 1 + 2x + 5x^2 - x^5
	
    std::map<int, double> terms;
};

#endif // POLY_H
