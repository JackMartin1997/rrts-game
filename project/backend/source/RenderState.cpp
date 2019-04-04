#include <RenderState.h>
#include <glm.hpp>
#include <ext.hpp>
#include <Session.h>

void rrts::Graphics::RenderState::setShader(rrts::Graphics::Shader *instance)
{
	shaderInstance = instance;
}

rrts::Graphics::Shader *rrts::Graphics::RenderState::getShader()
{
	return shaderInstance;
}

void rrts::Graphics::RenderState::setTexture(rrts::Graphics::Texture *instance)
{
	textureInstance = instance;
}

rrts::Graphics::RenderState::RenderState()
{
//	model = glm::mat4(1.0f);
//	projection = glm::mat4(1.0f);
//	projection = glm::ortho( 0.0f, (float) rrts::User::Session::getInstance()->getWindowSize().Width, 0.0f,
//	                         (float)rrts::User::Session::getInstance()->getWindowSize().Height, 0.0f, 100.0f );
//	view = glm::mat4(1.0f);
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
}