#pragma once
#include "typedef.hpp"
#include "../component/Component.hpp"

#include <vector>
#include <unordered_map>
#include <type_traits>

/**
 * @brief Component manager class. Manages components.
 */
class ComponentMgr
{
public:
    /**
     * @brief Constructor of ComponentMgr.
     */
    ComponentMgr();

    /**
     * @brief Create new Component.
     * 
     * @tparam Class - The ubclass of Component.
     * 
     @return Component* - Pointer to the newly created component.
     */
    template<typename Class>
    Component* CreateComponent();

    /**
     * @brief Get the Component by ID.
     * 
     * @param id - Id of given component.
     * 
     * @return Component* - Pointer to component found. If nothing found, nullptr returned.
     */
    Component* GetComponentByID(ComponentID id);

    /**
     * @brief Get the Component ID.
     * 
     * @param component - Component to get id of.
     * 
     * @return ComponentID - ID of component. 0 if not found.
     */
    //ComponentID GetComponentID(Component* component);

    /**
     * @brief Removes an component by ID, all components without an owner gets removed aswell.
     * 
     * @param id - ID of component to be removed.
     */
    void RemoveComponentByID(ComponentID id);
protected:
    //
private:
    /**
     * @brief Function for increasing next component id. DO NOT USE.
     * 
     * @return ComponentID (int) - ID of next component to be added.
     */
    ComponentID NextID()
    {
        return nextID++;
    }

    ComponentID nextID = 0;

    std::vector<ComponentID> componentIDs;      //!< A vector of all components registered.
    std::unordered_map<ComponentID, Component*> components;     //!< A unordered map, mapping components to ids.
};
