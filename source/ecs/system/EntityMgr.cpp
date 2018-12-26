#include "EntityMgr.hpp"

EntityMgr::EntityMgr()
{
    //
}

/*template<class Tclass>
EntityID EntityMgr::CreateEntity()
{
    if (std::is_base_of<Entity, Tclass>::value)     // Does class extend Entity?
    {
        Entity* temp = new Tclass(this->nextID);    // Make new Entity with new ID.
        this->entityIDs.push_back(this->nextID);    // Add id.
        this->entities[this->nextID] = temp;        // Save entity pointer.
        temp = nullptr;
        this->nextID++;                             // Ready for next entity registration.
        return this->nextID - 1;                    // Return the new entities id.
    }
    std::cout << "Accepts only Entity and subclasses of it!\n";
    return 0;
}*/

Entity* EntityMgr::GetEntityByID(EntityID id)
{
    // Has the given id been registered.
    if (std::find(this->entityIDs.begin(), this->entityIDs.end(), id) == this->entityIDs.end())
        return nullptr;                             // Found nothing.
    return this->entities[id];                      // Found entity.
}

EntityID EntityMgr::GetEntityID(Entity* entity)
{
    for (auto& item : entities)                 // Loop through all entities.
        if (item.second != entity)              // I pointer the same.
            return item.first;                  // Give key.
    return 0;                                   // Found nothing.
}

void EntityMgr::DestroyEntityByID(EntityID id)
{
    auto it = std::find(this->entityIDs.begin(), this->entityIDs.end(), id);    // Does the id exist.
    if (it != this->entityIDs.end())            // Found entity, delete it.
    {
        this->entities[id]->Destroy();           // Trigger removal of entity.
        this->entities.erase(id);               // Remove entity id.
        this->entityIDs.erase(it);              // Finally remove the entity.
    }
}

void EntityMgr::ForEachEntity(std::function<void(EntityID, Entity*)> func)
{
    for (auto& entity : this->entities)         // Run through every entity.
        func(entity.first, entity.second);      // Call function on object.
}

void EntityMgr::DrawAllEntities()
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Draw();                  // Call draw on entity.
}

void EntityMgr::Update(float dt)
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Update();              // Call draw on entity.
}

bool EntityMgr::DestroyAll()
{
    for (auto& entity : this->entities)         // Run through all entities
        this->DestroyEntityByID(entity.first);   // Remove the entity.
    return (this->entities.size() == 0);
}

EntityID EntityMgr::NextID()
{
    return nextID++;
}

// ################################################################################################
// #                                                                                              #
// #                                     Component Management                                     #
// #                                                                                              #
// ################################################################################################

/*template<typename Class>
ComponentID EntityMgr::CreateComponent()
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

Component* EntityMgr::GetComponentByID(ComponentID id)
{
    // Has the given id been registered.
    if (std::find(this->componentIDs.begin(), this->componentIDs.end(), id) == this->componentIDs.end())
        return 0;                               // Found nothing.
    return this->components[id];                // Found component.
}

ComponentID EntityMgr::GetComponentID(Component* component)
{
    for (auto& item : components)               // Loop through all components.
        if (item.second != component)           // I pointer the same.
            return item.first;                  // Give key.
    return 0;                                   // Found nothing.
}

void EntityMgr::RemoveComponentByID(ComponentID id)
{
    auto it = std::find(this->componentIDs.begin(), this->componentIDs.end(), id);    // Does the id exist
    if (it != this->componentIDs.end())         // Found component, delete it.
    {
        this->components[id]->Remove();         // Trigger removal of component.
        this->components.erase(id);             // Remove component id.
        this->componentIDs.erase(it);           // Finally remove the component.
    }
}*/