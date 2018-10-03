#include <iostream>
#include "SimpleMat.h"


using namespace std;

#define disp(x) cout<<#x<<":"<<endl<<x<<endl;

typedef mat3_5_double_type matmk;
typedef vec3_double_type vecm;
typedef hvec3_double_type hvecm;

void vecn_test()
{
	vecn vec1 = { 1,2,3 };
	disp(vec1);
	vec1.setOnes();
	disp(vec1);
	vec1.setZero();
	disp(vec1);

	vecn vec2 = vecn::Ones();
	vecn vec3 = vecn::Zero();
	disp(vec2);
	disp(vec3);
	disp(vec1(0));

	vecn vec4;
	vec4 << 0.1, 0.3, 0.4;
	disp(vec4);
	
	disp(vec2*vec4);
	disp(vec4.norm());

	disp(-vec2);
	disp(vec2 - vec4);
	disp(vec2 - 0.11);
	disp(vec2 + vec4);
	disp(vec2 + 0.11);
	disp(0.11 + vec2);
	disp(vec2 * 0.123);
	disp(0.123 * vec2);
	disp(vec2 * vec4);
	disp(vec2 / 1.2);

	vec4(2) = 0.6;
	disp(vec4.asDiagonal());
	

}

void pvecn_test()
{

	vecn vec1 = vecn::Ones();
	vecn vec2;
	vec2 << 1, 2, 3;
	pvecn pvec1 = { &vec1(0),&vec1(1) ,&vec1(2) };

	disp(vec1);
	disp(vec2);

	pvec1(1) = 2;
	disp(vec1);
	disp(pvec1);

	pvec1.setOnes();
	disp(vec1);
	disp(pvec1);

	disp(pvec1 + vec2);

	matnn mat1;
	mat1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	disp(mat1);
	mat1.row(1).setZero();
	disp(mat1);

	mat1.column(2).setOnes();
	disp(mat1);

	mat1.diagonal().setZero();
	disp(mat1);

}

void matnn_test()
{
	matnn mat1;
	vecn vec1;
	disp(mat1);
	disp(vec1);

	mat1 << 0.1324, 0.1415, 0.3627, 0.1723, 0.1246, 0.1641, 0.1251, 0.4574, 0.2462;
	disp(mat1);

	matnn mat2 = matnn::Identity();
	matnn mat3 = matnn::Zero();
	disp(mat2);
	disp(mat3);

	matnn mat4 = mat1;
	disp(mat4);

	mat1.setIdentity();
	disp(mat1);

	mat1.setZero();
	disp(mat1);

	matnn mat5 = mat4.transpose();
	disp(mat5);
	
	matnn mat6 = -mat5;
	matnn mat7 = mat4 + 0.2241;
	matnn mat8 = mat4 + mat5;
	matnn mat9 = mat5 - 0.1111;
	matnn mat10 = mat4 - mat5;
	disp(mat6);
	disp(mat7);
	disp(mat8);
	disp(mat9);
	disp(mat10);

	disp(mat4);
	disp(mat5);
	disp(mat4 * mat5);
	disp(mat4 * 1.123);
	disp(mat5 / 2.034);
	disp(1.123 + mat4);
	disp(1.123 * mat4);
	disp(mat4(0, 2));
	disp((1.1*mat4)(0, 1));
	const matnn matc = mat4;
	disp(matc(0, 1));

	vec1 = mat4.row(1);
	disp(vec1);
	disp(mat4.column(0));

	disp(mat4.column(1)*mat5);
	disp(mat5*mat4.column(1));

}

void matmk_test()
{
	matmk mat1;
	mat1.setIdentity();
	disp(mat1);
	disp(-mat1);

	matmk mat2;
	mat2.setOnes();
	disp(mat2);

	matmk mat3;
	mat3.setZero();
	disp(mat3);

	matmk mat4 = mat1 + mat2;
	disp(mat4);
	disp(mat1 + mat2);
	disp(mat1 - mat2);
	disp(mat1 + 1);
	disp(mat1 - 1);
	disp(mat1 * 1.2);
	disp(mat1 / 1.2);
	disp(1 + mat1);
	disp(1.6 * mat1);
	disp(1.6 - mat1);

	mat4 *= 10;
	disp(mat4);
	mat4 /= 2;
	disp(mat4);

	disp(mat4.transpose().setIdentity());
	disp(mat4);

}

void vecm_test()
{
	vecm vec1 = vecm();
	vec1.setIdentity();
	disp(vec1);

	hvecm hvec1;
	hvec1.setIdentity();
	disp(hvec1);

	vec1.transpose()(1) = 15;
	disp(vec1);
	
	disp(vec1.head2());
	disp(vec1.tail2());

	vecm vec2 = vecm(3.14, 2.72, 2.99);
	disp(vec2);

	hvecm hvec2 = hvecm(3.14, 2.72, 2.99);
	disp(hvec2);
	disp(hvec2.norm());

	disp(hvec2.tail1());
	disp(hvec2.tail3());

	mat3_3_double_type mat3;
	mat3.setIdentity();
	disp(mat3);
	disp(mat3.norm());

	mat3.col(2).setOnes();
	disp(mat3);

	mat3.row(1).setIdentity();
	disp(mat3);
}

void matn_test()
{
	// test the initialization and assign function
	matn mat1;

	disp(mat1);

	// functions
	mat1.resize(10);
	for (int i = 0;i < 10;++i) {
		data_type da = i*1.0;
		mat1.row(i) = vecn({ da,da,da });
	}

	disp(mat1);
	disp(mat1.row(2).setOnes());

	// copy function
	matn mat2 = mat1;
	disp(mat2);


}

void vec_test()
{
	// test the initialization and assign function
	vec v1;

	disp(v1);

	// test the basic operator functions
	v1.resize(11);
	for (int i = 0;i < 11;++i) {
		v1(i) = i;
	}

	disp(v1);

	// test the copy functions
	vec v2 = v1;
	disp(v2);
}

void pvec_test()
{
	// test the initialization function
	vec v1;
	v1.resize(10);
	for (int i = 0;i < 10;++i) {
		v1(i) = i;
	}

	pvec pv1 = v1;

	disp(pv1);

	// test basic function
	pv1(2) = 10;
	disp(v1);
}

int main()
{
	//vecn_test();
	//matnn_test();
	//pvecn_test();
	//matn_test();
	//vec_test();
	//pvec_test();
	//matmk_test();
	vecm_test();

	system("Pause");

	return 0;
}





