#include "entity_components/Land.h"
#include "entity_components/Menu.h"
#include "entity_components/Entity.h"
#include "entity_components/Character.h"
#include "entity_components/Combat.h"
#include "entity_components/Spell.h"
#include "entity_components/Skill.h"
#include "entity_components/Monster.h"
#include "entity_components/Structures.h"
#include <iostream>
#include <vector>
#include <limits>
#include <memory>

void offensiveSkill(Entity &user, Entity &target) {
    Character *charTarget = dynamic_cast<Character *>(&target);
    if (charTarget) {
        int damage = 20; // Example damage value
        charTarget->deductHp(damage);
        std::cout << "Offensive skill used! Target HP reduced by " << damage << "." << std::endl;
    }
}

void healingSpell(Entity &user, Entity &target) {
    Character *charTarget = dynamic_cast<Character *>(&target);
    if (charTarget) {
        int healAmount = 15; // Example healing value
        charTarget->addHp(healAmount);
        std::cout << "Healing spell used! Target HP increased by " << healAmount << "." << std::endl;
    }
}

std::unique_ptr<Character> createCharacterMenu() {
    int choice;
    std::string name;
    while (true) {
        std::cout << "Choose your character class:\n";
        std::cout << "1. Warrior\n";
        std::cout << "2. Mage\n";
        std::cout << "3. Archer\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 3) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid choice! Please try again.\n";
        } else {
            break;
        }
    }

    std::cout << "Enter your character's name: ";
    std::cin >> name;

    switch (choice) {
        case 1:
            return std::make_unique<Character>(name, 1, 0, 500, 150, 20, 15, 30, 25); // Example stats for Warrior
        case 2:
            return std::make_unique<Character>(name, 1, 0, 300, 80, 10, 40, 50, 15); // Example stats for Mage
        case 3:
            return std::make_unique<Character>(name, 1, 0, 400, 100, 15, 20, 35, 30); // Example stats for Archer
        default:
            std::cout << "Invalid choice! Defaulting to Warrior.\n";
            return std::make_unique<Character>(name, 1, 0, 500, 150, 20, 15, 30, 25);
    }
}

void displayMenuAndStartCombat(std::unique_ptr<Character>& player) {
    auto caelid = std::make_unique<Caelid>();
    auto necrolimbo = std::make_unique<Necrolimbo>();
    auto ciudadEterna = std::make_unique<Ciudad_Eterna>();
    auto forjaDelGigante = std::make_unique<Forja_de_gigante>();

    caelid->addStructure(CamposAbiertos());
    caelid->addStructure(Cuevas());
    caelid->addStructure(Puentes());

    necrolimbo->addStructure(Catacumbas());
    necrolimbo->addStructure(Cuevas());
    necrolimbo->addStructure(CamposAbiertos());

    ciudadEterna->addStructure(Puentes());
    ciudadEterna->addStructure(CamposAbiertos());

    forjaDelGigante->addStructure(Puentes());
    forjaDelGigante->addStructure(CamposAbiertos());

    std::vector<Land*> lands = {caelid.get(), necrolimbo.get(), ciudadEterna.get(), forjaDelGigante.get()};
    std::vector<std::string> options = {"Caelid", "Necrolimbo", "Ciudad Eterna", "Forja de Gigante", "Salir"};

    int choice;
    while (true) {
        std::cout << "Choose your land:\n";
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << i + 1 << ". " << options[i] << "\n";
        }
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > static_cast<int>(lands.size()) + 1) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid choice! Please try again.\n";
        } else if (choice == 5) {
            exit(0);
        } else {
            Land* selectedLand = lands[choice - 1];
            selectedLand->showMenu(*player);
        }
    }
}

int main() {
    // Create a character through the menu
    auto player = createCharacterMenu();

    // Display the menu and start combat
    displayMenuAndStartCombat(player);

    return 0;
}
