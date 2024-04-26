
#ifndef LAB_1_OPEN_CLOSE_FILE_H
#define LAB_1_OPEN_CLOSE_FILE_H
#include "bmp.h"
#include <stdio.h>

/* методы открытия и закрытия файла */
enum status_open open_file(FILE **file, const char* file_name, const char* mode);

enum status_close close_file(FILE **file);

#endif //LAB_1_OPEN_CLOSE_FILE_H
