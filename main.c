#include <stdio.h>
#include <conio.h>

void Find_Day(int d,int m,int y)
{
    int sum=0;
    for(int i=1;i<y;i++)
    {
        if(((i%4==0)&&(i%100!=0))||(i%400==0))
        {sum=sum+366;}
        else
        {sum=sum+365;}
    }
    
    if(((y%4==0)&&(y%100!=0))||(y%400==0))
    {
        for(int i=1;i<m;i++)
        {
            if(i==2)
            {sum=sum+29;}
            else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            {sum=sum+31;}
            else
            {sum=sum+30;}
        }
    }
    else
    {
        for(int i=1;i<m;i++)
        {
            if(i==2)
            {sum=sum+28;}
            else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            {sum=sum+31;}
            else
            {sum=sum+30;}
        }
    }
    
    sum=sum+d;
    int i=0;
    i=sum%7;
    if(i==1)
    {printf("(Monday)");}
    else if(i==2)
    {printf("(Tusday)");}
    else if(i==3)
    {printf("(Wednesday)");}
    else if(i==4)
    {printf("(Thusday)");}
    else if(i==5)
    {printf("(Friday)");}
    else if(i==6)
    {printf("(Saturday)");}
    else if(i==7)
    {printf("(Sunday)");}
}

int finddays(int y,int m)
{
    int sum=0;
    for(int i=1;i<y;i++)
    {
        if(((i%4==0)&&(i%100!=0))||(i%400==0))
        {sum=sum+366;}
        else
        {sum=sum+365;}
    }
    
    if(((y%4==0)&&(y%100!=0))||(y%400==0))
    {
        for(int i=1;i<m;i++)
        {
            if(i==2)
            {sum=sum+29;}
            else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            {sum=sum+31;}
            else
            {sum=sum+30;}
        }
    }
    else
    {
        for(int i=1;i<m;i++)
        {
            if(i==2)
            {sum=sum+28;}
            else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            {sum=sum+31;}
            else
            {sum=sum+30;}
        }
    }
    sum=sum+1;
    int i=sum%7;
    return i;
}
void Print_Calender(int y,int m)
{
    printf("\t----------------------------\n");
    if(m==1)
    {printf("\t\tJanuary(%d)",y);}
    else if(m==2)
    {printf("\t\tFebruary(%d)",y);}
    else if(m==3)
    {printf("\t\tMarch(%d)",y);}
    else if(m==4)
    {printf("\t\tApril(%d)",y);}
    else if(m==5)
    {printf("\t\tMay(%d)",y);}
    else if(m==6)
    {printf("\t\tJune(%d)",y);}
    else if(m==7)
    {printf("\t\tJuly(%d)",y);}
    else if(m==8)
    {printf("\t\tAugust(%d)",y);}
    else if(m==9)
    {printf("\t\tSeptember(%d)",y);}
    else if(m==10)
    {printf("\t\tOctober(%d)",y);}
    else if(m==11)
    {printf("\t\tNovember(%d)",y);}
    else if(m==12)
    {printf("\t\tDecember(%d)",y);}
    printf("\n\t----------------------------\n");
    printf("\tSun Mon Tue Wed Thu fri Sat\n");
    
    int sum=finddays(y,m);
    if(sum==7)
    {sum=0;}
    int day=0;
    
    if(((y%4==0)&&(y%100!=0))||(y%400==0))
    {
            if(m==2)
            {day=29;}
            else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
            {day=31;}
            else
            {day=30;}
    }
    else
    {
            if(m==2)
            {day=28;}
            else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
            {day=31;}
            else
            {day=30;}
    }
    
    int i;
    printf("\t");
    for(i=0;i<sum;i++)
    {printf("    ");}
    for(int j=1;j<=day;j++)
    {
        if(j<10)
        {printf("0%d  ",j);}
        else
        {printf("%d  ",j);}
        i++;
        if(i>=7)
        {i=0; printf("\n\t");}
    }
    printf("\n\n");
}

int main()
{
    printf("1. To Find Out The Day\n");
    printf("2. Print Calender\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        int date,month,year;
        clrscr();
        printf("Enter Date Like (DD/MM/YYYY) :- ");
        scanf("%d%d%d",&date,&month,&year);
        Find_Day(date,month,year);
    }
    else if(n==2)
    {
        int year;
        clrscr();
        printf("Enter Year Like (YYYY) :- ");
        scanf("%d",&year);
        char ch='P';  int month=1;
        while(ch!='Q' || ch!='q')
        {
            clrscr();
            Print_Calender(year,month);
            printf("\nPress 'N' to Next, Press 'P' to Previous and 'Q' to Quit : \n");
            scanf("%c",&ch);
            if(ch=='Q' || ch=='q')
            {
                break;
                
            }
            else if(ch=='P' || ch=='p')
            {
                month=month-1;
                if(month==0)
                {month=12; year--;}
            }
            else if(ch=='N' || ch=='n')
            {
                month=month+1;
                if(month>=13)
                {month=1; year++;}
            }
        }
        
    }
    
    return 0;
}
