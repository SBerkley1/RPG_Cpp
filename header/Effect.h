#pragma once
#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <memory>

#include "Ability.h"

struct Effect {
    string name = "";
    string description = "";
    int damageBonus = 0;
    int effectRounds = 0;
   
    int getDamageBonus() const { return damageBonus; }
    int getEffectRounds() const { return effectRounds; }
  
    
    std::string getEffectName() const {
       return name;
    }

    std::string getEffectDescription() const {
        return description;
    }

   
};

#endif // EFFECT_H