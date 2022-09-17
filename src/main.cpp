#include <iostream>
#include <string>
#include <filesystem>
#include "visualizer.hpp"
#include "visualizer.cpp" 

int main()
{
	std::string root_filepath = std::filesystem::current_path(); 
	Visualizer Visualizer(root_filepath);
	Visualizer.run();
	return 0;
}