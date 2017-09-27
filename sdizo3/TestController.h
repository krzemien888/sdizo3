#pragma once
class TestController final
{
public:
	TestController() = default;
	~TestController() = default;

	void runAllTests();

	void runBackpackTests();
	void runBackpackBruteforce();
	void runBackpackDynamic();
	void runBackpackGreedy();
private:
	void saveToFile(int testSize, int time);
	void saveToFile(std::string message);

	std::string filename;
	std::ofstream file;
};

