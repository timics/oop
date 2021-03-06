#include<iostream>
class BigNumber
{
    private:
        int *vec;

    public:
        BigNumber(); /**< A constructor */
        BigNumber(int x); /**< Another constructor, that initializes out BigNumber with an int value */
        ~BigNumber(); /**< The destructor */
        void show(); /**< A function that prints the decimal representation of our BigNumber */
        void operator =(BigNumber x); /**< We overload the assignment operator to allow assignment between big numbers*/
        bool operator ==(BigNumber x); /**< We overload the equality operator operator to allow checking the equality big numbers*/
        bool operator >(BigNumber x); /**< We overload the "greater than" operator to allow comparing big numbers*/
        BigNumber operator +(BigNumber x); /**< We overload the addition operator to allow addition between big numbers*/
        BigNumber operator -(BigNumber x); /**< We overload the subtraction operator to allow subtraction between big numbers*/
        BigNumber operator *(int x); /**<We overload the multiplication operator to allow multiplying a big number and an int*/
};

BigNumber::BigNumber()
{
    vec=new int[1000];
    vec[0]=0;
}

BigNumber::BigNumber(int x)
{
    vec=new int[1000];
    vec[0]=0;
    while(x>0)
    {
        ++vec[0];
        vec[vec[0]]=x%10;
        x=x/10;
    }
}

BigNumber::~BigNumber()
{
    delete [] vec;
}

void BigNumber::show()
{
    for(int i=vec[0];i>0;--i)
        std::cout<<vec[i];
}

void BigNumber::operator =(BigNumber x)
{
    vec[0]=x.vec[0];
    for(int i=1;i<=vec[0];++i)
        vec[i]=x.vec[i];
    return;
}

bool BigNumber::operator ==(BigNumber a)
{
    if(vec[0]!=a.vec[0])
        return 0;
    else
    {
        for(int i=1;i<=vec[0];++i)
            if(a.vec[i]!=vec[i])
                return 0;
    }
    return 1;
}

bool BigNumber::operator >(BigNumber a)
{
    if(vec[0]>a.vec[0])
        return 1;
    if(vec[0]<a.vec[0])
        return 0;

    for(int i=vec[0];i>=1;--i)
    {
        if(vec[i]>a.vec[i])
            return 1;
        if(vec[i]<a.vec[i])
            return 0;
    }
    return 0;
}

BigNumber BigNumber::operator +(BigNumber x)
{
    BigNumber y(0);
    y.vec[0]=vec[0];
    int carry=0;
    for(int i=1;i<=vec[0];++i)
    {
        int temp=vec[i]+x.vec[i]+carry;
        y.vec[i]=temp%10;
        carry=temp/10;
    }
    if(carry>0)
    {
        ++y.vec[0];
        y.vec[y.vec[0]]=carry;
    }
    return y;
}

BigNumber BigNumber::operator -(BigNumber x)
{
    BigNumber y(0);
    y.vec[0]=vec[0];
    int carry=0;
    for(int i=1;i<=vec[0];++i)
    {
        int temp=vec[i]-x.vec[i]-carry;
        y.vec[i]=(temp+10)%10;
        carry=1-(temp+10)/10;
    }
    if(carry>0)
    {
        --y.vec[0];
    }
    return y;
}

BigNumber BigNumber::operator *(int x)
{
    BigNumber y(0);
    y.vec[0]=vec[0];
    int carry=0;
    for(int i=1;i<=vec[0];++i)
    {
        int temp=vec[i]*x+carry;
        y.vec[i]=temp%10;
        carry=temp/10;
    }
    while(carry>0)
    {
        ++y.vec[0];
        y.vec[y.vec[0]]=carry%10;
        carry=carry/10;
    }
    return y;
}
