#include <iostream>
#include "entity_components/Land.h"
#include "entity_components/Character.h"

void physicalAttackFormula(Character &user, Character &target) {
    int damage = user.getAttack() - target.getDefense();
    std::cout << target.getCharacterName() << " takes " << damage << " damage!" << std::endl;
}

void fireSpellFormula(Character &user, Character &target) {
    int damage = user.getMagic_attack() - target.getMagic_defense();
    std::cout << target.getCharacterName() << " takes " << damage << " fire damage!" << std::endl;
}

int main() {
    // Create instances of each Land type
    Necrolimbo necrolimbo;
    Caelid caelid;
    Ciudad_Eterna ciudadEterna;
    Forja_de_gigante forjaDeGigante;

    // Add structures to Necrolimbo
    necrolimbo.addStructure<Cuevas>();
    necrolimbo.addStructure<Tuneles>();

    // Add structures to Caelid
    caelid.addStructure<Catacumbas>();
    caelid.addStructure<Puentes>();

    // Add structures to Ciudad Eterna
    ciudadEterna.addStructure<CamposAbiertos>();
    ciudadEterna.addStructure<Tuneles>();

    // Add structures to Forja de Gigante
    forjaDeGigante.addStructure<Cuevas>();
    forjaDeGigante.addStructure<Catacumbas>();

    // Describe each Land
    necrolimbo.describe();
    necrolimbo.printStructures();

    caelid.describe();
    caelid.printStructures();

    ciudadEterna.describe();
    ciudadEterna.printStructures();

    forjaDeGigante.describe();
    forjaDeGigante.printStructures();

    Character hero("Hero", 1, 0, 100, Lifebar(100), 15, 10, 20, 10);
    Character enemy("Enemy", 1, 0, 80, Lifebar(80), 10, 5, 15, 5);

    return 0;

    return 0;
}
