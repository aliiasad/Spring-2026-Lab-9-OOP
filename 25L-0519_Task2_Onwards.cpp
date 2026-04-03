# include <iostream>
# include <cstring>
using namespace std;

class ProjectManager    {
    private:
        string name;
        int completedProjects;
    public:
        ProjectManager();
        ProjectManager(string, int);
        
        string getName();

        void display();
        int getProjects();
        friend int efficiency(const ProjectManager&, const ProjectManager&);

        // task 2
        friend ProjectManager& operator++(ProjectManager&);
        friend ProjectManager& operator--(ProjectManager&);
        friend ProjectManager operator+(const ProjectManager&, const ProjectManager&);
        friend int operator-(const ProjectManager&, const ProjectManager&);
        friend int operator*(const ProjectManager&, const ProjectManager&);
        friend int operator/(const ProjectManager&, const ProjectManager&);

        // task 4
        friend bool operator==(const ProjectManager&, const ProjectManager&);
        friend bool operator!=(const ProjectManager&, const ProjectManager&);
        friend bool operator>(const ProjectManager&, const ProjectManager&);

        // task 5
        ProjectManager& operator=(const ProjectManager&);
        ProjectManager& operator+=(const ProjectManager&);
        ProjectManager& operator-=(const ProjectManager&);  
};

ProjectManager :: ProjectManager()  {
    name = "Unknown";
    completedProjects = 0;
}

ProjectManager :: ProjectManager(string name, int completedProjects) {
    this->name = name;
    this->completedProjects = completedProjects;
}

int ProjectManager :: getProjects() { 
    return completedProjects; 
}

string ProjectManager :: getName() { 
    return name; 
}

ProjectManager operator+(const ProjectManager& dummy1, const ProjectManager& dummy2)   {
    ProjectManager temp;
    temp.completedProjects = dummy1.completedProjects + dummy2.completedProjects;
    return temp;
}

int operator-(const ProjectManager& dummy1, const ProjectManager& dummy2) {
    return dummy1.completedProjects - dummy2.completedProjects;
}

int operator*(const ProjectManager& dummy1, const ProjectManager& dummy2) {
    return dummy1.completedProjects * dummy2.completedProjects;
}

int operator/(const ProjectManager& dummy1, const ProjectManager& dummy2) {
    if (dummy2.completedProjects == 0) {
        cout << "Error: Division by zero." << endl;
        return 0;
    }
    return dummy1.completedProjects / dummy2.completedProjects;
}

ProjectManager& operator++(ProjectManager& dummy)  {
    dummy.completedProjects++;
    return dummy;
}

ProjectManager& operator--(ProjectManager& dummy)  {
    if (dummy.completedProjects > 0)  {
        dummy.completedProjects--;
    }
    return dummy;
}

int efficiency(const ProjectManager& dummy1, const ProjectManager& dummy2) {
    if (dummy2.completedProjects == 0) {
        cout << "Error: Division by zero." << endl;
        return 0;
    }
    return dummy1.completedProjects / dummy2.completedProjects;
}

void ProjectManager :: display()    {
    cout << "Manager Name: " << name << endl;
    cout << "Completed Projects: " << completedProjects << endl;
    return;
}

// task 4
bool operator==(const ProjectManager& dummy1, const ProjectManager& dummy2) {
    return dummy1.completedProjects == dummy2.completedProjects;
}

bool operator!=(const ProjectManager& dummy1, const ProjectManager& dummy2) {
    return dummy1.completedProjects != dummy2.completedProjects;
}

bool operator>(const ProjectManager& dummy1, const ProjectManager& dummy2) {
    return dummy1.completedProjects > dummy2.completedProjects;
}

// task 5
ProjectManager& ProjectManager :: operator=(const ProjectManager& dummy) {
    if (this != &dummy) {
        name = dummy.name;
        completedProjects = dummy.completedProjects;
        cout << name << " assigned data from " << dummy.name << endl;
    }
    return *this;
}

ProjectManager& ProjectManager :: operator+=(const ProjectManager& dummy) {
    completedProjects += dummy.completedProjects;
    return *this;
}

ProjectManager& ProjectManager :: operator-=(const ProjectManager& dummy) {
    completedProjects -= dummy.completedProjects;
    if (completedProjects < 0)
        completedProjects = 0;
    return *this;
}

// task 3
class ProjectLog {
    private:
        string managerName;
        string projectName;
        int priorityLevel;
    public:
        friend void printLog(const ProjectLog&);
        friend ostream& operator<<(ostream&, const ProjectLog&);
        friend istream& operator>>(istream&, ProjectLog&);
};

istream& operator>>(istream& in, ProjectLog& dummy) {
    cout << "Enter Manager Name: ";
    getline(in, dummy.managerName);
    cout << "Enter Project: ";
    getline(in, dummy.projectName);
    cout << "Enter Priority Level: ";
    in >> dummy.priorityLevel;

    return in;
}

ostream& operator<<(ostream& out, const ProjectLog& dummy)  {
    out << "Manager: " << dummy.managerName << endl << "Project: " << dummy.projectName << endl << "Priority: " << dummy.priorityLevel << endl;
    return out;
}

void printLog(const ProjectLog& log) {
    cout << "Manager: " << log.managerName << " | Project: " << log.projectName << " | Priority: " << log.priorityLevel << endl;
}

int main()  {
    ProjectManager A("Manager A", 10);
    ProjectManager B("Manager B", 5);

    ++A;
    cout << A.getName() << " completed a new project. Total: " << A.getProjects() << endl;

    --B;
    cout << B.getName() << " project removed. Total: " << B.getProjects() << endl;

    ProjectManager combined = A + B;
    cout << "Combined Projects: " << combined.getProjects() << endl;

    cout << "Project Difference: " << (A - B) << endl;
    cout << "Productivity Score: " << (A * B) << endl;
    cout << "Efficiency Ratio: " << efficiency(A, B) << endl;

    // task 3
    ProjectLog log;
    cin >> log;
    cout << "Processing project log..." << endl;
    cout << log;
    printLog(log);

    // task 4
    if (A == B)
    cout << "Managers are equal" << endl;
    else
    cout << "Managers are not equal" << endl;

    if (A != B)
    cout << "Managers are not equal" << endl;

    if (A > B)
    cout << A.getName() << " has more completed projects than " << B.getName() << endl;

    // task 5
    A = B;
    cout << "Manager A updated projects: " << A.getProjects() << endl;

    A += B;
    cout << "After +=: " << A.getProjects() << endl;

    A -= B;
    cout << "After -=: " << A.getProjects() << endl;
    
    return 0;
}