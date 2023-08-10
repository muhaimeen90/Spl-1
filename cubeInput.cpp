#include<bits/stdc++.h>
using namespace std;
int cube [6][3][3];
//defining  white=1,red=2,green=3,yellow=4,blue=5 and orange=6 respectively
void cubeInput(){
    for(int i=0; i<6;i++)
        for(int j=0; j<3; j++)
            for(int k=0;k<3;k++)
                cin>>cube[i][j][k];
}
void printCube(){
    for(int i=0; i<6;i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << cube[i][j][k];
                cout<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}
int main(){
    cubeInput();
    printCube();

}