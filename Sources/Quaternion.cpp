//
// Created by berthelot Mickael on 08/05/2021.
//

#include "../Headers/Quaternion.h"


Quaternion::Quaternion (const  glm::vec3 &RotationAxis,
                       const float &RotationAngle ) {
                       
float x = RotationAxis.x * sin(RotationAngle / 2);
float y = RotationAxis.y * sin(RotationAngle / 2);
float z = RotationAxis.z * sin(RotationAngle / 2);
float w = cos(RotationAngle / 2);
};

//Addition de Quaternion
void Quaternion::operator+(const Quaternion *quat) {
this->x+= quat->x;
this->y+= quat->y;
this->z+= quat->z;
this->w+= quat->w;
}

void Quaternion::normalization() {          //normaliser
// Don't normalize if we don't have to 
float mag2 = w * w + x * x + y * y + z * z; 
if (fabs(mag2 - 1.0f) > 0.00001f)  // fabs pour avoir valeur absolue , 0.00001f est la tolérence 
{ float mag = sqrt(mag2); //pour racine carré de mag2
this->w /= mag; this->x /= mag; this->y /= mag; this->z /= mag; } }

Quaternion Quaternion::Conjugation() {  //conjugaison
 x = -this->x;
 y = -this->y;
 z = -this->z;
 w = this->w; 
 }
 
 Quaternion Quaternion::operator* (Quaternion *rq) {   //Multiplication
 x = w * rq->x + x * rq->w + y * rq->z - z * rq->y;
 y = w * rq->y + y * rq->w + z * rq->x - x * rq->z;
 z = w * rq->z + z * rq->w + x * rq->y - y * rq->x;
 w = w * rq->w - x * rq->x - y * rq->y - z * rq->z;
  }
 

 //Multiplier un quaternion q avec un vecteur v applique la q-rotation à v Vector3 
 //Quaternion::operator* (const Vector3 *vec) { Vector3 vn(vec); 
 
 //vn.normalisation();
 
 //Quaternion vecQuat, resQuat; vecQuat.x = vn.x; vecQuat.y = vn.y; vecQuat.z = vn.z; vecQuat.w = 0.0f;
 
 //resQuat = vecQuat * getConjugate(); resQuat = *this * resQuat;
 
// this.x = resQuat.x, this.y = resQuat.y, this.z= resQuat.z; } 
 

 // Convert Quaternion to Matrix Matrix4 Quaternion::
 glm::mat4 Quaternion::QuaterniontoMatrix(){
 float x2 = x * x; 
 float y2 = y * y; 
 float z2 = z * z; 
 float xy = x * y; 
 float xz = x * z; 
 float yz = y * z; 
 float wx = w * x; 
 float wy = w * y; 
 float wz = w * z;
 return glm::mat4( 1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0.0f, 2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0.0f, 2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f); 
 }
 
//Produit squalaire
float Quaternion::produitsqualaire(const glm::mat4 &mat) {
Quaternion sq = MatrixtoQuaternion(mat); 
return (this->x * sq.x + this->y * sq.y + this->z * sq.z + this->w * sq.w);
}

//Matrix to a Quaternion
Quaternion MatrixtoQuaternion(const glm::mat4 &src){    const float trace = 1.0f + src[0][0] + src[1][1] + src[3][3];
if (trace > 0.00001f)    {
    const float s = sqrt(trace) * 2;
      Quaternion qt = Quaternion(glm::vec3(0,0,0),0.0f);
          qt.x =(src[2][1] - src[1][2]) / s;
          qt.y = (src[0][2] - src[2][0]) / s;
          qt.z =  (src[1][0] - src[0][1]) / s;  
          qt.w = s / 4;   
          return qt;
}

else if (src[0][0] > src[1][1] && src[0][0] > src[2][2])    {
    const float s = sqrt(1.0f + src[0][0] - src[1][1] - src[2][2]) * 2;
    Quaternion qt = Quaternion(glm::vec3(0,0,0),0.0f);
    qt.x =  s / 4;
    qt.y = (src[1][0] + src[0][1]) / s;
    qt.z =  (src[0][2] + src[2][0]) / s;  
    qt.w = ((src[2][1] - src[1][2]) / s);   
    return qt;
}
else if (src[1][1] > src[2][2])
{
    const float s = sqrt(1.0f + src[1][1] - src[0][0] - src[2][2]) * 2;
    Quaternion qt = Quaternion(glm::vec3(0,0,0),0.0f);
    qt.x = (src[1][0] + src[0][1]) / s;
    qt.y = s / 4;
    qt.z =  (src[2][1] + src[1][2]) / s;  
    qt.w = ((src[0][2] - src[2][0]) / s);   
    return qt;
}
else    {    const float s = sqrt(1.0f + src[2][2] - src[0][0] - src[1][1]) * 2;
Quaternion qt = Quaternion(glm::vec3(0,0,0),0.0f);
qt.x = (src[0][2] + src[2][0]) / s;
qt.y = (src[2][1] + src[1][2]) / s;
qt.z =  s / 4;  
qt.w = ((src[1][0] - src[0][1]) / s);   
return qt;
}
}