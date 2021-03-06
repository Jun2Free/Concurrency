#include <iostream>
#include <thread>
#include <chrono>

void pause_thread(int n)
{
    std::this_thread::sleep_for (std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";
}

int main()
{
    std::cout<< "Spawning 3 threads...\n";
    std::thread t1 (pause_thread,1);
    std::thread t2 (pause_thread,2);
    std::thread t3 (pause_thread,3);
    std::cout << "Done spawning threads. Now waiting for them to join:\n";

    t1.join();  // This call will only return when the thread reaches the end of the thread function and block the main thread until then.
    t2.join();
    t3.join();
    std::cout << "All threads joined!\n";

    return 0;

}