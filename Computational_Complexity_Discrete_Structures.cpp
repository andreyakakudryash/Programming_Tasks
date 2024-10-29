
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int size, int& compsBubble);
void heapify(int arr[], int size, int i, int& compsHeap);
void heapSort(int arr[], int size);
int posledovSearch(int arr[], int size, int search, int& comps);
int binSearch(int arr[], int size, int search, int& comps);
void createTable(int start);
void createTableWithK(int start, int sortChoice);

void displayMenu() {
    cout << "Выберите задание: \n";
    cout << "1. Зависимость практической сложности двоичного и последовательного поиска от размера массива.\n";
    cout << "2. Реализация сортировок\n";
    cout << "3. Выход\n";
}

void displaySortMenu() {
    cout << "Выберите метод сортировки:\n";
    cout << "1. Пузырьковая сортировка\n";
    cout << "2. Пирамидальная сортировка\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    
    srand(time(0));

    int choice;
    int start = 20;

    while (true) {
        displayMenu();
        cout << "Введите номер задания: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createTable(start);
            break;
        case 2: {
            displaySortMenu();
            int sortChoice;
            cout << "Введите номер сортировки: ";
            cin >> sortChoice;

            createTableWithK(start, sortChoice);
            break;
        }
        case 3:
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный выбор! Пожалуйста, выберите снова.\n";
        }
    }
}

void bubbleSort(int arr[], int size, int &compsBubble) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            compsBubble++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

void heapify(int arr[], int size, int i, int &compsHeap) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    compsHeap++;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    compsHeap++;

    if (right < size && arr[right] > arr[largest])
        largest = right;
    compsHeap++;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest, compsHeap);
    }
}

void heapSort(int arr[], int size, int &compsHeap) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i, compsHeap);

    for (int i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, compsHeap);
    }

    cout << "Pyramid " << compsHeap << endl;
}

int posledovSearch(int arr[], int size, int search, int& comps) {
    comps = 0;
    for (int i = 0; i < size; i++) {
        comps++;
        if (arr[i] == search) {
            return i;
        }
    }
    return -1;
}

int binSearch(int arr[], int size, int search, int& comps) {
    int left = 0;
    int right = size - 1;
    comps = 0;

    while (left <= right) {
        int sredn = (left + right) / 2;
        comps++;
        if (arr[sredn] == search) {
            return sredn;
        }
        comps++;
        if (arr[sredn] < search) {
            left = sredn + 1;
        }
        else {
            right = sredn - 1;
        }
    }

    return -1;
}

void createTable(int start) {
    cout << "Размер массива (N)\tПракт. сложность послед. поиска\tПракт. сложность двоичного поиска\tВыбранный элемент\n";

    for (int size = start; size <= 500; size += 20) {
        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = i; 
        }

        int search = rand() % size;

        int compsSeq;
        int compsBin;
        int posledov = posledovSearch(arr, size, search, compsSeq);
        int bin = binSearch(arr, size, search, compsBin);

        cout << size << "\t\t\t\t\t" << compsSeq << "\t\t\t\t\t" << compsBin << "\t\t\t" << search << "\n";

delete[] arr;
    }
}

void createTableWithK(int start, int sortChoice) {
    
    cout << "Практ. сложность послед. поиска\t\tПракт. сложность двоичного поиска\tВыбранный элемент\n";
    int comps = 0;
    int K = 0;
    
    int size = 1000;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
         arr[i] = rand() % 1000; 
     }

     if (sortChoice == 1) {
         bubbleSort(arr, size, comps);
     }
     else if (sortChoice == 2) {
            heapSort(arr, size, comps);
     }
     else {
         cout << "Неверный выбор сортировки!\n";
         delete[] arr;
        }

        int compsPos = 0;
        int compsBin = 0;
        int search;
        int totalCompsPos = 0;
        int totalCompsBin = comps;


        while (totalCompsPos <= totalCompsBin) {

            K++;

            search = arr[rand() % size];

            posledovSearch(arr, size, search, compsPos);
            totalCompsPos += compsPos;
            binSearch(arr, size, search, compsBin);
            totalCompsBin += compsBin;

            cout << totalCompsPos / K << "\t\t\t\t\t\t\t" << totalCompsBin / K << "\t\t\t\t" << search << "\n";

        }


        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "K = " << K << endl;


        delete[] arr;
   
}
