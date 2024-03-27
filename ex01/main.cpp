#include <iostream>

#include "Serializer.hpp"
#include "data.hpp"

int main() {
  Data d1;
  uintptr_t saved;
  Data* d1Ptr;

  saved = Serializer::serialize(&d1);
  d1Ptr = Serializer::deserialize(saved);

  std::cout << "d1's address : " << &d1 << '\n';
  std::cout << "d1Ptr's value : " << d1Ptr << '\n';
}