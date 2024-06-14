//
// Created by Badi on 6/11/2024.
//

#ifndef REGNUM_UNITED_CHARACTER_H
#define REGNUM_UNITED_CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "Lifebar.h"
#include "Weapon.h"
#include "Entity.h"

class Character : public Entity{
private:
    std::string name;
    int level;
    int experience;
    int hp;
    Lifebar character_lifebar;
    int attack; int defense;
    int magic_attack; int magic_defense;
    Weapon right_hand; // Right hand weapon
    Weapon left_hand; // Left hand weapon
public:
    // Constructors
    Character();
    Character(std::string name, int level, int experience, int hp, Lifebar(int), int attack, int defense, int magic_attack, int magic_defense);

    // Setters
    void setCharacterName(std::string name);
    void setLevel(int value);
    void setExperience(int value);
    void setAttack(int value), setDefense(int value);
    void setMagic_attack(int value), setMagic_defense(int value);

    // Getters
    std::string getCharacterName() const {return name;};
    int getLevel() const {return level;};
    int getExperience() const {return experience;};
    int getAttack() const {return attack;};
    int getDefense() const {return defense;};
    int getMagic_attack() const {return magic_attack;};
    int getMagic_defense() const {return magic_defense;};

    // Additional methods
    void levelUp(int num_of_levels);
    virtual void equipWeapon(Weapon rightHand, Weapon leftHand){

    };

};


#endif //REGNUM_UNITED_CHARACTER_H
