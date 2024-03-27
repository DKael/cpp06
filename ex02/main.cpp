#include <iostream>
#include <random>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
  Base* test = generate();

  identify(test);
  identify(*test);
  delete test;
}

Base* generate(void) {
  std::random_device rd;
  int sel;
  Base* retVal;

  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(0, 2);
  sel = dis(gen);
  if (sel == 0) {
    retVal = static_cast<Base*>(new A);
  } else if (sel == 1) {
    retVal = static_cast<Base*>(new B);
  } else {
    retVal = static_cast<Base*>(new C);
  }
  return retVal;
}

void identify(Base* p) {
  A* APtr;
  B* BPtr;
  C* CPtr;

  APtr = dynamic_cast<A*>(p);
  if (APtr != NULL) {
    std::cout << "p actually poiting out object A\n";
    return;
  }
  BPtr = dynamic_cast<B*>(p);
  if (BPtr != NULL) {
    std::cout << "p actually poiting out object B\n";
    return;
  }
  CPtr = dynamic_cast<C*>(p);
  if (CPtr != NULL) {
    std::cout << "p actually poiting out object C\n";
    return;
  }
}

void identify(Base& p) {
  try {
    A& ARef = dynamic_cast<A&>(p);
    std::cout << "p is actually object A\n";
    static_cast<void>(ARef);
    return;
  } catch (std::bad_cast& bc) {
  }
  try {
    B& BRef = dynamic_cast<B&>(p);
    std::cout << "p is actually object B\n";
    static_cast<void>(BRef);
    return;
  } catch (std::bad_cast& bc) {
  }
  try {
    C& CRef = dynamic_cast<C&>(p);
    std::cout << "p is actually object C\n";
    static_cast<void>(CRef);
    return;
  } catch (std::bad_cast& bc) {
  }
}
