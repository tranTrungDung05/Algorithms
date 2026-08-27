/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* employee = nullptr;

        for(Employee* e : employees){
            if(e->id == id){
                employee = e;
                break;
            }
        }

        int importance = employee->importance;

        for(int i = 0; i < employee->subordinates.size(); i++){
            int subId = employee->subordinates[i];

            importance += getImportance(employees, subId);
        }

        return importance;
    }
};
