#include "EntityMgr.hpp"

EntityMgr::EntityMgr()
{
    //
}

EntityID EntityMgr::createEntity()
{
    Entity* temp = new Entity();        // Make new Entity.
    this->entityIDs.push_back(nextID);  // Add id.
    this->entities[nextID] = temp;      // Save entity pointer.
    temp = nullptr;
    this->nextID++;                     // Ready for next entity registration.
}

Entity* EntityMgr::getEntityByID(EntityID id)
{
    // Has the given id been registered.
    if (std::find(this->entityIDs.begin(), this->entityIDs.end(), id) == this->entityIDs.end())
        return 0;                       // Found nothing.
    return this->entities[id];          // Find entity.
}

EntityID EntityMgr::getEntityID(Entity* entity)
{
    for (auto& item : entities)         // Loop through all entities.
        if (item.second != entity)      // I pointer the same.
            return item.first;          // Give key.
    return 0;                           // Found nothing, returning 0.
}

void EntityMgr::removeEntityByID(EntityID id)
{
    auto it = std::find(this->entityIDs.begin(), this->entityIDs.end(), id);    // Does the id exist
    if (it != this->entityIDs.end())            // Found entity, delete it.
    {
        this->entities[id]->remove();           // Trigger removal of entity.
        this->entities.erase(id);               // Remove entity id.
        this->entityIDs.erase(it);              // Finally remove the entity.
    }
}