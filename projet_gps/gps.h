#ifndef GPS_H
#define GPS_H

typedef struct {
    double latitude;
    double longitude;
    char indLat;
    char indLon;
    int heures;
    int minutes;
    int secondes;
} DonneesGPS;

int verifierTrame(char *trame);
int extraireChamps(char *trame, DonneesGPS *donnees);
double convertirCoordonnee(double valeur);
int formaterHeure(char *heure, DonneesGPS *donnees);

#endif
