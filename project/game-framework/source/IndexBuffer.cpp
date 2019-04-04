#include <IndexBuffer.h>
#include <GL/glew.h>

void rrts::Graphics::IndexBuffer::create(void *indices, unsigned int size)
{
	count = size / sizeof(unsigned int);
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void rrts::Graphics::IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void rrts::Graphics::IndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

rrts::Graphics::IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &bufferID);
}

unsigned int rrts::Graphics::IndexBuffer::getCount()
{
	return count;
}
