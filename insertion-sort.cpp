void insertionSort()
{
    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int temp = A[i];
        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
            visualize(i, j + 1);
            SDL_Delay(5);
        }
        A[j + 1] = temp;
    }
}