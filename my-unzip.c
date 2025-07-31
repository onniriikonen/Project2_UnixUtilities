#include <stdio.h>
#include <stdlib.h>

// Purkaa tiedoston ja tulostaa sisällön
void decompress_file(FILE *file)
{
    int count;
    char symbol;

    // Toistetaan merkki count kertaa
    while (fread(&count, sizeof(int), 1, file) == 1)
    {
        if (fread(&symbol, sizeof(char), 1, file) != 1)
        {
            break;
        }
        for (int i = 0; i < count; i++)
        {
            printf("%c", symbol);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        // Virheellinen kutsu
        printf("my-unzip: file1 [file2 ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            // Virhe
            printf("my-unzip: cannot open file\n");
            return 1;
        }
        decompress_file(file);
        fclose(file);
    }

    return 0;
}
