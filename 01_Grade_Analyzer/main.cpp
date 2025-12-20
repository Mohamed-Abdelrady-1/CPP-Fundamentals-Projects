#include <iostream>
using namespace std;

struct StStudentStatus
{
    int PassedCount = 0;
    int FailedCount = 0;
};

void ReadGrades(float Grades[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Please Enter Grade for Subject " << i + 1 << ": ";
        cin >> Grades[i];
    }
}

float CalculateAverage(float Grades[5])
{
    float Sum = 0;
    for (int i = 0; i < 5; i++)
    {
        Sum += Grades[i];
    }
    return Sum / 5;
}

float GetMaxGrade(float Grades[5])
{
    float MaxVal = Grades[0];
    for (int i = 1; i < 5; i++)
    {
        if (Grades[i] > MaxVal)
            MaxVal = Grades[i];
    }
    return MaxVal;
}

float GetMinGrade(float Grades[5])
{
    float MinVal = Grades[0];
    for (int i = 1; i < 5; i++)
    {
        if (Grades[i] < MinVal)
            MinVal = Grades[i];
    }
    return MinVal;
}

StStudentStatus GetPassFailStatus(float Grades[5])
{
    StStudentStatus Status;
    for (int i = 0; i < 5; i++)
    {
        if (Grades[i] >= 50)
            Status.PassedCount++;
        else
            Status.FailedCount++;
    }
    return Status;
}

void PrintSummary(StStudentStatus Status, float Avg, float Max, float Min)
{
    cout << "\n*************************************\n";
    cout << "          Student Report             \n";
    cout << "*************************************\n";
    cout << "Average Grade : " << Avg << endl;
    cout << "Highest Grade : " << Max << endl;
    cout << "Lowest Grade  : " << Min << endl;
    cout << "Passed Subjects: " << Status.PassedCount << endl;
    cout << "Failed Subjects: " << Status.FailedCount << endl;
    cout << "*************************************\n";
}

int main()
{
    float Grades[5];
    ReadGrades(Grades);

    float Avg = CalculateAverage(Grades);
    float Max = GetMaxGrade(Grades);
    float Min = GetMinGrade(Grades);
    StStudentStatus Status = GetPassFailStatus(Grades);

    system("cls");
    PrintSummary(Status, Avg, Max, Min);

    return 0;
}