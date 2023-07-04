void Merge(int a[], int si, int ei)
{
    int sz = (ei - si) + 1;
    int* output = new int[sz];
    int mid = (si + ei) / 2, i = si, j = mid + 1, k = 0;
    while (i <= mid && j <= ei)
    {
        if (a[i] <= a[j])
        {
            output[k] = a[i];
            visualize(i, j);
            i++;
            k++;
        }
        else
        {
            output[k] = a[j];
            visualize(i, j);
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        output[k] = a[i];
        visualize(-1, i);
        i++;
        k++;
    }
    while (j <= ei)
    {
        output[k] = a[j];
        visualize(-1, j);
        j++;
        k++;
    }
    int x = 0;
    for (int l = si; l <= ei; l++)
    {
        a[l] = output[x];
        visualize(l);
        SDL_Delay(15);
        x++;
    }
    delete[]output;
}

void mergeSort(int a[], int si, int ei)
{
    if (si >= ei) return;
    int mid = (si + ei) / 2;
    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, ei);
    Merge(a, si, ei);
}