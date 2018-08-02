#include "../ecs/entity/Entity.hpp"
#include "../ecs/system/EntityMgr.hpp"

#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	EntityMgr entityMgr;
	entityMgr.createEntity<Entity>();

	entityMgr.drawAllEntities();
	//entityMgr.forEach([](EntityID id, Entity* entity){
	//	entity->draw();
	//});

	//while(true)
	//{
	//	
	//}
	return 0;
}