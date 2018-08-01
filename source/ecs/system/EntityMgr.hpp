#pragma once
#include "typedef.hpp"
#include "../entity/Entity.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>

#define PLAYER_ENTITY_ID 1

/**
 * @brief Entity manager class. Manages entities.
 */
class EntityMgr
{
public:
    /**
     * @brief Constructor of EntityMgr.
     */
    EntityMgr();

    /**
     * @brief Create new Entity. The entity's id goes from 2 and upwards. 1 is Player entity id.
     * 
     * @return EntityID - The ID to the newly created entity.
     */
    EntityID createEntity();

    /**
     * @brief Get the Entity by ID
     * 
     * @param id - id of given entity
     * 
     * @return Entity* - Pointer to entity found. If nothing found, nullptr returned.
     */
    Entity* getEntityByID(EntityID id);

    /**
     * @brief Get the Entity ID
     * 
     * @param entity - entity to get id of.
     * 
     * @return EntityID - ID of entity. 0 if not found.
     */
    EntityID getEntityID(Entity* entity);

    /**
     * @brief Removes an entity by ID, all components without an owner gets removed aswell.
     * 
     * @param id - ID of entity to be removed.
     */
    void removeEntityByID(EntityID id);
protected:
    //
private:
    int nextID = PLAYER_ENTITY_ID + 1;

    std::vector<EntityID> entityIDs;      //!< A vector of all entities registered.
    std::unordered_map<EntityID, Entity*> entities;     //!< A unordered map mapping entities to ids.
};
