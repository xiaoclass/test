// 轮班监督委员会问题，已解决
#include <iostream>  
#include <vector>
#include <algorithm>

using namespace std;

// Shift结构体表示一段时间范围和责任学生
struct Shift {
    int start;   // 起始时间
    int end;     // 结束时间
    int student; // 责任学生编号  
}; 

// 比较函数用于对Shift对象排序
bool compareShifts(const Shift &a, const Shift &b) { 
    return a.end < b.end; 
}

// 求解最短班委会函数  
vector<int> findSupervisoryCommittee(vector<Shift> shifts) {  
    // 按结束时间对shifts排序
    sort(shifts.begin(), shifts.end(), compareShifts);  

    vector<int> committee;      // 结果:最短班委会
    int currentEndTime = -1;   // 当前已经覆盖的结束时间  

    // 遍历排序后的shifts
    for (const Shift &shift : shifts) {  
        // 如果当前shift的起始时间在当前已经覆盖的结束时间之后
        // 则需要加入当前的学生到最短班委会,并更新当前结束时间
        if (shift.start > currentEndTime) {  
            committee.push_back(shift.student);
            currentEndTime = shift.end;  
        }
    }

    return committee;
}

// 主函数
int main() {
    int n;     // 班次数量
    cin >> n;  

    vector<Shift> shifts; // 班次时间表

    // 读取输入的班次时间表
    for (int i = 0; i < n; i++) {
        int start, end, student;
        cin >> start >> end >> student;
        shifts.push_back({start, end, student});
    }

    // 求解最短班委会
    vector<int> committee = findSupervisoryCommittee(shifts);  
    
    // 输出最短班委会成员数及成员列表
    cout << committee.size() << endl;
    for (int student : committee) {
        cout << student << endl;
    }
}
