#include "Tree2.h"
#include <stdio.h>
//#include <GL/glu.h>

Tree2::Tree2() {
	display_list = 0;
//    texture_obj = NULL;
	initialized = false;
	quadric_obj = NULL;
}

Tree2::~Tree2() {

	if (initialized) {
		glDeleteLists(display_list, 1);
		//        glDeleteTextures(1, &texture_obj);
		gluDeleteQuadric(quadric_obj);
	}

}

bool
Tree2::Initialize() {

	quadric_obj = gluNewQuadric();
	gluQuadricNormals(quadric_obj, GLU_SMOOTH);
	return true;
}

void
Tree2::DrawTree2() {

}

void
Tree2::Draw() {

	glPushMatrix();
	glColor3f(0.588, 0.294, 0.0);
	glTranslatef(-35, -45, 0);
	// obj ptr, base rad, top rad, height, slice around, slice up
	gluCylinder(quadric_obj, 1.0, 1.0, 2.0, 16, 16);

	glColor3f(0.133, 0.545, 0.133);
	
	glTranslatef(0, 0, 5.5);
//	gluCylinder(quadric_obj, 2.0, 0.0, 12.0, 16, 16);
	gluSphere(quadric_obj, 4.0, 16, 16);

	glPopMatrix();

}

