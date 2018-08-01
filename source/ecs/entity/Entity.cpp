#include "Entity.hpp"

#include <iostream>

// ################ Entity ################

Entity::Entity()
{
	//
}

bool Entity::registerComponent(Component* component)
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

void Entity::update()
{
	//
}

void Entity::draw()
{
	std::cout << "Entity!\n";
}

void Entity::remove()
{
	//
}

