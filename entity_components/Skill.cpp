#include "Skill.h"

Skill::Skill(std::string name, std::string type, std::function<void(Entity&, Entity&)> formula, bool heals)
    : name(std::move(name)), type(std::move(type)), formula(std::move(formula)), heals(heals) {}

void Skill::use(Entity &user, Entity &target) const {
    formula(user, target);
}

std::string Skill::getName() const {
    return name;
}

std::string Skill::getType() const {
    return type;
}
