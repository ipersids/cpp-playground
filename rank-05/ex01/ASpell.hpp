#ifndef ASPELL_EX01_HPP
#define ASPELL_EX01_HPP

#include <iostream>
#include "ATarget.hpp"
class ATarget;


class ASpell {
  public:
    ASpell() = delete;
    virtual ~ASpell() = default;
    ASpell(const ASpell& other) = delete;
    ASpell& operator=(const ASpell& other) = delete;
    ASpell(const std::string& name, const std::string& effects);

    const std::string& getName() const;
    const std::string& getEffects() const;

    virtual ASpell* clone() = 0;
    void launch(const ATarget& target) const;

  protected:
    std::string _name;
    std::string _effects;
};

#endif // ASPELL_EX01_HPP