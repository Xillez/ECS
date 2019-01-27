#include "Component.hpp"

Component::Component(ComponentID id) : ID(id)
{
	//
}

void Component::Initialize(const EntityID& parent)
{
	this->parentID = parent;

}

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

//virtual
void Component::Start()
{
	printf("Entity - Start()\n");
}

//virtual
void Component::Update()
{
	printf("Entity - Update()\n");
}

//virtual
/*void Component::PhysicsUpdate()
{
	//
}*/

//virtual
void Component::Draw()
{
	printf("Entity - Draw()\n");
}

//virtual
bool Component::Destroy()
{
	printf("Entity - Draw()\n");
	//this->parentID = 0;
}

// ##########################################
// ########## Management functions ##########
// ##########################################

ComponentID Component::GetID()
{
    return this->ID;
}

EntityID Component::GetParentID()
{
    return this->parentID;
}

void Component::SetParentID(EntityID parent)
{
    this->parentID = parent;
}

// #######################################
// ########## Utility functions ##########
// #######################################

//virtual
std::string Component::GetClassName(bool removeDigits)
{
	std::string name = typeid(*this).name();	// Get dirty class name.
	if (typeid(*this).__is_pointer_p())			// If it's a pointer remove prefix "P".
		name.erase(name.begin(), name.begin() + 1);
	if (removeDigits)							// Should remove digits?
	{
		int i = 0;
		while (isdigit(name.at(i))) i++;		// Find where digits end.
		name.erase(name.begin(), name.begin() + i);	// Remove digits.
	}
	return name;								// Return pretty name.
}

//virtual
/*std::string Component::GetLowestTypeName(bool removeDigits)
{
	std::string name = typeid(*this).name();		// Get the dirty name of class.
    printf("GET LOWEST TYPE NAME: %s\n", name);
	if (typeid(*this).__is_pointer_p())				// If it's a pointer remove prefix "P".
		name.erase(name.begin(), name.begin() + 1);
	if (removeDigits)								// Should remove digits?
	{
		int i = 0;
		while (isdigit(name.at(i))) i++;					// Find where digits end.
		name.erase(name.begin(), name.begin() + i);			// Remove them.
	}
	return name;									// Return pretty name.
}*/