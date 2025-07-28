#include <iostream>
using namespace std;

int main() {
    int arri1[5] = {2, 4, 6, 8, 10};
    int arri2[7] = {1, 3, 4, 5, 7, 10, 6};
    //int arri2[7] = {1, 3, 0, 5, 7, 0, 0};


    int arri1_size = sizeof(arri1) / sizeof(arri1[0]);
    int arri2_size = sizeof(arri2) / sizeof(arri2[0]);


    int min_size;
    if (arri1_size < arri2_size) {
        min_size = arri1_size;
    } else {
        min_size = arri2_size;
    }

    int resultant_array[min_size];
    int common_count = 0;



    for (int i = 0; i < arri1_size; i++) {
        for (int j = 0; j < arri2_size; j++) {
            if (arri1[i] == arri2[j]) {

                bool already_exists = false;
                for (int k = 0; k < common_count; k++) {
                    if (resultant_array[k] == arri1[i]) {
                        already_exists = true;
                        break;
                    }
                }

                if (!already_exists) {
                    resultant_array[common_count] = arri1[i];
                    common_count++;
                }
                break;
            }
        }
    }


    if (common_count > 0) {
        cout << "Common elements: ";
        for (int i = 0; i < common_count; i++) {
            cout << resultant_array[i] << " ";
        }
        cout << endl;
    } else {
        cout << "There are no common elements" << endl;
    }

    return 0;
}
