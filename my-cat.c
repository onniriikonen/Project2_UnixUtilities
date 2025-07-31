#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Ei annettuja tiedostoja
    if (argc == 1)
    {
        return 0;
    }

    // Käy läpi kaikki tiedostot
    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            // Virhe
            printf("my-cat: cannot open file\n");
            return 1;
        }

        // Tulosta tiedoston sisältö
        char line[4096];
        while (fgets(line, sizeof(line), file) != NULL)
        {
            printf("%s", line);
        }

        fclose(file);
    }

    return 0;
}
