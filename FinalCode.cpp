#include <iostream>
using namespace std;

void NhapMang(int *a,int n)
{
    cout << "Nhap phan tu: ";
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}
void XuatMang(int *a, int &n)
{
    cout << "\nXuat mang: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void Xoaphantu(int *&a, int &n, int &y)
{
    for(int x = y; x < n; x++)
    {
        a[x] = a[x+1];
    }

    int *temp = new int[n-1];
    for(int i = 0; i < n-1; i++)
    {
        temp[i] = a[i];
    }

    delete[] a;

    a = new int[n-1];
    for (int i = 0; i < n-1; i++)
    {
        a[i] = temp[i];
    }
    delete[] temp;
}


void Do(int *&a,int &n, int &dem)
{
    for (int y = 0; y < n; y++)
    {
        if (a[y] > 9)
        {
            break;
        }
        else if(a[0] == a[n-1])
        {
            Xoaphantu(a, n, y);
            n--;

            Do(a, n, dem);
        }
        else
        {
            for (int i = 0; i < n-1; i++)
            {
                if (a[i] > 9)
                {
                    break;
                }
                for (int j = i+1; j < n; j++)
                {
                    if (a[j] > 9)
                    {
                        break;
                    }
                    else if (a[i] == a[j])
                    {

                        Xoaphantu(a, n, i);
                        n--;
                        dem++;

                        Do(a, n, dem);

                    }

                }

            }
        }
    }

}
int main()
{
    int n;

    int dem = 0;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int *a = new int[n];
    NhapMang(a, n);

    Do(a, n, dem);
    cout << dem+n;

    delete[] a;
    system("pause");
    return 0;
}

