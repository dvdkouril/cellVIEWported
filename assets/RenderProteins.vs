#version 410

layout (location = 0) in vec3 pos;

uniform mat4 ciModelViewProjection;

void main(void)
{
  gl_Position = ciModelViewProjection * vec4(pos, 1);
}
