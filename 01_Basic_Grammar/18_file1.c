/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2025-04-11 21:22:36
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-11 18:14:23
 * @Description: file content
 */

#include <stdio.h>
#include <unistd.h>

typedef struct person
{
    char name[20];
    int age;
    char gender;
}Person;

static Person person = {
    "Clark",
    25,
    'M'
};

int save_total_score()
{
    FILE *fp;
    fp = fopen("test.txt", "r+");
    if (fp == NULL)
    {
        fp = fopen("test.txt", "w+");
        if (NULL == fp)
        {
            printf("Error! opening file\n");
            return -1;
        }
    }

    size_t len = fwrite(&person, 1, sizeof(unsigned int), fp);
    printf("fwrite len[%lu] name[%s] age[%d] gender[%c]\n", len, person.name, person.age, person.gender);

    fclose(fp);
    return 0;
}

int get_total_score()
{
    FILE *fp;
    fp = fopen("test.txt", "r+");
    if (fp == NULL)
    {
        fp = fopen("test.txt", "w+");
        if (NULL == fp)
        {
            printf("Error! opening file\n");
            return -1;
        }
    }

    size_t len = fread(&person, 1, sizeof(unsigned int), fp);
    printf("fread len[%lu] name[%s] age[%d] gender[%c]\n", len, person.name, person.age, person.gender);

    fclose(fp);
    return 0;
}

int main()
{
    save_total_score();

    get_total_score();
    return 0;
}
