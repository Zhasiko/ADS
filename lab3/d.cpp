#include <iostream>
using namespace std;

int main(){
    int cnt = 0;
    int n,m;
    int max;
    int min;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[n][m];
        }
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            for (int i = 0; i < n; ++i)
            {
                int min = a[i][0];
                for (int j = 1; j < n; ++j){
                    if (a[i][j]<min)
                        min = a[i][j];
                }

            }
        }
        for (int j = 0; j < n; ++j)
        {
            int max = a[0][j];
            for (int i = 0; i < n; ++i){
                if (a[i][j]>max)
                    max = a[i][j];
            }
        }
        if(max == min){
        cnt++;
        }
    }
return 0;
}