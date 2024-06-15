#ifndef REGNUM_UNITED_ITEM_H
#define REGNUM_UNITED_ITEM_H

#include <iostream>
#include <string>


class Item {
private:
    int hdsd;
    bool is_equippable;
    bool is_consumable;
public:
    // Constructores
    Item() : hdsd(0), is_equippable(false), is_consumable(false) {}
    Item(int hdsd, bool equippable_status, bool consumable_status)
            : hdsd(hdsd), is_equippable(equippable_status), is_consumable(consumable_status) {}

    // Métodos getters
    bool isEquippable() const { return is_equippable; }
    bool isConsumable() const { return is_consumable; }

    // Métodos de acción
    void damage(int value) {
        hdsd -= value;
        std::cout << "Damage: " << value << ", HDSD now: " << hdsd << std::endl;
    }

    void defense(int value) {
        hdsd += value;
        std::cout << "Defense: " << value << ", HDSD now: " << hdsd << std::endl;
    }

    void strength(int value) {
        hdsd += value;
        std::cout << "Strength: " << value << ", HDSD now: " << hdsd << std::endl;
    }

    void health(int value) {
        hdsd += value;
        std::cout << "Health: " << value << ", HDSD now: " << hdsd << std::endl;
    }
};

#endif //REGNUM_UNITED_ITEM_H