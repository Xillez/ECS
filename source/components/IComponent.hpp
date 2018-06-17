#pragma once

/**
 * @brief Container for classes and structures associated with components. 
 */
namespace components
{
	/**
	 * @brief Interface class for components.
	 */
	class IComponent
	{	
		protected:
			void* parent = nullptr;		//!< Parent object I exists inside.

		public:
			/**
			 * @brief Interface component class constructor.
			 */
			IComponent();

			/**
			 * @brief initialize function to give component parent object for updating and possibly drawing.
			 * 
			 * @param parent - Parent object I exists inside.
			 */
			virtual auto init(void* parent) -> void;

			/**
			 * @brief Update function for components. 
			 */
			virtual auto update(float dt) -> void = 0;
	
			/**
			 * @brief Draw the mesh on the screen using given shader program.
			 * @param shader A shader program for GL pipeline.
			 */
			virtual auto draw(modeler::Shader shader) -> void = 0;

			virtual auto getType() -> int = 0;
	};
}
