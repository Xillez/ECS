#include "../ecs/system/lists/List.hpp"
#include "../ecs/system/injector/Injector.hpp"
#include "../ecs/system/EntityMgr.hpp"
#include "../config/Config.hpp"
#include "../util/Logging.hpp"

#include <stdio.h>
#include <iostream>

class TestEntity : public ECS::Entity
{
public:
	TestEntity(ECS::EntityID id) : ECS::Entity(id)
	{
		//
	};
};

class TestComponent : public ECS::Component
{
public:
	TestComponent(ECS::ComponentID id) : ECS::Component(id)
	{

	};
};

class TestComponent2 : public ECS::Component
{
public:
	TestComponent2(ECS::ComponentID id) : ECS::Component(id)
	{

	};
};

int main(int argc, char const *argv[])
{
	#if DEBUG
		LOG_INFO("DEBUG BUILD!")
	#else
		LOG_INFO("RELEASE BUILD!")
	#endif
	#if defined(VERSION)
		LOG_INFO(VERSION);
	#endif
	#if LOGGING
		LOG_INFO("Logging enabled!")
	#endif
	/*#if OS_NAME
		LOG_INFO("Logging enabled!")
	#endif*/

	ECS::EntityMgr entityMgr;

	for (int i = 0; i < 1; i++)
	{
		ECS::Entity* entity = entityMgr.GetEntityByID(entityMgr.CreateEntity<TestEntity>());
		entity->CreateComponent<TestComponent>();
		entity->CreateComponent<TestComponent>();
		entity->CreateComponent<TestComponent>();
		entity->CreateComponent<TestComponent2>();
		entity->CreateComponent<TestComponent2>();
	}

	entityMgr.Start();

	int i = 0;
	while (i < 2)
	{
		entityMgr.Update();

		/*ECS::EntityMgr.ForEachEntity([](ECS::EntityID id, ECS::Entity* entity){
			TestComponent* comp = entity->CreateComponent<TestComponent>();
			TestComponent2* comp2 = entity->CreateComponent<TestComponent2>();
			
			printf("Component id: %d | ECS::EntityParent id: %d | Component class type: %s\n", comp->GetID(), comp->GetParentID(), comp->GetClassName().c_str());
			printf("Component id: %d | ECS::EntityParent id: %d | Component class type: %s\n", comp2->GetID(), comp2->GetParentID(), comp2->GetClassName().c_str());
		});*/

		entityMgr.Draw();

		i++;
	}
	
	return !entityMgr.DestroyAll();
}