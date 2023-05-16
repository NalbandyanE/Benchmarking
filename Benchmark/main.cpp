#include "vector.h"
#include "d_list.h"
#include <chrono>
#include <cstdlib>

int main(){
	Vector<int> vec1;
	Vector<int> vec2;
	Vector<int> vec3;
	List<int> list1;
	List<int> list2;
	List<int> list3;
	int size1 = 1000;
	int size2 = 10000;
	int size3 = 100000;

	for (int i = 0; i < size1; ++i) {
        int randomNum = std::rand() % 1000 + 1;
        vec1.push_back(randomNum);
    }

    for (int i = 0; i < size2; ++i) {
        int randomNum = std::rand() % 10000 + 1;
        vec2.push_back(randomNum);
    }

    for (int i = 0; i < size3; ++i) {
        int randomNum = std::rand() % 100000 + 1;
        vec3.push_back(randomNum);
    }

    for (int i = 0; i < size1; ++i) {
        int randomNum = std::rand() % 1000 + 1;
        list1.push_back(randomNum);
    }

    for (int i = 0; i < size2; ++i) {
        int randomNum = std::rand() % 10000 + 1;
        list2.push_back(randomNum);
    }

    for (int i = 0; i < size3; ++i) {
        int randomNum = std::rand() % 100000 + 1;
        list3.push_back(randomNum);
    }

    std::cout << "Vector insert function time benchmarking" << std::endl;
    auto start1 = std::chrono::high_resolution_clock::now();
	vec1.insert(256, 254000);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration1 = end1 - start1;
	std::cout << "Insertion time for inserting element with 1000 element is: " << duration1.count() << " ms" << std::endl;

	auto start2 = std::chrono::high_resolution_clock::now();
	vec2.insert(1500, 258741);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end2 - start2;
	std::cout << "Insertion time for inserting element with 10000 element is: " << duration2.count() << " ms" << std::endl;

	auto start3 = std::chrono::high_resolution_clock::now();
	vec3.insert(12000, 25698);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration3 = end3 - start3;
	std::cout << "Insertion time for inserting element with 100000 element is: " << duration3.count() << " ms" << std::endl;

	std::cout << std::endl;
	std::cout << "List insert function time benchmarking" << std::endl;
    auto start4 = std::chrono::high_resolution_clock::now();
	list1.insert(256, 254000);
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration4 = end4 - start4;
	std::cout << "Insertion time for inserting element with 1000 element is: " << duration4.count() << " ms" << std::endl;

	auto start5 = std::chrono::high_resolution_clock::now();
	list2.insert(1500, 258741);
    auto end5 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration5 = end5 - start5;
	std::cout << "Insertion time for inserting element with 10000 element is: " << duration5.count() << " ms" << std::endl;

	auto start6 = std::chrono::high_resolution_clock::now();
	list3.insert(12000, 25698);
    auto end6 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration6 = end6 - start6;
	std::cout << "Insertion time for inserting element with 100000 element is: " << duration6.count() << " ms" << std::endl;

	std::cout << std::endl;
	std::cout << "Vector erase function time benchmarking" << std::endl;
    auto start7 = std::chrono::high_resolution_clock::now();
	vec1.erase(541);
    auto end7 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration7 = end7 - start7;
	std::cout << "Deletion time for deleting element with 1000 element is: " << duration7.count() << " ms" << std::endl;

	auto start8 = std::chrono::high_resolution_clock::now();
	vec2.erase(2400);
    auto end8 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration8 = end8 - start8;
	std::cout << "Deletion time for deleting element with 10000 element is: " << duration8.count() << " ms" << std::endl;

	auto start9 = std::chrono::high_resolution_clock::now();
	vec3.erase(65412);
    auto end9 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration9 = end9 - start9;
	std::cout << "Deletion time for deleting element with 100000 element is: " << duration9.count() << " ms" << std::endl;

	std::cout << std::endl;
	std::cout << "List erase function time benchmarking" << std::endl;
    auto start10 = std::chrono::high_resolution_clock::now();
	list1.erase(541);
    auto end10 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration10 = end10 - start10;
	std::cout << "Deletion time for deleting element with 1000 element is: " << duration10.count() << " ms" << std::endl;

	auto start11 = std::chrono::high_resolution_clock::now();
	list2.erase(2400);
    auto end11 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration11 = end11 - start11;
	std::cout << "Deletion time for deleting element with 10000 element is: " << duration11.count() << " ms" << std::endl;

	auto start12 = std::chrono::high_resolution_clock::now();
	list3.erase(65412);
    auto end12 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration12 = end12 - start12;
	std::cout << "Deletion time for deleting element with 100000 element is: " << duration12.count() << " ms" << std::endl;

	std::cout << std::endl;
	std::cout << "Vector find function time benchmarking" << std::endl;
    auto start13 = std::chrono::high_resolution_clock::now();
	vec1.find(254000);
    auto end13 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration13 = end13 - start13;
	std::cout << "Searching time for find element with 1000 element is: " << duration13.count() << " ms" << std::endl;

	auto start14 = std::chrono::high_resolution_clock::now();
	vec2.find(258741);
    auto end14 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration14 = end14 - start14;
	std::cout << "Searching time for find element with 10000 element is: " << duration14.count() << " ms" << std::endl;

	auto start15 = std::chrono::high_resolution_clock::now();
	vec3.find(25698);
    auto end15 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration15 = end15 - start15;
	std::cout << "Searching time for find element with 100000 element is: " << duration15.count() << " ms" << std::endl;

	std::cout << std::endl;
	std::cout << "List find function time benchmarking" << std::endl;
    auto start16 = std::chrono::high_resolution_clock::now();
	list1.find(254000);
    auto end16 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration16 = end16 - start16;
	std::cout << "Searching time for find element with 1000 element is: " << duration16.count() << " ms" << std::endl;

	auto start17 = std::chrono::high_resolution_clock::now();
	list2.find(258741);
    auto end17 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration17 = end17 - start17;
	std::cout << "Searching time for find element with 10000 element is: " << duration17.count() << " ms" << std::endl;

	auto start18 = std::chrono::high_resolution_clock::now();
	list3.find(25698);
    auto end18 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration18 = end18 - start18;
	std::cout << "Searching time for find element with 100000 element is: " << duration18.count() << " ms" << std::endl;

	return 0;
}