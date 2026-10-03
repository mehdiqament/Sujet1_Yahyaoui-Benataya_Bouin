# Analyseur de trames GPS NMEA 🛰️

Programme en C qui analyse des trames GPS au format NMEA 0183 de type `GPGGA`. Il vérifie la validité de la trame, extrait la latitude, la longitude et l'heure, puis les affiche dans un format lisible. En bonus, les résultats sont sauvegardés dans un fichier texte.

Projet réalisé en binôme dans le cadre d'une SAÉ du BUT Informatique (IUT Paul Sabatier, Toulouse). Présentation et vidéo de démonstration sur la [page du projet](https://mehdiqament.dev/projets/gps-nmea.html).

## Auteurs

- Mohamed Yahyaoui Benataya
- Mehdi Bouin

## Compilation

```
make
```

## Utilisation

```
./projet_gps
```

Exemple de trame à entrer :

```
$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
```

## Fonctions principales

| Fonction | Rôle | Retour |
| --- | --- | --- |
| `verifierTrame(trame)` | Vérifie la validité de la trame | `0` si valide, `-1` sinon (trame `NULL`, mauvais préfixe, moins de 15 champs) |
| `extraireChamps(trame, donnees)` | Extrait les champs vers une structure `DonneesGPS` | `0` si OK, `-1` sinon (pointeur `NULL`, heure invalide) |
| `convertirCoordonnee(valeurBrute)` | Convertit une coordonnée NMEA en degrés décimaux (ex : `4807.038` → `48.117`) | Degrés décimaux |
| `formaterHeure(heureBrute, donnees)` | Décode une heure `HHMMSS` | `0` si OK, `-1` sinon (pointeur `NULL`, moins de 6 caractères, valeurs hors plage) |
| `afficherCoordonnees(donnees)` | Affiche les coordonnées au format `XX°YY'ZZ.ZZ''` | Affichage |
| `afficherHeure(donnees)` | Affiche l'heure au format `XXhYYmZZs` | Affichage |
