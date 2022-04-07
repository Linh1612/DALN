#pragma once
#include <bits/stdc++.h>

#include "Instance.h"
#include "Solution.h"

#define N 14

using namespace std;

class Solver {
   private:
    Instance *instance;
    Solution *bestSolution;

   public:
    Solver() {}

    Solver(Instance *instance) {
        this->instance = instance;
    }

    void StartConstruction() {
        vector<pair<int, int>> capacity_rooms;
        vector<Room> listRoom = instance->getListRoom();
        for(auto i : listRoom){
            capacity_rooms.push_back({i.getRoomCapacity().size(), i.getId()});
        }
        sort(capacity_rooms.begin(), capacity_rooms.end());
        bestSolution = new Solution(instance);
        for(int shift=0; shift<N; shift+=2){
            for(auto room: capacity_rooms){
                vector<int> id_doctors = listRoom[room.second].randListDoctor();
                bestSolution->setAt(shift, room.second, id_doctors);
                bestSolution->setAt(shift+1, room.second,id_doctors);
            }
        }
    }

    void MixSolution(Solution s){
        bestSolution->MixSolution(s);
    }

    void SolutionConstruction() {
    }

    void display(){
        bestSolution->display();
    }

};

