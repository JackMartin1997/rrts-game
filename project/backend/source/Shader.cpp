#include <utility>
#include <Shader.h>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <streambuf>

rrts::Graphics::Shader::Shader() = default;

rrts::Graphics::Shader::~Shader()
{
	glDeleteProgram(programID);
}

void rrts::Graphics::Shader::loadFromFile(std::string vertex, std::string fragment, std::string geometry)
{
	if (programID > -1)
		glDeleteProgram(programID);

	programID = glCreateProgram();

	if (!vertex.empty()) {
		vertexid = glCreateShader(GL_VERTEX_SHADER);
		compileShader(LoadFile(std::move(vertex)), vertexid, GL_VERTEX_SHADER);
		glAttachShader(programID, vertexid);
	}
	if (!fragment.empty()) {
		fragmentid = glCreateShader(GL_FRAGMENT_SHADER);
		compileShader(LoadFile(std::move(fragment)), fragmentid, GL_FRAGMENT_SHADER);
		glAttachShader(programID, fragmentid);
	}
	if (!geometry.empty())
	{
		geometryid = glCreateShader(GL_GEOMETRY_SHADER);
		compileShader(LoadFile(std::move(geometry)), geometryid, GL_GEOMETRY_SHADER);
		glAttachShader(programID, geometryid);
	}
	glLinkProgram(programID);

	std::string error;
	int success = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		error += "== PROGRAM ERROR == \n";
		char info[1024];
		glGetProgramInfoLog(programID, 1024, nullptr, info);
		error += info;
	}
	std::cout << error << "\n";
	unbind();
	glDeleteShader(vertexid);
	glDeleteShader(fragmentid);
}

std::string rrts::Graphics::Shader::LoadFile(std::string path)
{

#ifdef EMSCRIPTEN
	std::string str;
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen(path.c_str(), "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, stream)) != -1) {
		str += line;
	}

	free(line);
	fclose (stream);
#else
	std::string str;
	{
		std::ifstream stream(path);
		for( std::string line; getline( stream, line ); )
		{
			str += line + "\n";
		}
		stream.close();
	}
#endif
	return str;
}

std::string rrts::Graphics::Shader::errorCheck(unsigned int shader, unsigned int errortype, std::string message)
{
	std::string error;
	int success = 0;
	glGetShaderiv(shader, errortype, &success);
	if (!success) {
		error += message + "\n";
		char info[1024];
		glGetShaderInfoLog(shader, 1024, nullptr, info);
		error += info;
	}
	return std::move(error);
}

void rrts::Graphics::Shader::compileShader(std::string source, unsigned int id, unsigned int type)
{
	const char *c_src = source.c_str();
	glShaderSource(id, 1, &c_src, nullptr);
	glCompileShader(id);
	std::cout << errorCheck(id, GL_COMPILE_STATUS, "== SHADER INFO ==");
}

void rrts::Graphics::Shader::bind()
{
	glUseProgram(programID);
}

void rrts::Graphics::Shader::unbind()
{
	glUseProgram(0);
}

void rrts::Graphics::Shader::addUniformVec3(glm::vec3 vec3, std::string name)
{
	int location = glGetUniformLocation(programID, name.c_str());

	bind();
	if (location > -1)
		glUniform3f(location, vec3.x, vec3.y, vec3.z);
}

unsigned int rrts::Graphics::Shader::getId()
{
	return programID;
}
