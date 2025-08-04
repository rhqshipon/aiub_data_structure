#include <iostream>
using namespace std;

int main() {
    cout << "According to the problem, it is assumed that there are a total of 10 bank notes." << endl;

    cout << "Please enter bank notes to mimic the case: ";
    int sizeOfArray = 10;
    int bnotearray[sizeOfArray];
    for (int i = 0; i < 10; i++) {
        cin >> bnotearray[i];
    }



    for (int i = 0; i < sizeOfArray - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < sizeOfArray; j++) {
            if (bnotearray[j] > bnotearray[maxIndex]) {
                maxIndex = j;
            }
        }

        int temp = bnotearray[maxIndex];
        bnotearray[maxIndex] = bnotearray[i];
        bnotearray[i] = temp;
    }

    cout << "After Sort: ";
    for (int i = 0; i < sizeOfArray; i++) {
        cout << bnotearray[i] << " ";
    }
    cout << endl;


    int totalAmount = 0;
    for (int i = 0; i < sizeOfArray; i++) {
        totalAmount += bnotearray[i];
    }

    cout << "Total Amount: " << totalAmount << " taka" << endl;


    int desiredAmount;
    cout << "Provide an amount less than total: ";
    cin >> desiredAmount;


    int notesUsed[sizeOfArray];
    int notesCount = 0;
    int remainingAmount = desiredAmount;
    int totalNeededNotesSum = 0;


    for (int i = 0; i < sizeOfArray; i++) {
        if (remainingAmount > 0)    {
            if (bnotearray[i] <= remainingAmount) {
                notesUsed[notesCount] = bnotearray[i];
                notesCount++;
                remainingAmount -= bnotearray[i];
                totalNeededNotesSum += bnotearray[i];
            }
        }
    }
    cout << endl;


    if (remainingAmount != 0)    {
            cout << "WARNING: There are not sufficient ";
        if(desiredAmount > totalAmount) {
            cout << "AMOUNT of taka ";
        }
        else    {
            cout << "bank note VARIATIONS ";
        }
        cout << "provided in order to make the desired amount!" << endl;
        cout << "Remaining amount which cannot be made into count: " << remainingAmount << " taka" << endl;
    }



    cout << "Total notes needed: " << notesCount << " which are ";
    for (int i = 0; i < notesCount; i++) {
        cout << notesUsed[i] << " ";
    }

    if (remainingAmount != 0)    {
        cout << "which totals to " << totalNeededNotesSum << " taka" << endl;
    }
    cout << endl;


    return 0;
}
