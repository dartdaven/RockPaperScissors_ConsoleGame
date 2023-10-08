#include "RulesFactory.h"

#include <cassert>

#include "../Rules/ClassicGameRules.h"
#include "../Rules/BigBangGameRules.h"

std::unique_ptr<BaseGameRules> RulesFactory::generateRules(Rules rulesType)
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
