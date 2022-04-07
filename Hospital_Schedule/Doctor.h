#pragma once
#include<bits/stdc++.h>

using namespace std;

class Doctor{

private:
    int id;
    string name;
    vector<int> lich_nghi; // tinh theo buoi 0->13
    vector<int> lich_truc; // tinh theo ngay 0->6
    vector<int> lich_lam_viec; // tinh theo buoi 0->13
    vector<int> kha_nang; // phong co the lam viec

public:

    Doctor(){}

    Doctor(int id, string name,  vector<int> lich_nghi,  vector<int> lich_truc,  vector<int> lich_lam_viec,  vector<int> kha_nang){
        this->id = id;
        this->name = name;
        this->lich_nghi = lich_nghi;
        this->lich_truc = lich_truc;
        this->lich_lam_viec = lich_lam_viec;
        this->kha_nang = kha_nang;
    }

    Doctor(int id, string name){
        this->id = id;
        this->name = name;
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

    vector<int> getLichNghi(){
      return lich_nghi;
    }

    void setLichNghi(vector<int> lich_nghi){
      this->lich_nghi = lich_nghi;
    }

    vector<int> getLichTruc(){
      return lich_truc;
    }

    void setLichTruc(vector<int> lich_truc){
      this->lich_truc = lich_nghi;
    }

    vector<int> getLichLamViec(){
      return lich_lam_viec;
    }

    void setLichLamViec(vector<int> lich_lam_viec){
      this->lich_lam_viec = lich_lam_viec;
    }

    vector<int> getKhaNang(){
        return kha_nang;
    }

    void setKhaNang(vector<int> kha_nang){
        this->kha_nang = kha_nang;
    }
    void addKhaNang(int id_room){
        this->kha_nang.push_back(id_room);
    }

    friend istream &operator>>(istream &read, Doctor &doctor){
        return read;
    }

    friend ostream &operator<<(ostream &write,const Doctor &doctor){
        write << doctor.id << ": " << doctor.name << '\n';
        write << "Lich truc : ";
        for(auto i: doctor.lich_truc){
            write << i << " ";
        }
        write << "\nLich nghi :";
        for(auto i:doctor.lich_nghi){
            write << i << " ";
        }
        write << "\nKha nang: ";
        for(auto i:doctor.kha_nang){
            write << i << " ";
        }
        write << "\nLich lam viec :";
        for(auto i:doctor.lich_lam_viec){
            write << i << " ";
        }
        write << "\n";
        return write;
    }


};
