
#include "open_close_file.h"

/*  функция открытия файла  */
enum status_open open_file(FILE **file, const char* file_name, const char* mode) {
    *file = fopen(file_name, mode);
    if (*file) return OPEN_OK;
    return OPEN_ERROR;
}

/* функция закрытия файла */
enum status_close close_file(FILE **files){
    if (fclose(*files) == 0) return CLOSE_OK;
    return CLOSE_ERROR;
}

