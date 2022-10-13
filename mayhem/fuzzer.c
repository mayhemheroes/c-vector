#define CVECTOR_LOGARITHMIC_GROWTH
#include "../cvector.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
        uint8_t** s_data = (uint8_t **) &data;
	cvector_vector_type(int) v = NULL;

	/* add some elements to the back */
	
	//cvector_push_back(v, s_data);
	cvector_push_back(v, 10);
	cvector_push_back(v, 20);
	cvector_push_back(v, 30);
	cvector_push_back(v, 40);
	

	/* remove an element by specifying an array subscript */
	cvector_erase(v, 2);

	/* remove an element from the back */
	cvector_pop_back(v);
	cvector_pop_back(v);
	cvector_pop_back(v);
	cvector_pop_back(v);
	//cvector_pop_back(v);
	//cvector_pop_back(v);
	

	/* print out some stats about the vector */
	printf("pointer : %p\n", (void *)v);
	printf("capacity: %lu\n", cvector_capacity(v));
	printf("size    : %lu\n", cvector_size(v));

	/* iterator over the vector using "iterator" style */
	if (v) {
		int *it;
		int i = 0;
		for (it = cvector_begin(v); it != cvector_end(v); ++it) {
			printf("v[%d] = %d\n", i, *it);
			++i;
		}
	}

	/* iterator over the vector standard indexing too! */
	if (v) {
		size_t i;
		for (i = 0; i < cvector_size(v); ++i) {
			printf("v[%lu] = %d\n", i, v[i]);
		}
	}

	/* well, we don't have destructors, so let's clean things up */
	cvector_free(v);

return 0;
}
