#pragma once

#include <cassert>
#include <memory>

#include "BaseGameRules.h"
#include "ClassicGameRules.h"
#include "BigBangGameRules.h"

class RulesFactory
{
public:
    static std::unique_ptr<BaseGameRules> generateRules(Rules rulesType)
    {
        switch (rulesType)
        {
        case Rules::Classic:
            return std::make_unique<ClassicGameRules>();

        case Rules::BigBang:
            return std::make_unique<BigBangGameRules>();

        default:
            assert(false);
            return nullptr;
        }
    }
};