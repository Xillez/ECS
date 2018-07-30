#include "Component.hpp"

#include "../system/EntityMgr.hpp"

Component::Component()
{
	//
}

void Component::init(const EntityID& parent)
{
	this->parentID = parent;
}

// Virtual.
void Component::update(float dt)
{
    //
}

// Virtual.
void Component::draw()
{
    //
}

ComponentID Component::getId()
{
    return this->id;
}