#include <stdio.h>
#include "affichage.h"

void afficherCoordonnees(DonneesGPS *donnees)
{
    int degLat, minLat;
    double secLat;
    int degLon, minLon;
    double secLon;

    if (donnees == NULL)
        return;

    degLat = (int)donnees->latitude;
    minLat = (int)((donnees->latitude - degLat) * 60);
    secLat = ((donnees->latitude - degLat) * 60 - minLat) * 60;

    degLon = (int)donnees->longitude;
    minLon = (int)((donnees->longitude - degLon) * 60);
    secLon = ((donnees->longitude - degLon) * 60 - minLon) * 60;

    printf("Latitude  : %d°%d'%.2f'' %c\n", degLat, minLat, secLat, donnees->indLat);
    printf("Longitude : %d°%d'%.2f'' %c\n", degLon, minLon, secLon, donnees->indLon);
}

void afficherHeure(DonneesGPS *donnees)
{
    if (donnees == NULL)
        return;

    printf("Heure UTC : %02dh%02dm%02ds\n", donnees->heures, donnees->minutes, donnees->secondes);
}

void afficherTout(DonneesGPS *donnees)
{
    if (donnees == NULL)
        return;

    printf("\n=== Donnees GPS ===\n");
    afficherHeure(donnees);
    afficherCoordonnees(donnees);
    printf("===================\n\n");
}
