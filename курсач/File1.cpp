#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <string>
typedef struct
{
  char line[100];
  char day[100];
  char name[100];
  int pairNum;
  char pairType[100];
  char teacherName[100];
  void toString()
  {
    printf("\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA\n", line, day, name, pairNum, pairType, teacherName);
  }
} Subject, ss[30];
void addByNum();
void addElement();
void defaultPrintMenu(const char *str_array[], int a);
void printMenu(const char *str_array[], int var, int a);
void ifEnter(int var);
void print();
void deleteByNum();
void find();
void razb(char *s, char *massl[]);
void createFile();
void exiT();
void deleteFile();
void copyToBackUp();
void recovery();
void deleteBySetNum();
void changeDay();
void printTopTable();
void printAboutLections();
void sortByTeachers();
int comparator(const void *v1, const void *v2);
void countFriday();
int _tmain(int argc, _TCHAR *argv[])
{
  const char *str_array[] = {"Create file",
                             "Add element",
                             "Add by number",
                             "Print all",
                             "Delete by number",
                             "Delete file",
                             "Copy to backup file",
                             "Recovery from a backup file",
                             "Delete by set subject",
                             "Change day and number of pair by subject",
                             "Informaton about lections",
                             "Sort by teachers",
                             "Count of pairs at Friday",
                             "Exit"};

  int var = 0;
  int a = 14;
  defaultPrintMenu(str_array, a);
  for (;;)
  {
    switch (getch())
    {
    case 72:
      var--;
      if (var == -1)
      {
        var = a - 1;
      }
      printMenu(str_array, var, a);

      break;
    case 80:
      var++;
      if (var == a)
      {
        var = 0;
      }
      printMenu(str_array, var, a);
      break;
    case 13:
      ifEnter(var);
      break;
    case 75:
      exit(-1);
      break;
    }
  }

  return 0;
}
void defaultPrintMenu(const char *str_array[], int a)
{
  printf("-->%s\n", str_array[0]);
  for (int i = 1; i < a; i++)
  {
    printf("   %s\n", str_array[i]);
  }
}
void printMenu(const char *str_array[], int var, int a)
{
  system("cls");
  for (int i = 0; i < a; i++)
  {
    if (i == var)
    {
      printf("-->%s\n", str_array[i]);
    }
    else
    {
      printf("   %s\n", str_array[i]);
    }
  }
  return;
}
void ifEnter(int var)
{
  switch (var)
  {
  case 0:
    createFile();
    break;
  case 1:
    addElement();
    break;
  case 2:
    addByNum();
    break;
  case 3:
    print();
    break;
  case 4:
    deleteByNum();
    break;
  case 5:
    deleteFile();
    break;
  case 6:
    copyToBackUp();
    break;
  case 7:
    recovery();
    break;
  case 8:
    deleteBySetNum();
    break;
  case 9:
    changeDay();
    break;
  case 10:
    printAboutLections();
    break;
  case 11:
    sortByTeachers();
    break;
   case 12:
    countFriday();
    break;
  case 13:
    exiT();
    break;
  default:
    break;
  }
}
void addElement()
{
  FILE *f;
  f = fopen("test.csv", "at");
  Subject p;
  puts("Over the line or under the line");
  fflush(stdin);
  scanf("%s", &p.line);
  puts("Set day of week");
  fflush(stdin);
  scanf("%s", &p.day);
  puts("Set name of subject");
  fflush(stdin);
  scanf("%s", &p.name);
  puts("Set number of pair");
  fflush(stdin);
  scanf("%d", &p.pairNum);
  puts("Set type of pair (lection or practice)");
  fflush(stdin);
  scanf("%s", &p.pairType);
  puts("Set full name of teacher");
  fflush(stdin);
  scanf("%s", &p.teacherName);
  fprintf(f, "%s;%s;%s;%d;%s;%s;\n", p.line, p.day, p.name, p.pairNum, p.pairType, p.teacherName);
  fclose(f);
  fflush(stdin);
  return;
}
void addByNum()
{
  char **words = new char *[100];
  for (int i = 0; i < 100; i++)
  {
    words[i] = new char[200];
  }
  char *temp = new char[100];

  FILE *f1;
  FILE *f2;
  f1 = fopen("test.csv", "rt");
  f2 = fopen("test1.csv", "at");
  int i, m, length = 0;
  while (fscanf(f1, "%s\n", temp) != EOF)
    length++;
  fseek(f1, 0, 0);
  Subject p;
  puts("Input number: ");
  scanf("%d", &m);
  if (m > length || m <= -1)
  {
    puts("There is no such number");
    fclose(f1);
    fclose(f2);
    return;
  }

  char *copy = new char[100];
  for (int i = 0; i < m; i++)
  {
    fscanf(f1, "%s\n", temp);
    strcpy(copy, temp);
    razb(temp, words);
    // printf("%s;%s;%s;%d;%s;%s\n", p.line, p.day, p.name, p.pairNum, p.pairType, p.teacherName);
    fprintf(f2, "%s\n", copy);
  }

  puts("Over the line or under the line");
  fflush(stdin);
  scanf("%s", words[0]);
  puts("Set day of week");
  fflush(stdin);
  scanf("%s", words[1]);
  puts("Set name of subject");
  fflush(stdin);
  scanf("%s", words[2]);
  puts("Set number of pair");
  fflush(stdin);
  scanf("%s", words[3]);
  puts("Set type of pair (lection or practice)");
  fflush(stdin);
  scanf("%s", words[4]);
  puts("Set full name of teacher");
  fflush(stdin);
  scanf("%s", words[5]);
  fprintf(f2, "%s;%s;%s;%s;%s;%s;\n", words[0], words[1], words[2], words[3], words[4], words[5]);

  while (fscanf(f1, "%s\n", temp) != EOF)
  {
    razb(temp, words);
    fprintf(f2, "%s;%s;%s;%s;%s;%s;\n", words[0], words[1], words[2], words[3], words[4], words[5]);
  }
  fclose(f1);

  fclose(f2);

  if (remove("test.csv") != 0)
  {
    printf("delete error\n");
  }

  if (rename("test1.csv", "test.csv") != 0)
  {
    printf("rename error");
  }
  delete[] temp;
  for (int i = 0; i < 100; i++)
  {
    delete[] words[i];
  }
  delete[] words;
}
void razb(char *s, char *massl[])

{

  int k = 0;

  char *t;

  t = strtok(s, ";");

  while (t != 0)
  {

    strcpy(massl[k], t);

    k++;

    t = strtok(NULL, ";");
  }

  return;
}
void print()
{
  char **words = new char *[100];
  for (int i = 0; i < 100; i++)
  {
    words[i] = new char[200];
  }
  char *temp = new char[100];
  FILE *f2;
  f2 = fopen("test.csv", "rt");
  Subject p;
  printTopTable();
  while (fscanf(f2, "%s\n", temp) != EOF)
  {
    razb(temp, words);
    printf("\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA\n", words[0], words[1], words[2], words[3], words[4], words[5]);

    printf("\xCC");
    for (int i = 0; i < 95; i++)
    {
      printf("\xCD");
    }

    // printf("\xCC");
    printf("\xB9");
    printf("\n");
  }
  fclose(f2);
  delete[] temp;
  for (int i = 0; i < 100; i++)
  {
    delete[] words[i];
  }
  delete[] words;
}
void deleteByNum()
{
  char *temp = new char[30];
  Subject p;
  FILE *f1, *f2;
  f1 = fopen("test.csv", "rt");
  int num, n = 0;
  puts("Input number");
  scanf("%d", &num);
  while (fscanf(f1, "%s\n", temp) != EOF)
    n++;
  fseek(f1, 0, 0);
  if (num < n && num > -1)
  {
    f2 = fopen("test1.csv", "at");
    for (int i = 0; i <= num - 1; i++)
    {
      fscanf(f1, "%s\n", temp);
      fprintf(f2, "%s\n", temp);
    }
    fscanf(f1, "%s\n", temp);
    while (fscanf(f1, "%s\n", temp) != EOF)
    {
      fprintf(f2, "%s\n", temp);
    }
    fclose(f1);
    fclose(f2);
    if (remove("test.csv") != 0)
    {
      printf("delete error\n");
    }

    if (rename("test1.csv", "test.csv") != 0)
    {
      printf("rename error");
    }
  }
  else
  {
    puts("There is no such number");
    fclose(f1);
  }
  delete[] temp;
}

void createFile()
{
  FILE *f;
  if ((f = fopen("test.csv", "at")) != NULL)
  {
    puts("File created");
    fclose(f);
  }
  else
  {
    stderr;
  }
}
void exiT()
{
  exit(0);
}
void deleteFile()
{
  if (remove("test.csv") != 0)
  {
    printf("delete error\n");
  }
  else
  {
    puts("File deleted");
  }
}
void copyToBackUp()
{
  FILE *f1;
  FILE *f2;
  if ((f1 = fopen("test.csv", "rt")) != NULL)
  {
    f2 = fopen("res.csv", "wt");
    char *temp = new char[100];
    while (fscanf(f1, "%s\n", temp) != EOF)
    {
      fprintf(f2, "%s\n", temp);
    }

    fclose(f2);
    delete[] temp;
    puts("Done");
  }
  else
  {
    puts("There is no main file");
  }

  fclose(f1);
}
void recovery()
{
  FILE *f1;
  FILE *f2;
  f1 = fopen("test.csv", "wt");
  if ((f2 = fopen("res.csv", "rt")) != NULL)
  {
    char *temp = new char[100];
    while (fscanf(f2, "%s\n", temp) != EOF)
    {
      fprintf(f1, "%s\n", temp);
    }

    fclose(f2);
    delete[] temp;
    puts("Done");
  }
  else
  {
    puts("There is no backup file");
  }
  fclose(f1);
}
void deleteBySetNum()
{
  int k = 0;
  char *tempIn = new char[100];
  char *temp = new char[100];
  char *tempCopy = new char[100];
  char **words = new char *[100];
  for (int i = 0; i < 100; i++)
  {
    words[i] = new char[200];
  }
  puts("Input subject:");
  gets(tempIn);
  FILE *f1, *f2;
  f1 = fopen("test.csv", "rt");
  f2 = fopen("test1.csv", "at");
  while (fscanf(f1, "%s\n", temp) != EOF)
  {
    strcpy(tempCopy, temp);
    razb(temp, words);
    if (strcmp(tempIn, words[2]) != 0)
    {
      fprintf(f2, "%s\n", tempCopy);
    }
    else if (strcmp(tempIn, words[2]) == 0)
    {
      k++;
    }
  }
  if (k == 0)
  {
    puts("There is no such subject");
  }

  fclose(f1);
  fclose(f2);
  if (remove("test.csv") != 0)
  {
    printf("delete error\n");
  }

  if (rename("test1.csv", "test.csv") != 0)
  {
    printf("rename error");
  }

  delete[] temp;
  delete[] tempIn;
  delete[] tempCopy;
  for (int i = 0; i < 100; i++)
  {
    delete[] words[i];
  }
  delete[] words;
}
void changeDay()
{
  int k = 0;
  char *tempInSbj = new char[100];
  char *tempInDay = new char[100];
  char *tempInNum = new char[100];
  char *temp = new char[100];
  char *tempCopy = new char[100];
  char **words = new char *[100];
  for (int i = 0; i < 100; i++)
  {
    words[i] = new char[200];
  }
  puts("Input subject:");
  gets(tempInSbj);
  puts("Input new day:");
  gets(tempInDay);
  puts("Input pair number:");
  gets(tempInNum);
  FILE *f1, *f2;
  f1 = fopen("test.csv", "rt");
  f2 = fopen("test1.csv", "at");
  while (fscanf(f1, "%s\n", temp) != EOF)
  {
    strcpy(tempCopy, temp);
    razb(temp, words);
    if (strcmp(tempInSbj, words[2]) == 0)
    {
      strcpy(words[1], tempInDay);
      strcpy(words[3], tempInNum);
      fprintf(f2, "%s;%s;%s;%s;%s;%s;\n", words[0], words[1], words[2], words[3], words[4], words[5]);
      k++;
    }
    else if (strcmp(tempInSbj, words[2]) != 0)
    {
      fprintf(f2, "%s\n", tempCopy);
    }
  }
  if (k == 0)
  {
    puts("There is no such subject");
  }

  fclose(f1);
  fclose(f2);
  if (remove("test.csv") != 0)
  {
    printf("delete error\n");
  }

  if (rename("test1.csv", "test.csv") != 0)
  {
    printf("rename error");
  }

  delete[] tempInSbj, tempInDay, tempInNum, temp, tempCopy;

  for (int i = 0; i < 100; i++)
  {
    delete[] words[i];
  }
  delete[] words;
}
void printTopTable()
{
  printf("\xC9");
  for (int i = 0; i < 95; i++)
  {
    printf("\xCD");
  }
  printf("\xBB");
  printf("\n");
  printf("\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA\n", "Line", "Day", "Subject", "Number of pair", "Type of pair", "Full name");
  printf("\xCC");
  for (int i = 0; i < 95; i++)
  {
    printf("\xCD");
  }
  printf("\xB9");
  printf("\n");
}
void printAboutLections()
{
  char **words = new char *[100];
  for (int i = 0; i < 100; i++)
  {
    words[i] = new char[200];
  }
  char *temp = new char[100];
  FILE *f2;
  f2 = fopen("test.csv", "rt");
  printTopTable();
  while (fscanf(f2, "%s\n", temp) != EOF)
  {
    razb(temp, words);
    if (strcmp(words[4], "lection") == 0)
    {
      razb(temp, words);
      printf("\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15s\xBA\n", words[0], words[1], words[2], words[3], words[4], words[5]);

      printf("\xCC");
      for (int i = 0; i < 95; i++)
      {
        printf("\xCD");
      }
      printf("\xB9");
      printf("\n");
    }
  }
  fclose(f2);
  delete[] temp;
  for (int i = 0; i < 100; i++)
  {
    delete[] words[i];
  }
  delete[] words;
}
void sortByTeachers()
{
  char **words = new char *[100];
  for (int i = 0; i < 100; i++)
  {
    words[i] = new char[200];
  }
  int n = 0;
  char *temp = new char[100];
  FILE *f;
  f = fopen("test.csv", "rt");
  while (fscanf(f, "%s\n", temp) != EOF)
    n++;
  fseek(f, 0, 0);
  Subject s[n];
  int i = 0;
  while (fscanf(f, "%s\n", temp) != EOF)
  {
    razb(temp, words);

    strcpy(s[i].line, words[0]);
    strcpy(s[i].day, words[1]);
    strcpy(s[i].name, words[2]);
    s[i].pairNum = atoi(words[3]);
    strcpy(s[i].pairType, words[4]);
    strcpy(s[i].teacherName, words[5]);
    i++;
  }

  qsort(s, n, sizeof(Subject), comparator);
  printTopTable();
  for (int i = 0; i < n; i++)
  {
    printf("\xBA%-15s\xBA%-15s\xBA%-15s\xBA%-15d\xBA%-15s\xBA%-15s\xBA\n", s[i].line, s[i].day, s[i].name, s[i].pairNum, s[i].pairType, s[i].teacherName);
    printf("\xCC");
    for (int i = 0; i < 95; i++)
    {
      printf("\xCD");
    }
    printf("\xB9");
    printf("\n");
  }
  fclose(f);
  delete[] temp;
  for (int i = 0; i < 100; i++)
  {
    delete[] words[i];
  }
  delete[] words;
  system("pause");
}
int comparator(const void *a, const void *b)
{
  // Subject s;
  return strcmp(((Subject *)a)->teacherName, ((Subject *)b)->teacherName);
}
void countFriday()
{
  int count = 0;
  char **words = new char *[100];
  for (int i = 0; i < 100; i++)
  {
    words[i] = new char[200];
  }
  char *temp = new char[100];
  FILE *f;
  f = fopen("test.csv", "rt");
  while (fscanf(f, "%s\n", temp) != EOF)
  {
    razb(temp, words);
    if (strcmp(words[1], "Friday") == 0)
    {
      count++;
    }
  }
  if (count == 0)
  {
    puts("There is no pairs on Friday");
  }
  else
  {
    printf("There is %d pairs at Friday", count);
  }
  fclose(f);
  delete[] temp;
  for (int i = 0; i < 100; i++)
  {
    delete[] words[i];
  }
  delete[] words;
}