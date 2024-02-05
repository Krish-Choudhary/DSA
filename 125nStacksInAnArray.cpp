// https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
class NStack
{
    private:
    int *arr;
    int *top;
    int *next;
    int n;
    int s;
    int freespot;
public:
    NStack(int N, int S)
    {   // Constructor
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialise
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }

        // next initialise
        for(int i = 0; i < s; i++){
            next[i] = i + 1;
        }
        next[s - 1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freespot == -1)  return false;

        // step-1 => Find index
        int index = freespot;

        // step-2 => update freespot
        freespot = next[index];

        // step-3 => insert element
        arr[index] = x;

        // step-4 => update next to previous top
        next[index] = top[m - 1];

        // step-5 => update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow
        if(top[m - 1] == -1)    return -1;

        // Just reverse every step of push function

        // index of element that needs to be popped
        int index = top[m - 1];
        
        // storing previous top in top array
        top[m - 1] = next[index];

        // updating next array for next freespot
        next[index] = freespot;

        // setting freestop to present index as it is empty now
        freespot = index;

        return arr[index];
    }
};