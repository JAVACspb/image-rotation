

#ifndef LAB_1_CHECK_H
#define LAB_1_CHECK_H
#include "util.h"
#include "from_bmp.h"
#include <stdbool.h>
void check_arg(int arg);

void check_read_header(enum status_read_header);

void check_write_header(enum status_write_header);

void check_open_file(enum status_open statusOpen);

void check_from_bmp(enum status_deserializer statusDeserializer);

void check_to_bmp(enum write_status statusSerializer);

void check_close_file(enum status_close statusClose);
#endif //LAB_1_CHECK_H
