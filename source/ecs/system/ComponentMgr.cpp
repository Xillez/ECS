#include "ComponentMgr.hpp"

#include <type_traits>

ComponentMgr::ComponentMgr()
{
    //
}

template<typename Class>
ComponentID ComponentMgr::createComponent()
{
    if (std::is_base_of<Component, Class>::value)   // Does class extend Component?
    {
        Component* temp = new Class(nextID);        // Make new component.
        this->componentIDs.push_back(nextID);       // Add id.
        this->components[nextID] = temp;            // Save component pointer.
        temp = nullptr;
        this->nextID++;                             // Ready for next component registration.
        return this->nextID - 1;
    }
    return 0;
}

Component* ComponentMgr::getComponentByID(ComponentID id)
{
    // Has the given id been registered.
    if (std::find(this->componentIDs.begin(), this->componentIDs.end(), id) == this->componentIDs.end())
        return 0;                               // Found nothing.
    return this->components[id];                // Found component.
}

ComponentID ComponentMgr::getComponentID(Component* component)
{
    for (auto& item : components)               // Loop through all components.
        if (item.second != component)           // I pointer the same.
            return item.first;                  // Give key.
    return 0;                                   // Found nothing.
}

void ComponentMgr::removeComponentByID(ComponentID id)
{
    auto it = std::find(this->componentIDs.begin(), this->componentIDs.end(), id);    // Does the id exist
    if (it != this->componentIDs.end())         // Found component, delete it.
    {
        this->components[id]->remove();         // Trigger removal of component.
        this->components.erase(id);             // Remove component id.
        this->componentIDs.erase(it);           // Finally remove the component.
    }
}