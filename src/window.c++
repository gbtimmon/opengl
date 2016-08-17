#ifndef _WINDOW_C
#define _WINDOW_C

#define GLEW_STATIC
#include <GL/glew.h>
#include <glfw3.h>
#include <iostream>

#include "shader.h"

#define COLOR_CLEAR .2f, .3f, .3f, 1.f 

GLFWwindow* window = NULL;
GLuint VBO;
int height, width; 

GLfloat vertex[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f,
};
void key_callback( GLFWwindow* window, int key, int scancode, int action, int mode ){
    std::cout << "Key pressed! " << std::endl;
    if( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose( window, GL_TRUE );
};

int main( void ) {
   glfwInit();
   glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 ); 
   glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 ); 
   glfwWindowHint( GLFW_OPENGL_PROFILE       , GLFW_OPENGL_CORE_PROFILE ); 
   glfwWindowHint( GLFW_RESIZABLE            , GL_FALSE ); 
 
   window = glfwCreateWindow( 800, 600, "LearnOpenGL", NULL, NULL ); 

   if( window == NULL ){
       std::cout << "Failed to create GLFW Window!" << std::endl;
       glfwTerminate(); 
       return -1; 
   }; 

   glfwMakeContextCurrent( window ) ; 

   glewExperimental = GL_TRUE; 

   if( glewInit() != GLEW_OK ) 
   { 
       std::cout << "Failed to inti GLEW" << std::endl;
       return -1; 
   }
   
   glfwGetFramebufferSize( window, &width, &height ); 
   glViewport(0, 0, width, height);   

   loadShader();

   glfwSetKeyCallback( window, key_callback ) ;
   glClearColor( COLOR_CLEAR );

   glGenBuffers(1, &VBO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO); 
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

   while( ! glfwWindowShouldClose( window ) )
   {
       glfwPollEvents(); 

       glClear( GL_COLOR_BUFFER_BIT );

       glfwSwapBuffers(window);
   }

   glfwTerminate();
   return 0; 
};
#endif

