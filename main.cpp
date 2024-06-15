#include "entity_components/Land.h"
#include "entity_components/Menu.h"

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
