//
// Created by User on 14/06/2024.
//

#ifndef REGNUM_UNITED_ITEMTEMPLATE_H
#define REGNUM_UNITED_ITEMTEMPLATE_H

#include <iostream>
#include "Item.h"

template<typename ItemType>

class ItemTemplate : public Item {
public:
    ItemTemplate(int hdsd, bool equippable_status, bool consumable_status)
            : Item(hdsd, equippable_status, consumable_status) {}
};

// Estructura para la informaci贸n de HealthPotion
struct HealthPotionInfo : public Item {
    static constexpr bool equipable_status_value = false;
    static constexpr const bool* equipable_status = &equipable_status_value;

    static constexpr bool consumable_status_value = true;
    static constexpr const bool* consumable_status = &consumable_status_value;

    HealthPotionInfo(int hdsd)
            : Item(hdsd, *equipable_status, *consumable_status) {}
};

// Estructura para la informaci贸n de PoisonPotion
struct PoisonPotionInfo : public Item {
    static constexpr bool equipable_status_value = false;
    static constexpr const bool* equipable_status = &equipable_status_value;

    static constexpr bool consumable_status_value = true;
    static constexpr const bool* consumable_status = &consumable_status_value;

    PoisonPotionInfo(int hdsd)
            : Item(hdsd, *equipable_status, *consumable_status) {}

    void damage(int value) {
        Item::damage(value);
    }
};

// Estructura para la informaci贸n de DefensePotion
struct DefensePotionInfo : public Item {
    static constexpr bool equipable_status_value = false;
    static constexpr const bool* equipable_status = &equipable_status_value;

    static constexpr bool consumable_status_value = true;
    static constexpr const bool* consumable_status = &consumable_status_value;

    DefensePotionInfo(int hdsd)
            : Item(hdsd, *equipable_status, *consumable_status) {}
};

// Estructura para la informaci贸n de StrengthPotion
struct StrengthPotionInfo : public Item {
    static constexpr bool equipable_status_value = false;
    static constexpr const bool* equipable_status = &equipable_status_value;

    static constexpr bool consumable_status_value = true;
    static constexpr const bool* consumable_status = &consumable_status_value;

    StrengthPotionInfo(int hdsd)
            : Item(hdsd, *equipable_status, *consumable_status) {}
};
#endif //REGNUM_UNITED_ITEMTEMPLATE_H
