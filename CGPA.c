#include <stdio.h>

int main() {
    int num_subjects;
    float grade_points, credit_hours, total_points = 0.0, total_credits = 0.0, cgpa;

    // Prompt the user to enter the number of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &num_subjects);

    // Loop to input grade points and credit hours for each subject
    for(int i = 0; i < num_subjects; i++) {
        printf("Enter grade points for subject %d: ", i + 1);
        scanf("%f", &grade_points);
        printf("Enter credit hours for subject %d: ", i + 1);
        scanf("%f", &credit_hours);

        total_points += grade_points * credit_hours;
        total_credits += credit_hours;
    }

    // Calculate CGPA
    cgpa = total_points / total_credits;

    // Display the CGPA
    printf("Your CGPA is: %.2f\n", cgpa/10);

    return 0;
}
