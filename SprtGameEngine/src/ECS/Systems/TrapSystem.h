#pragma once

#include <vector>
#include "System.h"
#include "../Components/TransformComponent.h"
#include "../Components/PhysicsComponent.h"

class TrapSystem : System<TransformComponent, PhysicsComponent> {

public:
    TrapSystem();


    // Aktiver felle dersom en Entity med mass > 5kg står ved posisjon x=3, y=5 f.eks.
    void ActivateTrap();

    void Update();
};