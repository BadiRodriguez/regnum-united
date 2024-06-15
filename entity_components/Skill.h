
#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <string>
#include <functional>
#include "Character.h"

class Character; // Forward declaration
class Demigod; // Forward declaration

class Skill {
public:
    Skill(std::string name, std::string type, std::function<void(Entity&, Entity&)> formula, bool heals = false);

    const std::string &getName() const;
    const std::string &getType() const;
    void use(Entity &user, Entity &target) const;

private:
    std::string name;
    std::string type;
    std::function<void(Entity&, Entity&)> formula;
    bool heals;
};

#endif // SKILL_H