#include "editdistance.h"
#include <string>
#include <iostream>

using namespace std;


int main(int argc, const char** argv) {
    auto ed = new editdistance("科大讯飞","飞讯");
    ed->calculate();
    float acc = ed->getAcc();
    cout << "acc == " << acc << endl;
    delete ed;

    return 0;
}