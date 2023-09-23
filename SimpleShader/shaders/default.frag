#version 450
layout(location = 0) out vec4 final_color;

// Uniforms
/*
- used for passing data from CPU to GPU shaders.
- they are global, one uniform for entire shader program
*/
uniform vec4 triangleColor;

void main()
{
    final_color = triangleColor;
}
