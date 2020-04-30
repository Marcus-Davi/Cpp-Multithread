#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

struct interval_t {
	uint64_t init;
	uint64_t end;
};

static bool isPrime(uint64_t number);
static uint64_t findPrimes(uint64_t start, uint64_t number);
static uint64_t findPrimes2(uint64_t start, uint64_t number);
static void ComputeIntervals(uint64_t max, int NThreads, std::vector<interval_t>& intervals );

struct PrimeProcessor {
	interval_t I;
	PrimeProcessor(interval_t I_) : I(I_) {};
  //Functor
  void operator()(){
	findPrimes(I.init,I.end);
}



};



int main(){
	int NThreads = 1; // not goot if uint8_t
	uint64_t UpTo;
	std::vector<std::thread> threads;
	std::vector<interval_t> intervals;
	std::chrono::steady_clock::time_point start,end;



	while(1){
	threads.clear();
	std::cout << "Numer of available cores : " << std::thread::hardware_concurrency() << std::endl;
	std::cout << "Number of threads to be used : (> 20 may cause system stall | type '0' for exiting): ";
	std::cin >> NThreads;
std::cout << "N = " << NThreads << std::endl;
	if(NThreads == 0){
		std::cout << "Exiting .." << std::endl;
		return 0;
	}
	//threads.resize(NThreads);

	intervals.resize(NThreads);


	std::cout << "Digite value up to which the number of primes will be determined: ";
	std::cin >> UpTo;
	ComputeIntervals(UpTo,NThreads,intervals);



	std::cout << "Computing .. " << std::endl;
	start = std::chrono::steady_clock::now();


	//start threads
	for (unsigned int i = 0;i<NThreads; ++i){
		PrimeProcessor A(intervals[i]);
		 threads.push_back(std::thread(A));
	}

	//
	for(unsigned int i=0 ; i< threads.size();++i){
		while(threads[i].joinable() == false);
		threads[i].join();
	}



	// for(std::vector<std::thread>::iterator it = threads.begin(); it != threads.end(); ++it){
	// 		while((*it).joinable() == false);
	// 		(*it).join();
	// }

	 end = std::chrono::steady_clock::now();

std::cout << "Computation time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]" << std::endl;



}


	}


// Siveve of Erastothenes (Ver como implementa em paralelo)
static inline uint64_t findPrimes2(uint64_t start,uint64_t number){
	bool* A = new bool[number - start];


}


static inline uint64_t findPrimes(uint64_t start, uint64_t number){
	uint64_t count = 0;
	for(uint64_t i = start; i <= number; ++i){
		if (isPrime(i))
		count++;
	}

	std::cout << "Number of primes : " << count << std::endl << std::endl;
	return count;
}

static inline bool isPrime(uint64_t number) {
	if (number == 0 || number==1)
		return false;
	for (uint64_t i = 2; i < number; ++i) {
		if (number%i)
			continue;
		else
			return false;
	}

	return true;
}

static inline void ComputeIntervals(uint64_t max, int NThreads, std::vector<interval_t>& intervals ) {
	uint64_t section = max / NThreads;
	for (int i = 0; i < NThreads; ++i) {
		intervals[i].end = max - i*section;
		intervals[i].init = intervals[i].end - section+1;
		if (i == NThreads - 1 && (max%2==0))
			intervals[i].init += 1;
		else if (i == NThreads - 1 && (max%2!=0))
			intervals[i].init += 2;
		std::cout << "Interval " << i << "-> [" << intervals[i].init << "," << intervals[i].end << "]" << std::endl;
	}

}
