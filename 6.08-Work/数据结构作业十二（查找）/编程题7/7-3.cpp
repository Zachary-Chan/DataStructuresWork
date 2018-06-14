#include<iostream>
using  namespace std;

int BIN(int a[], int key, int n) {
    int left = 0;
    int right = n - 1;

    int i = 0;
    int j = 0;
    while (left <= right) {
        int middle = (left + right) / 2;

        if (key == a[middle])
        {
            i = j = middle;
            cout << i <<" "<<j<<endl;

            //cout << t;
            return middle;
        }
        if (key > a[middle])left = middle + 1;
        else { right = middle - 1; }

    }
     i = right;
     j = left;
    cout << i<<" "<< j<<endl;

    return -1;
}

int main() {
    int n;
    int x;
    cin >> n>> x;

    int *a = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    BIN(a, x, n);


}

