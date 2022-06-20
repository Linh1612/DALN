#pragma once

#include <bits/stdc++.h>

using namespace std;

class Room {
   private:
    int id;
    string name;
    int number_doctors;
    int level;
    vector<int> id_doctors;
    vector<int> room_capacity;

   public:
    Room() {
        id = 0;
        level = 0;
        number_doctors = 1;
    }
    Room(int id, string name, int level = 0, int number_doctors = 1) {
        this->id = id;
        this->name = name;
        this->level = level;
        this->number_doctors = number_doctors;
    }

    int getId() {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getLevel() {
        return level;
    }

    void setLevel(int level) {
        this->level = level;
    }

    int getNumberDoctors() {
        return number_doctors;
    }

    void setNumberDoctors(int number_doctors) {
        this->number_doctors = number_doctors;
    }

    vector<int> getIdDoctors() {
        return id_doctors;
    }

    void setIdDoctors(vector<int> id_doctors) {
        this->id_doctors = id_doctors;
    }

    bool checkIdDoctor(int id_doctor) {
        for (auto i : room_capacity) {
            if (i == id_doctor) return true;
        }
        return false;
    }

    void addRoomCapacity(int id_doctor) {
        room_capacity.push_back(id_doctor);
    }

    vector<int> getRoomCapacity() {
        return room_capacity;
    }
    vector<int> randListDoctor(int numberDoctor, vector<bool> &flag_id_doctors) {
        // flag_id_doctors : danh dau xem bac si thu i da lam hay chua (true: da lam, false: chua lam)
        int count_doctors_possible = 0;
        for (auto i : room_capacity) {
            if (flag_id_doctors[i] == false) {
                ++count_doctors_possible;
            }
        }
        if (count_doctors_possible < numberDoctor) return {-1};

        vector<int> result = {};
        int index;
        for (int i = 1; i <= numberDoctor; ++i) {
            do {
                index = rand() % room_capacity.size();
            } while (flag_id_doctors[room_capacity[index]]);

            result.push_back(room_capacity[index]);
            flag_id_doctors[room_capacity[index]] = true;
        }
        return result;
    }
    friend istream &operator>>(istream &read, Room &room) {
        read >> room.id >> room.name >> room.level >> room.number_doctors;
        return read;
    }

    friend ostream &operator<<(ostream &write, const Room &room) {
        write << room.id << " " << room.name << " " << room.level << " " << room.number_doctors << "\n";
        write << "List id doctor: ";
        for (auto id_doctor : room.id_doctors) {
            write << id_doctor << " ";
        }
        cout << "\n";
        return write;
    }
};
