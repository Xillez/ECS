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
};

class TestComponent : public Component
{
public:
	TestComponent(ComponentID id) : Component(id)
	{

	};
};

class TestComponent2 : public Component
{
public:
	TestComponent2(ComponentID id) : Component(id)
	{

	};
};

int main(int argc, char const *argv[])
{
	#if IS_BUILD_TYPE_DEBUG()
		printf("DEBUG BUILD!\n");
	#endif
	#if defined(PROJECT_VERSION)
		printf("Project version: %s\n", PROJECT_VERSION);
	#endif
	#if IS_LOGGING_ENABLED()
		printf("Logging enabled!\n");
	#endif

	EntityMgr EntityMgr;

	for (int i = 0; i < 2; i++)
	{
		EntityMgr.CreateEntity<TestEntity>();
	}

	EntityMgr.Start();

	int i = 0;
	while (i < 10000)
	{
		EntityMgr.Update();

		/*EntityMgr.ForEachEntity([](EntityID id, Entity* entity){
			TestComponent* comp = entity->CreateComponent<TestComponent>();
			TestComponent2* comp2 = entity->CreateComponent<TestComponent2>();
			
			printf("Component id: %d | EntityParent id: %d | Component class type: %s\n", comp->GetID(), comp->GetParentID(), comp->GetClassName().c_str());
			printf("Component id: %d | EntityParent id: %d | Component class type: %s\n", comp2->GetID(), comp2->GetParentID(), comp2->GetClassName().c_str());
		});*/

		//printf("\n--------------------------------------------------------------\n");

		EntityMgr.Draw();

		i++;
	}
	
	return !EntityMgr.DestroyAll();
}