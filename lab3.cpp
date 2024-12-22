#include <iostream>
#include <Windows.h>
#include <time.h>
#include <ctime>
#include <chrono>
#include <math.h>
#include <cstdlib>
using namespace std;

int taskMenu()
{
    int variant;
    cout << "Выберите задание: " << endl;
    cout << "1) Вывести матрицу N*N\n"
        << "2) Перестановки матриц\n"
        << "3) Сортировка(shaker sort)\n"
        << "4) Уменьшение, увеличение, умножение или деление всех элементов матрицы на введенное пользователем число\n"
        << "5) ИДЗ №1" << endl;
    cout << "Задание: ";
    cin >> variant;
    return variant;
}

int const N = 5;

void spiraloutput(int (*arr)[N]) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord;

    int top = 0, bottom = N - 1;
    int left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            destCoord.X = i * 4;
            destCoord.Y = top;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(arr + top) + i) << " ";
            Sleep(100);
        }
        top++;


        for (int i = top; i <= bottom; i++) {
            destCoord.X = right * 4;
            destCoord.Y = i;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(arr + i) + right) << " ";
            Sleep(100);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                destCoord.X = i * 4;
                destCoord.Y = bottom;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(arr + bottom) + i) << " ";
                Sleep(100);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                destCoord.X = left * 4;
                destCoord.Y = i;
                SetConsoleCursorPosition(hStdout, destCoord);
                cout << *(*(arr + i) + left) << " ";
                Sleep(100);
            }
            left++;
        }
    }

    destCoord.X = 0;
    destCoord.Y = N + 1;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void zmeyaoutput(int (*arr)[N]) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord;

        for (int stolb = 0; stolb < N; stolb++) {
            if (stolb % 2 == 0) {
                for (int row = 0; row < N; row++) {
                    destCoord.X = (N * N) + (stolb * 4);
                    destCoord.Y = row;
                    SetConsoleCursorPosition(hStdout, destCoord);
                    cout << *(*(arr + row) + stolb) << " ";
                    Sleep(100);
                }
            }
            else {
                for (int row = N - 1; row >= 0; row--) {
                    destCoord.X = (N * N) + (stolb * 4);
                    destCoord.Y = row;
                    SetConsoleCursorPosition(hStdout, destCoord);
                    cout << *(*(arr + row) + stolb) << " ";
                    Sleep(100);
                }
            }
        }
    destCoord.X = 0;
    destCoord.Y = N + 1;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void shakersort(int* arr, int n) {
    bool swapped = true;
    int* start = arr;
    int* end = arr + n * n - 1;

    while (swapped) {
        swapped = false;

        for (int* i = start; i < end; ++i) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --end;

        for (int* i = end - 1; i >= start; --i) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                swapped = true;
            }
        }

        ++start;
    }
}

int main(){
    srand(time(NULL));
    int maxvalue = N * N, minvalue = 1;
    int arr[N][N];
    int sortArr[N][N];
    int calcArr[N][N];
    int stairArr[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arr[i][j] = rand() % (maxvalue - minvalue + 1) + minvalue;
            sortArr[i][j] = arr[i][j];
            calcArr[i][j] = arr[i][j];
            stairArr[i][j] = arr[i][j];
        }
    }
    while (true) {
        setlocale(LC_ALL, "Russian");
        int variant = taskMenu();
        switch (variant) {
        case 1: {
            system("cls");
            spiraloutput(arr);
            zmeyaoutput(arr);
        }
              break;
        case 2: {
            int step = N / 2;
            int abcd;
            cout << "Выберите тип перестановки,введите число от 1 до 4: " << endl;
            cout << "1) a\n"
                << "2) b\n"
                << "3) c\n"
                << "4) d\n" << endl;
            cin >> abcd;
            switch (abcd) {
            case 1: {
                system("cls");
                int change[N][N];
                int* arr_ptr = *arr;
                int* change_ptr = *change;
                for (int i = 0; i < step; i++) {
                    for (int j = 0; j < step; j++) {
                        *(change_ptr + i * N + j) = *(arr_ptr + (i + step) * N + j);
                        *(change_ptr + i * N + (j + step)) = *(arr_ptr + i * N + j);
                        *(change_ptr + (i + step) * N + (j + step)) = *(arr_ptr + i * N + (j + step));
                        *(change_ptr + (i + step) * N + j) = *(arr_ptr + (i + step) * N + (j + step));
                    }
                }
                spiraloutput(change);
                zmeyaoutput(arr);
            }
                  break;
            case 2: {
                system("cls");
                int change2[N][N];
                int* arr_ptr = *arr;
                int* change2_ptr = *change2;
                for (int i = 0; i < step; i++) {
                    for (int j = 0; j < step; j++) {
                        *(change2_ptr + i * N + j) = *(arr_ptr + (i + step) * N + (j + step));
                        *(change2_ptr + i * N + (j + step)) = *(arr_ptr + (i + step) * N + j);
                        *(change2_ptr + (i + step) * N + (j + step)) = *(arr_ptr + i * N + j);
                        *(change2_ptr + (i + step) * N + j) = *(arr_ptr + i * N + (j + step));
                    }
                }
                spiraloutput(change2);
                zmeyaoutput(arr);
            }
                  break;
            case 3: {
                system("cls");
                int change3[N][N];
                int* arr_ptr = *arr;
                int* change3_ptr = *change3;
                for (int i = 0; i < step; i++) {
                    for (int j = 0; j < step; j++) {
                        *(change3_ptr + i * N + j) = *(arr_ptr + (i + step) * N + j);
                        *(change3_ptr + i * N + (j + step)) = *(arr_ptr + (i + step) * N + (j + step));
                        *(change3_ptr + (i + step) * N + j) = *(arr_ptr + i * N + j);
                        *(change3_ptr + (i + step) * N + (j + step)) = *(arr_ptr + i * N + (j + step));
                    }
                }
                spiraloutput(change3);
                zmeyaoutput(arr);
            }
                  break;
            case 4: {
                system("cls");
                int change4[N][N];
                int* arr_ptr = *arr;
                int* change4_ptr = *change4;
                for (int i = 0; i < step; i++) {
                    for (int j = 0; j < step; j++) {
                        *(change4_ptr + i * N + j) = *(arr_ptr + i * N + (j + step));
                        *(change4_ptr + (i + step) * N + j) = *(arr_ptr + (i + step) * N + (j + step));
                        *(change4_ptr + i * N + (j + step)) = *(arr_ptr + i * N + j);
                        *(change4_ptr + (i + step) * N + (j + step)) = *(arr_ptr + (i + step) * N + j);
                    }
                }
                spiraloutput(change4);
                zmeyaoutput(arr);
            }
                  break;
            }
        }
              break;
        case 3: {
            system("cls");
            shakersort(*sortArr, N);
            spiraloutput(sortArr);
            zmeyaoutput(sortArr);
        }
              break;
        case 4: {
            int matfucn;
            cout << "Выберите тип действия: " << endl;
            cout << "1) Вычитание\n"
                << "2) Прибавление\n"
                << "3) Умножение\n"
                << "4) Деление\n" << endl;
            cin >> matfucn;
            switch (matfucn) {
            case 1: {
                int num;
                cout << "Введите число: " << endl;
                cin >> num;
                system("cls");
                int* start = *calcArr;
                int* end = *(calcArr + N * N - 1);
                for (int* ptr = start; ptr <= end; ++ptr) {
                    *ptr -= num;
                }
                spiraloutput(calcArr);
                zmeyaoutput(arr);
            }
                  break;
            case 2: {
                int num;
                cout << "Введите число: " << endl;
                cin >> num;
                system("cls");
                int* start = *calcArr;
                int* end = *(calcArr + N * N - 1);
                for (int* ptr = start; ptr <= end; ++ptr) {
                    *ptr += num;
                }
                spiraloutput(calcArr);
                zmeyaoutput(arr);
            }
                  break;
            case 3: {
                int num;
                cout << "Введите число: " << endl;
                cin >> num;
                system("cls");
                int* start = *calcArr;
                int* end = *(calcArr + N * N - 1);
                for (int* ptr = start; ptr <= end; ++ptr) {
                    *ptr *= num;
                }
                spiraloutput(calcArr);
                zmeyaoutput(arr);
            }
                  break;
            case 4: {
                int num;
                cout << "Введите число: " << endl;
                cin >> num;
                system("cls");
                int* start = *calcArr;
                int* end = *(calcArr + N * N - 1);
                for (int* ptr = start; ptr <= end; ++ptr) {
                    *ptr /= num;
                }
                spiraloutput(calcArr);
                zmeyaoutput(arr);
            }
                  break;
            }
        }
              break;
        case 5: {
            system("cls");
            int idzArr[N][N];
            int idzArr2[N][N];
            int idzArr3[N][N];
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    idzArr[i][j] = rand() % (maxvalue - minvalue + 1) + minvalue;
                    idzArr2[i][j] = rand() % (maxvalue - minvalue + 1) + minvalue;
                }
            }
            spiraloutput(idzArr);
            zmeyaoutput(idzArr2);
            for (int i = 0; i < N; ++i) {
                int* elIDZArr = idzArr[i];
                int* elIDZArr2 = idzArr2[i];
                int* elIDZArr3 = idzArr3[i];
                for (int j = 0; j < N; ++j) {
                    *(elIDZArr3 + j) = *(elIDZArr + j) + *(elIDZArr2 + j);
                }
            }
            int t;
            cout << "Чтобы сложить матрицу (1/2) нажмите 1" << endl;
            cin >> t;
            if (t == 1) {
                system("cls");
                spiraloutput(idzArr3);
            }
            else {
                cout << "ОШИБКА: Некорректный ввод" << endl;
                cin >> t;
            }
        }
              break;
        default: {
            cout << "ОШИБКА: Некорректный ввод";
            exit(EXIT_FAILURE);
        }
        }
    }
}