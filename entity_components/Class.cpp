#include "Class.h"

std::string Class::get_range_type() const {
    return range_type;
}

void Class::describe() const {
    std::cout << "Class " << name << ", Range Type: " << range_type << std::endl;
}
