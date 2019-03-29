#version 300 es
precision mediump float;
in vec3 fr_position;
in vec3 fr_colour;
in vec2 fr_texcoord;

out vec4 FragColor;

void main()
{
	FragColor = vec4(fr_colour, 1.f);
}