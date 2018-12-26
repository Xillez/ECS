#include "Entity.hpp"

#include <iostream>
#include <algorithm>

Entity::Entity() : ID(DEFAULT_ENTITY_ID)
{
	//
}

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
/*template<class Tclass>
bool Entity::GetComponent()
{
	auto it = std::find(this->componentIDs.begin(), this->componentIDs.end(), id);    // Does the id exist.
	if (it != this->componentIDs.end())            // Found component, delete it.
	{
		// Add parent / initialize with current object as parent.
			//component->Initialize(this);
			// Add it to current Entity's component list.
			this->componentIDs.push_back(id);
	}

	// Tell whether it was added or not.
	return (id);
}*/

//virtual
Component* Entity::GetComponentByID(ComponentID id)
{
	/*auto it = std::find(this->componentIDs.begin(), this->componentIDs.end(), id);    // Does the id exist.
    if (it != this->componentIDs.end())            // Found component, delete it.
    {
        // Add parent / initialize with current object as parent.
		//component->Initialize(this);
		// Add it to current Entity's component list.
		this->componentIDs.push_back(id);
    }

	// Tell whether it was added or not.
	return (id);*/
}

//virtual
void Entity::Start()
{
	//
}

//virtual
void Entity::Update()
{
	//
}

//virtual
/*void Entity::PhysicsUpdate()
{
	//
}*/

//virtual
void Entity::Draw()
{
	std::cout << "Entity " << this->ID << ", ClassName: " << this->GetClassName() << "!\n";
}

//virtual
bool Entity::Destroy()
{
	this->componentIDs.clear();
    return (this->componentIDs.size() == 0);
}

int Entity::GetID()
{
	return this->ID;
}

//virtual
std::string Entity::GetClassName(bool removeDigits)
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
std::string Entity::GetLowestTypeName(bool removeDigits)
{
	std::string name = typeid(*this).name();		// Get the dirty name of class.
	if (typeid(*this).__is_pointer_p())				// If it's  a pointer remove prefix "P".
		name.erase(name.begin(), name.begin() + 1);
	if (removeDigits)								// Should remove digits?
	{
		int i = 0;
		while (isdigit(name.at(i))) i++;			// Find where digits end.
		name.erase(name.begin(), name.begin() + i);	// Remove them.
	}
	return name;									// Return pretty name.
}