#include "Entity.hpp"

#include <iostream>

// ################ Entity ################

Entity::Entity()
{
	//
}

bool Entity::registerComponent(BaseComponent* component)
{
	// If this is a valid component
	if (component)
	{
		// Add parent / initialize with current object as parent
		//component->init(this);
		// Add it to current Entitys component list
		this->componentList.push_back(component);
	}

	// Tell whether it was added or nots
	return (component);
}

auto Entity::update() -> void
{
	//
}

auto Entity::draw() -> void
{
	std::cout << "Entity!\n";
}

