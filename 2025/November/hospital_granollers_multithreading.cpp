#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <utility> // move function.
using namespace std;


//----------------------------------------------------------------------
//This is a simulation of the program runned by hospital de granollers (among other hospitals and institutions)
//to perform blood tests of patients each day. 

//Each room has a nurse in it. When a nurse ends dealing with patient,
//asks to next patient to enter the room by pressing "next patient" button.
//This step and the entair process is done asynchrounsly by each nurse in a room.
//The action of pressing the "next patitent" is simulated with a timeout.


//Each worker thread represents a nurse in a room. 
//The exact dealing time for each patient is not fixed. 
//Effective working time for each patient goes within a range of 5-10seconds(just a simulation) 
//This program is using C++11 standard library only.
//This program garantees no race conditions.
//----------------------------------------------------------------------


#define MAX_PATIENTS_DAY 5 // each nurse in a room will attend MAX_PATIENT per DAY.

//Declared globaly. So all thread can see and interact with the same instance.
//By using atomic object help us preventing data races among threads. 
std::atomic<int> _patient_counter(0);

//Active thread safe mechanism by using mutex.
//Declared globally, so all threads can share both mutual exlusion objects.
std::mutex g_cout_mutex;

//global function used by all the threads.
//Need to be programmed with protection against race conditions.
void print_turn(int _room, int _patient_counter) {

    {
        std::lock_guard<std::mutex> lock(g_cout_mutex);
        cout << "patient:" << _patient_counter << " go to room number:" << _room << endl;
    }//Here lock object, declared in the stack section of the process memory, gets destroyed. 
    //The unlock function of g_cout_mutex object is called within the destructor function of lock_guard object. 
    //This is the mecanishm we use to prevent data race among thread.  
}

class Room {
private:
    int id;
    //NOT IMPORTANT. Simulates when the nurse has pressed the "next patient button". 
    //Effective working time is simulated with a sleep for each thread (nurse).
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
public:
    Room(int _id) : distribution(5, 10) {
        id = _id;
        std::random_device rd;
        generator.seed(rd());
    }
    void working() {
        //working...
        int delay_seconds = distribution(generator);
        std::this_thread::sleep_for(std::chrono::seconds(delay_seconds));
        ++_patient_counter; //Incrementing atomic wrapped (thread safe) variable.
        print_turn(id, _patient_counter); // calling globally declared manually thread save function.    
    }
    int get_id() {
        return id;
    }
};


void manage_room(Room r) {

    int i = 0;
    while (i < MAX_PATIENTS_DAY)
    {
        r.working();
        ++i;
    }
}

int main()
{
    int _nrooms;
    cout << "How much rooms do you have in your hospital to perfom blood tests?" << endl;
    cin >> _nrooms;

    vector<std::thread> _workers;

    for (int i = 0; i < _nrooms; ++i) {
        Room _room(i); // declared by the main thread within the stack.
        //later on, the ownership of room object is transfered to each thread's stack (std::move)
        //threfore no need of object Room to be thread safe. 
        //This happens because each thread as is own Room. 
        _workers.push_back(std::thread(manage_room, std::move(_room)));
    }

    //Main thread waits to all worker threads to finish with their job.
    //This is important to ensure neither Operating System nor C++ runtime mess up with the resources,
    //such as objects in memory used by the threads, calling destructors with no real control over it 
    //and avoiding O.S "auto" clean ups . Overall avoid runtime exceptions regarding the use of threads.
    for (int i = 0; i < _nrooms; ++i) {
        if (_workers[i].joinable())
            _workers[i].join();
    }
}