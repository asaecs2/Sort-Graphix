#include<bits/stdc++.h>
#include<SDL.h>
#include<limits>
#include<time.h>
#include<chrono>
#include<string>

using namespace std;

const int wid = 910, len = 750, N = 130, M = 7;
int A[N], B[N];

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool over = false;

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Couldn't initialize SDL. SDL_Error: " << SDL_GetError();
        success = false;
    }
    else
    {
        if (!(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))) cout << "Warning: Linear Texture Filtering not enabled.\n";
        window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wid, len, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << "Couldn't create window. SDL_Error: " << SDL_GetError();
            success = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
            {
                cout << "Couldn't create renderer. SDL_Error: " << SDL_GetError();
                success = false;
            }
        }
    }
    return success;
}

void close()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}

void visualize(int x = -1, int y = -1, int z = -1)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    int j = 0;
    for (int i = 0; i <= wid - M; i += M)
    {
        SDL_PumpEvents();
        SDL_Rect rect = { i, 0, M, A[j] };
        if (complete)
        {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
        else if (j == x || j == z)
        {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderFillRect(renderer, &rect);
        }
        else if (j == y)
        {
            SDL_SetRenderDrawColor(renderer, 165, 105, 189, 0);
            SDL_RenderFillRect(renderer, &rect);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 170, 183, 184, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
        j++;
    }
    SDL_RenderPresent(renderer);
}

void randomize()
{
    unsigned int seed = (unsigned)time(NULL);
    srand(seed);
    for (int i = 0; i < N; i++)
    {
        int xyz = rand() % (len);
        B[i] = xyz;
    }
}

void execute()
{
    if (!init()) cout << "SDL Initialization Failed.\n";
    else
    {
        randomize();
        memcpy(A, B, sizeof(int) * N);
        const auto start = std::chrono::high_resolution_clock::now();
        SDL_Event e;
        bool quit = false;
        while (!quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT) quit = true, over = false;
                else if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                    case(cnt_q):
                        quit = true;
                        over = false;
                        cout << "\nEXITING SORTING VISUALIZER.\n";
                        break;
                    case(cnt_0):
                        randomize();
                        over = false;
                        memcpy(A, B, sizeof(int) * N);
                        cout << "\nNEW RANDOM LIST GENERATED.\n";
                        break;
                    case(cnt_1):
                        memcpy(A, B, sizeof(int) * N);
                        cout << "\nSELECTION SORT STARTED.\n";
                        over = false;
                        selectionSort();
                        over = true;
                        cout << "\nSELECTION SORT COMPLETE.\n";
                        break;
                    case(cnt_2):
                        memcpy(A, B, sizeof(int) * N);
                        cout << "\nINSERTION SORT STARTED.\n";
                        over = false;
                        insertionSort();
                        over = true;
                        cout << "\nINSERTION SORT COMPLETE.\n";
                        break;
                    case(cnt_3):
                        memcpy(A, B, sizeof(int) * N);
                        cout << "\nBUBBLE SORT STARTED.\n";
                        over = false;
                        bubbleSort();
                        over = true;
                        cout << "\nBUBBLE SORT COMPLETE.\n";
                        break;
                    case(cnt_4):
                        memcpy(A, B, sizeof(int) * N);
                        cout << "\nMERGE SORT STARTED.\n";
                        over = false;
                        over = true;
                        cout << "\nMERGE SORT COMPLETE.\n";
                        break;
                    case(cnt_5):
                        memcpy(A, B, sizeof(int) * N);
                        cout << "\nQUICK SORT STARTED.\n";
                        over = false;
                        quickSort(A, 0, N - 1);
                        over = true;
                        cout << "\nQUICK SORT COMPLETE.\n";
                        break;
                    case(cnt_6):
                        memcpy(A, B, sizeof(int) * N);
                        cout << "\nHEAP SORT STARTED.\n";
                        over = false;
                        heap_sort(A, N);
                        over = true;
                        cout << "\nHEAP SORT COMPLETE.\n";
                        break;                   
                    }
                }
            }
            visualize();
        }
        close();
    }
}

bool check()
{
    cout << "WARNING: Repititive commands may cause ambiguous behaviour. Please give a new command only after the current command's execution is done.\n\n"
        << "The available sorting algorithms:-\n"
        << "    Use 0 to Generate a different randomized list.\n"
        << "    Use 1 to start Selection Sort Algorithm.\n"
        << "    Use 2 to start Insertion Sort Algorithm.\n"
        << "    Use 3 to start Bubble Sort Algorithm.\n"
        << "    Use 4 to start Merge Sort Algorithm.\n"
        << "    Use 5 to start Quick Sort Algorithm.\n"
        << "    Use 6 to start Heap Sort Algorithm.\n"
        << "PRESS ENTER TO START SORTING VISUALIZER...\n\n"
        << "Or type -1 and press ENTER to quit the program.";
    string s;
    getline(cin, s);
    if (s == "-1") return false;
    return true;
}

void intro()
{
    cout << "---------------------------------Sorting Visualizer---------------------------------\n\n" << "The key is to generate random data, implement a sorting algorithm, and update the screen to visualize the sorting process.\n" << "You need to press ENTER to run the visualize the sorting techniques...";
    string s;
    getline(cin, s);
    if (s == "\n") return;
}

int main(int argc, char* args[])
{
    intro();
    while (1)
    {
        cout << '\n';
        if (check()) execute();
        else
        {
            cout << "\nExiting the program.\n";
            break;
        }
    }
    return 0;
}