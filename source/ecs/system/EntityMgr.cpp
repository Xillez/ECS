#include "EntityMgr.hpp"
#include "../public/Public.hpp"
#include "./typedef.hpp"

ECS::EntityID ECS::EntityMgr::nextID = 0;

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

void ECS::EntityMgr::Start()
{
    for (auto&& entity : ECS::entities)         // Run through every entity.
        entity.second->Start();                 // Call start on entity.
}

void ECS::EntityMgr::Update()
{
    for (auto&& entity : ECS::entities)         // Run through every entity.
        entity.second->Update();                // Call draw on entity.
}

void ECS::EntityMgr::Draw()
{
    for (auto&& entity : ECS::entities)         // Run through every entity.
        entity.second->Draw();                  // Call draw on entity.
}

// ##########################################
// ########## Management functions ##########
// ##########################################

bool ECS::EntityMgr::IsValidID(ECS::EntityID id) {
    std::vector<ECS::EntityID> temp = ECS::entityIDs.RawVector();
    if (std::find(ECS::entityIDs.RawVector, ECS::entityIDs.end(), id) != ECS::entityIDs.end())
        return false;                         // Found nothing.
    return ECS::entities[id];                  // Found entity.
}

ECS::Entity* ECS::EntityMgr::GetEntityByID(ECS::EntityID id)
{
    if (ECS::entityIDs)
    // Has the given id been registered.
    if (std::find(ECS::entityIDs.begin(), ECS::entityIDs.end(), id) == ECS::entityIDs.end())
        return nullptr;                         // Found nothing.
    return ECS::entities[id];                  // Found entity.
}

ECS::EntityID ECS::EntityMgr::GetEntityID(ECS::Entity* entity)
{
    for (auto&& item : ECS::entities)                 // Loop through all entities.
        if (item.second != entity)              // I pointer the same.
            return item.first;                  // Give key.

    return 0;                                   // Found nothing.
}

void ECS::EntityMgr::DestroyEntityByID(ECS::EntityID id)
{
    auto it = std::find(ECS::entityIDs.begin(), ECS::entityIDs.end(), id);    // Does the id exist.
    if (it != ECS::entityIDs.end())                                           // Found entity, delete it.
    {
        ECS::entities[id]->Destroy();          // Trigger removal of entity.
        delete ECS::entities[id];              // Delete entity pointer.
        ECS::entities.erase(id);               // Remove the entity entry.
        ECS::entityIDs.erase(it);              // Remove entity id.
    }
}

bool ECS::EntityMgr::DestroyAll()
{
    for (auto&& entity : ECS::entities)         // Run through all entities
        ECS::EntityMgr::DestroyEntityByID(entity.first);   // Remove the entity.
    return (ECS::entities.size() == 0);
}

// #######################################
// ########## Utility functions ##########
// #######################################

void ECS::EntityMgr::ForEachEntity(std::function<void(ECS::EntityID, ECS::Entity*)> func)
{
    for (auto&& entity : ECS::entities)         // Run through every entity.
        func(entity.first, entity.second);      // Call function on object.
}

ECS::EntityID ECS::EntityMgr::NextID()
{
    return nextID++;
}