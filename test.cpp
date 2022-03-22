#include "editdistance.h"
#include <string>
#include <iostream>

using namespace std;


int main(int argc, const char** argv) {
    auto ed = new editdistance("中华人民共和国","共和国");
    ed->calculate();
    float acc = ed->getAcc();
    cout << "acc == " << acc << endl;
    delete ed;

    return 0;
}
