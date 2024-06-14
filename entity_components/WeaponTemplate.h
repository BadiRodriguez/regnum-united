//
// Created by Badi on 6/13/2024.
//

#ifndef REGNUM_UNITED_WEAPONTEMPLATE_H
#define REGNUM_UNITED_WEAPONTEMPLATE_H

# include <iostream>
# include "Weapon.h"

template<typename WeaponType>
class WeaponTemplate: public Weapon{
public:
    WeaponTemplate(std::string name, int damage, int value) : Weapon(std::move(name), damage, value, WeaponType::damageType) {};
};

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

#endif //REGNUM_UNITED_WEAPONTEMPLATE_H
