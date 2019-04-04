#include <VertexBufferArray.h>
#include <GL/glew.h>

rrts::Graphics::VertexBufferArray::VertexBufferArray()
{
	create();
}

rrts::Graphics::VertexBufferArray::~VertexBufferArray()
{
	glDeleteVertexArrays(1, &bufferID);
}

const void rrts::Graphics::VertexBufferArray::bind()
{
	glBindVertexArray(bufferID);
}

void rrts::Graphics::VertexBufferArray::unbind()
{
	glBindVertexArray(0);
}

void rrts::Graphics::VertexBufferArray::create()
{
	glGenVertexArrays(1, &bufferID);
	bind();
}

void
rrts::Graphics::VertexBufferArray::AddAttribute(rrts::Graphics::AttribDataType type, unsigned int width,
                                                void *offset, unsigned int vectorSize)
{
	switch (type) {
		case Float: {
			bind();
			glVertexAttribPointer(currentAttributeIndex, vectorSize, GL_FLOAT, GL_FALSE,
			                      width, offset);
			glEnableVertexAttribArray(currentAttributeIndex);
			unbind();
			currentAttributeIndex++;
		}
			break;
	}
}

void rrts::Graphics::VertexBufferArray::setIndexCount(unsigned int count)
{
	count = count;
}
