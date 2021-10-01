#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char *str, int n)
{
    int ch, i;
    i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

bool remaind_hour(char *time_str, int *minutes)
{
    int hour, minute;
    printf("Enter 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    sprintf(time_str, "%d:%d", hour, minute);
    *minutes = hour * 60 + minute;
    return true;
}

bool remaind_day(char *day_str, int *day)
{

    printf("Enter day and reminder: ");
    scanf("%2d", day);
    if (*day < 0 || *day > 31)
    {
        printf("day is error\n");
        return false;
    }

    sprintf(day_str, "%2d", *day);
    return true;
}

bool remaind_date(char *time_str, int *days)
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, day;
    printf("Enter an date(xx-xx): ");
    scanf("%2d -%2d", &month, &day);
    sprintf(time_str, "%d-%d", month, day);
    *days = 0;
    for (int i = 0; i < month - 1; i++)
    {
        *days += months[i];
    }
    *days += day;
    return true;
}
int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        remaind_date(day_str, &day);
        if (day == 0)
        {
            break;
        }
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
        {
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        }
        for (j = num_remind; j > i; j--)
        {
            strcpy(reminders[j], reminders[j - 1]);
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
    {
        printf(" %s\n", reminders[i]);
    }
    return 0;
}