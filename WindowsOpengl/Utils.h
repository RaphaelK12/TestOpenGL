#ifndef _utils_h
#define _utils_h 1

#include "stdafx.h"
//#include "Vectors.h"
#ifndef max
#define max(a,b) (a>b?a:b)
#endif

#ifndef min
#define min(a,b) (a>b?b:a)
#endif

#define PI_2 (1.57079632679489661923f)   // pi/2
#define PI   (3.1415926535897932384626433832795f)
#define PI_d (3.1415926535897932384626433832795)

#define RADIANS_PER_DEGREE (PI/180.f)

inline float deg(float n);
inline float rad(float n);
//inline double deg(double n);
//inline double rad(double n);

int makeSphere(int xres, int yres, float3 size, int *nvert, int *nindex, vec3 **ver, vec3 **nor, usvec3 **ind);
void drawRandPoints(int num);
void drawTorus(int xres, int yres, float3 size);
void drawTorus2(int xres, int yres, float3 size);
void makeTorus(int xres, int yres, float3 size);
void drawAxis();
void drawGrid();


class SolidSphere
{
protected:
    float *vertices;
    float *normals;
    float *texcoords;
    ushort *indices;
	int numindices;
public:
    SolidSphere(float radius, unsigned int rings, ushort sectors)
    {
        float const R = 1.f/float(rings-1);
        float const S = 1.f/float(sectors-1);
        ushort r, s;

        vertices = new float[rings * sectors * 3];
        normals = new float[rings * sectors * 3];
        texcoords = new float[rings * sectors * 2];
        float *v = vertices;
        float *n = normals;
        float *t = texcoords;
        for(r = 0; r < rings; r++) for(s = 0; s < sectors; s++) {
                float const y = sin( -PI_2 + PI * r * R );
                float const x = cos(2*PI * s * S) * sin( PI * r * R );
                float const z = sin(2*PI * s * S) * sin( PI * r * R );

                *t++ = s*S;
                *t++ = r*R;

                *v++ = x * radius;
                *v++ = y * radius;
                *v++ = z * radius;

                *n++ = x;
                *n++ = y;
                *n++ = z;
        }

        indices = new ushort[rings * sectors * 4];
		numindices = rings * sectors * 4;
        ushort *i = indices;
        for(r = 0; r < rings-1; r++) for(s = 0; s < sectors-1; s++) {
                *i++ = r * sectors + s;
                *i++ = r * sectors + (s+1);
                *i++ = (r+1) * sectors + (s+1);
                *i++ = (r+1) * sectors + s;
        }
    }

    void draw(GLfloat x, GLfloat y, GLfloat z)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(x,y,z);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
        glNormalPointer(GL_FLOAT, 0, &normals[0]);
        glTexCoordPointer(2, GL_FLOAT, 0, &texcoords[0]);
        glDrawElements(GL_QUADS, numindices, GL_UNSIGNED_SHORT, &indices[0]);
        glPopMatrix();
    }
};

class sphere{
public:
	float *mVertices;
	float *mNormals;
	float *mTexture;
	char *mIndexes;

	// rings defines how many circles exists from the bottom to the top of the sphere
	// sectors defines how many vertexes define a single ring
	// radius defines the distance of every vertex from the center of the sphere.
	void generateSphereData(int totalRings, int totalSectors, float radius)
    {
        mVertices = new float[totalRings * totalSectors * 3];
        mNormals = new float[totalRings * totalSectors * 3];
        mTexture = new float[totalRings * totalSectors * 2];
        mIndexes = new char[totalRings * totalSectors * 6];

        float R = 1.0f / (float)(totalRings-1);
        float S = 1.0f / (float)(totalSectors-1);
        int r, s;

        float x, y, z;
        int vertexIndex = 0, textureIndex = 0, indexIndex = 0, normalIndex = 0;

        for(r = 0; r < totalRings; r++)
        {
            for(s = 0; s < totalSectors; s++)
            {
                y = (float)sin((-PI / 2.0f) + PI * r * R );
                x = (float)cos(2.0f * PI * s * S) * (float)sin(PI * r * R );
                z = (float)sin(2.0f * PI * s * S) * (float)sin(PI * r * R );

                if (mTexture != NULL)
                {
                    mTexture[textureIndex] = s * S;
                    mTexture[textureIndex + 1] = r * R;

                    textureIndex += 2;
                }

                mVertices[vertexIndex] = x * radius;
                mVertices[vertexIndex + 1] = y * radius;
                mVertices[vertexIndex + 2] = z * radius;

                vertexIndex += 3;

                mNormals[normalIndex] = x;
                mNormals[normalIndex + 1] = y;
                mNormals[normalIndex + 2] = z;

                normalIndex += 3;
            }
        }


        int r1, s1;
        for(r = 0; r < totalRings ; r++)
        {
            for(s = 0; s < totalSectors ; s++)
            {
                r1 = (r + 1 == totalRings) ? 0 : r + 1;
                s1 = (s + 1 == totalSectors) ? 0 : s + 1;

                mIndexes[indexIndex] = (char)(r * totalSectors + s);
                mIndexes[indexIndex + 1] = (char)(r * totalSectors + (s1));
                mIndexes[indexIndex + 2] = (char)((r1) * totalSectors + (s1));

                mIndexes[indexIndex + 3] = (char)((r1) * totalSectors + s);
                mIndexes[indexIndex + 4] = (char)((r1) * totalSectors + (s1));
                mIndexes[indexIndex + 5] = (char)(r * totalSectors + s);
                indexIndex += 6;
            }
        }
    }
};

float inline fact(float x){
	if(x>1)
		return fact(x-1);
	return 1;
}

float inline P4(float x){
	return 1 + x + x*x/2 + x*x*x/6 /*fact(3)*/ + x*x*x*x/24 /*fact(4)*/ ;
	return     x - x*x/2 + x*x*x/6 /*fact(3)*/ - x*x*x*x/24 /*fact(4)*/ ;


	//sin = x - pow(x, 3)/fact(3) + pow(x, 5)/fact(5) - pow(x, 7)/fact(7);
	//cos = 1 - pow(x, 2)/fact(2) + pow(x, 4)/fact(4) - pow(x, 6)/fact(6);
	//eZ  = 1+x+pow(x, 2)/fact(2) + pow(x, 3)/fact(3) + pow(x, 4)/fact(4);
};

// trigonometric
inline vec3 sqrt(vec3 a){
	return vec3(sqrt(a.x), sqrt(a.y), sqrt(a.z)); 
}

inline dvec3 cross( dvec3 a, dvec3 b){
	return dvec3(a.y*b.z - b.y*a.z, 
				 a.x*b.z - b.x*a.z,
				 a.x*b.y - b.x*a.y);
}

inline vec3 cross(vec3 a, vec3 b){
	return vec3(a.y*b.z - a.z*b.y, 
				a.z*b.x - a.x*b.z, 
				a.x*b.y - a.y*b.x);
}

inline float length(vec3 a){
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

inline float lensqr(vec3 a){
	return (a.x*a.x + a.y*a.y + a.z*a.z);
}

inline float distance(vec3 a, vec3 b){
	return length(a-b);
}

inline vec3 normalize(vec3 a){
	float len = length(a);
	if (len <-0.000001f || len > 0.000001f)
		return a/length(a);
	return a;
}

inline float dot(vec3 a, vec3 b){
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

inline vec3 faceforward(vec3 N, vec3 I, vec3 Nref){
	if(dot(Nref, I) < 0.0f){
		return N;
	}
	return -N;
}

inline vec3 reflect(vec3 I, vec3 N){
	return I - N * dot(N, I) * 2.0f;
}

inline vec3 refract (vec3 I, vec3 N, float eta){
	float k = 1.0f - eta* eta* (1.0f - dot(N, I) * dot(N, I));
	if (k < 0.0f) 
		return vec3(0.0f);
	else 
		return I * eta - (N * sqrt(k)) + eta * dot(N, I) ;
}

inline float clamp(float val, float a, float b) {
    return val < a ? a : (val > b ? b : val);
}
inline vec2 clamp(vec2 val, float a, float b) {
    vec2 tmp(
        val.x < a ? a : (val.x > b ? b : val.x), 
        val.y < a ? a : (val.y > b ? b : val.y));
    return tmp;
}
inline vec2 clamp(vec2 val, vec2 a, vec2 b) {
    vec2 tmp(
        val.x < a.x ? a.x : (val.x > b.x ? b.x : val.x), 
        val.y < a.y ? a.y : (val.y > b.y ? b.y : val.y));
    return tmp;
}
inline vec3 clamp(vec3 val, float a, float b) {
    vec3 tmp(
        val.x < a ? a : (val.x > b ? b : val.x),
        val.y < a ? a : (val.y > b ? b : val.y),
        val.z < a ? a : (val.z > b ? b : val.z));
    return tmp;
}
inline vec3 clamp(vec3 val, vec3 a, vec3 b) {
    vec3 tmp(
        val.x < a.x ? a.x : (val.x > b.x ? b.x : val.x),
        val.y < a.y ? a.y : (val.y > b.y ? b.y : val.y),
        val.z < a.z ? a.z : (val.z > b.z ? b.z : val.z));
    return tmp;
}
inline vec4 clamp(vec4 val, float a, float b) {
    vec4 tmp(
        val.x < a ? a : (val.x > b ? b : val.x),
        val.y < a ? a : (val.y > b ? b : val.y),
        val.z < a ? a : (val.z > b ? b : val.z),
        val.w < a ? a : (val.w > b ? b : val.w));
    return tmp;
}
inline vec4 clamp(vec4 val, vec4 a, vec4 b) {
    vec4 tmp(
        val.x < a.x ? a.x : (val.x > b.x ? b.x : val.x),
        val.y < a.y ? a.y : (val.y > b.y ? b.y : val.y),
        val.z < a.z ? a.z : (val.z > b.z ? b.z : val.z),
        val.w < a.w ? a.w : (val.w > b.w ? b.w : val.w));
    return tmp;
}

inline float mix (float a, float b, float factor){
    return a * (1 - factor) + b * factor;
}
inline vec2 mix (vec2 a, vec2 b, float factor){
    return a * (1 - factor) + b * factor;
}
inline vec3 mix (vec3 a, vec3 b, float factor){
    return a * (1 - factor) + b * factor;
}
inline vec4 mix (vec4 a, vec4 b, float factor){
    return a * (1 - factor) + b * factor;
}




inline vec3 calcNormal(vec3 v1, vec3 v2, vec3 v3) {
    vec3 n1, n2;
    n1 = v2 - v1;
    n2 = v2 - v3;
    return cross(n1, n2);
}

inline vec3 faceNormal(vec3 v1, vec3 v2, vec3 v3)
{
	vec3 n1, n2;
	// Calculate two vectors from the three points
	n1 = v1 - v2;
	n2 = v2 - v3;
	// Take the cross product of the two vectors to get
	// the normal vector and
	// Normalize the vector (shorten length to one)
	return normalize(cross(n1, n2));
}

template <typename T>
T bezier3(T a, T b, T c, float t) {
    T e = mix(a, b, t);
    T f = mix(b, c, t);

    return  mix(e, f, t);
}

template <typename T>
T bezier4(T a, T b, T c, T d, float t) {
    T e = mix(a, b, t);
    T f = mix(b, c, t);
    T g = mix(c, d, t);

    T h = mix(e, f, t);
    T i = mix(f, g, t);

    return mix(h, i, t);
}

template <typename T>
T bezier5(T a, T b, T c, T d, T e, float t) {
    T f = mix(a, b, t);
    T g = mix(b, c, t);
    T h = mix(c, d, t);
    T i = mix(d, e, t);

    T j = mix(f, g, t);
    T k = mix(g, h, t);
    T l = mix(h, i, t);

    T m = mix(j, k, t);
    T n = mix(k, l, t);

    return mix(m, n, t);
}

class frame {
public:
    frame();
    ~frame();
    frame(const frame& f);
    frame(vec2 _c1, vec2 _c2, vec2 _p);
    frame& operator = (const frame& f) ;
    frame& operator = (const frame* f) ;
    float2 c1;
    float2 c2;
    float2 p;
};

struct bz2d {
    vec2 c1;
    vec2 c2;
    vec2 p;
};
struct bz3d {
    vec3 c1;
    vec3 c2;
    vec3 p;
};



class animation {
public:
    animation(std::vector<frame>& f);
    animation(animation& a);
    animation(animation* a);
    ~animation();
    animation();
    animation& operator = (animation& a);
    animation& operator = (animation* a);
    float getFrame(float t);
    std::vector<frame> frames;
};

class bezier2d {
public:
    bezier2d(std::vector<bz2d>& f);
    bezier2d(bezier2d& a);
    bezier2d(bezier2d* a);
    ~bezier2d();
    bezier2d();
    bezier2d& operator = (bezier2d& a);
    bezier2d& operator = (bezier2d* a);
    float2 getPos(int p1, int p2, float t);
    std::vector<bz2d> frames;
};

class bezier3d {
public:
    bezier3d(std::vector<bz3d>& f);
    bezier3d(bezier3d& a);
    bezier3d(bezier3d* a);
   ~bezier3d();
    bezier3d();
    bezier3d& operator = (bezier3d& a);
    bezier3d& operator = (bezier3d* a);
    float3 getPos(int p1, int p2, float t);
    std::vector<bz3d> frames;
};



float fBezier2(frame& f1, frame& f2, float t);

#endif
