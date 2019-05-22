#include<bits/stdc++.h>
#define vi vector<double>
#define vvi vector<vi>

using namespace std;

vvi neutral(int n) {
    vvi res = vvi(n, vi(n));
    for(int i=0; i < n; ++i) {
        res[i][i] = 1.0;
    }
    return res;
}

vvi mul(vvi a, vvi b, int n) {
    vvi res = vvi(n, vi(n));
    for(int i=0; i < n; ++i) {
        for(int j=0; j < n; ++j) {
            for(int k=0; k < n; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

vvi fastExp(vvi b, int e) {
    int n = b.size();
    vvi res = neutral(n);

    while(e > 0) {
        if(e&1) res = mul(res, b, n);
        b = mul(b, b, n);
        e >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    vvi matrix(25, vi(25));
    for(int i=0; i < 25; ++i) {
        for(int j=0; j < 25; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << fixed << setprecision(10);
    matrix = fastExp(matrix, stoi(argv[1]));
    for(int i=0; i < 25; ++i) {
        for(int j=0; j <  25; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}
