#include <iostream>
#include "Matrix.h"
#include "UnDirectedGraph.h"
#include "DirectionGraph.h"
#include "Test_Matrix.h"
#include "Test_NotDirection.h"
#include "Test_Direction.h"
#include <string>
#include "MenuGraph.h"
#include "ComutatedNets.h"
#include "Test_Comutated_Net.h"
#include "MenuNet.h"
using namespace std;



int main() {
    Test_commutated_net1();
    Test_commutated_net2();
    Test_commutated_net3();
    Test_ping();
    Test_packeges();
    Test_matrix1();
    Test_matrix2();
    Test_matrix_append();
    Test_matrix_operators();
    Test_NotDirection1();
    Test_NotDirection2();
    Test_NotDirection3();
    Test_NotDirection_Operators();
    Test_Direction1();
    Test_Direction2();
    Test_Direction3();
    Test_Direction_Operators();
    cout << "1 - to use graphs"
         << endl
         << "2- to use commutated nets"
         << endl
         << "0 - to EXIT"
         << endl
         << "Your chose: ";
    int ch;
    cin >> ch;
    if (ch == 1)
        Menu();
    else
        if (ch == 2)
            MenuNet();
}

