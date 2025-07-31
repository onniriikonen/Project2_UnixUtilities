#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            printf("my-cat: cannot open file\n");
            return 1;
        }

        char line[4096];
        while (fgets(line, sizeof(line), file) != NULL)
        {
            printf("%s", line);
        }

        fclose(file);
    }

    return 0;
}
