#ifndef RRTS_INDEXBUFFER_H
#define RRTS_INDEXBUFFER_H

namespace rrts
{
    namespace Graphics
    {
	class IndexBuffer
	{
	public:
	    ~IndexBuffer();
	    void create(void *indices, unsigned int size);

	    unsigned int getCount();
	private:
	    void bind() const;

	    static void unbind();

	private:
	    unsigned int bufferID;
	    unsigned int count;
	};
    }
}

#endif //RRTS_INDEXBUFFER_H
