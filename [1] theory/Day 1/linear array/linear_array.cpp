#include <iostream>
using namespace std;


class linear_array {
    private:
        int sizeOfArray;
        int* array;

    public:
        linear_array()  {}
        ~linear_array() {
            delete[] array;  // Free the memory to avoid memory leaks
        }

        void init_array()    {
            cout << "Enter the size for the array:" << endl;
            cin >> sizeOfArray;
            array = new int[sizeOfArray];

            cout << "Enter the values for the array:" << endl;
            for (int i = 0; i < sizeOfArray; i++)   {
                int input = 0;
                cin >> input;
                array[i] = input;
            }
            cout << "Done!" << endl;
        }

        int searchData(int dataToSearch)    {
            int i = 0;
            for (i; i < sizeOfArray; i++)    {
                if (array[i] == dataToSearch)  {
                    break;
                }
            }
            int position = ++i;
            return position;
        }

        void addElementByPosition(int data, int position)   {
            for (int i = sizeOfArray - 2; i > position - 1; i--)    {
                array[i+1] = array[i];
            }
            array[position - 1] = data;
        }

        void addElementByNumberSearch(int data, int dataToReplace)   {
            int position = searchData(dataToReplace);
            addElementByPosition(data, position);
        }

        void deleteElementByPosition(int position)  {
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

        void deleteElementByNumberSearch(int dataToDelete)  {
            int position = searchData(dataToDelete);
            deleteElementByPosition(position);
        }

        void printArray()   {
            for (int i = 0; i < sizeOfArray; i++)   {
                cout << array[i] << " ";
            }
            cout << endl;
        }

};

int main()  {
    linear_array l1;
    l1.init_array();
    l1.printArray();

    l1.addElementByPosition(200, 2);
    l1.printArray();

    l1.deleteElementByPosition(5);
    l1.printArray();

	cout << "Hello World!" << endl;
	return 0;
}
