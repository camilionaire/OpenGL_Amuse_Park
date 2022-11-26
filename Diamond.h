#ifndef _DIAMOND_H_
#define _DIAMOND_H_

#include <Fl/gl.h>

class Diamond {

  private:
      // don't think i need this one.
    GLubyte display_list;   // The display list that does all the work.
    GLuint  texture_obj;    // The object for the grass texture.
    bool    initialized;    // Whether or not we have been initialised.



public:

    // will be the constructor eventually
    Diamond(void);
    // destructor
    ~Diamond(void);

    // basic functions that I think I will need
    bool    Initialize(void);	// Gets everything set up for drawing.
//    void    Update(void);	// Updates the location of the train
    void    Draw(void);		// Draws everything.

    void    DrawDiamond(void); // Draws the actual cube I guess...
};

#endif // !_DIAMOND_H_

