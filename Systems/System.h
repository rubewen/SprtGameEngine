#pragma once

#include <vector>
#include <tuple>
#include "../Types.h"
#include "../Components/Component.h"

// Når vi arver av denne klassen kan vi angi hvilke Components systemet skal ha (f.eks. RenderSystem<TransformComponent, RenderComponent>)
template <class... Components>
class System : BaseSystem {
protected:
    // En tuple er på en måte en liste med forskjellige typer per element
    using ComponentTuple = std::tuple<std::add_pointer_t<Components>...>;
    // Et system har en liste forskjellige typer Component-lister:
    std::vector<ComponentTuple> components;


    // Har ikke en konstruktør i denne klassen, siden vi ikke ønsker å kunne opprette objekt av denne klassen, men heller av de klassene som arver fra denne
};