#include "Tree.h"
#include <stdio.h>
//#include <GL/glu.h>

Tree::Tree() {
	display_list = 0;
//    texture_obj = NULL;
	initialized = false;
	quadric_obj = NULL;
}

Tree::~Tree() {

	if (initialized) {
		glDeleteLists(display_list, 1);
		//        glDeleteTextures(1, &texture_obj);
		gluDeleteQuadric(quadric_obj);
	}

}

bool
Tree::Initialize() {

	quadric_obj = gluNewQuadric();
	gluQuadricNormals(quadric_obj, GLU_SMOOTH);
	return true;
}

void
Tree::DrawTree() {

}

void
Tree::Draw() {

	glPushMatrix();

	// brown color
	glColor3f(0.588, 0.294, 0.0);
	glTranslatef(-45, 40, 0);
	// obj ptr, base rad, top rad, height, slice around, slice up
	gluCylinder(quadric_obj, 1.0, 1.0, 2, 16, 16);

	glTranslatef(6, 2, 0);
	gluCylinder(quadric_obj, 1.0, .75, 2, 16, 16);


	glTranslatef(-6, 4, 0);
	gluCylinder(quadric_obj, 1.0, 1.0, 2, 16, 16);

	// forrest green color
	glColor3f(0.133, 0.545, 0.133);
	
	glTranslatef(0, -6, 2);
	gluCylinder(quadric_obj, 2.0, 0.0, 12.0, 16, 16);
	glTranslatef(6, 2, 0);
	gluCylinder(quadric_obj, 2.0, 0.0, 8.0, 16, 16);
	glTranslatef(-6, 4, 0);
	gluCylinder(quadric_obj, 3.0, 0.0, 16.0, 16, 16);

	glPopMatrix();
}
