#pragma once

#include "GL\glew.h"
#include <map>

namespace Managers
{
	class TextureManager
	{

	public:
		TextureManager();
		~TextureManager();

		void Destroy();

	private:
		static std::map<std::string, GLuint> textures;
	};

}
