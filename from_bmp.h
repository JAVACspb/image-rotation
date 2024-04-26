
#ifndef LAB_1_FROM_BMP_H
#define LAB_1_FROM_BMP_H

#include <stdio.h>
#include "bmp.h"

enum status_deserializer{
    DESERIALIZER_OK,
    DESERIALIZER_INVALID_READING
};

enum status_deserializer from_bmp(FILE* n, struct image * img, uint32_t padding);

#endif //LAB_1_FROM_BMP_H
