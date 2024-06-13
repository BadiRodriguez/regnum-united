//
// Created by Badi on 6/11/2024.
//

#include "Character.h"

#include <utility>

Character::Character(std::string name, int level, int hp, Lifebar character_lifebar(int count), int attack, int defense, int magic_attack, int magic_defense) {
    this -> name = std::move(name);
    this -> level = level;
    this -> hp = hp;
    this -> character_lifebar = character_lifebar(hp);
    this -> attack = attack;
    this -> defense = defense;
    this -> magic_attack = magic_attack;
    this -> magic_defense = magic_defense;
}

void Character::setCharacterName(std::string new_name){
    name = std::move(new_name);
}

void Character::setLevel(int new_level) {
    if (new_level < 0){
        level = 1;
    }
    else{
        level = new_level;
    }
}

void Character::setAttack(int new_attack) {
    if ( new_attack < 0){
        attack = 0;
    }
    else{
        attack = new_attack;
    }
}

void Character::setDefense(int new_defense) {
    if(new_defense < 0){
        defense = 0;
    }
    else{
        defense = new_defense;
    }
}

void Character::setMagic_attack(int new_magic_attack) {
    if(new_magic_attack < 0){
        magic_attack = 0;
    }
    else{
        magic_attack = new_magic_attack;
    }
}

void Character::setMagic_defense(int new_magic_defense) {
    if(new_magic_defense < 0){
        magic_defense = 0;
    }
    else{
        magic_defense = new_magic_defense;
    }
}


