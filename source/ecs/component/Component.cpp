#include "Component.hpp"

Component::Component(ComponentID id) : ID(id)
{
	//
}

void Component::init(const EntityID& parent)
{
	this->parentID = parent;

}

// Virtual
void Component::update(float dt)
{
    //
}

// Virtual
void Component::draw()
{
    //
}

// Virtual
void Component::remove()
{
    //
}

ComponentID Component::getID()
{
    return this->ID;
}