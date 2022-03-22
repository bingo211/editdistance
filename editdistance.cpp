#include "editdistance.h"
#include <algorithm>
#include "utils.h"
using namespace std;

editdistance::editdistance(const std::string& source, 
                          const std::string& target)
{

    lab = to_wide_string(source);
    rec = to_wide_string(target);

    this->S = this->D = this->H= this->I = this->N = 0;
    this->dis = new int*[rec.length() + 1];
    this->flag = new int*[rec.length() + 1];

    for (int i = 0 ; i < this->rec.length() + 1 ; i++){
        this->dis[i] = new int[this->lab.length() + 1];
        this->flag[i] = new int[this->lab.length() + 1];
        
        for (int j = 0 ; j < this->lab.length() + 1; j++){
            this->dis[i][j] = 0;
            this->flag[i][j] = 0;
        }
    }
}

editdistance::~editdistance()
{
    for (int i = 0 ; i < rec.length() + 1 ;i++){
        delete[] dis[i];
        delete[] flag[i];
    }

    delete[] dis;
    delete[] flag;
}

//计算编辑距离及H\D\I\S等
void editdistance::calculate(){
    this->N = this->lab.length();
    this->getDistance();
    this->backtracking();
    this->H = this->N - this->S - this->D;
}

//计算编辑距离
int editdistance::getDistance(){
    int len1 = this->rec.length();
    int len2 = this->lab.length();

    if (len1 == 0){
        return len2;
    }else if (len2== 0){
        return len1;
    }

    for (int i = 0 ; i < len1 + 1 ; i++){
        this->dis[i][0] = i;
        this->flag[i][0] = 0;
    }

    for (int j = 0 ; j < len2 + 1 ; j++){
        this->dis[0][j] = j;
        this->flag[0][j] = 0;
    }

    for (int i = 1; i < len1 + 1 ; i++){
        for (int j = 1 ; j < len2 + 1 ; j++){
            int top = this->dis[i -1][j] +1;
            int left = this->dis[i][j-1]+1;
            int lt = (this->rec.at(i - 1) == this->lab.at(j -1))?  this->dis[i-1][j-1] :this->dis[i - 1][j -1] + 1;
            dis[i][j] = std::min(top, std::min(left, lt));

            if(dis[i][j] == lt) {
                flag[i][j] = 1;
            } else if(dis[i][j] == top) {
                flag[i][j] = 2;
            } else if(dis[i][j] == left) {
                flag[i][j] = 3;
            }
        }
    }
    return dis[len1][len2];  
}

//反向计算
void editdistance::backtracking()
{
    int i = this->rec.length();
    int j = this->lab.length();
    while(i > 0 && j > 0){
        if(this->rec.at(i - 1) == this->lab.at(j - 1)){
            i--;
            j--;
        }else{
            switch (this->flag[i][j]) {
            case 1:
                this->S++;
                i--;
                j--;
                break;
            case 2:
                this->I++;
                i--;
                break;
            case 3:
                this->D++;
                j--;
                break;
            default:
                break;
            }
        }
    }

    if(i == 0) {
        D += j;
    } else if(j == 0) {
        I += i;
    }
}

//计算ACC
float editdistance::getAcc()
{
    if (this->N == 0)
        return 0;
    return float(this->N - this->S - this->D - this->I) / this->N;
}
	
//计算CORR
float editdistance::getCorr() 
{
    if (this->N == 0)
        return 0;
    return float(this->N - this->S - this->D) / this->N;
}