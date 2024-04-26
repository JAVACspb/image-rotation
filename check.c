
#include "util.h"
#include "from_bmp.h"
#include "inttypes.h"
#include <stdbool.h>
#include <stdio.h>
#include "open_close_file.h"
#include "bmp.h"
#include "to_bmp.h"
#include "check.h"

void usage() {
    fprintf(stderr, "Usage: ./print_header BMP_FILE_NAME\n");
}

void check_arg(int argc) {
    if (argc != 2) usage();
    if (argc < 2) err("Not enough arguments \n");
    if (argc > 2) err("Too many arguments \n");
}

static const char* const messegeReadHeader[] = {
        [READ_HEADER_OK] = "INFO: Чтение заголовка прошло успешно!\n",
        [READ_INVALID_HEADER_SIGNATURE] = "Ошибка сигнатуры заголовка\n",
        [READ_INVALID_BITS] = "Ошибка байтов\n",
        [READ_ERROR] = "Ошибка чтения заголовка\n"
};

void check_read_header(enum status_read_header statusReadHeader) {
    if (statusReadHeader != READ_HEADER_OK) err(messegeReadHeader[statusReadHeader]);
    fprintf(stdout, "%s", messegeReadHeader[statusReadHeader]);
}

void check_write_header(enum status_write_header statusWriteHeader) {
    if (statusWriteHeader != WRITE_OK) err("Ошибка записи заголовка");
    fprintf(stdout, "INFO: Заголовок записан успешно\n");
}
void check_open_file(enum status_open statusOpen) {
    if (statusOpen == OPEN_ERROR) err("Ошибка открытия файла\n");
    fprintf(stdout, "INFO: Файл открыт успешно\n");

}

void check_from_bmp(enum status_deserializer statusDeserializer){
    if (statusDeserializer != DESERIALIZER_OK) err("Ошибка дессириализации\n");
    fprintf(stdout,"INFO: Дессериализация прошла успешно\n");
}

void check_to_bmp(enum write_status statusSerializer) {
    if (statusSerializer == SERIALIZER_ERROR) err("Ошибка сериализации\n");
    fprintf(stdout, "INFO: Сериализация прошла успешно\n");
}

void check_close_file(enum status_close statusClose) {
    if (statusClose == CLOSE_ERROR) err("Ошибка закрытия файла\n");
    fprintf(stdout, "INFO: Файл закрыт успешно\n");
}

//------------------------------





