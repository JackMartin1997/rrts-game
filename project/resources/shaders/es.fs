#version 300 es
precision mediump float;
in vec3 fr_position;
in vec3 fr_colour;
in vec2 fr_texcoord;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main()
{
	FragColor = texture(ourTexture, fr_texcoord);
}