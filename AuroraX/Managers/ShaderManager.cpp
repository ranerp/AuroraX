#include "ShaderManager.h"

using namespace Managers;

std::map<std::string, GLuint> ShaderManager::programs;

ShaderManager::ShaderManager()
{

}

ShaderManager::~ShaderManager()
{
	Destroy();
}

void ShaderManager::Destroy()
{
	std::map<std::string, GLuint>::iterator i;
	for (i = programs.begin(); i != programs.end(); i++)
	{
		GLuint program = i->second;
		glDeleteProgram(program);
	}
	programs.clear();
}