#include "EntityManager.h"

EntityManager::EntityManager() {
    std::cout << "EntityManager Created" << std::endl;
}

void EntityManager::Update() {
    // for (BaseSystem system : systems) {
    //     system.Update();
    // };
}

Entity EntityManager::CreateEntity() {
    Entity entity(EntityManager::entityId);
    // entities.emplace_back(entity);
    entityId++;
    return entity;
}

void EntityManager::DestroyEntity(EntityId entityId) {
    // entities.erase(entityId);
}
