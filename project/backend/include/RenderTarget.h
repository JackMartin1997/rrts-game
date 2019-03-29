#ifndef RRTS_RENDERTARGET_H
#define RRTS_RENDERTARGET_H

#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
	class RenderTarget
	{
	public:
	    void draw(RenderTarget &target);

	protected:
	    //void drawCall(RenderTarget &)


	    glm::vec3 position;
	    glm::vec3 transform;
	};
    }
}

#endif //RRTS_RENDERTARGET_H

