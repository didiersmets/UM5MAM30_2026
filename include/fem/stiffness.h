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
	double ABAB = norm2(AB);
	double ACAC = norm2(AC);
	double ABAC = dot(AB, AC);
	double BCBC = ABAB + ACAC - 2*dot(AB,AC);
	double Aire4 = 2 * sqrt(ABAB * ACAC - ABAC * ABAC);

	S[0] = BCBC / Aire4;           // S_00
	S[1] = ACAC / Aire4;           // S_11
	S[2] = ABAB / Aire4;           // S_22
	S[3] = (ABAC - ACAC) / Aire4;  // S_01
	S[4] = -ABAC / Aire4;          // S_12
	S[5] = (ABAC - ABAB) / Aire4;  // S_20
}
