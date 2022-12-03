#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int key_logger(){


while(true){

    for(int i=41;i<0x5B;i++){
        if(GetAsyncKeyState(i)){

        char text=i;


cout<<text;
Sleep(200);

}


if(i==0x5A){
    i=41;

}


}}

return 0;}

int auto_clicker(){
    while(true){
if(GetAsyncKeyState(VK_NUMPAD0)){
    INPUT input={0};
    input.type=INPUT_MOUSE;
    input.mi.dwFlags=MOUSEEVENTF_LEFTDOWN;
    SendInput(1,&input,sizeof(input));
    Sleep(50);
    ZeroMemory(&input,sizeof(input));
    input.mi.dwFlags=MOUSEEVENTF_LEFTUP;
    SendInput(1,&input,sizeof(input));
}}
return 0;}



int main()
{
    HANDLE hConsole;
int k;

hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int option=0;
    cout<<"Choose:"<<endl<<"[1]-to run keylogger"<<endl<<"[2]-to run auto clicker"<<endl<<"[3]-to get cursor position"<<endl<<"[4]-to get rainbow!!!"<<endl;
    cin>>option;

    if(option==1){
            cout<<endl;
    key_logger();

}

   else if(option==2){
    auto_clicker();

}

else if(option==3){
    POINT p;
    while(true){
GetCursorPos(&p);

cout<<p.x<<":"<<p.y;

if(GetAsyncKeyState(VK_LBUTTON)){
    cout<<"Left button ";
    Sleep(10);
}


if(GetAsyncKeyState(VK_RBUTTON)){
    cout<<"Right button";
    Sleep(10);
}
cout<<endl;
if(GetAsyncKeyState(VK_NUMPAD0)){
    INPUT input={0};
    input.type=INPUT_MOUSE;
    input.mi.dwFlags=MOUSEEVENTF_LEFTDOWN;
    SendInput(1,&input,sizeof(input));
    cout<<"left down";
    Sleep(500);
    ZeroMemory(&input,sizeof(input));
    input.mi.dwFlags=MOUSEEVENTF_LEFTUP;
    SendInput(1,&input,sizeof(input));
}

if(GetAsyncKeyState(VK_NUMPAD1)){
    INPUT input={0};
    input.type=INPUT_KEYBOARD;
    input.ki.wVk=VkKeyScanA('a');
    SendInput(1,&input,sizeof(input));
    cout<<"a";
    Sleep(500);
    ZeroMemory(&input,sizeof(input));
    input.mi.dwFlags=KEYEVENTF_KEYUP;

    Sleep(500);
}
Sleep(500);

    }}
    else if(option==4){
        for(k = 1; k < 255; k++){

SetConsoleTextAttribute(hConsole, k);
cout << "Rain Bow!" << endl;
}
    }
    return 0;
}
