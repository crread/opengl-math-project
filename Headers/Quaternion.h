//
// Created by berthelot Mickael on 08/05/2021.
//

#ifndef OPENGL_PROJECT_QUATERNION_H
#define OPENGL_PROJECT_QUATERNION_H

#include "./glm/glm.hpp"
#include "./glm/vec3.hpp"
#include "./glm/vec4.hpp"

class Quaternion {

public:
    Quaternion();

    void operator+(const Quaternion quat);
    //void rotation(glm::mat4 mat);
    void normalization();
    void rotation(const glm::mat4 &rotationMatrix);
    void Conjugation();
    void operator* (const Quaternion rq);
    glm::mat4 QuaterniontoMatrix();
    float produitsqualaire(const glm::mat4 &mat);
    Quaternion MatrixtoQuaternion(const glm::mat4 &src);
    float x;
    float y;
    float z;
    float w;
};

#endif //OPENGL_PROJECT_QUATERNION_H