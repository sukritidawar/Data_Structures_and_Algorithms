#include<iostream>
#include<algorithm>

using namespace std;

void sortArracctoOther(int a[], char b[], int n1){ //O((n1)log(n1))
    pair<int, char> pa[n1];
    for(int i = 0; i < n1; i++){
        pa[i] = make_pair(a[i], b[i]);
    }
    sort(pa, pa + n1);
    for(int i = 0; i < n1; i++){
        cout << pa[i].second << " ";
    }
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    int a[n1];
    char b[n2];
    for(int i = 0; i < n1; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n2; i++){
        cin >> b[i];
    }
    sortArracctoOther(a, b, n1);
    return 0;
}