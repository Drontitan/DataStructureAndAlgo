int main()
{

    int arr[10] = {252, 12, 46, 23, 98, 55, 80, 12, 38, 69, 10};

    int temp;

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 9; j++)

        {

            if (arr[j] > arr[j + 1])
            {

                arr[j] = arr[j + 1] + arr[j];

                arr[j + 1] = arr[j + 1] - arr[j];

                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }

    for (int i = 0; i < 10; i++)

        printf("%d ", arr[i]);
}