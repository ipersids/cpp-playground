#ifndef ATARGRT_EX01_HPP
#define ATARGRT_EX01_HPP

#include <iostream>

#include "ASpell.hpp"
class ASpell;

class ATarget {
 public:
  ATarget() = delete;
  virtual ~ATarget() = default;
  ATarget& operator=(const ATarget& other) = delete;
  ATarget(const ATarget& other);
  ATarget(const std::string& type);

  const std::string& getType() const;
  void getHitBySpell(const ASpell& spell) const;

  virtual ATarget* clone() = 0;

 private:
  std::string _type;
};

#endif  // ATARGRT_EX01_HPP