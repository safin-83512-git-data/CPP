#include <iostream>

struct Date 
{
    int day;
    int month;
    int year;
    
};
void InitDate(struct Date *ptrDate)
{
        ptrDate->day=12;
        ptrDate->month=4;
        ptrDate->year=2008;

}
void AcceptDate(struct Date *ptrDate)
{
    printf("Enter Day month & year:");
    scanf("%d%d%d",&ptrDate->day ,&ptrDate->month, &ptrDate->year);
}
void PrintDateOnConsole(struct Date *ptrDate)
{
    printf("Date-:%d-%d-%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}


int main()
{
    int choice;
    struct Date d1;
    InitDate(&d1);
    
    do 
    {
        printf("1.Init Date:\n");
        printf("2.Accept Date:\n");
        printf("3.Display Date:\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                InitDate(&d1);
                break;
            case 2:
                AcceptDate(&d1);
                break;
            case 3:
                PrintDateOnConsole(&d1);
                break;
            default:
                printf("wrong choice:");
                break;
        }
    }while(choice!=0);
        return 0;

}
