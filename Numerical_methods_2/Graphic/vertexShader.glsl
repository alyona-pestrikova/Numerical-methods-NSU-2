#version 130
in vec4 s_vPosition;
//out vec4 s_vColor;
void main () {
	vec4 pos = s_vPosition;
	gl_Position = pos;	
	//s_vColor = vec4(0.9,0.9,0.9,0.1);
}