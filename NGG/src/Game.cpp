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
            printf("Gissa nummer mellan (1 till 100) Du har 10 Försök: ");
            scanf_s("%d", &Gissning);
            if (Number < Gissning) {
                puts("Numret är lägre");
                counter--;
            }
            else if (Number > Gissning) {
                puts("Numret är högre");
                counter--;
            }

            
                
            // sätter in i fil
            
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
            cout << "Ditt förra försök var: " << text << "\n";
        }
        openFile.close();
        
       
        if (Number != Gissning)
        {
            puts("Försöken tog slut");
        }

        if (Number == Gissning) {
            puts("Grattis");
        }

        cin.get();

 
}


