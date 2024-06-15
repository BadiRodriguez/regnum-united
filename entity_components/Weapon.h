#ifndef REGNUM_UNITED_WEAPON_H
#define REGNUM_UNITED_WEAPON_H

#include <iostream>
#include <string>
#include <utility>

class Weapon { // Super-class that will define all weapons that can be obtained in the game. Worn by player characters and foes alike.
private:
    std::string name;
    int damage;
    int price;
    std::string damage_type; // This price can only be physical or magical (Physical is repelled with defense, Magical with magical defense.)
public:
    // Constructors
    Weapon() = default;
    Weapon(std::string _name, int _damage, int _price, std::string _damage_type);

    // Getters
    std::string getDamageType() const { return damage_type; }
    int getDamage() const { return damage; }
    std::string getName() const { return name; }
    int getPrice() const { return price; }

    // Additional method
    virtual void describe() const;

    // Overload the << operator for the Weapon class
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "Weapon: " << weapon.name << ", Damage: " << weapon.damage << ", Price: " << weapon.price << ", Damage Type: " << weapon.damage_type;
        return os;
    }
};

#endif //REGNUM_UNITED_WEAPON_H

