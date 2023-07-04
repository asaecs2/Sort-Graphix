int partition_arr(int a[], int si, int ei)
{
    int cnt = 0;
    for (int i = (si + 1); i <= ei; i++) if (a[i] <= a[si]) cnt++;
    int c = si + cnt;
    swap(a[c], a[si]);
    visualize(c, si);
    int i = si, j = ei;
    while (i<c && j>c)
    {
        if (a[i] <= a[c]) i++;
        else if (a[j] > a[c]) j--;
        else
        {
            swap(a[i], a[j]);
            visualize(i, j);
            SDL_Delay(70);
            i++, j--;
        }
    }
    return c;
}

void quickSort(int a[], int si, int ei)
{
    if (si >= ei) return;
    int c = partition_arr(a, si, ei);
    quickSort(a, si, c - 1);
    quickSort(a, c + 1, ei);
}