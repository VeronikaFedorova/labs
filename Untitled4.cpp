#include <cstdio>
#include <algorithm>
using namespace std;
int a[20][20], n, m;
int main() {
	
	
   scanf(" %d %d", &n, &m);
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         scanf(" %d", &a[i][j]);
        }
	}
         
         
   for(int i = 1; i < m; i++){
    a[0][i] += a[0][i - 1];}
    
   for(int i = 1; i < n; i++) {
   a[i][0] += a[i - 1][0];}
   
   for(int i = 1; i < n; i++){
      for(int j = 1; j < m; j++){
         a[i][j] += min(a[i - 1][j], a[i][j - 1]);
		 }
	}
         
   printf("%d", a[n - 1][m - 1]);
   return 0;
}
