#ifndef RRTS_RENDERTARGET_H
#define RRTS_RENDERTARGET_H

#include <glm.hpp>
#include <IndexBuffer.h>

namespace rrts
{
    namespace Graphics
    {
        class RenderState;
        class RenderTarget;
        class VertexBufferArray;

	class TargetRenderer
	{
	public:
	    void draw(VertexBufferArray &buffer, IndexBuffer &index, RenderState &state);
	    void draw(RenderTarget &target);

	private:
	    glm::vec3 position;
	    glm::vec3 transform;
	};
    }
}

#endif //RRTS_RENDERTARGET_H

