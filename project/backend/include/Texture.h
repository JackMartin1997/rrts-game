#ifndef RRTS_TEXTURE_H
#define RRTS_TEXTURE_H

#include <iostream>
#include <vec2.hpp>

namespace rrts
{
    namespace Graphics
    {
        class Texture
        {
        public:
            Texture();
            ~Texture();
            void loadFromFile(std::string path);

            void bind() const;
            static void unbind();

            glm::vec2 getSize();
        private:
            unsigned int id;
            unsigned int width;
            unsigned int height;
        };
    }
}
#endif //RRTS_TEXTURE_H
