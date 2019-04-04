#ifndef RRTS_RENDERSTATE_H
#define RRTS_RENDERSTATE_H

#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
        class Texture;
        class Shader;
        class TargetRenderer;
        class RenderTarget;

        /**
         * Render state - class which contains the state of a object that can be rendered.
         * this includes the texture and shader
         */
        class RenderState
        {
        public:
            RenderState();
            void setShader(Shader* instance);
            void setTexture(Texture* instance);

            Shader* getShader();
        private:

            // Ideally these should be const
            Shader* shaderInstance;
            Texture* textureInstance;

            glm::mat4 model;
            glm::mat4 projection;
            glm::mat4 view;

            friend TargetRenderer;
            friend RenderTarget;
        };

    }
}

#endif //RRTS_RENDERSTATE_H
