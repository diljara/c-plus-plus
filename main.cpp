#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void print(int numbers[80][80])
{
    for (int i=0; i < 80; i++, cout << endl)
    {
        for (int j=0; j < 80; j++)
        {
            cout << numbers[i][j];
        }
    }
    cout << endl;
}




void step(int numbers[80][80], int empti[80][2], int n)
{

    for (int i = 0; i < n; i++)
    {
        int x = empti[i][0];
        int y = empti[i][1];
        if (numbers[x][y] == 0)
        {
            int z = rand() % 4;
            if (z == 0) {
                empti[i][0]++;
            }
            if (z == 2) {
                empti[i][0]--;
            }
            if (z == 1) {
                empti[i][1]++;
            }
            if (z == 3) {
                empti[i][1]--;
            }

            numbers[x][y] = 1;
            numbers[empti[i][0]][empti[i][1]] = 0;
        }
    }
}



void check(int numbers[80][80], int empti[80][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = empti[i][0];
        int y = empti[i][1];
        if ((x == 80 - 1) || (y == 80 - 1) || (x == 0) || (y == 0)){
               numbers[x][y] = -1;
            }
        else {
             for (int j = i + 1; j < n; j++)
               {
                 if (abs(x - empti[j][0]) + abs (y - empti[j][1]) == 1)
                  {
                   numbers[x][y] = -1;
                   numbers[empti[j][0]][empti[j][1]] = -1;

                    }

                }
            }
    }
}


int multiply(int numbers[80][80])
{
    int s = 1;
    for (int i = 0; i < 80; i++)
    {
       for (int j = 0; j < 80; j++)
        {
            s = s * numbers[i][j];
        }
    }
    return s;
}



float singlevalue()
{
    int numbers[80][80] = { 0 };
    for (int i=0; i < 80; i++)
    {
        for (int j=0; j < 80; j++)
            {
            numbers[i][j] = 1;
            }
    }
    int n =1;
    int empti [80][2];
    for (int i=0; i < n; i++)
    {
        int x = rand() % 80;
        int y = rand() % 80;
        empti[i][0] = x;
        empti[i][1] = y;
        numbers[x][y] = 0;
    }
    bool done = true;
    check(numbers, empti, n);
    float result = 0.0;
    for (int t = 1; done == true; t++)
    {
        step(numbers, empti, n);
        check(numbers, empti, n);
        done = (multiply(numbers) == 0);
        result = t;
    }

return result;
}


int main(){
    float avtime = 0.0;
    srand(time(NULL));
    for (int counter = 0; counter < 500; counter++){
        //srand(time(NULL));
        avtime += singlevalue();
        }
    cout << avtime/500;
    return 0;
}
