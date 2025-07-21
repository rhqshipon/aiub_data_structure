#include <iostream>
using namespace std;


int searchData(int array[10], int sizeOfArray, int dataToSearch)    {
    int i = 0;
    for (i; i < sizeOfArray; i++)    {
        if (array[i] == dataToSearch)  {
            break;
        }
    }
    int position = ++i;
    return position;
}

void deleteElementByPosition(int array[10], int sizeOfArray, int position)  {
    for (int i = position - 1; i < sizeOfArray - 1; i++)    {
        array[i] = array[i+1];
    }
    for (int i = sizeOfArray - 1; i > position - 1; i--)    {
        if (array[i] == 0)  {
                continue;
        }
        array[i] = 0;
        break;
    }
}

void deleteElementByNumberSearch(int array[10], int sizeOfArray, int dataToDelete)  {
    int position = searchData(array, sizeOfArray, dataToDelete);
    deleteElementByPosition(array, sizeOfArray, position);
}

int main()  {
    int sizeOfArray = 6;
    int array[sizeOfArray] = {5, 6, 7, 5, 8, 9};

    int input;
    cout << "Enter the number to move towards the end of the list: ";
    cin >> input;

    int occuranceOfExistance = 0;
    cout << "The array initially looks like: ";
    for (int i = 0; i < sizeOfArray; i++)   {
        if (array[i] == input)  {
            occuranceOfExistance++;
        }
        cout << array[i] << " ";
    }
    cout << endl;



    cout << "The occurance of found existance of the input: " << occuranceOfExistance << endl;
    if (occuranceOfExistance != 0)  {
        for (int i = 0; i < occuranceOfExistance; i++)  {
        deleteElementByNumberSearch(array, sizeOfArray, input);
        array[sizeOfArray - 1] = input;
        }
    }
    else    {
        cout << "Error: Cannot perform this operation as the provided number is not in the provided array!" << endl;
    }

    cout << "The array finally looks like: ";
    for (int i = 0; i < sizeOfArray; i++)   {
        cout << array[i] << " ";
    }
    cout << endl;

    int maxValue = 0;
    int minValue = array[0];
    for (int i = 0; i < sizeOfArray; i++)   {
        if (array[i] == input)  {
            continue;
        }
        if (array[i] > maxValue)    {
            maxValue = array[i];
        }
        if (array[i] < minValue)    {
            minValue = array[i];
        }
    }

    cout << "Minimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue <<  endl;
    cout << "Difference: " << maxValue - minValue << endl;


    return 0;
}
