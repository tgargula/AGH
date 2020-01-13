#include <iostream>

#define classes_hpp

using namespace std;

class Complex {
    private:
        double Re;
        double Im;
    public:
        void set (double Re, double Im);
        void output ();
        Complex add (Complex z);
        Complex substract (Complex z);
        Complex multiply (Complex z);
        Complex divide (Complex z);
};

class Rational {
    private:
        int numerator;
        int denominator;
        const int accuracyByOutput = 10;
    public:
        void set (int numerator, int denominator);
        void outputAsFraction ();
        void output ();
        Rational add (Rational rat);
        Rational substract (Rational rat);
        Rational multiply (Rational rat);
        Rational divide (Rational rat);
};

void Complex::set (double Re, double Im) {
    this->Re = Re;
    this->Im = Im;
}

void Rational::set (int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

void Complex::output() {
    cout << this->Re;
    if (this->Im > 0) cout << " + " << this->Im << "i";
    else if (this->Im < 0) cout << " - " << -this->Im << "i";
    cout << "\n";
}

void Rational::output () {
    int num = this->numerator, den = this->denominator;
    cout << num / den << ".";

    for (int ctr = 0; ctr < this->accuracyByOutput; ctr++) {
        num %= den;
        num *= 10;
        cout << num / den;
    } 

    cout << endl;
}

void Rational::outputAsFraction () {
    cout << this->numerator << "/" << this->denominator << endl;
}

Complex Complex::add (Complex z) {
    Complex sum;
    sum.Re = this->Re + z.Re;
    sum.Im = this->Im + z.Im;
    return sum;
}

Complex Complex::substract (Complex z) {
    Complex difference;
    difference.Re = this->Re - z.Re;
    difference.Im = this->Im - z.Im;
    return difference;
}

Complex Complex::multiply (Complex z) {
    Complex product;
    product.Re = this->Re * z.Re - this->Im * z.Im;
    product.Im = this->Im * z.Re + this->Re * z.Im;
    return product;
}

Complex Complex::divide (Complex z) {
    Complex quotient;
    double denominator = z.Re * z.Re - z.Im * z.Im;
    quotient.Re = this->Re * z.Re + this->Im * z.Im;
    quotient.Im = this->Im * z.Re - this->Re * z.Im;
    quotient.Re /= denominator;
    quotient.Im /= denominator;
    return quotient;
}