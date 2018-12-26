#pragma once

#include "../system/typedef.hpp"
#include "../component/Component.hpp"

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>

#define DEFAULT_ENTITY_ID -1

/* TODO:
	- Make Entity EntityBase (maybe??)
	- Make GameObject class extend EntityBase (maybe??)
	- Implement PhysicsUpdate for physx compatibility.
 */

/**
 * @brief Generic Entity with components.
 */
class Entity// : BaseEntity
{
public:
	/**
	 * @brief Basic Entity constructur, Default Entity ID.
	 * !!Note!! Ment to be a temporary instantiation! Make sure you use Instantiate() to get legal id.
	 */
	Entity();

	/**
	 * @brief Entity constructor. Should NOT be used for new entity generation except for EntityMgr.
	 * 
	 * @param id - Id of new entity.
	 */
	Entity(EntityID id);

	/**
	 * @brief Entity deconstructor.
	 */
	virtual ~Entity();

	/**
     * @brief Create new Component with next local (to entity) component id.
     * 
     * @tparam Class - The subclass of Component.
     * 
     @return ComponentID - The ID to the newly created component.
     */
    template<typename Tclass>
    ComponentID CreateComponent()
	{
		//
	}

	/**
	 * @brief Get internal component on entity.
	 * 
	 * @tparam Tclass - Class extended from Component.
	 * 
	 * @return Component* - Pointer to internal component.
	 */
	template<class Tclass>
	Component* GetComponent()
	{
		//
	}

	/**
	 * @brief Get internal component on entity.
	 * 
	 * @tparam Tclass - Class extended from Component.
	 * 
	 * @return std::vector<Component*> - Vector of pointer to internal component.
	 */
	template<class Tclass>
	Component* GetComponents()
	{
		//
	}

	/**
	 * @brief Get the Component via ID
	 * 
	 * @param id - Id of the component you want.
	 * 
     * @return Component* - Pointer to component found. If nothing found, nullptr returned.
	 */
	virtual Component* GetComponentByID(ComponentID id);

	/**
     * @brief Removes an component by ID, all components without an owner gets removed aswell.
     * 
     * @param component - Pointer to component to be removed.
     */
    void RemoveComponent(Component* component);

	/**
     * @brief Removes an component by ID, all components without an owner gets removed aswell.
     * 
     * @param id - ID of component to be removed.
     */
    void RemoveComponentByID(ComponentID id);

	/**
	 * @brief Start function, called once at the very start of the lifecycle.
	 */
	virtual void Start();

	/**
	 * @brief Updates state for next frame.
	 */
	virtual void Update();

	/**
	 * @brief Physics update function for Entities.
	 */
	//virtual void PhysicsUpdate();	

	/**
	 * @brief Draw the entity and possible subcomponents.
	 */
	virtual void Draw();

	/**
	 * @brief Used for destroying an entity.
	 * 
	 * @return true - Entity was destroyed.
	 * @return false - Failed to destroy.
	 */
	virtual bool Destroy();

	/**
	 * @brief A function for getting id.
	 * 
	 * @return id - id for entity.
	 */
	virtual int GetID();

	/**
	 * @brief Get the name of the current class.
	 * 
	 * @return std::string - Name of the current class.
	 */
	virtual std::string GetClassName(bool removeDigit = true);

	/**
	 * @brief Get the name of the lowest class in the hierarchy.
	 * 
	 * @return std::string - Name of the lowest class in the hierarchy.
	 */
	virtual std::string GetLowestTypeName(bool removeDigit = true);

protected:
	std::vector<ComponentID> componentIDs;	//!< List of Component IDs.	

	//int nextID = INPUT_COMPONENT_ID + 1;


    //std::vector<ComponentID> componentIDs;      //!< A vector of all components registered.
    std::unordered_map<ComponentID, Component*> components;     //!< A unordered map, mapping components to ids.

private:
	EntityID ID;						//!< Id of Entity.

	ComponentID nextCompId = 0;

	void* mgr;							//!< Pointer back to EntityMgr.
};
