
#include "Skill.h"

#include <utility>

Skill::Skill(std::string name, std::string type, std::function<void(Character&, Character&)> formula, bool heals)
        : name(std::move(name)), type(std::move(type)), formula(std::move(formula)), heals(heals) {}

const std::string &Skill::getName() const {
    return name;
}

const std::string &Skill::getType() const {
    return type;
}

void Skill::use(Character &user, Character &target) const {
    formula(user, target);
}