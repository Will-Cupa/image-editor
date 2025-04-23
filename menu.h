#ifndef _MENU_H_
#define _MENU_H_
#include "image.h"
#include <iostream>
#include <vector>
using namespace std;

// liste des fonctions implementees
const vector<string> FONCTIONS = {"Composante Rouge",
                                  "Niveau De Gris",
                                  "Deuteranopie (experimental)",
                                  "Protanopie (experimental)",
                                  "Tritanopie (experimental)",
                                  "Noir Et Blanc",
                                  "Augmenter Luminosite",
                                  "Diminuer Luminosite",
                                  "Augmenter Contraste",
                                  "Diminuer Contraste",
                                  "Rogner",
                                  "Rotation",
                                  "Retournement",
                                  "Agrandissement",
                                  "Retrecissement",
                                  "Flou (Filtre)",
                                  "Flou Gaussien (Filtre)",
                                  "Gradient",
                                  "Contour Sobel",
                                  "Detection des bords",
                                  "Contraste (Filtre)",
                                  "Reglage auto",
                                  "ascii",
                                  "Annuler derniere modification"};

// Demande a l'utilisateur de saisir le nom du fichier a editer
// retourne le nom saisie par l'utilisateur
string saisirFichier();

// Affiche les fonctionnalites disponibles
void listeFonction();

// Demande a l'utilisateur de saisir un entier
// retourne cet entier (qui sera utilise pour choisir une fonctionnalite)
int choixFonction();

// Demande a l'utilisateur de saisir un facteur
// necessaire pour certaines fonctionnalites
// et retourne ce facteur
float saisirFacteur();

// Demande � l'utilisateur de saisir une direction parmi haut, bas, gauche,
// droite sous la forme 'h','b','g','d' et retourne le caractere saisi
char saisirDirectionFull();

// Demande � l'utilisateur de saisir une direction parmi gauche ou droite
// sous la forme 'g','d'
// et retourne le caractere saisi
char saisirDirectionGD();

// Demande � l'utilisateur de saisir une direction parmi haut ou bas
// sous la forme 'h','b'
// et retourne le caractere saisi
char saisirDirectionHB();

// Demande � l'utilisateur de saisir un sens (vertical ou horizontal)
// sous la forme 'h','v'
// et retourne le caractere saisi
char saisirSens();

// Cr�e une copie de l'image "Image"
// et y applique la fonction num�ro "choix"
// Puis l'ajoute au vecteur "histor" et la retourne
Image appliquerFonction(Image &image, int choix, vector<Image> &histor);

// Utilise les fonctions pr�c�dentes
// pour afficher un menu fonctionnel
void menu();
#endif
