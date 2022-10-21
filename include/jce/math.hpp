#include "dtypes/bigInt.hpp"

namespace jce {
    BigInt pow(const BigInt& base, BigInt exp);
    void pow(const BigInt& base, BigInt& exp, BigInt& out);
}