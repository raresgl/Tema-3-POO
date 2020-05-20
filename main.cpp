#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
#include "animal.h"
#include "vertebrate.h"
#include "nevertebrate.h"
#include "peste.h"
#include "pasare.h"
#include "reptila.h"
#include "mamifer.h"
#include "AtlasZoologic.h"
int main()
{
    int test = 5;
    switch(test){
        case 1:{
            Animal a;
            cin>>a;
            cout<<a;
            break;
            }
        case 2:{
            Vertebrate v1,v2;
            v1.setter(13,4,"tigru");
            v2 = v1;
            v2.afisare();
            break;
            }
        case 3:{
            Peste p;
            cin>>p;
            cout<<p;
            break;
            }
        case 4:{
            AtlasZoologic<Peste> at;
            Peste ob, ob2;
            cin>>ob;
            cin>>ob2;
            at += ob;
            at += ob2;
            at += ob;
            cout<<at;
            break;
        }
        case 5:{
            AtlasZoologic <Peste> at2;
            cin >> at2;
            cout << at2;
        }
    }
    return 0;
}
