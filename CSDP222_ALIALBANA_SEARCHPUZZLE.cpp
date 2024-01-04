/*
* Ali Albana
* 1337589
* PROJECT 1 
*/


#include <iostream>

using namespace std;



void binarySearch(char wordSearch[][6], int row, char target)
{
    char letters[26];
    int index = 0;
    bool found = false;
    int steps = 0;
    for (int i = 0; i < row;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            steps++;

            letters[index] = wordSearch[i][j];

            if (index < 26)
                index++;
        }


    }
    int first = 0;
    int last = 26 - 1;
    int middle;

    for (int i = 0; i < 26; i++)
    {
        steps++;
        middle = (first + last) / 2;

        if (letters[middle] == target)
        {
            found = true;
            break;
        }
        else if (letters[middle] < target)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    cout << "it took " << steps << " step to find the target! " << endl;


}


void linearSearch(char wordSearch[][6], int row, char target)
{
    bool found = false;
    int steps = 0;
    for (int i = 0; i < row;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            steps++;

            if (wordSearch[i][j] == target)
            {
                found = true;
                break;
            }
        }
        if (found)
            break;

    }
    cout << "It took " << steps << " step to find the target! " << endl;
}



void selectionSort(char wordSearch[][6], int row)
{
    char arr1[26];

    int index = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 6;j++)
        {
            if (index < 26)
            {
                arr1[index] = wordSearch[i][j];

                index++;
            }
        }
    }

    int min;
    for (int i = 0; i < 25; i++)
    {
        min = i;
        for (int j = i + 1; j < 26;j++)
        {
            if (arr1[j] < arr1[min])
                min = j;
        }
        if (min != i)
        {
            swap(arr1[min], arr1[i]);
        }
    }

    index = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 6; j++)

        {
            if (index < 26)
            {
                wordSearch[i][j] = arr1[index];
                index++;
            }
            else
            {
                wordSearch[i][j] = 'o';
            }
        }
    }
}

int main()

{
    char wordSearch[5][6] = { {'A','L','P','D','F','Q'},
                              {'C','H','I','O','K','G'},
                              {'S','N','B','J','E','R'},
                              {'V','Z','X','M','W','U'},
                              {'Y','T','0','0','0','0'}
    };

    selectionSort(wordSearch, 5);

    for (int i = 0; i < 5;i++)
    {
        for (int j = 0; j < 6; j++)
            cout << wordSearch[i][j] << " ";
        cout << endl;
    }
    linearSearch(wordSearch, 5, 'K');
    binarySearch(wordSearch, 5, 'K');

}