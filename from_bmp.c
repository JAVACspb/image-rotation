
#include <mm_malloc.h>
#include "from_bmp.h"
#include "bmp.h"


enum status_deserializer from_bmp(FILE* in, struct image * img, uint32_t padding){

    img->data = malloc(sizeof(struct pixel) * img->width * img->height);

    for (uint32_t i = 0; i < img->height; i++) {
        if (!fread(&(img->data[i * img->width]), sizeof(struct pixel), img->width, in)){
            free(img->data);
            return DESERIALIZER_INVALID_READING;
        }
        fseek(in, padding, SEEK_CUR);
    }
    return DESERIALIZER_OK;
}
