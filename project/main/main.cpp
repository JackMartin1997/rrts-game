#include <iostream>
#include <GL/glew.h>
#include <Window.h>
#include <Shader.h>
#include <Vertex.h>
#include <vec3.hpp>
#include <VertexBuffer.h>
#include <IndexBuffer.h>
#include <VertexBufferArray.h>
#include <Session.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

rrts::Graphics::Vertex vertices[] = {
	glm::vec3(-0.5f, 0.5f, 0.f), glm::vec3(1.0f, 0.0f, 0.f), glm::vec2(0.0f, 1.f),
	glm::vec3(-0.5f, -0.5f, 0.f),glm::vec3(0.0f, 1.0f, 0.f), glm::vec2(0.0f, 0.f),
	glm::vec3(0.5f, -0.5f, 0.f), glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 0.f),
	glm::vec3(0.5f, 0.5f, 0.f),  glm::vec3(0.0f, 0.0f, 1.f), glm::vec2(1.0f, 0.f),
};
unsigned int indices[] = {
	0, 1, 2,
	0, 2, 3
};

int main(int argc, char *argv[])
{
	rrts::Graphics::Window window(1280, 720);

	rrts::Graphics::Shader shader;
	shader.loadFromFile("shaders/es.vs", "shaders/es.fs");

	rrts::Graphics::VertexBufferArray vertexBufferArray;

	rrts::Graphics::VertexBuffer vertexBuffer{};
	vertexBuffer.create(&vertices, sizeof(vertices));

	rrts::Graphics::IndexBuffer indexBuffer{};
	indexBuffer.create(indices, sizeof(indices));

	vertexBufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
		(void*)offsetof(rrts::Graphics::Vertex, position), 3);

	vertexBufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
		(void*)offsetof(rrts::Graphics::Vertex, colour), 3);

	vertexBufferArray.AddAttribute(rrts::Graphics::AttribDataType::Float, sizeof(rrts::Graphics::Vertex),
		(void*)offsetof(rrts::Graphics::Vertex, texcoord), 2);

	window.WhileRunning([&](){
		window.pollEvents();
		window.clear();

		shader.bind();
		vertexBufferArray.bind();
		glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);

		window.swapBuffer();
	});

	return 0;
}