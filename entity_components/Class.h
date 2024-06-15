//
// Created by Badi on 6/13/2024.
//

#ifndef REGNUM_UNITED_CLASS_H
#define REGNUM_UNITED_CLASS_H

#include <iostream>

class Class {
private:
    std::string name;
    std::string range_type;

public:
    Class() = default;
    Class(std::string _name, std::string _range_type) : name(std::move(_name)), range_type(std::move(_range_type)) {}

    std::string get_range_type() {
        return range_type;
    }

    virtual void describe() const {
        std::cout << "Class " << name << ", Range Type: " << range_type << std::endl;
    }

    // Overload the << operator for the Profession class
    friend std::ostream& operator<<(std::ostream& os, const Class& profession) {
        os << "Class " << profession.name << ", Range type: " << profession.range_type;
        return os;
    }
};
};


#endif //REGNUM_UNITED_CLASS_H
