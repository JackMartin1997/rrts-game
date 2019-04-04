#ifndef RRTS_SQUARE_H
#define RRTS_SQUARE_H

#include <RenderTarget.h>
#include <VertexBuffer.h>

namespace rrts
{
    namespace Graphics
    {
        class Texture;

	class Square : public RenderTarget
	{
	public:
	    Square();

	    void setTexture(Texture *texture, bool resize = false);
	private:
	    rrts::Graphics::VertexBuffer vertexBuffer;
	};
    }
}

#endif //RRTS_SQUARE_H
