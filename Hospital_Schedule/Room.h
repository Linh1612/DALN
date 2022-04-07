#pragma once
#include<bits/stdc++.h>

using namespace std;

class Room{
private:
    int id;
    string name;
    int  level;
    int numberPerson;
    vector<int> id_doctors;
    vector<int> room_capacity;

  public:

    Room(){
        id = -1;
        level = -1;
        numberPerson = 1;
    }

    Room(int id, string name, int level, int numberPerson){
        this->id = id;
        this->name = name;
        this->level = level;
        this->numberPerson = numberPerson;
    }



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

    vector<int> getIdDoctors(){
        return id_doctors;
    }

    void setIdDoctors(vector<int> id_doctors){
        this->id_doctors = id_doctors;
    }

    void addRoomCapacity(int id_doctor){
        room_capacity.push_back(id_doctor);
    }

    vector<int> getRoomCapacity(){
        return room_capacity;
    }

    vector<int> randListDoctor(int numberDoctor){
        vector<int> result;
        vector<int> copy_room_capacity = room_capacity;
        for(int i=0; i<numberDoctor && i<room_capacity.size(); ++i){
            int index = rand() % copy_room_capacity.size();
            result.push_back(copy_room_capacity[index]);
            copy_room_capacity.erase(copy_room_capacity.begin() + index);
        }
        //cout << numberDoctor << " " << room_capacity.size() << " " << result.size() << "\n";
        return result;
    }

    vector<int> randListDoctor(){
        return randListDoctor(numberPerson);
    }

    friend istream &operator>>(istream &read, Room &room){
        read >> room.id >> room.name >> room.level >> room.numberPerson;
        return read;
    }

    friend ostream &operator<<(ostream &write, const Room &room){
        write << room.id << " " << room.name << " " << room.level << " " << room.numberPerson <<"\n";
        write << "List id doctor: ";
        for(auto id_doctor : room.id_doctors){
            write << id_doctor << " ";
        }
        cout << "\n";
        return write;
    }
};





