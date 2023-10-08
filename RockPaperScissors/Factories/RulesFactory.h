#pragma once

#include <memory>

#include "../Rules/BaseGameRules.h"

class RulesFactory
{
public:
    static std::unique_ptr<BaseGameRules> generateRules(Rules rulesType);
};