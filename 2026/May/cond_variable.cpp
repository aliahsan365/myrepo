#include <iostream>
#include <thread>
#include <future>
#include <condition_variable>
#include <queue>
#include<mutex>
using namespace std;

queue<int> d;
mutex m;
condition_variable cv;

void producer() {
    int count = 10;
    while (count > 0) {
        unique_lock<mutex> locker(m);
        d.push(count);
        locker.unlock();
        cv.notify_one(); // notifica para que salga del wait el thread que este durmiendo. su tarea ya esta hecha.
        //this_thread::sleep_for(chrono::seconds(1));
        --count;
    }
}



void consumer() {
    int data = 0;
    while (data!=1) {
        unique_lock<mutex> locker(m);
        cv.wait(locker); // se queda esperando,pero desbloqua el mutex de locker para liberar otros threads. 
        data = d.front(); 
        d.pop();
        locker.unlock();
        cout << data << endl;
    }
}




int main() {
    cout << "hola" << endl;
    thread tc(consumer);
    thread tp(producer);
    tc.join();
    tp.join();
    return 0;
} 