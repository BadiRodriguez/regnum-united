//
// Created by Badi on 6/13/2024.
//

#ifndef REGNUM_UNITED_ENTITY_H
#define REGNUM_UNITED_ENTITY_H

struct Entity {
    bool interaction_status; // Single variable to distinguish playable from non-playable characters

    // Default constructor
    Entity() : interaction_status(false) {}

    // Constructor with bool parameter
    Entity(bool status) : interaction_status(status) {}

    virtual ~Entity() = default; // Virtual destructor for polymorphism

    bool is_playable() const {
        return interaction_status;
    }
    void setInteraction_status(bool status) {
        interaction_status = status;
    }
};

#endif // REGNUM_UNITED_ENTITY_H
