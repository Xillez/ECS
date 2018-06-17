#include "Entity.hpp"
#include "../environment/Camera.hpp"
#include "../environment/LightSource.hpp"
#include "../modeler/ShaderManager.hpp"
#include "../components/GraphicsComponent.hpp"

extern environment::Camera* camera;
extern modeler::ShaderManager* shaderManager;
extern environment::LightSource* lightSource;

game::Entity::Entity()
{
	this->position = glm::vec3(2.0f, 0.0f, 0.0f);
	this->velocity = glm::vec3(0.0f, 0.0f, 0.0f);
	this->acceleration = glm::vec3(0.0f, 0.0f, 0.0f);

	shaderProgram = shaderManager->getShader(std::vector<std::pair<GLenum, std::string>>{
		{GL_VERTEX_SHADER, "../shader/vertex.vert"},
		{GL_FRAGMENT_SHADER, "../shader/fragment.frag"},
	});
}

auto game::Entity::registerComponent(components::IComponent* component) -> bool
{
	// If this is a valid component
	if (component)
	{
		// Add parent / initialize with current object as parent
		component->init(this);
		// Add it to current Entitys component list
		this->componentList.push_back(component);
	}

	// Tell whether it was added or not
	return (component);
}

auto game::Entity::update(float dt) -> void
{
	//
}

auto game::Entity::draw(float dt) -> void
{
	std::cout << "Entity: " << id << "\n";
}

auto game::Entity::setPos(glm::vec3 newPos) -> void
{
	//
}