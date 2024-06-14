//
// Created by Badi on 6/13/2024.
//

#ifndef REGNUM_UNITED_ITEM_H
#define REGNUM_UNITED_ITEM_H


class Item {
private:
    bool is_equippable;
    bool is_consumable;
public:
    // Constructors
    Item();
    Item(bool equippable_status, bool consumable_status)
    {is_equippable = equippable_status;
     is_consumable = consumable_status;};

    // Methods
    bool isEquippable() {return is_equippable;} // Getter for whether the item is equippable or not;
    bool isConsumable() {return is_consumable;} // Getter for whether the item is consumable or not;
};


#endif //REGNUM_UNITED_ITEM_H
