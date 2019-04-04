#include <Square.h>
#include <Vertex.h>
#include <glm.hpp>
#include <VertexBuffer.h>
#include <VertexBufferArray.h>
#include <IndexBuffer.h>
#include <Shader.h>

/* Texture coordinate layout
	0,1------------1,1
	 |              |
	 |              |
	 |              |
	 |              |
	0,0------------1,0
*/
rrts::Graphics::Vertex vertices[] = {
	glm::vec3(-0.5f, 0.5f, 0.f), glm::vec3(1.0f, 0.0f, 0.f), glm::vec2(0.0f, 0.f), //LEFT-DOWN
	glm::vec3(-0.5f, -0.5f, 0.f),glm::vec3(0.0f, 1.0f, 0.f), glm::vec2(0.0f, 1.f), //LEFT-UP
	glm::vec3(0.5f, -0.5f, 0.f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 1.f), //RIGHT-UP
	glm::vec3(0.5f, 0.5f, 0.f),  glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 0.f), //RIGHT-DOWN
};
unsigned int indices[] = {
	0, 1, 2,
	0, 2, 3
};

rrts::Graphics::Square::Square()
{
	state.setShader(new rrts::Graphics::Shader);
	state.getShader()->loadFromFile("shaders/es.vs", "shaders/es.fs");

	bufferArray.bind();

	vertexBuffer.create(&vertices, sizeof(vertices));

	indexBuffer.create(indices, sizeof(indices));

	bufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
	                               (void*)offsetof(rrts::Graphics::Vertex, position), 3);

	bufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
	                               (void*)offsetof(rrts::Graphics::Vertex, colour), 3);

	bufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
	                               (void*)offsetof(rrts::Graphics::Vertex, texcoord), 2);

	bufferArray.setIndexCount(indexBuffer.getCount());

	rrts::Graphics::VertexBufferArray::unbind();
}

void rrts::Graphics::Square::setTexture(rrts::Graphics::Texture *texture, bool resize)
{
	if (resize)
	{

	}

	this->state.setTexture(texture);
}
