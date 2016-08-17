#ifndef _SHADER_C
#define _SHADER_C

#define GLEW_STATIC
#include <GL/glew.h>
#include <glfw3.h>
#include <string>
#include <fstream>
#include <iostream>

#include "colors.h"

std::string shader1;

GLuint vertexShader; 
o//COMPILE A SHADER HERE
int loadShader( ) { 
    std::ifstream ifs("./shader/basic.vert");

    shader1.assign( ( std::istreambuf_iterator<char>(ifs) ),
                    ( std::istreambuf_iterator<char>()    )  );

    

};


#endif 
