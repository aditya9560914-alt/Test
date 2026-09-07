// #include <stdio.h>

// int isPossible(int arr[], int n, int m, int maxPages)
// {
//     int students = 1;
//     int pages = 0;

//     for (int i = 0; i < n; i++)
//     {
//         if (pages + arr[i] <= maxPages)
//         {
//             pages += arr[i];
//         }
//         else
//         {
//             students++;
//             pages = arr[i];
//         }
//     }

//     return students <= m;
// }

// int main()
// {
//     int arr[] = {10, 20, 30, 40};
//     int n = 4;
//     int m = 2;

//     int start = 40;
//     int end = 100;
//     int ans = -1;

//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (isPossible(arr, n, m, mid))
//         {
//             ans = mid;
//             end = mid - 1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//     }

//     printf("Minimum maximum pages = %d", ans);

//     return 0;
// }


//  withot function program::==>>//!!



#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4, m = 2;

    int start = 40, end = 100;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int students = 1;
        int pages = 0;

        for (int i = 0; i < n; i++)
        {
            if (pages + arr[i] <= mid)
            {
                pages = pages + arr[i];
            }
            else
            {
                students++;
                pages = arr[i];
            }
        }

        if (students <= m)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    printf("Minimum maximum pages = %d", ans);

    return 0;
}