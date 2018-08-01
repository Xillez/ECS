#pragma once

#include "../system/typedef.hpp"
#include "../components/Component.hpp"

#include <stdio.h>
#include <string>
#include <vector>

/**
 * @brief Generic Entity with components.
 */
class Entity
{
public:
	
	/**
	 * @brief Entity constructor.
	 */
	Entity();

	/**
	 * @brief Entity deconstructor.
	 */
	~Entity();

	/**
	 * @brief A function for registering components.
	 * 
	 * @param component - component added to current object.
	 * 
	 * @return true if added, false otherwise
	 */
	bool registerComponent(Component* component);

	/**
	 * @brief updates state for next frame.
	 */
	virtual void update();

	/**
	 * @brief Draw the entity and possible subcomponents.
	 */
	virtual void draw();

	/**
	 * @brief Remove the entity and all associated components if not reused.
	 */
	virtual void remove();
	
	/**
	 * @brief A function for getting id
	 * 
	 * @return id - id for entity.
	 */
	int getID();
	
	/**
	 * @brief A function for setting id
	 * 
	 * @param id - requested id for entity.
	 */
	void setID(int id);

protected:
	static const EntityID id;

	std::vector<Component*> componentList;
			
private:
	//
};
