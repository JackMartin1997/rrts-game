#ifndef RRTS_SHADER_H
#define RRTS_SHADER_H

#include <iostream>
#include <vec3.hpp>

namespace rrts
{
    namespace Graphics
    {
	class Shader
	{
	public:
	    Shader();

	    ~Shader();

	    /**
	     * Loads the shaders from the file. the geometry shader is optional my default but the others are required
	     * @param vertex
	     * @param fragment
	     * @param geometry
	     */
	    void loadFromFile(std::string vertex, std::string fragment, std::string geometry = "");

	    void bind();

	    static void unbind();

	    /**
	     * Adds a Vec3 uniform to the shader
	     * @param vec3
	     * @param name
	     */
	    void addUniformVec3(glm::vec3 vec3, std::string name);

	    unsigned int getId();
	private:
	    unsigned int vertexid;
	    unsigned int fragmentid;
	    unsigned int geometryid;

	    unsigned int programID;

	    void compileShader(std::string source, unsigned int id, unsigned int type);

	    std::string LoadFile(std::string path);

	    std::string errorCheck(unsigned int shader, unsigned int errortype, std::string message);
	};
    }
}

#endif //RRTS_SHADER_H
