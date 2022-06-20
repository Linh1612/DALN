#pragma once
#include <bits/stdc++.h>

#include "instance.h"
#include "solution.h"

#define N 14

using namespace std;

class Solver {
   private:
    Instance *instance;
    Solution *bestSolution;
    vector<vector<pair<int, int>>> capacity_room_shifts;

   public:
    Solver() {}

    Solver(Instance *instance) {
        this->instance = instance;
        bestSolution = new Solution(instance);
    }

    void LocalSearch() {
        StartConstruction();
        int sc = bestSolution->Score();
        cout << "Score start: " << sc << "\n";
        bestSolution->display();
        int step = 2000;
        Solution CurrentSol = *bestSolution;
        float eps = 0.995;

        do {
            cout << "================================================================";
            cout << "\nstep:" << step << "\n";
            Solution tmp = CurrentSol;
            Destroy(&tmp);
            Repair(&tmp);

            if (tmp.Score() <= CurrentSol.Score()) {
                CurrentSol = tmp;
                if (tmp.Score() < bestSolution->Score()) {
                    *bestSolution = tmp;
                    tmp.display();
                }
            }

            cout << "tmp score: " << tmp.Score() << " - best score: " << bestSolution->Score() << "\n";
//            cout << "tmp score: " << tmp.CountSub1() << " - best score: " << bestSolution->Score() << "\n";
//            cout << "tmp score: " << tmp.CountSub2() << " - best score: " << bestSolution->Score() << "\n";
//            cout << "tmp score: " << tmp.CountSub3() << " - best score: " << bestSolution->Score() << "\n";
//            cout << "tmp score: " << tmp.CountSub4() << " - best score: " << bestSolution->Score() << "\n";
//            tmp.display();
            cout << "\n=====================================\n";
            eps *= 0.995;
            //tmp.XuatFile_1("C:/Users/Asus/Documents/QTProject/Hospital/output/tmp.csv");

        } while (--step);        
    }

    void StartConstruction() {
        vector<pair<int, int>> capacity_rooms;
        vector<Room> listRoom = instance->getListRoom();
        for (auto i : listRoom) {
            capacity_rooms.push_back({i.getRoomCapacity().size(), i.getId()});
        }

        vector<int> id_rooms = {};
        vector<bool> flag_doctors;
        int flag;
        int num_doctors = instance->getNumberDoctors();
        int num_rooms = instance->getNumberRooms();

        for (int shift = 0; shift < N; shift += 2) {
            vector<pair<int, int>> capacity_rooms_copy = capacity_rooms;
            flag = num_rooms;
            flag_doctors.assign(num_doctors, false);
            id_rooms.assign(num_rooms, 0);

            // check lich lam viec
            vector<bool> flag_working = bestSolution->checkDoctorsWorking(shift);
            //flag_doctors = flag_working;
            for (int id = 0; id < flag_working.size(); ++id) {
                if (!flag_working[id]) continue;
                flag_doctors[id] = true;
                for (int i = 0; i < listRoom.size(); i++) {
                    if (listRoom[capacity_rooms_copy[i].second].checkIdDoctor(id)) {
                        capacity_rooms_copy[i].first -= 1;
                    }
                }
            }

            for (auto id_room : bestSolution->getListRoomIsNotEmpty(shift)) {
                id_rooms[id_room] = -1;
                flag--;
            }

            for (; flag > 0; flag--) {
                sort(capacity_rooms_copy.begin(), capacity_rooms_copy.end());
                int index_min_room = -1;
                for (auto i : capacity_rooms_copy) {
                    if (id_rooms[i.second] >= 0 && i.first > 0) {
                        index_min_room = i.second;
                        break;
                    }
                }

                if (index_min_room < 0) break;

                vector<int> id_doctors_ran = listRoom[index_min_room].randListDoctor(1, flag_doctors);

                bestSolution->setAt(shift, index_min_room, id_doctors_ran);
                bestSolution->setAt(shift + 1, index_min_room, id_doctors_ran);

                // xoa bac si ra khoi phong
                for (auto id : id_doctors_ran) {
                    flag_doctors[id] = true;
                    for (int i = 0; i < listRoom.size(); i++) {
                        if (listRoom[capacity_rooms_copy[i].second].checkIdDoctor(id)) {
                            capacity_rooms_copy[i].first -= 1;
                        }
                    }
                }

                // xoa phong
                id_rooms[index_min_room] = -1;
            }
            capacity_room_shifts.push_back(capacity_rooms_copy);
            capacity_room_shifts.push_back(capacity_rooms_copy);
        }
    }

    void Repair(Solution *CurrentSol) {
        vector<pair<int, int>> capacity_rooms;

        vector<int> id_rooms = {};
        vector<bool> flag_doctors;
        int flag;
        int num_doctors = instance->getNumberDoctors();
        int num_rooms = instance->getNumberRooms();
        vector<Room> listRoom = instance->getListRoom();

        for (auto i : listRoom) {
            capacity_rooms.push_back({i.getRoomCapacity().size(), i.getId()});
        }

        for (int shift = 0; shift < N; shift+=2) {
            vector<pair<int, int>> capacity_rooms_copy = capacity_rooms;
            flag = num_rooms;
            flag_doctors.assign(num_doctors, false);
            id_rooms.assign(num_rooms, 0);

//            // check lich lam viec
            vector<bool> flag_working = CurrentSol->checkDoctorsWorking(shift);
            for (int id = 0; id < flag_working.size(); ++id) {
                if (!flag_working[id]) continue;
                flag_doctors[id] = true;
                for (int i = 0; i < listRoom.size(); i++) {
                    if (listRoom[capacity_rooms_copy[i].second].checkIdDoctor(id)) {
                        capacity_rooms_copy[i].first -= 1;
                    }
                }
            }

            for (auto id_room : CurrentSol->getListRoomIsNotEmpty(shift)) {
                id_rooms[id_room] = -1;
                flag--;
            }

            for (; flag > 0; flag--) {
                sort(capacity_rooms_copy.begin(), capacity_rooms_copy.end());
                int index_min_room = -1;
                for (auto i : capacity_rooms_copy) {
                    if (id_rooms[i.second] >= 0 && i.first > 0) {
                        index_min_room = i.second;
                        break;
                    }
                }

                if (index_min_room < 0) break;

                vector<int> id_doctors_ran = listRoom[index_min_room].randListDoctor(1, flag_doctors);

                CurrentSol->setAt(shift, index_min_room, id_doctors_ran);
                CurrentSol->setAt(shift+1, index_min_room, id_doctors_ran);

                // xoa bac si ra khoi phong va list bac si chua xep lich
                for (auto id : id_doctors_ran) {
                    //flag_doctors[id] = true;
                    for (int i = 0; i < listRoom.size(); i++) {
                        if (listRoom[capacity_rooms_copy[i].second].checkIdDoctor(id)) {
                            capacity_rooms_copy[i].first -= 1;
                        }
                    }
                }

                // xoa phong
                id_rooms[index_min_room] = -1;
            }
            capacity_room_shifts[shift] = capacity_rooms_copy;
            capacity_room_shifts[shift+1] = capacity_rooms_copy;
        }
    }

    void Destroy(Solution *CurrentSol) {
        int rand_ = (rand() % 21 + 10) * N / 2 * instance->getNumberRooms() / 100;
        cout << rand_ << "\n"
             << "------------\n";
        while (rand_) {
            int index_row = rand() % CurrentSol->getInfoSchedule().size();
            index_row -= index_row % 2;
            vector<list_D> shift = CurrentSol->getInfoSchedule()[index_row];
            int index_col = rand() % (shift.size() - 2);
            if (shift[index_col].size() > 0 && shift[index_col][0] != -1 && CurrentSol->fixed_position[index_row][index_col] == false) {
                for (auto i : shift[index_col]) {
                    for (auto &cap_id_room : capacity_room_shifts[index_row]) {
                        if (cap_id_room.second == index_col) {
                            cap_id_room.first += 1;
                            break;
                        }
                    }
                }
                vector<int> trc = CurrentSol->getInfoSchedule()[index_row][index_col];
                CurrentSol->setAt(index_row, index_col, vector<int>(1, -1));
                vector<int> sau = CurrentSol->getInfoSchedule()[index_row][index_col];
                CurrentSol->setAt(index_row+1, index_col, vector<int>(1, -1));

                --rand_;
            }
        }
        //       CurrentSol->XuatFile("C:/Users/Asus/Documents/QTProject/Hospital_Schedule/destroy.csv");
        //       cout << "destroy\n";
    }

    void DataFromFile(string linkFile) {
        Solution s_data = Solution();
        s_data.readFile(linkFile);
        bestSolution->MixSolution(s_data);
    }

    void display() {
        bestSolution->display();
    }

    void WriteFile(string linkFile_result, string linkFile_error, string linkFile_schedulePersonal) {
        bestSolution->XuatFile_1(linkFile_result);
        //bestSolution->XuatFile(linkFile_result);
        bestSolution->display_error(linkFile_error);
        bestSolution->XuatFile_2(linkFile_schedulePersonal);
    }
};
