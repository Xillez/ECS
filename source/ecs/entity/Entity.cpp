#include "Entity.hpp"

#include <iostream>

// ################ BaseEntity ################

bool BaseEntity::registerComponent(BaseComponent* component)
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



//auto BaseEntity::nextID() -> EntityID
//{
//	id++;
//}

// ################ Entity ################
Entity::Entity()
{
	//
}

auto Entity::update() -> void
{
	//
}

auto Entity::draw() -> void
{
	std::cout << "Entity!\n";
}