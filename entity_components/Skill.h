#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <functional>
#include "Entity.h"

class Skill {
private:
    std::string name;
    std::string type;
    std::function<void(Entity&, Entity&)> formula;
    bool heals;

public:
    Skill(std::string name, std::string type, std::function<void(Entity&, Entity&)> formula, bool heals = false);

    void use(Entity &user, Entity &target) const;
    std::string getName() const;
    std::string getType() const;
};

#endif // SKILL_H
