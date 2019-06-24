#include "EntityManager.h"


EntityManager::EntityManager() {
    
}

void EntityManager::Update() {
    for (System* system : systems) {
        system->Update();
    };
        
        
}

EntityId EntityManager::CreateEntity() {
    entities.emplace(Entity(entityId));
    entityId++;
}

void EntityManager::DestroyEntity(EntityId entityId) {
    entities.erase(entityId);
}
