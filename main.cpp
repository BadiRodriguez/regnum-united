#include "entity_components/Land.h"
#include "entity_components/Menu.h"
#include "entity_components/Entity.h"
#include "entity_components/Character.h"


void offensiveSkill(Entity &user, Entity &target) {
    Character *charTarget;
    charTarget = dynamic_cast<Character *>(&target);
    if (charTarget) {
        int damage = 20; // Example damage value
        charTarget->deductHp(damage);
        std::cout << "Offensive skill used! Target HP reduced by " << damage << "." << std::endl;
    }
}

void healingSpell(Entity &user, Entity &target) {
    Character *charTarget;
    charTarget = dynamic_cast<Character *>(&target);
    if (charTarget) {
        int healAmount = 15; // Example healing value
        charTarget->addHp(healAmount);
        std::cout << "Healing spell used! Target HP increased by " << healAmount << "." << std::endl;
    }
}

int main() {
    Caelid caelid;
    Necrolimbo necrolimbo;
    Ciudad_Eterna ciudadEterna;
    Forja_de_gigante forjaDelGigante;

    caelid.addStructure(CamposAbiertos());
    caelid.addStructure(Cuevas());
    caelid.addStructure(Puentes());

    necrolimbo.addStructure(Catacumbas());
    necrolimbo.addStructure(Cuevas());
    necrolimbo.addStructure(CamposAbiertos());

    ciudadEterna.addStructure(Puentes());
    ciudadEterna.addStructure(CamposAbiertos());

    forjaDelGigante.addStructure(Puentes());
    forjaDelGigante.addStructure(CamposAbiertos());

    // Create two characters
    Character hero("Hero", 10, 500, 150, 20, 15, 30, 25, 20);
    Character villain("Villain", 8, 400, 120, 18, 12, 25, 20, 18);

    // Create skills and spells
    auto slash = std::make_unique<Skill>("Slash", "Offensive", offensiveSkill);
    auto heal = std::make_unique<Spell>("Heal", "Restoration", healingSpell, true);

    // Add skills and spells to the hero
    hero.addSkill(std::move(slash));
    hero.addSpell(std::move(heal));

    // Hero uses skill on villain
    hero.performSkill("Slash", villain);
    std::cout << "Villain's HP after Slash: " << villain.getCurrentHp() << std::endl;

    // Hero casts spell on themselves
    hero.castSpell("Heal", hero);
    std::cout << "Hero's HP after Heal: " << hero.getCurrentHp() << std::endl;

    std::cout << "----Elder Ring----" << std::endl;
    std::cout << "[Presione enter para continuar]" << std::endl;
    std::cin.get();

    while (true) {
        std::cout << "Elige una Land (Selecciona un numero): " << std::endl;
        Menu({"Caelid", "Necrolimbo", "Ciudad Eterna", "Forja del Gigante", "Salir"},
             [&]() { std::cout << caelid; },
             [&]() { std::cout << necrolimbo; },
             [&]() { std::cout << ciudadEterna; },
             [&]() { std::cout << forjaDelGigante; },
             [&]() { exit(0); });



    }
}
