#pragma once

#include "vec3.h"

/* Given a triangle ABC, computes the (symmetric) 3x3 mass M s.t.
 *
 *   M_{ij} := \int_{ABC} \phi_i \phi_j
 *
 * where \phi_0 := \phi_A, \phi_1 := \phi_B, \phi_2 := \phi_C
 * are the shape functions of the P1 Lagrange element associated
 * to ABC.
 *
 * Idea behind computation :
 * -------------------------
 *
 * Hiden for now.
 */
void inline mass(const Vec3d &AB, const Vec3d &AC, double *__restrict M)
{
	/* Your implementation goes here ! */
	double area = 0.5 * norm(cross(AB, AC)); // Evaluation of the area of the triangle ABC

	double coeff = area / 12.0; // Reference coefficient

	M[0] = coeff * 2.0; // Diagonal term
	M[1] = coeff * 1.0; // Extra-diagonal term

	return;
}