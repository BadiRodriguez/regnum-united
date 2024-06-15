#include "Character.h"
#include <iostream>

// Default constructor
Character::Character() : level(1), experience(0), experience_to_next_level(100), attack(0), defense(0), magic_attack(0), magic_defense(0), agility(0) {}

// Parameterized constructor
Character::Character(std::string name, int level, int experience, int hp, int attack, int defense, int magic_attack, int magic_defense, int agility)
    : name(name), level(level), experience(experience), experience_to_next_level(100 * level), character_lifebar(hp), attack(attack), defense(defense),
      magic_attack(magic_attack), magic_defense(magic_defense), agility(agility) {}

// Setters
void Character::setCharacterName(std::string name) { this->name = name; }
void Character::setLevel(int value) { level = value; }
void Character::setExperience(int value) { experience = value; }
void Character::setAttack(int value) { attack = value; }
void Character::setDefense(int value) { defense = value; }
void Character::setMagic_attack(int value) { magic_attack = value; }
void Character::setMagic_defense(int value) { magic_defense = value; }
void Character::setAgility(int value) { agility = value; }

// Additional methods
void Character::gainExperience(int exp) {
    experience += exp;
    while (experience >= experience_to_next_level) {
        levelUp();
    }
}

void Character::levelUp(int num_of_levels) {
    for (int i = 0; i < num_of_levels; ++i) {
        level++;
        experience_to_next_level = 100 * level;
        attack += 5;
        defense += 5;
        magic_attack += 5;
        magic_defense += 5;
        agility += 2;
        character_lifebar.addHp(20); // Example increase
    }
}

void Character::equipWeapon(const Weapon& rightHand, const Weapon& leftHand) {
    right_hand = rightHand;
    left_hand = leftHand;
}

void Character::learnSkill(std::unique_ptr<Skill> skill) {
    skills.push_back(std::move(skill));
}

// Skill and Spell methods
void Character::addSkill(std::unique_ptr<Skill> skill) {
    skills.push_back(std::move(skill));
}

void Character::addSpell(std::unique_ptr<Spell> spell) {
    spells.push_back(std::move(spell));
}

void Character::performSkill(const std::string &skillName, Character &target) {
    for (const auto& skill : skills) {
        if (skill->getName() == skillName) {
            skill->use(*this, target);
            return;
        }
    }
    std::cout << "Skill not found!" << std::endl;
}

void Character::castSpell(const std::string &spellName, Character &target) {
    for (const auto& spell : spells) {
        if (spell->getName() == spellName) {
            spell->use(*this, target);
            return;
        }
    }
    std::cout << "Spell not found!" << std::endl;
}

// Additional methods
void Character::describe() const {
    std::cout << "Character: " << name << ", Level: " << level << ", HP: " << character_lifebar.getCurrentValue() << "/" << character_lifebar.getMaxValue() << std::endl;
}
