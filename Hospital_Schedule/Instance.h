#pragma once
#include <bits/stdc++.h>
#include "Room.h"
#include "Doctor.h"
#include "Library.h"

using namespace std;

class Instance {
private:
    int numRoom;
    int numDoctor;
    vector<Room> list_room;
    vector<Doctor> list_doctor;


public:
    Instance() {
        numRoom = 0;
        numDoctor = 0;
        list_room = vector<Room>();
        list_doctor = vector<Doctor>();
    }

    Instance(int numRoom, int numDoctor, vector<Room> list_room, vector<Doctor> list_doctor) {
        this->numRoom = numRoom;
        this->numDoctor = numDoctor;
        this->list_room = list_room;
        this->list_doctor = list_doctor;

    }

    int getNumRoom(){
      return numRoom;
    }

    void setNumRoom(int numRoom){
      this->numRoom = numRoom;
    }

    int getNumDoctor(){
      return numRoom;
    }

    void setNumDoctor(int numDoctor){
      this->numDoctor = numDoctor;
    }

    vector<Room> getListRoom(){
      return list_room;
    }

    void setListRoom(vector<Room> list_room){
      this->list_room = list_room;
    }

    vector<Doctor> getListDoctor(){
      return list_doctor;
    }

    void setListDoctor(vector<Doctor> list_doctor){
      this->list_doctor = list_doctor;
    }
    void readNameDoctors(string link_file){
        vector<vector<string>> data = readData(link_file);
        for(int i = 0; i<data.size(); ++i){
            list_doctor.push_back({});
            list_doctor[i].setId(i);
            list_doctor[i].setName(data[i][1]);
        }
        numDoctor = list_doctor.size();
    }
    void readInforRooms(string link_file){
        vector<vector<string>> data = readData(link_file);
        for(int i = 0; i<data.size(); ++i){
            list_room.push_back({});
            list_room[i].setId(i);
            list_room[i].setName(data[i][1]);
            list_room[i].setLevel(stoi(data[i][2]));
        }
        numRoom = list_room.size();
    }

    void readCapacityDoctors(string link_file){
        vector<vector<string>> data = readData(link_file);
        for(int i=0; i<data.size() && i<numDoctor; ++i){
            for(auto j:data[i]){
                list_doctor[i].addKhaNang(stoi(j)-1);
                if(stoi(j) <= list_room.size())
                    list_room[stoi(j)-1].addRoomCapacity(i);
            }
        }
    }

};


