#include "Character.h"
#include "Skill.h"
#include "Spell.h"

#include <utility>

Character::Character()
        : name("Unnamed"),
          level(1),
          experience(0),
          experience_to_next_level(100),
          hp(100),
          character_lifebar(100),
          attack(10),
          defense(10),
          magic_attack(10),
          magic_defense(10),
          agility(10) {}

Character::Character(std::string name, int level, int experience, int hp, int attack, int defense, int magic_attack, int magic_defense, int agility)
        : Entity(true),
          name(std::move(name)),
          level(level),
          experience(experience),
          experience_to_next_level(100 * level), // Dynamic threshold based on level
          hp(hp),
          character_lifebar(hp),
          attack(attack),
          defense(defense),
          magic_attack(magic_attack),
          magic_defense(magic_defense),
          agility(agility) {}

void Character::setCharacterName(std::string new_name) {
    name = std::move(new_name);
}

void Character::setLevel(int new_level) {
    level = (new_level < 0) ? 1 : new_level;
}

void Character::setExperience(int value) {
    experience = value;
}

void Character::setAttack(int new_attack) {
    attack = (new_attack < 0) ? 0 : new_attack;
}

void Character::setDefense(int new_defense) {
    defense = (new_defense < 0) ? 0 : new_defense;
}

void Character::setMagic_attack(int new_magic_attack) {
    magic_attack = (new_magic_attack < 0) ? 0 : new_magic_attack;
}

void Character::setMagic_defense(int new_magic_defense) {
    magic_defense = (new_magic_defense < 0) ? 0 : new_magic_defense;
}

void Character::setAgility(int new_agility) {
    agility = (new_agility < 0) ? 0 : new_agility;
}

void Character::levelUp(int num_of_levels) {
    if (num_of_levels <= 0) {
        return;
    }

    for (int i = 0; i < num_of_levels; ++i) {
        if (experience < experience_to_next_level) {
            break;
        }

        experience -= experience_to_next_level;
        level++;
        experience_to_next_level = 50 * level; // Update threshold

        // Increase character stats on level up (example logic)
        hp += 20;
        attack += 5;
        defense += 5;
        magic_attack += 5;
        magic_defense += 5;
        agility += 2;
    }

    std::cout << getCharacterName() << " leveled up! New level: " << level << std::endl;
}

void Character::gainExperience(int exp) {
    experience += exp;
    while (experience >= experience_to_next_level) {
        levelUp(1);
    }
}

void Character::equipWeapon(const Weapon& right_Hand, const Weapon& left_Hand) {
    this->right_hand = right_Hand;
    this->left_hand = left_Hand;
}

void Character::learnSkill(std::unique_ptr<Skill> skill) {
    skills.push_back(std::move(skill));
    std::cout << name << " learned a new skill: " << skills.back()->getName() << std::endl;
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

