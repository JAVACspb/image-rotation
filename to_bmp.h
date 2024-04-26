
#ifndef LAB_1_TO_BMP_H
#define LAB_1_TO_BMP_H
#include "bmp.h"
#include <stdio.h>

enum write_status to_bmp( FILE* out, struct image const* img, uint32_t padding);
#endif //LAB_1_TO_BMP_H
