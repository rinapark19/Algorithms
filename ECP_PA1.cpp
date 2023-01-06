// PA1 2021312460 Park Chae Rin
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Student{ 
	char nickname;
	float height;
	float weight;
};

void find_best_bmi_student(Student student_array[], char *best_bmi_student) 
{
	float best = 21;
	float bmi[10] = {0};
	
	for(int i=0; i < 10; i++)
	{
		bmi[i] = student_array[i].weight / pow(student_array[i].height/100, 2); 
 	}
 	
 	Student best_bmi_s = student_array[0];
 	
 	for(int i=1; i < 10; i++)
 	{
 		float best_bmi = best_bmi_s.weight / pow(best_bmi_s.height/100, 2);
 		
 		if(abs(best-bmi[i]) < abs(best-best_bmi))
 		{
 			best_bmi_s = student_array[i];
		 }		
	}
	
	*best_bmi_student = best_bmi_s.nickname;	
}

void find_lowest_highest_bmi_student(Student student_array[], char &lowest_bmi_student, char &highest_bmi_student)
{
	float bmi[10] = {0};
	
	for(int i=0; i < 10; i++)
	{
		bmi[i] = student_array[i].weight / pow(student_array[i].height/100, 2);
 	}
 	
 	Student lowest_bmi_s = student_array[0];
 	
 	
 	for(int i = 1; i < 10; i++)
 	{
 		float lowest_bmi = lowest_bmi_s.weight / pow(lowest_bmi_s.height/100, 2);
 		
 		if(bmi[i] < lowest_bmi)
 		{
 			lowest_bmi_s = student_array[i];
		}		
	}
	
	lowest_bmi_student = lowest_bmi_s.nickname;
	
	Student highest_bmi_s = student_array[0];
	
	for(int i = 1; i < 10; i++)
	{
		float highest_bmi = highest_bmi_s.weight / pow(highest_bmi_s.height/100, 2);
		
		if(bmi[i] > highest_bmi)
		{
			highest_bmi_s = student_array[i];
		}
	}
	
	highest_bmi_student = highest_bmi_s.nickname;

}

int main()
{
	Student student_array[10];
	student_array[0].nickname = 'A';
	student_array[1].nickname = 'B';
	student_array[2].nickname = 'C';
	student_array[3].nickname = 'D';
	student_array[4].nickname = 'E';
	student_array[5].nickname = 'F';
	student_array[6].nickname = 'G';
	student_array[7].nickname = 'H';
	student_array[8].nickname = 'I';
	student_array[9].nickname = 'J';
		
	char best_bmi_student;
	char lowest_bmi_student;
	char highest_bmi_student;
	
	int seed;
	cout << "Input Seed: ";
	cin >> seed;
	srand(seed);
	
	int i = 0;
	for(i; i < 10; i++)
	{
		student_array[i].height = 160 + rand() % 20;
		student_array[i].weight = 50 + rand() % 20;
	}
	
	
	find_best_bmi_student(student_array, &best_bmi_student);
	cout << "The best bmi student: " << best_bmi_student << endl;
	
	find_lowest_highest_bmi_student(student_array, lowest_bmi_student, highest_bmi_student);
	cout << "The lowest bmi student: " << lowest_bmi_student << endl;
	cout << "The highest bmi student: " << highest_bmi_student << endl;
	
	return 0;
}
