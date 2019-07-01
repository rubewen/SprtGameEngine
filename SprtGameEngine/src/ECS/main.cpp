#include <iostream>
#include "EntityManager.h"

/*
1. Ny Entity opprettes
2. RenderSystem vil vite om Entity har de to komponents som den trenger (Transform & Render)
3. Hvis den nye Entity inneholder TransformComponent OG RenderComponent:
    RenderSystem vil da lagre referanse til disse to KOMPONENTENE i sin liste over komponenter den styrer
*/

int main() {
    EntityManager entityManager;

    Entity entity1 = entityManager.CreateEntity();
    Entity entity2 = entityManager.CreateEntity();
    Entity entity3 = entityManager.CreateEntity();

    std::cout << "Entity 1 id: " << std::endl;
    std::cout << entity1.GetId() << std::endl;
    std::cout << "Entity 2 id: " << std::endl;
    std::cout << entity2.GetId() << std::endl;
    std::cout << "Entity 3 id: " << std::endl;
    std::cout << entity3.GetId() << std::endl;
    system("pause");
};