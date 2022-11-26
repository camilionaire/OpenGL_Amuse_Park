#ifndef _TREE_H
#define _TREE_H

#include <Fl/gl.h>
#include <GL/glu.h>

class Tree
{
private:
      // don't think i need this one.
    GLubyte display_list;   // The display list that does all the work.
//    GLuint  texture_obj;    // The object for the grass texture.
    bool    initialized;    // Whether or not we have been initialised.
    GLUquadric * quadric_obj;


public:
    // will be the constructor eventually
    Tree(void);
    // destructor
    ~Tree(void);

    // basic functions that I think I will need
    bool    Initialize(void);	// Gets everything set up for drawing.
//    void    Update(void);	// Updates the location of the train
    void    Draw(void);		// Draws everything.

    void    DrawTree(void); // Draws the actual cube I guess...

};

#endif // !_TREE_H
