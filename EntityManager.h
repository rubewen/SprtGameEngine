// EntityManager.h
#pragma once
#include <iostream>
#include <vector>

#include "Entities/Entity.h"
#include "Components/Component.h"
#include "Systems/System.h"

class EntityManager {
private:
    static EntityId entityId;

    std::vector<Entity*> entities;
    std::vector<Component*> components;
    // std::vector<System*> systems;

public:
    EntityManager();

    void Update();

    EntityId CreateEntity();

    void DestroyEntity(EntityId entityId);
};