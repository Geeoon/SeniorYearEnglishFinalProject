#pragma once
#include <iostream>
#include <chrono>
#include <thread>

struct ConsoleHelper {
	inline static void print(std::string string, int delay = 50) {
		for (auto& ch : string) {
			std::cout << ch;
			wait(delay);
		}
	}

	inline static void wait(int delay) {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
};