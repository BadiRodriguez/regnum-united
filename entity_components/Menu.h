#ifndef MENU_H
#define MENU_H

#include <vector>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <limits>

template <typename... Funcs>
void Menu(const std::vector<std::string>& options, Funcs... funcs) {
    std::vector<std::function<void()>> functions = {funcs...};

    if (options.size() != functions.size()) {
        throw std::invalid_argument("Number of options and functions must match");
    }

    int choice;
    while (true) {
        std::cout << "Select an option:\n";
        for (int index = 0; index < options.size(); ++index) {
            std::cout << index + 1 << ") " << options[index] << "\n";
        }
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > static_cast<int>(functions.size())) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid choice! Please try again.\n";
        } else {
            if (options[choice - 1] == "Volver al menú principal") {
                break; // Exit the menu loop to return to the main menu
            }
            functions[choice - 1]();
        }
    }
}

#endif // MENU_H
