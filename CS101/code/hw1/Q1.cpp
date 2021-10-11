#include <iostream>
#include <math.h>
using namespace std;
#define tower_number 2

struct point
{
    int x,y;
};
struct max_dis
{
    int r0,r1;
};

int dis(point p, point q){
    return pow((p.x-q.x),2)+pow((p.y-q.y),2);
}

int main(){
    point tower[tower_number];
    int radius[tower_number];
    int r_test[tower_number][tower_number];
    max_dis m_d[tower_number];
    int S[2] = {0,0};
    for(int i=0;i < tower_number;i++){
        cin >> tower[i].x >> tower[i].y;
        radius[i] = 0;
        m_d[i].r0 = 0;
        m_d[i].r1 = 0;
    }

    int end_num;
    cin >> end_num;
    point end;
    for(int i=0;i < end_num;i++){
        cin >> end.x >> end.y;
        if (dis(tower[0],end)>m_d[0].r0)
        {
            m_d[0].r0 = dis(tower[0],end);
            m_d[0].r1 = dis(tower[1],end);
        }
        if (dis(tower[1],end)>m_d[1].r1)
        {
            m_d[1].r1 = dis(tower[1],end);
            m_d[1].r0 = dis(tower[0],end);
        }
        
        if(dis(tower[0],end)>radius[0] && dis(tower[1],end)>radius[1]){
            r_test[0][0] = dis(tower[0],end);
            if(m_d[1].r0 > r_test[0][0]){
                r_test[0][1] = m_d[1].r1;
            }
            else{
                r_test[0][1] = 0;
            }
            S[0] = r_test[0][0]+r_test[0][1];

            r_test[1][1] = dis(tower[1],end);
            if(m_d[0].r1 > r_test[1][1]){
                r_test[1][0] = m_d[0].r0;                
            }
            else{
                r_test[1][0] = 0;
            }
            S[1] = r_test[1][0]+r_test[1][1];

            if (S[0]<S[1])
            {
                radius[0] = r_test[0][0];
                radius[1] = r_test[0][1];
            }
            else{
                radius[0] = r_test[1][0];
                radius[1] = r_test[1][1];
            }
        }
    }

    cout << radius[0] + radius[1] << endl;

    return 0;
}