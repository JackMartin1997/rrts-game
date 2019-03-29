#include <Session.h>
#include <Window.h>
#include <GL/glew.h>
#include <iostream>
std::unique_ptr<rrts::User::Session> rrts::User::Session::instance;

#ifndef EMSCRIPTEN
#ifdef linux

std::string rrts::User::getCPUID()
{
	// TODO: get cpu information from proc

	return "not implemented";
}

long rrts::User::getMemorySize()
{
	// TODO: get amount of memory in MB from proc

	return 0;
}
#endif
#endif
#ifdef EMSCRIPTEN

std::string rrts::User::getCPUID()
{
	// TODO: get cpu information somehow

	return "not implemented";
}

long rrts::User::getMemorySize()
{
	// TODO: get amount of memory in MB somehow

	return 0;
}

#endif

void rrts::User::windowResizeCallback(GLFWwindow *window, int width, int height)
{
	rrts::User::Session::getInstance()->windowWidth = static_cast<unsigned int>(width);
	rrts::User::Session::getInstance()->windowHeight = static_cast<unsigned int>(height);
}

rrts::User::size rrts::User::Session::getWindowSize()
{
	return {windowWidth, windowHeight};
}

rrts::User::Session *rrts::User::Session::getInstance()
{
	if (instance == nullptr)
		instance.reset(new Session());

	return instance.get();
}

void rrts::User::Session::setWindow(rrts::Graphics::Window &window)
{
	this->window = &window;
	glfwSetWindowSizeCallback(window.window, &windowResizeCallback);
}

rrts::User::Session::Session()
{
	int textureUnits = 0;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &textureUnits);

	std::cout << "New Session Started" << std::endl
		<< "Operating System: " << OS_VERSION << std::endl
		<< "CPU: " << getCPUID() << std::endl
		<< "Memory: " << getMemorySize() << "MB" << std::endl
		<< "Max Texture Units: " << textureUnits << std::endl;
}

rrts::User::Session::~Session()
= default;
