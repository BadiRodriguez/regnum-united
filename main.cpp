
#include <iostream>
#include "tierra.h"

int main() {
    int opcion;

    Caelid caelid;
    Necrolimbo necrolimbo;
    Ciudad_Eterna ciudadEterna;
    Forja_de_gigante forjaDelGigante;

    caelid.agregarEstructura(CamposAbiertos());
    caelid.agregarEstructura(Cuevas());
    caelid.agregarEstructura(Puentes());

    necrolimbo.agregarEstructura(Catacumbas());
    necrolimbo.agregarEstructura(Cuevas());
    necrolimbo.agregarEstructura(CamposAbiertos());

    ciudadEterna.agregarEstructura(Puentes());
    ciudadEterna.agregarEstructura(CamposAbiertos());

    forjaDelGigante.agregarEstructura(Puentes());
    forjaDelGigante.agregarEstructura(CamposAbiertos());

    std:: cout << "----Elder Ring----" << std::endl;
    std:: cout << "[Presione enter para continuar]" << std::endl;
    std::cin.get();

    std :: cout << "Elige tu clase de Personaje:" << std::endl;

    std :: cout << "Elige una tierra (Selecciona un numero): " << std::endl;
    std :: cout << "1) Caelid" << std::endl;
    std :: cout << "2) Necrolimbo" << std::endl;
    std :: cout << "3) Ciudad Eterna" << std::endl;
    std :: cout << "4) Forja del Gigante" << std::endl;
    std :: cin >> opcion;
}
