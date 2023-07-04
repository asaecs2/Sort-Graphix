void bubbleSort()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (A[j + 1] < A[j])
            {
                swap(A[j], A[j+1]);
                visualize(j + 1, j, N - i);
            }
            SDL_Delay(1);
        }
    }
}