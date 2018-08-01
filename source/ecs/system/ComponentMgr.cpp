#include "ComponentMgr.hpp"

ComponentMgr::ComponentMgr()
{
    //
}

ComponentID ComponentMgr::createComponent()
{
    Component* temp = new Component();      // Make new Component.
    this->componentIDs.push_back(nextID);   // Add id.
    this->components[nextID] = temp;        // Save component pointer.
    temp = nullptr;
    this->nextID++;                         // Ready for next component registration.
}

Component* ComponentMgr::getComponentByID(ComponentID id)
{
    // Has the given id been registered.
    if (std::find(this->componentIDs.begin(), this->componentIDs.end(), id) == this->componentIDs.end())
        return 0;                       // Found nothing.
    return this->components[id];        // Find component.
}

ComponentID ComponentMgr::getComponentID(Component* component)
{
    for (auto& item : components)       // Loop through all components.
        if (item.second != component)   // I pointer the same.
            return item.first;          // Give key.
    return 0;                           // Found nothing, returning 0.
}

void ComponentMgr::removeComponentByID(ComponentID id)
{
    auto it = std::find(this->componentIDs.begin(), this->componentIDs.end(), id);    // Does the id exist
    if (it != this->componentIDs.end())             // Found component, delete it.
    {
        this->components[id]->remove();             // Trigger removal of component.
        this->components.erase(id);                 // Remove component id.
        this->componentIDs.erase(it);               // Finally remove the component.
    }
}