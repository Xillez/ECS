//#include "../ecs/entity/Entity.hpp"
#include "../ecs/system/EntityMgr.hpp"
#include "../config/Config.hpp"

#include <stdio.h>
#include <iostream>

class TestEntity : public Entity
{
	public:
		TestEntity(EntityID id) : Entity(id)
		{
			//
		};

		virtual std::string getBottomClassName(bool removeDigits = true)
		{
			std::string name = typeid(*this).name();
			if (typeid(*this).__is_pointer_p())
				name.erase(name.begin(), name.begin() + 1);
			if (removeDigits)
			{
				int i = 0;
				while (isdigit(name.at(i))) i++;
				name.erase(name.begin(), name.begin() + i);
			}
			return name;
		}
};

int main(int argc, char const *argv[])
{
	#if IS_BUILD_TYPE_DEBUG()
		printf("DEBUG BUILD!\n");
	#endif
	#if defined(PROJECT_VERSION)
		printf("Project version: %s\n", PROJECT_VERSION);
	#endif

	EntityMgr entityMgr;

	for (int i = 0; i < 10; i++)
	{
		entityMgr.createEntity<Entity>();
		entityMgr.createEntity<TestEntity>();
	}

	entityMgr.drawAllEntities();
	
	//entityMgr.forEach([](EntityID id, Entity* entity){
	//	entity->draw();
	//});

	//while(true)
	//{
	//	
	//}
	return !entityMgr.destroyAll();
}