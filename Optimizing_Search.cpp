#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime> 
#include <iomanip> 
#include <vector> 
#include <algorithm> 



using namespace std;
using namespace std::chrono;

bool isPrimeBasic(int n, int&num) {
    num = 0;
    num++;
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++) {
        num++;
        if (n % i == 0)
            return false;
    }
    return true;
}


bool isPrimeOdd(int n, int&num) {
    num = 0;
    num++;
    if (n < 2)
        return false;
    num++;
    if (n == 2)
        return true;
    for (int i = 2; i <= n / 2; i++) {
        num++;
        if (n % (2 * i - 1) == 0)
            return false;
    }
    return true;
}


bool isPrimeSqrt(int n, int&num) {
    num = 0;
    num++;
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        num++;
        if (n % i == 0)
            return false;
    }
    return true;
}


bool isPrimeSqrtOdd(int n, int&num) {
    num = 0;
    num++;
    if (n < 2)
        return false;
    num++;
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n) / 2; i++) {
        num++;
        if (n % i == 0)
            return false;
    }
    return true;
}

int nodDoMin(int M, int N, int& num) {
    num = 0;
    int gcd = 1;
    for (int i = 1; i <= min(M, N); ++i) {
        num++;
        if (M % i == 0 && N % i == 0)
            gcd = i;
    }
    return gcd;
}

int nodOtMin(int M, int N, int& num) {
    num = 0;
    for (int i = min(M, N); i > 0; --i) {
        num++;
        if (M % i == 0 && N % i == 0)
            return i;
    }
    return 1;
}

int nodEuclid(int M, int N, int& num) {
    num = 0;
    while (N != 0) {
        num++;
        int temp = N;
        N = M % N;
        M = temp;
    }
    return M;
}


int nokMass(int M, int N, int& num) {
    num = 0;
    vector<int> massM, massN;

    for (int i = 1; i <= N * M; ++i) {
        num++;
        massM.push_back(M * i);
        massN.push_back(N * i);
    }

    for (int m : massM) {
        if (find(massN.begin(), massN.end(), m) != massN.end()) {
            return m;
        }
    }
    return M * N;
}

int nokMax(int M, int N, int& num) {
    num = 0;
    for (int i = max(M, N); i <= M * N; ++i) {
        num++;
        if (i % M == 0 && i % N == 0)
            return i;
    }
    return M * N;
}

int nokEuclid(int M, int N, int& num) {
    num = 0;
    int nod = nodEuclid(M, N, num);
    return (M * N) / nod;
}


double measure_nodDoMin(int M, int N, int& num) {
    auto start = high_resolution_clock::now();
    nodDoMin(M, N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

double measure_nodOtMin(int M, int N, int& num) {
    auto start = high_resolution_clock::now();
    nodOtMin(M, N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

double measure_nodEuclid(int M, int N, int& num) {
    auto start = high_resolution_clock::now();
    nodEuclid(M, N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}


double measure_time_basic(int N, int &num) {
    auto start = high_resolution_clock::now();
    isPrimeBasic(N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}


double measure_time_odd(int N, int&num) {
    auto start = high_resolution_clock::now();
    isPrimeOdd(N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}


double measure_time_sqrt(int N, int&num) {
    auto start = high_resolution_clock::now();
    isPrimeSqrt(N, num);
    auto end = high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measure_time_sqrt_odd(int N, int&num) {
    auto start = high_resolution_clock::now();
    isPrimeSqrtOdd(N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

double measure_nokMass(int M, int N, int& num) {
    auto start = high_resolution_clock::now();
    nokMass(M, N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

double measure_nokMax(int M, int N, int& num) {
    auto start = high_resolution_clock::now();
    nokMax(M, N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

double measure_nokEuclid(int M, int N, int& num) {
    auto start = high_resolution_clock::now();
    nokEuclid(M, N, num);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

double measure_sort_time(vector<int>& arr) {
    auto start = high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();
}

void test_sort() {
    cout << "N\t\tВремя сортировки \n";
    int n = 0;
    int step = 100;
    while (n < 3000) {
        int size = n + step;

        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % (size);

        }
            double sort_time = measure_sort_time(arr);
            cout << size << "\t\t" << fixed << setprecision(7) << sort_time << "\n";
            n += step;
        }

}


int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));
    int limit = 100;
    int limit2 = 0;
    int step = 10;
    int num = 0;
    int choice;

    while (true) {
        cout << "Выберите операцию:\n";
        cout << "1 - Замеры для проверки простоты\n";
        cout << "2 - Замеры для вычисления НОД\n";
        cout << "3 - Замеры для вычисления НОК\n";
        cout << "4 - Замеры для встроенной сортировки\n";

        cout << "0 - Выход\n";
        cin >> choice;

        if (choice == 1) {
            cout << "N\t"
                << "2 to N\t\t"
                << "2 to N (odd)\t\t\t"
                << "2 to sqrt(N)\t\t"
                << "2 to sqrt(N) (odd)\n";

            for (int i = 0; i < 5; ++i) {
                int N = rand() % (limit + 1) + limit2;

                cout << N << "\t" << std::fixed << std::setprecision(7) << measure_time_basic(N, num) << "  " << num << "\t\t";
                cout << measure_time_odd(N, num) << "  " << num << "\t\t";
                cout << measure_time_sqrt(N, num) << "  " << num << "\t\t\t";
                cout << measure_time_sqrt_odd(N, num) << "  " << num << "\n";

                limit2 = limit;
                limit *= step;
            }
        }
        else if (choice == 2) {
            int M, N;
            cout << "Введите два числа M и N для вычисления НОД: " << "\n";
            cout << " M = ";
            cin >> M;
            cout << " N = ";
            cin >> N;

            
            cout << "Алгоритм\t\tВремя\t\t\tСложность\t\tОтвет\n";
            int nod = nodDoMin(M, N, num);
            cout << "Перебор от 1 до min\t" << std::fixed << std::setprecision(7) << measure_nodDoMin(M, N, num) << "\t\t\t" << num << "\t\t" << nod << "\n";
            int nod1 = nodOtMin(M, N, num);

            cout << "Перебор от min до 1\t" << measure_nodOtMin(M, N, num) << "\t\t\t" << num << "\t\t" << nod1 << "\n";
            int nod2 = nodEuclid(M, N, num);
            cout << "Евклид\t\t\t" << measure_nodEuclid(M, N, num) << "\t\t\t" << num << "\t\t" << nod2 << "\n";
        }
        else if (choice == 3) {
            int M, N;
            cout << "Введите два числа M и N для вычисления НОК: " << "\n";
            cout << " M = ";
            cin >> M;
            cout << " N = ";
            cin >> N;

            cout << "Алгоритм\t\tВремя\t\t\tСложность\t\tОтвет\n";
            int nok = nokMass(M, N, num);
            cout << "Формирование кратных\t" << std::fixed << std::setprecision(7) << measure_nokMass(M, N, num) << "\t\t\t" << num << "\t\t" << nok << "\n";
            int nok1 = nokMax(M, N, num);

            cout << "Перебор от max до M*N\t" << measure_nokMax(M, N, num) << "\t\t\t" << num << "\t\t" << nok1 << "\n";
            int nok2 = nokEuclid(M, N, num);

            cout << "Евклид\t\t\t" << measure_nokEuclid(M, N, num) << "\t\t\t" << num << "\t\t" << nok2 << "\n";
        }

        else if (choice == 4) {
            
            test_sort();
        }

        else if (choice == 0) {
            break;
        }
        else {
            cout << "Некорректный ввод. Попробуйте снова.\n";
        }
    }

    return 0;
}
