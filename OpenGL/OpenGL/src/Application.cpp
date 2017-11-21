#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// If GLEW cannot init, state erorr
	if (glewInit() != GLEW_OK)
		std::cout << "ERROR! GLEW did not init." << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl; 
	
	// Positions of vertex for the triangle; NOT a "vertex"
	float positions[6] = {
	-0.5f, -0.5f, 
	 0.0f,  0.5f, 
	 0.5f, -0.5f
	};

	// Create a buffer
	unsigned int buffer; 

	// 1 = How many buffers I would like.
	// &buffer is the reference of the unsigned int 
	// that acts as an id of the generated buffer
	glGenBuffers(1, &buffer); 

	// Select the buffer
	// GL_ARRAY_BUFFER is the target. 
	// Then pass in the id of the buffer. 
	glBindBuffer(GL_ARRAY_BUFFER, buffer); 

	
	
	// Declaring the size of the buffer now.
	// 6 floats * sizeof float type in bytes  
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); 

	// Enable the vertex index
	glEnableVertexAttribArray(0); 

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); 

	

	// glBindBuffer(GL_ARRAY_BUFFER, 0); 

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		
		glDrawArrays(GL_TRIANGLES, 0, 3); 
		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
