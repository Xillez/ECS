#pragma once
#include <vector>
#include <string>
#include <unordered_map>
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
     * @brief Injector class. Runtime injection of values to make connections. Reads ".imeta" xml files for solid connections connections.
     */
    class Injector
    {
    public:
        /**
         * @brief Constructor of Injector.
         */
        Injector()
        {
            //
        }

        // ##########################################
        // ########## Management functions ##########
        // ##########################################

        /**
         * @brief Reads ".imeta" files and injects the object.
         * @attention NOT IMPLEMENTED!!
         */
        void ReadInject()
        {
            //
        }

        /**
         * @brief Makes an injection configuration file for object
         * @attention NOT IMPLEMENTED!!
         * 
         * @tparam Ttype Type of object to make injection config file for.
         * @param item - Ttype* - Runtime object with values to save. Default: nullptr.
         */
        template<class Ttype>
        void MakeInjectFile(Ttype* item = nullptr)
        {
            //
        }

        /**
         * @brief Function for injecting a value in an object.
         * @attention NOT IMPLEMENTED!!
         * 
         * @tparam Tobj - Type of object to inject into.
         * @tparam Tvalue - Type of value to inject into "obj".
         * 
         * @param obj - Object to inject into.
         * @param name - Name of a member variable in "obj".
         * @param value Object to inject into "obj".
         * 
         * @return true - If injection was successful.
         * @return false - If injection was NOT successful.
         */
        template<typename Tobj, typename Tvalue>
        bool Inject(Tobj* obj, std::string name, Tvalue value)
        {
            return 0;
        }


        
    protected:
        //
    private:
        //
    };


}