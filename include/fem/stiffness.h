#pragma once

#include "vec3.h"

/* Given a triangle ABC, computes the (symmetric) 3x3 stiffness matrix S s.t.
 *
 *   S_{ij} := \int_{ABC} \nabla \phi_i \cdot \nabla \phi_j
 *
 * where \phi_0 := \phi_A, \phi_1 := \phi_B, \phi_2 := \phi_C
 * are the shape functions of the P1 Lagrange element associated
 * to ABC.
 *
 * Input : the vectors AB and AC.
 * Output: the six coefficients S_{00} S_{11} S_{22} S_{01} S_{12} S_{20},
 *         corresponding to the interactions A<->A, B<->B, C<->C, A<->B, B<->C,
 *         C<->A
 *
 * Idea behind computation :
 * -------------------------
 *
 * Hiden for now.
 *
 */
void inline stiffness(const Vec3d &AB, const Vec3d &AC, double *__restrict S)
{
	/* Your implementation goes here */

	// Evaluation of vector BC
	const Vec3d BC = AC - AB;

	// Evaluation of sinus and cosinus of angles a, b, c
	const double cos_a = dot(AB, AC) / (norm(AB) * norm(AC));
	const double sin_a = sqrt(1.0 - cos_a * cos_a);

	const double cos_b = -dot(AB, BC) / (norm(AB) * norm(BC));
	const double sin_b = sqrt(1.0 - cos_b * cos_b);

	const double cos_c = dot(AC, BC) / (norm(AC) * norm(BC));
	const double sin_c = sqrt(1.0 - cos_c * cos_c);

	// Implementation of stiffness matrix coefficients

	S[0] = sin_a / (2.0 * sin_b * sin_c);
	S[1] = sin_b / (2.0 * sin_a * sin_c);
	S[2] = sin_c / (2.0 * sin_a * sin_b);

	S[3] = -0.5 * cos_c / sin_c;
	S[4] = -0.5 * cos_a / sin_a;
	S[5] = -0.5 * cos_b / sin_b;

	return;
}
