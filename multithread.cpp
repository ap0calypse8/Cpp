#include<iostream>
#include<thread>
#include<vector>
#include<chrono>
#include<mutex>
#include<random>


void makerandom(int threadID, int num) {

    std::random_device rd; //utilisation of hardware device to produe randomness
    std::mt19937 gen(rd());//Mersenne Twister rn generator engine
    std::uniform_int_distribution<> dis(1, 100);//used to generate random integers with a uniform probability distribution within the specified range

    std::cout << "Thread" << threadID << "is generating" << num << "random numbers \n";
    std::cout.flush();

    for (int i = 0; i < num; ++i) {
        std::cout << "Thread" << threadID << ":" << dis(gen) << "\n";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));//taking a break from the work (simulated)
    }

}

int main() {
    const int threadCount = 3;
    const int numperThread = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < threadCount; ++i) { //i+1 becomes the threadId
        threads.emplace_back(makerandom, i + 1, numperThread);//adjust the arguments in accordance with the parameter provided

    }
        for (auto& t : threads) {
            t.join();
        }
    
    return 0;
}
