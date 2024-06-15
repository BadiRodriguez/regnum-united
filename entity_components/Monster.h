//
// Created by Badi on 6/14/2024.
//

#ifndef REGNUM_UNITED_MONSTER_H
#define REGNUM_UNITED_MONSTER_H

#include <iostream>
#include <string>
#include <vector>
#include "Lifebar.h"
#include "Entity.h"
#include "Item.h" // Assuming there is an Item class for the items monsters yield

class Monster : public Entity {
private:
    std::string species_name;
    int challenge_rating;
    Lifebar monster_lifebar;
    std::vector<Item> loot; // Items yielded upon defeat
    int attack;
    int defense;
    int magic_attack;
    int magic_defense;
    int agility;

public:
    // Constructors
    Monster();
    Monster(std::string species_name, int challenge_rating, int hp, int attack, int defense, int magic_attack, int magic_defense, int agility, std::vector<Item> loot);

    // Setters
    void setSpeciesName(const std::string &name);
    void setChallengeRating(int value);
    void setLoot(const std::vector<Item> &loot);
    void setAttack(int value);
    void setDefense(int value);
    void setMagicAttack(int value);
    void setMagicDefense(int value);
    void setAgility(int value);

    // Getters
    std::string getSpeciesName() const { return species_name; }
    int getChallengeRating() const { return challenge_rating; }
    std::vector<Item> getLoot() const { return loot; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getMagicAttack() const { return magic_attack; }
    int getMagicDefense() const { return magic_defense; }
    int getAgility() const { return agility; }

    // Lifebar Methods
    void deductHp(int amount) { monster_lifebar.deductHp(amount); }
    void addHp(int amount) { monster_lifebar.addHp(amount); }
    void displayLifebar() const { monster_lifebar.displayLifebar(); }
    int getCurrentHp() const { return monster_lifebar.getCurrentValue(); }
    int getMaxHp() const { return monster_lifebar.getMaxValue(); }

    // Template function to create a monster
    template<typename... Args>
    static Monster createMonster(Args... args);
};

#endif //REGNUM_UNITED_MONSTER_H

