#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int MM_count =0; 
int noIn=0;

void init(char MM[][4]){

    for(int i =0;i<100;i++){
        for(int j=0;j<4;j++){
            MM[i][j] = '-';
        }
    }
}

int find(char ch){      //function for finding number after GD __ and PD __

    switch(ch){

        case '0':
            return 0;
            break;
        case '1':
            return 10;
            break;
        case '2':
            return 20;
            break;
        case '4':
            return 30;
            break;
        default :
            return 10;
            break;
    }
}

void Write(char IR[],char MM[][4]){

    int sadd = find(IR[2]);
    int eadd = sadd+9;

    ofstream outputFile("output.txt",ios::app); 

    for(int i =sadd;i<eadd;i++){
        for(int j=0;j<4;j++){
            if(MM[i][j] != '-'){
            outputFile<<MM[i][j];
            }
        }
    }
    outputFile.close();
}


void Read(string data ,char IR[],char MM[][4]){         //read data from input file and store into memory

    IR[3] = '0';  //error handling
    
    int row = find(IR[2]);
  
    int col =0;
    for(int i =0;i<data.length();i++){
        if(col == 4){
            row++;
            col = 0;
        }
        MM[row][col] = data.at(i);
        col++;
    }
    MM_count  = MM_count+10;
}

void Terminate(){

    ofstream outputFile("output.txt",ios::app);
    outputFile<<"\n\n"<<endl;
    outputFile.close();
}

void MOS(string data,char MM[][4],char IR[],int si){
 
    switch(si){

        case 1:
            Read(data,IR,MM);
            break;
        case 2:
            Write(IR,MM);
            break;
        case 3:
            Terminate();
            break;
        default:
            return;
            break;
    }
}

void executeuserprogram(string data,int Ic,char MM[][4]){
  
    int si = 3;

    int c = 0;

    char IR[4];

    while(Ic < noIn){

    si = 3;

    for (int j = 0; j < 4; j++) {
            IR[j] = MM[Ic][j];
    }
    
    Ic++;

    char R [40];
    
    string function = "";
    function = function + IR[0];
    function = function + IR[1];

    int operandAdd = find(IR[2]);

    if(function == "LR"){
        si = 0;
        int r_count =0;
        for(int i =operandAdd;i<=(operandAdd+9);i++){
            for(int j = 0;j<4;j++){
                R[r_count++] = MM[i][j];
            }
        }
    }

    else if(function == "SR"){

        int r_count = 0;
        for(int i = operandAdd;i<(operandAdd+9);i++){
            for(int j=0;j<4;j++){
                MM[i][j] = R[r_count++];
            }
        }  
        si =0;
    }

    else if(function == "CR"){

        int r_count = 0;

        for(int i=operandAdd;i<(operandAdd+9);i++){
            for(int j=0;j<9;j++){
                if(MM[i][j] != R[r_count++]){
                    printf("Not Equal");
                }
            }
        }

    }

    else if(function == "BT"){
        if(c == 1){
            Ic = operandAdd;
        }
    }
    else if(function == "GD"){
        si = 1;
    }
    else if(function == "PD"){
        si = 2;
    }
    else if(function == "H-"){
        si = 3;
    }
    else{
        printf("Invalid Job");
        return;
    }

    MOS(data,MM,IR,si);

    }
}

void startexecution(string data,char MM[][4]){
    int Ic = 0;
    executeuserprogram(data,Ic,MM);
}


void Load(char MM[][4]){
 
    string line;

    ifstream fin;
    
    fin.open("input.txt");
 
    while (getline(fin, line)) {

        string opcode = line;
        string op = opcode.substr(0,4);
        
        if(op == "$AMJ"){
            continue;
        }
        else if(op == "$DTA"){
            if (getline(fin, line)){
                string data = line;
                startexecution(data,MM);
            }
            else{
                printf("\n**Data Missing");
                break;
            }
        }
        else if(op == "$END"){
            MM_count = 0;
           continue;
        }
        else{                               //program card
            string inst = line;
            int row = MM_count;
            int col =0;
            for(int i =0;i<inst.length();i++){
                if(col == 4){
                    row++;
                    col = 0;
                }
                MM[row][col] = inst.at(i);
                col++;
            }
            noIn = row+1;
        }
    }

    fin.close();
}

int main(){

    char MM[100][4];

    init(MM);

    Load(MM);

    // startexecution(MM);
    printf("\n Main Memory Simulation\n\n");
    
    for(int i =0;i<100;i++){
        printf("%2d     ",i);
        for(int j=0;j<4;j++){
            printf("%5c ",MM[i][j]);
        }
        printf("\n");
    }
    printf("\n");
   
    return 0;
}
