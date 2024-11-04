#include <iostream>
#include "config.h"

using namespace std;

int main(){
    cout << "Hello, World!" << endl;
    cout << PROJECT_NAME << " VERSION : " << PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR;
    return 0; 
}