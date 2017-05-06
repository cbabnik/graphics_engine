#include <QtTest/QtTest>

#include "resources.h"
#include <stdexcept>
#include <climits>

class TestResources: public QObject
{
   Q_OBJECT

private:
   static constexpr float TOLERANCE = 0.0001;

private slots:
   void point_comparison();
   void point_arithmetic();
   void point_member_access();
   void point_rounding();
   void point_normalization();
   void point_constructors();
   void point_combined();

   void matrix_constructors();
   void matrix_inversion();
   void matrix_transpose();
   void matrix_multiplication();
   void matrix_member_access();
   void matrix_combined();

   void color_constructors();
   void color_assignment();
   void color_member_access();
   void color_arithmetic();
   void color_comparison();
   void color_combined();

   void interaction_matrix_point();
};

void TestResources::point_comparison(){
   // Point2D
  {
   Point2D p1(1,2), p2(1,2), p3(2,2);
   QVERIFY( p1 == p2 );
   QVERIFY( !(p1 == p3) );
   QVERIFY( !(p1 != p2) );
   QVERIFY( p1 != p3 );
  }
   // Point2DF
  {
   Point2DF p1(1.0, 2.0), p2(1.0001, 1.9999), p3(2.0001, 1.9999);
   QVERIFY( p1 == p2 );
   QVERIFY( !(p1 == p3) );
   QVERIFY( !(p1 != p2) );
   QVERIFY( p1 != p3 );
  }
   // Point3D
  {
   Point3D p1(1,2,3), p2(1,2,3), p3(1,1,3), p4(-100,-100,10);
   QVERIFY( p1 == p2 );
   QVERIFY( !(p1 == p3) );
   QVERIFY( !(p1 != p2) );
   QVERIFY( p1 != p3 );
   QVERIFY( !(p1 <  p3) );
   QVERIFY( p1 <  p4 );
   QVERIFY( p1 <= p3 );
   QVERIFY( p1 >= p3 );
   QVERIFY( p2 >= p3 );
   QVERIFY( p2 <= p3 );
   QVERIFY( !(p1 >  p4) );
   QVERIFY( p4 >  p1 );
   QVERIFY( p1 <= p4 );
   QVERIFY( !(p1 >= p4) );
   QVERIFY( !(p2 >= p4) );
   QVERIFY( p2 <= p4 );
  }
   // Point3DF
  {
   Point3DF p1(1,2,3), p2(1.0001, 1.9999, 3.0001), p3(1,1,3), p4(-100,-100,10);
   QVERIFY( p1 == p2 );
   QVERIFY( !(p1 == p3) );
   QVERIFY( !(p1 != p2) );
   QVERIFY( p1 != p3 );
   QVERIFY( !(p1 <  p3) );
   QVERIFY( p1 <  p4 );
   QVERIFY( p1 <= p3 );
   QVERIFY( p1 >= p3 );
   QVERIFY( p2 >= p3 );
   QVERIFY( p2 <= p3 );
   QVERIFY( !(p1 >  p4) );
   QVERIFY( p4 >  p1 );
   QVERIFY( p1 <= p4 );
   QVERIFY( !(p1 >= p4) );
   QVERIFY( !(p2 >= p4) );
   QVERIFY( p2 <= p4 );
  }
}
void TestResources::point_arithmetic(){
   // Point2D
  {
   Point2D p1(5,10), p2(1,2);
   Point2D p3=p1+p2;
   Point2D p4=p1-p2;

   QVERIFY( p3.x == 6 );
   QVERIFY( p3.y == 12 );
   QVERIFY( p4.x == 4 );
   QVERIFY( p4.y == 8 );
   QVERIFY( p1.dot(p2) == p2.dot(p1) );
   QVERIFY( p1.dot(p2) == 25 );

   p3+=p2;
   p4-=p2;

   QVERIFY( p3.x == 7 );
   QVERIFY( p3.y == 14 );
   QVERIFY( p4.x == 3 );
   QVERIFY( p4.y == 6 );

   Point2DF p5=2*p4;

   QVERIFY( abs(p5.x - 6)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p5.y - 12) < Point2DF::TOLERANCE );

   p5=p4*3;

   QVERIFY( abs(p5.x - 9)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p5.y - 18) < Point2DF::TOLERANCE );
  }
   // Point2DF
  {
   Point2DF p1(3.3,-4.4), p2(1.1,2.2);
   Point2DF p3=p1+p2;
   Point2DF p4=p1-p2;

   QVERIFY( abs(p3.x - 4.4)    < Point2DF::TOLERANCE );
   QVERIFY( abs(p3.y - (-2.2)) < Point2DF::TOLERANCE );
   QVERIFY( abs(p4.x - 2.2)    < Point2DF::TOLERANCE );
   QVERIFY( abs(p4.y - (-6.6)) < Point2DF::TOLERANCE );
   QVERIFY( abs(p1.dot(p2) - p2.dot(p1)) < Point2DF::TOLERANCE );
   QVERIFY( abs(p1.dot(p2) - (-6.05)) < Point2DF::TOLERANCE );

   p3+=p2;
   p4-=p2;

   QVERIFY( abs(p3.x - 5.5)    < Point2DF::TOLERANCE );
   QVERIFY( abs(p3.y - 0)      < Point2DF::TOLERANCE );
   QVERIFY( abs(p4.x - 1.1)    < Point2DF::TOLERANCE );
   QVERIFY( abs(p4.y - (-8.8)) < Point2DF::TOLERANCE );

   Point2DF p5=2*p4;

   QVERIFY( abs(p5.x - 2.2)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p5.y - (-17.6)) < Point2DF::TOLERANCE );

   p5=p4*.5;

   QVERIFY( abs(p5.x - 0.55)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p5.y - (-4.4)) < Point2DF::TOLERANCE );

   p5*=2;

   QVERIFY( abs(p5.x - 1.1)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p5.y - (-8.8)) < Point2DF::TOLERANCE );
  }
   // Point3D
  {
   Point3D p1(5,10,15), p2(1,2,3);
   Point3D p3=p1+p2;
   Point3D p4=p1-p2;

   QVERIFY( p3.x == 6 );
   QVERIFY( p3.y == 12 );
   QVERIFY( p3.z == 18 );
   QVERIFY( p4.x == 4 );
   QVERIFY( p4.y == 8 );
   QVERIFY( p4.z == 12 );
   QVERIFY( p1.dot(p2) == p2.dot(p1) );
   QVERIFY( p1.dot(p2) == 70 );

   p3+=p2;
   p4-=p2;

   QVERIFY( p3.x == 7 );
   QVERIFY( p3.y == 14 );
   QVERIFY( p3.z == 21 );
   QVERIFY( p4.x == 3 );
   QVERIFY( p4.y == 6 );
   QVERIFY( p4.z == 9 );

   Point3DF p5=2*p4;

   QVERIFY( abs(p5.x - 6)  < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.y - 12) < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.z - 18) < Point3DF::TOLERANCE );

   p5=p4*3;

   QVERIFY( abs(p5.x - 9)  < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.y - 18) < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.z - 27) < Point3DF::TOLERANCE );

   Point3D p6 = p1.cross(p2);

   QVERIFY( p6.x == 0 );
   QVERIFY( p6.y == 0 );
   QVERIFY( p6.z == 0 );
  }
   // Point3DF
  {
   Point3DF p1(3.3,-4.4,0.5), p2(1.1,2.2,1.0);
   Point3DF p3=p1+p2;
   Point3DF p4=p1-p2;

   QVERIFY( abs(p3.x - 4.4)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p3.y - (-2.2)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3.z - 1.5)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p4.x - 2.2)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p4.y - (-6.6)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p4.z - (-0.5)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p1.dot(p2) - p2.dot(p1)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p1.dot(p2) - (-5.55)) < Point3DF::TOLERANCE );

   p3+=p2;
   p4-=p2;

   QVERIFY( abs(p3.x - 5.5)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p3.y - 0)      < Point3DF::TOLERANCE );
   QVERIFY( abs(p3.z - 2.5)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p4.x - 1.1)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p4.y - (-8.8)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p4.z - (-1.5)) < Point3DF::TOLERANCE );

   Point3DF p5=2*p4;

   QVERIFY( abs(p5.x - 2.2)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.y - (-17.6))< Point3DF::TOLERANCE );
   QVERIFY( abs(p5.z - (-3.0)) < Point3DF::TOLERANCE );

   p5=p4*.5;

   QVERIFY( abs(p5.x - 0.55)   < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.y - (-4.4)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.z - (-0.75))< Point3DF::TOLERANCE );

   p5*=2;

   QVERIFY( abs(p5.x - 1.1)    < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.y - (-8.8)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p5.z - (-1.5)) < Point3DF::TOLERANCE );

   Point3DF p6 = p1.cross(p2);

   QVERIFY( abs(p6.x - (-5.5)) < Point3DF::TOLERANCE );
   QVERIFY( abs(p6.y - (-2.75))< Point3DF::TOLERANCE );
   QVERIFY( abs(p6.z - 12.10)  < Point3DF::TOLERANCE );
  }
}

void TestResources::point_member_access(){
   Point2D  p2d(1,2);
   Point2DF p2df(1,2);
   Point3D  p3d(1,2,3);
   Point3DF p3df(1,2,3);
   p2d[0] += 10;
   p2d[1] += 20;
   p2df[0] += 10;
   p2df[1] += 20;
   p3d[0] += 10;
   p3d[1] += 20;
   p3d[2] += 30;
   p3df[0] += 10;
   p3df[1] += 20;
   p3df[2] += 30;

   QVERIFY( p2d[0] == 11 );
   QVERIFY( p2d[1] == 22 );
   QVERIFY( abs(p2df[0] - 11) < Point2DF::TOLERANCE );
   QVERIFY( abs(p2df[1] - 22) < Point2DF::TOLERANCE );
   QVERIFY( p3d[0] == 11 );
   QVERIFY( p3d[1] == 22 );
   QVERIFY( p3d[2] == 33 );
   QVERIFY( abs(p3df[0] - 11) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df[1] - 22) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df[2] - 33) < Point3DF::TOLERANCE );

   QVERIFY_EXCEPTION_THROWN( p2d[-1] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p2d[2] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p2df[-1] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p2df[2] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p3d[-1] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p3d[3] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p3df[-1] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p3df[3] , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p2d[INT_MIN], std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( p2d[INT_MAX], std::out_of_range );
}

void TestResources::point_rounding(){
   // Rounding
  {
   Point2DF p1(1.2, 1.8), p2(.5,-.5), p3(-1.2, -1.8);
   Point2D r1 = p1.round();
   Point2D r2 = p2.round();
   Point2D r3 = p3.round();
   Point2D t1 = p1.truncate();
   Point2D t2 = p2.truncate();
   Point2D t3 = p3.truncate();

   QVERIFY( r1.x == 1 );
   QVERIFY( r1.y == 2 );
   QVERIFY( r2.x == 1 );
   QVERIFY( r2.y == -1 );
   QVERIFY( r3.x == -1 );
   QVERIFY( r3.y == -2 );
   QVERIFY( t1.x == 1 );
   QVERIFY( t1.y == 1 );
   QVERIFY( t2.x == 0 );
   QVERIFY( t2.y == 0 );
   QVERIFY( t3.x == -1 );
   QVERIFY( t3.y == -1 );
  }
  {
   Point3DF p1(1.2, 1.8, -.5), p2(-1.2, -1.8, .5);
   Point3D r1 = p1.round();
   Point3D r2 = p2.round();
   Point3D t1 = p1.truncate();
   Point3D t2 = p2.truncate();

   QVERIFY( r1.x == 1 );
   QVERIFY( r1.y == 2 );
   QVERIFY( r1.z == -1 );
   QVERIFY( r2.x == -1 );
   QVERIFY( r2.y == -2 );
   QVERIFY( r2.z == 1 );
   QVERIFY( t1.x == 1 );
   QVERIFY( t1.y == 1 );
   QVERIFY( t1.z == 0 );
   QVERIFY( t2.x == -1 );
   QVERIFY( t2.y == -1 );
   QVERIFY( t2.z == 0 );
  }
}

void TestResources::point_normalization(){
   Point2D  p2d(3,4);
   Point2DF p2df(3,4);
   Point3D  p3d(3,4,12);
   Point3DF p3df(3,4,12);

   QVERIFY( abs(p2d.length() - 5)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p2df.length() - 5) < Point2DF::TOLERANCE );
   QVERIFY( abs(p3d.length() - 13) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df.length() - 13)< Point3DF::TOLERANCE );

   Point2DF p2dn = p2d.normalize();
   Point2DF p2dfn = p2df.normalize();
   Point3DF p3dn = p3d.normalize();
   Point3DF p3dfn = p3df.normalize();

   QVERIFY( abs(p2dn.length() - 1)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p2dfn.length() - 1) < Point2DF::TOLERANCE );
   QVERIFY( abs(p3dn.length() - 1)  < Point3DF::TOLERANCE );
   QVERIFY( abs(p3dfn.length() - 1) < Point3DF::TOLERANCE );
   QVERIFY( abs(p2dn.x - .6)  < Point2DF::TOLERANCE );
   QVERIFY( abs(p2dfn.x - .6) < Point2DF::TOLERANCE );
   QVERIFY( abs(p3dn.x - 3.0/13)  < Point3DF::TOLERANCE );
   QVERIFY( abs(p3dfn.x - 3.0/13) < Point3DF::TOLERANCE );
}

void TestResources::point_constructors(){
   Point2D p2d(1,2);

   Point2DF p2df(p2d);
   QVERIFY( abs(p2df.x - 1) < Point2DF::TOLERANCE );
   QVERIFY( abs(p2df.y - 2) < Point2DF::TOLERANCE );

   Point3D p3d(p2d,3);
   QVERIFY( p3d.x == 1 );
   QVERIFY( p3d.y == 2 );
   QVERIFY( p3d.z == 3 );

   Point3DF p3df1(p3d);
   Point3DF p3df2(p2df,3);
   QVERIFY( abs(p3df1.x - 1) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df1.y - 2) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df1.z - 3) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df2.x - 1) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df2.y - 2) < Point3DF::TOLERANCE );
   QVERIFY( abs(p3df2.z - 3) < Point3DF::TOLERANCE );
}

void TestResources::point_combined(){
  {
   Point2D p(3,4);
   QVERIFY( (.2*p) == p.normalize() );
   QVERIFY( Point2DF(p + p) == p*2 );
   Point2D p2 = p;
   p2 += p;
   p2 += p;
   p2 -= p;
   QVERIFY( p2 == Point2D(6,8) );
  }
  {
   Point2DF p(3,4);
   QVERIFY( (.2*p) == p.normalize() );
   QVERIFY( p + p == p*2 );
   Point2DF p2 = p;
   p2 += 2*p;
   p2 -= p;
   QVERIFY( p2 == Point2DF(6,8) );
   QVERIFY( Point2D(6,8) == p2.truncate() );
   QVERIFY( Point2D(6,8) == p2.round() );
  }
  {
   Point3D p(3,4,12);
   QVERIFY( ((1.0/13)*p) == p.normalize() );
   QVERIFY( Point3DF(p + p) == p*2 );
   Point3D p2 = p;
   p2 += p;
   p2 += p;
   p2 -= p;
   QVERIFY( p2 == Point3D(6,8,24) );
  }
  {
   Point3DF p(3,4,12);
   QVERIFY( ((1.0/13)*p) == p.normalize() );
   QVERIFY( p + p == p*2 );
   Point3DF p2 = p;
   p2 += 2*p;
   p2 -= p;
   QVERIFY( p2 == Point3DF(6,8,24) );
   QVERIFY( Point3D(6,8,24) == p2.truncate() );
   QVERIFY( Point3D(6,8,24) == p2.round() );
  }

   Point3DF p0(0,0,0), p1(1,2,3), p2(1.5, 3.5, 0.2), p3(3.14, 1.62, 1.1);
   QVERIFY( abs((p1.cross(p2)).dot(p3)) == abs(p1.dot(p2.cross(p3))) );
   QVERIFY( (p1.dot(p2) - p2.dot(p1)) < Point3DF::TOLERANCE ); // commutative
   QVERIFY( p1.cross(p2) == p0-(p2.cross(p1)) ); // anti-commutative
   QVERIFY( p1.cross(p2.cross(p3)) +
            p2.cross(p3.cross(p1)) +
            p3.cross(p1.cross(p2)) == p0 ); // Jacobi identity
   QVERIFY( p1.cross(p2+p3) == (p1.cross(p2))+(p1.cross(p3)) ); // distributative
}

void TestResources::matrix_member_access(){
   Matrix M;
   M.m[2][3] = 2.0;
   QVERIFY( abs(M[2][3] - 2) < TOLERANCE );
}

void TestResources::matrix_transpose(){
   Matrix M;
   M.m[2][3] = 2.0;
   M = M.transpose();
   QVERIFY( abs(M[2][2] - 1) < TOLERANCE );
   QVERIFY( abs(M[2][3] - 0) < TOLERANCE );
   QVERIFY( abs(M[3][2] - 2) < TOLERANCE );
}

void TestResources::matrix_constructors(){
   Matrix Mt = Matrix::TranslationMatrix(5, 10, 15);
   Matrix Ms = Matrix::ScaleMatrix(5, 10, 15);

   Matrix Mx = Matrix::RotationMatrix('x', 30);
   Matrix My = Matrix::RotationMatrix('y', 30);
   Matrix Mz = Matrix::RotationMatrix('z', 30);

   QVERIFY( abs(Mt.m[0][3] - 5 ) < Matrix::TOLERANCE );
   QVERIFY( abs(Mt.m[0][0] - 1 ) < Matrix::TOLERANCE );
   QVERIFY( abs(Mt.m[1][3] - 10) < Matrix::TOLERANCE );
   QVERIFY( abs(Mt.m[2][3] - 15) < Matrix::TOLERANCE );
   QVERIFY( abs(Mt.m[3][3] - 1 ) < Matrix::TOLERANCE );

   QVERIFY( abs(Ms.m[0][0] - 5 ) < Matrix::TOLERANCE );
   QVERIFY( abs(Ms.m[0][1] - 0 ) < Matrix::TOLERANCE );
   QVERIFY( abs(Ms.m[1][1] - 10) < Matrix::TOLERANCE );
   QVERIFY( abs(Ms.m[2][2] - 15) < Matrix::TOLERANCE );
   QVERIFY( abs(Ms.m[3][3] - 1 ) < Matrix::TOLERANCE );

   QVERIFY( abs(Mx.m[0][0] - 1     ) < Matrix::TOLERANCE );
   QVERIFY( abs(Mx.m[1][1] - 0.8660) < Matrix::TOLERANCE );
   QVERIFY( abs(Mx.m[1][2] - (-0.5)) < Matrix::TOLERANCE );
   QVERIFY( abs(Mx.m[2][1] - 0.5   ) < Matrix::TOLERANCE );
   QVERIFY( abs(Mx.m[2][2] - 0.8660) < Matrix::TOLERANCE );

   QVERIFY( abs(My.m[1][1] - 1     ) < Matrix::TOLERANCE );
   QVERIFY( abs(My.m[2][2] - 0.8660) < Matrix::TOLERANCE );
   QVERIFY( abs(My.m[2][0] - 0.5   ) < Matrix::TOLERANCE );
   QVERIFY( abs(My.m[0][2] - (-0.5)) < Matrix::TOLERANCE );
   QVERIFY( abs(My.m[0][0] - 0.8660) < Matrix::TOLERANCE );

   QVERIFY( abs(Mz.m[2][2] - 1     ) < Matrix::TOLERANCE );
   QVERIFY( abs(Mz.m[0][0] - 0.8660) < Matrix::TOLERANCE );
   QVERIFY( abs(Mz.m[0][1] - 0.5   ) < Matrix::TOLERANCE );
   QVERIFY( abs(Mz.m[1][0] - (-0.5)) < Matrix::TOLERANCE );
   QVERIFY( abs(Mz.m[1][1] - 0.8660) < Matrix::TOLERANCE );

   QVERIFY_EXCEPTION_THROWN( Matrix('A'), std::invalid_argument );
}

void TestResources::matrix_inversion(){
   Matrix M, expectedResult;
   M.m[0][0] = 2;
   M.m[0][1] = 3;
   M.m[0][2] = 2.7;
   M.m[0][3] = 23;
   M.m[1][0] = 5.5;
   M.m[1][1] = 4;
   M.m[1][2] = 5;
   M.m[1][3] = 1.5;
   M.m[2][0] = 2.3;
   M.m[2][1] = 1.1;
   M.m[2][2] = 10;
   M.m[2][3] = 2.9;
   expectedResult.m[0][0] = -0.49282;
   expectedResult.m[0][1] = 0.38611;
   expectedResult.m[0][2] = -0.05999;
   expectedResult.m[0][3] = 10.92971;
   expectedResult.m[1][0] = 0.62138;
   expectedResult.m[1][1] = -0.19698;
   expectedResult.m[1][2] = -0.06928;
   expectedResult.m[1][3] = -13.7954;
   expectedResult.m[2][0] = 0.04499;
   expectedResult.m[2][1] = -0.06713;
   expectedResult.m[2][2] = 0.12141;
   expectedResult.m[2][3] = -1.28633;

   QVERIFY( M.invert() == expectedResult );
}

void TestResources::matrix_multiplication(){
   Matrix M;
   M[0][0] = 1;
   M[0][1] = 2;
   M[0][2] = 3;
   M[1][0] = 4;
   M[1][1] = 5;
   M[1][2] = 6;
   M[2][0] = 7;
   M[2][1] = 8;
   M[2][2] = 9;
   M[0][3] = 2;
   M[1][3] = 5;
   M[2][3] = 8;
   Matrix M2;
   M2[0][0] = 1;
   M2[0][1] = 1;
   M2[0][2] = 2;
   M2[1][0] = 1.5;
   M2[1][1] = 1.5;
   M2[1][2] = 1.5;
   M2[2][0] = 2;
   M2[2][1] = 1;
   M2[2][2] = 3;
   M2[0][3] = 2;
   M2[1][3] = 1.5;
   M2[2][3] = 4;
   Matrix expectedResult('0');
   expectedResult.m[0][0] = 10;
   expectedResult.m[0][1] = 7;
   expectedResult.m[0][2] = 14;
   expectedResult.m[0][3] = 19;
   expectedResult.m[1][0] = 23.5;
   expectedResult.m[1][1] = 17.5;
   expectedResult.m[1][2] = 33.5;
   expectedResult.m[1][3] = 44.5;
   expectedResult.m[2][0] = 37;
   expectedResult.m[2][1] = 28;
   expectedResult.m[2][2] = 53;
   expectedResult.m[2][3] = 70;
}

void TestResources::matrix_combined(){
   QVERIFY( Matrix::RotationMatrix('x', 30) == Matrix::RotationMatrix('X', 30) );
   QVERIFY( Matrix::RotationMatrix('y', 30) == Matrix::RotationMatrix('Y', 30) );
   QVERIFY( Matrix::RotationMatrix('z', 30) == Matrix::RotationMatrix('Z', 30) );
   QVERIFY( Matrix('I') == Matrix('i') );
   QVERIFY( Matrix('z') == Matrix('0') );
   QVERIFY( Matrix('z') == Matrix('Z') );
   QVERIFY( Matrix('0') != Matrix() );
   QVERIFY( Matrix('v') == Matrix('V') );
   QVERIFY( Matrix('f') == Matrix('F') );
   QVERIFY( Matrix('V') == Matrix('F') );
   QVERIFY( Matrix('h') == Matrix('H') );
   QVERIFY( Matrix('m') == Matrix('M') );
   QVERIFY( Matrix('m') == Matrix('H') );

   Matrix M;
   M[0][0] = 1;
   M[0][1] = 2;
   M[0][2] = 3;
   M[1][0] = 4;
   M[1][1] = 5;
   M[1][2] = 6;
   M[2][0] = 7;
   M[2][1] = 8;
   M[2][2] = 9;
   M[0][3] = 2;
   M[1][3] = 5;
   M[2][3] = 8;
   M[3][0] = 9;
   M[3][1] = 4;
   M[3][2] = 1;
   Matrix M2;
   M2[0][0] = 1.5;
   M2[0][1] = 2.1;
   M2[0][2] = 0.1;
   M2[1][0] = 4.9;
   M2[1][1] = 5;
   M2[1][2] = 10;
   M2[2][0] = 17;
   M2[2][1] = .5;
   M2[2][2] = 5.5;
   M2[0][3] = 4;
   M2[1][3] = 4;
   M2[2][3] = 1.8;
   M2[3][0] = 8.9;
   M2[3][1] = 4;
   M2[3][2] = 1;

   QVERIFY( M.invert() * M == Matrix('I') );
   QVERIFY( M.invert() * M2.invert() == (M2*M).invert() );
   QVERIFY( M.transpose() * M2.transpose() == (M2*M).transpose() );
}

void TestResources::interaction_matrix_point(){
   Point3D p(10,100,1000);
   Matrix M;
   M[0][0] = 1;
   M[0][1] = 2;
   M[0][2] = 3;
   M[1][0] = 4;
   M[1][1] = 5;
   M[1][2] = 6;
   M[2][0] = 7;
   M[2][1] = 8;
   M[2][2] = 9;
   M[0][3] = 2;
   M[1][3] = 5;
   M[2][3] = 8;
   M[3][0] = 9;
   M[3][1] = 4;
   M[3][2] = 1;
   Point3DF expectedResultA(3212,6545,9878);
   Point3DF expectedResultB(7419,8524,9631);

   QVERIFY( M*p == expectedResultA );
   QVERIFY( p*M == expectedResultB );
}

void TestResources::color_constructors(){
   Color c1;
   Color c2(0xaaffaa00);
   Color c3(255,100,0);

   QVERIFY( (c1.color & c1.rgbMask) == 0                     );
   QVERIFY( c1.colorComponent.red   == 0                     );
   QVERIFY( c1.colorComponent.green == 0                     );
   QVERIFY( c1.colorComponent.blue  == 0                     );
   QVERIFY( (c2.color & c2.rgbMask) == 0x00ffaa00            );
   QVERIFY( c2.colorComponent.red   == 0xff                  );
   QVERIFY( c2.colorComponent.green == 0xaa                  );
   QVERIFY( c2.colorComponent.blue  == 0x00                  );
   QVERIFY( (c3.color & c3.rgbMask) == 255*256*256 + 100*256 );
   QVERIFY( c3.colorComponent.red   == 255                   );
   QVERIFY( c3.colorComponent.green == 100                   );
   QVERIFY( c3.colorComponent.blue  == 0                     );
}
void TestResources::color_assignment(){
   Color c1 = 0xa3ff00aa;

   QVERIFY( (c1.color & c1.rgbMask) == 0x00ff00aa );
   QVERIFY( c1.colorComponent.red   == 0xff       );
   QVERIFY( c1.colorComponent.green == 0x00       );
   QVERIFY( c1.colorComponent.blue  == 0xaa       );
}
void TestResources::color_member_access(){
   Color c1 = 0xaabbccdd;
   c1[0] -= 0xb;
   c1[1] -= 0xc;
   c1[2] -= 0xd;

   QVERIFY( c1[0] == 0xb0 );
   QVERIFY( c1[1] == 0xc0 );
   QVERIFY( c1[2] == 0xd0 );

   QVERIFY_EXCEPTION_THROWN( c1[-1]     , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( c1[3]      , std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( c1[INT_MIN], std::out_of_range );
   QVERIFY_EXCEPTION_THROWN( c1[INT_MAX], std::out_of_range );
}
void TestResources::color_arithmetic(){
   Color c1 = 0x00112233;
   Color c2 = 0x00204060;

   Color c3 = 2*c1;
   Color c4 = c1*3.0;
   Color c5 = 100*c1;
   Color c6 = -1*c1;

   Color c7 = 0x000a0b0c;
   c7 *= 0x11;

   QVERIFY( (c1.color & Color::rgbMask) == 0x112233 );
   QVERIFY( (c2.color & Color::rgbMask) == 0x204060 );
   QVERIFY( (c3.color & Color::rgbMask) == 0x224466 );
   QVERIFY( (c4.color & Color::rgbMask) == 0x336699 );
   QVERIFY( (c5.color & Color::rgbMask) == 0xffffff );
   QVERIFY( (c6.color & Color::rgbMask) == 0x000000 );
   QVERIFY( (c7.color & Color::rgbMask) == 0xaabbcc );

   Color c8 = c1+c2;
   Color c9 = c2-c1;
   c3 += c4;
   c5 -= c7;

   QVERIFY( (c8.color & Color::rgbMask) == 0x316293 );
   QVERIFY( (c9.color & Color::rgbMask) == 0x0f1e2d );
   QVERIFY( (c3.color & Color::rgbMask) == 0x55aaff );
   QVERIFY( (c5.color & Color::rgbMask) == 0x554433 );
}
void TestResources::color_comparison(){
   Color c1(0x00112233);
   Color c2(0x00204060);
   Color c3(0x11,0x22,0x33);

   QVERIFY(   c1 == c3   );
   QVERIFY( !(c1 != c3 ) );
   QVERIFY(   c1 != c2   );
   QVERIFY( !(c1 == c2 ) );
}
void TestResources::color_combined(){
   Color c1(0xfa3f);
   c1 = 0xab4d1f;
   Color c2(50,20,10);

   QVERIFY( ((2.3*c2).color & Color::rgbMask) == 0x732e17 );

   c2 *= 32.0/10;

   QVERIFY( c1 != c2 );

   c2 += 0x0b0d0f;
   c2 -= 0x000010;

   QVERIFY( c1 == c2 );

   c2[2] = c2[1];

   QVERIFY( (c2.color & Color::rgbMask) == 0xab4d4d );
}

QTEST_MAIN(TestResources)
#include "test_resources.moc"
