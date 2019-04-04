#ifndef RRTS_TRANSFORMABLE_H
#define RRTS_TRANSFORMABLE_H

#include <glm.hpp>

namespace rrts
{
    namespace Graphics
    {
	class Transformable
	{
	public:
	    virtual void rotate(float by)=0;
	    virtual void scale(float by)=0;
	    virtual void setSize(int width, int height)=0;
	    virtual void setPosition(int x, int y)=0;

	protected:

	    glm::vec2 size;
	    glm::vec2 position;
	    float rotation;
	};
    }
}

#endif //RRTS_TRANSFORMABLE_H
