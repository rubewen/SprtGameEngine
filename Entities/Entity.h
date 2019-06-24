#pragma once

#include <vector>
#include "../Types.h"

class Component;

class Entity {
    EntityId id;
    std::vector<Component> components;

public:
    Entity(EntityId id) {
        this->id = id;
    };

    Entity(EntityId id, Component components[]) {
        this->id = id;
        this->components.emplace_back(components);
    };

    void AddComponent(Component component);

    void RemoveComponent(Component component);

    void Instantiate(Vector2f position);
};