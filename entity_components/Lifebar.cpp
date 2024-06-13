//
// Created by Badi on 6/11/2024.
//

#include "Lifebar.h"

Lifebar::Lifebar(int hp_value) {
    max_value = hp_value;
}

Lifebar::Lifebar(int hp_value, int bar_count) {
    max_value = hp_value;
    bar_length = bar_count;
}

void Lifebar::deductHp(int amount) {
    if ((current_value - amount) < 0) {
        current_value = 0;
    } else {
        current_value -= amount;
    }
}


void Lifebar::addHp(int amount) {
    if ((current_value + amount) > max_value) {
        current_value = max_value;
    } else {
        current_value += amount;
    }
}

void Lifebar::displayLifebar() const {
    int filled_bars = (current_value * bar_length) / max_value;
    int empty_bars = bar_length - filled_bars;
    std::cout << "["
              << std::string(filled_bars, '|')
              << std::string(empty_bars, ' ')
              << "]";
}