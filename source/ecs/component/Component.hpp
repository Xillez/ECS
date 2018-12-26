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
	 * 
	 * @param id - Id of new component.
	 */
	Component(ComponentID id);

	/**
	 * @brief initialize function to give component parent object for updating and possibly drawing.
	 *  
	 * @param parent - Parent object I exists inside.
	 */
	virtual void Initialize(const EntityID& parent);

	/**
	 * @brief Update function for components. 
	 */
	virtual void Update(float dt);

	/**
	 * @brief Draw the mesh on the screen.
	 */
	virtual void Draw();

	/**
	 * @brief Make ready for removal. 
	 */
	virtual void Destroy();

	/**
	 * @brief Get the Component id.
	 * 
	 * @return ComponentID - The id of the component.
	 */
	ComponentID GetID();
	
private: 
	const ComponentID ID;			//!< Component's id.
	EntityID parentID;		//!< Parent id exists inside.
};