#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <tuple>

template<int index = 0, typename... Types>
void displayMenu(const std::vector<std::string>& options, const std::tuple<Types...>& funcs) {
    if constexpr (index < sizeof...(Types)) {
        std::cout << index + 1 << ") " << options[index] << std::endl;
        displayMenu<index + 1>(options, funcs);
    }
}

template<int index = 0, typename... Types>
void selectOption(int selection, const std::tuple<Types...>& funcs) {
    if constexpr (index < sizeof...(Types)) {
        if (index == selection - 1) {
            auto func = std::get<index>(funcs); func();
        } else {
            selectOption<index + 1>(selection, funcs);
        }
    }
}

template<typename... Types>
void Menu(const std::vector<std::string>& options, Types... funcs) {
    if (options.size() != sizeof...(funcs)) {
        throw std::invalid_argument("Number of options and functions must match");
    }

    auto funcsTuple = std::make_tuple(funcs...);

    displayMenu(options, funcsTuple);

    std::cout << "Select an option: ";
    std::string input; std::cin >> input;
    try {
        int selection = stoi(input);
        if (0 < selection && selection <= options.size()) {
            selectOption(selection, funcsTuple);
        } else {
            std::cout << "Out of range option selected." << std::endl;
        }
    } catch (std::invalid_argument&) {
        std::cout << "Invalid option selected." << std::endl;
    }
}

#endif // MENU_H
