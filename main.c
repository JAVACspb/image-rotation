#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "from_bmp.h"
#include "to_bmp.h"
#include "open_close_file.h"
#include "rotate_picture.h"
#include "util.h"
#include "check.h"



int main( int argc, char** argv ) {
    check_arg(argc);

    struct image image = {0};

    read_image_from_file(argv[1], &image);

    struct image new_image = {0};

    /* поворот картинки */
    new_image = rotate(&image);


    write_image_in_file(&new_image);

    /* освобождение памяти */
    free(image.data);
    free(new_image.data);
    return 0;
}
