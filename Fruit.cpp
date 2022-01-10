#include "Fruit.h"
#include <GL/gl.h>

Fruit::Fruit(float _size)
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	v_x = 0.0f;
	v_y = 0.0f;
	v_z = 0.0f;
	etat = DEHORS;
	size = _size;
}

Etat Fruit::update(double modelview_matrix_canon[16], double modelview_matrix_recipient[16])
{
	// update des vitesses et positions
	v_y = v_y - 1.62 * dt; // pesanteur de la lune
	x = x + v_x * dt;
	y = y + v_y * dt;
	z = z + v_z * dt;

	// update de l'état
	if (y < -1000 * size) { etat = SUPPRIMER; }

	return etat;
}

void Fruit::draw(double modelview_matrix_canon[16])
{
	static const GLfloat n[6][3] =
	{
	  {-1.0, 0.0, 0.0},
	  {0.0, 1.0, 0.0},
	  {1.0, 0.0, 0.0},
	  {0.0, -1.0, 0.0},
	  {0.0, 0.0, 1.0},
	  {0.0, 0.0, -1.0}
	};
	static const GLint faces[6][4] =
	{
	  {0, 1, 2, 3},
	  {3, 2, 6, 7},
	  {7, 6, 5, 4},
	  {4, 5, 1, 0},
	  {5, 6, 2, 1},
	  {7, 4, 0, 3}
	};
	GLfloat v[8][3];
	GLint i;

	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

	for (i = 5; i >= 0; i--) {
		glBegin(type);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glColor4f(1.0f,1.0f,0.0f,0.4f);
		glEnd();
	}
}
