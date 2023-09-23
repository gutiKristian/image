#version 450

// Here we specified in variable and it's locaiton
layout(location = 0) in vec3 position;

// we don't have to specify the location tho
in vec3 dummy; 
/*
is a valid declaration
then in opengl we can acquire it's location using
glGetAttribLocation(shaderProgram, "dummy")
*/

// Uniforms
/*
- used for passing data from CPU to GPU shaders.
- they are global, one uniform for entire shader program
*/
uniform vec4 triangleColor;
//* Even though we declared this uniform here, we can access it in fragment shader as well (as mentioned it's global)
//* although this is not a good practice! and we should put the declaration inside the fragment shader to make the code more readable

void main()
{
    // Already in NDC
    gl_Position = vec4(position, 1.0);
}