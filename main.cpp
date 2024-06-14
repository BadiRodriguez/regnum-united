#include <iostream>
#include "entity_components/Land.h"

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

    return 0;
}
