#include "../include/nh2.h"

int
main()
{
        FileBuffer file;
        int n;
        file = load_file("hello.c");
        if (!is_valid_fileBuffer(file))
        {
                perror("Cant load file");
                exit(1);
        }
        n = save_file(file);
        printf("%d bytes saved\n", n);
        close_file(&file);
}
