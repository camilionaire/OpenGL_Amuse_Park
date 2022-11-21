#ifndef _CUBE_H_
#define _CUBE_H_

#include <Fl/gl.h>



class Cube {

  private:
      // don't think i need this one.
//    GLubyte display_list;   // The display list that does all the work.
    GLuint  texture_obj;    // The object for the grass texture.
    bool    initialized;    // Whether or not we have been initialised.



public:

    // will be the constructor eventually
    Cube(void);
    // destructor
    ~Cube(void);

    // basic functions that I think I will need
    bool    Initialize(void);	// Gets everything set up for drawing.
//    void    Update(void);	// Updates the location of the train
    void    Draw(void);		// Draws everything.
};

#endif // !_CUBE_H_



