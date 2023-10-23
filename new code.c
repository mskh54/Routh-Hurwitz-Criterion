#include <stdio.h>

int test_system(int n,int system[n]) {
    int flag = 0;
    for(int i =0 ; i<n ; i++){
        if (system[i]<0 ||system[i] ==0) {
        flag =1;
        break;
        }
    }
    return flag;
}

int det_Routh(int a,int b, int c , int d){
    return (((c*b)-(a*d))/c);
}

void get_system(int n ,int system[n]){
    printf("please enter system :" );
    for(int i =0 ; i<n ; i++){
        scanf("%d",&system[i]);
    }
}

void init_Routh(int n , int Routh[n+1][n-2],int system[n]){

    for(int i=0 ; i<=n/2 ; i++){
        Routh[0][i] = system[2*i];
    }

    for(int i=0 ; i<=n/2 ; i++){
        Routh[1][i] = system[2*i+1];
    }

    for(int i=2 ; i<n ; i++){
        for(int j =0 ; j<n-2 ; j++){
            Routh[i][j] = 0;
        }
    }

}

int main(){
    int n;
    printf("please enter order system:" );
    scanf("%d",&n);
    n++;

    int system[n];
    get_system(n , system);

    if(test_system(n,system)){
        printf("this system not Stability!!!\n");
        return 0;
    }

    int Routh[n+1][n-2];
    init_Routh(n,Routh,system);

    for(int i=0 ; i<=n-2 ; i++){
        for(int j =0 ; j<n-2 ; j++){
        Routh[i+2][j] = det_Routh(Routh[i][j] ,Routh[i][j+1] ,Routh[i+1][0] ,Routh[i+1][j+1]);
        }
    }

    int flag = 1;
    for(int i=0 ; i<n+1 ; i++){
        if (Routh[i][0]<=0){
        flag = 0;
        break;
        }
    }
    if(flag){
        printf("yes.\nthis system is Stability.\n");
    }
    else{
        printf("this system is NOT Stability!!!\n");
    }

    return 0;
}