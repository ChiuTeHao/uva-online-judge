#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
class Point
{
    public:
        double x,y;
        Point(double x_=0,double y_=0);
};
typedef Point Vector;
Vector operator*(const Vector &v,double t)
{
    return Vector(v.x*t,v.y*t);
}
Vector operator+(const Point &A,const Point &B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(const Point &A,const Point &B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector Rotate(Vector &v,double rad)
{
    return Vector( v.x*cos(rad)-v.y*sin(rad) , v.x*sin(rad)+v.y*cos(rad) );
}
double Dot(Vector &A,Vector &B)
{
    return A.x*B.x+A.y*B.y;
}
double Length(Vector &v)
{
    return sqrt( Dot(v,v) );
}
double Angle(Vector &A,Vector &B)
{
    return acos(Dot(A,B)/Length(A)/Length(B));
}
Point::Point(double x_,double y_):x(x_),y(y_)
{
}
double Cross(Vector &A,Vector &B)
{
    return A.x*B.y-B.x*A.y;
}
Vector GetLineIntersection(Point &A,Vector v,Point &B,Vector w)
{
    Vector u=A-B;
    double t=Cross(w,u)/Cross(v,w);
    return A+v*t;
}
Point getPoint(Point &A,Point &B,Point &C)
{
    Vector v1=C-B,v2=A-B;
    double angle1=Angle(v1,v2);
    Vector DB=Rotate(v1,angle1/3);
    Vector v3=B-C,v4=A-C;
    double angle2=Angle(v3,v4);
    Vector DC=Rotate(v3,-angle2/3);
    return GetLineIntersection(B,DB,C,DC);
}
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        Point A,B,C;
        scanf("%lf%lf",&A.x,&A.y);
        scanf("%lf%lf",&B.x,&B.y);
        scanf("%lf%lf",&C.x,&C.y);
        Point D=getPoint(A,B,C);
        Point E=getPoint(B,C,A);
        Point F=getPoint(C,A,B);
        printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",D.x,D.y,E.x,E.y,F.x,F.y);
    }
}
