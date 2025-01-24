#include "../include/nh2.h"
#include <assert.h>
#include <stdio.h>

#define MAX_LINE_LEN 2047

FileBuffer
load_file(const char *filename)
{
        /* Create a dynamic array o dynamic arrays of chars and
         * load all the contents of the file into it
         * The FileBuffer with this dynamic arrays is returned */
        FileBuffer file_buffer;
        da_char line_buffer;
        char line[MAX_LINE_LEN + 1];

        file_buffer.file = fopen(filename, "r");
        assert(file_buffer.file);
        da_init(&file_buffer.buffer);

        while (fgets(line, MAX_LINE_LEN, file_buffer.file))
        {
                da_init(&line_buffer);
                for (char *c = line; *c; ++c)
                        da_append(&line_buffer, *c);
                da_append(&file_buffer.buffer, line_buffer);
        }

        return file_buffer;
}

int
save_file(FileBuffer buf)
{
        int counter = 0;
        for_da_each(char_da_ptr, buf.buffer)
        {
                for_da_each(c, *char_da_ptr)
                {
                        putc(*c, buf.file);
                        ++counter;
                }
                putc('\n', buf.file);
                ++counter;
        }
        return counter;
}

void
close_file(FileBuffer *buf)
{
        for_da_each(char_da_ptr, buf->buffer)
        {
                da_destroy(char_da_ptr);
        }
        da_destroy(&buf->buffer);
        fclose(buf->file);
        memset(buf, 0, sizeof(FileBuffer));
}

int
is_valid_fileBuffer(FileBuffer buf)
{
        return buf.file != NULL;
}
