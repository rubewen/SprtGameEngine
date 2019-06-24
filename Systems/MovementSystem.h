#pragma once

#include <vector>
#include "System.h"
#include "../Components/TransformComponent.h"
#include "../Components/RenderComponent.h"

class MovementSystem : System<TransformComponent, RenderComponent> {

public:
    MovementSystem();

    void Update() override;
};