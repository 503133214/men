#include<bits/stdc++.h>
using namespace std;

void greedy(int n, double d, double S[], double radio) {
    d *= radio;
    double currentMilk = 0.0;
    double wastedMilk = 0.0;
    double wastedMilk_batches[n];
    int batches = 0;
    int batches_index[n + 1]; 
    double B[n];

    for(int i = 0; i < n; i++) {
        currentMilk += S[i];
        if(currentMilk >= d) {
            batches_index[batches] = i;
            B[batches] = d / radio;
            wastedMilk_batches[batches] = currentMilk - d;
            wastedMilk += currentMilk - d;
            currentMilk = 0;
            batches++;
        }
    }

    if(currentMilk > 0 && currentMilk < d) {
        batches_index[batches] = n - 1;
        B[batches] = currentMilk / radio;
        batches++;
    }

    cout << "Total number of chocolate batches produced: " << batches << endl;
    cout << "Total amount of wasted milk: " << wastedMilk << " liters" << endl;

    for(int i = 0; i < batches; i++) {
        cout << "Batch " << i + 1 << ": " << B[i] << " KG " << "Milk used from shipments: ";
        for(int j = (i == 0 ? 0 : batches_index[i - 1] + 1); j <= batches_index[i]; j++) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    double d, radio;
    cout << "Enter the number of milk shipments: ";
    cin >> n;
    double S[n];
    cout << "Enter the amounts of milk in each shipment (liters): ";
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    cout << "Enter the amount of milk required for one batch of chocolates (liters): ";
    cin >> d;
    
    cout << "Enter the ratio [per] (cho/milk): ";
    cin >> radio;
    greedy(n, d, S, radio);
}

