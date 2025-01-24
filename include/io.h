#ifndef IO_H
#define IO_H

#include "../include/da.h"
#include <stddef.h>
#include <stdio.h> // FILE

DA(char) da_char;
DA(da_char) da_str;

// ../src/io.c
typedef struct FileBuffer
{
        da_str buffer;
        FILE *file;
} FileBuffer;

/* Move the contents from a file to a FileBuffer */
FileBuffer load_file(const char *filename);
/* Update the content of a file from a FileBuffer */
int save_file(FileBuffer buf);
/* Close a FileBuffer. It can not be used later */
void close_file(FileBuffer *buf);
/* Return if a FileBuffer is valid */
int is_valid_fileBuffer(FileBuffer buf);

#endif
