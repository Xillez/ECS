#pragma once
#include "../system/typedef.hpp"

/**
 * @brief Base class for components. To make component, make new class extendng from this one. 
 */
class Component
{
public:
	/**
	 * @brief Constructor of Component.
	 */
	Component();

	/**
	 * @brief initialize function to give component parent object for updating and possibly drawing.
	 *  
	 * @param parent - Parent object I exists inside.
	 */
	virtual void init(const EntityID& parent);

	/**
	 * @brief Update function for components. 
	 */
	virtual void update(float dt);

	/**
	 * @brief Draw the mesh on the screen.
	 */
	virtual void draw();

	/**
	 * @brief Make ready for removal. 
	 */
	virtual void remove();

	/**
	 * @brief Get the Component id.
	 * 
	 * @return ComponentID - The id of the component.
	 */
	ComponentID getId();
	
private: 
	ComponentID id;			//!< Component's id.
	EntityID parentID;		//!< Parent id exists inside.
};