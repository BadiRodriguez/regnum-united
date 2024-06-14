//
// Created by User on 14/06/2024.
//

#ifndef REGNUM_UNITED_STRUCTURES_H
#define REGNUM_UNITED_STRUCTURES_H

#include <iostream>
#include <string>

class Structures {
protected:
    std::string name;
public:
    explicit Structures(const std::string& name) : name(name) {}

    virtual void printName() const {
        std::cout << "These are the " << name << std::endl;
    }

    virtual ~Structures() = default; // Always good practice to have a virtual destructor in a base class
};

class Cuevas : public Structures {
public:
    Cuevas() : Structures("Cuevas") {}
};

class Tuneles : public Structures {
public:
    Tuneles() : Structures("Tuneles") {}
};

class Catacumbas : public Structures {
public:
    Catacumbas() : Structures("Catacumbas") {}
};

class Puentes : public Structures {
public:
    Puentes() : Structures("Puentes") {}
};

class CamposAbiertos : public Structures {
public:
    CamposAbiertos() : Structures("Campos Abiertos") {}
};

#endif //REGNUM_UNITED_STRUCTURES_H
