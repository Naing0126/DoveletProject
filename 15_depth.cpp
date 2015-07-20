#include<stdio.h>
int arr[2000];
int max = 0;
int maxIdx = 0;
int chk[3] = { 0, };

void PreToArr(int idx, int dep){
    int ch1, ch2;
    scanf("%d", &ch1);
    if (ch1 != -1){
        arr[idx * 2] = ch1;
        if (max < dep + 1)
            max = dep + 1;
        if (maxIdx < idx * 2)
            maxIdx = idx * 2;
        PreToArr(idx * 2, dep + 1);
    }
    scanf("%d", &ch2);
    if (ch2 != -1){
        arr[idx * 2 + 1] = ch2;
        if (max < dep + 1)
            max = dep + 1;
        if (maxIdx < idx * 2 + 1)
            maxIdx = idx * 2 + 1;
        PreToArr(idx * 2 + 1, dep + 1);
    }
    else if (ch2 == -1){
        return;
    }
}

int main(){
    int i;
    int root;

    for (i = 0; i < 1030; i++)
        arr[i] = -1;

    scanf("%d", &root);
    arr[1] = root;
    PreToArr(1, 1);

    int cnt = 0;
    for (i = 1; i <= maxIdx; i++){
        if (arr[i * 2] != -1 && arr[i * 2 + 1] != -1)
            cnt++;
    }

    printf("%d\n", cnt);
    printf("%d", max);

    return 0;
}