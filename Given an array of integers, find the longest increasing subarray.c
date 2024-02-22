
int max(int num1, int num2)
{

    return (num1 > num2) ? num1 : num2;
}
 

int maxIncSubarr(int a[], int n)
{

    // Create two arrays pre and pos

    int pre[n];

    int pos[n];

    for (int i = 0; i < n; i++)

        pre[i] = 0;

    for (int i = 0; i < n; i++)

        pos[i] = 0;
 

    pre[0] = 1;

    pos[n - 1] = 1;

    int l = 0;
 

    // Find out the contribution of the current element in

    // array[0, i] and update pre[i]

    for (int i = 1; i < n; i++) {

        if (a[i] > a[i - 1])

            pre[i] = pre[i - 1] + 1;

        else

            pre[i] = 1;

    }
 

    // Find out the contribution of the current element in

    // array[N - 1, i] and update pos[i]

    l = 1;

    for (int i = n - 2; i >= 0; i--) {

        if (a[i] < a[i + 1])

            pos[i] = pos[i + 1] + 1;

        else

            pos[i] = 1;

    }
 

    // Calculate the maximum length of the strictly

    // increasing subarray without removing any element

    int ans = 0;

    l = 1;

    for (int i = 1; i < n; i++) {

        if (a[i] > a[i - 1])

            l++;

        else

            l = 1;

        ans = max(ans, l);

    }
 

    // Calculate the maximum length of the strictly

    // increasing subarray after removing the current

    // element

    for (int i = 1; i <= n - 2; i++)

        if (a[i - 1] < a[i + 1])

            ans = max(pre[i - 1] + pos[i + 1], ans);
 

    return ans;
}
 
// Driver code

int main()
{

    int arr[] = { 1, 2 };

    int n = sizeof(arr) / sizeof(int);

    printf("%d", maxIncSubarr(arr, n));

    return 0;
}
