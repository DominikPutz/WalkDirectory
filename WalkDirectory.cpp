// WalkDirectory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

int main()
{
  char directory[255];
  char extension[10];
  std::cout << "Input current path: (e.g. \"..\\..\\files\\folder\\subfolder\"): ";
  std::cin >> directory;
  fs::path current_dir(directory);

  std::cout << "File extension: (e.g. \".pdf\"): ";
  std::cin >> extension;

  std::ofstream excel;
  excel.open("result.csv");
  excel << "Path; Filename\n";

  // list all files containing the proper extension
  for (auto &file : fs::recursive_directory_iterator(current_dir))
  {
    if (file.path().extension() == extension)
    {
      std::cout << file.path().string() << std::endl;
      //write into excel
      excel << file.path().parent_path().string() + ";" + file.path().filename().string() + "\n";
    }
  }

  excel.close();

  return 1;
}
