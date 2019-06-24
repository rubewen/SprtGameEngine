#include "MovementSystem.h"


MovementSystem::MovementSystem() {
    
}

void MovementSystem::Update() {
    for (auto& componentTuple: components) {
        TransformComponent* transform = std::get<TransformComponent*>(componentTuple);
        RenderComponent* renderer = std::get<RenderComponent*>(componentTuple);
    };
};
