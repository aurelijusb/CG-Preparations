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

 * Composite transformation: translate(rotate(scale()))
    / x'\   / s_x*cos(r)  -s_x*sin(r)  t_x \   / x \
    | y'| = | s_x*sin(r)   s_y*cos(r)  t_y | x | y |
    \ 1 /   \     0             0       1  /   \ 1 /

 * Rotation about axies
  * About X axis
    /  1   0    0   0 \
    |  0  cos  sin  0 |
    |  0 -sin  cos  0 |
    \  0   0    0   1 /
  * About Y axis
    / cos     -sin  0 \
    |  0   1    0   0 |
    | sin  0   cos  0 |
    \  0   0    0   1 /
  * About Z axis
    / cos sin   0   0 \
    |-sin cos   0   0 |
    |  0   0    1   0 |
    \  0   0    0   1 /
    
Reference
---------
 * Peter Grogono "Getting Started with OpenGL". Concordia University, 2003.
 * A. Lenkevičius, J. Matickas „KOMPIUTERINĖ GRAFIKA“. Technologija, Kaunas, 2004.
 * http://www.eecis.udel.edu/~chandra/640/Spring05/lecture4.ppt
