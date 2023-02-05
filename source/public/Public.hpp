#pragma once
#include "../lists/List.hpp"
#include "../ecs/component/Component.hpp"
#include "../ecs/entity/Entity.hpp"

namespace ECS
{
    // Anything public that should be acccesible for the entire program for now. Remake to dependency injector.
    ECS::List<EntityID> entityIDs;      //!< A vector of all entities registered.
    std::unordered_map<EntityID, Entity*> entities;     //!< A unordered map mapping entities to ids.
    ECS::List<ECS::Component> components = ECS::List<ECS::Component>();
}