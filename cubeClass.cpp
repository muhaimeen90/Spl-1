#include<bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include<graphics.h>
using namespace std;

class rCube
{
public:
    int rCube [54];
    //defining  yellow=1,orange=2,green=3,red=4,blue=5 and white=6 respectively
    //centre block is 22 numbered element
    int moves=0;
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
    void helpPage()
    {   setcolor(GREEN);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
        outtextxy(650,200,"HELP PAGE!");
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        outtextxy(650,300,"F- FRONT");
        outtextxy(650,350,"B- BACK");
        outtextxy(650,400,"L- LEFT");
        outtextxy(650,450,"R- RIGHT");
        outtextxy(650,500,"U- UP");
        outtextxy(650,550,"D- DOWN");
    }
    void drawRectangleWithBorder(int x1, int y1, int x2, int y2, int borderWidth, int fillColor, int borderColor)
    {
        // Set the fill color
        setfillstyle(SOLID_FILL, fillColor);
        // Draw the filled rectangle
        bar(x1, y1, x2, y2);

        // Draw the border
        setcolor(borderColor);
        for (int i = 0; i < borderWidth; ++i)
        {
            rectangle(x1 + i, y1 + i, x2 - i, y2 - i);
        }
    }

    void color(int x1,int y1,int x2,int y2,int color)
    {
        switch(color)
        {
        case 1:
            drawRectangleWithBorder(x1,y1,x2,y2,4,YELLOW,BLACK);
            break;
        case 2:
            drawRectangleWithBorder(x1,y1,x2,y2,4,MAGENTA,BLACK);
            break;

        case 3:
            drawRectangleWithBorder(x1,y1,x2,y2,4,GREEN,BLACK);
            break;

        case 4:
            drawRectangleWithBorder(x1,y1,x2,y2,4,RED,BLACK);
            break;

        case 5:
            drawRectangleWithBorder(x1,y1,x2,y2,4,BLUE,BLACK);
            break;

        case 6:
            drawRectangleWithBorder(x1,y1,x2,y2,4,WHITE,BLACK);
            break;
        }
    }
    void printCube()
    {
        int x1=0,y1=0,x2=50,y2=50;
        for(int i=0; i<54; i++)
        {
            if(i == 0 || i == 3 || i == 6 || i == 45 || i == 48 || i == 51)
            {
                x1=x1+150;
                x2=x2+150;
//                y1=y1+75;
//                y2=y2+75;
            }
            if(i<9)
            {
                color(x1,y1,x2,y2,rCube[i]);
                x1=x1+50;
                x2=x2+50;
//            y1+=50;
//            y2+=50;
            }
            else if(i < 18)
            {
                int array[12] = {0, 1, 2, 9, 10, 11, 18, 19, 20, 27, 28, 29};
                for(int j=0; j<12; j++)
                {
                    color(x1,y1,x2,y2,rCube[i+array[j]]);
                    x1=x1+50;
                    x2=x2+50;

                }
                i+=2;
                if(i == 17)
                    i = 44;
                else
                {
                    x1=0;
                    x2=50;
                    y1=y1+50;
                    y2=y2+50;
                }
            }
            else
            {
                color(x1,y1,x2,y2,rCube[i]);
                x1+=50;
                x2+=50;
            }

            if(i == 2 || i == 5 || i == 8 || i == 38 || i == 41 || i == 44 || i == 47 || i == 50 || i == 53)
            {
                x1=0;
                x2=50;
                y1=y1+50;
                y2=y2+50;
            }
        }
    }

    void color2(int c)
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
                color2(rCube[i]);
                cout << rCube[i] << " ";
            }

            else if(i < 18)
            {
                int array[12] = {0, 1, 2, 9, 10, 11, 18, 19, 20, 27, 28, 29};
                for(int j=0; j<12; j++)
                {
                    color2(rCube[i+array[j]]);
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
                color2(rCube[i]);
                cout << rCube[i] << " ";
            }
            if(i == 2 || i == 5 || i == 8 || i == 38 || i == 41 || i == 44 || i == 47 || i == 50 || i == 53)
                cout << "\n";
        }
        cout << "\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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

        moves++;
    }
    void turnCUp()
    {
        turnUp();
        turnUp();
        turnUp();
    }
    void turnUp2()
    {
        turnUp();
        turnUp();
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
    void turnCDown()
    {
        turnDown();
        turnDown();
        turnDown();

    }
    void turnDown2()
    {
        turnDown();
        turnDown();
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
    void turnCLeft()
    {
        turnLeft();
        turnLeft();
        turnLeft();


    }
    void turnLeft2()
    {
        turnLeft();
        turnLeft();
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
    void turnCRight()
    {
        turnRight();
        turnRight();
        turnRight();

    }
    void turnRight2()
    {
        turnRight();
        turnRight();

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
    void turnCFront()
    {
        turnFront();
        turnFront();
        turnFront();

    }
    void turnFront2()
    {
        turnFront();
        turnFront();
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

    void turnCBack()
    {
        turnBack();
        turnBack();
        turnBack();

    }
    void turnBack2()
    {
        turnBack();
        turnBack();
    }
    void turnCubeToLeft()
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

    void turnCubeToRight()
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

    void turnCubeToUp()
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

    void turnCubeToDown()
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

    void turnCubeSideToLeft()
    {
        //Turn front'
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

        temp = rCube[19];
        rCube[19] = rCube[21];
        rCube[21] = rCube[25];
        rCube[25] = rCube[23];
        rCube[23] = temp;
        temp = rCube[18];
        rCube[18] = rCube[24];
        rCube[24] = rCube[26];
        rCube[26] = rCube[20];
        rCube[20] = temp;

        temp = rCube[19];
        rCube[19] = rCube[21];
        rCube[21] = rCube[25];
        rCube[25] = rCube[23];
        rCube[23] = temp;
        temp = rCube[18];
        rCube[18] = rCube[24];
        rCube[24] = rCube[26];
        rCube[26] = rCube[20];
        rCube[20] = temp;

        //Turn back
        temp = rCube[37];
        rCube[37] = rCube[39];
        rCube[39] = rCube[43];
        rCube[43] = rCube[41];
        rCube[41] = temp;
        temp = rCube[36];
        rCube[36] = rCube[42];
        rCube[42] = rCube[44];
        rCube[44] = rCube[38];
        rCube[38] = temp;

        //Turn the rest to side left
        for(int j=0; j<3; j++)
        {
            for(int i=0; i<3; i++)
            {
                temp = rCube[0+i+(j*3)];
                rCube[0+i+(j*3)] = rCube[29+(i*3)-j];
                rCube[29+(i*3)-j] = rCube[53-i-(j*3)];
                rCube[53-i-(j*3)] = rCube[15-(i*3)+j];
                rCube[15-(i*3)+j] = temp;
            }
        }
    }

    void turnCubeSideToRight()
    {
        //Turn front
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

        //Turn back'
        temp = rCube[37];
        rCube[37] = rCube[39];
        rCube[39] = rCube[43];
        rCube[43] = rCube[41];
        rCube[41] = temp;
        temp = rCube[36];
        rCube[36] = rCube[42];
        rCube[42] = rCube[44];
        rCube[44] = rCube[38];
        rCube[38] = temp;

        temp = rCube[37];
        rCube[37] = rCube[39];
        rCube[39] = rCube[43];
        rCube[43] = rCube[41];
        rCube[41] = temp;
        temp = rCube[36];
        rCube[36] = rCube[42];
        rCube[42] = rCube[44];
        rCube[44] = rCube[38];
        rCube[38] = temp;

        temp = rCube[37];
        rCube[37] = rCube[39];
        rCube[39] = rCube[43];
        rCube[43] = rCube[41];
        rCube[41] = temp;
        temp = rCube[36];
        rCube[36] = rCube[42];
        rCube[42] = rCube[44];
        rCube[44] = rCube[38];
        rCube[38] = temp;

        for(int j=0; j<3; j++)
        {
            for(int i=0; i<3; i++)
            {
                temp = rCube[6+i-(j*3)];
                rCube[6+i-(j*3)] = rCube[17-(i*3)-j];
                rCube[17-(i*3)-j] = rCube[47-i+(j*3)];
                rCube[47-i+(j*3)] = rCube[27+(i*3)+j];
                rCube[27+(i*3)+j] = temp;
            }
        }
    }
    void turnMiddle()
    {
        turnCubeToDown();
        turnRight();
        turnCLeft();
    }
    void turnMiddle2()
    {
        turnMiddle();
        turnMiddle();
    }
    void turnCMiddle()
    {
        turnMiddle();
        turnMiddle();
        turnMiddle();
    }

    void turnEquator()
    {
        turnCubeToRight();
        turnUp();
        turnCDown();
    }
    void turnCEquator()
    {
        turnEquator();
        turnEquator();
        turnEquator();
    }
    void turnStanding()
    {
        turnCubeToRight();
        turnCFront();
        turnBack();
    }
    void turnCStanding()
    {
        turnStanding();
        turnStanding();
        turnStanding();
    }

    void displayTurn(vector<int> sequence)
    {
        cout << "Reduced sequence: " << sequence.size() << endl;
        int x=650;
        for(int i=0; i<sequence.size(); i++)
        {
            if(sequence[i] == 100){
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(650,200,"White Cross! ");
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
                outtextxy(650,250,"Solved Step 1: ");
                x=650;
                printCube();
            }
            else if(sequence[i] == 200){
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(650,200,"White Corners! ");
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
                outtextxy(650,250,"Solved Step 2: ");
                x=650;
                printCube();
            }
            else if(sequence[i] == 300){
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(650,200,"Second Layer! ");
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
                outtextxy(650,250,"Solved Step 3: ");
                x=650;
                printCube();
            }
                else if(sequence[i] == 400){
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(650,200," Layer! ");
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
                outtextxy(650,250,"Solved Step 4: ");
                x=650;
                printCube();
                }
            else if(sequence[i] == 500)
                cout << "\nSolved step 5\n\n";
            else if(sequence[i] == 600)
                cout << "\nSolved step 6\n\n";
            else if(sequence[i] == 700)
                cout << "\nSolved step 7\n";
            else if(sequence[i] == 0)
                cout << "U";
            else if(sequence[i] == 1)
                cout << "D";
            else if(sequence[i] == 2)
                cout << "L";
            else if(sequence[i] == 3)
                cout << "R";
            else if(sequence[i] == 4)
                cout << "F";
            else if(sequence[i] == 5)
                cout << "B";
            else if(sequence[i] == 6)
                cout << "M";
            else if(sequence[i] == 7)
                cout << "E";
            else if(sequence[i] == 8)
                cout << "S";
            else if(sequence[i] == 9)
                cout << "U'";
            else if(sequence[i] == 10)
                cout << "D'";
            else if(sequence[i] == 11)
                cout << "L'";
            else if(sequence[i] == 12)
                cout << "R'";
            else if(sequence[i] == 13)
                cout << "F'";
            else if(sequence[i] == 14)
                cout << "B'";
            else if(sequence[i] == 15)
                cout << "M'";
            else if(sequence[i] == 16)
                cout << "E'";
            else if(sequence[i] == 17)
                cout << "S'";
            else if(sequence[i] == 18)
                cout << "U2";
            else if(sequence[i] == 19)
                cout << "D2";
            else if(sequence[i] == 20)
                cout << "L2";
            else if(sequence[i] == 21)
                cout << "R2";
            else if(sequence[i] == 22)
                cout << "F2";
            else if(sequence[i] == 23)
                cout << "B2";
            else if(sequence[i] == 24)
                cout << "M2";
            else if(sequence[i] == 25)
                cout << "E2";
            else if(sequence[i] == 26)
                cout << "S2";
            else if(sequence[i] == 27)
                cout << "X";
            else if(sequence[i] == 28)
                cout << "X'";
            else if(sequence[i] == 29)
                cout << "Y";
            else if(sequence[i] == 30)
                cout << "Y'";
            else if(sequence[i] == 31)
                cout << "Z";
            else if(sequence[i] == 32)
                cout << "Z'";
            else if(sequence[i] == 33)
                cout << "X2";
            else if(sequence[i] == 34)
                cout << "Y2";
            else if(sequence[i] == 35)
                cout << "Z2";
        }
        cout << "\n";
    }

    void reduce(vector<int>& sequence)
    {
        if(sequence.size() > 1)
        {
            if(sequence.size() > 3)
            {
                for(int i=0; i<sequence.size()-3; i++)
                {
                    if(sequence.size() > 3)
                    {
                        if((sequence[i] == sequence[i+1]) && (sequence[i] == sequence[i+2]) && (sequence[i] == sequence[i+3]) && sequence.size() > 3) //Remove 4 same move
                        {
                            sequence.erase(sequence.begin()+i);
                            sequence.erase(sequence.begin()+i);
                            sequence.erase(sequence.begin()+i);
                            sequence.erase(sequence.begin()+i);
                        }
                    }
                    else
                        break;
                }
            }
            if(sequence.size() > 2)
            {
                for(int i=0; i<sequence.size()-2; i++)
                {
                    if(sequence.size() > 2)
                    {
                        if(sequence[i] == sequence[i+1] && sequence[i] == sequence[i+2])
                        {
                            sequence.erase(sequence.begin()+i);
                            sequence.erase(sequence.begin()+i);
                            if(sequence[i] < 9)
                                sequence[i] = sequence[i] + 9;
                            else if(sequence[i] < 18)
                                sequence[i] = sequence[i] - 9;
                            else if(sequence[i] > 26)
                            {
                                if(sequence[i] == 27 || sequence[i] == 29 || sequence[i] == 31)
                                    sequence[i] = sequence[i] + 1;
                                else if(sequence[i] == 28 || sequence[i] == 30 || sequence[i] == 32)
                                    sequence[i] = sequence[i] - 1;
                            }
                        }
                    }
                }
            }
            if(sequence.size() > 1)
            {
                for(int i=0; i<sequence.size()-1; i++)
                {
                    if(sequence.size() > 1)
                    {
                        if((sequence[i]+9 == sequence[i+1]) && sequence[i] < 9) //To reduce clockwise with anti-clockwise
                        {
                            sequence.erase(sequence.begin()+i);
                            sequence.erase(sequence.begin()+i);
                        }
                        if((sequence[i]-9 == sequence[i+1]) && sequence[i] < 18) //To reduce anti-clockwise with clockwise
                        {
                            sequence.erase(sequence.begin()+i);
                            sequence.erase(sequence.begin()+i);
                        }
                        if((sequence[i]+1 == sequence[i+1]) && sequence[i] > 26 && sequence[i] < 33) //X X' Y Y' Z Z'
                        {
                            sequence.erase(sequence.begin()+i);
                            sequence.erase(sequence.begin()+i);
                        }
                        if(sequence[i] == sequence[i+1] && sequence[i] < 9) //To merge 2 same move (Clockwise)
                        {
                            sequence.erase(sequence.begin()+i);
                            sequence[i] = sequence[i] + 18;
                        }
                        if(sequence[i] == sequence[i+1] && sequence[i] > 8 && sequence[i] < 18) //To merge 2 same move (Counter Clockwise)
                        {
                            sequence.erase(sequence.begin()+i);
                            sequence[i] = sequence[i] + 9;
                        }
                        if(sequence[i] == sequence[i+1] && sequence[i] > 26 && sequence[i] < 33) //To merge 2 same move (X Y Z)
                        {
                            sequence.erase(sequence.begin()+i);
                            if(sequence[i] == 27 || sequence[i] == 28) //X / X'
                                sequence[i] = 33;
                            else if(sequence[i] == 29 || sequence[i] == 30) //Y / Y'
                                sequence[i] = 34;
                            else if(sequence[i] == 31 || sequence[i] == 32) //Z / Z'
                                sequence[i] = 35;
                        }
                    }
                    else
                        break;
                }
            }
        }
    }
    bool solver(vector<int>& sequence)
    {

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
                                turnCUp();
                                turnLeft2();
                                sequence.push_back(9);
                                sequence.push_back(20);
                            }
                            else if(diff == 0)
                            {
                                turnUp2();
                                turnFront2();
                                sequence.push_back(18);
                                sequence.push_back(22);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnUp();
                                turnRight2();
                                sequence.push_back(0);
                                sequence.push_back(21);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnBack2();
                                sequence.push_back(23);
                            }
                        }
                        else if(rCube[3] == 6) //Second edge
                        {
                            diff = currentSide[i] - rCube[10];
                            if(diff == 1 || diff == -3)
                            {
                                turnLeft2();
                                sequence.push_back(20);
                            }
                            else if(diff == 0)
                            {
                                turnCUp();
                                turnFront2();
                                sequence.push_back(9);
                                sequence.push_back(22);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnUp2();
                                turnRight2();
                                sequence.push_back(18);
                                sequence.push_back(21);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnUp();
                                turnBack2();
                                sequence.push_back(0);
                                sequence.push_back(23);
                            }
                        }
                        else if(rCube[5] == 6) //Third edge
                        {
                            diff = currentSide[i] - rCube[28];
                            if(diff == 1 || diff == -3)
                            {
                                turnUp2();
                                turnLeft2();
                                sequence.push_back(18);
                                sequence.push_back(20);
                            }
                            else if(diff == 0)
                            {
                                turnUp();
                                turnFront2();
                                sequence.push_back(0);
                                sequence.push_back(22);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnRight2();
                                sequence.push_back(21);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnCUp();
                                turnBack2();
                                sequence.push_back(9);
                                sequence.push_back(23);
                            }
                        }
                        else if(rCube[7] == 6) //Fourth edge
                        {
                            diff = currentSide[i] - rCube[19];
                            if(diff == 1 || diff == -3)
                            {
                                turnUp();
                                turnLeft2();
                                sequence.push_back(0);
                                sequence.push_back(20);
                            }
                            else if(diff == 0)
                            {
                                turnFront2();
                                sequence.push_back(22);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnCUp();
                                turnRight2();
                                sequence.push_back(9);
                                sequence.push_back(21);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnUp2();
                                turnBack2();
                                sequence.push_back(18);
                                sequence.push_back(23);
                            }
                        }
                        else if(rCube[19] == 6) //Check side first edge
                        {
                            diff = currentSide[i] - rCube[7];
                            if(diff == 0)
                            {
                                turnUp();
                                turnLeft();
                                turnCFront();
                                turnCLeft();
                                turnCUp();
                                int array[] = {0,2,13,11,9};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnFront();
                                turnCRight();
                                turnCFront();
                                int array[] = {4,12,13};
                                sequence.insert(sequence.end(), array, array+3);
                            }
                            else if(diff == 1 || diff == -3)
                            {
                                turnCFront();
                                turnLeft();
                                turnFront();
                                int array[] = {13,2,4};
                                sequence.insert(sequence.end(), array, array+3);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnUp();
                                turnCLeft();
                                turnBack();
                                turnLeft();
                                turnCUp();
                                int array[] = {0,11,5,2,9};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                        }
                        else if(rCube[21] == 6) //Second edge
                        {
                            diff = currentSide[i] - rCube[14];
                            if(diff == 0)
                            {
                                turnCLeft();
                                turnCUp();
                                turnFront2();
                                turnUp();
                                turnLeft();
                                int array[] = {11,9,22,0,2};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                            else if(diff == 1 || diff == -3)
                            {
                                turnLeft();
                                sequence.push_back(2);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnCLeft();
                                turnUp2();
                                turnRight2();
                                turnUp2();
                                turnLeft();
                                int array[] = {11,18,21,18,2};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnCLeft();
                                turnUp();
                                turnBack2();
                                turnCUp();
                                turnLeft();
                                int array[] = {11,0,23,9,2};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                        }
                        else if(rCube[23] == 6) //Third edge
                        {
                            diff = currentSide[i] - rCube[30];
                            if(diff == 0)
                            {
                                turnRight();
                                turnUp();
                                turnFront2();
                                turnCUp();
                                turnCRight();
                                int array[] = {3,0,22,9,12};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                            else if(diff == 1 || diff == -3)
                            {
                                turnRight();
                                turnUp2();
                                turnLeft2();
                                turnUp2();
                                turnCRight();
                                int array[] = {3,18,20,18,12};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnCRight();
                                sequence.push_back(12);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnRight();
                                turnCUp();
                                turnBack2();
                                turnUp();
                                turnCRight();
                                int array[] = {3,9,23,0,12};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                        }
                        else if(rCube[25] == 6) //Fourth edge
                        {
                            diff = currentSide[i] - rCube[46];
                            if(diff == 0)
                            {
                                turnCFront();
                                turnRight();
                                turnUp();
                                turnFront2();
                                turnCRight();
                                int array[] = {13,3,0,22,12};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                            else if(diff == 1 || diff == -3)
                            {
                                turnFront();
                                turnLeft();
                                turnCFront();
                                int array[] = {4,2,13};
                                sequence.insert(sequence.end(), array, array+3);
                            }
                            else if(diff == -1 || diff == 3)
                            {
                                turnCFront();
                                turnCRight();
                                turnFront();
                                int array[] = {13,12,4};
                                sequence.insert(sequence.end(), array, array+3);
                            }
                            else if(diff == -2 || diff == 2)
                            {
                                turnCFront();
                                turnRight();
                                turnCUp();
                                turnBack2();
                                turnCRight();
                                int array[] = {13,3,9,23,12};
                                sequence.insert(sequence.end(), array, array+5);
                            }
                        }
                        turnCubeToLeft();
                        sequence.push_back(29);
                        i++;
                        if(i == 4)
                            i = 0;
                    }
                }
                if(finish)
                {
                    //Check bottom
                    if(rCube[25] != rCube[22])
                    {
                        diff = rCube[22] - rCube[25];
                        if(diff == 1 || diff == -3)
                        {
                            turnCMiddle();
                            turnStanding();
                            turnUp();
                            turnCStanding();
                            turnUp2();
                            turnMiddle();
                            int array[] = {15,8,0,17,18,6};
                            sequence.insert(sequence.end(), array, array+6);
                        }
                        else if(diff == -1 || diff == 3)
                        {
                            turnCMiddle();
                            turnCStanding();
                            turnCUp();
                            turnStanding();
                            turnUp2();
                            turnMiddle();
                            int array[] = {15,17,9,8,18,6};
                            sequence.insert(sequence.end(), array, array+6);
                        }
                        else if(diff == 2 || diff == -2)
                        {
                            turnCMiddle();
                            turnUp();
                            turnMiddle2();
                            turnUp();
                            turnMiddle2();
                            turnUp();
                            turnMiddle();
                            int array[] = {15,0,24,0,24,0,6};
                            sequence.insert(sequence.end(), array, array+7);
                        }
                    }
                    turnCubeToLeft();
                    sequence.push_back(29);
                }
            }
        }
        finish = false;
        sequence.push_back(100);

        //Step 2: Solve white corners
        //To make white side on top
        turnCubeSideToLeft();
        turnCubeSideToLeft();
        sequence.push_back(32);
        sequence.push_back(32);

        while(!step2)
        {
            if(rCube[0] == 6 && rCube[2] == 6 && rCube[6] == 6 && rCube[8] == 6)
            {
                bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
                for(int j = 0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if((rCube[38] == currentSide[temp]) && (rCube[9] == currentSide[j]) && (rCube[10] == currentSide[j]))
                    {
                        corner1 = true;
                        break;
                    }
                    else
                        corner1 = false;
                }
                for(int j = 0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if((rCube[29] == currentSide[temp]) && (rCube[36] == currentSide[j]) && (rCube[37] == currentSide[j]))
                    {
                        corner2 = true;
                        break;
                    }
                    else
                        corner2 = false;
                }
                for(int j = 0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if((rCube[11] == currentSide[temp]) && (rCube[18] == currentSide[j]) && (rCube[19] == currentSide[j]))
                    {
                        corner3 = true;
                        break;
                    }
                    else
                        corner3 = false;
                }
                for(int j = 0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if((rCube[20] == currentSide[temp]) && (rCube[27] == currentSide[j]) && (rCube[28] == currentSide[j]))
                    {
                        corner4 = true;
                        break;
                    }
                    else
                        corner4 = false;
                }
                if(corner1 && corner2 && corner3 && corner4)
                    step2 = true;
            }
            if(!step2)
            {
                while(!finish)
                {
                    if(rCube[0] == 6 && rCube[2] == 6 && rCube[6] == 6 && rCube[8] == 6)
                        finish = true;
                    else
                    {
                        //Make orange side the front
                        if(rCube[45] == 6) //Top first corner
                        {
                            diff = currentSide[i] - rCube[24];
                            diff2 = currentSide[i] - rCube[17];

                            if(diff == 0 && diff2 == 1)
                            {
                                turnDown();
                                turnCRight();
                                turnDown2();
                                turnRight();
                                turnDown();
                                turnCRight();
                                turnCDown();
                                turnRight();
                                int array[] = {1,12,19,3,1,12,10,3};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if((diff == 1 && diff2 == 2) || (diff == 1 && diff2 == -2))
                            {
                                turnDown2();
                                turnCBack();
                                turnDown2();
                                turnBack();
                                turnDown();
                                turnCBack();
                                turnCDown();
                                turnBack();
                                int array[] = {19,14,19,5,1,14,10,5};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if((diff == 2 && diff2 == -1) || (diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3))
                            {
                                turnCDown();
                                turnCLeft();
                                turnDown2();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                turnCDown();
                                turnLeft();
                                int array[] = {10,11,19,2,1,11,10,2};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if(diff == -1 && diff2 == 0)
                            {
                                turnCFront();
                                turnDown2();
                                turnFront();
                                turnDown();
                                turnCFront();
                                turnCDown();
                                turnFront();
                                int array[] = {13,19,4,1,13,10,4};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                        }
                        else if(rCube[47] == 6) //Top second corner
                        {
                            diff = currentSide[i] - rCube[26];
                            diff2 = currentSide[i] - rCube[33];

                            if(diff == 1 && diff2 == 0)
                            {
                                turnCRight();
                                turnDown2();
                                turnRight();
                                turnDown();
                                turnCRight();
                                turnCDown();
                                turnRight();
                                int array[] = {12,19,3,1,12,10,3};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                            else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1))
                            {
                                turnDown();
                                turnCBack();
                                turnDown2();
                                turnBack();
                                turnDown();
                                turnCBack();
                                turnCDown();
                                turnBack();
                                int array[] = {1,14,19,5,1,14,10,5};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if((diff == -1 && diff2 == -2) || (diff == -1 && diff2 == 2))
                            {
                                turnDown2();
                                turnCLeft();
                                turnDown2();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                turnCDown();
                                turnLeft();
                                int array[] = {19,11,19,2,1,11,10,2};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if(diff == 0 && diff2 == -1)
                            {
                                turnCDown();
                                turnLeft();
                                turnDown2();
                                turnCLeft();
                                turnCDown();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                int array[] = {10,2,19,11,10,2,1,11};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                        }
                        else if(rCube[51] == 6) //Top third corner
                        {
                            diff = currentSide[i] - rCube[44];
                            diff2 = currentSide[i] - rCube[15];

                            if((diff == 1 && diff2 == 0) || (diff == -1 && diff2 == 0))
                            {
                                turnDown2();
                                turnCRight();
                                turnDown2();
                                turnRight();
                                turnDown();
                                turnCRight();
                                turnCDown();
                                turnRight();
                                int array[] = {19,12,19,3,1,12,10,3};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if((diff == -2 && diff2 == 1) || (diff == -2 && diff2 == -3) || (diff == 2 && diff2 == 1))
                            {
                                turnCDown();
                                turnRight();
                                turnCDown();
                                turnCRight();
                                turnDown2();
                                turnRight();
                                turnDown();
                                turnCRight();
                                int array[] = {10,3,10,12,19,3,1,12};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if((diff == -2 && diff2 == -2) || (diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 && diff2 == 2))
                            {
                                turnCLeft();
                                turnDown2();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                turnCDown();
                                turnLeft();
                                int array[] = {11,19,2,1,11,10,2};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                            else if((diff == 0 && diff2 == -1) || (diff == 0 && diff2 == 3))
                            {
                                turnDown();
                                turnLeft();
                                turnDown2();
                                turnCLeft();
                                turnCDown();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                int array[] = {1,2,19,11,10,2,1,11};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                        }
                        else if(rCube[53] == 6) //Top fourth corner
                        {
                            diff = currentSide[i] - rCube[42];
                            diff2 = currentSide[i] - rCube[35];

                            if((diff == 0 && diff2 == 1) || (diff == 0 && diff2 == -3))
                            {
                                turnCDown();
                                turnCRight();
                                turnDown2();
                                turnRight();
                                turnDown();
                                turnCRight();
                                turnCDown();
                                turnRight();
                                int array[] = {10,12,19,3,1,12,10,3};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if((diff == 1 && diff2 == -2) || (diff == -3 && diff2 == -2) || (diff == 1 && diff2 == 2))
                            {
                                turnRight();
                                turnDown2();
                                turnCRight();
                                turnCDown();
                                turnRight();
                                turnDown();
                                turnCRight();
                                int array[] = {3,19,12,10,3,1,12};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                            else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
                            {
                                turnDown();
                                turnBack();
                                turnDown2();
                                turnCBack();
                                turnCDown();
                                turnBack();
                                turnDown();
                                turnCBack();
                                int array[] = {1,5,19,14,10,5,1,14};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                            else if((diff == -1 && diff2 == 0) || (diff == 3 && diff2 == 0))
                            {
                                turnDown2();
                                turnLeft();
                                turnDown2();
                                turnCLeft();
                                turnCDown();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                int array[] = {19,2,19,11,10,2,1,11};
                                sequence.insert(sequence.end(), array, array+8);
                            }
                        }
                        else if(rCube[18] == 6) //Side first corner
                        {
                            diff = currentSide[i] - rCube[6];
                            diff2 = currentSide[i] - rCube[11];

                            if((diff == -1 && diff2 == 0) || (diff == 3 && diff2 == 0))
                            {
                                turnLeft();
                                turnCDown();
                                turnCLeft();
                                turnDown();
                                turnLeft();
                                turnCDown();
                                turnCLeft();
                                int array[] = {2,10,11,1,2,10,11};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                            else if((diff == 0 && diff2 == 1) || (diff == 0 & diff2 == -3))
                            {
                                turnLeft();
                                turnCDown();
                                turnCLeft();
                                turnDown();
                                turnCRight();
                                turnCDown();
                                turnRight();
                                int array[] = {2,10,11,1,12,10,3};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                            else if((diff == 1 && diff2 == -2) || (diff == 1 && diff2 == 2) || (diff == -3 && diff2 == -2))
                            {
                                turnLeft();
                                turnCDown();
                                turnCLeft();
                                turnDown2();
                                turnCBack();
                                turnCDown();
                                turnBack();
                                int array[] = {2,10,11,19,14,10,5};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                            else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
                            {
                                turnLeft();
                                turnCDown();
                                turnCLeft();
                                turnBack();
                                turnCDown();
                                turnCBack();
                                int array[] = {2,10,11,5,10,14};
                                sequence.insert(sequence.end(), array, array+6);
                            }
                        }
                        else if(rCube[20] == 6) //Side second corner
                        {
                            diff = currentSide[i] - rCube[8];
                            diff2 = currentSide[i] - rCube[27];

                            if((diff == 1 && diff2 == 0) || (diff == -1 && diff2 == 0) || (diff == -3 && diff2 == 0))
                            {
                                turnCRight();
                                turnDown();
                                turnRight();
                                turnCDown();
                                turnCRight();
                                turnDown();
                                turnRight();
                                int array[] = {12,1,3,10,12,1,3};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                            else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1) || (diff == -2 && diff2 == -3))
                            {
                                turnCRight();
                                turnDown();
                                turnRight();
                                turnCBack();
                                turnDown();
                                turnBack();
                                int array[] = {12,1,3,14,1,5};
                                sequence.insert(sequence.end(), array, array+6);
                            }
                            else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 & diff2 == 2))
                            {
                                turnCRight();
                                turnDown();
                                turnRight();
                                turnCLeft();
                                turnDown2();
                                turnLeft();
                                int array[] = {12,1,3,11,19,2};
                                sequence.insert(sequence.end(), array, array+6);
                            }
                            else if((diff == 0 && diff2 == -1) || (diff == 0 && diff2 == 3) || (diff == 0 && diff2 == 1))
                            {
                                turnCRight();
                                turnDown();
                                turnRight();
                                turnCDown();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                int array[] = {12,1,3,10,2,1,11};
                                sequence.insert(sequence.end(), array, array+7);
                            }
                        }
                        else if(rCube[24] == 6) //Side third corner
                        {
                            diff = currentSide[i] - rCube[45];
                            diff2 = currentSide[i] - rCube[17];

                            if((diff == 1 && diff2 == 0) || (diff == -3 && diff2 == 0))
                            {
                                turnDown();
                                turnCRight();
                                turnCDown();
                                turnRight();
                                int array[] = {1,12,10,3};
                                sequence.insert(sequence.end(), array, array+4);
                            }
                            else if((diff == -2 && diff2 == 1) || (diff == 2 && diff2 == 1) || (diff == -2 && diff2 == -3))
                            {
                                turnDown2();
                                turnCBack();
                                turnCDown();
                                turnBack();
                                int array[] = {19,14,10,5};
                                sequence.insert(sequence.end(), array, array+4);
                            }
                            else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 && diff2 == 2))
                            {
                                turnCDown();
                                turnCLeft();
                                turnCDown();
                                turnLeft();
                                int array[] = {10,11,10,2};
                                sequence.insert(sequence.end(), array, array+4);
                            }
                            else if((diff == 0 && diff2 == -1) || (diff == 0 && diff2 == 3))
                            {
                                turnDown();
                                turnLeft();
                                turnCDown();
                                turnCLeft();
                                int array[] = {1,2,10,11};
                                sequence.insert(sequence.end(), array, array+4);
                            }
                        }
                        else if(rCube[26] == 6) //Side fourth corner
                        {
                            diff = currentSide[i] - rCube[47];
                            diff2 = currentSide[i] - rCube[33];

                            if((diff == 0 && diff2 == 1) || (diff == 0 && diff2 == -3))
                            {
                                turnCDown();
                                turnCRight();
                                turnDown();
                                turnRight();
                                int array[] = {10,12,1,3};
                                sequence.insert(sequence.end(), array, array+4);
                            }
                            else if((diff == 1 && diff2 == -2) || (diff == 1 && diff2 == 2) || (diff == -3 && diff2 == -2))
                            {
                                turnCBack();
                                turnDown();
                                turnBack();
                                int array[] = {14,1,5};
                                sequence.insert(sequence.end(), array, array+3);
                            }
                            else if((diff == -2 && diff2 == -1) || (diff == 2 && diff2 == 3) || (diff == 2 && diff2 == -1))
                            {
                                turnCLeft();
                                turnDown2();
                                turnLeft();
                                int array[] = {11,19,2};
                                sequence.insert(sequence.end(), array, array+3);
                            }
                            else if((diff == -1 && diff2 == 0) || (diff == 3 && diff2 == 0))
                            {
                                turnCDown();
                                turnLeft();
                                turnDown();
                                turnCLeft();
                                int array[] = {10, 2, 1, 11};
                                sequence.insert(sequence.end(), array, array+4);
                            }
                        }
                        turnCubeToLeft();
                        sequence.push_back(29);
                        i--;
                        if(i == -1)
                            i = 3;
                    }
                }
                if(finish)
                {
                    //Orient the corners
                    finish = false;

                    if(i+1 == 4)
                        temp = 0;
                    else
                        temp = i+1;

                    if(rCube[18] != rCube[22] && rCube[11] != rCube[13])
                    {
                        diff = rCube[22] - rCube[18];
                        diff2 = rCube[22] - rCube[11];

                        if((diff == 1 && diff2 == 0) || (diff == -3 && diff2 == 0))
                        {
                            turnLeft();
                            turnDown();
                            turnCLeft();
                            turnCRight();
                            turnCDown();
                            turnRight();
                            turnLeft();
                            turnDown();
                            turnCLeft();
                            int array[] = {2,1,11,12,10,3,2,1,11};
                            sequence.insert(sequence.end(), array, array+9);
                        }
                        else if((diff == -2 && diff2 == 1) || (diff == -2 && diff2 == -3) || (diff == 2 && diff2 == 1) || (diff == 2 && diff2 == -3))
                        {
                            turnLeft();
                            turnRight();
                            turnDown2();
                            turnCLeft();
                            turnCRight();
                            int array[] = {2,3,19,11,12};
                            sequence.insert(sequence.end(), array, array+5);
                        }
                        else if((diff == -1 && diff2 == -2) || (diff == 3 && diff2 == 2) || (diff == -1 && diff2 == 2))
                        {
                            turnLeft();
                            turnDown2();
                            turnCLeft();
                            turnDown();
                            turnCLeft();
                            turnCDown();
                            turnLeft();
                            turnDown2();
                            turnLeft();
                            turnDown();
                            turnCLeft();
                            int array[] = {2,19,11,1,11,10,2,19,2,1,11};
                            sequence.insert(sequence.end(), array, array+11);
                        }
                    }
                    turnCubeToLeft();
                    sequence.push_back(29);
                    i--;
                    if(i == -1)
                        i = 3;
                }
            }
        }
        finish = false;
        sequence.push_back(200);

        //Step 3: Solve second layers
        counter = 1;
        while(!step3)
        {
            if((rCube[12] == rCube[13] && rCube[14] == rCube[13]) && (rCube[21] == rCube[22] && rCube[23] == rCube[22]) && (rCube[30] == rCube[31] && rCube[32] == rCube[31]) && (rCube[39] == rCube[40] && rCube[41] == rCube[40]))
                step3 = true;

            if(!step3)
            {
                if((rCube[25] != 1) && (rCube[46] != 1)) //Must not be yellow
                {
                    counter = 1;
                    while(rCube[25] != rCube[22])
                    {
                        turnCubeToLeft();
                        turnDown();
                        sequence.push_back(29);
                        sequence.push_back(1);
                    }
                    if((rCube[46] != rCube[13]) && (rCube[46] == rCube[31])) //Right side
                    {
                        turnCDown();
                        turnCRight();
                        turnDown();
                        turnRight();
                        turnDown();
                        turnFront();
                        turnCDown();
                        turnCFront();
                        int array[] = {10,12,1,3,1,4,10,13};
                        sequence.insert(sequence.end(), array, array+8);
                    }
                    else if((rCube[46] == rCube[13]) && (rCube[46] != rCube[31])) //Left side
                    {
                        turnDown();
                        turnLeft();
                        turnCDown();
                        turnCLeft();
                        turnCDown();
                        turnCFront();
                        turnDown();
                        turnFront();
                        int array[] = {1,2,10,11,10,13,1,4};
                        sequence.insert(sequence.end(), array, array+8);
                    }
                }
                else
                {
                    turnCubeToLeft();
                    sequence.push_back(29);
                    counter++;
                    if(counter == 5)
                    {
                        turnCDown();
                        turnCRight();
                        turnDown();
                        turnRight();
                        turnDown();
                        turnFront();
                        turnCDown();
                        turnCFront();
                        int array[] = {10,12,1,3,1,4,10,13};
                        sequence.insert(sequence.end(), array, array+8);
                        counter = 1;
                    }
                }
            }
        }
        sequence.push_back(300);

        //Step 4: Solve yellow cross
        //Make yellow side on top
        turnCubeSideToLeft();
        turnCubeSideToLeft();
        sequence.push_back(32);
        sequence.push_back(32);

        while(!step4)
        {
            if(rCube[1] == 1 && rCube[3] == 1 && rCube[5] == 1 && rCube[7] == 1) //Yellow cross
                step4 = true;
            else
            {
                //Yellow Line, yellow L, yellow dot
                if((rCube[3] == 1 && rCube[5] == 1) || (rCube[1] == 1 && rCube[3] == 1) || (rCube[1] != 1 && rCube[3] != 1 && rCube[5] != 1 && rCube[7] != 1))
                {
                    turnFront();
                    turnRight();
                    turnUp();
                    turnCRight();
                    turnCUp();
                    turnCFront();
                    int array[] = {4,3,0,12,9,13};
                    sequence.insert(sequence.end(), array, array+6);
                }
                else //Yellow line or L is facing wrong direction
                {
                    turnCubeToLeft();
                    sequence.push_back(29);
                }
            }
        }
        sequence.push_back(400);

        //Step 5: Fix yellow edges
        counter = 1;
        while(!step5)
        {
            if(rCube[10] == rCube[13] && rCube[19] == rCube[22] && rCube[28] == rCube[31] && rCube[37] == rCube[40])
                step5 = true;
            else
            {
                if(counter == 3)
                {
                    turnUp2();
                    sequence.push_back(18);
                    counter = 0;
                }
                if((rCube[19] != rCube[22]) && (rCube[10] != rCube[13]))
                {
                    turnRight();
                    turnUp();
                    turnCRight();
                    turnUp();
                    turnRight();
                    turnUp2();
                    turnCRight();
                    turnUp();
                    int array[] = {3,0,12,0,3,18,12,0};
                    sequence.insert(sequence.end(), array, array+8);
                    counter++;
                }
                else if((rCube[10] == rCube[13]) && (rCube[19] != rCube[22]) && (rCube[28] == rCube[31]) && (rCube[37] != rCube[40]))
                {
                    turnRight();
                    turnUp();
                    turnCRight();
                    turnUp();
                    turnRight();
                    turnUp2();
                    turnCRight();
                    turnUp();
                    turnUp2();
                    turnRight();
                    turnUp();
                    turnCRight();
                    turnUp();
                    turnRight();
                    turnUp2();
                    turnCRight();
                    int array[] = {3,0,12,0,3,18,12,0,18,3,0,12,0,3,18,12};
                    sequence.insert(sequence.end(), array, array+16);
                }
                else
                {
                    turnCubeToRight();
                    sequence.push_back(30);
                }
            }
        }
        sequence.push_back(500);

        i = 1;
        //To reset the orange side as the front
        while(rCube[22] != currentSide[1])
        {
            turnCubeToLeft();
            sequence.push_back(29);
        }

        finish =false;
        //Step 6: Position yellow corner
        while(!step6)
        {
            bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
            int pos, pos1 = -1, pos2 = -1, pos3 = -1, pos4 = -1;
            for(int j=0; j<4; j++)
            {
                if(j+1 == 4)
                    temp = 0;
                else
                    temp = j+1;
                if(((rCube[8] == 1 && rCube[20] == currentSide[j] && rCube[27] == currentSide[temp]) || (rCube[8] == currentSide[temp] && rCube[20] == 1 && rCube[27] == currentSide[j]) || (rCube[8] == currentSide[j] && rCube[20] == currentSide[temp] && rCube[27] == 1)) && rCube[22] == currentSide[j])
                {
                    corner1 = true;
                    pos1 = j;
                    break;
                }
                else
                    corner1 = false;
            }
            for(int j=0; j<4; j++)
            {
                if(j+1 == 4)
                    temp = 0;
                else
                    temp = j+1;
                if(((rCube[2] == 1 && rCube[29] == currentSide[j] && rCube[36] == currentSide[temp]) || (rCube[2] == currentSide[temp] && rCube[29] == 1 && rCube[36] == currentSide[j]) || (rCube[2] == currentSide[j] && rCube[29] == currentSide[temp] && rCube[36] == 1)) && rCube[31] == currentSide[j])
                {
                    corner2 = true;
                    pos2 = j;
                    break;
                }
                else
                    corner2 = false;
            }
            for(int j=0; j<4; j++)
            {
                if(j+1 == 4)
                    temp = 0;
                else
                    temp = j+1;
                if(((rCube[0] == 1 && rCube[38] == currentSide[j] && rCube[9] == currentSide[temp]) || (rCube[0] == currentSide[temp] && rCube[38] == 1 && rCube[9] == currentSide[j]) || (rCube[0] == currentSide[j] && rCube[38] == currentSide[temp] && rCube[9] == 1)) && rCube[40] == currentSide[j])
                {
                    corner3 = true;
                    pos3 = j;
                    break;
                }
                else
                    corner3 = false;
            }
            for(int j=0; j<4; j++)
            {
                if(j+1 == 4)
                    temp = 0;
                else
                    temp = j+1;
                if(((rCube[6] == 1 && rCube[11] == currentSide[j] && rCube[18] == currentSide[temp]) || (rCube[6] == currentSide[temp] && rCube[11] == 1 && rCube[18] == currentSide[j]) || (rCube[6] == currentSide[j] && rCube[11] == currentSide[temp] && rCube[18] == 1)) && rCube[13] == currentSide[j])
                {
                    corner4 = true;
                    pos4 = j;
                    break;
                }
                else
                    corner4 = false;
            }
            if(corner1 && corner2 && corner3 && corner4) //All corner is position correctly
                step6 = true;
            else if(!corner1 && !corner2 && !corner3 && !corner4) //All corner is position incorrectly
            {
                turnUp();
                turnRight();
                turnCUp();
                turnCLeft();
                turnUp();
                turnCRight();
                turnCUp();
                turnLeft();
                int array[] = {0,3,9,11,0,12,9,2};
                sequence.insert(sequence.end(), array, array+8);
            }
            else if(corner1 || corner2 || corner3 || corner4)
            {
                while(!finish)
                {
                    if(corner1)
                        pos = pos1;
                    else if(corner2)
                        pos = pos2;
                    else if(corner3)
                        pos = pos3;
                    else if(corner4)
                        pos = pos4;

                    if(i-1 == -1)
                        temp = 3;
                    else
                        temp = i-1;
                    if(i-pos == 0)
                    {
                        turnUp();
                        turnRight();
                        turnCUp();
                        turnCLeft();
                        turnUp();
                        turnCRight();
                        turnCUp();
                        turnLeft();
                        int array[] = {0,3,9,11,0,12,9,2};
                        sequence.insert(sequence.end(), array, array+8);

                        for(int j=0; j<4; j++)
                        {
                            if(j+1 == 4)
                                temp = 0;
                            else
                                temp = j+1;
                            if(((rCube[8] == 1 && rCube[20] == currentSide[j] && rCube[27] == currentSide[temp]) || (rCube[8] == currentSide[temp] && rCube[20] == 1 && rCube[27] == currentSide[j]) || (rCube[8] == currentSide[j] && rCube[20] == currentSide[temp] && rCube[27] == 1)) && rCube[22] == currentSide[j])
                            {
                                corner1 = true;
                                pos1 = j;
                                break;
                            }
                            else
                                corner1 = false;
                        }
                        for(int j=0; j<4; j++)
                        {
                            if(j+1 == 4)
                                temp = 0;
                            else
                                temp = j+1;
                            if(((rCube[2] == 1 && rCube[29] == currentSide[j] && rCube[36] == currentSide[temp]) || (rCube[2] == currentSide[temp] && rCube[29] == 1 && rCube[36] == currentSide[j]) || (rCube[2] == currentSide[j] && rCube[29] == currentSide[temp] && rCube[36] == 1)) && rCube[31] == currentSide[j])
                            {
                                corner2 = true;
                                pos2 = j;
                                break;
                            }
                            else
                                corner2 = false;
                        }
                        for(int j=0; j<4; j++)
                        {
                            if(j+1 == 4)
                                temp = 0;
                            else
                                temp = j+1;
                            if(((rCube[0] == 1 && rCube[38] == currentSide[j] && rCube[9] == currentSide[temp]) || (rCube[0] == currentSide[temp] && rCube[38] == 1 && rCube[9] == currentSide[j]) || (rCube[0] == currentSide[j] && rCube[38] == currentSide[temp] && rCube[9] == 1)) && rCube[40] == currentSide[j])
                            {
                                corner3 = true;
                                pos3 = j;
                                break;
                            }
                            else
                                corner3 = false;
                        }
                        for(int j=0; j<4; j++)
                        {
                            if(j+1 == 4)
                                temp = 0;
                            else
                                temp = j+1;
                            if(((rCube[6] == 1 && rCube[11] == currentSide[j] && rCube[18] == currentSide[temp]) || (rCube[6] == currentSide[temp] && rCube[11] == 1 && rCube[18] == currentSide[j]) || (rCube[6] == currentSide[j] && rCube[11] == currentSide[temp] && rCube[18] == 1)) && rCube[13] == currentSide[j])
                            {
                                corner4 = true;
                                pos4 = j;
                                break;
                            }
                            else
                                corner4 = false;
                        }
                        if(corner1 && corner2 && corner3 && corner4) //All corner is position correctly
                            finish = true;
                    }
                    else
                    {
                        turnCubeToLeft();
                        sequence.push_back(29);
                        i++;
                        if(i == 4)
                            i = 0;
                    }
                }
            }
        }
        finish = false;
        sequence.push_back(600);

        //Step 7: Orient yellow corner
        while(!step7)
        {
            if(rCube[0] == 1 && rCube[2] == 1 && rCube[6] == 1 && rCube[8] == 1)
            {
                bool corner1 = false, corner2 = false, corner3 = false, corner4 = false;
                for(int j=0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if(rCube[20] == currentSide[j] && rCube[27] == currentSide[temp] && rCube[22] == currentSide[j])
                    {
                        corner1 = true;
                        break;
                    }
                    else
                        corner1 = false;
                }
                for(int j=0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if(rCube[29] == currentSide[j] && rCube[36] == currentSide[temp] && rCube[31] == currentSide[j])
                    {
                        corner2 = true;
                        break;
                    }
                    else
                        corner2 = false;
                }
                for(int j=0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if(rCube[38] == currentSide[j] && rCube[9] == currentSide[temp] && rCube[40] == currentSide[j])
                    {
                        corner3 = true;
                        break;
                    }
                    else
                        corner3 = false;
                }
                for(int j=0; j<4; j++)
                {
                    if(j+1 == 4)
                        temp = 0;
                    else
                        temp = j+1;
                    if(rCube[11] == currentSide[j] && rCube[18] == currentSide[temp] && rCube[13] == currentSide[j])
                    {
                        corner4 = true;
                        break;
                    }
                    else
                        corner4 = false;
                }
                if(corner1 && corner2 && corner3 && corner4)
                    step7 = true;
            }
            if(!step7)
            {
                counter = 0;
                if(counter == 4)
                {
                    return false;
                }
                if(rCube[8] != 1)
                {
                    turnCRight();
                    turnCDown();
                    turnRight();
                    turnDown();
                    int array[] = {12,10,3,1};
                    sequence.insert(sequence.end(), array, array+4);
                    counter++;
                }
                else
                {
                    turnCUp();
                    sequence.push_back(9);
                }
            }
        }
        sequence.push_back(700);
        // Double check whole rCube is correct or not
        while(rCube[22] != 3)
            turnCubeToLeft();
        for(int i=0; i<9; i++)
            if(rCube[i] != 1)
                return false;
        for(int i=9; i<18; i++)
            if(rCube[i] != 2)
                return false;
        for(int i=18; i<27; i++)
            if(rCube[i] != 3)
                return false;
        for(int i=27; i<36; i++)
            if(rCube[i] != 4)
                return false;
        for(int i=36; i<45; i++)
            if(rCube[i] != 5)
                return false;
        for(int i=45; i<54; i++)
            if(rCube[i] != 6)
                return false;
        cout<<"\n";
        return true;

    }

};
int main()
{
    vector<int> sequence;
    vector<int> seq;
    // Handle STD_OUTPUT_HANDLE;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"\nR";
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
    cout<<"R\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"         By Abb Muhaimeen\n"<<endl;
    rCube rCube;
    rCube.rCubeInput();
    int height= GetSystemMetrics(SM_CYSCREEN);
    int width= GetSystemMetrics(SM_CXSCREEN);
    initwindow(width,height,"SOLVER");
    readimagefile("res/cube.jpg",600,400,1400,700);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(650,0,"RUBIK'S CUBE SOLVER!");
    outtextxy(650,50,"By Abb Muhaimeen!");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
    outtextxy(650,200,"1.Play!");
    outtextxy(650,250,"2.Solve!");
    outtextxy(650,300,"3.Quit");

    char choice= getch();
    cleardevice();

    if(choice=='1')
    {
        rCube.printCube();
        rCube.helpPage();
        while(1)
        {
            char move=getch();
            switch(move)
            {
            case 'F':
                cleardevice();
                rCube.helpPage();
                rCube.turnFront();
                rCube.printCube();
                break;
            case 'B':
                cleardevice();
                rCube.helpPage();
                rCube.turnBack();
                rCube.printCube();
                break;
            case 'U':
                cleardevice();
                rCube.helpPage();
                rCube.turnUp();
                rCube.printCube();
                break;
            case 'D':
                cleardevice();
                rCube.helpPage();
                rCube.turnDown();
                rCube.printCube();
                break;
            case 'L':
                cleardevice();
                rCube.helpPage();
                rCube.turnLeft();
                rCube.printCube();
                break;
            case 'R':
                cleardevice();
                rCube.helpPage();
                rCube.turnRight();
                rCube.printCube();
                break;
            }
        }
    }
    else if(choice==2){
            rCube.solver(sequence);
			rCube.reduce(sequence);
			rCube.displayTurn(sequence);
    }
    getch();
    closegraph();


}

