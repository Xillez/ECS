#pragma once
#include "../ecs/system/typedef.hpp"

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <type_traits>
#include <typeinfo>

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
     * @tparam Ttype Class/Type you want to store.
     */
    template<class Ttype>
    class List
    {
    public:
        /**
         * @brief Constructor of List.
         */
        List()
        {
            this->data = std::vector<Ttype*>();
        }

        // ##########################################
        // ########## Management functions ##########
        // ##########################################

        /**
         * @brief Adds an item to the list.
         * 
         * @param item Item to be added.
         */
        void Add(Ttype* item)
        {
            if (item != nullptr)            // If not nothing, add it.
                this->data.push_back(item);
        }

        /**
         * @brief Get the item by index.
         * 
         * @param index - Index of given item.
         * 
         * @return Ttype* - Pointer to item found. If nothing found, nullptr returned.
         */
        Ttype* GetItemByIndex(int index)
        {
            return this->data.at(index);
        }

        /**
         * @brief Get the index and item is stored.
         * 
         * @param item - Ttype - Item to get index of.
         * 
         * @return int - Index of item. Negative if not found.
         */
        int GetItemIndex(Ttype* item)
        {
            for (int i = 0; i < this->data.size(); i++)
                if (this->data.at(i))
                    return i;

            return -1;
        }

        /**
         * @brief Get the item by type
         * 
         * @tparam Tclass - Class/Type to check for.
         * 
         * @return A std::vector of specified type if found.
         */
        template<class Tclass>
        Ttype* GetItemByType()
        {
            for (int i = 0; i < this->data.size(); i++)
                if (typeid((*this->data.at(i))) == typeid(Tclass))
                    return this->data.at(i);

            return nullptr;
        }

        /**
         * @brief Get the item by type
         * 
         * @tparam Tclass - Class/Type to check for.
         * 
         * @return A std::vector of specified type if found.
         */
        template<class Tclass>
        std::vector<Ttype*> GetItemsByType()
        {
            std::vector<Ttype*> temp = std::vector<Ttype*>();

            for (int i = 0; i < this->data.size(); i++)
                if (typeid((*this->data.at(i))) == typeid(Tclass))
                    temp.push_back();

            return temp;
        }

        /**
         * @brief Removes an item by index.
         * 
         * @param index Index to be removed.
         *
         */
        void RemoveByIndex(int index)
        {
            if (index < 0 || index >= this->data.size())
                return;

            this->data.erase(this->data.begin() + index);
        }

        /**
         * @brief Removes item. If nullptr is given, entire list is deleted.
         * 
         * @param item - Pointer to item to be destroyed.
         */
        void Remove(Ttype* item = nullptr)
        {
            if (item == nullptr)    // List is supposed to be cleared.
            {
                this->data.clear();
                return;
            }

            this->data.erase(std::find(this->data.begin(), this->data.end(), item));    // Erase if it exists.
        }

        // #######################################
        // ########## Utility functions ##########
        // #######################################

        /**
         * @brief Calls the given function for every item registered with its respective index.
         * 
         * @param func - Function to call for each item. Function signature: void(*func)(int, Ttype*).
         */
        void ForEach(std::function<void(int, Ttype*)> func)
        {
            for (int i = 0; i < this->data.size(); i++)
                func(i, this->data[i]);
        }

        /**
         * @brief Calls the given function for every item registered with its respective index. Quits if "func" returns true.
         * 
         * @param func - Function to call for each item. Function signature: bool(*func)(int, Ttype*).
         */
        void Some(std::function<bool(int, Ttype*)> func)
        {
            for (int i = 0; i < this->data.size(); i++)
                if (func(i, this->data.at(i)))
                    return;
        }

        /**
         * @brief Returns the list as std::vector.
         * 
         * @return An std::vector containing all items.
         */
        std::vector<Ttype*> RawVector()
        {
            return this->data;
        }

        /**
         * @brief Converts the list to string.
         * 
         * @return - string - The list in string form.
         * TODO: Make it print the content of the objects instead of its type.
         */
        std::string ToString()
        {
            std::string str = "{ ";

            for (int i = 0; i < this->data.size(); i++)
            {
                str.append(typeid(this->data.at(i)).name());
                if (i != this->data.size() - 1)
                    str.append(", ");
            }

            return str.append(" }");
        }

    protected:
        //
    private:
        std::vector<Ttype*> data;      //!< A vector of all registered items.
    };
}