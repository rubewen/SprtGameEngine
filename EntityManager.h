// EntityManager.h
#pragma once
#include <iostream>
#include <vector>
#include "Types.h"
#include "Components/Component.h"
#include "Systems/BaseSystem.h"
#include "Entities/Entity.h"
#include "Types.h"


class EntityManager {
private:
    std::vector<Entity> entities;
    std::vector<Component> components;
    std::vector<BaseSystem> systems;

public:
    static EntityId entityId;

    EntityManager();

    void Update();

    Entity CreateEntity();

    void DestroyEntity(EntityId entityId);
};