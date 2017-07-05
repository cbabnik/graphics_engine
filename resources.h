// Author:
// Curtis Babnik
// cbabnik@sfu.ca
// 301235515

#ifndef RESOURCES_H
#define RESOURCES_H

// Declaration of various data structures used by my graphics_engine
// * I'm considering turning this into a git submodule

#include <cstdint>

// forward declaration
struct Point2D;
struct Point2DF;
struct Point3D;
struct Point3DF;
class Matrix;
class Color;

// Points (or vectors)
// + F indicates float form, as opposed to int
// + Comparison is defined in terms of depth
// - '>>' and '<<' could be added to mean "the vector from p1 to p2"
// - Conversions between 2D and 3D could be defined
// - Some cross struct interaction might be useful
struct Point2D
{
   // constructors
   Point2D(int xVal, int yVal) : x(xVal), y(yVal) {};
   static Point2D random(int x1, int y1, int x2, int y2);
   // members
   int x;
   int y;
   // member access
         int& operator[](int idx);
   const int& operator[](int idx) const;
   // arithmetic
   Point2D  operator- (const Point2D& rhs) const;
   Point2D  operator+ (const Point2D& rhs) const;
   Point2DF operator* (const float&   rhs) const;
   Point2D& operator-=(const Point2D& rhs);
   Point2D& operator+=(const Point2D& rhs);
   int      dot       (const Point2D& other) const;
   // comparison
   bool operator==(const Point2D& rhs) const;
   bool operator!=(const Point2D& rhs) const;
   // other
   float length() const;
   Point2DF normalize() const;
   // debugging
   void print() const;
};
struct Point2DF
{
   // constants
   static constexpr float TOLERANCE = 0.01;
   // constructors
   Point2DF(float xVal, float yVal) : x(xVal), y(yVal) {};
   Point2DF(Point2D p) : x(p.x), y(p.y) {};
   static Point2DF random(float x1, float y1, float x2, float y2);
   // members
   float x;
   float y;
   // member access
         float& operator[](int idx);
   const float& operator[](int idx) const;
   // arithmetic
   Point2DF  operator- (const Point2DF& rhs) const;
   Point2DF  operator+ (const Point2DF& rhs) const;
   Point2DF  operator* (const float&    rhs) const;
   Point2DF& operator-=(const Point2DF& rhs);
   Point2DF& operator+=(const Point2DF& rhs);
   Point2DF& operator*=(const float&    rhs);
   float     dot       (const Point2DF& other) const;
   // comparison
   bool operator==(const Point2DF& rhs) const;
   bool operator!=(const Point2DF& rhs) const;
   // rounding
   Point2D truncate() const;
   Point2D round() const;
   // other
   float length() const;
   Point2DF normalize() const;
   // debugging
   void print() const;
};
struct Point3D
{
   // constructors
   Point3D(int xVal, int yVal, int zVal) : x(xVal), y(yVal), z(zVal) {};
   Point3D(Point2D p, float zVal) : x(p.x), y(p.y), z(zVal) {};
   static Point3D random(int x1, int y1, int z1, int x2, int y2, int z2);
   // members
   int x;
   int y;
   int z;
   // member access
         int& operator[](int idx);
   const int& operator[](int idx) const;
   // arithmetic
   Point3D  operator- (const Point3D& rhs) const;
   Point3D  operator+ (const Point3D& rhs) const;
   Point3DF operator* (const float&   rhs) const;
   Point3D& operator-=(const Point3D& rhs);
   Point3D& operator+=(const Point3D& rhs);
   int      dot       (const Point3D& other) const;
   Point3D  cross     (const Point3D& other) const;
   // comparison
   bool operator==(const Point3D& rhs) const;
   bool operator!=(const Point3D& rhs) const;
   bool operator< (const Point3D& rhs) const;
   bool operator> (const Point3D& rhs) const;
   bool operator<=(const Point3D& rhs) const;
   bool operator>=(const Point3D& rhs) const;
   // other
   float length() const;
   Point3DF normalize() const;
   // debugging
   void print() const;
};
struct Point3DF
{
   // constants
   static constexpr float TOLERANCE = 0.01;
   // constructors
   Point3DF(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {};
   Point3DF(Point2DF p, float zVal) : x(p.x), y(p.y), z(zVal) {};
   Point3DF(Point3D p) : x(p.x), y(p.y), z(p.z) {};
   static Point3DF random(float x1,float y1,float z1,float x2,float y2,float z2);
   // members
   float x;
   float y;
   float z;
   // member access
         float& operator[](int idx);
   const float& operator[](int idx) const;
   // arithmetic
   Point3DF  operator- (const Point3DF& rhs) const;
   Point3DF  operator+ (const Point3DF& rhs) const;
   Point3DF  operator* (const float&    rhs) const;
   Point3DF& operator-=(const Point3DF& rhs);
   Point3DF& operator+=(const Point3DF& rhs);
   Point3DF& operator*=(const float&    rhs);
   float     dot       (const Point3DF& other) const;
   Point3DF  cross     (const Point3DF& other) const;
   // comparison
   bool operator==(const Point3DF& rhs) const;
   bool operator!=(const Point3DF& rhs) const;
   bool operator< (const Point3DF& rhs) const;
   bool operator> (const Point3DF& rhs) const;
   bool operator<=(const Point3DF& rhs) const;
   bool operator>=(const Point3DF& rhs) const;
   // rounding
   Point3D truncate() const;
   Point3D round() const;
   // other
   float length() const;
   Point3DF normalize() const;
   // debugging
   void print() const;
};
Point2DF operator*(const float& lhs, const Point2D&  rhs);
Point2DF operator*(const float& lhs, const Point2DF& rhs);
Point3DF operator*(const float& lhs, const Point3D&  rhs);
Point3DF operator*(const float& lhs, const Point3DF& rhs);

// 4 by 4 matrix
// Used as a 3D homogenous transformation matrix
// The bottom row is often assumed to be [0, 0, 0, 1]
class Matrix
{
public:
   // constants
   static constexpr float TOLERANCE = 0.01;
   // constructors
   Matrix() : Matrix('I') {};
   Matrix(char type);
   // false constructors
   static Matrix TranslationMatrix(float x, float y, float z);
   static Matrix ScaleMatrix(float x, float y, float z);
   static Matrix RotationMatrix(char axis, float degrees); // RH rotation on LH CHS
   // members
   float m[4][4];
   // member access
         float* operator[](int idx);
   const float* operator[](int idx) const;
   // comparison
   bool operator==(const Matrix& rhs) const;
   bool operator!=(const Matrix& rhs) const;
   // multiplication
   Matrix   operator* (const Matrix& rhs) const;
   Point3DF operator* (const Point3DF& rhs) const;
   Point3DF operator* (const Point3D& rhs) const;
   Matrix&  operator*=(const Matrix& rhs);
   // transformations
   Matrix translate(float x, float y, float z) const;
   Matrix scale(float x, float y, float z) const;
   Matrix rotate(char axis, float degrees) const; // RH rotation on LH CHS
   // other
   Matrix transpose() const;
   Matrix invert() const;
   // debugging
   void print() const;
};
Point3DF operator*(const Point3DF& lhs, const Matrix& rhs);
Point3DF operator*(const Point3D&  lhs, const Matrix& rhs);

// Colour class
// A wrapper for 32 bit unsigned argb values. alpha ignored
class Color
{
public:
   // constants
   static const unsigned int rgbMask = 0x00FFFFFF;
   static const Color WHITE, BLACK, GRAY, RED, GREEN, BLUE,
                      CYAN, MAGENTA, YELLOW, BROWN, ORANGE;
   Color();
   Color(unsigned int color);
   Color(uint8_t r, uint8_t g, uint8_t b);
   static Color random();
   // members
   union{
      struct{
         uint8_t blue;
         uint8_t green;
         uint8_t red;
         uint8_t alpha; // UNUSED
      } colorComponent;
      unsigned int color;
   };
   // member access
         uint8_t& operator[](int idx);
   const uint8_t& operator[](int idx) const;
   // assignment
   Color& operator=(unsigned int rhs);
   // comparison
   bool operator==(const Color& rhs) const;
   bool operator==(unsigned int rhs) const;
   bool operator!=(const Color& rhs) const;
   bool operator!=(unsigned int rhs) const;
   // arithmetic
   Color  operator* (float rhs) const;
   Color& operator*=(float rhs);
   Color  operator+ (const Color& rhs) const;
   Color& operator+=(const Color& rhs);
   Color  operator- (const Color& rhs) const;
   Color& operator-=(const Color& rhs);
   // debugging
   void print() const;
};
Color operator*(float lhs, const Color& rhs);

#endif // RESOURCES_H
