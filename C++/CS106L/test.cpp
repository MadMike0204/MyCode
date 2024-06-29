#include <unistd.h> 
#include <filesystem> 
#include <iostream> 
#include <string> 
using std::cin; 
using std::cout; 
using std::endl; 
using std::string; 
using std::filesystem::current_path; 
int main() {
    
    char tmp[256]; 
    getcwd(tmp, 256); 
    cout << "Current working directory: " << tmp << endl; 
    return EXIT_SUCCESS; 
}