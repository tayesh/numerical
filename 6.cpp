#include <iostream>
#include <iomanip>
using namespace std;

int fact(int i) {
    int factorial = 1;
    for (int j = 1; j <= i; j++)
        factorial *= j;
    return factorial;
}

double newtonbackwardinterpolation(double x[], double y[], double value, int n) {
    double differ_table[n][n], h, u, result;

    for (int i = 0; i < n; i++)
        differ_table[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            differ_table[i][j] = differ_table[i][j - 1] - differ_table[i - 1][j - 1];
        }
    }

    cout << "Difference Table\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << setw(10) << differ_table[i][j] << "\t";
        }
        cout << endl;
    }

    h = x[1] - x[0];
    u = (value - x[n - 1]) / h;
    result = y[n - 1];

    for (int i = 1; i < n; i++) {
        double u_term = 1.0;
        for (int j = 0; j < i; j++)
            u_term *= (u + j);
        result += (u_term * differ_table[n - 1][i]) / fact(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n], value, result;

    cout << "\n\nEnter x values: ";
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "\n\nEnter their corresponding y values: ";
    for (int i = 0; i < n; i++)
        cin >> y[i];

    cout << "\n\nEnter the value at which you want interpolated value: ";
    cin >> value;

    result = newtonbackwardinterpolation(x, y, value, n);
    cout << "\n\nThe interpolated result at " << value << " is " << result << endl;

    return 0;
}

