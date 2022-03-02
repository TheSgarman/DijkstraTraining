#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Math.h"
#include <string>
#include <algorithm>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

#define E 11

vector <string> cities{ "Berlin", "Paris", "London", "Vilnius", "Varsaw", "Vienne", "Rome", "Milan", "Sparte", "Moscou" };

int minDistance(int distance[], bool shortestPathFound[])
{

    //min
    int min = INT_MAX, min_index;

    for (int v = 0; v < E; v++)
        if (shortestPathFound[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}


void displayShortPathfromStart(int distance[])
{


    cout << "From: \t \t Shortest Travel Costs:" << endl;
    for (int i = 0; i < E; i++)
        cout << cities[i] << "\t \t " << distance[i] << endl;





}

void pathEvaluator(int graph[E][E], int startPointChosen)
{
    int distance[E];
    bool shortestPathFound[E];

    for (int i = 0; i < E; i++)
        distance[i] = INT_MAX, shortestPathFound[i] = false;

    distance[startPointChosen] = 0;

    for (int count = 0; count < E - 1; count++) {
        int u = minDistance(distance, shortestPathFound);
        shortestPathFound[u] = true;

        for (int v = 0; v < E; v++)

            if (!shortestPathFound[v] && graph[u][v] && distance[u] != INT_MAX
                && distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
    }

    displayShortPathfromStart(distance);
}



int main()
{
    string answer;
    string* aswr = &answer;
    int answerID;
    int* aswrID=&answerID;
    int startPointChosen;
    int* spc = &startPointChosen;
    bool inLoop = true;

    while (inLoop)
    {





        cities.push_back("Hidland");
        cout << "Where are you located? Berlin(0), Paris(1), London(2), Vilnius(3), Varsaw(4), Vienne(5), Rome(6), Milan(7), Sparte(8), Moscou(9)\n";


        cin >> *spc;


        if (*spc > 10)
        {
            int dataBaseSize = 100000;
            cities.push_back("an unknown city");
            cities.push_back("mysterious town");
            for (int c = 0; c < dataBaseSize; ++c) {
                cities.push_back("U?NKN0W011");
                if (*spc > dataBaseSize) {
                    cout << "ERROR: Program shutting down..." << endl;
                    sleep_for(seconds(2));
                    cout << "Process killed!" << endl;
                    sleep_for(seconds(1));
                    return 0;
                }
            }
            cout << "Your city is not in our data base..." << endl;
            sleep_for(seconds(1));
            cout << "You are in " << cities[*spc] << endl;
            cout << "ERROR: Program shutting down..." << endl;
            sleep_for(seconds(2));
            cout << "Process killed!" << endl;
            sleep_for(seconds(1));


            return 0;


        }


        if (std::find(cities.begin(), cities.end(), cities[*spc]) != cities.end())
        {
            cout << cities[*spc] << " is where you are... I'll get the cost of each road for you:\n";
            sleep_for(seconds(1));
        }

        cout << "Looking for path...\n" << endl;
        sleep_for(seconds(2));

        int inF = Maths::infinity;
                                //A  B  C  D  E  F  G  H  I  J              HL
        int graph[E][E] = { /*A*/{0, 4, 0, 0, 0, 0, 0, 0, 8, 5,            	inF },
                            /*B*/{4, 0, 5, 0, 0, 0, 0, 0, 6, 0,            	inF },
                            /*C*/{0, 0, 0, 6, 0, 0, 0, 0, 4, 0,            	inF },
                            /*D*/{0, 0, 0, 0, 4, 0, 0, 5, 0, 0,            	inF },
                            /*E*/{0, 0, 0, 0, 0, 0, 0, 3, 0, 0,            	inF },
                            /*F*/{0, 0, 0, 0, 2, 0, 3, 3, 0, 0,            	inF },
                            /*G*/{0, 0, 0, 0, 0, 2, 0, 0, 5, 4,            	inF },
                            /*H*/{0, 0, 0, 0, 0, 0, 2, 0, 3, 0,            	inF },
                            /*I*/{4, 0, 4, 0, 0, 0, 5, 0, 0, 3,            	inF },
                            /*J*/{7, 0, 0, 0, 0, 0, 3, 0, 0, 0,            	inF },
                            /*HL*/{inF, inF, inF, inF, inF, inF, inF, inF, inF, inF }


        };


        pathEvaluator(graph, *spc);





        cout << "\nType any number to restart, and 0 to quit " << endl;
        cin >> *aswrID;
        switch (*aswrID) {
        case 0:
            cout << "\n\nThank you for using the roadCost App by roadCostCorp! " << endl;
            sleep_for(seconds(2));
            return 0;
        default:
            cout << "Restarting process...\n\n\n" << endl;
                sleep_for(seconds(3));
            
            inLoop = true;
           
        }
       
    }
   
}

