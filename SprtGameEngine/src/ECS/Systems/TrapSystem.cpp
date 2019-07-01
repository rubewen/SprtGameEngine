#include "TrapSystem.h"


TrapSystem::TrapSystem() {
    
}

void TrapSystem::ActivateTrap() {
    for (auto& componentTuple: components) {
        TransformComponent* transform = std::get<TransformComponent*>(componentTuple);
        PhysicsComponent* physics = std::get<PhysicsComponent*>(componentTuple);
    };
}

void TrapSystem::Update() {
    
}
