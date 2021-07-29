#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
#include "tiny_obj_loader.h"

#include "glew/include/glew.h"
#include "GLFW/include/glfw3.h"

#include <cstdio>
#include <cmath>
#include <iostream>
#include "./GLShader.h"
#include "./Sources/Quaternion.cpp"
#include "./headers/glm/glm.hpp"
#include "./headers/glm/gtc/type_ptr.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "./stb-master/stb_image.h"

GLuint Dragon3DProgram = 0;

void Initialize(GLFWwindow* window)
{
    printf("Version OPENGL : %s\n", glGetString(GL_VERSION));
    printf("Vendor : %s\n", glGetString(GL_VENDOR));
    printf("Renderer : %s\n", glGetString(GL_RENDERER));
    printf("Version GLSL : %s\n",glGetString(GL_SHADING_LANGUAGE_VERSION));

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("Erreur OpenGL, code %d\n", error);
    }

    Dragon3DProgram = CreateShaderProgram(
                            "./../Dragon3DLight.vs.glsl",
                            "./../Dragon3DLight.fs.glsl");

}

void Terminate()
{
    DestroyProgram(Dragon3DProgram);
}

void addCube(const int coef, std::vector<float> *listData, int &index)
{
     const GLfloat g_vertex_buffer_data[] = {
            coef + -1.0f, coef + -1.0f, coef -1.0f,
            coef + -1.0f, coef + -1.0f, coef + 1.0f,
            coef + -1.0f, coef + 1.0f, coef + 1.0f,
            coef + 1.0f, coef + 1.0f, coef + -1.0f,
            coef + -1.0f, coef + -1.0f,coef + -1.0f,
            coef + -1.0f, coef + 1.0f,coef + -1.0f,
            coef + 1.0f, coef + -1.0f, coef + 1.0f,
            coef + -1.0f, coef + -1.0f, coef + -1.0f,
            coef + 1.0f, coef + -1.0f, coef + -1.0f,
            coef + 1.0f, coef + 1.0f, coef + -1.0f,
            coef + 1.0f, coef + -1.0f, coef + -1.0f,
            coef + -1.0f, coef + -1.0f, coef + -1.0f,
            coef + -1.0f, coef + -1.0f, coef + -1.0f,
            coef + -1.0f, coef + 1.0f, coef + 1.0f,
            coef + -1.0f, coef + 1.0f, coef + -1.0f,
            coef + 1.0f, coef + -1.0f, coef + 1.0f,
            coef + -1.0f, coef + -1.0f, coef + 1.0f,
            coef + -1.0f, coef + -1.0f, coef + -1.0f,
            coef + -1.0f, coef + 1.0f, coef + 1.0f,
            coef + -1.0f, coef + -1.0f, coef + 1.0f,
            coef + 1.0f, coef + -1.0f, coef + 1.0f,
            coef + 1.0f, coef + 1.0f, coef + 1.0f,
            coef + 1.0f, coef + -1.0f, coef + -1.0f,
            coef + 1.0f, coef + 1.0f, coef + -1.0f,
            coef + 1.0f, coef + -1.0f, coef + -1.0f,
            coef + 1.0f, coef + 1.0f, coef + 1.0f,
            coef + 1.0f, coef + -1.0f, coef + 1.0f,
            coef + 1.0f, coef + 1.0f, coef + 1.0f,
            coef + 1.0f, coef + 1.0f, coef + -1.0f,
            coef + -1.0f, coef + 1.0f, coef + -1.0f,
            coef + 1.0f, coef + 1.0f, coef + 1.0f,
            coef + -1.0f, coef + 1.0f, coef + -1.0f,
            coef + -1.0f, coef + 1.0f, coef + 1.0f,
            coef + 1.0f, coef + 1.0f, coef + 1.0f,
            coef + -1.0f, coef + 1.0f, coef + 1.0f,
            coef + 1.0f, coef + -1.0f, coef + 1.0f
    };

    listData->insert(listData->end(), std::begin(g_vertex_buffer_data), std::end(g_vertex_buffer_data));
    index += 12 * 3;
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_SAMPLES, 10);

    window = glfwCreateWindow(640, 480, "Dragon", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    GLenum glewError = glewInit();
    if (glewError != GLEW_NO_ERROR)
    {
        glfwTerminate();
        return -1;
    }

    tinyobj::attrib_t attribs;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string warm;
    std::string err;

    bool ret = tinyobj::LoadObj(&attribs, &shapes, &materials, &warm, &err, "./../models/suzanne.obj", nullptr, true, true);

    if (!warm.empty()) {
        std::cout<<warm<<std::endl;
    }

    if (!err.empty()) {
        std::cout<<err<<std::endl;
    }

    if (!ret) {
        exit(1);
    }

    std::vector<float> listData;

    int index = 0;

    for (auto & shape : shapes){

        int index_offset = 0;

        for (int j = 0; j < shape.mesh.num_face_vertices.size(); j++) {
            int fv = shape.mesh.num_face_vertices[j];

            for (int k = 0; k < fv; k++) {
                tinyobj::index_t idx = shape.mesh.indices[index_offset + k];

                listData.push_back(attribs.vertices[3 * idx.vertex_index+0]);
                listData.push_back(attribs.vertices[3*idx.vertex_index+1]);
                listData.push_back(attribs.vertices[3*idx.vertex_index+2]);

                if (!attribs.normals.empty()) {
                    listData.push_back(attribs.normals[3*idx.normal_index+0]);
                    listData.push_back(attribs.normals[3*idx.normal_index+1]);
                    listData.push_back(attribs.normals[3*idx.normal_index+2]);
                }

                if (!attribs.texcoords.empty()) {
                    listData.push_back(attribs.texcoords[2*idx.texcoord_index+0]);
                    listData.push_back(attribs.texcoords[2*idx.texcoord_index+1]);
                }
            }
            index_offset += fv;
            index += fv;
        }
    }

    Initialize(window);

    int h, w, nrChannels;
    uint8_t *data = stbi_load("./../Textures/grass_grass_0070_03.jpg", &w, &h, &nrChannels, STBI_rgb_alpha);

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    }

    addCube(3, &listData, index);
    addCube(-3, &listData, index);

    //Quaternion declaration
    Quaternion q = Quaternion();


    //--------------------------------


    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetWindowSize(window, &width, &height);

        glViewport(0, 0, width, height);

        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glEnable(GL_MULTISAMPLE);
        glDepthFunc(GL_LESS);

        const GLint POSITION = glGetAttribLocation( Dragon3DProgram, "a_position");
        glEnableVertexAttribArray(POSITION);
        glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, &listData[0]);

        const GLint texAttrib = glGetAttribLocation(Dragon3DProgram,"a_texcoords");
        glEnableVertexAttribArray(texAttrib);
        glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, &listData[0]);

        glUseProgram(Dragon3DProgram);

        float time = glfwGetTime();
        const int timeLocation = glGetUniformLocation(Dragon3DProgram, "u_time");
        glUniform1f(timeLocation, time);

        float rotationMatrix[] = {
                //la mat 4 a balancer
            cosf(time), 0.f, -sinf(time), 0.0f,
            0.0f, 1.0f, 0.0f, 0.f,
            sinf(time), 0.f, cosf(time), 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        const int rotationLocation = glGetUniformLocation(
                    Dragon3DProgram,
                    "u_rotationMatrix"

        );
        //Mat déclaration
        glm::mat4 mat = {  cosf(time), 0.f, -sinf(time), 0.0f,
                              0.0f, 1.0f, 0.0f, 0.f,
                              sinf(time), 0.f, cosf(time), 0.0f,
                              0.0f, 0.0f, 0.0f, 1.0f};

        glm::mat4 mat2 = {  cosf(time), 8.f, -sinf(time), 5.5f,
                           8.0f, 1.0f, 8.0f, 8.f,
                           sinf(time), 8.f, cosf(time), 8.2f,
                           4.9f, 8.0f, 8.0f, 8.0f};


        glm::mat4 mat3 = {  cosf(time), 0.f, -sinf(time), 0.0f,
                           0.0f, 0.05f, 0.0f, 0.f,
                           sinf(time), 0.f, cosf(time), 0.0f,
                           0.0f, 0.0f, 0.0f, 0.05f};
        //-----------------------------------------
        q = q.MatrixtoQuaternion(mat);

        //Déclaration de q2
        Quaternion q2 = Quaternion();
        q2 = q2.MatrixtoQuaternion(mat2);
        Quaternion q3 = Quaternion();
        q3 = q3.MatrixtoQuaternion(mat3);

        //Addition de quaternion
        //q+q2;

        //Multiplication de quaternion
        //q*q2;
        //q*q3;

        //Let's set rotation !!!
        glUniformMatrix4fv(rotationLocation,
                            1,
                            GL_TRUE,
//                           rotationMatrix

//QUaternion en matrice et matrice en glfloat
                           glm::value_ptr(q.QuaterniontoMatrix())
                            );

        float translationMatrix[] = {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            cosf(time), 0.0f, -20.0f, 1.0f
        };

        const int translationLocation = glGetUniformLocation(
                    Dragon3DProgram,
                    "u_translationMatrix"
        );

        glUniformMatrix4fv(translationLocation,
                            1,
                            GL_FALSE,
                            translationMatrix
                            );

        float fov = 30.0f;
        float radianFov = fov * (float)(M_PI / 180.0);
        float aspect = (float)width / (float)height;
        float znear = 0.1f, zfar = 500.0f;
        float cot = 1.0f / tanf(radianFov / 2.0f);

        float projectionMatrix[] = {
            cot/aspect, 0.0f, 0.0f, 0.0f,
            0.0f, cot, 0.0f, 0.0f,
            0.0f, 0.0f, -(znear+zfar)/(zfar-znear), -1.0f,
            0.0f, 0.0f, -(2.0f*znear*zfar)/(zfar-znear), 0.0f
        };

        const int projectionLocation = glGetUniformLocation(
                    Dragon3DProgram,
                    "u_projectionMatrix"
        );

        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, projectionMatrix);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glDrawArrays(GL_TRIANGLES, listData[0], index);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    Terminate();
    glfwTerminate();
    return 0;
}
