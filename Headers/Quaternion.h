//
// Created by berthelot Mickael on 08/05/2021.
//

#ifndef OPENGL_PROJECT_QUATERNION_H
#define OPENGL_PROJECT_QUATERNION_H


class Quaternion {
public:
    Quaternion();
}

 void Quaternion::operator+(const Quaternion *quat);
 void Quaternion::normalization();
 Quaternion Quaternion::Conjugation();
 Quaternion Quaternion::operator* (const Quaternion *rq) const;
 glm::mat4 glm::mat4::QuaterniontoMatrix();
 float float::produitsqualaire(const glm::mat4 *mat);
 Quaternion MatrixtoQuaternion(const glm::mat4 *src);
 
 void setY(float y);

;


#endif //OPENGL_PROJECT_QUATERNION_H
