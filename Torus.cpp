#include "Torus.h"
#include "libtarga.h"
#include <Fl/math.h>
#include <stdio.h>
#include <GL/glu.h>
#include <GL/glut.h>


Torus::Torus(void) {
	display_list = 0;
//    texture_obj = NULL;
	initialized = false;
}


Torus::~Torus(void) {
    
    if (initialized) {
        glDeleteLists(display_list, 1);
//        glDeleteTextures(1, &texture_obj);
    }
}



// Initializer. Would return false if anything could go wrong.
bool
Torus::Initialize(void) {


    // We only do all this stuff once, when the GL context is first set up.
    initialized = true;

	return true;
}

//void
//Torus::Update(void) {
//
//} // Updates the location of the train
struct Vector3 { float x; float y; float z; };
void
Torus::Draw(void) {

	glPushMatrix();
	// moves it to the front left and a little off the ground
//	glTranslatef(35, -40, 1);
	glColor3f(1, 0.0627, 0.9412); // hot pink
	glColor3f(1, 1, 1); // white

	glTranslatef(0, 5, 0);


	for (int d = 0; d <= 3; d++) {
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(0, 1, 0);
		//		glTranslatef(0, 1, 0);
		glVertex3f(0, 2, 0);
		//		glTranslatef(0, -1, 1);
		glVertex3f(0, 1, 1);
		//		glTranslatef(0, 1, 0);
		glVertex3f(0, 2, 1);
	glEnd();
		glTranslatef(0, 1, 0);
	}
	


	glPopMatrix();
 
//	// this is the hot pink side?
//    for (int d = 0; d <= 3; d++) {
//		glBegin(GL_POLYGON);
//		float angle = d * 45.0 / 360;
//		glNormal3f(cos(angle), sin(angle), 0);
//		// x if zero for all here... i think
//		glVertex3f(0, 4, 0);
//		glVertex3f(0, 5, 0);
//		glVertex3f(0, 6, 1);
//		glVertex3f(0, 5, 2);
//		glVertex3f(0, 4, 2);
//		glVertex3f(0, 3, 1);
//		glEnd();
//		glRotatef(45.0, 0, 0, 1);
//    }
//	// to unrotate it, I think...
//	glRotatef(-45.0, 0, 0, 1);
//	glColor3f(0.1216, 0.3176, 1);
//	
//    for (int d = 0; d <= 3; d++) {
//		glBegin(GL_POLYGON);
//		float angle = d * 45.0 / 360;
//		glNormal3f(-cos(angle), -sin(angle), 0);
//		// x if zero for all here... i think
//		glVertex3f(0, 3, 1);
//		glVertex3f(0, 4, 2);
//		glVertex3f(0, 5, 2);
//		glVertex3f(0, 6, 1);
//		glVertex3f(0, 5, 0);
//		glVertex3f(0, 4, 0);
//		glEnd();
//		glRotatef(45.0, 0, 0, 1);
//    }
    
//    glPushMatrix();
//    glCallList(display_list);
//    glPopMatrix();
}

void
Torus::DrawTorus(void) {
}
