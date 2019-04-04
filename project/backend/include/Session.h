#ifndef RRTS_SESSION_H
#define RRTS_SESSION_H

#include <GL/glew.h>
#include <glm.hpp>
#include <memory>
#include <GLFW/glfw3.h>

#ifdef linux
#define OS_VERSION "Linux"
#endif
#ifdef EMSCRIPTEN
#define OS_VERSION "Web"
#endif

namespace rrts
{
    namespace Graphics
    {
        class Window;
    }

    namespace User
    {
        struct size
        {
            unsigned int Width;
            unsigned int Height;
        };


        void windowResizeCallback(GLFWwindow* window, int width, int height);

        static std::string getCPUID();
        static long getMemorySize();

	class Session
	{
	public:
	    size getWindowSize();
	    void setWindow(rrts::Graphics::Window &window);
	    static Session* getInstance();

	    ~Session();
	    unsigned int getFPS();
	    void setFPS(unsigned int framecount);
	private:
	    Session();

	    rrts::Graphics::Window *window;

	    unsigned int fps = 0;

	    // Default to 720p
	    unsigned int windowWidth = 1280;
	    unsigned int windowHeight = 720;

	    static std::unique_ptr<Session> instance;

	    friend void windowResizeCallback(GLFWwindow* window, int width, int height);
	};
    }
}

#endif //RRTS_SESSION_H
