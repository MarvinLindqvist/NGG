#include"include.h"
#include"Game.h"
#include<fstream>
#include <time.h> 

using namespace std;

void Game::Run() {
    
    
    int Number;
    int Gissning;
        srand(time(NULL));
        Number = rand() % 100+1 ;
       int counter = 10;

      
        do {
            printf("Gissa nummer mellan (1 till 100) Du har 10 F�rs�k: ");
            scanf_s("%d", &Gissning);
            if (Number < Gissning) {
                puts("Numret �r l�gre");
                counter--;
            }
            else if (Number > Gissning) {
                puts("Numret �r h�gre");
                counter--;
            }

            
                
            // s�tter in i fil
            
            ofstream File("Rekord.txt");
            File << counter << endl;
            File.close();
      
            // if
            if (Number == Gissning) {
                counter = 10;
            }

            if (counter == 0) {
                break;
            }

             
        } while (Number != Gissning);
        
        //skriver ut ur fil
        string text;
        ifstream openFile("Rekord.txt");
        while (getline(openFile, text))
        {
            cout << "Ditt f�rra f�rs�k var: " << text << "\n";
        }
        openFile.close();
        
       
        if (Number != Gissning)
        {
            puts("F�rs�ken tog slut");
        }

        if (Number == Gissning) {
            puts("Grattis");
        }

        cin.get();

 
}


