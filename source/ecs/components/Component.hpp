#pragma once

typedef unsigned int ComponentID;

class BaseComponent
{
public:
	/**
	 * @brief initialize function to give component parent object for updating and possibly drawing.
	 *  
	 * @param parent - Parent object I exists inside.
	 */
	virtual auto init(void* parent) -> void;

	/**
	 * @brief Update function for components. 
	 */
	virtual auto update(float dt) -> void = 0;

	/**
	 * @brief Draw the mesh on the screen.
	 */
	virtual auto draw() -> void = 0;

	
private: 
	const ComponentID id;
	unsigned int parentID;		//!< Parent object exists inside.
};

class TestComponent : public BaseComponent
{
public:
	TestComponent();

private:
	float x, y;
};

