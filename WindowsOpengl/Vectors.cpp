#include "stdafx.h"
#include "Vectors.h"



template <class T>
 _vec2<T>::_vec2(void){
	x=y=0;
 };
template <class T>
_vec2<T>::_vec2(T v){
	x=y=v;
}

template <class T>
_vec2<T>::_vec2(T *v){
	i[0]=v[0];
	i[1]=v[1];
}

template <class T>
_vec2<T>::_vec2(T x1, T y1){
	x=x1;
	y=y1;
}

template <class T>
_vec2<T>::_vec2(_vec2<T> &v){
	x=v.x;
	y=v.y;
}
template <class T>
_vec2<T>::_vec2(_vec3<T> &v){
	x=v.x;
	y=v.y;
}
template <class T>
_vec2<T>::_vec2(_vec4<T> &v){
	x=v.x;
	y=v.y;
}
template <class T>
_vec2<T>& _vec2<T>::operator + (T &v){
	return _vec2(x+v, y+v);
}
template <class T>
_vec2<T> _vec2<T>::operator + (_vec2<T> &v){
	return _vec2(x+v.x, y+v.y);
}
template <class T>
_vec2<T>& _vec2<T>::operator - (T &v){
	return _vec2(x-v, y-v);
}
template <class T>
_vec2<T>& _vec2<T>::operator - (_vec2<T> &v){
	return _vec2(x-v.x, y-v.y);
}
template <class T>
_vec2<T>& _vec2<T>::operator * (T &v){
	return _vec2(x*v, y*v);
}
template <class T>
_vec2<T>& _vec2<T>::operator * (_vec2<T> &v){
	return _vec2(x*v.x, y*v.y);
}
template <class T>
_vec2<T>& _vec2<T>::operator / (T &v){
	return _vec2(x/v, y/v);
}
template <class T>
_vec2<T>& _vec2<T>::operator / (_vec2<T> &v){
	return _vec2(x/v.x, y/v.y);
}
template <class T>
_vec2<T>& _vec2<T>::operator = (T &v){
	x=v; y=v;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator = (_vec2<T> &v){
	x=v.x; y=v.y;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator +=(T &v){
	x+=v; y+=v;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator +=(_vec2<T> &v){
	x+=v.x; y+=v.y;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator -=(T &v){
	x-=v; y-=v;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator -=(_vec2<T> &v){
	x-=v.x; y-=v.y;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator *=(T &v){
	x*=v; y*=v;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator *=(_vec2<T> &v){
	x*=v.x; y*=v.y;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator /=(T &v){
	x/=v; y/=v;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator /=(_vec2<T> &v){
	x/=v.x; y/=v.y;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator ++(){
	x++; y++;
	return *this;
}
template <class T>
_vec2<T>& _vec2<T>::operator --(){
	x--; y--;
	return *this;
}
template <class T>
int _vec2<T>::operator ==(T &v){
	return ((x==v)&&(y==v));
}
template <class T>
int _vec2<T>::operator ==(_vec2<T> &v){
	return ((x==v.x)&&(y==v.y));
}
template <class T>
int _vec2<T>::operator !=(T &v){
	return ((x!=v)&&(y!=v));
}
template <class T>
int _vec2<T>::operator !=(_vec2<T> &v){
	return ((x!=v.x)&&(y!=v.y));
}
template <class T>
T& _vec2<T>::operator [](int &v){
	return i[v];
}


template <class T>
_vec3<T>::_vec3(){
	x=0; y=0; z=0;
};
template <class T>
_vec3<T>::_vec3(T v){
	x=y=z=v;
}
template <class T>
_vec3<T>::_vec3(T *v){
	i[0]=v[0];
	i[1]=v[1];
	i[2]=v[2];
}
template <class T>
_vec3<T>::_vec3(T x1, T y1, T z1){
	x=x1;
	y=y1;
	z=z1;
}
template <class T>
_vec3<T>::_vec3(T x1, _vec2<T> &v){
	x=x1;
	y=v.x;
	z=v.y;
}
template <class T>
_vec3<T>::_vec3(_vec2<T> &x1){
	x=x1.x;
	y=x1.y;
	z=0;
}
template <class T>
_vec3<T>::_vec3(_vec3<T> &x1){
	x=x1.x;
	y=x1.y;
	z=x1.z;
}
template <class T>
_vec3<T>::_vec3(_vec4<T> &x1){
	x=x1.x;
	y=x1.y;
	z=x1.z;
}
template <class T>
_vec3<T>::_vec3(_vec2<T> &v, T &z1){
	x=v.x;
	y=v.y;
	z=z1;
}
template <class T>
_vec3<T>::_vec3(_vec2<T> &v, _vec2<T> &z1){
	x=v.x;
	y=v.y;
	z=z1.x;
}
template <class T>
_vec3<T>& _vec3<T>::operator + (T &v){
	return _vec3(x+v[0], y+v[1], z+v[2]);
}
template <class T>
_vec3<T>& _vec3<T>::operator + (_vec3<T> &v){
	return _vec3(x+v.x, y+v.y, z+v.z);
}
template <class T>
_vec3<T>& _vec3<T>::operator - (T &v){
	return _vec3(x-v, y-v, z-v);
}
template <class T>
_vec3<T>& _vec3<T>::operator - (_vec3<T> &v){
	return _vec3(x-v.x, y-v.y, z-v.z);
}
template <class T>
_vec3<T>& _vec3<T>::operator * (T &v){
	return _vec3(x*v, y*v, z*v);
}
template <class T>
_vec3<T>& _vec3<T>::operator * (_vec3<T> &v){
	return _vec3(x*v.x, y*v.y, z*v.z);
}
template <class T>
_vec3<T>& _vec3<T>::operator / (T &v){
	return _vec3(x/v, y/v, z/v);
}
template <class T>
_vec3<T>& _vec3<T>::operator / (_vec3<T> &v){
	return _vec3(x/v.x, y/v.y, z/v.z);
}
template <class T>
_vec3<T>& _vec3<T>::operator = (T &v){
	x=v; y=v; z=v;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator = (_vec3<T> &v){
	x=v.x; y=v.y; z=v.z;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator +=(T &v){
	x+=v; y+=v; z+=v;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator +=(_vec3<T> &v){
	x+=v.x; y+=v.y; z+=v.z;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator -=(T &v){
	x-=v; y-=v; z-=v;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator -=(_vec3<T> &v){
	x-=v.x; y-=v.y; z-=v.z;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator *=(T &v){
	x*=v; y*=v; z*=v;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator *=(_vec3<T> &v){
	x*=v.x; y*=v.y; z*=v.z;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator /=(T &v){
	x/=v; y/=v; z/=v;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator /=(_vec3<T> &v){
	x/=v.x; y/=v.y; z/=v.z;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator ++(){
	x++; y++; z++;
	return *this;
}
template <class T>
_vec3<T>& _vec3<T>::operator --(){
	x--; y--; z--;
	return *this;
}
template <class T>
int _vec3<T>::operator ==(T &v){
	return ((x==v)&&(y==v)&&(z==v));
}
template <class T>
int _vec3<T>::operator ==(_vec3<T> &v){
	return ((x==v.x)&&(y==v.y)&&(z==v.z));
}
template <class T>
int _vec3<T>::operator !=(T &v){
	return ((x!=v)&&(y!=v)&&(z!=v));
}
template <class T>
int _vec3<T>::operator !=(_vec3<T> &v){
	return ((x!=v.x)&&(y!=v.y)&&(z!=v.z));
}
template <class T>
	T& _vec3<T>::operator [](int &v){
		return i[v];
	}


		
template <class T>
_vec4<T>::_vec4(): x(0), y(0), z(0), w(0){};
template <class T>
_vec4<T>::_vec4(T v){
	x=y=z=w=v;
}
template <class T>
_vec4<T>::_vec4(T *v){
	i[0]=v[0];
	i[1]=v[1];
	i[2]=v[2];
	i[3]=v[3];
}
template <class T>
_vec4<T>::_vec4(T x1, T y1, T z1, T w1){
	x=x1;
	y=y1;
	z=z1;
	w=w1;
}
template <class T>
_vec4<T>::_vec4(T x1, T y1, _vec2<T> z1){
	x=x1;
	y=y1;
	z=z1.x
	w=z1.y
}
template <class T>
_vec4<T>::_vec4(T x1, _vec2<T> &y1, T w1){
	x=x1;
	y=y1.x;
	z=y1.y;
	w=w1;
}
template <class T>
_vec4<T>::_vec4(T x1, _vec3<T> &y1){
	x=x1;
	y=y1.x;
	z=y1.y;
	w=y1.z;
}
template <class T>
_vec4<T>::_vec4(_vec2<T> &x1){
	x=x1.x;
	y=x1.y;
	z=0;
	w=0;
}
template <class T>
_vec4<T>::_vec4(_vec3<T> &x1){
	x=x1.x;
	y=x1.y;
	z=x1.z;
	w=0;
}
template <class T>
_vec4<T>::_vec4(_vec4<T> &x1){
	x=x1.x;
	y=x1.y;
	z=x1.z;
	w=x1.w;
}
template <class T>
_vec4<T>::_vec4(_vec2<T> &x1, T z1, T w1){
	x=x1.x;
	y=x1.y;
	z=z1;
	w=w1;
}
template <class T>
_vec4<T>::_vec4(_vec3<T> &x1, T w1){
	x=x1.x;
	y=x1.y;
	z=x1.z
	w=w1;
}
template <class T>
_vec4<T>::_vec4(_vec2<T> &x1, _vec2<T> &z1){
	x=x1.x;
	y=x1.y;
	z=z1.x;
	w=z1.y;
}
template <class T>
_vec4<T>::_vec4(_vec3<T> &x1, _vec2<T> &w1){
	x=x1.x;
	y=x1.y;
	z=x1.z;
	w=w1.x;
}
template <class T>
_vec4<T>::_vec4(_vec3<T> &x1, _vec3<T> &w1){
	x=x1.x;
	y=x1.y;
	z=x1.z;
	w=w1.x;
}
template <class T>
_vec4<T>::_vec4(_vec2<T> &x1, _vec3<T> &z1){
	x=x1.x;
	y=x1.y;
	z=z1.x;
	w=z1.y;
}
template <class T>
_vec4<T>& _vec4<T>::operator + (T v){
	return _vec4(x+v, y+v, z+v, w+v);
}
template <class T>
_vec4<T>& _vec4<T>::operator + (_vec4<T> &v){
	return _vec4(x+v.x, y+v.y, z+v.z, w+v.w);
}
template <class T>
_vec4<T>& _vec4<T>::operator - (T v){
	return _vec4(x-v, y-v, z-v, w-v);
}
template <class T>
_vec4<T>& _vec4<T>::operator - (_vec4<T> &v){
	return _vec4(x-v.x, y-v.y, z-v.z, w-v.w);
}
template <class T>
_vec4<T>& _vec4<T>::operator * (T v){
	return _vec4(x*v, y*v, z*v, w*v);
}
template <class T>
_vec4<T>& _vec4<T>::operator * (_vec4<T> &v){
	return _vec4(x*v.x, y*v.y, z*v.z, w*v.w);
}
template <class T>
_vec4<T>& _vec4<T>::operator / (T v){
	return _vec4(x/v, y/v, z/v, w/v);
}
template <class T>
_vec4<T>& _vec4<T>::operator / (_vec4<T> &v){
	return _vec4(x/v.x, y/v.y, z/v.z, w/v.w);
}
template <class T>
_vec4<T>& _vec4<T>::operator = (T v){
	x=v; y=v; z=v; w=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator = (_vec4<T> &v){
	x=v.x; y=v.y; z=v.z; w=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator = (_vec3<T> &v){
	x=v.x; y=v.y; z=v.z; w=0;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator = (_vec2<T> &v){
	x=v.x; y=v.y; z=0; w=0;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator +=(T v){
	x+=v; y+=v; z+=v; w+=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator +=(_vec4<T> &v){
	x+=v.x; y+=v.y; z+=v.z; w+=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator -=(T v){
	x-=v; y-=v; z-=v; w-=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator -=(_vec4<T> &v){
	x-=v.x; y-=v.y; z-=v.z; w-=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator *=(T v){
	x*=v; y*=v; z*=v; w*=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator *=(_vec4<T> &v){
	x*=v.x; y*=v.y; z*=v.z; w*=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator /=(T v){
	x/=v; y/=v; z/=v; w/=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator /=(_vec4<T> &v){
	x/=v.x; y/=v.y; z/=v.z; w/=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator ++(){
	x++; y++; z++; w++;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator --(){
	x--; y--; z--; w--;
	return *this;
}
template <class T>
int _vec4<T>::operator ==(T v){
	return ((x==v)&&(y==v)&&(z==v)&&(w==v));
}
template <class T>
int _vec4<T>::operator ==(_vec4<T> &v){
	return ((x==v.x)&&(y==v.y)&&(z==v.z)&&(w==v.w));
}
template <class T>
int _vec4<T>::operator !=(T v){
	return ((x!=v)&&(y!=v)&&(z!=v)&&(w!=v));
}
template <class T>
int _vec4<T>::operator !=(_vec4<T> &v){
	return ((x!=v.x)&&(y!=v.y)&&(z!=v.z)&&(w!=v.w));
}
template <class T>
T& _vec4<T>::operator [](int v){
	return i[v];
}










/* // deprecated
schar2::schar2(schar x1, schar y1){
	x = x1;
	y = y1;
}
schar2::schar2(schar *v){
	i[0] = v[0];
	i[1] = v[1];
}
schar2::schar2(schar v){
	x = y = v;
}
schar2::schar2(){
	x = y = 0;
}

schar3::schar3(schar x1, schar y1, schar z1){
	x = x1;
	y = y1;
	z = z1;
}
schar3::schar3(schar *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
schar3::schar3(schar v){
	x = y = z = v;
}
schar3::schar3(){
	x = y = z = 0;
}

schar4::schar4(schar x1, schar y1, schar z1, schar w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
schar4::schar4(schar *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
schar4::schar4(schar v){
	x = y = z = w = v;
}
schar4::schar4(){
	x = y = z = w = 0;
}


uchar2::uchar2(uchar x1, uchar y1){
	x = x1;
	y = y1;
}
uchar2::uchar2(uchar *v){
	i[0] = v[0];
	i[1] = v[1];
}
uchar2::uchar2(uchar v){
	x = y = v;
}
uchar2::uchar2(){
	x = y = 0;
}

uchar3::uchar3(uchar x1, uchar y1, uchar z1){
	x = x1;
	y = y1;
	z = z1;
}
uchar3::uchar3(uchar *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
uchar3::uchar3(uchar v){
	x = y = z = v;
}
uchar3::uchar3(){
	x = y = z = 0;
}

uchar4::uchar4(uchar x1, uchar y1, uchar z1, uchar w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
uchar4::uchar4(uchar *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
uchar4::uchar4(uchar v){
	x = y = z = w = v;
}
uchar4::uchar4(){
	x = y = z = w = 0;
}


short2::short2(short x1, short y1){
	x = x1;
	y = y1;
}
short2::short2(short *v){
	i[0] = v[0];
	i[1] = v[1];
}
short2::short2(short v){
	x = y = v;
}
short2::short2(){
	x = y = 0;
}

short3::short3(short x1, short y1, short z1){
	x = x1;
	y = y1;
	z = z1;
}
short3::short3(short *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
short3::short3(short v){
	x = y = z = v;
}
short3::short3(){
	x = y = z = 0;
}

short4::short4(short x1, short y1, short z1, short w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
short4::short4(short *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
short4::short4(short v){
	x = y = z = w = v;
}
short4::short4(){
	x = y = z = w = 0;
}


ushort2::ushort2(ushort x1, ushort y1){
	x = x1;
	y = y1;
}
ushort2::ushort2(ushort *v){
	i[0] = v[0];
	i[1] = v[1];
}
ushort2::ushort2(ushort v){
	x = y = v;
}
ushort2::ushort2(){
	x = y = 0;
}

ushort3::ushort3(ushort x1, ushort y1, ushort z1){
	x = x1;
	y = y1;
	z = z1;
}
ushort3::ushort3(ushort *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
ushort3::ushort3(ushort v){
	x = y = z = v;
}
ushort3::ushort3(){
	x = y = z = 0;
}

ushort4::ushort4(ushort x1, ushort y1, ushort z1, ushort w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
ushort4::ushort4(ushort *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
ushort4::ushort4(ushort v){
	x = y = z = w = v;
}
ushort4::ushort4(){
	x = y = z = w = 0;
}


float2::float2(float x1, float y1){
	x = x1;
	y = y1;
}
float2::float2(float *v){
	i[0] = v[0];
	i[1] = v[1];
}
float2::float2(float v){
	x = y = v;
}
float2::float2(){
	x = y = 0;
}

float3::float3(float x1, float y1, float z1){
	x = x1;
	y = y1;
	z = z1;
}
float3::float3(float *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
float3::float3(float v){
	x = y = z = v;
}
float3::float3(){
	x = y = z = 0;
}

float4::float4(float x1, float y1, float z1, float w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
float4::float4(float *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
float4::float4(float v){
	x = y = z = w = v;
}
float4::float4(){
	x = y = z = w = 0;
}


double2::double2(double x1, double y1){
	x = x1;
	y = y1;
}
double2::double2(double *v){
	i[0] = v[0];
	i[1] = v[1];
}
double2::double2(double v){
	x = y = v;
}
double2::double2(){
	x = y = 0;
}

double3::double3(double x1, double y1, double z1){
	x = x1;
	y = y1;
	z = z1;
}
double3::double3(double *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
double3::double3(double v){
	x = y = z = v;
}
double3::double3(){
	x = y = z = 0;
}

double4::double4(double x1, double y1, double z1, double w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
double4::double4(double *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
double4::double4(double v){
	x = y = z = w = v;
}
double4::double4(){
	x = y = z = w = 0;
}




vec2::vec2(float x1, float y1){
	x = x1;
	y = y1;
}
vec2::vec2(float *v){
	i[0] = v[0];
	i[1] = v[1];
}
vec2::vec2(float v){
	x = y = v;
}
vec2::vec2(){
	x = y = 0;
}

vec3::vec3(float x1, float y1, float z1){
	x = x1;
	y = y1;
	z = z1;
}
vec3::vec3(float *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
vec3::vec3(float v){
	x = y = z = v;
}
vec3::vec3(){
	x = y = z = 0;
}

vec4::vec4(float x1, float y1, float z1, float w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
vec4::vec4(float *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
vec4::vec4(float v){
	x = y = z = w = v;
}
vec4::vec4(){
	x = y = z = w = 0;
}


usvec2::usvec2(ushort x1, ushort y1){
	x = x1;
	y = y1;
}
usvec2::usvec2(ushort *v){
	i[0] = v[0];
	i[1] = v[1];
}
usvec2::usvec2(ushort v){
	x = y = v;
}
usvec2::usvec2(){
	x = y = 0;
}

usvec3::usvec3(ushort x1, ushort y1, ushort z1){
	x = x1;
	y = y1;
	z = z1;
}
usvec3::usvec3(ushort *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
}
usvec3::usvec3(ushort v){
	x = y = z = v;
}
usvec3::usvec3(){
	x = y = z = 0;
}

usvec4::usvec4(ushort x1, ushort y1, ushort z1, ushort w1){
	x = x1;
	y = y1;
	z = z1;
	w = w1;
}
usvec4::usvec4(ushort *v){
	i[0] = v[0];
	i[1] = v[1];
	i[2] = v[2];
	i[3] = v[3];
}
usvec4::usvec4(ushort v){
	x = y = z = w = v;
}
usvec4::usvec4(){
	x = y = z = w = 0;
}

*/

