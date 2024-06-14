cmake_minimum_required(VERSION 3.28)
project(Regnum_United)

set(CMAKE_CXX_STANDARD 20)

add_executable(Regnum_United main.cpp
        entity_components/Character.cpp
        entity_components/Character.h
        entity_components/Lifebar.cpp
        entity_components/Lifebar.h
        entity_components/Weapon.cpp
        entity_components/Weapon.h
        entity_components/WeaponTemplate.cpp
        entity_components/WeaponTemplate.h
        entity_components/Class.cpp
        entity_components/Class.h
        entity_components/Entity.cpp
        entity_components/Entity.h
        entity_components/Item.cpp
        entity_components/Item.h
        entity_components/weapons_list.cpp
        entity_components/Skill.cpp
        entity_components/Skill.h
        entity_components/Spell.cpp
        entity_components/Spell.h)
