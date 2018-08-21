#include "Entity.hpp"

#include <iostream>
#include <algorithm>

Entity::Entity(EntityID id) : ID(id)
{
	//
}

//virtual
Entity::~Entity()
{
	//
}

//virtual
bool Entity::addComponent(ComponentID id)
{
	auto it = std::find(this->componentIDs.begin(), this->componentIDs.end(), id);    // Does the id exist.
    if (it != this->componentIDs.end())            // Found component, delete it.
    {
        // Add parent / initialize with current object as parent.
		//component->init(this);
		// Add it to current Entity's component list.
		this->componentIDs.push_back(id);
    }

	// Tell whether it was added or not.
	return (id);
}

//virtual
void Entity::update(float dt)
{
	//
}

//virtual
void Entity::draw()
{
	std::cout << "Entity " << this->ID << ", ClassName: " << this->getClassName() << "!\n";
}

//virtual
void Entity::remove()
{
	//
}

int Entity::getID()
{
	return this->ID;
}

//virtual
std::string Entity::getClassName(bool removeDigits)
{
	std::string name = typeid(*this).name();	// Get dirty class name.
	if (removeDigits)							// Should remove digits?
	{
		int i = 0;
		while (isdigit(name.at(i))) i++;		// Find where digits end.
		name.erase(name.begin(), name.begin() + i);	// Remove digits.
	}
	return name;								// Return pretty name.
}

//virtual
bool Entity::destroy()
{
    return true;
}