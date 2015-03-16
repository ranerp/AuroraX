#include "TextureManager.h"

using namespace Managers;

std::map<std::string, GLuint> TextureManager::textures;

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

void TextureManager::Destroy()
{
	std::map<std::string, GLuint>::iterator i;
	for (i = textures.begin(); i != textures.end(); i++)
	{
		GLuint texture = i->second;
		glDeleteTextures(1, &texture);
	}
	textures.clear();
}
