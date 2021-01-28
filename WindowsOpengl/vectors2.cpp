#include "Vectors2.h"


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
_vec2<T> _vec2<T>::operator + (T &v){
	return _vec2(x+v, y+v);
}
template <class T>
_vec2<T> _vec2<T>::operator + (_vec2<T> &v){
	return _vec2(x+v.x, y+v.y);
}
template <class T>
_vec2<T> _vec2<T>::operator - (T &v){
	return _vec2(x-v, y-v);
}
template <class T>
_vec2<T> _vec2<T>::operator - (_vec2<T> &v){
	return _vec2(x-v.x, y-v.y);
}
template <class T>
_vec2<T> _vec2<T>::operator * (T &v){
	return _vec2(x*v, y*v);
}
template <class T>
_vec2<T> _vec2<T>::operator * (_vec2<T> &v){
	return _vec2(x*v.x, y*v.y);
}
template <class T>
_vec2<T> _vec2<T>::operator / (T &v){
	return _vec2(x/v, y/v);
}
template <class T>
_vec2<T> _vec2<T>::operator / (_vec2<T> &v){
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
_vec3<T> _vec3<T>::operator + (T &v){
	return _vec3(x+v[0], y+v[1], z+v[2]);
}
template <class T>
_vec3<T> _vec3<T>::operator + (_vec3<T> &v){
	return _vec3(x+v.x, y+v.y, z+v.z);
}
template <class T>
_vec3<T> _vec3<T>::operator - (T &v){
	return _vec3(x-v, y-v, z-v);
}
template <class T>
_vec3<T> _vec3<T>::operator - (_vec3<T> &v){
	return _vec3(x-v.x, y-v.y, z-v.z);
}
template <class T>
_vec3<T> _vec3<T>::operator * (T &v){
	return _vec3(x*v, y*v, z*v);
}
template <class T>
_vec3<T> _vec3<T>::operator * (_vec3<T> &v){
	return _vec3(x*v.x, y*v.y, z*v.z);
}
template <class T>
_vec3<T> _vec3<T>::operator / (T &v){
	return _vec3(x/v, y/v, z/v);
}
template <class T>
_vec3<T> _vec3<T>::operator / (_vec3<T> &v){
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
_vec4<T> _vec4<T>::operator + (T &v){
	return _vec4(x+v, y+v, z+v, w+v);
}
template <class T>
_vec4<T> _vec4<T>::operator + (_vec4<T> &v){
	return _vec4(x+v.x, y+v.y, z+v.z, w+v.w);
}
template <class T>
_vec4<T> _vec4<T>::operator - (T &v){
	return _vec4(x-v, y-v, z-v, w-v);
}
template <class T>
_vec4<T> _vec4<T>::operator - (_vec4<T> &v){
	return _vec4(x-v.x, y-v.y, z-v.z, w-v.w);
}
template <class T>
_vec4<T> _vec4<T>::operator * (T &v){
	return _vec4(x*v, y*v, z*v, w*v);
}
template <class T>
_vec4<T> _vec4<T>::operator * (_vec4<T> &v){
	return _vec4(x*v.x, y*v.y, z*v.z, w*v.w);
}
template <class T>
_vec4<T> _vec4<T>::operator / (T &v){
	return _vec4(x/v, y/v, z/v, w/v);
}
template <class T>
_vec4<T> _vec4<T>::operator / (_vec4<T> &v){
	return _vec4(x/v.x, y/v.y, z/v.z, w/v.w);
}
template <class T>
_vec4<T>& _vec4<T>::operator = (T &v){
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
_vec4<T>& _vec4<T>::operator +=(T &v){
	x+=v; y+=v; z+=v; w+=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator +=(_vec4<T> &v){
	x+=v.x; y+=v.y; z+=v.z; w+=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator -=(T &v){
	x-=v; y-=v; z-=v; w-=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator -=(_vec4<T> &v){
	x-=v.x; y-=v.y; z-=v.z; w-=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator *=(T &v){
	x*=v; y*=v; z*=v; w*=v;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator *=(_vec4<T> &v){
	x*=v.x; y*=v.y; z*=v.z; w*=v.w;
	return *this;
}
template <class T>
_vec4<T>& _vec4<T>::operator /=(T &v){
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
int _vec4<T>::operator ==(T &v){
	return ((x==v)&&(y==v)&&(z==v)&&(w==v));
}
template <class T>
int _vec4<T>::operator ==(_vec4<T> &v){
	return ((x==v.x)&&(y==v.y)&&(z==v.z)&&(w==v.w));
}
template <class T>
int _vec4<T>::operator !=(T &v){
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



void main(void)
{
	LONGLONG freq, count1, count2;
	QueryPerformanceCounter((LARGE_INTEGER *)&count1);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	printf("Frequência: %I64d ticks/s\n", freq);
	QueryPerformanceCounter((LARGE_INTEGER *)&count2);
	printf("Contagem: 1: %I64d 2: %I64d dif: %I64d\n", count1, count2, count2-count1);
	printf("Tempo: %I64d µs\n", (count2-count1)*1000000/freq);
}