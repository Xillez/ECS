#include <string>
#include <typeinfo>

namespace ECS
{
    /**
     * @brief Get the name of the current class.
     * 
     * @return std::string - Name of the current class.
     */
    template<typename Ttype>
    std::string GetNameOfType()
    {
        std::string name = typeid(Ttype).name();	// Get dirty class name.
        if (typeid(Ttype).__is_pointer_p())			// If it's a pointer remove prefix "P".
            name.erase(name.begin(), name.begin() + 1);
        if (removeDigits)							// Should remove digits?
        {
            int i = 0;
            while (isdigit(name.at(i))) i++;		// Find where digits end.
            name.erase(name.begin(), name.begin() + i);	// Remove digits.
        }
        return name;
    }

    /**
     * @brief Get the name of the lowest class in the hierarchy.
     * 
     * @return std::string - Name of the lowest class in the hierarchy.
     */
    //virtual std::string GetLowestTypeName(bool removeDigit = true);
}