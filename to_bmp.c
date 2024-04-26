
#include "to_bmp.h"
#include "mm_malloc.h"

enum write_status to_bmp( FILE* out, struct image const* img, uint32_t padding){
    const char null_bits[3] = {0};
    for (uint32_t height = 0; height < img->height; ++height) {
        if (!fwrite(&img->data[height*img->width], sizeof(struct pixel), img->width, out)){
            free(img->data);
            return SERIALIZER_ERROR;
        }
        fwrite(null_bits, padding, 1, out);
    }
    return SERIALIZER_OK;
}
