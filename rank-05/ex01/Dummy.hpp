#pragma once

#include <iostream>
#include <new>

#include "ATarget.hpp"

class Dummy : public ATarget {
 public:
  Dummy();
  ~Dummy() = default;
  Dummy(const Dummy& other) = delete;
  Dummy& operator=(const Dummy& other) = delete;

  Dummy* clone() override;
};