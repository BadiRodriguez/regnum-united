//
// Created by Badi on 6/14/2024.
//

#include "Demigod.h"

#include <utility>

Demigod::Demigod(std::string name, int challenge_rating, int hp, int attack, int defense, int magic_attack, int magic_defense, int agility, Weapon right_hand, Weapon left_hand): Entity(false) {
    this -> name = std::move(name);
    this -> challenge_rating = challenge_rating;
    this -> hp = hp;
    this -> demigod_lifebar = Lifebar(hp);
    this -> attack = attack;
    this -> defense = defense;
    this -> magic_attack = magic_attack;
    this -> magic_defense = magic_defense;
    this -> agility = agility;
}

void Demigod::setDemigodName(std::string name) {
    this -> name = std::move(name);
}

void Demigod::setChallenge_rating(int value) {
    this -> challenge_rating = challenge_rating;
}

void Demigod::setAttack(int value) {
    this -> attack = attack;
}

void Demigod::setDefense(int value) {
    this -> defense = defense;
}

void Demigod::setMagic_attack(int value) {
    this -> magic_attack = magic_attack;
}

void Demigod::setMagic_defense(int value) {
    this -> magic_defense = magic_defense;
}

void Demigod::setAgility(int value) {
    this -> agility = agility;
}

void Demigod::AssignRightHandWeapon(Weapon weapon) {
    right_hand = weapon;
}

void Demigod::AssignLeftHandWeapon(Weapon weapon) {
    left_hand = weapon;
}


