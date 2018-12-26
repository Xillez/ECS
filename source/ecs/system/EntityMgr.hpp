#pragma once
#include "typedef.hpp"
#include "../entity/Entity.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

// ################################################################################################
// #                                                                                              #
// #                                       Entity Management                                      #
// #                                                                                              #
// ################################################################################################

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
    EntityID CreateEntity()
    {
        if (std::is_base_of<Entity, Tclass>::value)     // Does class extend Entity?
        {
            EntityID tempID = this->NextID();       // Ready for next entity registration.
            Entity* temp = new Tclass(tempID);      // Make new Entity with new ID.
            this->entityIDs.push_back(tempID);      // Add id.
            this->entities[tempID] = temp;          // Save entity pointer.
            temp = nullptr;
            return this->entities[tempID]->GetID(); // Return the new entities id.
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
    Entity* GetEntityByID(EntityID id);

    /**
     * @brief Get the Entity ID.
     * 
     * @param entity - entity to get id of.
     * 
     * @return EntityID - ID of entity. 0 if not found.
     */
    EntityID GetEntityID(Entity* entity);

    /**
     * @brief Get the Entity By Type
     * 
     * @tparam Tclass - Class extending Entity.
     * 
     * @return std::vector<Entity> 
     */
    template<class Tclass>    
    std::vector<Entity> GetEntityByType();


    /**
     * @brief Removes an entity by ID, all components without an owner gets removed aswell.
     * 
     * @param id - ID of entity to be removed.
     */
    void DestroyEntityByID(EntityID id);

    /**
     * @brief A built-in ForEachEntity loop calling given function for every object registered (with respective id).
     * 
     * @param func - Function to call for each object. Function signature: void(*func)(EntityID, Entity*).
     */
    void ForEachEntity(std::function<void(EntityID, Entity*)> func);

    /**
     * @brief Draw all entities. 
     */
    void DrawAllEntities();

    /**
     * @brief Update all entities.
     * 
     * @param dt - How many seconds since last update/frame.
     */
    void Update(float dt);

    /**
     * @brief Destroys all entities and readys for destruction.
     * 
     * @return true - All Entities was destroyed.
	 * @return false - Failed to destroy entities. 
     */
    bool DestroyAll();

    /**
     * @brief Function for increasing next entity id. DO NOT USE.
     * 
     * @return int 
     */
    EntityID NextID()
    {
        return nextID++;
    }

protected:
    //
private:
    std::vector<EntityID> entityIDs;      //!< A vector of all entities registered.
    std::unordered_map<EntityID, Entity*> entities;     //!< A unordered map mapping entities to ids.

    EntityID nextID;

// ################################################################################################
// #                                                                                              #
// #                                     Component Management                                     #
// #                                                                                              #
// ################################################################################################

    /**
     * @brief Create new Component. The component's id goes from 2 and upwards. 1 is Player component id.
     * 
     * @tparam Class - The ubclass of Component.
     * 
     @return ComponentID - The ID to the newly created component.
     */
    //template<typename Class>
    //ComponentID CreateComponent();

    /**
     * @brief Get the Component by ID.
     * 
     * @param id - Id of given component.
     * 
     * @return Component* - Pointer to component found. If nothing found, nullptr returned.
     */
    //Component* GetComponentByID(ComponentID id);

    /**
     * @brief Get the Component ID.
     * 
     * @param component - Component to get id of.
     * 
     * @return ComponentID - ID of component. 0 if not found.
     */
    //ComponentID GetComponentID(Component* component);

    /**
     * @brief Removes an component by ID, all components without an owner gets removed aswell.
     * 
     * @param id - ID of component to be removed.
     */
    //void RemoveComponentByID(ComponentID id);
protected:
    //
private:
    /*int nextID = INPUT_COMPONENT_ID + 1;

    std::vector<ComponentID> componentIDs;      //!< A vector of all components registered.
    std::unordered_map<ComponentID, Component*> components;     //!< A unordered map, mapping components to ids.*/
};