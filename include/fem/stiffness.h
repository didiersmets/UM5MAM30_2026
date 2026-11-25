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
	double areaABC = 1/2 * norm(cross(AB, AC));
	S[0] = pow(norm2(-AB + AC),2) / (4 * areaABC);
	S[1] = pow(norm2(-AC),2) / (4 * areaABC);
	S[2] = pow(norm2(AB),2) / (4 * areaABC);
	S[3] = dot(-AC,(-AB + AC)) / (4 * areaABC);  //AB
	S[4] = dot(-AC, AB) / (4 * areaABC);         //BC
	S[5] = dot(AB,(-AB + AC)) / (4 * areaABC);   //AC

}
