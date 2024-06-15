//
// Created by Badi on 6/14/2024.
//

#include "Monster.h"

Monster::Monster()
        : species_name("Unnamed"),
          challenge_rating(1),
          monster_lifebar(100),
          attack(10),
          defense(10),
          magic_attack(10),
          magic_defense(10),
          agility(10) {}

Monster::Monster(std::string species_name, int challenge_rating, int hp, int attack, int defense, int magic_attack, int magic_defense, int agility, std::vector<Item> loot)
        : Entity(false),
          species_name(std::move(species_name)),
          challenge_rating(challenge_rating),
          monster_lifebar(hp),
          loot(std::move(loot)),
          attack(attack),
          defense(defense),
          magic_attack(magic_attack),
          magic_defense(magic_defense),
          agility(agility) {}

void Monster::setSpeciesName(const std::string &name) {
    species_name = name;
}

void Monster::setChallengeRating(int value) {
    challenge_rating = value;
}

void Monster::setLoot(const std::vector<Item> &loot_items) {
    loot = loot_items;
}

void Monster::setAttack(int value) {
    attack = value;
}

void Monster::setDefense(int value) {
    defense = value;
}

void Monster::setMagicAttack(int value) {
    magic_attack = value;
}

void Monster::setMagicDefense(int value) {
    magic_defense = value;
}

void Monster::setAgility(int value) {
    agility = value;
}

template<typename... Args>
Monster Monster::createMonster(Args... args) {
    return Monster(args...);
}