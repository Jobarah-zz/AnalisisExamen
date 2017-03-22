#include "Test.h"
#include <iostream>

using namespace std;

//Counts the number of possible paths from origin to destination in the given DAG (Directed Acyclic Graph)
//Use Dynamic Programing to optimize the process
int countPaths(int** DAG, int size, int origin, int destination)
{
    return -1;
}

//helper function to verify if a colour has been pushed in the vector returned by getVertexColors
bool answerContains(vector<int> answer, bool *available, int cr, int size)
{
    for(int i =0; i < size; i++)
    {
        if(available[i])
        {
            if(answer[i]==cr)
            {
                return false;
            }
        }
    }
    return true;
}

//helper flag every adjacent node's color as unavailable
void processNeighboursColours(int **graph, bool *available, int iteration, int size)
{
    for (int j = 0; j < size; j++)
    {
        if (graph[iteration][j] != -1 || graph[j][iteration] != -1)
        {
            available[j] = true;
        }
    }
}

//retrieve first index whose value is false
int findFirstAvailableColour(bool * available, vector<int> answer, int size)
{
    for (int colour = 0; colour < size; colour++)
    {
        if (available[colour] == false && answerContains(answer, available, colour, size))
        {
            return colour;
        }
    }
}

void resetAvailableColours(int ** graph, bool* available, int iteration, int size)
{
    for(int j =0; j < size; j++)
    {
        if(graph[iteration][j] != -1 || graph[j][iteration] != -1)
        {
            available[j] = false;
        }
    }
}

//Returns a vector that maps each vertex to a color (or number)
//Two adjacent vertex cannot have the same color
//The less colors used, the better
//Use a Greedy Paradigm to optimize the process
//The best solution is not required
//based on code from http://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
vector<int> getVertexColors(int** graph, int size)
{
    vector<int> answer;

    // Assign the first color to first vertex
    answer.push_back(0);
    // Initialize remaining size-1 vertices as unassigned
    for(int i=1; i < size; i++)
        answer.push_back(-1);

    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[size];
    for (int cr = 0; cr < size; cr++)
        available[cr] = false;

    for(int i = 0; i < size; i++)
    {

        processNeighboursColours(graph, available, i, size);

        answer[i] = findFirstAvailableColour(available, answer, size);

        resetAvailableColours(graph, available, i, size);
    }

    return answer;
}

int main ()
{
    test();
    return 0;
}