// Author:
// Curtis Babnik
// cbabnik@sfu.ca
// 301235515

#ifndef RESOURCES_H
#define RESOURCES_H

// Declaration of various structs used by my graphics_engine
// * I'm considering turning this into a git submodule

// forward declaration
struct Point2D;
struct Point2DF;
struct Point3D;
struct Point3DF;

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
};
struct Point2DF
{
   // constants
   static constexpr float TOLERANCE = 0.01;
   // constructors
   Point2DF(float xVal, float yVal) : x(xVal), y(yVal) {};
   Point2DF(Point2D p) : x(p.x), y(p.y) {};
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
};
struct Point3D
{
   // constructors
   Point3D(int xVal, int yVal, int zVal) : x(xVal), y(yVal), z(zVal) {};
   Point3D(Point2D p, float zVal) : x(p.x), y(p.y), z(zVal) {};
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
};
struct Point3DF
{
   // constants
   static constexpr float TOLERANCE = 0.01;
   // constructors
   Point3DF(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {};
   Point3DF(Point2DF p, float zVal) : x(p.x), y(p.y), z(zVal) {};
   Point3DF(Point3D p) : x(p.x), y(p.y), z(p.z) {};
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
};
Point2DF operator*(const float& lhs, const Point2D&  rhs);
Point2DF operator*(const float& lhs, const Point2DF& rhs);
Point3DF operator*(const float& lhs, const Point3D&  rhs);
Point3DF operator*(const float& lhs, const Point3DF& rhs);

#endif // RESOURCES_H
