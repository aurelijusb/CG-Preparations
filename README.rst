Just preparations
=================

Notes, while prepairing for Computer graphics exam:
 * Transformations written inverse until draw or push matrix 
    glMatrixMode(GL MODELVIEW);
    glLoadIdentity();           // M := I
    glTranslatef(x,y,z);        // M := M × T
    glRotatef(a,x,y,z);         // M := M × R
    drawObject();               // C' = M × C

 * If matrix pushed, corrdinate system according last transformation
    glLoadIdentity();                       I
    glPushMatrix();                       I I
    glTranslatef(1.0, 0.0, 0.0);          T I
    glPushMatrix();                     T T I
    glRotatef(10.0, 0.0, 1.0, 0.0);    TR T I
    glPopMatrix();                        T I
    glPushMatrix();                     T T I
    
Reference
---------
 * Peter Grogono "Getting Started with OpenGL". Concordia University, 2003.

