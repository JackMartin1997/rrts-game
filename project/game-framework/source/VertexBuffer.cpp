#include <VertexBuffer.h>
#include <GL/glew.h>

void rrts::Graphics::VertexBuffer::create(void * vertices, unsigned int size)
{
	if(!bufferID)
		glGenBuffers(1, &bufferID);

	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void rrts::Graphics::VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void rrts::Graphics::VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
}

rrts::Graphics::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(GL_ARRAY_BUFFER, &bufferID);
}
