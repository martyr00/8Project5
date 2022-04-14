#include <iostream>

int get_min_val(int * a, int i);
int get_max_val(int * a, int i);

int * get_p_array() {
    int *p = new int[50];

    for (int i = 0; i < 50; i++) {
        if (i == 0) {
            p[i] = 1;
            continue;
        }

        p[i] = (p[i - 1] * 67 + 11) % 128;
    }

    return p;
}

int * get_a_array(const int * p) {
    int *a = new int[50];

    for (int i = 0; i < 50; i++) {
        a[i] = p[i] - 64;
    }

    return a;
}

int get_min_val(int arr[], int i) {
    if (i < 50) {
        return std::min(arr[i], get_min_val(arr,i + 1));
    } else {
        return arr[0];
    }
}

int get_max_val(int arr[], int i) {
    if (i < 50) {
        return std::max(arr[i], get_max_val(arr,i + 1));
    } else {
        return arr[0];
    }
}

int main() {
    int *p = get_p_array();
    int *a = get_a_array(p);
    int i = 0;

    int result = get_min_val(a, i) * get_max_val(a, i);

    std::cout << "max * min elements of the array a: " << result << std::endl;
}
