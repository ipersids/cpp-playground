#pragma once

#include <cstdint>

#include "data.hpp"

class Serializer {
 public:
  Serializer() = delete;
  Serializer(const Serializer& other) = delete;
  Serializer& operator=(const Serializer& other) = delete;

  static std::uintptr_t serialize(Data* ptr);
  static Data* deserialize(std::uintptr_t raw);

 private:
  ~Serializer() = default;
};
