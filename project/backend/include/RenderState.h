#ifndef RRTS_RENDERSTATE_H
#define RRTS_RENDERSTATE_H

namespace rrts
{
    namespace Graphics
    {
        class Texture;
        class Shader;

        class RenderState
        {
        public:


        protected:
            const Shader* shaderInstance;
            const Texture* textureInstance;
        };

    }
}

#endif //RRTS_RENDERSTATE_H
