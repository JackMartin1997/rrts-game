#ifndef RRTS_VERTEX_H
#define RRTS_VERTEX_H

#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
        class Vertex
        {
        public:
            glm::vec3 position;
            glm::vec3 colour;
            glm::vec2 texcoord;
        };
    }
}

#endif //RRTS_VERTEX_H
