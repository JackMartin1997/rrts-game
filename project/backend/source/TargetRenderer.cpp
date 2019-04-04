#include <TargetRenderer.h>
#include <RenderState.h>
#include <VertexBufferArray.h>
#include <Shader.h>
#include <GL/glew.h>
#include <RenderTarget.h>
#include <Texture.h>
#include <ext.hpp>
#include <glm.hpp>

void rrts::Graphics::TargetRenderer::draw(rrts::Graphics::RenderTarget &target)
{
	// transformations



	draw(target.bufferArray, target.indexBuffer, target.state);
}

void rrts::Graphics::TargetRenderer::draw(rrts::Graphics::VertexBufferArray &buffer, rrts::Graphics::IndexBuffer &index,
                                        rrts::Graphics::RenderState &state)
{
	buffer.bind();
	state.shaderInstance->bind();
	if (state.textureInstance != nullptr)
		state.textureInstance->bind();

	glDrawElements(GL_TRIANGLES, index.getCount(), GL_UNSIGNED_INT, 0);
}
