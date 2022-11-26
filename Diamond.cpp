#include "Diamond.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>


Diamond::Diamond(void) {
	display_list = 0;
    texture_obj = NULL;
	initialized = false;
}


Diamond::~Diamond(void) {
    
    if (initialized) {
        glDeleteLists(display_list, 1);
        glDeleteTextures(1, &texture_obj);
    }
}



// Initializer. Would return false if anything could go wrong.
bool
Diamond::Initialize(void) {
    ubyte   *image_data;
    int	    image_height, image_width;


    // Load the image for the texture. The texture file has to be in
    // a place where it will be found.
    if ( ! ( image_data = (ubyte*)tga_load("blue_glass.tga", &image_width,
					   &image_height, TGA_TRUECOLOR_24) ) )
    {
	fprintf(stderr, "Cube::Initialize: Couldn't load wh_wood.tga\n");
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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
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

    DrawDiamond();

	// Turn texturing off again, because we don't want everything else to
	// be textured.
	glDisable(GL_TEXTURE_2D);
    glEndList();

    // We only do all this stuff once, when the GL context is first set up.
    initialized = true;

	return true;
}


void
Diamond::Draw(void) {
    glPushMatrix();
    glCallList(display_list);
    glPopMatrix();
}

void
Diamond::DrawDiamond(void) {

    glBegin(GL_TRIANGLES);

    // this should be bottom half of diamond.
    glColor3f(1, 1, 0);

    // facing xpos?
    glNormal3f(1, 1, -0.5);

    glTexCoord2f(0.5, 0);   glVertex3f(0, 0, 10); 
    glTexCoord2f(0, 1);     glVertex3f(0, 4, 15);
    glTexCoord2f(1, 1);     glVertex3f(4, 0, 15);

    // facing xneg?
    glNormal3f(1, -1, -0.5);

    glTexCoord2f(0.5, 0);   glVertex3f(0, 0, 10); 
    glTexCoord2f(0, 1);     glVertex3f(4, 0, 15);
    glTexCoord2f(1, 1);     glVertex3f(0, -4, 15);

    // facing ypos?
    glNormal3f(-1, -1, -0.5);

    glTexCoord2f(0.5, 0);   glVertex3f(0, 0, 10); 
    glTexCoord2f(0, 1);     glVertex3f(0, -4, 15);
    glTexCoord2f(1, 1);     glVertex3f(-4, 0, 15);

    // facing yneg?
    glNormal3f(-1, 1, -0.5);

    glTexCoord2f(0.5, 0);   glVertex3f(0, 0, 10); 
    glTexCoord2f(0, 1);     glVertex3f(-4, 0, 15);
    glTexCoord2f(1, 1);     glVertex3f(0, 4, 15);


    // this will be the top half of the diamond
    // facing xpos?
    glNormal3f(1, 1, 0.5);

    glTexCoord2f(0.5, 1);   glVertex3f(0, 0, 20); 
    glTexCoord2f(1, 0);     glVertex3f(4, 0, 15);
    glTexCoord2f(0, 0);     glVertex3f(0, 4, 15);

    // facing xneg?
    glNormal3f(1, -1, 0.5);

    glTexCoord2f(0.5, 1);   glVertex3f(0, 0, 20); 
    glTexCoord2f(1, 0);     glVertex3f(0, -4, 15);
    glTexCoord2f(0, 0);     glVertex3f(4, 0, 15);

    // facing ypos?
    glNormal3f(-1, -1, 0.5);

    glTexCoord2f(0.5, 1);   glVertex3f(0, 0, 20); 
    glTexCoord2f(1, 0);     glVertex3f(-4, 0, 15);
    glTexCoord2f(0, 0);     glVertex3f(0, -4, 15);

    // facing yneg?
    glNormal3f(-1, 1, 0.5);

    glTexCoord2f(0.5, 1);   glVertex3f(0, 0, 20); 
    glTexCoord2f(1, 0);     glVertex3f(0, 4, 15);
    glTexCoord2f(0, 0);     glVertex3f(-4, 0, 15);

    glEnd();



}
