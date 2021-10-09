#include <iostream>
#include <math.h>
using namespace std;
#define tower_number 2

int distance(int x1, int y1, int x2, int y2){
    return pow((x1-x2),2)+pow((y1-y2),2);
}

int main(){
    int tower[tower_number][2];
    int radius[tower_number];
    for(int i=0;i < tower_number;i++){
        for(int j=0;j < 2;j++){
            cin >> tower[i][j];
        }
        radius[i] = 0;
    }
    
    int end_num;
    cin >> end_num;
    int end[2];
    for(int i=0;i < end_num;i++){
        cin >> end[0] >> end[1];
        if(distance(tower[0][0],tower[0][1],end[0],end[1]) > distance(tower[1][0],tower[1][1],end[0],end[1])){
            radius[1] = distance(tower[1][0],tower[1][1],end[0],end[1]);
        }
        else{
            radius[0] = distance(tower[0][0],tower[0][1],end[0],end[1]);
        }
    }

    cout << radius[0] + radius[1] << endl;

    return 0;
}