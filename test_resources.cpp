#include <QtTest/QtTest>

#include "resources.h"

class TestResources: public QObject
{
   Q_OBJECT

private slots:
   void point_comparison();
   void point_arithmetic();
   void point_member_access();
   void point_other();
   void combined();
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
}

void TestResources::point_other(){
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

void TestResources::combined(){

}

QTEST_MAIN(TestResources)
#include "test_resources.moc"
