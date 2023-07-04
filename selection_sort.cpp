void selectionSort()
{
    for (int i = 0; i < N - 1; i++)
    {
        int idx_min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[idx_min])
            {
                idx_min = j;
                visualize(i, idx_min);
            }
            SDL_Delay(1);
        }
        swap(A[i], A[idx_min]);
    }
}