/**
 * @file Zombie.hpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>

class Zombie {
  public:
    Zombie() = delete;
    Zombie(const std::string& name);
    Zombie(const Zombie& other) = delete;
    Zombie& operator=(const Zombie& other) = delete;
    ~Zombie();

    void announce(void);

  private:
    std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // ZOMBIE_HPP_