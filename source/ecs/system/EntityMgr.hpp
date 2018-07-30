#pragma once
#include "../entity/Entity.hpp"

#include <vector>

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
     * @brief Registers entity.
     * 
     * @param entity - A pointer to the entity to be registered.
     * 
     * @return true - the entity registered successfully.
     * @return false - the entity failed to register.
     */
    bool registerEntity(Entity* entity);
protected:
    //
private: 
    std::vector<Entity*> entities;      //!< A vector of all entities registered.
};
