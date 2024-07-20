#include <iostream>

using namespace std;

int main()
{
    int arr[11];
    int dem = 0;
    for (int i = 1; i <= 11; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= 10; i++)
    {
        if (arr[i] == arr[11])
            dem++;
    }
    if (dem == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 1; i <= 10; i++)
        {
            if (arr[i] == arr[11])
                cout<<i<<" ";
        }
    }
    return 0;
}