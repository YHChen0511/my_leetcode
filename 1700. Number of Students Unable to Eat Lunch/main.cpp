#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        while(!students.empty()){
            int n = students.size(), i = 0;
            bool flag = false;
            while(i<n){ 
                if(students[0] == sandwiches[0]){
                    students.erase(students.begin());
                    sandwiches.erase(sandwiches.begin());
                    flag = true;
                } else{
                    students.push_back(students[0]);
                    students.erase(students.begin());
                }
                i++;
            }
            if(!flag){
                return students.size();
            }
        }
        return 0;
    }
};