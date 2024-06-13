//
// Created by Badi on 6/13/2024.
//

#include "Weapon.h"


Weapon::Weapon(std::string _name, int _damage, int _value, std::string _damage_type){
    name = std::move(_name);
    damage = _damage;
    value = _value;
    damage_type = std::move(_damage_type);
}

void Weapon::describe() const {
    std::cout <<
    "Weapon: " << name << ", Damage: " << damage << ", Damage Type: " << damage_type
    << std::endl;
}