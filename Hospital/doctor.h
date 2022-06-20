#pragma once

#include <bits/stdc++.h>
#include "room.h"

using namespace std;

class Doctor {
   private:
    int id;
    string name;
    vector<int> personal_calendar;  // xet theo buoi: 0-nghi, 1-lamviec, 2-truc
    vector<bool> ability;           // xet kha nang lam viec o phong theo id(index) phong: 0 - khong lam duoc, 1 - co the lam


   public:
    vector<string> job_schedule;    // xet lich lam viec cua bac si trong lich
    Doctor() {}
    Doctor(int id, string name, vector<int> personal_calendar, vector<bool> ability) {
        this->id = id;
        this->name = name;
        this->personal_calendar = personal_calendar;
        this->ability = ability;
        job_schedule.assign(14, "");
    }
    Doctor(int id, string name) {
        this->id = id;
        this->name = name;
        job_schedule.assign(14, "");
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
    vector<int> getPersonalCalendar() {
        return personal_calendar;
    }

    void setPersonalCalendar(vector<int> personal_calendar) {
        this->personal_calendar = personal_calendar;
    }

    void setPersonalCalendarAt(int index_shift, int value) {
        if ((index_shift + 1) > personal_calendar.size()) {
            cout << "index_shift > personal_calendar.size() - 1 !\n";
            return;
        }
        if (value < 0 || value > 2) {
            cout << "Gia tri cua lich lam viec ca nhan khong hop le!";
            return;
        }
        personal_calendar[index_shift] = value;
    }
    void setNumberAbility(int number_rooms) {
        ability.resize(number_rooms, false);
    }

    void setAbilityAt(int id_room) {
        if ((id_room + 1) > ability.size()) {
            cout << "id_room > ability.size() - 1\n";
            return;
        }
        ability[id_room] = true;
    }

    void showAbility(vector<Room> listRooms, string linkFile_AbilityDoctor){
        ofstream out(linkFile_AbilityDoctor, std::ofstream::app);
        out << "Ability " << name << ": ";
        int index =0;
        for(auto i:ability){
            if(i==1)
                out << "\n\t\tPhong so " << index+1 << ": " << listRooms[index].getName();
            ++index;

        }
        out << "\n";
        out.close();
    }
};
