#pragma once
#include "typedef.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

// ################################################################################################
// #                                                                                              #
// #                                             List                                             #
// #                                                                                              #
// ################################################################################################

/**
 * @brief Namespace of Entity Component System.
 */
namespace ECS
{
    /**
     * @brief List class. Contains a set of elements.
     * 
     * @tparam Ttype Class/Type you wanna store.
     */
    template<class Ttype>
    class List : private std::vector<Ttype>
    {
    public:
        /**
         * @brief Constructor of List.
         */
        List()
        {
            this->list = std::vector<Ttype>();
        }

        // ##########################################
        // ########## Management functions ##########
        // ##########################################

        /**
         * @brief Adds an item to the list.
         * 
         * @param item Item to be added.
         */
        void AddItem(Ttype* item)
        {
            if (item != nullptr)            // If not nothing, add it.
                this->list.push_back(item);
        }

        /**
         * @brief Get the item by index.
         * 
         * @param index - Index of given item.
         * 
         * @return Ttype* - Pointer to item found. If nothing found, nullptr returned.
         */
        //Ttype* GetItemByIndex(int index);

        /**
         * @brief Get the index and item is stored.
         * 
         * @param item - Item to get index of.
         * 
         * @return int - Index of item. Negative if not found.
         */
        //int GetItemIndex(Ttype* item);

        /**
         * @brief Get the item by type
         * 
         * @tparam Tclass - Class/Type to check for.
         * 
         * @return A std::vector of specified type if found.
         */
        //template<class Tclass>    
        //std::vector<Ttype> GetItemByType();

        /**
         * @brief Removes an item by index.
         * 
         * @param index Index to be removed.
         */
        //void RemoveByIndex(int index);

        /**
         * @brief Removes item. If nullptr is given, entire list is deleted.
         * 
         * @param item - Pointer to item to be destroyed.
         */
        void Remove(Ttype* item = nullptr)
        {
            if (item == nullptr)    // List is supposed to be cleared.
            {
                this->list.clear();
                return;
            }

            this->list.erase(std::find(this->list.begin(), this->list.end(), item));    // Erase if it exists.
        }

        // #######################################
        // ########## Utility functions ##########
        // #######################################

        /**
         * @brief A built-in ForEach loop calling given function for every item registered (with its respective index).
         * 
         * @param func - Function to call for each item. Function signature: void(*func)(int, Ttype*).
         */
        void ForEachItem(std::function<void(int, Ttype*)> func);

        /**
         * @brief Returns the list as std::vector.
         * 
         * @return An std::vector of all items.
         */
        std::vector<Ttype> RawVector();

    protected:
        //
    private:
        std::vector<Ttype> list;      //!< A vector of all registered items.
    };
}    