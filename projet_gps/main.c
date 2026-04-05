#include <stdio.h>
#include <string.h>
#include "gps.h"
#include "affichage.h"

void sauvegarder(DonneesGPS *donnees)
{
    FILE *f;

    f = fopen("resultat.txt", "w");
    if (f == NULL)
    {
        printf("Erreur ouverture fichier\n");
        return;
    }

    fprintf(f, "Heure UTC : %02dh%02dm%02ds\n", donnees->heures, donnees->minutes, donnees->secondes);
    fprintf(f, "Latitude  : %f %c\n", donnees->latitude, donnees->indLat);
    fprintf(f, "Longitude : %f %c\n", donnees->longitude, donnees->indLon);

    fclose(f);
    printf("Resultat sauvegarde dans resultat.txt\n");
}

int main()
{
    char trame[256];
    DonneesGPS donnees;
    int len;

    printf("=== Analyseur de trames GPS ===\n");
    printf("Entrez une trame GPGGA : ");

    fgets(trame, 256, stdin);

    len = strlen(trame);
    if (trame[len - 1] == '\n')
        trame[len - 1] = '\0';

    if (verifierTrame(trame) != 0)
    {
        printf("Erreur : trame invalide !\n");
        return -1;
    }

    if (extraireChamps(trame, &donnees) != 0)
    {
        printf("Erreur : extraction impossible !\n");
        return -1;
    }

    afficherTout(&donnees);

    sauvegarder(&donnees);

    return 0;
}
