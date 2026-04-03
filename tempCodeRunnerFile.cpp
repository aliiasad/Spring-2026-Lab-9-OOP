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

        void display();
        string getName();
        int getProjects();

        ProjectManager& operator++();
        ProjectManager& operator--();
        ProjectManager operator+(const ProjectManager&);
        ProjectManager operator-(const ProjectManager&);
        ProjectManager operator*(const ProjectManager&);
        ProjectManager operator/(const ProjectManager&);
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

ProjectManager ProjectManager :: operator+(const ProjectManager& dummy)   {
    ProjectManager temp;
    temp.completedProjects = this->completedProjects + dummy.completedProjects;
    return temp;
}

ProjectManager ProjectManager :: operator-(const ProjectManager& dummy)   {
    ProjectManager temp;
    temp.completedProjects = this->completedProjects - dummy.completedProjects;
    return temp;
}

ProjectManager ProjectManager :: operator*(const ProjectManager& dummy)   {
    ProjectManager temp;
    temp.completedProjects = this->completedProjects * dummy.completedProjects;
    return temp;
}

ProjectManager ProjectManager :: operator/(const ProjectManager& dummy)   {
    if (dummy.completedProjects == 0)   {
        cout << "Error: Division by zero." << endl;
        return ProjectManager("Error", 0);
    }   
    ProjectManager temp;
    temp.completedProjects = this->completedProjects / dummy.completedProjects;
    return temp;
}

ProjectManager& ProjectManager :: operator++()  {
    completedProjects++;
    return *this;
}

ProjectManager& ProjectManager :: operator--()  {
    if (completedProjects > 0)  {
        completedProjects--;
    }
    return *this;
}

void ProjectManager :: display()    {
    cout << "Manager Name: " << name << endl;
    cout << "Completed Projects: " << completedProjects << endl;
    return;
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

    ProjectManager diff = A - B;
    cout << "Project Difference: " << diff.getProjects() << endl;

    ProjectManager prod = A * B;
    cout << "Productivity Score: " << prod.getProjects() << endl;

    ProjectManager ratio = A / B;
    cout << "Efficiency Ratio: " << ratio.getProjects() << endl;
    return 0;
}