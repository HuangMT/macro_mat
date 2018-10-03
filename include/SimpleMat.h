#pragma once

#ifndef _SIMPLE_MAT_H_
#define _SIMPLE_MAT_H_

#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cassert>
#include <cmath>
#include "reccursive_macro.h"

using std::ostream;
using std::initializer_list;
using std::vector;
using std::iterator;

typedef double data_type;
typedef double* pdata_type;

class matnn;
class vecn;
class pvecn;
class matn;
class vec;
class pvec;

/* =============================================================================================================================
													Name
=============================================================================================================================
*/
#define _mat_base(dataType,_m,_k) mat##_m##_##_k##_##dataType##_base
#define _mat_type(dataType,_m,_k) mat##_m##_##_k##_##dataType##_type
#define _vec_base(dataType,_m) vec##_m##_##dataType##_base
#define _vec_type(dataType,_m) vec##_m##_##dataType##_type
#define _hvec_base(dataType,_m) hvec##_m##_##dataType##_base
#define _hvec_type(dataType,_m) hvec##_m##_##dataType##_type

#define mat_base(dataType,_m,_k) _mat_base(dataType,_m,_k)
#define mat_type(dataType,_m,_k) _mat_type(dataType,_m,_k)
#define vec_base(dataType,_m) _vec_base(dataType,_m)
#define vec_type(dataType,_m) _vec_type(dataType,_m)
#define hvec_base(dataType,_m) _hvec_base(dataType,_m)
#define hvec_type(dataType,_m) _hvec_type(dataType,_m)

/* =============================================================================================================================
												Matmk, macro
=============================================================================================================================
*/
#if 1
#define declare_mat_base(dataType, _m, _k) class mat_base(dataType, _m, _k);

#define def_mat_base(dataType,_m,_k)																												  \
class mat_base(dataType, _m, _k)																													  \
{																																					  \
public:																																				  \
	typedef dataType data_type;																														  \
	typedef dataType * pdata_type;																													  \
	const static int _n_row = _m;																													  \
	const static int _n_column = _k;																												  \
	virtual inline int n_column() const { return _n_column; }																						  \
	virtual inline int n_row() const { return _n_row; }																								  \
																																					  \
	mat_base(dataType, _m, _k) (pdata_type ptr = nullptr, int rd = _n_column, int cd = 1) : data_ptr(ptr), column_diff(cd), row_diff(rd) {}			  \
	mat_base(dataType, _m, _k) (const mat_base(dataType, _m, _k)& mat) :																			  \
		data_ptr(mat.data_ptr), column_diff(mat.column_diff), row_diff(mat.row_diff) {}																  \
																																					  \
	virtual inline data_type& operator () (int nr, int nc) {																						  \
		return *(data_ptr + nr * row_diff + nc * column_diff);																						  \
	}																																				  \
	inline virtual const data_type& operator () (int nr, int nc) const {																			  \
		return *(data_ptr + nr * row_diff + nc * column_diff);																						  \
	}																																				  \
	mat_base(dataType, _k, _m) transpose();																											  \
																																					  \
	vec_base(dataType, _k) row(int idx);																											  \
	hvec_base(dataType, _m) col(int idx);																											  \
																																					  \
	virtual void operator += (const mat_base(dataType, _m, _k)& mat);																				  \
	virtual void operator += (data_type num);																										  \
	virtual void operator -= (const mat_base(dataType, _m, _k)& mat);																				  \
	virtual void operator -= (data_type num);																										  \
	virtual void operator *= (data_type num);																										  \
	virtual void operator /= (data_type num);																										  \
	void operator = (const mat_base(dataType, _m, _k)& mat);																						  \
																																					  \
	mat_base(dataType, _m, _k)& setIdentity();																										  \
	mat_base(dataType, _m, _k)& setZero();																											  \
	mat_base(dataType, _m, _k)& setOnes(data_type data = 1);																						  \
																																					  \
	/*Algorithm*/																																	  \
	dataType norm();																																  \
																																					  \
protected:																																			  \
	int column_diff;																																  \
	int row_diff;																																	  \
	pdata_type data_ptr;																															  \
};																																					  \

#define def_mat(dataType,_m,_k)																														  \
class mat_type(dataType, _m, _k) :virtual public mat_base(dataType, _m, _k)																			  \
{																																					  \
public:																																				  \
	using mat_base(dataType, _m, _k)::operator=;																									  \
																																					  \
	mat_type(dataType, _m, _k)() : mat_base(dataType, _m, _k)(data) {}																				  \
	mat_type(dataType, _m, _k)(const mat_base(dataType, _m, _k) & mat): mat_type(dataType, _m, _k)() { (*this) = mat; }								  \
	mat_type(dataType, _m, _k)(const mat_type(dataType, _m, _k) & mat):	mat_type(dataType, _m, _k)((mat_base(dataType, _m, _k)) mat) {}				  \
																																					  \
protected:																																			  \
	data_type data[_n_row*_n_column];																												  \
};																																					  \

#define declare_same_class_operator(dataType,_m,_k)																									  \
ostream& operator << (ostream& out, mat_base(dataType,_m,_k)& mat);																					  \
mat_type(dataType, _m, _k) operator - (const mat_base(dataType,_m,_k)& mat);																		  \
mat_type(dataType, _m, _k) operator + (const mat_base(dataType,_m,_k)& mat1, const mat_base(dataType,_m,_k)& mat2);									  \
mat_type(dataType, _m, _k) operator - (const mat_base(dataType,_m,_k)& mat1, const mat_base(dataType,_m,_k)& mat2);									  \
mat_type(dataType, _m, _k) operator + (const mat_base(dataType,_m,_k)& mat, mat_base(dataType,_m,_k)::data_type num);								  \
mat_type(dataType, _m, _k) operator - (const mat_base(dataType,_m,_k)& mat, mat_base(dataType,_m,_k)::data_type num);								  \
mat_type(dataType, _m, _k) operator * (const mat_base(dataType,_m,_k)& mat, mat_base(dataType,_m,_k)::data_type num);								  \
mat_type(dataType, _m, _k) operator / (const mat_base(dataType,_m,_k)& mat, mat_base(dataType,_m,_k)::data_type num);								  \
mat_type(dataType, _m, _k) operator + (mat_base(dataType,_m,_k)::data_type num, const mat_base(dataType,_m,_k)& mat);								  \
mat_type(dataType, _m, _k) operator - (mat_base(dataType,_m,_k)::data_type num, const mat_base(dataType,_m,_k)& mat);								  \
mat_type(dataType, _m, _k) operator * (mat_base(dataType,_m,_k)::data_type num, const mat_base(dataType,_m,_k)& mat);								  \

#endif

/* =============================================================================================================================
												Vecm, macro
=============================================================================================================================
*/
#if 1
#define declare_vec_base(dataType, _m) class vec_base(dataType, _m)
#define declare_hvec_base(dataType, _m) class hvec_base(dataType, _m)

#define _declare_vec_cut_function(n,dataType) vec_base(dataType, n) tail##n(); vec_base(dataType, n) head##n();
#define declare_vec_cut_function(n,type) _declare_vec_cut_function(n, type)
#define declare_all_vec_cut_functions(n, type) BIDO(declare_vec_cut_function, n, type)

#define def_vec_base(dataType, _m)																							 \
class vec_base(dataType, _m) : virtual public mat_base(dataType, _m, 1)														 \
{																															 \
public:																														 \
	using mat_base(dataType, _m, 1)::operator();																			 \
																															 \
	vec_base(dataType, _m) (pdata_type ptr = nullptr, int d = 1) : mat_base(dataType, _m, 1)(ptr, d, 0) {}					 \
	vec_base(dataType, _m) (const vec_base(dataType, _m) & vec) : vec_base(dataType, _m)(vec.data_ptr, vec.row_diff) {}		 \
																															 \
	declare_all_vec_cut_functions(_m, dataType);																			 \
																															 \
	inline data_type& operator () (int idx) {																				 \
		return (*this)(idx, 1);																								 \
	}																														 \
																															 \
	inline const data_type& operator () (int idx) const {																	 \
		return (*this)(idx, 1);																								 \
	}																														 \
																															 \
	hvec_base(dataType, _m) transpose();																					 \
																															 \
};																															 \


#define _declare_hvec_cut_function(n,dataType) hvec_base(dataType, n) tail##n(); hvec_base(dataType, n) head##n();
#define declare_hvec_cut_function(n,type) _declare_hvec_cut_function(n, type)
#define declare_all_hvec_cut_functions(n, type) BIDO(declare_hvec_cut_function, n, type)

#define def_hvec_base(dataType, _m)																								\
class hvec_base(dataType, _m) : virtual public mat_base(dataType, 1, _m)														\
{																																\
public:																															\
	using mat_base(dataType, 1, _m)::operator();																				\
																																\
	hvec_base(dataType, _m) (pdata_type ptr = nullptr, int d = 1) : mat_base(dataType, 1, _m)(ptr, 0, d) {}						\
	hvec_base(dataType, _m) (const hvec_base(dataType, _m) & vec) : hvec_base(dataType, _m)(vec.data_ptr, vec.column_diff) {}	\
																																\
	declare_all_hvec_cut_functions(_m, dataType);																				\
																																\
	inline data_type& operator () (int idx) {																					\
		return (*this)(1, idx);																									\
	}																															\
																																\
	inline const data_type& operator () (int idx) const {																		\
		return (*this)(1, idx);																									\
	}																															\
																																\
	vec_base(dataType, _m) transpose();																							\
																																\
};																																\

#define declare_vec_type(dataType, _m) class vec_type(dataType, _m);
#define declare_hvec_type(dataType, _m) class hvec_type(dataType, _m);

#define _PARADEF(n,dataType) , dataType x##n
#define PARADEF(n,dataType) _PARADEF(n, dataType)
#define PARAS(n,dataType) dataType x##0 BIDO(PARADEF,DEC(n),dataType)
#define _ASSIGN(n) (*this)(n)=x##n; 
#define ASSIGN(n) _ASSIGN(n)
#define ASSIGN_CONSTRUCTION(n) (*this)(0)=x0;BIDO(ASSIGN,DEC(n))

#define def_vec_type(dataType, _m)																					  \
class vec_type(dataType, _m) : public mat_type(dataType, _m, 1), public vec_base(dataType, _m)						  \
{																													  \
public:																												  \
	vec_type(dataType, _m) () : mat_base(dataType, _m, 1)(data, 1, 0) {}											  \
	vec_type(dataType, _m) (const mat_base(dataType, _m, 1) & mat) : mat_type(dataType, _m, 1)(mat) {}				  \
	vec_type(dataType, _m) (PARAS(_m, dataType)) : vec_type(dataType, _m) () {										  \
		ASSIGN_CONSTRUCTION(_m);																					  \
	}																												  \
protected:																											  \
};																													  \

#define def_hvec_type(dataType, _m)																					  \
class hvec_type(dataType, _m) : public mat_type(dataType, 1, _m), public hvec_base(dataType, _m)					  \
{																													  \
public:																												  \
	hvec_type(dataType, _m) () : mat_base(dataType, 1, _m)(data, 0, 1) {}											  \
	hvec_type(dataType, _m) (const mat_base(dataType, 1, _m) & mat) : mat_type(dataType, 1, _m)(mat) {}				  \
	hvec_type(dataType, _m) (PARAS(_m, dataType)) : hvec_type(dataType, _m) () {									  \
		ASSIGN_CONSTRUCTION(_m);																					  \
	}																												  \
protected:																											  \
};																													  \

/* =============================================================================================================================
											declare and dec
=============================================================================================================================
*/
#if 1

#define declare_all_vec(m) declare_vec_base(double, m);declare_hvec_base(double, m);declare_vec_type(double, m);declare_hvec_type(double, m);
#define declare_all_vecm() DO(declare_all_vec,5)
declare_all_vecm();

#define declare_all_mat(n,m) declare_mat_base(double, n, m);
#define declare_all_mat_m(m) DO(declare_all_mat,5,m)
#define declare_all_mat_mn() BIDO(declare_all_mat_m,5)
declare_all_mat_mn();

#define def_all_mat(n,m) def_mat_base(double, n, m);def_mat(double, n, m);declare_same_class_operator(double, n, m);
#define def_all_mat_m(m) DO(def_all_mat,5,m)
#define def_all_mat_mn() BIDO(def_all_mat_m,5)
def_all_mat_mn();

#define def_all_vec(m) def_vec_base(double, m);def_hvec_base(double, m);def_vec_type(double, m);def_hvec_type(double, m);
#define def_all_vecm() DO(def_all_vec, 5)
def_all_vecm();

#endif




#endif




























class matnn
{
public:
	const static int mat_size = 3;

	// subclass

	class Loader {
	public:
		Loader(matnn &mat, int idx = 0) :mat(mat), idx(idx) {}
		Loader operator , (data_type num);
		matnn& mat;
		int idx;
	};

	// construct function

	matnn();
	matnn(const matnn& mat);
	matnn& setZero();
	matnn& setIdentity();
	static matnn Identity();
	static matnn Zero();

	matnn transpose() const;

	// basic operator

	matnn operator - () const;
	matnn operator + (data_type plus) const;
	matnn operator + (const matnn& plus) const;
	matnn operator - (data_type minus) const;
	matnn operator - (const matnn& minus) const;
	matnn operator * (data_type mul) const;
	matnn operator * (const matnn& mat) const;
	matnn operator / (data_type div) const;
	vecn operator * (const vecn& vec) const;

	Loader operator << (data_type num);

	friend ostream& operator << (ostream& out, const matnn& mat);

	friend matnn operator + (data_type mul, const matnn& mat);
	friend matnn operator * (data_type mul, const matnn& mat);

	// function

	data_type& operator () (int row, int column);
	const data_type& operator () (int row, int column) const;
	pvecn row(int idx);
	pvecn column(int idx);
	pvecn diagonal();

private:
	data_type data[mat_size*mat_size];
};

class vecn {
public:
	const static int vec_size = 3;

	// Loader class
	class Loader {
	public:
		Loader(vecn& vec, int idx) :vec(vec), idx(idx) {}
		Loader operator , (data_type num);

	private:
		vecn& vec;
		int idx;
	};

	// construction functions
	vecn();
	vecn(vecn& vec);
	vecn(initializer_list<data_type> list);

	vecn& setZero();
	vecn& setOnes();

	static vecn Zero();
	static vecn Ones();

	Loader operator << (data_type num);

	// basic calculation
	
	vecn operator - () const;
	vecn operator + (data_type num) const;
	vecn operator + (const vecn& num) const;
	vecn operator - (data_type num) const;
	vecn operator - (const vecn& num) const;
	vecn operator * (data_type num) const;
	vecn operator / (data_type num) const;
	vecn operator * (const matnn& mat) const;
	vecn& operator = (const vecn& vec);
	data_type operator * (const vecn& vec) const;

	friend vecn operator + (data_type num, const vecn& vec);
	friend vecn operator * (data_type num, const vecn& vec);

	friend ostream& operator << (ostream& out, const vecn& vec);

	// function

	inline virtual data_type& operator () (int idx) {
		return data[idx];
	}

	inline virtual const data_type& operator () (int idx) const {
		return data[idx];
	}

	inline data_type norm() {
		return *this * *this;
	}

	matnn asDiagonal();
	data_type sum();

private:
	data_type data[vec_size];
};

class pvecn :public vecn
{
public:
	pvecn();
	pvecn(const pvecn& pvec);
	pvecn(vecn& vec);
	pvecn(initializer_list<pdata_type> list);
	pvecn(pdata_type p, int step);

	bool bind(int idx, pdata_type p);

	inline data_type& operator () (int idx) {
		return *pdata[idx];
	}

	inline const data_type& operator () (int idx) const {
		return *pdata[idx];
	}

private:
	pdata_type pdata[vec_size];
};

class matn
{
public:
	const static int mat_size = 3;
	
	matn();
	matn(const matn& mat);

	virtual bool resize(int nr, int nc = mat_size);

	inline int data_len() const {
		return data.size() / mat_size;
	}

	// basic operator

	inline data_type& operator () (int row, int column) {
		return data.data()[row*mat_size + column];
	}

	const data_type& operator() (int row, int column) const {
		return data.data()[row*mat_size + column];
	}

	friend ostream& operator << (ostream& out, const matn& mat);

	// functions
	pvecn row(int idx);

private:
	vector<data_type> data;
};

class vec
{
public:
	// construction functions
	vec();
	vec(const vec& v);

	// basic operations
	virtual bool inline resize(int n) {
		data.resize(n);
		return true;
	}
	
	inline virtual int data_len() const {
		return data.size();
	}

	inline virtual data_type& operator () (int idx) {
		return data.data()[idx];
	}

	inline virtual const data_type& operator () (int idx) const {
		return data.data()[idx];
	}

private:
	vector<data_type> data;
};

class pvec:public vec
{
public:
	pvec();
	pvec(const pvec& pv);
	pvec(vec& v);

	inline virtual int data_len() const {
		return pdata.size();
	}

	inline virtual data_type& operator () (int idx) {
		return *pdata.data()[idx];
	}

	inline virtual const data_type& operator () (int idx) const {
		return *pdata.data()[idx];
	}

private:
	vector<pdata_type> pdata;
};

ostream& operator << (ostream& out, vec& v);




#endif