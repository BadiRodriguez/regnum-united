#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

class Structures {
protected:
    std::string name;

public:
    virtual ~Structures() = default;
    std::string getName() const { return name; } // Marking getName as const
};

class CamposAbiertos : public Structures {
public:
    CamposAbiertos() { name = "Campos Abiertos"; }
};

class Cuevas : public Structures {
public:
    Cuevas() { name = "Cuevas"; }
};

class Puentes : public Structures {
public:
    Puentes() { name = "Puentes"; }
};

class Catacumbas : public Structures {
public:
    Catacumbas() { name = "Catacumbas"; }
};

#endif // STRUCTURES_H
