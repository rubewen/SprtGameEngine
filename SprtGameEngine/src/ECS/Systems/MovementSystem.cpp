#include "MovementSystem.h"


MovementSystem::MovementSystem() {
    
}

void MovementSystem::Update() {
    for (auto& componentTuple: components) {
        TransformComponent* transform = std::get<TransformComponent*>(componentTuple);
        PhysicsComponent* physics = std::get<PhysicsComponent*>(componentTuple);
    };
};
