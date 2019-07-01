#pragma once

#include <vector>
#include "System.h"
#include "../Components/TransformComponent.h"
#include "../Components/PhysicsComponent.h"

class MovementSystem : System<TransformComponent, PhysicsComponent> {

public:
    MovementSystem();

    void Update();
};