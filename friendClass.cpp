#include<iostream>
using namespace std;

class A{

    private:
        int x1; 

    public:
        friend class B;
        void setx1(int x1)
        {
            this->x1 = x1;
        }
        int getVal()
        {
            return this->x1;
        }
};

class B{
    private:
    int x2;
    public:
    void setX21(int x2,int x1,A &a1)
    {
        this->x2 = x2;
        a1.x1 = x1;
    }
    int getX2()
    {
        return this->x2;
    }
};

int main()
{
    B b1;
    A a1;
    a1.setx1(10);
    cout<<a1.getVal()<<endl;
    b1.setX21(10,11,a1);
    cout<<a1.getVal()<<endl;
    return 0;
}
