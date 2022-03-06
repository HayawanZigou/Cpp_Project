#pragma once

#include <unordered_set>

namespace GL {

class DynamicObject
{
public:
    virtual ~DynamicObject() {};
    
    // TASK-0 C-4: retirer un avion.
    // Pour savoir si un avion doit être retiré, on fait en sorte que move renvoie un booleen.
    virtual bool move() = 0;
};

inline std::unordered_set<DynamicObject*> move_queue;

} // namespace GL
