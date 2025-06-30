#pragma once

#include <iostream>
#include <new>

#include "ASpell.hpp"

class Fwoosh: public ASpell {
  public:
    Fwoosh();
    ~Fwoosh() = default;
    Fwoosh(const Fwoosh& other) = delete;
    Fwoosh& operator=(const Fwoosh& other) = delete;

    Fwoosh* clone() override;
};