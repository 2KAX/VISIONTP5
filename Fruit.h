#pragma once

enum Etat { DEHORS, DEDANS, SUPPRIMER };

class Fruit {
private :
	float x, y, z; // Position du fruit dans le repère du marqueur qui lance
	float v_x, v_y, v_z; // Vitesse du fruit dans le repère du marqueur qui lance
	Etat etat; // Etat du fruit
	float size; // Taille d_un fruit
	const float dt = 1 / 60; // Durée pour l'intégration des positions et vitesses entre deux frames
public :
	Fruit();
	Fruit(float size);
	Etat update(double modelview_matrix_canon[16], double modelview_matrix_recipient[16]); // Mise à jour des coordonées et de l'état entre deux frames et renvoie l'état du fruit
	void draw(double modelview_matrix_canon[16]); // Dessin du fruit sur le QR code
};