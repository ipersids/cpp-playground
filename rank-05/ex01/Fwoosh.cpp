#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}
Fwoosh* Fwoosh::clone() {
  Fwoosh* res = new (std::nothrow) Fwoosh();
  if (!res) return nullptr;
  return res;
}