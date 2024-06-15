#ifndef COMBAT_H
#define COMBAT_H

#include "Monster.h"
#include "Character.h"
#include <vector>
#include <iostream>

void printHealthBar(const std::string& name, int currentHp, int maxHp) {
    int barWidth = 50;
    std::cout << name << ": [";
    int pos = barWidth * currentHp / maxHp;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << currentHp << "/" << maxHp << "\n";
}

bool normalCombat(Character& player_character, std::vector<Monster>&& monsters) {
    std::cout << "Enemies ahead!" << std::endl;
    std::cout << "Battle - BEGIN!!!" << std::endl;

    while (player_character.getCurrentHp() > 0 && !monsters.empty()) {
        for (auto it = monsters.begin(); it != monsters.end(); ) {
            Monster& monster = *it;

            // Player's turn
            printHealthBar(player_character.getCharacterName(), player_character.getCurrentHp(), player_character.getMaxHp());
            printHealthBar(monster.getSpeciesName(), monster.getCurrentHp(), monster.getMaxHp());

            int choice;
            std::cout << "Choose your action:\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Use Skill\n";
            std::cout << "3. Use Spell\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    int playerDamage = player_character.getAttack() - monster.getDefense();
                    playerDamage = playerDamage < 0 ? 0 : playerDamage;
                    monster.deductHp(playerDamage);
                    std::cout << player_character.getCharacterName() << " attacks " << monster.getSpeciesName() << " for " << playerDamage << " damage.\n";
                    break;
                }
                case 2:
                    std::cout << "Choose a skill to use (not implemented yet).\n";
                    break;
                case 3:
                    std::cout << "Choose a spell to cast (not implemented yet).\n";
                    break;
                default:
                    std::cout << "Invalid choice! You missed your turn.\n";
                    break;
            }

            // Check if monster is defeated
            if (monster.getCurrentHp() <= 0) {
                printHealthBar(monster.getSpeciesName(), 0, monster.getMaxHp());
                std::cout << monster.getSpeciesName() << " is defeated!\n";
                it = monsters.erase(it); // Remove defeated monster
                continue;
            }

            // Monster's turn
            int monsterDamage = monster.getAttack() - player_character.getDefense();
            monsterDamage = monsterDamage < 0 ? 0 : monsterDamage;
            player_character.deductHp(monsterDamage);
            std::cout << monster.getSpeciesName() << " attacks " << player_character.getCharacterName() << " for " << monsterDamage << " damage.\n";

            // Check if player is defeated
            if (player_character.getCurrentHp() <= 0) {
                std::cout << player_character.getCharacterName() << " has been defeated!\n";
                printHealthBar(player_character.getCharacterName(), 0, player_character.getMaxHp());
                return false; // Player defeated
            }

            ++it; // Move to next monster
        }
    }

    if (player_character.getCurrentHp() > 0) {
        std::cout << player_character.getCharacterName() << " has defeated all the monsters!\n";
        return true; // Player won
    }
    return false; // Just in case
}

#endif // COMBAT_H
