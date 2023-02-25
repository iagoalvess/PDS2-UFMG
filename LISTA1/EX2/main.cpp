#include <iostream>
#include <string>

using namespace std;

int main() {
    int num; 
    cin >> num;

    char letras[num];

    for (int i = 0; i < num; i++){
        cin >> letras[i];
    }

    string frase;
    cin.ignore();
    getline (cin, frase);

    int contador[num];

    for (int i = 0; i < num; i++) {
        contador[i] = 0;
    }

    frase.length();

    for (int i = 0; i < frase.length(); i++){
        cin >> frase[i];
        
        for (int j = 0; j <= frase.length(); j++){
            if(frase[i] == letras[j]){
                frase[i] = '#';
                contador[j]++;
            }
        }
    } 

    cout << frase << endl;

    for (int i = 0; i < num; i++){
        cout << letras[i] << " " << contador[i] << endl;
    }

    return 0;
}