#include "bmp.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include "check.h"
#include "open_close_file.h"
#include "from_bmp.h"
#include "to_bmp.h"
#define TYPE_BMP 19778 // сигнатура формата




struct __attribute__((packed)) bmp_header {
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

static struct bmp_header creat_new_bmp( size_t width, size_t height) {
    return (struct bmp_header) {
            .bfType = TYPE_BMP,
            .bfileSize =(width*height*sizeof(struct pixel)),
            .bfReserved = 0,
            .bOffBits = sizeof(struct bmp_header),
            .biSize = 40,
            .biWidth = width,
            .biHeight = height,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biSizeImage = 0,
            .biXPelsPerMeter = 3780,
            .biYPelsPerMeter = 3780,
            .biClrUsed = 0,
            .biClrImportant = 0
    };
}

static uint32_t pad(const size_t weight) {
    if (((weight * 3) % 4) != 0 ) return (4 - ((weight * 3) % 4));
    return 0;
}


static enum status_read_header read_header( FILE* f, struct bmp_header* header ) {
    if (!fread(header, sizeof(struct bmp_header), 1, f)) {
        fclose(f);
        return READ_ERROR;
    }
    if (header->bfType != 19778) {
        fclose(f);
        return READ_INVALID_HEADER_SIGNATURE;
    }
    if (header->bOffBits != header->biSize + 14) {
        fclose(f);
        return READ_INVALID_BITS;
    }
    return READ_HEADER_OK;
}
void read_image_from_file( const char* filename, struct image* img ) {
    FILE* file = NULL;
    check_open_file(open_file(&file, filename, "rb"));
    struct bmp_header header = {0};
    check_read_header(read_header(file,&header));
    img->width = header.biWidth;
    img->height = header.biHeight;
    check_from_bmp(from_bmp(file, img, pad(img->width)));
    check_close_file(close_file(&file));
}

static enum status_write_header write_header(FILE* new_file, struct bmp_header* header) {
    if (!fwrite(header, sizeof(struct bmp_header), 1, new_file)) return WRITE_ERROR;
    return WRITE_OK;
}

void write_image_in_file(struct image* new_img) {
    FILE* new_file = NULL;
    check_open_file(open_file(&new_file, "new_lol.bmp", "wb"));
    const uint32_t padding = pad(new_img->width);
    struct bmp_header new_header = creat_new_bmp(new_img->width, new_img->height);
    check_write_header(write_header(new_file, &new_header));
    check_to_bmp(to_bmp(new_file, new_img, padding));
    check_close_file(close_file(&new_file));


}




