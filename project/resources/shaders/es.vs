#version 300 es
precision mediump float;
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colour;
layout (location = 2) in vec2 texcoord;

out vec3 fr_position;
out vec3 fr_colour;
out vec2 fr_texcoord;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	fr_position = position;
	fr_colour = colour;
	fr_texcoord = texcoord;

	gl_Position = vec4(position, 1.0f);
}