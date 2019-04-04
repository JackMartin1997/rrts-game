#ifndef RRTS_DRAWTARGET_H
#define RRTS_DRAWTARGET_H

#include <RenderState.h>
#include <VertexBufferArray.h>
#include <IndexBuffer.h>
#include <glm.hpp>
#include <Transformable.h>

namespace rrts
{
    namespace Graphics
    {
        class TargetRenderer;

        class RenderTarget : public Transformable
        {
        public:
            void rotate(float by) override;
            void scale(float by) override;
            void setSize(int width, int height) override;
            void setPosition(int x, int y) override;
        protected:
            VertexBufferArray bufferArray; // this could be a issue in future
            IndexBuffer indexBuffer;
            RenderState state;

            friend TargetRenderer;
        };
    }
}


#endif //RRTS_DRAWTARGET_H
