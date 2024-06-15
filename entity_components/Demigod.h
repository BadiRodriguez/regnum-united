//
// Created by Badi on 6/14/2024.
//

#ifndef REGNUM_UNITED_DEMIGOD_H
#define REGNUM_UNITED_DEMIGOD_H

#include "Entity.h"
#include "Lifebar.h"
#include "Weapon.h"
#include "Skill.h"
#include <iostream>
#include <vector>

class Demigod : public Entity{

private:
    std::string name;
    int challenge_rating;
    int hp;
    Lifebar demigod_lifebar;
    int attack;
    int defense;
    int magic_attack;
    int magic_defense;
    int agility;
    Weapon right_hand; // Right hand weapon
    Weapon left_hand;  // Left hand weapon
    std::vector<std::unique_ptr<Skill>> skills;
    std::vector<std::unique_ptr<Spell>> spells;

public:
    // Constructors
    Demigod() = default;
    Demigod(std::string name, int challenge_rating, int hp, Lifebar demigod_lifebar, int attack, int defense, int magic_attack, int magic_defense, int agility, Weapon right_hand, Weapon left_hand);

    // Setters
    void setDemigodName(std::string name);
    void setChallenge_rating(int value);
    void setAttack(int value);
    void setDefense(int value);
    void setMagic_attack(int value);
    void setMagic_defense(int value);
    void setAgility(int value);

    // Getters
    std::string getDemigodName() const { return name; }
    int getChallenge_rating() const { return challenge_rating; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getMagic_attack() const { return magic_attack; }
    int getMagic_defense() const { return magic_defense; }
    int getAgility() const { return agility; }
    Weapon getRightHandWeapon() const { return right_hand; };
    Weapon getLeftHandWeapon() const { return left_hand; };

    // Unique methods
    void AssignRightHandWeapon(Weapon weapon);
    void AssignLeftHandWeapon(Weapon weapon);
};


#endif //REGNUM_UNITED_DEMIGOD_H
