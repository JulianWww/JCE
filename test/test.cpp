#include <iostream>
#include <jce/math.hpp>
#include <jce/dtypes/bigInt.hpp>

int main(int argc, char **argv) {
  jce::BigInt base(10);
  jce::BigInt exp(10);

  std::cout << jce::pow(base, exp) << std::endl;
  return 1;
}