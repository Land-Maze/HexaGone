#include <python3.7/Python.h>


void pythonInitial(){
    


}

void sendPacket(const char* IP, const char* Port){
    
    const char* script_path = "./UDP.py";

    Py_Initialize();
    PyRun_SimpleFileEx(fopen(script_path, "r"), script_path, 1);
    Py_Finalize();

    
}

