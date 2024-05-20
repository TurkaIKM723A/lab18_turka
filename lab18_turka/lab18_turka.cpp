#include <iostream>

using namespace std;

class Fraction {

private:

    int numerator; // це чисельник
    int denominator; // це знаменник

public:

    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {

        if (denom == 0) {

            throw invalid_argument("Denominator cannot be zero");
        }
    }

    Fraction operator+(const Fraction& other) const {

        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;

        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {

        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;

        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {

        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;

        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {

        if (other.numerator == 0) {

            throw invalid_argument("Division by zero");
        }

        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;

        return Fraction(num, denom);
    }

    bool operator<(const Fraction& other) const {

        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {

        return numerator * other.denominator > other.numerator * denominator;
    }

    void print() const {

        cout << numerator << "/" << denominator;
    }
};

int main() {

    Fraction f1(1, 2); // 1/2
    Fraction f2(3, 4); // 3/4

    Fraction result;

    result = f1 + f2;
    f1.print(); cout << " + "; f2.print(); cout << " = "; result.print(); cout << '\n';

    result = f1 - f2;
    f1.print(); cout << " - "; f2.print(); cout << " = "; result.print(); cout << '\n';

    result = f1 * f2;
    f1.print(); cout << " * "; f2.print(); cout << " = "; result.print(); cout << '\n';

    result = f1 / f2;
    f1.print(); cout << " / "; f2.print(); cout << " = "; result.print(); cout << '\n';

    // порівняння
    f1.print(); cout << " < "; f2.print(); cout << " = " << (f1 < f2) << '\n';
    f1.print(); cout << " > "; f2.print(); cout << " = " << (f1 > f2) << '\n';

    return 0;
}


