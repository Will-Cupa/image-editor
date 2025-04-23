#ifndef _IMAGE_H_INCLUDED
#define _IMAGE_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

const vector<char> SHADE = {' ','.',',','*','/','(','&','%','#'};
const int TERMINAL_WIDTH = 211;

class Image {
  vector<vector<int>> _rouge;
  vector<vector<int>> _bleu;
  vector<vector<int>> _vert;
  int _largeur;
  int _hauteur;

public:
  /// Constructeur

  // Constructeur a partir d'un fichier ppm
  Image(string &fichier);

  Image(int hauteur, int largeur);

  Image niveauGris() const;

  vector<vector<char>> ToAscii() const;

  Image retrecissement(int facteur) const;

  int getFacteur();
};

char valueToAscii(int val);

#endif // IMAGE_H_INCLUDED
