#include "Roof.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>


// center should be at 26, 0, 2?
Roof::Roof(void) {
    x = 26;
    y = 0;
    z = 2;
	display_list = 0;
    texture_obj = NULL;
	initialized = false;
}

// hopefully this will place the roof wherever I want.
Roof::Roof(int c[3]) {
    x, y, z = c[0], c[1], c[2];
	display_list = 0;
    texture_obj = NULL;
	initialized = false;
}

Roof::~Roof(void) {
    
    if (initialized) {
        glDeleteLists(display_list, 1);
        glDeleteTextures(1, &texture_obj);
    }
}


// Initializer. Would return false if anything could go wrong.
bool
Roof::Initialize(void) {
    ubyte   *image_data;
    int	    image_height, image_width;


    // Load the image for the texture. The texture file has to be in
    // a place where it will be found.
    if ( ! ( image_data = (ubyte*)tga_load("red_roof.tga", &image_width,
					   &image_height, TGA_TRUECOLOR_24) ) )
    {
	fprintf(stderr, "Roof::Initialize: Couldn't load red_roof.tga\n");
	return false;
    }

    // This creates a texture object and binds it, so the next few operations
    // apply to this texture.
    glGenTextures(1, &texture_obj);
    glBindTexture(GL_TEXTURE_2D, texture_obj);

    // This sets a parameter for how the texture is loaded and interpreted.
    // basically, it says that the data is packed tightly in the image array.
    // DON'T KNOW IF I ACTUALLY NEED THIS OR NAW!!!
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // This sets up the texture with high quality filtering. First it builds
    // mipmaps from the image data, then it sets the filtering parameters
    // and the wrapping parameters. We want the grass to be repeated over the
    // ground.
    gluBuild2DMipmaps(GL_TEXTURE_2D,3, image_width, image_height, 
		      GL_RGB, GL_UNSIGNED_BYTE, image_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		    GL_NEAREST_MIPMAP_LINEAR);

    // This says what to do with the texture. Modulate will multiply the
    // texture by the underlying color.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 

    // Now do the geometry. Create the display list.
    display_list = glGenLists(1);
    glNewList(display_list, GL_COMPILE);

	// Turn on texturing and bind the grass texture.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_obj);

    DrawRoof();

	// Turn texturing off again, because we don't want everything else to
	// be textured.
	glDisable(GL_TEXTURE_2D);
    glEndList();

    // We only do all this stuff once, when the GL context is first set up.
    initialized = true;

	return true;
}

//void
//Roof::Update(void) {
//
//} // Updates the location of the train

// this i jus copied and modified from the ground.cpp version
void
Roof::Draw(void) {
    glPushMatrix();
    glCallList(display_list);
    glPopMatrix();
}

// center should be at 26, 0, 2?
void
Roof::DrawRoof(void) {

    glBegin(GL_QUADS);
    // this I think is the bottom?
    glColor3f(1, 0, 0);
    glNormal3f(0, 0, -1);

    glVertex3f(x-3, y+3, z);
    glVertex3f(x+3, y+3, z);
    glVertex3f(x+3, y-3, z);
    glVertex3f(x-3, y-3, z);
    glEnd();

    // this is where will build 4 triangles to a point
    glBegin(GL_TRIANGLES);

    // facing xpos?
    glColor3f(1, 0, 0);
    glNormal3f(1, 0, 1);

    glVertex3f(x, y, z+2); 
    glVertex3f(x+3, y-3, z);
    glVertex3f(x+3, y+3, z);

    // facing xneg?
    glColor3f(1, 0, 0);
    glNormal3f(-1, 0, 1);

    glVertex3f(x, y, z+2); 
    glVertex3f(x-3, y+3, z);
    glVertex3f(x-3, y-3, z);

    // facing ypos?
    glColor3f(1, 0, 0);
    glNormal3f(0, 1, 1);

    glVertex3f(x, y, z+2); // say top?
    glVertex3f(x+3, y+3, z);
    glVertex3f(x-3, y+3, z);

    // facing yneg?
    glColor3f(1, 0, 0);
    glNormal3f(0, -1, 1);

    glVertex3f(x, y, z+2); // say top?
    glVertex3f(x-3, y-3, z);
    glVertex3f(x+3, y-3, z);
    glEnd();

}



