#ifndef RRTS_WINDOW_H
#define RRTS_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>

namespace rrts
{
    namespace User
    {
        class Session;
    }
    namespace Graphics
    {
#ifdef EMSCRIPTEN
	static void frame(void* inst);
#endif

	class Window
	{
	public:
	    /**
	     * Creates window and initializes opengl 3.3
	     * @param width
	     * @param height
	     */
	    Window(int width, int height);

	    /**
	     * Creates window, initializes opengl and sets the frame callback
	     * @param width
	     * @param height
	     * @param callback
	     */
	    Window(int width, int height, std::function<void()> callback);

	    ~Window();

	    /**
	     * swaps the window buffer
	     */
	    void swapBuffer();

	    /**
	     * Polls events and updates the input manager
	     * @warning program will halt if not called inside the game loop
	     */
	    void pollEvents();

	    /**
	     * Window while loop, this has to be the main game loop for the sake of compatibility
	     * @param callback
	     */
	    void WhileRunning(std::function<void()> callback);

	    /**
	     * Clears the screen to black
	     */
	    void clear();

	    /**
	     * Clears the screen and sets the colour to the rgb values inputted
	     * @param r
	     * @param g
	     * @param b
	     * @param a
	     */
	    void clear(float r, float g, float b, float a);

	private:

	    void createWindow(int width, int height);

	    void setFrameCallBack(std::function<void()> callback);

	    void runFrame();

#ifdef EMSCRIPTEN
	    friend void frame(void* inst);
#endif
	    GLFWwindow *window;
	    std::function<void()> frameCallback;

	    friend rrts::User::Session;
	};

#ifdef EMSCRIPTEN
	static void frame(void* inst)
	{
		auto win = static_cast<Window *>(inst);

		win->runFrame();
	}
#endif
    }
}
#endif
