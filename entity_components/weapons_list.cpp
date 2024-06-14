//
// Created by Badi on 6/13/2024.
//

#include "WeaponTemplate.h"

// Define specific weapon types using the templated class
using Axe = WeaponTemplate<AxeInfo>;
using Sword = WeaponTemplate<SwordInfo>;
using Bow = WeaponTemplate<BowInfo>;
using Wand = WeaponTemplate<WandInfo>;
using Maze = WeaponTemplate<MazeInfo>;
using Dagger = WeaponTemplate<DaggerInfo>;
using Katana = WeaponTemplate<KatanaInfo>;
using Scepter = WeaponTemplate<ScepterInfo>;
using Staff = WeaponTemplate<StaffInfo>;

void renderWeapons() {

    Sword S1("Bronze sword", 10, 12);
    Sword S2("Iron sword", 15, 22);
    Sword S3("Steel sword", 18, 53);
    Sword S4("Chavez's edge", 25, 170);
    Axe A1("Tin axe", 14, 15);
    Axe A2("Ferr-steel axe", 19, 26);
    Axe A3("Koktwo-Cleaver", 22, 66);
    Axe A4("Paca's saw", 29, 200);
    Maze M1("Wooden mace", 12, 11);
    Maze M2("Iron mace", 14, 32);
    Maze M3("Steel mace", 19, 55);
    Maze M4("Bellringer's Club", 27, 210);
    Dagger D1("Kitchen knife", 5, 7);
    Dagger D2("Serrated dagger", 9, 16);
    Dagger D3("Killing edge", 11, 29);
    Dagger D4("The Answerer", 15, 59);
    Bow B1("Wooden bow", 11, 11);
    Bow B2("Steel-reinforced bow", 13, 23);
    Bow B3("Reinflenche", 15, 54);
    Bow B4("Flauta's bow", 64, 1864);
    Katana K1("Brass katana", 11, 14);
    Katana K2("Iron katana", 13, 21);
    Katana K3("Steel-saint katana", 16, 49);
    Katana K4("Cachimbos's Avenger", 24, 190);
    Wand W1("Old-tree wand", 10, 15);
    Wand W2("Varita divina", 13, 28);
    Wand W3("Wand of wanding", 16, 49);
    Wand W4("Yggdrassil's root", 25, 71);
    Scepter C1("Appretience scepter", 5, 11);
    Scepter C2("Wooden scepter", 10, 23);
    Scepter C3("Sand scepter", 16, 46);
    Scepter C4("Sercenador divino", 28, 110);
    Staff T1("Appretience's staff", 3, 9);
    Staff T2("Steel-special staff", 6, 12);
    Staff T3("Studious staff", 9, 21);
    Staff T4("Master's rod", 12, 49);

}