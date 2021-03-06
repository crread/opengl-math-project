//
// Created by berthelot Mickael on 11/05/2021.
//

#ifndef OPENGL_PROJECT_OBJLOADER_H
#define OPENGL_PROJECT_OBJLOADER_H

#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glew.h>
#include <list>

#include "./glm/glm.hpp"
#include "./glm/vec3.hpp"
#include "./glm/vec4.hpp"

typedef struct DataObj {
    std::vector< unsigned int> vertexIndices;
    std::vector< unsigned int> uvIndices;
    std::vector< unsigned int> normalIndices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> vertices;
} DataObj;

class ObjLoader {
public:
    ObjLoader(const char *filename) : filename(filename)
    {
        this->data = new DataObj();
    };
    void load_obj() const;

    DataObj *data;

    const char * filename;
};


#endif //OPENGL_PROJECT_OBJLOADER_H
