#include<bits/stdc++.h>
#include <iostream>
#include <Windows.h>
using namespace std;

class rCube {
public: int rCube [54];
    //defining  white=1,orange=2,green=3,red=4,blue=5 and yellow=6 respectively
    void solvedInput(){
        int num=0;
        for(int i=0; i<54;i++){
            if(i%9==0)num++;
            rCube[i]=num;
        }
    }

    void rCubeInput(){
        freopen("CubeInput.txt","r",stdin);
        for(int i=0; i<54;i++){
            cin>>rCube[i];
        }
    }
    void color(int c){

        switch(c) {
        case 1:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            break;
        case 2:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            break;

        case 3:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            break;

        case 4:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            break;

        case 5:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            break;

        case 6:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            break;
        }
    }


    void printrCube(){
        for(int i=0; i<54; i++)
        {
            if(i == 0 || i == 3 || i == 6 || i == 45 || i == 48 || i == 51)
                cout << "      ";
            if(i < 9){
                color(rCube[i]);
                cout << rCube[i] << " ";
            }

            else if(i < 18)
            {
                int array[12] = {0, 1, 2, 9, 10, 11, 18, 19, 20, 27, 28, 29};
                for(int j=0; j<12; j++){
                    color(rCube[i+array[j]]);
                    cout << rCube[i+array[j]] << " ";
                }
                i+=2;
                if(i == 17)
                    i = 44;
                else
                    cout << "\n";
            }
            else{
                color(rCube[i]);
                cout << rCube[i] << " ";
            }
            if(i == 2 || i == 5 || i == 8 || i == 38 || i == 41 || i == 44 || i == 47 || i == 50 || i == 53)
                cout << "\n";
        }
        cout << "\n";
    }

    void turnUpCw()
    {
        int temp = rCube[1];
        rCube[1] = rCube[3];
        rCube[3] = rCube[7];
        rCube[7] = rCube[5];
        rCube[5] = temp;
        temp = rCube[0];
        rCube[0] = rCube[6];
        rCube[6] = rCube[8];
        rCube[8] = rCube[2];
        rCube[2] = temp;

        for(int i=0; i<3; i++)
        {
            temp = rCube[9+i];
            rCube[9+i] = rCube[18+i];
            rCube[18+i] = rCube[27+i];
            rCube[27+i] = rCube[36+i];
            rCube[36+i] = temp;
        }
    }
    void turnUpAcw(){
        turnDownCw();
        turnDownCw();
        turnDownCw();
    }

    void turnDownCw()
    {
        int temp = rCube[46];
        rCube[46] = rCube[48];
        rCube[48] = rCube[52];
        rCube[52] = rCube[50];
        rCube[50] = temp;
        temp = rCube[45];
        rCube[45] = rCube[51];
        rCube[51] = rCube[53];
        rCube[53] = rCube[47];
        rCube[47] = temp;

        for(int i=0; i<3; i++)
        {
            temp = rCube[15+i];
            rCube[15+i] = rCube[42+i];
            rCube[42+i] = rCube[33+i];
            rCube[33+i] = rCube[24+i];
            rCube[24+i] = temp;
        }
    }
    void turnDownAcw(){
        turnDownAcw();
        turnDownAcw();
        turnDownAcw();
    }

    void turnLeftCw()
    {
        int temp =  rCube[10];
        rCube[10] = rCube[12];
        rCube[12] = rCube[16];
        rCube[16] = rCube[14];
        rCube[14] = temp;
        temp = rCube[9];
        rCube[9] = rCube[15];
        rCube[15] = rCube[17];
        rCube[17] = rCube[11];
        rCube[11] = temp;

        for(int i=0; i<3; i++)
        {
            temp = rCube[0+(i*3)];
            rCube[0+(i*3)] = rCube[44-(i*3)];
            rCube[44-(i*3)] = rCube[45+(i*3)];
            rCube[45+(i*3)] = rCube[18+(i*3)];
            rCube[18+(i*3)] = temp;
        }
    }
    void turnLeftAcw(){
        turnLeftCw();
        turnDownCw();
        turnDownCw();
    }

    void turnRightCw()
    {
        int temp = rCube[28];
        rCube[28] = rCube[30];
        rCube[30] = rCube[34];
        rCube[34] = rCube[32];
        rCube[32] = temp;
        temp = rCube[27];
        rCube[27] = rCube[33];
        rCube[33] = rCube[35];
        rCube[35] = rCube[29];
        rCube[29] = temp;

        for(int i=0; i<3; i++)
        {
            temp = rCube[2+(i*3)];
            rCube[2+(i*3)] = rCube[20+(i*3)];
            rCube[20+(i*3)] = rCube[47+(i*3)];
            rCube[47+(i*3)] = rCube[42-(i*3)];
            rCube[42-(i*3)] = temp;
        }
    }
    void turnRightAcw(){
        turnRightCw();
        turnRightCw();
        turnRightCw();
    }

    void turnFrontCw()
    {
        int temp = rCube[19];
        rCube[19] = rCube[21];
        rCube[21] = rCube[25];
        rCube[25] = rCube[23];
        rCube[23] = temp;
        temp = rCube[18];
        rCube[18] = rCube[24];
        rCube[24] = rCube[26];
        rCube[26] = rCube[20];
        rCube[20] = temp;

        for(int i=0; i<3; i++)
        {
            temp = rCube[6+i];
            rCube[6+i] = rCube[17-(i*3)];
            rCube[17-(i*3)] = rCube[47-i];
            rCube[47-i] = rCube[27+(i*3)];
            rCube[27+(i*3)] = temp;
        }
    }
    void turnFrontAcw(){
        turnFrontCw();
        turnFrontCw();
        turnFrontCw();
    }

    void turnBackCw()
    {
        int temp = rCube[37];
        rCube[37] = rCube[39];
        rCube[39] = rCube[43];
        rCube[43] = rCube[41];
        rCube[41] = temp;
        temp = rCube[36];
        rCube[36] = rCube[42];
        rCube[42] = rCube[44];
        rCube[44] = rCube[38];
        rCube[38] = temp;

        for(int i=0; i<3; i++)
        {
            temp = rCube[0+i];
            rCube[0+i] = rCube[29+(i*3)];
            rCube[29+(i*3)] = rCube[53-i];
            rCube[53-i] = rCube[15-(i*3)];
            rCube[15-(i*3)] = temp;
        }
    }
    void turnBackAcw(){
        turnBackCw();
        turnBackCw();
        turnBackCw();
    }

};
int main(){
    // Handle STD_OUTPUT_HANDLE;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"\n\nR";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout<<"U";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"B";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<"I";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<"K";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout<<"'S";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<" C";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout<<"U";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"B";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<"E ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<"S";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout<<"O";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"L";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    cout<<"V";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"E";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<"R\n\n";


     rCube obj1;
     // obj1.rCubeInput();
     // obj1.printrCube();
     obj1.solvedInput();
     // obj1.turnFrontCw();
     // obj1.turnFrontAcw();
     obj1.turnUpCw();
     obj1.printrCube();
//     obj1.turnDownCw();
//     obj1.printrCube();
//     obj1.turnDownCw();
//     obj1.printrCube();
//     obj1.turnDownCw();
//     obj1.printrCube();
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}
