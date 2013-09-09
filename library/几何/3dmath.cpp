#include <math.h>
const double eps=1e-8;

bool zero(double x){
	return (x>0?x:-x)<eps;
}

struct point{
	double x,y,z;
};

struct line{
	point a,b;
	line(point a,point b){
		this->a=a;
		this->b=b;
	}
};

struct plane{
	point a,b,c;
	line(point a,point b,point c){
		this->a=a;
		this->b=b;
		this->c=c;
	}
};

double dmult(
