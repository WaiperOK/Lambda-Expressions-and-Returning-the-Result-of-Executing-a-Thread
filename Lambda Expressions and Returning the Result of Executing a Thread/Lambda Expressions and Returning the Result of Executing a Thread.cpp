#include <iostream>

#include <thread> // библиотека для многопоточности

#include <chrono>

#include <math.h> 

using namespace std;

int Sum(int a, int b)
{

	this_thread::sleep_for(chrono::milliseconds(3000)); // имитация длительного процесса обработки данных (3000 milliseconds)

	cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STARTED\t==========\t " << endl;

	this_thread::sleep_for(chrono::milliseconds(5000)); // имитация длительного процесса обработки данных (5000 milliseconds) 

	cout << "ID потока = \t" << this_thread::get_id() << "\t ==========\t" << "DoWork STOPPED\t==========\t " << endl;

	return a + b;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int result;

	thread t([&result]() { result = Sum(2, 5); }); // лямда. функция, передача в поток 



	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока =" << this_thread::get_id() << "\tmain" << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join();
	cout << "Sum Result = " << result << endl;

	return 0;
}



