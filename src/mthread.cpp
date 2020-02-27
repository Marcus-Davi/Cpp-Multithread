#include <iostream>
#include <thread>


using namespace std;


class object {
	public:
	object(unsigned int var){
	cout << "object made " << endl;
	variable = var;
	}

	void operator()(){
		for(int i=0;i<variable;++i){
	cout << "object var = " << i << endl;
		}
	}

	void operator()(int j) {
		for(int i=0;i<j;++i)
		{
		cout << "object i = " << i << endl;
		}
	}

	unsigned int getVar(){
		return variable;
	}

	object operator+(object b){
	object r(0);
	r.variable = b.variable + variable;
	return r;
	}

	private:
	unsigned int variable;

};

void function(int k){
for(int i=0;i<k;++i){
	cout << "i = " << i << endl;
}

}

int main(){

	object o(2);
	object a(3);
	object k = o+a;
//	o(5);

	std::thread t1(function,10);
	std::thread t2(o,10);
	std::thread t3(k);

	t1.join();
	t2.join();
	t3.join();

	cout << "finalizado" << endl;

	return 0;
}
