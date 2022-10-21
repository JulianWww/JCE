#include <jce/math.hpp>

jce::BigInt jce::pow(const BigInt& base, BigInt exp) {
    BigInt output;
    pow(base, exp, output);
    return output;
}
void jce::pow(const BigInt& base, BigInt& exp, BigInt& out) {
    if (jce::BigInt::Null(exp)) {
        out = 1;
    }
    else if (jce::BigInt::Null(exp % 2)) {
        exp.divide_by_2();
        pow(base, exp, out);
        out = out * out;
    }
    else {
        exp--;
        exp.divide_by_2();
        pow(base, exp, out);
        out = out * out * base;
    }
}