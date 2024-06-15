#include "Demigod.h"

#include <utility>

Demigod::Demigod(std::string name, int challenge_rating, int hp, int attack, int defense, int magic_attack, int magic_defense, int agility, Weapon right_hand, Weapon left_hand)
        : Entity(false), name(std::move(name)), challenge_rating(challenge_rating), hp(hp), demigod_lifebar(hp), attack(attack), defense(defense), magic_attack(magic_attack), magic_defense(magic_defense), agility(agility), right_hand(std::move(right_hand)), left_hand(std::move(left_hand)) {}

void Demigod::setDemigodName(std::string name) {
    this->name = std::move(name);
}

void Demigod::setChallenge_rating(int value) {
    this->challenge_rating = value;
}

void Demigod::setAttack(int value) {
    this->attack = value;
}

void Demigod::setDefense(int value) {
    this->defense = value;
}

void Demigod::setMagic_attack(int value) {
    this->magic_attack = value;
}

void Demigod::setMagic_defense(int value) {
    this->magic_defense = value;
}

void Demigod::setAgility(int value) {
    this->agility = value;
}

void Demigod::AssignRightHandWeapon(Weapon weapon) {
    right_hand = std::move(weapon);
}

void Demigod::AssignLeftHandWeapon(Weapon weapon) {
    left_hand = std::move(weapon);
}

void Demigod::dropWeapons() {
    std::cout << name << " has dropped " << right_hand.getName() << " and " << left_hand.getName() << "." << std::endl;
    // Logic to handle dropped weapons in the game world
}

std::vector<std::unique_ptr<Skill>> Demigod::releaseSkills() {
    std::cout << name << " has released their skills upon death." << std::endl;
    return std::move(skills);
}


