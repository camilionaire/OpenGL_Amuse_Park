#include "Tree3.h"
#include <stdio.h>
//#include <GL/glu.h>

Tree3::Tree3() {
	display_list = 0;
//    texture_obj = NULL;
	initialized = false;
	quadric_obj = NULL;
}

Tree3::~Tree3() {

	if (initialized) {
		glDeleteLists(display_list, 1);
		//        glDeleteTextures(1, &texture_obj);
		gluDeleteQuadric(quadric_obj);
	}

}

bool
Tree3::Initialize() {

	quadric_obj = gluNewQuadric();
	gluQuadricNormals(quadric_obj, GLU_SMOOTH);
	return true;
}

void
Tree3::DrawTree3() {

	glPushMatrix();
	glScalef(0.6, 0.6, 0.6);
	glColor3f(0.588, 0.294, 0.0);
	// obj ptr, base rad, top rad, height, slice around, slice up
	gluCylinder(quadric_obj, 1.0, 1.0, 2.0, 16, 16);

	glColor3f(0.133, 0.545, 0.133);
	
	glTranslatef(0, 0, 9.5);
	glScalef(1.0, 1.0, 2.0);
//	gluCylinder(quadric_obj, 2.0, 0.0, 12.0, 16, 16);
	gluSphere(quadric_obj, 4.0, 16, 16);

	glPopMatrix();
}

void
Tree3::Draw() {

	glPushMatrix();
	glTranslatef(48, 12, 0);
	DrawTree3();
	glTranslatef(-8, 0, 0);
	DrawTree3();
	glTranslatef(-8, 0, 0);
	DrawTree3();
	glTranslatef(0, -24, 0);
	DrawTree3();
	glTranslatef(8, 0, 0);
	DrawTree3();
	glTranslatef(8, 0, 0);
	DrawTree3();

	glPopMatrix();

}


