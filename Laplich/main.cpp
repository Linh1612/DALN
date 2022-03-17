#pragma one
#include "Library.h"

#define N 14

using namespace std;

class Room{
private:
    int id;
    string name;
    int level;
    int numberPerson;
    typedef vector<pair<int, int>> day_of_week;
    day_of_week days;

  public:
    int getId(){
        return id;
    }

    void setId(int id){
        this->id = id;
    }

    string getName(){
        return name;
    }

    void setName(string name){
        this->name = name;
    }

    int getLevel(){
        return level;
    }

    void setLevel(int level){
        this->level = level;
    }

    int getNumberPerson(){
        return numberPerson;
    }

    void setNumberPerson(int numberPerson){
        this->numberPerson = numberPerson;
    }

    day_of_week getDays(){
        return days;
    }

    void setDays(day_of_week days){
        this->days = days;
    }

    friend istream &operator>>(istream &read, Room &room){
        read >> room.id >> room.name >> room.level >> room.numberPerson;
        for(int i = 0; i < 7; i++){
            int Doctor_M, Doctor_A;
            read >> Doctor_M >> Doctor_A;
            (room.days).push_back({Doctor_M, Doctor_A});
        }
        return read;
    }

    friend ostream &operator<<(ostream &write, Room &room){
        //write << room.id << " " << room.name << " " << room.level << " " << room.numberPerson << "\n";
        for(int i = 0; i < 7; i++){
            int Doctor_M = room.days[i].first;
            int Doctor_A = room.days[i].second;
            write << Doctor_M << " " << Doctor_A << "; ";
        }
        return write;
    }

};

class Solution{
   private:
    vector<Room> listRoom;
    int numberDoctor;

   public:
    void setListRoom(const vector<Room> &listRoom){
        this->listRoom = listRoom;
    }

    vector<Room> getListRoom(){
        return listRoom;
    }

    void setNumberDoctor(int numberDoctor){
        this->numberDoctor = numberDoctor;
    }

    int getNumberDoctor(){
        return numberDoctor;
    }
//điều kiện 1: 1 tuần không làm quá 4 buổi phòng nặng
    bool check_Sub1(){
        vector<int> count;
        for(int i = 0; i < numberDoctor; i++){
            count.push_back({0});
        }
        for(auto r : listRoom){
            if(r.getLevel() == 1){
                for(auto d : r.getDays()){
                    count[d.first]++;
                    count[d.second]++;
                    if(count[d.first] + count[d.second] > 4) return false;
                }
            }
        }
        return true;
    }

//điều kiện 2: 2 ngày liền không làm phòng nặng quá 2 buổi
    bool check_Sub2(){
        vector<int> count;
        for(int i = 0; i < numberDoctor; i++){
            count.push_back({});
        }
        for(int i=0; i<7; ++i){
            // dem ngay thu 1
            for(auto r : listRoom){
                if(r.getLevel() == 1){
                    pair<int, int> day_1 = r.getDays()[i];
                    pair<int, int> day_2 = r.getDays()[i+1%7];
                    count[day_1.first] ++;
                    count[day_2.second] ++;
                    if(count[day_1.first] > 2 || count[day_2.second] > 2) return false;
                }
            }

          count.assign(count.size(), 0);
        }
        return true;
    }

//điều kiện 3: 1 người không được làm ở quá 1 phòng
    bool check_Sub3(){
        vector<int> count_M;
        vector<int> count_A;
        for(int i = 0; i < numberDoctor; i++){
            count_M.push_back({});
            count_A.push_back({});
        }
        for(int i=0; i<7; ++i){
            for(auto r : listRoom){
                pair<int, int> day_1 = r.getDays()[i];
                count_M[day_1.first] ++;
                count_A[day_1.second] ++;
            }
            for(int i = 0; i < numberDoctor; i++){
                if(count_M[i] > 1 || count_A[i] > 1) return false;
            }
            count_M.assign(count_M.size(), 0);
            count_A.assign(count_A.size(), 0);
        }
        return true;
    }

};



struct dt{
    string name;
    vector<int> value;
};



//Docfile dữ liệu bản cứng của lịch
Solution readdt(){
    freopen("C:/Users/Asus/Documents/QTProject/Laplich/JobSchedule.csv","r", stdin);
    string line;
    int number_room, number_doctor;
    cin >> number_room >> number_doctor;
    cin >> line;
    vector<Room> data;
    while(number_room--){
        cin >> line;
        vector<string> tmp = tokenize(line, ',');
        Room row;
        row.setName(tmp[0]);
        vector<pair<int, int>> days;
        for(int i = 1; i < tmp.size(); i+=2){
            days.push_back({stoi(tmp[i]), stoi(tmp[i+1])});
        }
        row.setDays(days);
        data.push_back(row);
    }
    Solution s;
    s.setListRoom(data);
    s.setNumberDoctor(number_doctor);
//    fclose(stdin);
    return s;
}

//Docfile phòng
vector<pair<string, int>> readroom(){
    freopen("C:/Users/Asus/Documents/QTProject/Laplich/Room.csv","r", stdin);
    string line;
    vector<pair<string, int>> rooms;
    while (getline(cin, line)){
        vector<string> rm = tokenize(line, ',');
        string room = rm[1];
//        for(auto i : rms) cout << i << "\n";
        int level = 0;
        if(rm[2] == "Nang"){
            level = 1;
        }
        rooms.push_back({room, level});
    }
    for(auto i : rooms){
        cout << i.first << " " <<i.second << "\n";
    }
//    fclose(stdin);
    return rooms;
}

//In kết quả
void display(Solution s){
    cout << s.getNumberDoctor() << "\n";
    for(auto r:s.getListRoom()){
        cout << r << "\n";
    }
    cout << "Finish show data!";
}

//Kiểm tra rỗng
bool Check_Null(vector<dt> data){
    for(auto i : data){
        for(auto j:i.value){
            if(j == 0){
                return false;
            }
        }
    }
    return true;
}



int main(){
 //   readroom();
    vector<pair<string, int>> rooms;
    rooms.push_back({"A",1});
    rooms.push_back({"B",1});
    rooms.push_back({"C",0});
    rooms.push_back({"D",0});
    rooms.push_back({"E",0});
    rooms.push_back({"F",1});
    rooms.push_back({"G",0});
    rooms.push_back({"H",1});

    Solution start = readdt();
//    cout << check_Sub1(rooms, data) << "\n";
//    cout << check_Sub2(rooms, data) << "\n";
//    cout << check_Sub3(rooms, data) << "\n";

    display(start);
    cout << "\n" << start.check_Sub3() << "\n";


}

