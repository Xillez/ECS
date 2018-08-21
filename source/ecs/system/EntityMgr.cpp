#include "EntityMgr.hpp"

EntityMgr::EntityMgr()
{
    //
}

/*template<class Tclass>
EntityID EntityMgr::createEntity()
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

Entity* EntityMgr::getEntityByID(EntityID id)
{
    // Has the given id been registered.
    if (std::find(this->entityIDs.begin(), this->entityIDs.end(), id) == this->entityIDs.end())
        return nullptr;                             // Found nothing.
    return this->entities[id];                      // Found entity.
}

EntityID EntityMgr::getEntityID(Entity* entity)
{
    for (auto& item : entities)                 // Loop through all entities.
        if (item.second != entity)              // I pointer the same.
            return item.first;                  // Give key.
    return 0;                                   // Found nothing.
}

void EntityMgr::removeEntityByID(EntityID id)
{
    auto it = std::find(this->entityIDs.begin(), this->entityIDs.end(), id);    // Does the id exist.
    if (it != this->entityIDs.end())            // Found entity, delete it.
    {
        this->entities[id]->remove();           // Trigger removal of entity.
        this->entities.erase(id);               // Remove entity id.
        this->entityIDs.erase(it);              // Finally remove the entity.
    }
}

void EntityMgr::forEach(std::function<void(EntityID, Entity*)> func)
{
    for(auto& entity : this->entities)          // Run through every entity.
        func(entity.first, entity.second);      // Call function on object.
}

void EntityMgr::drawAllEntities()
{
    for(auto& entity : this->entities)          // Run through every entity.
        entity.second->draw();                  // Call draw on entity.
}

void EntityMgr::update(float dt)
{
    for(auto& entity : this->entities)          // Run through every entity.
        entity.second->update(dt);              // Call draw on entity.
}

bool EntityMgr::destroyAll()
{
    return true;
}