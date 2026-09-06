// Last updated: 9/6/2026, 5:15:19 PM
1class ParkingSystem {
2public:
3    int big,medium,small;
4    ParkingSystem(int big, int medium, int small) {
5        this->big = big;
6        this->medium = medium;
7        this->small = small;
8        
9    }
10
11    bool addCar(int carType) {
12        if(carType==1 && big>0) {
13            big--;
14            return true;
15        }      
16        if(carType==2 && medium>0) {
17            medium--;
18            return true;
19        }    
20        if(carType==3 && small>0) {
21            small--;
22            return true;
23        } 
24        return false;     
25    }
26};
27