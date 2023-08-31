#include<bits/stdc++.h>
using namespace std;
int rCube [54];
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
            cout << rCube[i] << " ";
        else if(i < 18)
        {
            int array[12] = {0, 1, 2, 9, 10, 11, 18, 19, 20, 27, 28, 29};
            for(int j=0; j<12; j++)
                cout << rCube[i+array[j]] << " ";
            i+=2;
            if(i == 17)
                i = 44;
            else
                cout << "\n";
        }
        else
            cout << rCube[i] << " ";
        if(i == 2 || i == 5 || i == 8 || i == 38 || i == 41 || i == 44 || i == 47 || i == 50 || i == 53)
            cout << "\n";   
    }
    cout << "\n";
}
int main(){
    //rCubeInput();
    solvedInput();
    printrCube();

}