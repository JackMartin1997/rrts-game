#ifndef RRTS_VERTEXBUFFERARRAY_H
#define RRTS_VERTEXBUFFERARRAY_H


namespace rrts
{
    namespace Graphics
    {
        class TargetRenderer;

        enum AttribDataType
        {
                Float
        };

	class VertexBufferArray
	{
	public:
	    VertexBufferArray();
	    ~VertexBufferArray();

	    const void bind();
	    static void unbind();

	    /**
	     * Initializes the vertex buffer srray
	     */
	    void create();

	    /**
	     * Adds a attribute to the vertex array. this requires shaders made to handle the data
	     * @param type
	     * @param width
	     * @param offset
	     * @param vectorSize
	     */
	    void AddAttribute(AttribDataType type, unsigned int width, void* offset, unsigned int vectorSize);

	    void setIndexCount(unsigned int count);
	private:
	    unsigned int bufferID;
	    unsigned int currentAttributeIndex = 0;

	    unsigned int count = 0;
	    friend TargetRenderer;
	};
    }
}

#endif //RRTS_VERTEXBUFFERARRAY_H
