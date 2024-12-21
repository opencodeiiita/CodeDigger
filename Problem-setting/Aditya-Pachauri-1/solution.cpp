#include <iostream>
using namespace std;

#define sp_lift 5
#define sp_man 1
int floor_height = 10;
int room_dist = 5;
int no_room_corr = 10;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int floor, room;
        cin >> floor >> room;
        int lift1, lift2;
        if (room >= 1 && room <= 10) {
            lift1 = 1;
            lift2 = 2;
        } else if (room > 10 && room <= 20) {
            lift1 = 2;
            lift2 = 3;
        } else if (room > 20 && room <= 30) {
            lift1 = 3;
            lift2 = 4;
        } else {
            lift1 = 4;
            lift2 = 1;
        }
        int time = 0;
        int imp_no = room % 10;
        if (imp_no >= 1 && imp_no <= 5) {
            time = floor_height*(floor - 1) * sp_lift + room_dist * no_room_corr * sp_man + room_dist * imp_no * sp_man;
        } else {
           
            time = floor_height*(floor - 1) * sp_lift + room_dist * no_room_corr * sp_man + room_dist * (10 - imp_no + 1) * sp_man;
        }

        cout << lift1 << " " << lift2 << " " << time << endl;
    }

    return 0;
}


