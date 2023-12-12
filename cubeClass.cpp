#include<bits/stdc++.h>
#include <iostream>
#include <Windows.h>
using namespace std;

class rCube
{
public:
    int rCube [54];
    //defining  yellow=1,orange=2,green=3,red=4,blue=5 and white=6 respectively
    //centre block is 22 numbered element

    void solvedInput()
    {
        int num=0;
        for(int i=0; i<54; i++)
        {
            if(i%9==0)num++;
            rCube[i]=num;
        }
    }

    void rCubeInput()
    {
        freopen("CubeInput.txt","r",stdin);
        for(int i=0; i<54; i++)
        {
            cin>>rCube[i];
        }
    }
    bool checkValid()
{
	int diff;
	if(rCube[4] == 1 && rCube[13] == 2 && rCube[22] == 3 && rCube[31] == 4 && rCube[40] == 5 && rCube[49] == 6)
	{
		for(int i=0; i<4; i++)
		{
			diff = rCube[21] - rCube[14];
			if(diff == 1 || diff == -3)
				cubeLeft();
			else
				return false;
		}
		for(int i=0; i<4; i++)
		{
			diff = rCube[23] - rCube[30];
			if(diff == -1 || diff == 3)
				cubeLeft();
			else
				return false;
		}
		for(int i=0; i<4; i++)
		{
			diff = rCube[19] - rCube[7];
			if(diff == 2 || diff == 1 || diff == 3 || diff == 4)
				cubeLeft();
			else
				return false;
		}
		for(int i=0; i<4; i++)
		{
			diff = rCube[25] - rCube[46];
			if(diff == -3 || diff == -4 || diff == -2 || diff == -1)
				cubeLeft();
			else
				return false;
		}
	}
	else
		return false;
}
    void color(int c)
    {

        switch(c)
        {
        case 6:
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

        case 1:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            break;
        }
    }


    void printrCube()
    {
        for(int i=0; i<54; i++)
        {
            if(i == 0 || i == 3 || i == 6 || i == 45 || i == 48 || i == 51)
                cout << "      ";
            if(i < 9)
            {
                color(rCube[i]);
                cout << rCube[i] << " ";
            }

            else if(i < 18)
            {
                int array[12] = {0, 1, 2, 9, 10, 11, 18, 19, 20, 27, 28, 29};
                for(int j=0; j<12; j++)
                {
                    color(rCube[i+array[j]]);
                    cout << rCube[i+array[j]] << " ";
                }
                i+=2;
                if(i == 17)
                    i = 44;
                else
                    cout << "\n";
            }
            else
            {
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
        cout<<"U ";
    }
    void turnUpAcw()
    {
        turnUpCw();
        turnUpCw();
        turnUpCw();
        cout<<"U' ";
    }
    void turnUp2()
    {
        turnUpCw();
        turnUpCw();
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
        cout<<"D ";
    }
    void turnDownAcw()
    {
        turnDownAcw();
        turnDownAcw();
        turnDownAcw();
        cout<<"D' ";
    }
    void turnDown2()
    {
        turnDownCw();
        turnDownCw();
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
        cout<<"L ";
    }
    void turnLeftAcw()
    {
        turnLeftCw();
        turnLeftCw();
        turnLeftCw();
        cout<<"L' ";

    }
    void turnLeft2()
    {
        turnLeftCw();
        turnLeftCw();
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
        cout<<"R ";
    }
    void turnRightAcw()
    {
        turnRightCw();
        turnRightCw();
        turnRightCw();
        cout<<"R' ";
    }
    void turnRight2()
    {
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
        cout<<"F ";
    }
    void turnFrontAcw()
    {
        turnFrontCw();
        turnFrontCw();
        turnFrontCw();
        cout<<"F' ";
    }
    void turnFront2()
    {
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
        cout<<"B ";
    }

    void turnBackAcw()
    {
        turnBackCw();
        turnBackCw();
        turnBackCw();
        cout<<"B' ";
    }
    void turnBack2()
    {
        turnBackCw();
        turnBackCw();
    }
    void cubeLeft()
{
	//Turn up
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

	//Turn down'
	temp = rCube[46];
	rCube[46] = rCube[48];
	rCube[48] = rCube[52];
	rCube[52] = rCube[50];
	rCube[50] = temp;
	temp = rCube[45];
	rCube[45] = rCube[51];
	rCube[51] = rCube[53];
	rCube[53] = rCube[47];
	rCube[47] = temp;

	temp = rCube[46];
	rCube[46] = rCube[48];
	rCube[48] = rCube[52];
	rCube[52] = rCube[50];
	rCube[50] = temp;
	temp = rCube[45];
	rCube[45] = rCube[51];
	rCube[51] = rCube[53];
	rCube[53] = rCube[47];
	rCube[47] = temp;

	temp = rCube[46];
	rCube[46] = rCube[48];
	rCube[48] = rCube[52];
	rCube[52] = rCube[50];
	rCube[50] = temp;
	temp = rCube[45];
	rCube[45] = rCube[51];
	rCube[51] = rCube[53];
	rCube[53] = rCube[47];
	rCube[47] = temp;

	//Turn rest to left
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = rCube[9+i+(j*3)];
			rCube[9+i+(j*3)] = rCube[18+i+(j*3)];
			rCube[18+i+(j*3)] = rCube[27+i+(j*3)];
			rCube[27+i+(j*3)] = rCube[36+i+(j*3)];
			rCube[36+i+(j*3)] = temp;
		}
	}
}

void cubeRight()
{
	//Turn up'
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

	temp = rCube[1];
	rCube[1] = rCube[3];
	rCube[3] = rCube[7];
	rCube[7] = rCube[5];
	rCube[5] = temp;
	temp = rCube[0];
	rCube[0] = rCube[6];
	rCube[6] = rCube[8];
	rCube[8] = rCube[2];
	rCube[2] = temp;

	temp = rCube[1];
	rCube[1] = rCube[3];
	rCube[3] = rCube[7];
	rCube[7] = rCube[5];
	rCube[5] = temp;
	temp = rCube[0];
	rCube[0] = rCube[6];
	rCube[6] = rCube[8];
	rCube[8] = rCube[2];
	rCube[2] = temp;

	//Turn down
	temp = rCube[46];
	rCube[46] = rCube[48];
	rCube[48] = rCube[52];
	rCube[52] = rCube[50];
	rCube[50] = temp;
	temp = rCube[45];
	rCube[45] = rCube[51];
	rCube[51] = rCube[53];
	rCube[53] = rCube[47];
	rCube[47] = temp;

	//Turn rest to right
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = rCube[15+i-(j*3)];
			rCube[15+i-(j*3)] = rCube[42+i-(j*3)];
			rCube[42+i-(j*3)] = rCube[33+i-(j*3)];
			rCube[33+i-(j*3)] = rCube[24+i-(j*3)];
			rCube[24+i-(j*3)] = temp;
		}
	}
}

void cubeUp()
{
	//Turn right
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

	//Turn left'
	temp = rCube[10];
	rCube[10] = rCube[12];
	rCube[12] = rCube[16];
	rCube[16] = rCube[14];
	rCube[14] = temp;
	temp = rCube[9];
	rCube[9] = rCube[15];
	rCube[15] = rCube[17];
	rCube[17] = rCube[11];
	rCube[11] = temp;

	temp = rCube[10];
	rCube[10] = rCube[12];
	rCube[12] = rCube[16];
	rCube[16] = rCube[14];
	rCube[14] = temp;
	temp = rCube[9];
	rCube[9] = rCube[15];
	rCube[15] = rCube[17];
	rCube[17] = rCube[11];
	rCube[11] = temp;

	temp = rCube[10];
	rCube[10] = rCube[12];
	rCube[12] = rCube[16];
	rCube[16] = rCube[14];
	rCube[14] = temp;
	temp = rCube[9];
	rCube[9] = rCube[15];
	rCube[15] = rCube[17];
	rCube[17] = rCube[11];
	rCube[11] = temp;

	//Turn the rest to up
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = rCube[2+(i*3)-j];
			rCube[2+(i*3)-j] = rCube[20+(i*3)-j];
			rCube[20+(i*3)-j] = rCube[47+(i*3)-j];
			rCube[47+(i*3)-j] = rCube[42-(i*3)+j];
			rCube[42-(i*3)+j] = temp;
		}
	}
}

void cubeDown()
{
	//Turn left
	int temp = rCube[10];
	rCube[10] = rCube[12];
	rCube[12] = rCube[16];
	rCube[16] = rCube[14];
	rCube[14] = temp;
	temp = rCube[9];
	rCube[9] = rCube[15];
	rCube[15] = rCube[17];
	rCube[17] = rCube[11];
	rCube[11] = temp;

	//Turn right'
	temp = rCube[28];
	rCube[28] = rCube[30];
	rCube[30] = rCube[34];
	rCube[34] = rCube[32];
	rCube[32] = temp;
	temp = rCube[27];
	rCube[27] = rCube[33];
	rCube[33] = rCube[35];
	rCube[35] = rCube[29];
	rCube[29] = temp;

	temp = rCube[28];
	rCube[28] = rCube[30];
	rCube[30] = rCube[34];
	rCube[34] = rCube[32];
	rCube[32] = temp;
	temp = rCube[27];
	rCube[27] = rCube[33];
	rCube[33] = rCube[35];
	rCube[35] = rCube[29];
	rCube[29] = temp;

	temp = rCube[28];
	rCube[28] = rCube[30];
	rCube[30] = rCube[34];
	rCube[34] = rCube[32];
	rCube[32] = temp;
	temp = rCube[27];
	rCube[27] = rCube[33];
	rCube[33] = rCube[35];
	rCube[35] = rCube[29];
	rCube[29] = temp;

	//Turn the rest to down
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
		{
			temp = rCube[0+(i*3)+j];
			rCube[0+(i*3)+j] = rCube[44-(i*3)-j];
			rCube[44-(i*3)-j] = rCube[45+(i*3)+j];
			rCube[45+(i*3)+j] = rCube[18+(i*3)+j];
			rCube[18+(i*3)+j] = temp;
		}
	}
}

//void RCube::turnCubeSideToLeft()
//{
//	//Turn front'
//	int temp = rCube[19];
//	rCube[19] = rCube[21];
//	rCube[21] = rCube[25];
//	rCube[25] = rCube[23];
//	rCube[23] = temp;
//	temp = rCube[18];
//	rCube[18] = rCube[24];
//	rCube[24] = rCube[26];
//	rCube[26] = rCube[20];
//	rCube[20] = temp;
//
//	temp = rCube[19];
//	rCube[19] = rCube[21];
//	rCube[21] = rCube[25];
//	rCube[25] = rCube[23];
//	rCube[23] = temp;
//	temp = rCube[18];
//	rCube[18] = rCube[24];
//	rCube[24] = rCube[26];
//	rCube[26] = rCube[20];
//	rCube[20] = temp;
//
//	temp = rCube[19];
//	rCube[19] = rCube[21];
//	rCube[21] = rCube[25];
//	rCube[25] = rCube[23];
//	rCube[23] = temp;
//	temp = rCube[18];
//	rCube[18] = rCube[24];
//	rCube[24] = rCube[26];
//	rCube[26] = rCube[20];
//	rCube[20] = temp;
//
//	//Turn back
//	temp = rCube[37];
//	rCube[37] = rCube[39];
//	rCube[39] = rCube[43];
//	rCube[43] = rCube[41];
//	rCube[41] = temp;
//	temp = rCube[36];
//	rCube[36] = rCube[42];
//	rCube[42] = rCube[44];
//	rCube[44] = rCube[38];
//	rCube[38] = temp;
//
//	//Turn the rest to side left
//	for(int j=0; j<3; j++)
//	{
//		for(int i=0; i<3; i++)
//		{
//			temp = rCube[0+i+(j*3)];
//			rCube[0+i+(j*3)] = rCube[29+(i*3)-j];
//			rCube[29+(i*3)-j] = rCube[53-i-(j*3)];
//			rCube[53-i-(j*3)] = rCube[15-(i*3)+j];
//			rCube[15-(i*3)+j] = temp;
//		}
//	}
//}
//
//void RCube::turnCubeSideToRight()
//{
//	//Turn front
//	int temp = rCube[19];
//	rCube[19] = rCube[21];
//	rCube[21] = rCube[25];
//	rCube[25] = rCube[23];
//	rCube[23] = temp;
//	temp = rCube[18];
//	rCube[18] = rCube[24];
//	rCube[24] = rCube[26];
//	rCube[26] = rCube[20];
//	rCube[20] = temp;
//
//	//Turn back'
//	temp = rCube[37];
//	rCube[37] = rCube[39];
//	rCube[39] = rCube[43];
//	rCube[43] = rCube[41];
//	rCube[41] = temp;
//	temp = rCube[36];
//	rCube[36] = rCube[42];
//	rCube[42] = rCube[44];
//	rCube[44] = rCube[38];
//	rCube[38] = temp;
//
//	temp = rCube[37];
//	rCube[37] = rCube[39];
//	rCube[39] = rCube[43];
//	rCube[43] = rCube[41];
//	rCube[41] = temp;
//	temp = rCube[36];
//	rCube[36] = rCube[42];
//	rCube[42] = rCube[44];
//	rCube[44] = rCube[38];
//	rCube[38] = temp;
//
//	temp = rCube[37];
//	rCube[37] = rCube[39];
//	rCube[39] = rCube[43];
//	rCube[43] = rCube[41];
//	rCube[41] = temp;
//	temp = rCube[36];
//	rCube[36] = rCube[42];
//	rCube[42] = rCube[44];
//	rCube[44] = rCube[38];
//	rCube[38] = temp;
//
//	for(int j=0; j<3; j++)
//	{
//		for(int i=0; i<3; i++)
//		{
//			temp = rCube[6+i-(j*3)];
//			rCube[6+i-(j*3)] = rCube[17-(i*3)-j];
//			rCube[17-(i*3)-j] = rCube[47-i+(j*3)];
//			rCube[47-i+(j*3)] = rCube[27+(i*3)+j];
//			rCube[27+(i*3)+j] = temp;
//		}
//	}
//}
    void turnMiddleCw()
    {
        cubeDown();
        turnRightCw();
        turnLeftAcw();
    }
    void turnMiddleAcw()
    {
        turnMiddleCw();
        turnMiddleCw();
        turnMiddleCw();
    }

    void turnEquatorCw()
    {
        cubeRight();
        turnUpCw();
        turnDownAcw();
    }
    void turnEquatorAcw()
    {
        turnEquatorCw();
        turnEquatorCw();
        turnEquatorCw();
    }
    void turnStandingCw()
    {
        cubeRight();
        turnFrontAcw();
        turnBackCw();
    }
    void turnStandingAcw()
    {
        turnStandingCw();
        turnStandingCw();
        turnStandingCw();
    }

    void alignCenter(int centre)
    {
        while(rCube[22]!=centre)
        {
            cubeUp();

            if(rCube[22]==centre)break;
            cubeRight();

        }

    }
    void solver()
    {
        cout<<"Move Lists: ";
        //     whiteCross();
        //     cout<<"\n";
        // }

        // void whiteCross(){

        //     alignCenter(1);
        //     while(rCube[19]!=1 && rCube[21]!=1 && rCube[23]!=1 && rCube[25]!=1){

        //     }
        // }
        bool finish = false, step1 = false, step2 = false, step3 = false, step4 = false, step5 = false, step6 = false, step7 = false;
        int diff, diff2, temp;
        int currentSide[] = {2, 3, 4, 5};
        int i = 1, counter;

        //Step 1: Solve white cross
        while(!step1)
        {
            //Check is white cross and corresponding color match
            if(rCube[46] == 6 && rCube[48] == 6 && rCube[50] == 6 && rCube[52] == 6)
            {
                bool side1 = false, side2 = false, side3 = false, side4 = false;
                for(int j=0; j<4; j++)
                {
                    if(rCube[16] == currentSide[j] && rCube[13] == currentSide[j])
                    {
                        side1 = true;
                        break;
                    }
                    else
                        side1 = false;
                }
                for(int j=0; j<4; j++)
                {
                    if(rCube[25] == currentSide[j] && rCube[22] == currentSide[j])
                    {
                        side2 = true;
                        break;
                    }
                    else
                        side2 = false;
                }
                for(int j=0; j<4; j++)
                {
                    if(rCube[34] == currentSide[j] && rCube[31] == currentSide[j])
                    {
                        side3 = true;
                        break;
                    }
                    else
                        side3 = false;
                }
                for(int j=0; j<4; j++)
                {
                    if(rCube[43] == currentSide[j] && rCube[40] == currentSide[j])
                    {
                        side4 = true;
                        break;
                    }
                    else
                        side4 = false;
                }
                if(side1 && side2 && side3 && side4)
                    step1 = true;
            }
            if(!step1)
            {
                while(!finish)
                {
                    //Checking white cross
                    if(rCube[46] == 6 && rCube[48] == 6 && rCube[50] == 6 && rCube[52] == 6)
                        finish = true;
                    else
                    {
                        //Check top
                        if(rCube[1] == 6) //First edge
                        {
                            diff = currentSide[i] - rCube[37];
                            if(diff == 1 || diff == -3)
                            {
                                turnUpCw();
                                turnLeft2();

                            }
                            else if(diff == 0)
                            {
                                turnUp2();
                                turnFront2();

                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnUpCw();
                                turnRight2();

                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnBack2();

                            }
                        }
                        else if(rCube[3] == 6) //Second edge
                        {
                            diff = currentSide[i] - rCube[10];
                            if(diff == 1 || diff == -3)
                            {
                                turnLeft2();

                            }
                            else if(diff == 0)
                            {
                                turnUpAcw();
                                turnFront2();

                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnUp2();
                                turnRight2();

                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnUpCw();
                                turnBack2();

                            }
                        }
                        else if(rCube[5] == 6) //Third edge
                        {
                            diff = currentSide[i] - rCube[28];
                            if(diff == 1 || diff == -3)
                            {
                                turnUp2();
                                turnLeft2();

                            }
                            else if(diff == 0)
                            {
                                turnUpCw();
                                turnFront2();

                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnRight2();

                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnUpAcw();
                                turnBack2();

                            }
                        }
                        else if(rCube[7] == 6) //Fourth edge
                        {
                            diff = currentSide[i] - rCube[19];
                            if(diff == 1 || diff == -3)
                            {
                                turnUpCw();
                                turnLeft2();

                            }
                            else if(diff == 0)
                            {
                                turnFront2();

                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnUpAcw();
                                turnRight2();

                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnUp2();
                                turnBack2();

                            }
                        }
                        else if(rCube[19] == 6) //Check side first edge
                        {
                            diff = currentSide[i] - rCube[7];
                            if(diff == 0)
                            {
                                turnUpCw();
                                turnLeftCw();
                                turnFrontAcw();
                                turnLeftAcw();
                                turnUpAcw();

                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnFrontCw();
                                turnRightAcw();
                                turnFrontAcw();

                            }
                            else if(diff == 1 || diff == -3)
                            {
                                turnFrontAcw();
                                turnLeftCw();
                                turnFrontCw();

                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnUpCw();
                                turnLeftAcw();
                                turnBackCw();
                                turnLeftCw();
                                turnUpAcw();

                            }
                        }
                        else if(rCube[21] == 6) //Second edge
                        {
                            diff = currentSide[i] - rCube[14];
                            if(diff == 0)
                            {
                                turnLeftAcw();
                                turnUpAcw();
                                turnFront2();
                                turnUpCw();
                                turnLeftCw();

                            }
                            else if(diff == 1 || diff == -3)
                            {
                                turnLeftCw();

                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnLeftAcw();
                                turnUp2();
                                turnRight2();
                                turnUp2();
                                turnLeftCw();

                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnLeftAcw();
                                turnUpCw();
                                turnBack2();
                                turnUpAcw();
                                turnLeftCw();

                            }
                            else if(rCube[23] == 6) //Third edge
                            {
                                diff = currentSide[i] - rCube[30];
                                if(diff == 0)
                                {
                                    turnRightCw();
                                    turnUpCw();
                                    turnFront2();
                                    turnUpAcw();
                                    turnRightAcw();
                                }
                                    else if(diff == 1 || diff == -3)
                                    {
                                        turnRightCw();
                                        turnUp2();
                                        turnLeft2();
                                        turnUp2();
                                        turnRightAcw();


                                    }
                                    else if(diff == -1 || diff == 3)
                                    {
                                        turnRightAcw();

                                    }
                                    else if(diff == -2 || diff == 2)
                                    {
                                        turnRightCw();
                                        turnUpAcw();
                                        turnBack2();
                                        turnUpCw();
                                        turnRightAcw();

                                    }
                                }
                                else if(rCube[25] == 6) //Fourth edge
                                {
                                    diff = currentSide[i] - rCube[46];
                                    if(diff == 0)
                                    {
                                        turnFrontAcw();
                                        turnRightCw();
                                        turnUpCw();
                                        turnFront2();
                                        turnRightAcw();

                                    }
                                    else if(diff == 1 || diff == -3)
                                    {
                                        turnFrontCw();
                                        turnLeftCw();
                                        turnFrontAcw();

                                    }
                                    else if(diff == -1 || diff == 3)
                                    {
                                        turnFrontAcw();
                                        turnRightAcw();
                                        turnFrontCw();

                                    }
                                    else if(diff == -2 || diff == 2)
                                    {
                                        turnFrontAcw();
                                        turnRightCw();
                                        turnUpAcw();
                                        turnBack2();
                                        turnRightAcw();

                                    }
                                }
                                cubeLeft();

                                i++;
                                if(i == 4)
                                    i = 0;
                            }
                        }
                        if(finish)
                        {

                            if(rCube[25] != rCube[22])
                            {
                                diff = rCube[22] - rCube[25];
                                if(diff == 1 || diff == -3)
                                {
                                    turnMiddleAcw();
                                    turnStandingCw();
                                    turnUpCw();
                                    turnStandingAcw();
                                    turnUp2();
                                    turnMiddleCw();

                                }
                                else if(diff == -1 || diff == 3)
                                {
                                    turnMiddleAcw();
                                    turnStandingAcw();
                                    turnUpAcw();
                                    turnStandingCw();
                                    turnUp2();
                                    turnMiddleCw();

                                }
                                else if(diff == 2 || diff == -2)
                                {
                                    turnMiddleAcw();
                                    turnUpCw();
                                    turnMiddleCw();
                                    turnMiddleCw();
                                    turnUpCw();
                                    turnMiddleCw();
                                    turnMiddleCw();
                                    turnUpCw();
                                    turnMiddleCw();

                                }
                            }
                            cubeLeft();

                        }
                    }
                }

            }

        cout<<"\n";
        }
};
        int main()
        {
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
            obj1.rCubeInput();
            // obj1.printrCube();
            // obj1.solvedInput();
            // obj1.turnFrontCw();
            // obj1.turnFrontAcw();
//     obj1.turnUpCw();
            // obj1.printrCube();
//     obj1.turnDownCw();
//     obj1.printrCube();
//     obj1.turnDownCw();
//     obj1.printrCube();
//     obj1.turnDownCw();
//     obj1.printrCube();
            // obj1.cubeUp();
            // obj1.cubeRight();
            obj1.printrCube();
            obj1.solver();
            obj1.printrCube();
            // obj1.alignCenter(6);
//            obj1.printrCube();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        }
