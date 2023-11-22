#include <cmath>
#include "Poly.h"

Poly::Poly(double constant) {
    if (constant != 0) {
        terms[0] = constant;
    }
}

Poly::Poly(int exp, double coef) {
    if (coef != 0) {
        terms[exp] = coef;
    }
}

Poly Poly::operator+(const Poly& other) const {
    Poly result = *this;
    for (const auto& term : other.terms) {
        result[term.first] += term.second;
        if (result[term.first] == 0) {
            result.terms.erase(term.first);
        }
    }
    return result;
}

Poly Poly::operator+(double constant) const {
    //~ Poly result = *this;
    //~ result[0] += constant;
    //~ if (result[0] == 0) {
        //~ result.terms.erase(0);
    //~ }
    //~ return result;
    return *this + Poly(constant);
}

Poly operator+(double constant, const Poly& poly) {
    return poly + constant;
}

Poly Poly::operator-(const Poly& other) const {
    //~ Poly result = *this;
    //~ for (const auto& term : other.terms) {
        //~ result[term.first] -= term.second;
        //~ if (result[term.first] == 0) {
            //~ result.terms.erase(term.first);
        //~ }
    //~ }
    //~ return result;
    
    return *this + (-other);
}

Poly Poly::operator-(double constant) const {
	return *this + (-constant);
    //~ Poly result = *this;
    //~ result[0] -= constant;
    //~ if (result[0] == 0) {
        //~ result.terms.erase(0);
    //~ }
    //~ return result;
}

Poly operator-(double constant, const Poly& poly) {
    //~ Poly result;
    //~ result[0] = constant;
    //~ return result - poly;
    
    return constant + (-poly);
}

Poly Poly::operator-() const {
    Poly result = *this;
    for (auto& term : result.terms) {
        term.second = -term.second;
    }
    return result;
}

Poly Poly::operator*(const Poly& other) const {
    Poly result;
    for (const auto& term1 : terms) {
        for (const auto& term2 : other.terms) {
            int exp = term1.first + term2.first;
            double coef = term1.second * term2.second;
            result[exp] += coef;
            if (result[exp] == 0) {
                result.terms.erase(exp);
            }
        }
    }
    return result;
}

Poly Poly::operator*(double constant) const {
    //~ Poly result = *this;
    //~ for (auto& term : result.terms) {
        //~ term.second *= constant;
        //~ if (term.second == 0) {
            //~ result.terms.erase(term.first);
        //~ }
    //~ }
    //~ return result;
    
    return *this * Poly(constant);
}

Poly operator*(double constant, const Poly& poly) {
    return poly * constant;
}

double Poly::operator()(double x) const {
    double result = 0;
    for (const auto& term : terms) {
        result += term.second * pow(x, term.first);
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Poly& poly) {
    bool firstTerm = true;
    for (const auto& term : poly.terms) {
        if (!firstTerm && term.second > 0) {
            os << " + ";
        }
        if (term.second < 0) {
            os << " - ";
        }
        if (abs(term.second) != 1 || term.first == 0) {
            os << abs(term.second);
        }
        if (term.first > 0) {
            os << "x";
            if (term.first > 1) {
                os << "^" << term.first;
            }
        }
        firstTerm = false;
    }
    if (poly.terms.empty()) {
        os << "0";
    }
    return os;
}

double& Poly::operator[](int exp) {
    return terms[exp];
}
