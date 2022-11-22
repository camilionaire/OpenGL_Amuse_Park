#pragma once
#ifndef _ROOF_H_
#define _ROOF_H_

#include <Fl/gl.h>


// copied this from Cube.h and then just changed names.

class Roof {

  private:
      // don't think i need this one.
    GLubyte display_list;   // The display list that does all the work.
    GLuint  texture_obj;    // The object for the grass texture.
    bool    initialized;    // Whether or not we have been initialised.
    int     x, y, z;



public:

    // will be the constructor eventually
    Roof(void);
    // put in location of center in xyz
    Roof(int [3]);

    // destructor
    ~Roof(void);

    // basic functions that I think I will need
    bool    Initialize(void);	// Gets everything set up for drawing.
//    void    Update(void);	// Updates the location of the train
    void    Draw(void);		// Draws everything.

    void    DrawRoof(void); // Draws the actual cube I guess...
};

#endif // !_ROOF_H_


