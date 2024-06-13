//
// Created by Badi on 6/11/2024.
//

#ifndef REGNUM_UNITED_CHARACTER_H
#define REGNUM_UNITED_CHARACTER_H

#include <iostream>
#include <string>
#include "Lifebar.h"

class Character {
private:
    std::string name;
    int level;
    int hp;
    Lifebar character_lifebar;
    int attack; int defense;
    int magic_attack; int magic_defense;
public:
    // Constructors
    Character() = default;
    Character(std::string, int, int, Lifebar(int), int, int, int, int);

    // Setters
    void setCharacterName(std::string);
    void setLevel(int);
    void setAttack(int), setDefense(int);
    void setMagic_attack(int), setMagic_defense(int);

    // Getters
    std::string getCharacterName() const {return name;};
    int getLevel() const {return level;};
    int getAttack() const {return attack;};
    int getDefense() const {return defense;};
    int getMagic_attack() const {return magic_attack;};
    int getMagic_defense() const {return magic_defense;};
};


#endif //REGNUM_UNITED_CHARACTER_H
