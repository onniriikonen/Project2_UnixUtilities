#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 8192

void search_in_file(FILE *input, const char *searchterm)
{
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, input) != -1)
    {
        if (strstr(line, searchterm) != NULL)
        {
            printf("%s", line);
        }
    }
    free(line);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("my-grep: searchterm [file ...]\n");
        return 1;
    }

    const char *searchterm = argv[1];

    if (argc == 2)
    {
        search_in_file(stdin, searchterm);
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL)
            {
                printf("my-grep: cannot open file\n");
                return 1;
            }
            search_in_file(file, searchterm);
            fclose(file);
        }
    }

    return 0;
}
