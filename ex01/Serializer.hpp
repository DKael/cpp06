#ifndef SERIALIZAER_HPP
#define SERIALIZAER_HPP

typedef unsigned long uintptr_t;

#include "data.hpp"

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer& origin);
  Serializer& operator=(const Serializer& origin);
  ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif