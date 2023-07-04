void heap_sort(int* input, int n)
{
    for (int i = 1; i < n; i++)
    {
        int idx_child = i;
        int idx_parent = (idx_child - 1) / 2;
        while (idx_child > 0)
        {
            if (input[idx_child] > input[idx_parent]) swap(input[idx_parent], input[idx_child]);
            else break;
            visualize(idx_parent, idx_child);
            SDL_Delay(40);
            idx_child = idx_parent;
            idx_parent = (idx_child - 1) / 2;
        }
    }
    for (int last_idx = n - 1; last_idx >= 0; last_idx--)
    {
        swap(input[0], input[last_idx]);
        int idx_parent = 0;
        int lci = 2 * idx_parent + 1;
        int rci = 2 * idx_parent + 2;
        while (lci < last_idx)
        {
            int idx_max = idx_parent;
            if (input[lci] > input[idx_max]) idx_max = lci;
            if (rci<last_idx && input[rci]>input[idx_max]) idx_max = rci;
            if (idx_max == idx_parent) break;
            swap(input[idx_parent], input[idx_max]);
            visualize(idx_max, idx_parent, last_idx);
            SDL_Delay(40);
            idx_parent = idx_max;
            lci = 2 * idx_parent + 1;
            rci = 2 * idx_parent + 2;
        }
    }
}