#include "image.h"
#include "loadImage.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Image::Image(string& fichier) {
  loadImage(fichier, _rouge, _vert, _bleu);
  _hauteur = _rouge.size();
  _largeur = _rouge[0].size();
}

Image::Image(int hauteur, int largeur) {

  _hauteur = hauteur;
  _largeur = largeur;
  _rouge = vector<vector<int>>(_hauteur, vector<int>(_largeur, 0));
  _vert = vector<vector<int>>(_hauteur, vector<int>(_largeur, 0));
  _bleu = vector<vector<int>>(_hauteur, vector<int>(_largeur, 0));
}

Image Image::niveauGris() const {
  int avg;
  Image I = *this;
  for (int i = 0; i < _hauteur; i++) {
    for (int j = 0; j < _largeur; j++) {
      avg = (_rouge[i][j] + _vert[i][j] + _bleu[i][j]) / 3; // calcul de la moyenne
      I._rouge[i][j] = avg;
      I._vert[i][j] = avg;
      I._bleu[i][j] = avg;
    }
  }
  return I;
}


vector<vector<char>> Image::ToAscii() const {
  Image img = niveauGris();
  cout << img.getFacteur();
  img = img.retrecissement(img.getFacteur());

  vector<vector<char>> charImg = {};
  char px;

  for (int i = 0; i < img._hauteur; i++) {
    charImg.push_back({});
    for (int j = 0; j < img._largeur; j++) {
        px = valueToAscii(img._rouge[i][j]);

        charImg[i].push_back(px);
        charImg[i].push_back(px);
    }
  }
  return charImg;
}

Image Image::retrecissement(int facteur) const {
  Image I(_hauteur / facteur, _largeur / facteur);
  int moyr;
  int moyv;
  int moyb;
  for (int i = 0; i < _hauteur; i += facteur) {
    for (int j = 0; j < _largeur; j += facteur) {
      moyr = 0;
      moyv = 0;
      moyb = 0;
      for (int k = 0; k < facteur; k++) {
        for (int l = 0; l < facteur; l++) {
          if ((i + k) < _hauteur && (j + l) < _largeur) {
            moyr += _rouge[i + k][j + l];
            moyv += _vert[i + k][j + l];
            moyb += _bleu[i + k][j + l];
          }
        }
      }
      moyr = moyr / (facteur * facteur);
      moyv = moyv / (facteur * facteur);
      moyb = moyb / (facteur * facteur);
      if (i / facteur != I._hauteur && j / facteur != I._largeur) {
        I._rouge[i / facteur][j / facteur] = moyr;
        I._vert[i / facteur][j / facteur] = moyv;
        I._bleu[i / facteur][j / facteur] = moyb;
      }
    }
  }
  return I;
}

int Image::getFacteur(){
    return (_largeur/(TERMINAL_WIDTH/2))+1;
}

char valueToAscii(int val){
    for(int i = 0; i <= 256; i+=32){
        if (val <= i) {
            return SHADE[i/32];
        }
    }
    return SHADE[0];
}
