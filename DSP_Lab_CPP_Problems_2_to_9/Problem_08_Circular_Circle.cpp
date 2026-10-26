
#include <iostream>
using namespace std;

int main()
{
    int i,j,n,x1_size,y_size,x2_size,sum=0,temp,x_o,y_o,h_o;

    cout << "Enter number of first signal samples: ";
    cin >> x1_size;

    cout << "Enter number of second signal samples: ";
    cin >> x2_size;

    if(x1_size>x2_size)
    {
        y_size=x1_size;
    }
    else
    {
        y_size=x2_size;
    }

    int x1[100],x2[100],y[100];

    for(i=0;i<y_size;i++)
    {
        x1[i]=0;
        x2[i]=0;
        y[i]=0;
    }

    cout << "Enter first signal sequences: ";
    for(i=0;i<x1_size;i++)
    {
        cin >> x1[i];
    }

    cout << "\nEnter second signal sequences: ";
    for(i=0;i<x2_size;i++)
    {
        cin >> x2[i];
    }

    for(i=0;i<y_size;i++)
    {
        temp=i;
        sum=0;

        for(j=0;j<y_size;j++)
        {
            sum=sum+x1[j]*x2[temp];
            temp--;

            if(temp<0)
            {
                temp=y_size-1;
            }
        }
        y[i]=sum;
    }

    cout << "\n\nCircular convolution result: ";
    for(i=0;i<y_size;i++)
    {
        cout << y[i] << "  ";
    }

    cout << "\n";
    return 0;
}
