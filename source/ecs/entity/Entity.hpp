#pragma once

#include "../components/Component.hpp"

#include <stdio.h>
#include <string>
#include <vector>

typedef unsigned int EntityID;

template<typename T>
class BaseEntity
{
public:
	/**
	 * @brief Constructor for BaseEntity
	 * 
	 * @param component 
	 * @return true 
	 * @return false 
	 */
	BaseEntity();

	/**
	 * @brief A function for registering components.
	 * 
	 * @param component - component added to current object.
	 * 
	 * @return true if added, false otherwise
	 */
	bool registerComponent(BaseComponent* component);
	
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

	std::vector<BaseComponent*> componentList;

	//static EntityID nextID();
};

/**
 * @brief Generic Entity with components.
 */
class Entity : public BaseEntity<Entity>
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
	 * @brief updates state for next frame.
	 */
	void update();

	/**
	 * @brief Draw the entity and possible subcomponents.
	 */

	void draw();
			
private:
	//
};
