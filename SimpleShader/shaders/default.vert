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

void main()
{
    // Already in NDC
    gl_Position = vec4(position, 1.0);
}