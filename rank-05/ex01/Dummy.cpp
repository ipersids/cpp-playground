#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}
Dummy* Dummy::clone() {
  Dummy* res = new (std::nothrow) Dummy();
  if (!res) return nullptr;
  return res;
}