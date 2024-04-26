#ifndef _BMP_H_
#define _BMP_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>



struct pixel {
    uint8_t b, g, r;
};

struct image {
    uint32_t width, height;
    struct pixel* data;
};

enum status_read_header {
    READ_HEADER_OK,
    READ_INVALID_HEADER_SIGNATURE,
    READ_INVALID_BITS,
    READ_ERROR
};

enum status_write_header {
    WRITE_OK,
    WRITE_ERROR
};

enum  write_status  {
    SERIALIZER_OK,
    SERIALIZER_ERROR
};

enum status_open {
    OPEN_OK = 0,
    OPEN_ERROR = 1
};

enum status_close {
    CLOSE_OK = 0,
    CLOSE_ERROR = 1
};


void read_image_from_file( const char* filename , struct image* img);
void write_image_in_file(struct image* new_img);

#endif
