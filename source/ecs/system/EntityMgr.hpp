#pragma once
#include "typedef.hpp"
#include "../entity/Entity.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

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
     * @tparam Class - The subclass of Entity to be made.
     * 
     * @return EntityID - The ID to the newly created entity.
     */
    template<class Tclass>       // In header because of cmake undefined error! DO NOT MOVE BACK!!
    EntityID createEntity()
    {
        if (std::is_base_of<Entity, Tclass>::value)     // Does class extend Entity?
        {
            Entity* temp = new Tclass(this->nextID);    // Make new Entity with new ID.
            this->entityIDs.push_back(this->nextID);    // Add id.
            this->entities[this->nextID] = temp;        // Save entity pointer.
            temp = nullptr;
            this->nextID++;                             // Ready for next entity registration.
            return this->nextID - 1;                    // Return the new entities id.
        }
        std::cout << "Accepts only Entity and subclasses of it!\n";
        return 0;
    }

    /**
     * @brief Get the Entity by ID.
     * 
     * @param id - id of given entity.
     * 
     * @return Entity* - Pointer to entity found. If nothing found, nullptr returned.
     */
    Entity* getEntityByID(EntityID id);

    /**
     * @brief Get the Entity ID.
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

    /**
     * @brief A built-in foreach loop calling given function for every object registered (with respective id).
     * 
     * @param func - Function to call for each object. Function signature: void(*func)(EntityID, Entity*).
     */
    void forEach(std::function<void(EntityID, Entity*)> func);

    /**
     * @brief Draw all entities. 
     */
    void drawAllEntities();

    /**
     * @brief Update all entities.
     * 
     * @param dt - How many seconds since last update/frame.
     */
    void update(float dt);

    /**
     * @brief Destroys all entities and readys for destruction.
     * 
     * @return true - All Entities was destroyed.
	 * @return false - Failed to destroy entities. 
     */
    bool destroyAll();

protected:
    //
private:
    int nextID = PLAYER_ENTITY_ID + 1;

    std::vector<EntityID> entityIDs;      //!< A vector of all entities registered.
    std::unordered_map<EntityID, Entity*> entities;     //!< A unordered map mapping entities to ids.
};
