#include <iostream>
#include <fstream>

int main() {
/*

   In python, we open a file using the open() function, passing it two args (filename and mode).

     open("file.txt", "r")  # for reading
     open("file.txt", "w")  # for overwriting
     open("file.txt", "a")  # for appending

   In C++, we do the same way, but with different syntax.

     std::fstream fd("file.txt", std::ios::in);   // for reading
     std::fstream fd("file.txt", std::ios::out);  // for overwriting
     std::fstream fd("file.txt", std::ios::app);  // for appending


    Python ->  C++

    r      ->  std::ios::in
    w      ->  std::ios::out
    a      ->  std::ios::app
    rb     ->  std::ios::binary | std::ios::in
    rw     ->  std::ios::binary | std::ios::out

*/

    std::string filename;
    std :: cout << "What is the filename? ";
    std :: cin >> filename;
    
    std::fstream fd(filename, std::ios::app);
    fd << "Hello\n";
    fd.close();
    

    std::fstream fd_reading(filename, std::ios::in);
    std::string contents;
    fd_reading >> contents;

    std::cout << "The contents of the file are:" << std::endl;
    std::cout << contents << std::endl;
    fd_reading.close();
}
