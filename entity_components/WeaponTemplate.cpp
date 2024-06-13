//
// Created by Badi on 6/13/2024.
//

#include "WeaponTemplate.h"

struct AxeInfo {
    static constexpr const char* damageType = "physical";
};

struct SwordInfo {
    static constexpr const char* damageType = "physical";
};

struct BowInfo {
    static constexpr const char* damageType = "physical";
};

struct WandInfo {
    static constexpr const char* damageType = "magical";
};

struct MazeInfo {
    static constexpr const char* damageType = "physical";
};

struct DaggerInfo {
    static constexpr const char* damageType = "physical";
};

struct KatanaInfo {
    static constexpr const char* damageType = "physical";
};
struct ScepterInfo {
    static constexpr const char* damageType = "magical";
};

struct StaffInfo {
    static constexpr const char* damageType = "magical";
};

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
