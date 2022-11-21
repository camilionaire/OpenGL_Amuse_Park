#ifndef _CUBE_H_
#define _CUBE_H_

#include <Fl/gl.h>


class Cube {




public:

    // will be the constructor eventually
    Cube(void);
    // destructor
    ~Cube(void);

    // basic functions that I think I will need
    bool    Initialize(void);	// Gets everything set up for drawing.
    void    Update(float);	// Updates the location of the train
    void    Draw(void);		// Draws everything.
};

#endif // !_CUBE_H_



