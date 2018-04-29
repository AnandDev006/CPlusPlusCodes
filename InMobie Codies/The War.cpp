/*
Given a 2d Matrix representing a map, with '.' representing free territory, 'L' for Lanisters, 
'T' for Targaryens, 'O' for own position, 'X' for destination, 'm' for mountain such that T > L in strength
and no one can conquer mountain area.
You are allowed to move up, down, left or righht without leaving the matrix while the L and T
army expands in all 4 above mentioned directions simultaneously after each second. Area taken by L or T is
not accessible to O.
Neither L nor T can capture location X
Find if its possible to reach X,
    if yes print distance to X from O
    if no print -1
*/

/*
    SOLUTION
    BFS by using a pseudo node as the start node which is connected to 'O's 'L's and 'T's
    OR
    Start BFS with the Q already having all 'O's 'L's and 'T's in it ( similar to above )
    trick is to replace both L & T with the same name as independant of their relative strength
    O is less than either so lets call both L & T as F
    this reduces the need to check for precedence between mulitple armies and also reduces overhead
*/

#include <bits/stdc++.h>
#define gs 10000 // Grid Size
#define x first
#define y second

using namespace std;

int M, N;
char grid[gs][gs];
int dist[gs][gs];
queue<pair<int, int>> Q;
int Xi, Xj;

bool isValid(int i2, int j2, int i1, int j1)
{
    if (i2 >= 0 && i2 < M && j2 >= 0 && j2 < N && grid[i2][j2] != 'm' && grid[i2][j2] != 'F')
    {
        if (grid[i1][j1] == 'O' && grid[i2][j2] != 'O')
            return true;
        if (grid[i1][j1] == 'F' && grid[i2][j2] != 'X')
            return true;
    }
    return false;
}

void print()
{
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}

void fun()
{
    const int x[] = {0, 0, 1, -1};
    const int y[] = {1, -1, 0, 0};
    int X, Y;
    while (!Q.empty())
    {
        X = Q.front().x;
        Y = Q.front().y;
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            if (isValid(X + x[i], Y + y[i], X, Y))
            {
                grid[X + x[i]][Y + y[i]] = grid[X][Y];
                if (grid[X][Y] == 'O')
                    dist[X + x[i]][Y + y[i]] = dist[X][Y] + 1;
                Q.push(make_pair(X + x[i], Y + y[i]));
            }
        }
    }
    if (dist[Xi][Xj])
        cout << dist[Xi][Xj] << endl;
    else
        cout << -1 << endl;

    print();
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
        {

            cin >> grid[i][j];

            if (grid[i][j] == 'L' || grid[i][j] == 'T')
                grid[i][j] = 'F';

            if (grid[i][j] == 'X')
            {
                Xi = i;
                Xj = j;
            }

            if (grid[i][j] == 'F' || grid[i][j] == 'O')
                Q.push(make_pair(i, j));
        }
    fun();
    return 0;
}