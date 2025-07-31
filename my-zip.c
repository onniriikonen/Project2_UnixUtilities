#include <stdio.h>
#include <stdlib.h>

// Pakkaa tiedoston sisällön RLE-muotoon (toistomäärä + merkki)
void compress_file(FILE *input)
{
    int current = fgetc(input);
    if (current == EOF)
        return;

    int count = 1;
    int next;

    // Käy merkit läpi ja laskee peräkkäiset toistot
    while ((next = fgetc(input)) != EOF)
    {
        if (next == current)
        {
            count++;
        }
        else
        {
            // Kirjoita toistomäärä ja merkki
            fwrite(&count, sizeof(int), 1, stdout);
            fputc(current, stdout);
            current = next;
            count = 1;
        }
    }

    // Viimeinen
    fwrite(&count, sizeof(int), 1, stdout);
    fputc(current, stdout);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        // Virheellinen kutsu
        printf("my-zip: file1 [file2 ...]\n");
        return 1;
    }

    // Käy läpi tiedostot ja pakkaa ne
    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            // Virhe
            printf("my-zip: cannot open file\n");
            return 1;
        }
        compress_file(file);
        fclose(file);
    }

    return 0;
}
