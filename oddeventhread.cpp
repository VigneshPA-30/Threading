#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int count = 1;

void printEvenNumbers() {
    while (count <= 20) {
        unique_lock<mutex> lock(mtx);
        if (count % 2 == 0) {
            cout << "Even Thread: " << count << endl;
            count++;
        }
        lock.unlock();
    }
}

void printOddNumbers() {
    while (count <= 20) {
        unique_lock<mutex> lock(mtx);
        if (count % 2 != 0) {
            cout << "Odd Thread: " << count << endl;
            count++;
        }
        lock.unlock();
    }
}

int main() {
    thread t1(printEvenNumbers);
    thread t2(printOddNumbers);

    t1.join();
    t2.join();

    return 0;
}
