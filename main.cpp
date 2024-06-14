
#include <iostream>
#include "Land.h"

int main() {
    int opcion;

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

    std:: cout << "----Elder Ring----" << std::endl;
    std:: cout << "[Presione enter para continuar]" << std::endl;
    std::cin.get();

    std :: cout << "Elige tu clase de Personaje:" << std::endl;

    std :: cout << "Elige una Land (Selecciona un numero): " << std::endl;
    std :: cout << "1) Caelid" << std::endl;
    std :: cout << "2) Necrolimbo" << std::endl;
    std :: cout << "3) Ciudad Eterna" << std::endl;
    std :: cout << "4) Forja del Gigante" << std::endl;
    std :: cin >> opcion;
}
