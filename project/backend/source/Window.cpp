#include <Window.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Session.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

rrts::Graphics::Window::Window(int width, int height)
{
	createWindow(width, height);
	rrts::User::Session::getInstance()->setWindow(*this);
}

rrts::Graphics::Window::Window(int width, int height, std::function<void()> callback)
{
	createWindow(width, height);
	setFrameCallBack(std::move(callback));
}

rrts::Graphics::Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void rrts::Graphics::Window::swapBuffer()
{
	glfwSwapBuffers(window);
	glFlush();
}

void rrts::Graphics::Window::pollEvents()
{
	glfwPollEvents();
}

void rrts::Graphics::Window::WhileRunning(std::function<void()> callback)
{
	setFrameCallBack(std::move(callback));

#ifdef EMSCRIPTEN
	emscripten_set_main_loop_arg(rrts::Graphics::frame, this, 0, true);
#else
	while (!glfwWindowShouldClose(window)) {
		frameCallback();
	}
#endif
}
#ifndef EMSCRIPTEN
void GLAPIENTRY MessageCallback( GLenum source,
	GLenum type, GLuint id, GLenum severity,
	GLsizei length, const GLchar* message, const void* userParam )
{
	fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
	( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
	type, severity, message );
}
#endif

void rrts::Graphics::Window::createWindow(int width, int height)
{
	if (!glfwInit()) {
		std::cout << "GLFW failed to initialize \n";
	}

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
	if (!window) {
		// Window or OpenGL context creation failed
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	GLenum err=glewInit();
	if(err!=GLEW_OK) {
		std::cout << "glewInit failed: " << glewGetErrorString(err) << std::endl;
		exit(1);
	}
#ifndef EMSCRIPTEN
	glEnable              ( GL_DEBUG_OUTPUT );
	glDebugMessageCallback( MessageCallback, 0 );
#endif
}

void rrts::Graphics::Window::runFrame()
{
	frameCallback();
}

void rrts::Graphics::Window::setFrameCallBack(std::function<void()> callback)
{
	frameCallback = std::move(callback);
}

void rrts::Graphics::Window::clear(float r, float g, float b, float a)
{
	glViewport(0, 0, rrts::User::Session::getInstance()->getWindowSize().Width,
		rrts::User::Session::getInstance()->getWindowSize().Height);
	glClearColor(r, g, b, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void rrts::Graphics::Window::clear()
{
	clear(0.f,0.f,0.f,1.f);
}
