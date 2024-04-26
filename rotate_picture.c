
#include <mm_malloc.h>
#include "rotate_picture.h"
// тут будет один метод rotate
#include "bmp.h"
#include <stdio.h>

struct image creat_image(uint64_t height, uint64_t width) {
    return (struct image) {
            .height = width,
            .width = height,
            .data = malloc(sizeof(struct pixel) * height * width)
    };
}

struct image rotate(struct image const* picture) {
    struct image new_picture = creat_image(picture->height, picture->width);

    for (uint32_t height = 0; height < picture->height; ++height)
        for (uint32_t width = 0; width < picture->width; ++width)
            new_picture.data[(picture->height - 1 - height) + picture->height * width] = picture->data[picture->width * height + width];

    return new_picture;
}
