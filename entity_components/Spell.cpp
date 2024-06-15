#include "Spell.h"

Spell::Spell(std::string name, std::string elementalType, std::function<void(Entity&, Entity&)> formula, bool heals)
    : name(std::move(name)), elementalType(std::move(elementalType)), formula(std::move(formula)), heals(heals) {}

void Spell::use(Entity &user, Entity &target) const {
    formula(user, target);
}

std::string Spell::getName() const {
    return name;
}

std::string Spell::getElementalType() const {
    return elementalType;
}
