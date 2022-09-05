#include <cstlib>
#include <random>
#include <iostream>
#include <time.h>
using namespace std;
float Temp1;                    // temporary variable
float Temp2;                    // temporary variable
int Last = 0;                   // temporary variable that stores last List[index]
int Last2 = 0;                  // temporary variable that stores last List[index]
int Ind1 = 0;                   // Index 1
int Ind2 = 0;                   // Index 2
int N = 5;                      // Number of trees
long simpleDist[N];             // List of the inital N Distances between neighbouring Trees
int Circ = N*(N-1)+1;           // Circumference of the circle
long complexDist[N*(N-1)];      // List of all the Distances between all Trees
int tries                       // tracks numbers of tries
bool Success = true;

distGenerator();                                    //generates a pseudo-random list of N single digits,
                                                    //which is stored in the list "simpleDist"
void distGenerator(){
    std::random_device rd;                          // obtain a random number from hardware
    std::mt19937 gen(rd());                         // seed the generator
    std::uniform_int_distribution<> distr(2, 10);   // define range
    for(ind1=1,simpleDist[0]=1;ind1<N;ind1++;){
        simpleDist[ind1] = distr(gen);              // generate numbers
    }
    listGenerator();
}

void listGenerator(){                                                       // creates a list of all possible distances between all tress and
                                                                            // writes it into the list "complexDist"
                                                                            // the order of the list is irrelevant

    for(Ind1=0; Ind1<N; Ind1++;){
        Ind2 = 1;
        for(complexDist[0]=simpleDist[1]+simpleDist[2];Ind2<N;Ind2++;){
            complexDist[Last+1]=complexDist[Last]+simpleDist[Last2];
            Last ++;
        }
    } 
    for(Ind2=0;Ind2<N;i++){         
        complexDist[Last+1]=simpleDist[Ind2];    
        Last++;
    }
    listChecker();
}
void listChecker(){                                                         // checks the list for duplicate distances, if it finds duplictaes
                                                                            // it goes back to the digit Generator at the beginning,
                                                                            // if it doesn't, the task is done.
    for (Ind1 = 0; Ind1<=Last; Ind1++;){
        for (Ind2=Ind1+1;Ind2<=Last; Ind2++){
            if(complexDist[Ind2]==complexDist[Ind1]){
                tries++;
                Success = false
                Ind2=Last+1;
                listGenerator();
            }
        }
        
    }
    if (Success==true;){
            cout<<"Success!! It took"+ String()"tries"+"tries to get this result:"
            cout<<String()"simpleDist"
        }
}