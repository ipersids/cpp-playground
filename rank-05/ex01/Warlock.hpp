#ifndef WARLOCK_EX00_H
#define WARLOCK_EX00_H

#include <iostream>
#include <map>

#include "ASpell.hpp"

class Warlock {
 public:
  Warlock() = delete;
  Warlock(const std::string& name, const std::string& title);
  Warlock(const Warlock& other) = delete;
  Warlock& operator=(const Warlock& other) = delete;
  ~Warlock();

  const std::string& getName() const;
  const std::string& getTitle() const;
  void setTitle(const std::string& title);
  void introduce() const;

  void learnSpell(ASpell* spell);
  void forgetSpell(const std::string& spell_type);
  void launchSpell(const std::string& spell_type, ATarget& target);

 private:
  std::string _name;
  std::string _title;
  std::map<std::string, ASpell*> _spells;
};

#endif  // WARLOCK_EX00_H
