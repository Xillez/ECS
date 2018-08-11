#pragma once

#include "../system/typedef.hpp"
#include "../component/Component.hpp"

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <functional>

/**
 * @brief Generic Entity with components.
 */
class Entity
{
public:
	/**
	 * @brief Entity constructor.
	 * 
	 * @param id - Id of new entity.
	 */
	Entity(EntityID id);

	/**
	 * @brief Entity deconstructor.
	 */
	virtual ~Entity();

	/**
	 * @brief Add a component.
	 * 
	 * @param id - component id to be registered.
	 * 
	 * @return true if added, false otherwise.
	 */
	virtual bool addComponent(ComponentID id);

	/**
	 * @brief updates state for next frame.
	 */
	virtual void update(float dt);

	/**
	 * @brief Draw the entity and possible subcomponents.
	 */
	virtual void draw();

	/**
	 * @brief Remove the entity and all associated components if not reused.
	 */
	virtual void remove();
	
	/**
	 * @brief A function for getting id.
	 * 
	 * @return id - id for entity.
	 */
	int getID();

protected:
	std::vector<ComponentID> componentIDs;	//!< List of Component IDs.	

private:
	const EntityID ID;						//!< Id of Entity.
};
