#pragma once
//#define GLM_FORCE_MESSAGES 1
//#define GLM_FORCE_AVX512 1
#define GLM_FORCE_SSE2 1
//#define GLM_SWIZZLE 1
//#define GLM_MESSAGES 1

//#pragma warning(disable:4201)
//#pragma warning(disable:4244)
//#pragma warning(disable:4100)
//#pragma warning(disable:4189)

#include "../../../glm/glm/glm.hpp"
#include "../../../glm/glm/ext.hpp"

typedef glm::detail::hdata  half;
typedef glm::u8vec2	  uchar2;
typedef glm::i8vec2   schar2;
typedef glm::u8vec2	   byte2;
//typedef glm::i8vec2   sbyte2;
typedef glm::u16vec2 ushort2;
typedef glm::i16vec2  short2;
typedef glm::u32vec2   uint2;
typedef glm::i32vec2    int2;
typedef glm::u16vec2  usvec2;
typedef glm::i16vec2   svec2;
typedef glm::u32vec2  uivec2;
typedef glm::i32vec2   ivec2;
typedef glm::u64vec2  ulong2;
typedef glm::i64vec2  slong2;
typedef glm::vec2       vec2;
typedef glm::vec2     float2;
typedef glm::dvec2   double2;
typedef glm::dvec2     dvec2;
typedef glm::tvec2<glm::detail::hdata, glm::highp>  half2;

typedef glm::u8vec3	  uchar3;
typedef glm::i8vec3   schar3;
typedef glm::u8vec3	   byte3;
//typedef glm::i8vec3   sbyte3;
typedef glm::u16vec3 ushort3;
typedef glm::i16vec3  short3;
typedef glm::u32vec3   uint3;
typedef glm::i32vec3    int3;
typedef glm::u16vec3  usvec3;
typedef glm::i16vec3   svec3;
typedef glm::u32vec3  uivec3;
typedef glm::i32vec3   ivec3;
typedef glm::u64vec3  ulong3;
typedef glm::i64vec3  slong3;
typedef glm::vec3       vec3;
typedef glm::vec3     float3;
typedef glm::dvec3   double3;
typedef glm::dvec3     dvec3;
typedef glm::tvec3<glm::detail::hdata, glm::highp>  half3;

typedef glm::u8vec4	  uchar4;
typedef glm::i8vec4   schar4;
typedef glm::u8vec4	   byte4;
//typedef glm::i8vec4   sbyte4;
typedef glm::u16vec4 ushort4;
typedef glm::i16vec4  short4;
typedef glm::u32vec4   uint4;
typedef glm::i32vec4    int4;
typedef glm::u16vec4  usvec4;
typedef glm::i16vec4   svec4;
typedef glm::u32vec4  uivec4;
typedef glm::i32vec4   ivec4;
typedef glm::u64vec4  ulong4;
typedef glm::i64vec4  slong4;
typedef glm::vec4       vec4;
typedef glm::vec4     float4;
typedef glm::dvec4   double4;
typedef glm::dvec4     dvec4;
typedef glm::tvec4<glm::detail::hdata, glm::highp>  half4;

///// Matrizes
typedef glm::dmat2       dmat2;
typedef glm::dmat3       dmat3;
typedef glm::dmat4       dmat4;
typedef glm::dmat2x2     dmat2x2;
typedef glm::dmat2x3     dmat2x3;
typedef glm::dmat2x4     dmat2x4;
typedef glm::dmat3x2     dmat3x2;
typedef glm::dmat3x3     dmat3x3;
typedef glm::dmat3x4     dmat3x4;
typedef glm::dmat4x2     dmat4x2;
typedef glm::dmat4x3     dmat4x3;
typedef glm::dmat4x4     dmat4x4;


typedef glm::mat2       mat2;
typedef glm::mat3       mat3;
typedef glm::mat4       mat4;
typedef glm::mat2x2     mat2x2;
typedef glm::mat2x3     mat2x3;
typedef glm::mat2x4     mat2x4;
typedef glm::mat3x2     mat3x2;
typedef glm::mat3x3     mat3x3;
typedef glm::mat3x4     mat3x4;
typedef glm::mat4x2     mat4x2;
typedef glm::mat4x3     mat4x3;
typedef glm::mat4x4     mat4x4;



typedef glm::dmat2x2     float2x2;
typedef glm::dmat2x3     float2x3;
typedef glm::dmat2x4     float2x4;
typedef glm::dmat3x2     float3x2;
typedef glm::dmat3x3     float3x3;
typedef glm::dmat3x4     float3x4;
typedef glm::dmat4x2     float4x2;
typedef glm::dmat4x3     float4x3;
typedef glm::dmat4x4     float4x4;


typedef glm::mat2x2     double2x2;
typedef glm::mat2x3     double2x3;
typedef glm::mat2x4     double2x4;
typedef glm::mat3x2     double3x2;
typedef glm::mat3x3     double3x3;
typedef glm::mat3x4     double3x4;
typedef glm::mat4x2     double4x2;
typedef glm::mat4x3     double4x3;
typedef glm::mat4x4     double4x4;
