#include<stdio.h>
int main ()
{
    int i;
    for (i=1;;i++)
    {
        char a[10];
        scanf("%s",a);
        if(strcmp(a,"Hajj")==0)
            printf("Case %d: Hajj-e-Akbar\n",i);
        else if(strcmp(a,"Umrah")==0)
            printf("Case %d: Hajj-e-Asghar\n",i);
        else if(strcmp(a,"*")==0)
            break;
    }
    return 0;
}
