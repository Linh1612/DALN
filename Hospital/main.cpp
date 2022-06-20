#include <bits/stdc++.h>

#include "instance.h"
#include "solver.h"

using namespace std;

int main(int argc, char const *argv[]) {
    vector<string> links = {"C:/Users/Asus/Documents/QTProject/Hospital/data/Doctor_1.csv",
                            "C:/Users/Asus/Documents/QTProject/Hospital/data/Room_1.csv",
                            "C:/Users/Asus/Documents/QTProject/Hospital/data/AbilityMatrix_1.csv",
                            "C:/Users/Asus/Documents/QTProject/Hospital/data/JobSchedule_1.csv",
                            "C:/Users/Asus/Documents/QTProject/Hospital/output/result.csv",
                            "C:/Users/Asus/Documents/QTProject/Hospital/output/error.csv",
                            "C:/Users/Asus/Documents/QTProject/Hospital/output/schedulePersonal.csv"};

    Instance instance;
    instance.readNameDoctors(links[0]);
    instance.readInforRooms(links[1]);
    instance.readCapacityDoctors(links[2]);

    Solver Solver(&instance);

    Solver.DataFromFile(links[3]);
    //Solver.StartConstruction();
    Solver.LocalSearch();
    Solver.display();
    Solver.WriteFile(links[4], links[5], links[6]);
    cout << "Finish!\n";
    return 0;
}
