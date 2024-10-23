
#include <iostream>

using namespace std;

int main() {
    int years[] = {
        1920, 1921, 1922, 1923, 1924, 1925, 1926, 1927, 1928, 1929,
        1930, 1931, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939,
        1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1949,
        1950, 1951, 1952, 1953, 1954, 1955, 1956, 1957, 1958, 1959,
        1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969,
        1970
    };

    int births[] = {
        19, 77, 40, 90, 2, 25, 54, 17, 79, 6,
        44, 24, 14, 4, 95, 47, 66, 48, 23, 98,
        15, 86, 25, 50, 9, 29, 64, 3, 67, 4,
        90, 81, 74, 34, 98, 13, 87, 96, 56, 90,
        49, 85, 94, 66, 19, 95, 47, 42, 65, 87,
        11
    };

    int n = sizeof(years) / sizeof(years[0]);
    int max_births = -1;
    int min_births = -1;

    for (int i = 0; i < n; ++i) {
        int count = births[i];

        if (max_births == -1 || count > max_births) {
            max_births = count;
        }

        if (min_births == -1 || count < min_births) {
            min_births = count;
        }
    }

    int years_max_births[10];
    int years_min_births[10];
    int max_count = 0;
    int min_count = 0;

    for (int i = 0; i < n; ++i) {
        int count = births[i];

        if (count == max_births) {
            years_max_births[max_count] = years[i];
            max_count++;
        }

        if (count == min_births) {
            years_min_births[min_count] = years[i];
            min_count++;
        }
    }

    cout << "Nam co so luong nguoi sinh ra lon nhat (" << max_births << "): ";
    for (int i = 0; i < max_count; ++i) {
        cout << years_max_births[i] << " ";
    }
    cout << endl;

    cout << "Nam co so luong nguoi sinh ra be nhat (" << min_births << "): ";
    for (int i = 0; i < min_count; ++i) {
        cout << years_min_births[i] << " ";
    }
    cout << endl;

    cout << "Cac nam co cung so nguoi sinh ra:" << endl;
    for (int i = 0; i < n; ++i) {
        int current_count = births[i];
        bool printed = false;
        cout <<"Co "<< current_count<<" nguoi sinh ra" << ": ";
        
        for (int j = 0; j < n; ++j) {
            if (births[j] == current_count) {
                cout <<years[j] << " ";
                printed = true;
            }
        }

        if (printed) {
            cout << endl;
        }
    }

    return 0;
}
