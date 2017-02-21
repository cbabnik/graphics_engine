// Author:
// Curtis Babnik
// cbabnik@sfu.ca
// 301235515

#include "resources.h"

#include <stdexcept>
#include <cmath>
#include <cstdio>

// Implementation of various structs used by my graphics_engine

// Point2D
int& Point2D::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw std::out_of_range("idx out of range for Point2D");
   }
}
const int& Point2D::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw std::out_of_range("idx out of range for Point2D");
   }
}
Point2D Point2D::operator-(const Point2D& rhs) const{
   return Point2D(x-rhs.x, y-rhs.y);
}
Point2D Point2D::operator+(const Point2D& rhs) const{
   return Point2D(x+rhs.x, y+rhs.y);
}
Point2DF Point2D::operator*(const float& rhs) const{
   return Point2DF(x*rhs, y*rhs);
}
Point2D& Point2D::operator-=(const Point2D& rhs){
   x-=rhs.x;
   y-=rhs.y;
   return *this;
}
Point2D& Point2D::operator+=(const Point2D& rhs){
   x+=rhs.x;
   y+=rhs.y;
   return *this;
}
int Point2D::dot(const Point2D& other) const{
   return x*other.x + y*other.y;
}
bool Point2D::operator==(const Point2D& rhs) const{
   return x==rhs.x && y==rhs.y;
}
bool Point2D::operator!=(const Point2D& rhs) const{
   return !(*this==rhs);
}
float Point2D::length() const{
   return sqrt(pow(x,2)+pow(y,2));
}
Point2DF Point2D::normalize() const{
   float len = length();
   return Point2DF(x/len, y/len);
}
void Point2D::print() const{
   printf("[%d  %d]\n", x, y);
}

// Point2DF
float& Point2DF::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw std::out_of_range("idx out of range for Point2DF");
   }
}
const float& Point2DF::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw std::out_of_range("idx out of range for Point2DF");
   }
}
Point2DF Point2DF::operator-(const Point2DF& rhs) const{
   return Point2DF(x-rhs.x, y-rhs.y);
}
Point2DF Point2DF::operator+(const Point2DF& rhs) const{
   return Point2DF(x+rhs.x, y+rhs.y);
}
Point2DF Point2DF::operator*(const float& rhs) const{
   return Point2DF(x*rhs, y*rhs);
}
Point2DF& Point2DF::operator-=(const Point2DF& rhs){
   x-=rhs.x;
   y-=rhs.y;
   return *this;
}
Point2DF& Point2DF::operator+=(const Point2DF& rhs){
   x+=rhs.x;
   y+=rhs.y;
   return *this;
}
Point2DF& Point2DF::operator*=(const float& rhs){
   x*=rhs;
   y*=rhs;
   return *this;
}
float Point2DF::dot(const Point2DF& other) const{
   return x*other.x + y*other.y;
}
bool Point2DF::operator==(const Point2DF& rhs) const{
   return abs(x-rhs.x)<TOLERANCE && abs(y-rhs.y)<TOLERANCE;
}
bool Point2DF::operator!=(const Point2DF& rhs) const{
   return !(*this==rhs);
}
Point2D Point2DF::truncate() const{
   return Point2D(int(x), int(y));
}
Point2D Point2DF::round() const{
   return Point2D(std::round(x), std::round(y));
}
float Point2DF::length() const{
   return sqrt(pow(x,2)+pow(y,2));
}
Point2DF Point2DF::normalize() const{
   float len = length();
   return Point2DF(x/len, y/len);
}
void Point2DF::print() const{
   printf("[%.2f  %.2f]\n", x, y);
}

// Point3D
int& Point3D::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw std::out_of_range("idx out of range for Point3D");
   }
}
const int& Point3D::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw std::out_of_range("idx out of range for Point3D");
   }
}
Point3D Point3D::operator-(const Point3D& rhs) const{
   return Point3D(x-rhs.x, y-rhs.y, z-rhs.z);
}
Point3D Point3D::operator+(const Point3D& rhs) const{
   return Point3D(x+rhs.x, y+rhs.y, z+rhs.z);
}
Point3DF Point3D::operator*(const float& rhs) const{
   return Point3DF(x*rhs, y*rhs, z*rhs);
}
Point3D& Point3D::operator-=(const Point3D& rhs){
   x-=rhs.x;
   y-=rhs.y;
   z-=rhs.z;
   return *this;
}
Point3D& Point3D::operator+=(const Point3D& rhs){
   x+=rhs.x;
   y+=rhs.y;
   z+=rhs.z;
   return *this;
}
int Point3D::dot(const Point3D& other) const{
   return x*other.x + y*other.y + z*other.z;
}
Point3D Point3D::cross(const Point3D& other) const{
   return Point3D(y*other.z - z*other.y,
                  z*other.x - x*other.z,
                  x*other.y - y*other.x);
}
bool Point3D::operator==(const Point3D& rhs) const{
   return x==rhs.x && y==rhs.y && z==rhs.z;
}
bool Point3D::operator!=(const Point3D& rhs) const{
   return !(*this==rhs);
}
bool Point3D::operator<(const Point3D& rhs) const{
   return z<rhs.z;
}
bool Point3D::operator>(const Point3D& rhs) const{
   return z>rhs.z;
}
bool Point3D::operator<=(const Point3D& rhs) const{
   return z<=rhs.z;
}
bool Point3D::operator>=(const Point3D& rhs) const{
   return z>=rhs.z;
}
float Point3D::length() const{
   return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}
Point3DF Point3D::normalize() const{
   float len = length();
   return Point3DF(x/len, y/len, z/len);
}
void Point3D::print() const{
   printf("[%d  %d  %d]\n", x, y, z);
}

// Point3DF
float& Point3DF::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw std::out_of_range("idx out of range for Point3DF");
   }
}
const float& Point3DF::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw std::out_of_range("idx out of range for Point3DF");
   }
}
Point3DF Point3DF::operator-(const Point3DF& rhs) const{
   return Point3DF(x-rhs.x, y-rhs.y, z-rhs.z);
}
Point3DF Point3DF::operator+(const Point3DF& rhs) const{
   return Point3DF(x+rhs.x, y+rhs.y, z+rhs.z);
}
Point3DF Point3DF::operator*(const float& rhs) const{
   return Point3DF(x*rhs, y*rhs, z*rhs);
}
Point3DF& Point3DF::operator-=(const Point3DF& rhs){
   x-=rhs.x;
   y-=rhs.y;
   z-=rhs.z;
   return *this;
}
Point3DF& Point3DF::operator+=(const Point3DF& rhs){
   x+=rhs.x;
   y+=rhs.y;
   z+=rhs.z;
   return *this;
}
Point3DF& Point3DF::operator*=(const float& rhs){
   x*=rhs;
   y*=rhs;
   z*=rhs;
   return *this;
}
float Point3DF::dot(const Point3DF& other) const{
   return x*other.x + y*other.y + z*other.z;
}
Point3DF Point3DF::cross(const Point3DF& other) const{
   return Point3DF(y*other.z - z*other.y,
                   z*other.x - x*other.z,
                   x*other.y - y*other.x);
}
bool Point3DF::operator==(const Point3DF& rhs) const{
   return abs(x-rhs.x)<TOLERANCE &&
          abs(y-rhs.y)<TOLERANCE &&
          abs(z-rhs.z)<TOLERANCE;
}
bool Point3DF::operator!=(const Point3DF& rhs) const{
   return !(*this==rhs);
}
bool Point3DF::operator<(const Point3DF& rhs) const{
   return z<rhs.z;
}
bool Point3DF::operator>(const Point3DF& rhs) const{
   return z>rhs.z;
}
bool Point3DF::operator<=(const Point3DF& rhs) const{
   return rhs.z-z > -TOLERANCE;
}
bool Point3DF::operator>=(const Point3DF& rhs) const{
   return z-rhs.z > -TOLERANCE;
}
Point3D Point3DF::truncate() const{
   return Point3D(int(x), int(y), int(z));
}
Point3D Point3DF::round() const{
   return Point3D(std::round(x), std::round(y), std::round(z));
}
float Point3DF::length() const{
   return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}
Point3DF Point3DF::normalize() const{
   float len = length();
   return Point3DF(x/len, y/len, z/len);
}
void Point3DF::print() const{
   printf("[%.2f  %.2f  %.2f]\n", x, y, z);
}

// Point RHS functions
Point2DF operator*(const float& lhs, const Point2D&  rhs){
   return Point2DF(lhs*rhs.x, lhs*rhs.y);
}
Point2DF operator*(const float& lhs, const Point2DF&  rhs){
   return Point2DF(lhs*rhs.x, lhs*rhs.y);
}
Point3DF operator*(const float& lhs, const Point3D&  rhs){
   return Point3DF(lhs*rhs.x, lhs*rhs.y, lhs*rhs.z);
}
Point3DF operator*(const float& lhs, const Point3DF&  rhs){
   return Point3DF(lhs*rhs.x, lhs*rhs.y, lhs*rhs.z);
}

// ------
// Matrix
// ------
Matrix::Matrix(char type){
   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         m[i][j] = 0;
   switch(type)
   {
   case '0': // 0 matrix
   case 'z':
   case 'Z':
      break;
   case 'I': // identity
   case 'i':
   case '1':
      m[0][0] = 1;
      m[1][1] = 1;
      m[2][2] = 1;
      m[3][3] = 1;
      break;
   case 'F': // flipped vertically
   case 'f':
   case 'v':
   case 'V':
      m[0][0] = 1;
      m[1][1] = -1;
      m[2][2] = 1;
      m[3][3] = 1;
      break;
   case 'M': // flipped horizontally (mirrored)
   case 'm':
   case 'h':
   case 'H':
      m[0][0] = 1;
      m[1][1] = -1;
      m[2][2] = 1;
      m[3][3] = 1;
      break;
   default:
      throw std::invalid_argument("bad type for matrix");
   }
}
Matrix Matrix::TranslationMatrix(float x, float y, float z){
   Matrix M;
   M[0][3] = x;
   M[1][3] = y;
   M[2][3] = z;

   return M;
}
Matrix Matrix::ScaleMatrix(float x, float y, float z){
   Matrix M;
   M[0][0] = x;
   M[1][1] = y;
   M[2][2] = z;

   return M;
}
Matrix Matrix::RotationMatrix(char axis, float degrees){
   Matrix M;
   switch(axis)
   {
   case 'x':
   case 'X':
      M[1][1] = M[1][1]*cos(degrees/180*M_PI);
      M[1][2] =-M[2][2]*sin(degrees/180*M_PI);
      M[2][1] = M[1][1]*sin(degrees/180*M_PI);
      M[2][2] = M[2][2]*cos(degrees/180*M_PI);
      break;
   case 'y':
   case 'Y':
      M[2][2] = M[2][2]*cos(degrees/180*M_PI);
      M[2][0] = M[0][0]*sin(degrees/180*M_PI);
      M[0][2] =-M[2][2]*sin(degrees/180*M_PI);
      M[0][0] = M[0][0]*cos(degrees/180*M_PI);
      break;
   case 'z':
   case 'Z':
      M[0][0] = M[2][2]*cos(degrees/180*M_PI);
      M[0][1] = M[1][1]*sin(degrees/180*M_PI);
      M[1][0] =-M[2][2]*sin(degrees/180*M_PI);
      M[1][1] = M[1][1]*cos(degrees/180*M_PI);
      break;
   default:
      throw;
   }

   return M;
}
float* Matrix::operator[](int idx){
   return m[idx];
}
const float* Matrix::operator[](int idx) const{
   return m[idx];
}
bool Matrix::operator==(const Matrix& rhs) const{
   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         if( abs(m[i][j] - rhs[i][j]) > TOLERANCE )
            return false;
   return true;
}
bool Matrix::operator!=(const Matrix& rhs) const{
   return !(*this==rhs);
}
Matrix Matrix::operator*(const Matrix& rhs) const{
   Matrix res('0');

   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         for(int k = 0; k < 4; k++)
            res[i][j] += m[i][k]*rhs[k][j];

   return res;
}
Point3DF Matrix::operator*(const Point3DF& rhs) const{
   Point3DF res(0,0,0);

   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
         res[i] += m[i][j]*rhs[j];
   for(int i = 0; i < 3; i++)
      res[i] += m[i][3];

   return res;
}
Point3DF Matrix::operator*(const Point3D& rhs) const{
   return (*this)*Point3DF(rhs);
}
Matrix& Matrix::operator*=(const Matrix& rhs){
   float res[4][4];
   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         res[i][j] = 0;

   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         for(int k = 0; k < 4; k++)
            res[i][j] += m[i][k]*rhs[k][j];

   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         m[i][j] = res[i][j];
   return *this;
}
Matrix Matrix::translate(float x, float y, float z) const{
   return TranslationMatrix(x, y, z)*(*this);
}
Matrix Matrix::scale(float x, float y, float z) const{
   return ScaleMatrix(x, y, z)*(*this);
}
Matrix Matrix::rotate(char axis, float degrees) const{
   return RotationMatrix(axis, degrees)*(*this);
}
Matrix Matrix::transpose() const{
   Matrix M('0');

   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         M[i][j] = m[j][i];

   return M;
}
Matrix Matrix::invert() const{
   // inversion works by guassian elimination on an augmented matrix
   Matrix copyM('0');
   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         copyM[i][j] = m[i][j];
   Matrix inverseM;

   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         if(i!=j){
            float ratio = copyM[j][i]/copyM[i][i];
            for(int k = 0; k < 4; k++){
               inverseM.m[j][k] -= ratio * inverseM.m[i][k];
               copyM.m[j][k] -= ratio * copyM.m[i][k];
            }
         }
   for(int i = 0; i < 4; i++){
      float scale = copyM.m[i][i];
      for(int j = 0; j < 4; j++)
         inverseM.m[i][j] /= scale;
   }

   return inverseM;
}
void Matrix::print() const{
   for(int i = 0; i < 4; i++){
      printf("[ ");
      for(int j = 0; j < 3; j++)
         if(m[i][j] < 0)
            printf("%.3f  ", m[i][j]);
         else
            printf(" %.3f  ", m[i][j]);
      printf("]\n");
   }
}

Point3DF operator*(const Point3DF& lhs, const Matrix& rhs){
   Point3DF res(0,0,0);

   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
         res[i] += rhs.m[j][i]*lhs[j];
   for(int i = 0; i < 3; i++)
      res[i] += rhs.m[3][i];

   return res;
}
Point3DF operator*(const Point3D& lhs, const Matrix& rhs){
   return Point3DF(lhs)*rhs;
}

//=====
//Color
//=====
Color::Color(){
   this->color = 0;
}
Color::Color(unsigned int color){
   this->color = color;
}
Color::Color(uint8_t r, uint8_t g, uint8_t b);
   colorComponent.alpha = 0;
   colorComponent.red = r;
   colorComponent.blue = b;
   colorComponent.green = g;
}
uint8_t& Color::operator[](int idx){
   switch(idx)
   {
      case 0: return colorComponent.red;
      case 1: return colorComponent.blue;
      case 2: return colorComponent.green;
      default: throw std::out_of_range("idx out of range for Color");
   }
}
const uint8_t& Color::operator[](int idx) const{
   switch(idx)
   {
      case 0: return colorComponent.red;
      case 1: return colorComponent.blue;
      case 2: return colorComponent.green;
      default: throw std::out_of_range("idx out of range for Color");
   }
}
Color& Color::operator=(unsigned int rhs){
   this->color = rhs;
   return (*this);
}
bool Color::operator==(const Color& rhs) const{
   return (colorComponent.red == rhs.colorComponent.red
        && colorComponent.blue == rhs.colorComponent.blue
        && colorComponent.green == rhs.colorComponent.green);
}
bool Color::operator!=(const Color& rhs) const{
   return !((*this)==rhs);
}
bool Color::operator==(unsigned int rhs) const{
   return ((color&rgbMask) == (rhs&rgbMask));
}
bool Color::operator!=(unsigned int rhs) const{
   return !((*this)==rhs);
}
Color Color::operator*(float rhs) const{
   Color newColor;
   newColor.colorComponent.red  = ((int)(colorComponent.red*rhs)  > 255 ?
                                   255 : (int)(colorComponent.red*rhs));
   newColor.colorComponent.blue = ((int)(colorComponent.blue*rhs) > 255 ?
                                   255 : (int)(colorComponent.blue*rhs));
   newColor.colorComponent.green=((int)(colorComponent.green*rhs) > 255 ?
                                   255 :(int)(colorComponent.green*rhs));
   return newColor;
}
Color& Color::operator*=(float rhs){
   colorComponent.red  = ((int)(colorComponent.red*rhs)  > 255 ?
                          255 : (int)(colorComponent.red*rhs));
   colorComponent.blue = ((int)(colorComponent.blue*rhs) > 255 ?
                          255 : (int)(colorComponent.blue*rhs));
   colorComponent.green=((int)(colorComponent.green*rhs) > 255 ?
                          255 :(int)(colorComponent.green*rhs));
   return (*this);
}
Color Color::operator+(const Color& rhs) const{
   Color newColor;
   newColor.colorComponent.red =
                           ((colorComponent.red + rhs.colorComponent.red) > 255 ?
                            255 : (colorComponent.red + rhs.colorComponent.red));
   newColor.colorComponent.blue =
                           ((colorComponent.blue + rhs.colorComponent.blue) > 255 ?
                            255 : (colorComponent.blue + rhs.colorComponent.blue));
   newColor.colorComponent.green =
                           ((colorComponent.green + rhs.colorComponent.green) > 255 ?
                            255 : (colorComponent.green + rhs.colorComponent.green));
   return newColor;
}
Color& Color::operator+=(const Color& rhs){
   colorComponent.red = ((colorComponent.red + rhs.colorComponent.red) > 255 ?
                         255 : (colorComponent.red + rhs.colorComponent.red));
   colorComponent.blue = ((colorComponent.blue + rhs.colorComponent.blue) > 255 ?
                          255 : (colorComponent.blue + rhs.colorComponent.blue));
   colorComponent.green = ((colorComponent.green + rhs.colorComponent.green) > 255 ?
                           255 : (colorComponent.green + rhs.colorComponent.green));
   return (*this);
}
Color Color::operator-(const Color& rhs) const{
   Color newColor;
   newColor.colorComponent.red =
                           ((colorComponent.red - rhs.colorComponent.red) < 0 ?
                            0 : (colorComponent.red - rhs.colorComponent.red));
   newColor.colorComponent.blue =
                           ((colorComponent.blue - rhs.colorComponent.blue) < 0 ?
                            0 : (colorComponent.blue - rhs.colorComponent.blue));
   newColor.colorComponent.green =
                           ((colorComponent.green - rhs.colorComponent.green) < 0 ?
                            0 : (colorComponent.green - rhs.colorComponent.green));
   return newColor;
}
Color& Color::operator-=(const Color& rhs){
   colorComponent.red = ((colorComponent.red - rhs.colorComponent.red) < 0 ?
                         0 : (colorComponent.red - rhs.colorComponent.red));
   colorComponent.blue = ((colorComponent.blue - rhs.colorComponent.blue) < 0 ?
                          0 : (colorComponent.blue - rhs.colorComponent.blue));
   colorComponent.green = ((colorComponent.green - rhs.colorComponent.green) < 0 ?
                           0 : (colorComponent.green - rhs.colorComponent.green));
   return (*this);
}
void Color::print() const{
   printf("Color: 0x%x\n", color&rgbMask);
   printf("   alpha: %d\n", colorComponent.alpha);
   printf("   red  : %d\n", colorComponent.red);
   printf("   green: %d\n", colorComponent.green);
   printf("   blue : %d\n", colorComponent.blue);
}
