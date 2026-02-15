#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_COLS 20  
void printoMatrica(double matrica[][MAX_COLS], int rreshta, int kolona, int n) {
    cout << "-                                    -" << endl;
    for (int i = 0; i < rreshta; i++) {
        cout << "| ";
        for (int j = 0; j < kolona; j++) {
            if (j == n) cout << " | ";  
            cout << setw(8) << fixed << setprecision(2) << matrica[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-                                    -" << endl;
    cout << endl;
}

bool gjejInverseMeGaussJordan(double matrica[][20], int n) {
    double m_zgjeruar[10][MAX_COLS];  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m_zgjeruar[i][j] = matrica[i][j];  
        }
        for (int j = n; j < 2 * n; j++) {
            m_zgjeruar[i][j] = (i == j - n) ? 1 : 0; 
        }
    }

    
    for (int i = 0; i < n; i++) {
        double temp = m_zgjeruar[i][i];
        if (temp == 0) {
            cout << "Matrica nuk mund të bëhet inverte.\n";
            return false;
        }

        
        for (int j = 0; j < 2 * n; j++) {
            m_zgjeruar[i][j] /= temp;
        }
        cout << "Normalizimi i rreshtit " << i + 1 << ":\n";
        printoMatrica(m_zgjeruar, n, 2 * n, n);

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double faktor = m_zgjeruar[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    m_zgjeruar[k][j] -= faktor * m_zgjeruar[i][j];
                }
                cout << "Eleminimi i rreshtit " << k + 1 << " duke përdorur rreshtin " << i + 1 << ":\n";
                printoMatrica(m_zgjeruar, n, 2 * n, n);
            }
        }
    }

    cout << "Matrica inverse (ne te djathte):\n";
    printoMatrica(m_zgjeruar, n, 2 * n, n);

    return true;
}

int main() {
    int n;
    cout << "Fut dimensionin e matrices (maksimumi 10x10): ";
    cin >> n;

    if (n > 10) {
        cout << "Maksimumi i dimensioneve është 10. Programi do të ndalojë.\n";
        return 1;
    }

    double matrica[10][20]; 

    cout << "Fut elementet e matrices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrica[i][j];
        }
    }

    cout << "Matrica fillestare:\n";
    printoMatrica(matrica, n, n, n);

    if (!gjejInverseMeGaussJordan(matrica, n)) {
        cout << "Matrica nuk ka inverse.\n";
    }

    return 0;
}
