//
// Created by Badi on 6/11/2024.
//

#include "Character.h"
#include "Skill.h"
#include "Spell.h"

#include <utility>

Character::Character()
        :name("Unnamed"),
        level(1),
        experience(0),
        hp(100),
        character_lifebar(100),
        attack(10),
        defense(10),
        magic_attack(10),
        magic_defense(10),
        agility(10)
        {}

Character::Character(std::string name, int level, int experience, int hp, int attack, int defense, int magic_attack, int magic_defense, int agility):
    Entity(true)
    {
    this -> name = std::move(name);
    this -> level = level;
    this -> experience = experience;
    this -> hp = hp;
    this -> character_lifebar = Lifebar(hp);
    this -> attack = attack;
    this -> defense = defense;
    this -> magic_attack = magic_attack;
    this -> magic_defense = magic_defense;
    this -> agility = agility;
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

void Character::setExperience(int value) {
    experience = value;
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

void Character::setAgility(int new_agility) {
    if(new_agility < 0){
        agility = 0;
    }
    else{
        agility = new_agility;
    }
}

void Character::levelUp(int num_of_levels) {
    if (num_of_levels <= 0){
        return;
    }
    std::cout << getCharacterName() << " leveled up!" << std::endl;
    std::cout << getLevel() << " -> " << getLevel() + num_of_levels;
    level += num_of_levels;
}

void Character::equipWeapon(const Weapon& right_Hand, const Weapon& left_Hand) {
    this -> right_hand = right_Hand;
    this -> left_hand = left_Hand;
}

void Character::addSkill(std::unique_ptr<Skill> skill) {
    skills.push_back(std::move(skill));
}

void Character::addSpell(std::unique_ptr<Spell> spell) {
    spells.push_back(std::move(spell));
}

void Character::performSkill(const std::string &skillName, Character &target) {
    for (const auto &skill : skills) {
        if (skill->getName() == skillName) {
            std::cout << name << " performs " << skillName << " on " << target.getCharacterName() << ", a " << skill->getType() << " type skill!" << std::endl;
            skill->use(*this, target);
            return;
        }
    }
    std::cout << name << " doesn't know the skill " << skillName << std::endl;
}

void Character::castSpell(const std::string &spellName, Character &target) {
    for (const auto &spell : spells) {
        if (spell->getName() == spellName) {
            std::cout << name << " casts " << spellName << " on " << target.getCharacterName() << ", a " << spell->getElementalType() << " elemental spell!" << std::endl;
            spell->use(*this, target);
            return;
        }
    }
    std::cout << name << " doesn't know the spell " << spellName << std::endl;
}
