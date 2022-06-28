// g++ secondthread.cpp -pthread
// f you compile without the -pthread flag, you will see an error of the form: undefined reference to pthread_create.
// // You will need to use the -pthread flag for all other multithreaded examples in this course going forward.

#include <iostream>
#include <thread>

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); //simulate work
    std::cout << "Finished work in thread\n";
}

int main() {
    // create thread
    std::thread t(threadFunction);

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  //simulate work
    std::cout << "Finished work in main\n";

    // wait for thread to finish
    t.join();

    return 0;
}
