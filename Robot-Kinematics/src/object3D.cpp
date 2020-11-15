#include "object3D.h"

object3D::object3D(){}
object3D::object3D(double pos_x, double pos_y, double pos_z){
 Origin = {pos_x, pos_y, pos_z};
}
object3D::~object3D(){}

bool object3D::read_object(const char* name){

	uint8_t head[80]; // Header of STL

	///***************************************************************+
	/// Will Crackear :C
	///****************************************************************

	fileObject.open(name, std::ios::in | std::ios::binary );
	if(fileObject){

		fileObject.read(reinterpret_cast<char *> (&head), 80);
		int32_t size; // Number of triangles
		fileObject.read(reinterpret_cast<char *> (&size), sizeof(int32_t));
		ntriangles = size;	// Save number of triangles for class
		triangles = new Triangles[size]; // Generate triangles needed to read the file

		float P0[3], P1[3], P2[3], n[3];
		uint16_t attribute; // Triangle count

		for(int i = 0; i < ntriangles; i++){
			fileObject.read(reinterpret_cast<char *> (&n[0]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&n[1]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&n[2]), sizeof(float));
			triangles[i].normal = {n[0], n[1], n[2]};	//Save coordinates of normal vector

			fileObject.read(reinterpret_cast<char *> (&P0[0]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&P0[1]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&P0[2]), sizeof(float));
			triangles[i].p[0] = { P0[0],P0[1],P0[2] };

			fileObject.read(reinterpret_cast<char *> (&P1[0]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&P1[1]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&P1[2]), sizeof(float));
			triangles[i].p[1] = { P1[0], P1[1],P1[2] };

			fileObject.read(reinterpret_cast<char *> (&P2[0]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&P2[1]), sizeof(float));
			fileObject.read(reinterpret_cast<char *> (&P2[2]), sizeof(float));
			triangles[i].p[2] = { P2[0], P2[1],P2[2] };
			fileObject.read(reinterpret_cast<char *> (&attribute), sizeof(uint16_t));
		}
		fileObject.close();
		return true;
	}else{
		ntriangles = 0;
		cout << "No open file" << endl;
	}
	return false;
}
void object3D::moveOrigin(vector3d tO){
	Origin = tO;
}
void object3D::traslatarOrigin(vector3d tM){
	Origin = Origin + tM;
}
bool object3D::drawObject(){
	glBegin(GL_TRIANGLES);
	glFrontFace(GL_FRONT_AND_BACK);
	Triangles vUnit;

	for(int i = 0; i < ntriangles; i++){
		Triangles Vs(triangles[i].p[0], triangles[i].p[1], triangles[i].p[2]);
		Triangles Vm;

	}
	return true;
}
