#include "Instance.h"
#include "Solution.h"
#include "Solver.h"

using namespace std;

int main() {
    srand(time(NULL));
    vector<string> link_file = {"C:/Users/Asus/Documents/QTProject/Hospital_Schedule/Doctor.csv",
                                "C:/Users/Asus/Documents/QTProject/Hospital_Schedule/Room.csv",
                                "C:/Users/Asus/Documents/QTProject/Hospital_Schedule/AbilityMatrix.csv",
                                "C:/Users/Asus/Documents/QTProject/Hospital_Schedule/JobSchedule.csv"
                               };

    Solution s_data = Solution();
    s_data.readFile(link_file[3]);
    s_data.display();

    Instance instance = Instance();
    instance.readNameDoctors(link_file[0]);
    instance.readInforRooms(link_file[1]);
    instance.readCapacityDoctors(link_file[2]);

    
    Solver Solver(&instance);
    Solver.StartConstruction();
    Solver.MixSolution(s_data);
    Solver.display();



    return 0;
}


