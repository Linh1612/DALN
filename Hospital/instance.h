#pragma once

#include <bits/stdc++.h>

#include "doctor.h"
#include "lib_.h"
#include "room.h"

using namespace std;
class Instance {
   private:
    int numberRooms;
    int numberDoctors;
    vector<Room> listRooms;
    vector<Doctor> listDoctors;

   public:
    Instance() {
        numberRooms = 0;
        numberDoctors = 0;
        listRooms = vector<Room>();
        listDoctors = vector<Doctor>();
    }

    Instance(int numRoom, int numDoctor) {
        this->numberRooms = numRoom;
        this->numberDoctors = numDoctor;
        listRooms = vector<Room>();
        listDoctors = vector<Doctor>();
    }

    int getNumberRooms() {
        return this->numberRooms;
    }
    void setNumberRooms(int numberRooms) {
        this->numberRooms = numberRooms;
    }

    int getNumberDoctors() {
        return this->numberDoctors;
    }
    void setNumberDoctors(int numberDoctors) {
        this->numberDoctors = numberDoctors;
    }

    vector<Room> getListRoom() {
        return listRooms;
    }

    void setListRoom(vector<Room> list_room) {
        this->listRooms = list_room;
    }

    vector<Doctor> getListDoctor() {
        return listDoctors;
    }

    void setListDoctor(vector<Doctor> list_doctor) {
        this->listDoctors = list_doctor;
    }

    void readNameDoctors(string link_file) {
        vector<vector<string>> data = readData(link_file);
        for (int i = 0; i < data.size(); ++i) {
            listDoctors.push_back({});
            listDoctors[i].setId(i);
            if (data[i][1][data[i][1].size() - 1] == '\r') {
                data[i][1].erase(data[i][1].end() - 1);
            }
            listDoctors[i].setName(data[i][1]);
        }
        numberDoctors = listDoctors.size();
    }


    void readInforRooms(string link_file) {
        vector<vector<string>> data = readData(link_file);
        for (int i = 0; i < data.size(); ++i) {
            listRooms.push_back({});
            listRooms[i].setId(i);
            listRooms[i].setName(data[i][1]);
            listRooms[i].setLevel(stoi(data[i][2]));
        }
        numberRooms = listRooms.size();
    }

    void readCapacityDoctors(string link_file) {
        vector<vector<string>> data = readData(link_file);
        for (int i = 0; i < data.size() && i < numberDoctors; ++i) {
            listDoctors[i].setNumberAbility(listRooms.size());
            for (const auto &j : data[i]) {
                listDoctors[i].setAbilityAt(stoi(j) - 1);
                if (stoi(j) <= listRooms.size())
                    listRooms[stoi(j) - 1].addRoomCapacity(i);
            }
        }
    }
};
