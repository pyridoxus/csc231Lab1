/*********************************************
Lab 1

Description
-----------
Draws points from file

Instructions
------------
- Open and read a file containing point positions
- Each line in the file contains the x,y,z position for 1 point
- Assume no more than 100 points in the file
- Store the points, close the file
- Draw all the points (as in example below)
- Use point files, Point file 1 (pointList.dat), Point file 2 (pointList2.dat)
*********************************************/

#include <iostream>
using namespace std;
#include "lab1.h"
#include <fstream>

void myInit();
void myDraw();

int main( int argc, char *argv[] )
{
  // Open file (NOTE: Use \\ to separate folder names in filename)
  fstream in;

  in.open( "pointList2.dat", ios::in );
  if(in.fail())
  {
  	cout << "Cannot open file." << endl;
  	return 1;
  }

	// Read and store the points here
  g_numPoints = 0;
  while(!in.eof())
  {
  	in >> g_points[g_numPoints].x;
  	in >> g_points[g_numPoints].y;
  	in >> g_points[g_numPoints].z;
    g_numPoints++;
  	if(g_numPoints >= 100) break;
  }
  // Close the file here
  in.close();
  // Initialize window system
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  glutInitWindowSize( 640, 480 );
  glutCreateWindow( "Lab 1" );

  // Initialize graphics
  myInit();

  // Display callback and enter event loop
  glutDisplayFunc( myDraw );
  glutMainLoop();
  return 0;
}

void myInit()
{
  // Background color
  glClearColor(0.0, 0.0, 0.0, 0.0);

  // Projection
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( -2.0, 2.0, -2.0, 2.0, -2.0, 2.0 );
}

void myDraw()
{
  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT );

  // Example code to draw 4 white points
  // Draw your points here
  glColor3f( 1.0, 1.0, 1.0 );
  glBegin( GL_POINTS );
//  glVertex3f( -0.25, -0.25, 0.0 );
//  glVertex3f( 0.25, -0.25, 0.0 );
//  glVertex3f( 0.25, 0.25, 0.0 );
//  glVertex3f( -0.25, 0.25, 0.0 );

  for(int i = 0; i < g_numPoints; i++)
  {
    glVertex3f( g_points[i].x, g_points[i].y, g_points[i].z);
  }
  glEnd();

  // Execute draw commands
  glFlush();
}


