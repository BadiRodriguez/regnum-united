//
// Created by Badi on 6/11/2024.
//

#ifndef REGNUM_UNITED_LIFEBAR_H
#define REGNUM_UNITED_LIFEBAR_H

#include <iostream>
#include <string>

class Lifebar {
private:
    int max_value;
    int bar_length = 20;
    int current_value = max_value;
public:
    // Constructors
    Lifebar() = default;
    explicit Lifebar(int);
    Lifebar(int, int);

    void deductHp(int);
    void addHp(int);
    void displayLifebar() const;

    // Setters
    void setCurrentValue(int value){ current_value = value; }

    // Getters
    int getCurrentValue() const { return current_value; }
    int getMaxValue() const { return max_value; }

};

#endif //REGNUM_UNITED_LIFEBAR_H
