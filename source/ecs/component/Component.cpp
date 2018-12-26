#include "Component.hpp"

Component::Component(ComponentID id) : ID(id)
{
	//
}

void Component::Initialize(const EntityID& parent)
{
	this->parentID = parent;

}

// Virtual
void Component::Update(float dt)
{
    //
}

// Virtual
void Component::Draw()
{
    //
}

// Virtual
void Component::Destroy()
{
    //
}

ComponentID Component::GetID()
{
    return this->ID;
}