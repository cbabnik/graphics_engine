// Author:
// Curtis Babnik
// cbabnik@sfu.ca
// 301235515

#include "resources.h"

#include <stdexcept>
#include <cmath>

// Implementation of various structs used by my graphics_engine

// Point2D
inline int& Point2D::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw;
   }
}
inline const int& Point2D::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw;
   }
}
inline Point2D Point2D::operator-(const Point2D& rhs) const{
   return Point2D(x-rhs.x, y-rhs.y);
}
inline Point2D Point2D::operator+(const Point2D& rhs) const{
   return Point2D(x+rhs.x, y+rhs.y);
}
inline Point2DF Point2D::operator*(const float& rhs) const{
   return Point2DF(x*rhs, y*rhs);
}
inline Point2D& Point2D::operator-=(const Point2D& rhs){
   x-=rhs.x;
   y-=rhs.y;
   return *this;
}
inline Point2D& Point2D::operator+=(const Point2D& rhs){
   x+=rhs.x;
   y+=rhs.y;
   return *this;
}
inline int Point2D::dot(const Point2D& other) const{
   return x*other.x + y*other.y;
}
inline bool Point2D::operator==(const Point2D& rhs) const{
   return x==rhs.x && y==rhs.y;
}
inline bool Point2D::operator!=(const Point2D& rhs) const{
   return !(*this==rhs);
}
inline float Point2D::length() const{
   return sqrt(pow(x,2)+pow(y,2));
}
inline Point2DF Point2D::normalize() const{
   float len = length();
   return Point2DF(x/len, y/len);
}

// Point2DF
inline float& Point2DF::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw;
   }
}
inline const float& Point2DF::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      default: throw;
   }
}
inline Point2DF Point2DF::operator-(const Point2DF& rhs) const{
   return Point2DF(x-rhs.x, y-rhs.y);
}
inline Point2DF Point2DF::operator+(const Point2DF& rhs) const{
   return Point2DF(x+rhs.x, y+rhs.y);
}
inline Point2DF Point2DF::operator*(const float& rhs) const{
   return Point2DF(x*rhs, y*rhs);
}
inline Point2DF& Point2DF::operator-=(const Point2DF& rhs){
   x-=rhs.x;
   y-=rhs.y;
   return *this;
}
inline Point2DF& Point2DF::operator+=(const Point2DF& rhs){
   x+=rhs.x;
   y+=rhs.y;
   return *this;
}
inline Point2DF& Point2DF::operator*=(const float& rhs){
   x*=rhs;
   y*=rhs;
   return *this;
}
inline float Point2DF::dot(const Point2DF& other) const{
   return x*other.x + y*other.y;
}
inline bool Point2DF::operator==(const Point2DF& rhs) const{
   return abs(x-rhs.x)<TOLERANCE && abs(y-rhs.y)<TOLERANCE;
}
inline bool Point2DF::operator!=(const Point2DF& rhs) const{
   return !(*this==rhs);
}
inline Point2D Point2DF::truncate() const{
   return Point2D(int(x), int(y));
}
inline Point2D Point2DF::round() const{
   return Point2D(std::round(x), std::round(y));
}
inline float Point2DF::length() const{
   return sqrt(pow(x,2)+pow(y,2));
}
inline Point2DF Point2DF::normalize() const{
   float len = length();
   return Point2DF(x/len, y/len);
}

// Point3D
inline int& Point3D::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw;
   }
}
inline const int& Point3D::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw;
   }
}
inline Point3D Point3D::operator-(const Point3D& rhs) const{
   return Point3D(x-rhs.x, y-rhs.y, z-rhs.z);
}
inline Point3D Point3D::operator+(const Point3D& rhs) const{
   return Point3D(x+rhs.x, y+rhs.y, z-rhs.z);
}
inline Point3DF Point3D::operator*(const float& rhs) const{
   return Point3DF(x*rhs, y*rhs, z*rhs);
}
inline Point3D& Point3D::operator-=(const Point3D& rhs){
   x-=rhs.x;
   y-=rhs.y;
   z-=rhs.z;
   return *this;
}
inline Point3D& Point3D::operator+=(const Point3D& rhs){
   x+=rhs.x;
   y+=rhs.y;
   z+=rhs.z;
   return *this;
}
inline int Point3D::dot(const Point3D& other) const{
   return x*other.x + y*other.y + z*other.z;
}
inline Point3D Point3D::cross(const Point3D& other) const{
   return Point3D(y*other.z - z*other.y,
                  z*other.x - x*other.z,
                  x*other.y - y*other.x);
}
inline bool Point3D::operator==(const Point3D& rhs) const{
   return x==rhs.x && y==rhs.y && z==rhs.z;
}
inline bool Point3D::operator!=(const Point3D& rhs) const{
   return !(*this==rhs);
}
inline bool Point3D::operator<(const Point3D& rhs) const{
   return z<rhs.z;
}
inline bool Point3D::operator>(const Point3D& rhs) const{
   return z>rhs.z;
}
inline bool Point3D::operator<=(const Point3D& rhs) const{
   return z<=rhs.z;
}
inline bool Point3D::operator>=(const Point3D& rhs) const{
   return z>=rhs.z;
}
inline float Point3D::length() const{
   return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}
inline Point3DF Point3D::normalize() const{
   float len = length();
   return Point3DF(x/len, y/len, z/len);
}

// Point3DF
inline float& Point3DF::operator[](int idx){
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw;
   }
}
inline const float& Point3DF::operator[](int idx) const{
   switch(idx)
   {
      case 0: return x;
      case 1: return y;
      case 2: return z;
      default: throw;
   }
}
inline Point3DF Point3DF::operator-(const Point3DF& rhs) const{
   return Point3DF(x-rhs.x, y-rhs.y, z-rhs.z);
}
inline Point3DF Point3DF::operator+(const Point3DF& rhs) const{
   return Point3D(x+rhs.x, y+rhs.y, z-rhs.z);
}
inline Point3DF Point3DF::operator*(const float& rhs) const{
   return Point3DF(x*rhs, y*rhs, z*rhs);
}
inline Point3DF& Point3DF::operator-=(const Point3DF& rhs){
   x-=rhs.x;
   y-=rhs.y;
   z-=rhs.z;
   return *this;
}
inline Point3DF& Point3DF::operator+=(const Point3DF& rhs){
   x+=rhs.x;
   y+=rhs.y;
   z+=rhs.z;
   return *this;
}
inline Point3DF& Point3DF::operator*=(const float& rhs){
   x*=rhs;
   y*=rhs;
   z*=rhs;
   return *this;
}
inline float Point3DF::dot(const Point3DF& other) const{
   return x*other.x + y*other.y + z*other.z;
}
inline Point3DF Point3DF::cross(const Point3DF& other) const{
   return Point3DF(y*other.z - z*other.y,
                   z*other.x - x*other.z,
                   x*other.y - y*other.x);
}
inline bool Point3DF::operator==(const Point3DF& rhs) const{
   return abs(x-rhs.x)<TOLERANCE &&
          abs(y-rhs.y)<TOLERANCE &&
          abs(z-rhs.z)<TOLERANCE;
}
inline bool Point3DF::operator!=(const Point3DF& rhs) const{
   return !(*this==rhs);
}
inline bool Point3DF::operator<(const Point3DF& rhs) const{
   return z<rhs.z;
}
inline bool Point3DF::operator>(const Point3DF& rhs) const{
   return z>rhs.z;
}
inline bool Point3DF::operator<=(const Point3DF& rhs) const{
   return z<=rhs.z;
}
inline bool Point3DF::operator>=(const Point3DF& rhs) const{
   return z>=rhs.z;
}
inline Point3D Point3DF::truncate() const{
   return Point3D(int(x), int(y), int(z));
}
inline Point3D Point3DF::round() const{
   return Point3D(std::round(x), std::round(y), std::round(z));
}
inline float Point3DF::length() const{
   return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}
inline Point3DF Point3DF::normalize() const{
   float len = length();
   return Point3DF(x/len, y/len, z/len);
}

// Point RHS functions
inline Point2DF operator*(const float& lhs, const Point2D&  rhs){
   return Point2DF(lhs*rhs.x, lhs*rhs.y);
}
inline Point2DF operator*(const float& lhs, const Point2DF&  rhs){
   return Point2DF(lhs*rhs.x, lhs*rhs.y);
}
inline Point3DF operator*(const float& lhs, const Point3D&  rhs){
   return Point3DF(lhs*rhs.x, lhs*rhs.y, lhs*rhs.z);
}
inline Point3DF operator*(const float& lhs, const Point3DF&  rhs){
   return Point3DF(lhs*rhs.x, lhs*rhs.y, lhs*rhs.z);
}

