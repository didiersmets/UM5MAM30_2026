#include "mesh.h"
#include "adjacency.h"

VTAdjacency::VTAdjacency(const Mesh &m)
{
	size_t v_count = m.vertex_count();
	size_t t_count = m.triangle_count();

	degree.resize(v_count);
	offset.resize(v_count);
	vtri.resize(3 * t_count);

	for (size_t i = 0; i < v_count; ++i)
		degree[i] = 0;

	for (size_t t = 0; t < t_count; ++t) {
		degree[m.indices[3 * t + 0]]++;
		degree[m.indices[3 * t + 1]]++;
		degree[m.indices[3 * t + 2]]++;
	}

	if (v_count > 0)
		offset[0] = 0;
	for (size_t k = 1; k < v_count; ++k)
		offset[k] = offset[k - 1] + degree[k - 1];

	TArray<uint32_t> pos;
	pos.resize(v_count);
	for (size_t k = 0; k < v_count; ++k)
		pos[k] = offset[k];

	for (size_t t = 0; t < t_count; ++t) {
		uint32_t a = m.indices[3 * t + 0];
		uint32_t b = m.indices[3 * t + 1];
		uint32_t c = m.indices[3 * t + 2];
		vtri[pos[a]++] = { b, c };
		vtri[pos[b]++] = { c, a };
		vtri[pos[c]++] = { a, b };
	}
}