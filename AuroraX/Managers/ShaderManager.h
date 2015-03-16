#pragma once

#include <map>
#include "GL/glew.h"

namespace Managers
{
	class ShaderManager
	{
	public:
		ShaderManager();
		~ShaderManager();

		void Destroy();

	private:
		static std::map<std::string, GLuint> programs;
	};
}