#pragma once

#include <vector>
#include "../Types.h"

class Component;

class Entity {
    std::vector<Component> components;
    EntityId id;

public:
    
    Entity(EntityId& id) : id(id) {
        std::cout << "Entity with id " << id << " created." << std::endl;
    };

    // Entity(EntityId id, std::vector<Component> components) {
    //     this->id = id;
    //     this->components.emplace_back(components);
    // };

    EntityId GetId() const {
        return id;
    }

    void AddComponent(Component component);

    void RemoveComponent(Component component);

    void Instantiate(Vector2f position);
};