// EntityManager.h
#pragma once
#include <iostream>
#include <vector>
#include "Components/Component.h"
#include "Systems/BaseSystem.h"
#include "Entities/Entity.h"
#include "../Types.h"


class EntityManager {
private:
    EntityId entityId;

    std::vector<Entity> entities;
    std::vector<Component> components;
    std::vector<BaseSystem> systems;

public:
    static EntityManager& getInstance();

    void Update();

    Entity CreateEntity();

    void DestroyEntity(EntityId entityId);

private:
    EntityManager();

    // Ikke lov å instansiere en kopi av EntityManager:
    EntityManager(EntityManager const&) = delete;
    void operator=(EntityManager const&) = delete;
};

