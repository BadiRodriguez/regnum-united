//
// Created by jfpro on 14/06/24.
//

#ifndef COMBAT_H
#define COMBAT_H

#include "Monster.h"
#include "Character.h"
#include "Demigod.h"
#include "Menu.h"

#include<iostream>
#include<random>

void normalCombat(Character player_character, std::vector<Monster>&& Monsters) {
    // Begin combat for declared character and monsters
    std::cout << "Enemies ahead!" << std::endl;
    std::cout << "Battle - BEGIN!!!" << std::endl;
    while (player_character.getCurrentHp() > 0 or Monsters[0].getCurrentHp() > 0) {

    };

}

#endif //COMBAT_H
