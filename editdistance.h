#ifndef __EDIT_DISTANCE__INCLUDE__
#define __EDIT_DISTANCE__INCLUDE__
#include <string>
using namespace std;

class editdistance
{
private:
    wstring rec;
    wstring lab;
    int **dis,**flag;
    int H,D,S,I,N;
    
public:
    editdistance(const std::string& source, const std::string& target);
    ~editdistance();
    void calculate();
    float getAcc();
    float getCorr();
private:
    int getDistance();
    void backtracking();
};

#endif