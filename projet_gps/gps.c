#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gps.h"

int verifierTrame(char *trame)
{
    int i;
    int nbVirgules = 0;

    if (trame == NULL)
        return -1;

    if (strncmp(trame, "$GPGGA", 6) != 0)
        return -1;

    for (i = 0; trame[i] != '\0'; i++)
    {
        if (trame[i] == ',')
            nbVirgules++;
    }

    if (nbVirgules < 14)
        return -1;

    return 0;
}

double convertirCoordonnee(double valeur)
{
    int degres;
    double minutes;
    double resultat;

    degres = (int)(valeur / 100);
    minutes = valeur - (degres * 100);
    resultat = degres + (minutes / 60.0);

    return resultat;
}

int formaterHeure(char *heure, DonneesGPS *donnees)
{
    char buf[3];

    if (heure == NULL || donnees == NULL)
        return -1;

    if (strlen(heure) < 6)
        return -1;

    buf[2] = '\0';

    buf[0] = heure[0];
    buf[1] = heure[1];
    donnees->heures = atoi(buf);

    buf[0] = heure[2];
    buf[1] = heure[3];
    donnees->minutes = atoi(buf);

    buf[0] = heure[4];
    buf[1] = heure[5];
    donnees->secondes = atoi(buf);

    if (donnees->heures > 23 || donnees->minutes > 59 || donnees->secondes > 59)
        return -1;

    return 0;
}

int extraireChamps(char *trame, DonneesGPS *donnees)
{
    char copie[256];
    char *champ;
    int index;
    double latBrute;
    double lonBrute;
    char heureBrute[16];

    if (trame == NULL || donnees == NULL)
        return -1;

    strcpy(copie, trame);

    latBrute = 0.0;
    lonBrute = 0.0;
    index = 0;

    champ = strtok(copie, ",");

    while (champ != NULL)
    {
        if (index == 1)
            strcpy(heureBrute, champ);

        if (index == 2)
            latBrute = atof(champ);

        if (index == 3)
            donnees->indLat = champ[0];

        if (index == 4)
            lonBrute = atof(champ);

        if (index == 5)
            donnees->indLon = champ[0];

        index++;
        champ = strtok(NULL, ",");
    }

    donnees->latitude = convertirCoordonnee(latBrute);
    donnees->longitude = convertirCoordonnee(lonBrute);

    if (formaterHeure(heureBrute, donnees) != 0)
        return -1;

    return 0;
}
