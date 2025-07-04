#ifndef WARLOCK_EX00_H
#define WARLOCK_EX00_H

#include <iostream>

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

 private:
  std::string _name;
  std::string _title;
};

#endif  // WARLOCK_EX00_H
