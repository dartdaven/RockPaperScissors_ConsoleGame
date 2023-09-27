#pragma once

#include <memory>

#include "BaseGameRules.h"

class RulesFactory
{
public:
    static std::unique_ptr<BaseGameRules> generateRules(Rules rulesType);
};