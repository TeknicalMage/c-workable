#include <iostream>
#include <string>


#include <Windows.h>    

#include <chrono>
#include <thread>






using namespace std;

int hits = 0;


    //C Keypress
void C_Key_input(){
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan('c');
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(20);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    //C Keypress
};

    //Move Forward Input
void mvmt(){
    std::cout << "Move Forward \n\n";
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan('w'); 
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    //Keydown time determines Distance
    //std::this_thread::sleep_for(std::chrono::milliseconds(339213));

    //std::this_thread::sleep_for(std::chrono::milliseconds(11940)); | 51.587
    //std::this_thread::sleep_for(std::chrono::milliseconds(11540)); | 49.86
    //std::this_thread::sleep_for(std::chrono::milliseconds(11640)); | 50.291
    //std::this_thread::sleep_for(std::chrono::milliseconds(11600)); | 50.076 per input
    std::this_thread::sleep_for(std::chrono::milliseconds(11600000));
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
};
    //Move Forward Input        


void text(){
    
    string a;

    a = system("pwd");

    std::cout << a;

};


 
void tick(){
    while (true){
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            std::cout << hits;
            hits++;
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) { 
            std::thread forwardm(mvmt);
            forwardm.detach();
            std::cout << hits;
            hits++;
        }
        if (GetAsyncKeyState(VK_NUMPAD1)) { 
            std::thread whereami(text);
            std::cout << whereami.get_id();
            whereami.detach();
            std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
        }






    }



};

int main(){
    std::cout << "Script Start\n\n";
    tick();   
    return 0;

}



