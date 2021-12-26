#include<stdio.h>
#include<stdlib.h>
void bosluk(char ***a,char ***b,int i, int j,int boyut1,int boyut2)
{
*b[i][j]=*a[i][j];
if(i!=boyut1-1){
if(*a[i+1][j]==' ')bosluk(a,b,i+1,j,boyut1,boyut2);
else if(*a[i+1][j]=='*');
else *b[i+1][j]=*a[i+1][j];}
if(i!=boyut1-1 && j!=boyut2-1){
if(*a[i+1][j+1]==' ')bosluk(a,b,i+1,j+1,boyut1,boyut2);
else if(*a[i+1][j+1]=='*');
else *b[i+1][j+1]=*a[i+1][j+1];}
if(i!=boyut1-1 && j!=0){
if(*a[i+1][j-1]==' ')bosluk(a,b,i+1,j-1,boyut1,boyut2);
else if(*a[i+1][j-1]=='*');
else *b[i+1][j-1]=*a[i+1][j-1];}
if(i!=0 && j!=boyut2-1){
if(*a[i-1][j+1]==' ')bosluk(a,b,i-1,j+1,boyut1,boyut2);
else if(*a[i-1][j+1]=='*');
else *b[i-1][j+1]=*a[i-1][j+1];}
if(i!=0 && j!=0){
if(*a[i-1][j-1]==' ')bosluk(a,b,i-1,j-1,boyut1,boyut2);
else if(*a[i-1][j-1]=='*');
else *b[i-1][j-1]=*a[i-1][j-1];}
if(i!=0){
if(*a[i-1][j]==' ')bosluk(a,b,i-1,j,boyut1,boyut2);
else if(*a[i-1][j]=='*');
else *b[i-1][j]=*a[i-1][j];}
if(j!=boyut2-1){
if(*a[i][j+1]==' ')bosluk(a,b,i,j+1,boyut1,boyut2);
else if(*a[i][j+1]=='*');
else *b[i][j+1]=*a[i][j+1];}
if(j!=0){
if(*a[i][j-1]==' ')bosluk(a,b,i,j-1,boyut1,boyut2);
else if(*a[i][j-1]=='*');
else *b[i][j-1]=*a[i][j-1];}


}
int main()
{
int boyut1,boyut2,mayinsayi,mayin=0,a,b,i,j,kon1,kon2,count,sign;
printf("Enter Board Sizes:(example: 25 25) \n");
scanf("%d %d",&boyut1,&boyut2);

char **tahta;
char y,**bomba;
tahta=(char **)malloc(sizeof(char *)*boyut1);
bomba=(char **)malloc(sizeof(char *)*boyut1);
for(i=0;i<boyut1;i++)
{
*(tahta+i)=(char *)malloc(sizeof(char)*boyut2);
*(bomba+i)=(char *)malloc(sizeof(char)*boyut2);
}
for(i=0;i<boyut1;i++)
{
for(j=0;j<boyut2;j++)
tahta[i][j]='#';
}
for(i=0;i<boyut1;i++)
{
for(j=0;j<boyut2;j++)
bomba[i][j]=' ';
}

printf("Enter the amount of mines you want on your board: \n");
while(1){
scanf("%d",&mayinsayi);
if(mayinsayi<=boyut1*boyut2)break;
printf("Do you think a board with sizes %d x %d can have %d mines? \nEnter a new value!\n",boyut1,boyut2,mayinsayi);
}
while(mayin<mayinsayi)
{
a=rand()%boyut1;
b=rand()%boyut2;
if(bomba[a][b]=='*')
continue;
else
bomba[a][b]='*';
mayin++;
}
for(i=0;i<boyut1;i++)
{
for(j=0;j<boyut2;j++)
{
count=0;
if(bomba[i][j]==' ')
{
if(i!=0 && bomba[i-1][j]=='*')count++;
if(i!=0 && j!=0 && bomba[i-1][j-1]=='*')count++;
if(j!=boyut2-1 && i!=0 && bomba[i-1][j+1]=='*')count++;
if(j!=0 && bomba[i][j-1]=='*')count++;
if(j!=boyut2-1 && bomba[i][j+1]=='*')count++;
if(i!=boyut1-1 && bomba[i+1][j]=='*')count++;
if(i!=boyut1-1 && j!=0 && bomba[i+1][j-1]=='*')count++;
if(i!=boyut1-1 && j!=boyut2-1 && bomba[i+1][j+1]=='*')count++;
if(count!=0)
bomba[i][j]='0'+count;
}
}
}
//tahta yazma
printf("  ");
for(i=0;i<boyut2;i++)
printf("%d",i%10);
printf("\n");
printf("  ");
for(i=0;i<boyut2;i++)
printf("-");
printf("\n");
for(i=0;i<boyut1;i++)
{
printf("%d|",i%10);
for(j=0;j<boyut2;j++)
printf("%c",tahta[i][j]);
printf("\n");
}
//tahta yazma
printf("Enter a command and destination.\nCommands:\ns -> marking\na -> explode \nq -> quit\n(example: a 15 25)\n");
while(1)
{
count=0;
sign=0;
scanf("%c",&y);
if(y=='\n')continue;
if(y=='q'){printf("Game over, you quit\n");break;}
else if(y=='s')
{
scanf("%d %d",&kon1,&kon2);
if(tahta[kon1][kon2]=='/')
{
tahta[kon1][kon2]='#';
mayin++;
}
else
{tahta[kon1][kon2]='/';
mayin--;
}
}
else if(y=='a')
{
scanf("%d %d",&kon1,&kon2);
if(bomba[kon1][kon2]=='*'){tahta[kon1][kon2]=bomba[kon1][kon2];sign=1;}
else if(bomba[kon1][kon2]==' ')
{
tahta[kon1][kon2]=bomba[kon1][kon2];
//bosluk(&bomba,&tahta,kon1,kon2,boyut1,boyut2);
}
else
{
tahta[kon1][kon2]=bomba[kon1][kon2];
}
}
//tahta yazma
printf("  ");
for(i=0;i<boyut2;i++)
printf("%d",i%10);
printf("\n");
printf("  ");
for(i=0;i<boyut2;i++)
printf("-");
printf("\n");
for(i=0;i<boyut1;i++)
{
printf("%d|",i%10);
for(j=0;j<boyut2;j++)
printf("%c",tahta[i][j]);
printf("\n");
}
//tahta yazma

if(sign==1){printf("Game over, you lost\n");break;}
for(i=0;i<boyut1;i++)
{
for(j=0;j<boyut2;j++)
{if(tahta[i][j]=='#' || tahta[i][j]=='/')count++;}
}
if(count<=mayinsayi){printf("Game over, you win\n");break;}
printf("mine count: %d\n",mayin);
}
return 0;

}

