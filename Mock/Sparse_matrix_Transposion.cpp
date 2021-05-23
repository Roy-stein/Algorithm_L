#include <stdio.h>
#define MAXSIZE 50
#define MAXRC 10
//��Ԫ��ṹ��
typedef struct{
    //��������������
    int i,j;
    //ֵ
    int e;
}triple;
//�洢�������Ԫ��˳���
typedef struct{
    //�洢����
    triple data[MAXSIZE + 1];
    //�洢����������������ͷ� 0 Ԫ�ĸ���
    int mu,nu,tu;
}TSMatrix;
//��ʼ����Ԫ��˳���
TSMatrix tcreate(int m,int n,int t){
    TSMatrix M;
    int k;
    M.mu = m;
    M.nu = n;
    M.tu = t;
    printf("input %d data ",M.tu);
    printf("i j e \n");
    for(k=1;k<=M.tu;k++){
        scanf("%d%d%d",&M.data[k].i,&M.data[k].j,&M.data[k].e);
    }
    return M;
}
void printt(TSMatrix M){
    int i,j,k=1;
    for(i=0;i<M.mu;i++){
        printf("\n");
        for(j=0;j<M.nu;j++){
            if(k>M.tu){
                printf("%3d",0);
            }
            else{
                if((i==M.data[k].i) && (j == M.data[k].j)){
                    printf("%3d",M.data[k].e);
                    k++;
                }else{
                    printf("%3d",0);
                }
            }
        }
    }
    printf("\n");
}
//�����ת�ú���
TSMatrix fasttrans(TSMatrix a){
    TSMatrix b;
    int col,p,q,t;
    int num[MAXSIZE];
    int cpot[MAXSIZE];
    b.mu = a.nu;
    b.nu = a.mu;
    b.tu = a.tu;
    if(b.tu){
        for(col = 0;col<a.nu;col++){
            num[col] = 0;
        }
        for(t=1;t<=a.tu;t++){
            num[a.data[t].j]++;
        }
        cpot[0]=1;
        for(col=1;col<a.nu;col++){
            cpot[col] = cpot[col-1]+num[col-1];
        }
        for(p=1;p<=a.tu;p++){
            col =a.data[p].j;
            q = cpot[col];
            b.data[q].i = a.data[p].j;
            b.data[q].j = a.data[p].i;
            b.data[q].e = a.data[p].e;
            cpot[col]++;
        }
    }
    return b;
}
int main(){
    int m,n,t;
    TSMatrix E,F;
    printf("input m,n,t:\n");
    scanf("%d%d%d",&m,&n,&t);
    E = tcreate(m,n,t);
    printt(E);
    F = fasttrans(E);
    printt(F);
}
