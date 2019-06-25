#pragma once

#include "../Entities/Entity.h"

class Component {
protected:
    Entity entity;


public:
    Component();

    void Enable();

    void Disable();

};