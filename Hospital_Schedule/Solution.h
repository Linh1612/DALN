#pragma once

#include <bits/stdc++.h>
#include "Instance.h"
#include "Library.h"
#define N 14

using namespace std;
typedef vector<int> list_D;

class Solution{
    private:
        // buoi a phong b do bs 1, 2, 3 ... lam
        vector<vector<list_D>> info_Schedule;
        Instance instance;
        vector<int> id_hard_room;

        friend class Solver;

    public:
        Solution(){
            info_Schedule =  vector<vector<list_D>>();
            instance = Instance();
            id_hard_room = vector<int>();
        }
        Solution(Instance *instance){
            this->instance = *instance;
            for(int index_shift = 0; index_shift < N; ++index_shift){
                info_Schedule.push_back({});
                for(int index_room=0; index_room < instance->getNumRoom()+2; ++index_room){
                    info_Schedule[index_shift].push_back({});
                }
            }
            for(auto &i : instance->getListRoom()){
                if(i.getLevel()==1){
                    id_hard_room.push_back(i.getId());
                }
            }
        }


        Solution(vector<vector<list_D>> info_Schedule){
            this->info_Schedule = info_Schedule;
        }

        vector<vector<list_D>> getInfoSchedule(){
            return info_Schedule;
        }

        void setInfoSchedule(vector<vector<list_D>> info_Schedule){
            this->info_Schedule = info_Schedule;
        }

        vector<list_D> getLichNghi(){
               return info_Schedule.at(info_Schedule.size() - 1);
        }

        void setLichNghi( vector<list_D> lich_nghi){
               info_Schedule[info_Schedule.size() - 1] = lich_nghi;
        }

        vector<list_D> getLichTruc(){
               return info_Schedule.at(info_Schedule.size() - 2);
        }

        void setLichTruc( vector<list_D> lich_truc){
               info_Schedule[info_Schedule.size() - 2] = lich_truc;
        }

        void setAt(int index_shift, int id_room, list_D id_doctors){
            info_Schedule[index_shift][id_room] = id_doctors;
        }

        void display(){
            cout << "Thong tin chi tiet: \n";
            for(const auto &row : info_Schedule){
                for(const auto &col : row){
                    for(auto id_doctor : col){
                        printf("%4d\t",id_doctor+1);
                    }
                    cout << "; ";
                }
                cout << "\n";
            }
            cout << "So vi pham: " << CountSub1() + CountSub2() + CountSub3() << "\n";
        }

        //điều kiện 1: 1 tuần không làm quá 4 buổi phòng nặng
            int CountSub1(){
                int result = 0;
                vector<int> count;
                for(int i = 0; i < instance.getNumDoctor(); i++){
                    count.push_back(0);
                }
                vector<Room> listRoom = instance.getListRoom();
                for(auto shift : info_Schedule){
                    for(auto id_room : id_hard_room){
                        for(auto id_doctor : shift[id_room]){
                                count[id_doctor] ++;
                                if(count[id_doctor] > 4)
                                    result ++;
                        }
                    }
                }
                return result;

            }

        //điều kiện 2: 2 ngày liền không làm phòng nặng quá 2 buổi
            int CountSub2(){
                int result = 0;
                vector<int> count;
                for(int i = 0; i < instance.getNumDoctor(); i++){
                    count.push_back({});
                }
                for(int i=0; i<info_Schedule.size() - 3; i += 2){
                    for(int j=i; j<i+3; ++j){
                        for(auto id_room : id_hard_room){
                            for(auto id_doctor : info_Schedule[j][id_room]){
                                count[id_doctor] ++;
                                if(count[id_doctor] > 2)
                                    result ++;
                            }
                        }
                    }
                    count.assign(count.size(), 0);
                }
                return result;
            }

        //điều kiện 3: 1 người không được làm ở quá 1 phòng
            int CountSub3(){
                int result = 0;
                vector<int> count;
                for(int i = 0; i < instance.getNumDoctor(); i++){
                    count.push_back({});
                }
                for(const auto &i:info_Schedule){
                    for(const auto &j : i){
                        for(auto id_doctor : j){
                            count[id_doctor] ++;
                            if(count[id_doctor] > 1){
                                result++;
                            }
                        }
                    }
                    count.assign(count.size(), 0);
                }
                return result;
            }

            void readFile(string link_file){
                vector<vector<list_D>> dt;
                vector<vector<string>> data = readData(link_file);
                for(int row=1; row<data.size(); ++row){
                    while(dt.size()<row){
                        dt.push_back({});
                    }
                    for(int col=1; col<data[row].size(); ++col){
                        while(dt[row-1].size() < col){
                            dt[row-1].push_back({});
                        }
                        vector<string> token = tokenize(data[row][col], ';');
                        for(const auto &tmp:token){
                            dt[row-1][col-1].push_back(stoi(tmp)-1);
                        }
                    }
                }


                for(int j=0; j<dt[0].size(); j++){
                    info_Schedule.push_back({});
                    for(int i=0; i<dt.size(); ++i){
                        info_Schedule[j].push_back({});
                        info_Schedule[j][i] = dt[i][j];
                    }
                }
                cout << "Finish read file !\n";
            }

            void MixSolution(Solution s){
                vector<vector<list_D>> s_info_Schedule = s.getInfoSchedule();
                for(int row=0; row<s_info_Schedule.size(); ++row){
                    for(int col=0; col<s_info_Schedule[0].size(); ++col){
                        if(s_info_Schedule[row][col][0] != -1){
                            info_Schedule[row][col] = s_info_Schedule[row][col];
                        }
                    }
                }
            }

};



