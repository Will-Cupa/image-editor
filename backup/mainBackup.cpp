#include <iostream>
#include <stdlib.h>
#include "image.h"

using namespace std;

int main()
{
    //Speed up displays
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string fileName = "img";

    Image img(fileName);

    vector<vector<char>> ascii;

    ascii = img.ToAscii();



    while(true){
        for(int i=0; i < ascii.size(); i++){
            for(int j=0; j < ascii[0].size();j++){
                cout << ascii[i][j];
            }
            cout << "\n";
        }
        system("cls");
    }

    return 0;
}
