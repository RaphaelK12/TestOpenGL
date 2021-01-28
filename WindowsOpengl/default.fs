#version 410 core
// Output
layout (location = 0) out vec4 color;
// Input from vertex shader
in VS_OUT{
	// Vertex positions
	vec4 position;		// position in local space
	vec4 position_M;	// position in global space
	vec4 position_V;	// position in view space
	vec4 position_P;	// position in projection space
	vec4 position_MV;	// position in model view space
	vec4 position_MVP;	// position in model view projection space
	vec3 normal;	// normal
	vec3 lightDir;	// Light
	vec2 uv1;		// first uv
	vec2 uv2;		// Second uv possible not used
	vec4 color1;		// vertex color 
	vec4 color2;	// vertex color 
} fs_in;

// Material properties
uniform vec3 viewPos = vec3(5,5,0);
uniform vec4 diffuse_albedo = vec4(0.5, 0.2, 0.7, 1);
uniform vec3 specular_albedo = vec3(0.7);
uniform float specular_power = 128.0; // 200

vec3 lightColor = vec3(1.0, 1.0, 1.0);
float lightPower = 18.0; // 40

struct material{
	vec4 diffuse;		// color passed to program
	vec4 color1;		// color passed to program
	vec4 color2;		// color passed to program
	vec4 color3;		// color passed to program
	
	vec4 ambient;		// color passed to program
	vec4 emission;		// color passed to program
	vec4 translucenci;	// color passed to program
	vec4 sadowsColor;	// color passed to program
	
	vec4 specular;		// color passed to program
	vec4 reflex;		// color passed to program
	vec4 shinines;		// color passed to program
};

uniform material mt;

struct light{
	vec3 direction;
	vec3 color;
	float power;
	vec3 specPower;
};
struct shading{
	vec3 diffuse;
	vec3 specular;
	float rim;
	float distance;
};

vec4 blinPhong_1( in vec3 n, in vec3 l, in vec3 v, 
				in float spec_power, in vec3 spec_albedo,
				in vec4 diff_albedo, in vec4 color){
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	vec4 diffuse = max(dot(N, L), 0.0) * diff_albedo; // Compute the diffuse component for each fragment
	vec3 specular = pow(max(dot(N, H), 0.0), spec_power) * spec_albedo; // Compute the specular component for each fragment
	return diffuse + vec4(specular, 0);	// Write final color to the framebuffer
}
vec4 blinPhong_2( in vec3 n, in vec3 l, in vec3 v, 
				in float spec_power, in vec3 spec_albedo,
				in vec4 diff_albedo, in vec4 color){
  vec3 normal = normalize(n);
  vec3 lightDir = l;
  float distance = length(lightDir);
  distance = distance * distance;
  lightDir = normalize(lightDir);
  float lambertian = max(dot(lightDir, normal), 0.0);
  float specular = 0.0;
  // if (lambertian > 0.0) {
    vec3 viewDir = normalize(v);
     // this is blinn phong
     vec3 halfDir = normalize(lightDir + viewDir);
     specular = pow(max(dot(halfDir, normal), 0.0), specular_power);
  // }
  vec3 colorLinear = diff_albedo.rgb * lambertian * lightColor * lightPower / distance +
                     spec_albedo * specular * lightColor * lightPower / distance;
  return vec4(colorLinear.rgb, diff_albedo.a);				
}
vec4 blinPhong_3( in vec3 n, in vec3 l, in vec3 v, // this is phong, good specular in angular
				in float spec_power, in vec3 spec_albedo,
				in vec4 diff_albedo, in vec4 color){
	vec3 normal = normalize(n);
	vec3 lightDir = l;
	float distance = length(lightDir);
	distance = distance * distance;
	lightDir = normalize(lightDir);
	float lambertian = max(dot(lightDir, normal), 0.0);
	float specular = 0.0;
	// if (lambertian > 0.0) {
		vec3 viewDir = normalize(v);
		 vec3 reflectDir = reflect(-lightDir, normal);
		 float specAngle = max(dot(reflectDir, viewDir), 0.0);
		 specular = pow(specAngle, specular_power/4.0);
	// }
	vec3 colorLinear = lambertian * diff_albedo.rgb * lightColor * lightPower / distance +
					 spec_albedo * specular * lightColor * lightPower / distance;
	return vec4(colorLinear.rgb, diff_albedo.a);				
}

shading lambert( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l.direction);
	s.diffuse = l.color * max(dot(N, L), 0.0)*l.power; // Compute the diffuse component for each fragment
	s.specular = vec3(0); // Compute the specular component for each fragment
	s.rim = 0;
	return s;	// Write final color to the framebuffer
}
shading blinPhong1( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	s.diffuse = l.color * max(dot(N, L), 0.0); // Compute the diffuse component for each fragment
	s.specular = l.color* pow(vec3(max(dot(N, H), 0.0)), l.specPower); // Compute the specular component for each fragment
	s.rim = 0;
	return s;	// Write final color to the framebuffer
}
shading blinPhong2( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V);
	float distance = length(l.direction);
	s.distance = distance * distance;
	s.diffuse = l.color * max(dot(L, N), 0.0)* l.power/ s.distance;
	s.specular = l.color* pow(vec3(max(dot(H, N), 0.0)) , l.specPower) * l.power / s.distance;
	s.rim = 0;
	return s;
}
shading blinPhong3( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	float distance = length(l.direction);
	float specAngle = max(dot(reflect(-L, N), V), 0.0);
	s.distance = distance * distance;
	s.diffuse = l.color* max(dot(L, N), 0.0) * l.power / s.distance;
	s.specular = l.color* pow(vec3(specAngle) , l.specPower/4.0) * l.power / s.distance;
	s.rim = 0;
	return s;				
}

void main(void){
	light l;
	l.direction=fs_in.lightDir;
	l.color=lightColor;
	l.power = lightPower;
	l.specPower = mt.shinines.rgb;
	// color = blinPhong_2(fs_in.normal, fs_in.lightDir, viewPos, 
	// specular_power, specular_albedo,	diffuse_albedo,	fs_in.color1);
	shading s = blinPhong1(fs_in.normal, viewPos, l);
	color = vec4(
					mt.ambient.rgb + mt.emission.rgb +
					s.diffuse * mt.diffuse.rgb +
					s.specular * mt.specular.rgb,
	mt.diffuse.a);
		
		
		
		
		


}
