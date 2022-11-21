
#include "Cube.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>



Cube::Cube(void) {}

Cube::~Cube(void) {}


// Initializer. Would return false if anything could go wrong.
bool
Cube::Initialize(void) {
	return true;
}

//void
//Cube::Update(void) {
//
//} // Updates the location of the train


void
Cube::Draw(void) {
    glBegin(GL_QUADS);
    // front
    glColor3f(1, 0, 0);
    glNormal3f(0, 0, 1);

    glVertex3f(-1, 1, 2);
    glVertex3f(-1, -1, 2);
    glVertex3f(1, -1, 2);
    glVertex3f(1, 1, 2);

    // back
    glColor3f(0, 1, 0);
    glColor3f(0, 0, -1);

    glVertex3f(-1, 1, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(-1, -1, 0);

    // top
    glColor3f(0, 0, 1);
    glColor3f(0, 1, 0);

    glVertex3f(-1, 1, 0);
    glVertex3f(-1, 1, 2);
    glVertex3f(1, 1, 2);
    glVertex3f(1, 1, 0);

    // bottom
    glColor3f(1, 1, 0);
    glColor3f(0, -1, 0);

    glVertex3f(-1, -1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(1, -1, 2);
    glVertex3f(-1, -1, 2);

    // left
    glColor3f(0, 1, 1);
    glColor3f(-1, 0, 0);

    glVertex3f(-1, 1, 0);
    glVertex3f(-1, -1, 0);
    glVertex3f(-1, -1, 2);
    glVertex3f(-1, 1, 2);

    // right
    glColor3f(1, 0, 1);
    glColor3f(1, 0, 0);

    glVertex3f(1, 1, 2);
    glVertex3f(1, -1, 2);
    glVertex3f(1, -1, 0);
    glVertex3f(1, 1, 0);
    glEnd();

} // Draws everything.
