// EntityManager.h
#pragma once
#include <iostream>
#include <vector>

#include "Entity.h"
#include "Component.h"
#include "System.h"

static class EntityManager {
private:
    static EntityId entityId;

    std::vector<Entity> entities;
    std::vector<Component> components;
    std::vector<System> systems;

public:
    EntityManager();

    EntityId CreateEntity() {
        entities.emplace(Entity(entityId));
        entityId++;
    };

    void DestroyEntity(EntityId entityId) {
        entities.erase(entityId);
    };
};