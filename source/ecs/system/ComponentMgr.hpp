#pragma once
#include "typedef.hpp"
#include "../component/Component.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>

#define INPUT_COMPONENT_ID 1

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
     * @brief Create new Component. The component's id goes from 2 and upwards. 1 is Player component id.
     * 
     * @tparam Class - The ubclass of Component.
     * 
     @return ComponentID - The ID to the newly created component.
     */
    template<typename Class>
    ComponentID CreateComponent();

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
    int nextID = INPUT_COMPONENT_ID + 1;

    std::vector<ComponentID> componentIDs;      //!< A vector of all components registered.
    std::unordered_map<ComponentID, Component*> components;     //!< A unordered map, mapping components to ids.
};
