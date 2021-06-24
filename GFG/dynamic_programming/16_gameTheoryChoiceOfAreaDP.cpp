/*
Choice of Area
https://www.geeksforgeeks.org/game-theory-choice-area/

Difficulty Level : Medium
Last Updated : 05 Feb, 2018

Consider a game, in which you have two types of powers, 
A and B and there are 3 types of Areas X, Y and Z. 
Every second you have to switch between these areas,
each area has specific properties by which your power A and power B 
increase or decrease. We need to keep choosing areas in such a way that 
our survival time is maximized. 
Survival time ends when any of the powers, A or B reaches less than 0.


Initial value of Power A = 20        
Initial value of Power B = 8

Area X (3, 2) : If you step into Area X, 
                A increases by 3, 
                B increases by 2

Area Y (-5, -10) : If you step into Area Y, 
                   A decreases by 5, 
                   B decreases by 10

Area Z (-20, 5) : If you step into Area Z, 
                  A decreases by 20, 
                  B increases by 5

It is possible to choose any area in our first step.
We can survive at max 5 unit of time by following 
these choice of areas :
X -> Z -> X -> Y -> X
*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

struct area
{
    int a,b;
    area(int a, int b) : a(a), b(b)
    {}
};

int maxSurvivalSecondStep(int A, int B, area X, area Y, area Z, int last, map<pair<int,int>, int> &memo)
{
    if(A<=0 || B<=0)
    {
        return 0;
    }
    pair<int,int> cur = make_pair(A,B);
    
    if(memo.find(cur) != memo.end())
    {
        return memo[cur];
    }
    int temp;
    
    switch(last)
    {
        case 1:
            temp = 1 + max(maxSurvivalSecondStep(A+Y.a, B+Y.b, X,Y,Z,2,memo)
                            ,maxSurvivalSecondStep(A+Z.a, B+Z.b, X,Y,Z,3,memo));
            break;
        case 2:
            temp = 1 + max(maxSurvivalSecondStep(A+X.a, B+X.b, X,Y,Z,1,memo)
                            ,maxSurvivalSecondStep(A+Z.a, B+Z.b, X,Y,Z,3,memo));
            break;
        case 3:
            temp = 1 + max(maxSurvivalSecondStep(A+Y.a, B+Y.b, X,Y,Z,2,memo)
                            ,maxSurvivalSecondStep(A+X.a, B+X.b, X,Y,Z,1,memo));
            break;
    }
    memo[cur] = temp;
    return temp;
}

int maxSurvivalFirstStep(int A, int B, area X, area Y, area Z)
{
    if(A<=0||B<=0)
    {
        return 0;
    }
    map<pair<int,int>, int> memo;
    
    return max(maxSurvivalSecondStep(A+X.a, B+X.b, X,Y,Z,1,memo),
                maxSurvivalSecondStep(A+Y.a, B+Y.b, X,Y,Z,2,memo),
                maxSurvivalSecondStep(A+Z.a, B+Z.b, X,Y,Z,3,memo));
}

int main()
{
    area X(3, 2);
    area Y(-5, -10);
    area Z(-20, 5);
  
    int A = 20;
    int B = 8;
    cout<<maxSurvivalFirstStep(A,B,X,Y,Z);
    return 0;
}