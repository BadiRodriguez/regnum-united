    //
// Created by Badi on 6/13/2024.
//

#ifndef REGNUM_UNITED_ENTITY_H
#define REGNUM_UNITED_ENTITY_H


struct Entity{ // Super-class that will mother all other character types of the game;
    bool interaction_status; // Single variable to distinguish playable from non-playable characters
                            // true means that it is a playable character
                            // false means that it is NOT a playable character
    bool is_playable() const {
        return interaction_status;
    }
    void setInteraction_status(bool status){
        interaction_status = status;
    };
};


#endif //REGNUM_UNITED_ENTITY_H
