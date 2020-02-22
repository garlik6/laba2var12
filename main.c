#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int fun(int n,int *p,int *k);
int insert_checking(int n,int p);
void sort(int mas[]);
int fun(int n,int *p,int *k) {
    int s=0;
    *p=1;
    s=0;
    *k=0;
    while (n>9)
        {
        n/=10;
        *k=*k+1;
        }
    *p=*p*n;
    s=n%10+s;
    *k=*k+1;
    //printf("s=%d\n",s);
    n/=10;
    return s;
}
int insert_checking(int n,int p) {
    if ((n>0)&(n<INT_MAX)&(p==1)) {
        return 1;
    } else return 0;

}

#define SIZE 100
int main() {
    int n=0,t,k,size,i,p;
    int mas1[SIZE],mas2[SIZE],mas3[SIZE];
    do {
        printf("insert array length (<=100)\n");
        p=scanf("%d",&size);
        fflush (stdin);
        }
    while((size>100)||(size<=0)||(p!=1));

    for(i=0;i<size;i++) {
           do {
                printf("insert %d element\n",i);
                p=scanf("%d",&mas1[i]);
                fflush (stdin);
            }
           while(insert_checking(mas1[i],p)!=1);

    }
    for(i=0;i<size;i++) {
         printf("mas1[%d]=%d\n",i,mas1[i]);
    }
    printf("deleting one-digit numbers\n");

    for(i=0;i<size;i++) {
        fun(mas1[i],&t,&k);
        if (k==1) {
            for(int j=i;j<size-1;j++) {
                mas1[j]=mas1[j+1];
            }
           size--;
            i--;
        }
    }
    system("cls");
    if (size==0) {printf("your array consists only of one-digit numbers");
    }
    for(i=0;i<size;i++) {
        printf("mas1[%d]=%d\n",i,mas1[i]);
    }
//    scanf("%d",&n);
//    printf("n=%d\n",n);
//    printf("s=%d\n",fun(n,&t,&k));
//    printf("t=%d\n",t);
//    printf("k=%d\n",k);
//    return(0);
}
