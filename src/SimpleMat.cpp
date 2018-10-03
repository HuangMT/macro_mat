#include "SimpleMat.h"

using namespace std;

vecn::vecn()
{
}

vecn::vecn(vecn & vec)
{
	for (int i = 0;i < vec_size;++i) {
		(*this)(i) = vec(i);
	}
}

vecn::vecn(initializer_list<data_type> list)
{
	int cnt = 0;
	for (auto p = list.begin();p != list.end();++p) {
		data[cnt] = *p;
		if (++cnt >= vec_size) {
			break;
		}
	}
}

vecn& vecn::setZero()
{
	for (int i = 0;i < vec_size;++i) {
		(*this)(i) = 0;
	}
	return *this;
}

vecn& vecn::setOnes()
{
	for (int i = 0;i < vec_size;++i) {
		(*this)(i) = 1;
	}
	return *this;
}

vecn vecn::Zero()
{
	vecn ret;
	ret.setZero();
	return ret;
}

vecn vecn::Ones()
{
	vecn ret;
	ret.setOnes();
	return ret;
}

vecn::Loader vecn::operator<<(data_type num)
{
	data[0] = num;
	return vecn::Loader(*this, 0);
}

vecn vecn::operator-() const
{
	vecn ret;
	for (int i = 0; i < vec_size;++i) {
		ret(i) = -(*this)(i);
	}
	return ret;
}

vecn vecn::operator+(data_type num) const
{
	vecn ret;
	for (int i = 0;i < vec_size;++i) {
		ret(i) = (*this)(i) + num;
	}
	return ret;
}

vecn vecn::operator+(const vecn & num) const
{
	vecn ret;
	for (int i = 0;i < vec_size;++i) {
		ret(i) = (*this)(i) + num(i);
	}
	return ret;
}

vecn vecn::operator-(data_type num) const
{
	return *this + (-num);
}

vecn vecn::operator-(const vecn & num) const
{
	vecn ret;
	for (int i = 0;i < vec_size;++i) {
		ret(i) = (*this)(i) - num(i);
	}
	return ret;
}

vecn vecn::operator*(data_type num) const
{
	vecn ret;
	for (int i = 0;i < vec_size;++i) {
		ret(i) = (*this)(i) * num;
	}
	return ret;
}

vecn vecn::operator/(data_type num) const
{
	return *this * (1.0 / num);
}

vecn vecn::operator*(const matnn & mat) const
{
	vecn ret = vecn::Zero();
	for (int i = 0;i < vec_size;++i) {
		for (int k = 0;k < vec_size;++k) {
			ret(i) += mat(k, i) * (*this)(k);
		}
	}
	return ret;
}

vecn& vecn::operator=(const vecn & vec)
{
	for (int i = 0;i < vec_size;++i) {
		(*this)(i) = vec(i);
	}
	return *this;
}

data_type vecn::operator*(const vecn & vec) const
{
	data_type ret = 0;
	for (int i = 0;i < vec_size;++i) {
		ret += (*this)(i)*vec(i);
	}
	return ret;
}

matnn vecn::asDiagonal()
{
	matnn mat = matnn::Zero();
	for (int i = 0;i < vec_size;++i) {
		mat(i, i) = (*this)(i);
	}
	return mat;
}

data_type vecn::sum()
{
	data_type ret = 0;
	for (int i = 0;i < vec_size;++i) {
		ret += (*this)(i);
	}
	return ret;
}

vecn::Loader vecn::Loader::operator , (data_type num)
{
	if (++idx < vec_size) {
		vec.data[idx] = num;
	}
	return vecn::Loader(vec,idx);
}

ostream& operator << (ostream& out, const vecn& vec)
{
	for (int i = 0;i < vecn::vec_size;++i) {
		out << vec(i) << ",\t";
	}
	return out;
}

vecn operator + (data_type num, const vecn& vec)
{
	return vec + num;
}

vecn operator * (data_type num, const vecn& vec)
{
	return vec * num;
}

matnn::matnn()
{
}

matnn::matnn(const matnn & mat)
{
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			(*this)(i, j) = mat(i, j);
		}
	}
}

matnn& matnn::setZero()
{
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			(*this)(i, j) = 0;
		}
	}
	return *this;
}

matnn& matnn::setIdentity()
{
	this->setZero();
	for (int i = 0;i < mat_size;++i) {
		(*this)(i,i) = 1;
	}
	return *this;
}

matnn matnn::transpose() const
{
	matnn ret;
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			ret(i, j) = (*this)(j, i);
		}
	}
	return ret;
}

data_type & matnn::operator()(int row, int column)
{
	return data[row * mat_size + column];
}

const data_type & matnn::operator()(int row, int column) const
{
	return data[row * mat_size + column];
}

pvecn matnn::row(int idx)
{
	pvecn ret;
	if (idx < mat_size) {
		for (int i = 0;i < mat_size;++i) {
			ret.bind(i, &(*this)(idx, i));
		}
	}
	return ret;
}

pvecn matnn::column(int idx)
{
	pvecn ret;
	if (idx < mat_size) {
		for (int i = 0;i < mat_size;++i) {
			ret.bind(i, &(*this)(i, idx));
		}
	}
	return ret;
}

pvecn matnn::diagonal()
{
	pvecn ret;
	for (int i = 0;i < mat_size;++i) {
		ret.bind(i, &(*this)(i, i));
	}
	return ret;
}

matnn matnn::operator+(data_type plus) const
{
	matnn ret;
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			ret(i,j) = (*this)(i,j) + plus;
		}
	}
	return ret;
}

matnn matnn::operator+(const matnn & plus) const
{
	matnn ret;
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			ret(i, j) = (*this)(i, j) + plus(i, j);
		}
	}
	return ret;
}

matnn matnn::operator-() const
{
	matnn ret;
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			ret(i, j) = -(*this)(i, j);
		}
	}
	return ret;
}

matnn matnn::operator-(data_type minus) const
{
	return *this + (-minus);
}

matnn matnn::operator-(const matnn& minus) const
{
	return *this + (-minus);
}

matnn matnn::operator*(data_type mul) const
{
	matnn ret;
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			ret(i, j) = (*this)(i, j) * mul;
		}
	}
	return ret;
}

matnn matnn::operator*(const matnn & mat) const
{
	matnn ret = matnn::Zero();
	for (int i = 0;i < mat_size;++i) {
		for (int j = 0;j < mat_size;++j) {
			for (int k = 0;k < mat_size;++k) {
				ret(i, j) += (*this)(i, k) * mat(k, j);
			}
		}
	}
	return ret;
}

matnn matnn::operator/(data_type div) const
{
	return *this * (1.0 / div);
}

vecn matnn::operator*(const vecn & vec) const
{
	vecn ret = vecn::Zero();
	for (int i = 0;i < mat_size;++i) {
		for (int k = 0;k < mat_size;++k) {
			ret(i) += (*this)(i, k) * vec(k);
		}
	}
	return ret;
}

matnn::Loader matnn::operator<<(data_type num)
{
	data[0] = num;
	return matnn::Loader(*this);
}

matnn matnn::Identity()
{
	matnn mat;
	mat.setIdentity();
	return mat;
}

matnn matnn::Zero()
{
	matnn mat;
	mat.setZero();
	return mat;
}

ostream& operator << (ostream& out, const matnn& mat)
{
	for (int i = 0;i < matnn::mat_size;++i) {
		if (i > 0) {
			out << endl;
		}
		for (int j = 0;j < matnn::mat_size;++j) {
			out << mat(i, j) << ",\t";
		}
	}
	return out;
}

matnn operator + (data_type mul, const matnn& mat)
{
	return mat + mul;
}

matnn operator * (data_type mul, const matnn& mat)
{
	return mat * mul;
}

matnn::Loader matnn::Loader::operator,(data_type num)
{
	if (++idx < mat_size*mat_size) {
		mat.data[idx] = num;
	}
	return matnn::Loader(mat, idx);
}

pvecn::pvecn()
{
	for (int i = 0;i < vec_size;++i) {
		pdata[i] = 0;
	}
}

pvecn::pvecn(const pvecn & pvec)
{
	for (int i = 0;i < vec_size;++i) {
		pdata[i] = pvec.pdata[i];
	}
}

pvecn::pvecn(vecn & vec)
{
	for (int i = 0;i < vec_size;++i) {
		pdata[i] = &(vec(i));
	}
}

pvecn::pvecn(initializer_list<pdata_type> list)
{
	int cnt = 0;
	for (auto p = list.begin();p != list.end();++p) {
		pdata[cnt] = *p;
		if (++cnt >= vec_size) {
			break;
		}
	}
}

pvecn::pvecn(pdata_type p, int step)
{
	for (int i = 0;i < pvecn::vec_size;++i) {
		pdata[i] = p + step * i;
	}
}

bool pvecn::bind(int idx, pdata_type p)
{
	if (idx < vec_size) {
		pdata[idx] = p;
		return true;
	}

	return false;
}

matn::matn()
{
}

matn::matn(const matn & mat)
{
	data.assign(mat.data.begin(), mat.data.end());
}

bool matn::resize(int nr, int nc)
{
	if (nc == mat_size) {
		data.resize(nr * nc);
		return true;
	}
	return false;
}

pvecn matn::row(int idx)
{
	return pvecn(data.data() + idx*mat_size, 1);
}

ostream& operator << (ostream& out, const matn& mat)
{
	for (int i = 0;i < mat.data_len();++i) {
		if (i > 0) {
			out << endl;
		}
		for (int j = 0;j < matn::mat_size;++j) {
			out << mat(i, j) << ",\t";
		}
	}
	return out;
}

vec::vec()
{
}

vec::vec(const vec & v)
{
	data = v.data;
}

ostream& operator << (ostream& out, vec& v)
{
	for (int i = 0;i < v.data_len();++i) {
		out << v(i) << ",\t";
	}
	return out;
}

pvec::pvec()
{
}

pvec::pvec(const pvec & pv)
{
	pdata = pv.pdata;
}

pvec::pvec(vec & v)
{
	pdata.resize(v.data_len());
	for (int i = 0;i < v.data_len();++i) {
		pdata[i] = &v(i);
	}
}

#if 0

void mat_base(double,3,3)::operator+=(const mat_base(double,3,3) & mat)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) += mat(i, j);
		}
	}
}

void mat_base(double,3,3)::operator+=(mat_base(double,3,3)::data_type num)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) += num;
		}
	}
}

void mat_base(double,3,3)::operator-=(const mat_base(double,3,3) & mat)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) -= mat(i, j);
		}
	}
}

void mat_base(double,3,3)::operator-=(mat_base(double,3,3)::data_type num)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) -= num;
		}
	}
}

void mat_base(double,3,3)::operator*=(mat_base(double,3,3)::data_type num)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) *= num;
		}
	}
}

void mat_base(double,3,3)::operator/=(mat_base(double,3,3)::data_type num)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) /= num;
		}
	}
}

void mat_base(double,3,3)::operator=(const mat_base(double,3,3) & mat)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) = mat(i, j);
		}
	}
}

mat_base(double,3,3) & mat_base(double,3,3)::setIdentity()
{
	int ite = n_row() < n_column() ? n_row() : n_column();
	setZero();
	for (int i = 0;i < ite;++i) {
		(*this)(i, i) = 1;
	}
	return *this;
}

mat_base(double,3,3) & mat_base(double,3,3)::setZero()
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) = 0;
		}
	}
	return *this;
}

mat_base(double,3,3) & mat_base(double,3,3)::setOnes(mat_base(double,3,3)::data_type data)
{
	for (int i = 0;i < n_row();++i) {
		for (int j = 0;j < n_column();++j) {
			(*this)(i, j) = data;
		}
	}
	return *this;
}


matmk::matmk(const mat_base(double, 3, 3)&mat)
{
	(*this) = mat;
}

matmk::matmk(const matmk & mat): matmk()
{
	(*this) = mat;
}

ostream& operator << (ostream& out, mat_base(double,3,3)& mat)
{
	for (int i = 0;i < mat.n_row();++i) {
		if (i > 0) {
			out << endl;
		}
		for (int j = 0;j < mat.n_column();++j) {
			out << mat(i, j) << ",\t";
		}
	}
	return out;
}

matmk operator - (const mat_base(double,3,3)& mat)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = -mat(i, j);
		}
	}
	return ret;
}

matmk operator + (const mat_base(double,3,3)& mat1, const mat_base(double,3,3)& mat2)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat1(i, j) + mat2(i, j);
		}
	}
	return ret;
}

matmk operator - (const mat_base(double,3,3)& mat1, const mat_base(double,3,3)& mat2)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat1(i, j) - mat2(i, j);
		}
	}
	return ret;
}

matmk operator + (const mat_base(double,3,3)& mat, mat_base(double,3,3)::data_type num)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat(i, j) + num;
		}
	}
	return ret;
}

matmk operator - (const mat_base(double,3,3)& mat, mat_base(double,3,3)::data_type num)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat(i, j) - num;
		}
	}
	return ret;
}

matmk operator * (const mat_base(double,3,3)& mat, mat_base(double,3,3)::data_type num)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat(i, j) * num;
		}
	}
	return ret;
}

matmk operator + (mat_base(double,3,3)::data_type num, const mat_base(double,3,3)& mat)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat(i, j) + num;
		}
	}
	return ret;
}

matmk operator - (mat_base(double,3,3)::data_type num, const mat_base(double,3,3)& mat)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = - mat(i, j) + num;
		}
	}
	return ret;
}

matmk operator * (mat_base(double,3,3)::data_type num, const mat_base(double,3,3)& mat)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat(i, j) * num;
		}
	}
	return ret;
}

matmk operator / (const mat_base(double,3,3)& mat, mat_base(double,3,3)::data_type num)
{
	matmk ret;
	for (int i = 0;i < ret.n_row();++i) {
		for (int j = 0;j < ret.n_column();++j) {
			ret(i, j) = mat(i, j) / num;
		}
	}
	return ret;
}

bool matnk::resize(int nr, int nc)
{
	if ((nc != _n_column) || (nr < 0)) {
		return false;
	}

	data.resize(nr * _n_column);
	_update();

	return true;
}

#endif


























































//def_mat_base_in_class_functions(dataType,_m,_k)
#if 1
#define def_mat_base_in_class_functions(dataType,_m,_k)\
void mat_base(dataType,_m,_k)::operator+=(const mat_base(dataType,_m,_k) & mat)						  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) += mat(i, j);									  									  \
		}																  									  \
	}																	  									  \
}																		  									  \
																		  									  \
void mat_base(dataType,_m,_k)::operator+=(mat_base(dataType,_m,_k)::data_type num)					  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) += num;										  									  \
		}																  									  \
	}																	  									  \
}																		  									  \
																		  									  \
void mat_base(dataType,_m,_k)::operator-=(const mat_base(dataType,_m,_k) & mat)						  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) -= mat(i, j);									  									  \
		}																  									  \
	}																	  									  \
}																		  									  \
																		  									  \
void mat_base(dataType,_m,_k)::operator-=(mat_base(dataType,_m,_k)::data_type num)					  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) -= num;										  									  \
		}																  									  \
	}																	  									  \
}																		  									  \
																		  									  \
void mat_base(dataType,_m,_k)::operator*=(mat_base(dataType,_m,_k)::data_type num)					  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) *= num;										  									  \
		}																  									  \
	}																	  									  \
}																		  									  \
																		  									  \
void mat_base(dataType,_m,_k)::operator/=(mat_base(dataType,_m,_k)::data_type num)					  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) /= num;										  									  \
		}																  									  \
	}																	  									  \
}																		  									  \
																		  									  \
void mat_base(dataType,_m,_k)::operator=(const mat_base(dataType,_m,_k) & mat)						  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) = mat(i, j);									  									  \
		}																  									  \
	}																	  									  \
}																		  									  \
																		  									  \
mat_base(dataType,_m,_k) & mat_base(dataType,_m,_k)::setIdentity()									  		  \
{																		  									  \
	int ite = n_row() < n_column() ? n_row() : n_column();				  									  \
	setZero();															  									  \
	for (int i = 0;i < ite;++i) {										  									  \
		(*this)(i, i) = 1;												  									  \
	}																	  									  \
	return *this;														  									  \
}																		  									  \
																		  									  \
mat_base(dataType,_m,_k) & mat_base(dataType,_m,_k)::setZero()										  		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
		for (int j = 0;j < n_column();++j) {							  									  \
			(*this)(i, j) = 0;											  									  \
		}																  									  \
	}																	  									  \
	return *this;														  									  \
}																		  									  \
																		  									  \
mat_base(dataType,_m,_k) & mat_base(dataType,_m,_k)::setOnes(mat_base(dataType,_m,_k)::data_type data)		  \
{																		  									  \
	for (int i = 0;i < n_row();++i) {									  									  \
			for (int j = 0;j < n_column();++j) {						  									  \
				(*this)(i, j) = data;									  									  \
			}															  									  \
	}																	  									  \
	return *this;														  									  \
}																		  									  \
																											  \
mat_base(dataType, _k, _m) mat_base(dataType, _m, _k)::transpose()											  \
{																											  \
	return mat_base(dataType, _k, _m)(data_ptr, column_diff, row_diff);										  \
}																											  \
																											  \
vec_base(dataType, _k) mat_base(dataType, _m, _k)::row(int idx)												  \
{																											  \
	return vec_base(dataType, _k)(data_ptr + idx*row_diff, column_diff);									  \
}																											  \
																											  \
hvec_base(dataType, _m) mat_base(dataType, _m, _k)::col(int idx)											  \
{																											  \
	return hvec_base(dataType, _m)(data_ptr + idx*column_diff, row_diff);									  \
}																											  \
																											  \
dataType mat_base(dataType, _m, _k)::norm() {																  \
	dataType ret = 0;																						  \
	for(int i = 0;i < n_row();++i){																			  \
		for(int j = 0;j < n_column();++j){																	  \
			ret += (*this)(i,j)*(*this)(i,j);																  \
		}																									  \
	}																										  \
	return sqrt(ret);																						  \
}																											  \
																											


#endif

//def_mat_type_in_class_functions(dataType,_m,_k)
#if 1
#define def_mat_type_in_class_functions(dataType,_m,_k)																			  \

#endif

//def_same_class_operator(dataType,_m,_k)
#if 1
#define def_same_class_operator(dataType,_m,_k)																						 \
ostream& operator << (ostream& out, mat_base(dataType, _m, _k)& mat)																 \
{																																	 \
	for (int i = 0;i < mat.n_row();++i) {																							 \
		if (i > 0) {																												 \
			out << endl;																											 \
		}																															 \
		for (int j = 0;j < mat.n_column();++j) {																					 \
			out << mat(i, j) << ",\t";																								 \
		}																															 \
	}																																 \
	return out;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator - (const mat_base(dataType, _m, _k)& mat)														 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = -mat(i, j);																									 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator + (const mat_base(dataType, _m, _k)& mat1, const mat_base(dataType, _m, _k)& mat2)				 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat1(i, j) + mat2(i, j);																					 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator - (const mat_base(dataType, _m, _k)& mat1, const mat_base(dataType, _m, _k)& mat2)				 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat1(i, j) - mat2(i, j);																					 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator + (const mat_base(dataType, _m, _k)& mat, mat_base(dataType, _m, _k)::data_type num)			 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat(i, j) + num;																							 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator - (const mat_base(dataType, _m, _k)& mat, mat_base(dataType, _m, _k)::data_type num)			 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat(i, j) - num;																							 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator * (const mat_base(dataType, _m, _k)& mat, mat_base(dataType, _m, _k)::data_type num)			 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat(i, j) * num;																							 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator + (mat_base(dataType, _m, _k)::data_type num, const mat_base(dataType, _m, _k)& mat)			 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat(i, j) + num;																							 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator - (mat_base(dataType, _m, _k)::data_type num, const mat_base(dataType, _m, _k)& mat)			 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = - mat(i, j) + num;																							 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator * (mat_base(dataType, _m, _k)::data_type num, const mat_base(dataType, _m, _k)& mat)			 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat(i, j) * num;																							 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \
																																	 \
mat_type(dataType, _m, _k) operator / (const mat_base(dataType, _m, _k)& mat, mat_base(dataType, _m, _k)::data_type num)			 \
{																																	 \
	mat_type(dataType, _m, _k) ret;																									 \
	for (int i = 0;i < ret.n_row();++i) {																							 \
		for (int j = 0;j < ret.n_column();++j) {																					 \
			ret(i, j) = mat(i, j) / num;																							 \
		}																															 \
	}																																 \
	return ret;																														 \
}																																	 \

#endif

//def_vec_type_in_class_functions(dataType,_m)
#if 1
#define def_vec_base_in_class_function(dataType, _m)						\
hvec_base(dataType, _m) vec_base(dataType, _m)::transpose()					\
{																			\
	return hvec_base(dataType, _m)(data_ptr, row_diff);						\
}																			\
																			\
vec_base(dataType, _m) hvec_base(dataType, _m)::transpose()					\
{																			\
	return vec_base(dataType, _m)(data_ptr, row_diff);						\
}																			\

#endif

//def_vec_type_in_class_functions(dataType,_m)
#if 1

#define _def_cut_functions(n, dataType, _m)										  \
vec_base(dataType, n) vec_base(dataType, _m)::tail##n() 						  \
{																				  \
	return vec_base(dataType, n)(data_ptr + row_diff*(_m - n), row_diff);		  \
}																				  \
																				  \
vec_base(dataType, n) vec_base(dataType, _m)::head##n() 						  \
{																				  \
	return vec_base(dataType, n)(data_ptr, row_diff);							  \
}																				  \
																				  \
hvec_base(dataType, n) hvec_base(dataType, _m)::tail##n() 						  \
{																				  \
	return hvec_base(dataType, n)(data_ptr + column_diff*(_m - n), column_diff);  \
}																				  \
																				  \
hvec_base(dataType, n) hvec_base(dataType, _m)::head##n() 						  \
{																				  \
	return hvec_base(dataType, n)(data_ptr, column_diff);						  \
}																				  \

#define def_cut_functions(n, dataType, _m) _def_cut_functions(n, dataType, _m)
#define def_all_cut_functions(_m, dataType) DO_3PARA(def_cut_functions, _m, dataType, _m) 

#define def_vec_type_in_class_functions(dataType, _m) \
def_all_cut_functions(_m, dataType);


#endif

#define def_all_vec_func(m) def_vec_base_in_class_function(double, m);def_vec_type_in_class_functions(double, m);
#define def_all_vec_funcm() DO(def_all_vec_func,5);
def_all_vec_funcm();

#define def_all_mat_func(n,m) def_mat_base_in_class_functions(double, n, m);def_mat_type_in_class_functions(double, n, m);def_same_class_operator(double, n, m);
#define def_all_mat_func_m(m) DO(def_all_mat_func,5,m)
#define def_all_mat_func_mn() BIDO(def_all_mat_func_m,5)
def_all_mat_func_mn();


