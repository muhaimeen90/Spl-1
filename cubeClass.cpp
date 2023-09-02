#include<bits/stdc++.h>
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
        freopen("rCubeInput.txt","r",stdin);
        for(int i=0; i<54;i++){
            cin>>rCube[i];
        }           
    }

    void printrCube(){
        for(int i=0; i<54; i++)
        {
            if(i == 0 || i == 3 || i == 6 || i == 45 || i == 48 || i == 51)
                cout << "      ";
            if(i < 9)
                cout << rrCube[i] << " ";
            else if(i < 18)
            {
                int array[12] = {0, 1, 2, 9, 10, 11, 18, 19, 20, 27, 28, 29};
                for(int j=0; j<12; j++)
                    cout << rrCube[i+array[j]] << " ";
                i+=2;
                if(i == 17)
                    i = 44;
                else
                    cout << "\n";
            }
            else
                cout << rrCube[i] << " ";
            if(i == 2 || i == 5 || i == 8 || i == 38 || i == 41 || i == 44 || i == 47 || i == 50 || i == 53)
                cout << "\n";   
        }
        cout << "\n";
    }

    void turnUp()
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

    void turnDown()
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

    void turnLeft()
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

    void turnRight()
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

    void turnFront()
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

void turnBack()
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


};
int main(){
        // rrCubeInput();
        // printrrCube();
        // solvedInput();
        // printrrCube();
    rCube obj1;
    obj1.rCubeInput();
    obj1.printrCube();
    obj1.solvedInput();

}