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
	double AIRE = aire(AB, AC);
	M[0] = AIRE/12.;
	M[1] = AIRE/24.;

}

/*

AIRE = (AB ^ AC)/2
M_ii = AIRE/12
M_ij = AIRE/24



*/
