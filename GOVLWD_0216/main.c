#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp= fopen("bodnarmate.txt", "w");
    fprintf(fp,"Nev:Bodnar Mate Laszlo Szak:Mernokinformatikus Neptunkod:GOVLWD");
    fclose(fp);

    FILE *fp2;

    char sor[100];
    fp2= fopen("bodnarmate.txt", "r");
    fgets(sor, 100, fp);
    fgets(sor, 100, fp);
    printf("%s", sor);
    fclose(fp2);


    return 0;
}
