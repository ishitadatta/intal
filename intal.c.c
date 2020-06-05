#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int convert_to_int(char ch) 
{
  return (int)(ch - 48);
}

char convert_to_char(int in) 
{
  return (char)(in + 48);
}

char* intal_add(char* intal1, char* intal2)
{
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);

  int l = (l1 > l2)? l1 + 1: l2 + 1;
  int s = (l1 > l2)? l2: l1;
  
  int i, a1, a2, rd, c = 0;
  char* res = (char*)malloc((l + 1) * sizeof(char));

  for(i = 0 ; i < s; ++i) 
  {
    a1 = convert_to_int(intal1[l1 - 1 - i]);
    a2 = convert_to_int(intal2[l2 - 1 - i]);

    rd = a1 + a2 + c;
    c = (rd > 9)? 1: 0;
    rd = (rd > 9)? rd - 10: rd;

    res[l - 1 - i] = convert_to_char(rd);
  }

  while(i < l - 1) 
  {
    if(l1 > l2) 
    {
      rd = convert_to_int(intal1[l1 - 1 - i]) + c;
      c = (rd > 9)? 1: 0;
      rd = (rd > 9)? rd - 10: rd;

      res[l - 1 - i] = convert_to_char(rd);
    } else 
    {
      rd = convert_to_int(intal2[l2 - 1 - i]) + c;
      c = (rd > 9)? 1: 0;
      rd = (rd > 9)? rd - 10: rd;

      res[l - 1 - i] = convert_to_char(rd);
    }

    ++i;
  }

  if(c != 0) 
  {
    res[0] = convert_to_char(c);
    res[l] = '\0';
  } else {
    for(i = 0; i < l - 1; ++i) 
    {
      res[i] = res[i + 1];
    }

    res = (char*)realloc(res, l * sizeof(char));
    res[l - 1] = '\0';
  }

  return res;
}

int intal_compare(char* intal1, char* intal2) 
{
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);

  if(l1 > l2)
    return 1;
  else if(l2 > l1)
    return -1;

  for(int i = 0; i < l1; ++i) 
  {
    if(intal1[i] > intal2[i])
      return 1;
    else if(intal2[i] > intal1[i])
      return -1;
  }
  
  return 0;
}

char* intal_diff(char* intal1, char* intal2)
 {
  int cmp = intal_compare(intal1, intal2);
  if(cmp == 0) 
  {
    char* res = (char*)malloc(2 * sizeof(char));
    res[0] = '0';
    res[1] = '\0';
    return res;
  } else if(cmp == -1) 
  {
    char* temp = intal1;
    intal1 = intal2;
    intal2 = temp;
  }

  int l1 = strlen(intal1);
  int l2 = strlen(intal2);

  int l = (l1 > l2)? l1: l2;
  int s = l1 + l2 - l;
  
  int i, a1, a2, rd, c = 0;
  char* res = (char*)malloc((l + 1) * sizeof(char));

  for(i = 0 ; i < s; ++i) 
  {
    a1 = convert_to_int(intal1[l1 - 1 - i]) - c;
    a2 = convert_to_int(intal2[l2 - 1 - i]);

    c = (a2 > a1)? 1: 0;
    a1 = (a2 > a1)? a1 + 10: a1;
    rd = a1 - a2;

    res[l - 1 - i] = convert_to_char(rd);
  }

  while(i < l) 
  {
    rd = convert_to_int(intal1[l1 - 1 - i]) - c;
    c = (rd > -1)? 0: 1;
    rd = (rd > -1)? rd: rd + 10;

    res[l - 1 - i] = convert_to_char(rd);

    ++i;
  }

  for(i = 0; i < l; ++i) 
  {
    if(res[i] != '0')
      break;
  }

  res[l] = '\0';
  int trim = i;
  if(trim != 0) 
  {
    for(i = 0; i <= l - trim; ++i)
      res[i] = res[i + trim];

    res = realloc(res, (l - trim + 1) * sizeof(char));
  }

  return res;
}

char* intal_multiply(char* intal1, char* intal2) 
{
  if(strcmp(intal1, "0") == 0 || strcmp(intal2, "0") == 0) 
  {
    char* res = (char*)malloc(2 * sizeof(char));
    res[0] = '0';
    res[1] = '\0';
    return res;
  }

  int i, j,rd, c = 0;
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);

  int l = l1 + l2;
  char* res = (char*)malloc((l + 1) * sizeof(char));

  for(i = 0; i < l; ++i)
    res[i] = '0';

  for(i = 0; i < l1; ++i) 
  {
    c = 0;
    for(j = 0; j < l2; ++j) 
    {
      int a1 = convert_to_int(intal1[l1 - 1 - i]);
      int a2 = convert_to_int(intal2[l2 - 1 - j]);
      int a3 = convert_to_int(res[l - 1 - i - j]);

      rd = (a1 * a2) + c + a3;
      c = rd / 10;
      rd = rd % 10;

      res[l - 1 - i - j] = convert_to_char(rd);
    }

    for(j = l2 + i; j < l2 + l1; ++j)
     {
      int a3 = convert_to_int(res[l - 1 - j]);

      rd = c + a3;
      c = rd / 10;
      rd = rd % 10;
      res[l - 1 - j] = convert_to_char(rd);
    }
  }

  res[l] = '\0';
  if(res[0] == '0') 
  {
    for(i = 0; i <= l; ++i)
      res[i] = res[i + 1];

    res = realloc(res, l * sizeof(char));
  }

  return res;
}

char* intal_mod(char* intal1, char* intal2) 
{
  int cmp = intal_compare(intal1, intal2);
  if(cmp == -1) {
    char* res = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
    strcpy(res, intal1);
    return res;
  } else if(cmp == 0)
   {
    char* res = (char*)malloc((2) * sizeof(char));
    strcpy(res, "0");
    return res;
  }

  int p = strlen(intal2);
  int stop = strlen(intal1);
  char* current = (char*)malloc((strlen(intal2) + 2) * sizeof(char));
  for(int i = 0; i < p; ++i)
    current[i] = intal1[i];
  current[p] = '\0';

  do {
    if(intal_compare(current, intal2) == -1 && p < stop) 
    {
      int len = strlen(current);
      if(strcmp(current, "0") == 0)
        len = 0;
      current[len] = intal1[p];
      current[len + 1] = '\0';
      ++p;
    }

    if(intal_compare(current, intal2) != -1)
    {
      char* res = intal_diff(current, intal2);
      while(intal_compare(res, intal2) > -1)
       {
        char* temp = res;
        res = intal_diff(res, intal2);
        free(temp);
      }
      
      strcpy(current, res);
      free(res);
    }    
  } while(p < stop);

  current = realloc(current, (strlen(current) + 1) * sizeof(char));
  current[strlen(current) + 1] = '\0';
  return current;
}

char* intal_pow(char* intal1, unsigned int n) 
{
  if(n == 0) {
    char* res = (char*)malloc(2 * sizeof(char));
    res[0] = '1';
    res[1] = '\0';
    return res;
  }

  char* res = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
  strcpy(res, intal1);

  for(int i = 1; i < n; ++i) 
  {
    char* arg = res;
    res = intal_multiply(res, intal1);
    free(arg);
  }

  return res;
}

char* intal_gcd(char* intal1, char* intal2)
 {
  char* c = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
  strcpy(c, intal1);
  char* d = (char*)malloc((strlen(intal2) + 1) * sizeof(char));
  strcpy(d, intal2);

  int flag = strcmp(c, "0");
  while(flag != 0) {
    char* temp = d;
    d = c;
    c = intal_mod(temp, c);

    free(temp);
    flag = strcmp(c, "0");
  }

  free(c);
  return d;
}

char* intal_fibonacci(unsigned int n)
 {
  char* temp1 = (char*)malloc(2 * sizeof(char));
  temp1[0] = '0';
  temp1[1] = '\0';

  if(n == 0)
    return temp1;

  char* temp2 = (char*)malloc(2 * sizeof(char));
  temp2[0] = '1';
  temp2[1] = '\0';

  if(n == 1)
    return temp2;

  for(int i = 1; i < n; ++i) {
    char* temp3 = intal_add(temp1, temp2);
    free(temp1);
    temp1 = temp2;
    temp2 = temp3;
  }

  free(temp1);
  return temp2;
}

char* intal_factorial(unsigned int n) 
{
  char* start = (char*)malloc(2 * sizeof(char));
  start[0] = '1';
  start[1] = '\0';

  if(n < 2)
    return start;

  char* res = (char*)malloc(2 * sizeof(char));
  res[0] = '1';
  res[1] = '\0';

  char* step = (char*)malloc(2 * sizeof(char));
  step[0] = '1';
  step[1] = '\0';

  for(int i = 1; i <n; ++i) 
  {
    char* temp = start;
    start = intal_add(start, step);
    free(temp);

    temp = res;
    res = intal_multiply(start, res);
    free(temp);
  }

  free(start);
  free(step);
  
  return res;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
 {
  char** c = (char**)malloc((k+1) * sizeof(char*));
  for(int i = 0; i < k + 1; ++i) {
    c[i] = (char*)malloc(2 * sizeof(char));
    c[i][0] = '0';
    c[i][1] = '\0';
  }

  c[0][0] = '1';

  for(int i = 1; i < n + 1; ++i)
  {
    int j = (i > k)? k: i;
    while(j > 0)
    {
      char* temp = c[j];
      c[j] = intal_add(c[j], c[j - 1]);
      free(temp);
      --j;
    }
  }

  char* res = (char*)malloc((strlen(c[k]) + 1) * sizeof(char));
  strcpy(res, c[k]);
  
  for(int i = 0; i < k + 1; ++i)
  {
    free(c[i]);
  }
  free(c);

  return res;
}

int intal_max(char **arr, int n)
{
  int p = 0;
  for(int i = 1; i < n; ++i)
  {
    if(intal_compare(arr[p], arr[i]) == -1)
      p = i;
  }

  return p;
}

int intal_min(char **arr, int n) 
{
  int p = 0;
  for(int i = 1; i < n; ++i)
   {
    if(intal_compare(arr[p], arr[i]) ==1)
      p = i;
  }

  return p;
}

int intal_search(char **arr, int n, const char* key) 
{
  int p = -1;
  for(int i = 0; i < n; ++i)
   {
    if(intal_compare(arr[i], (char*)key) == 0)
    {
      p = i;
      break;
    }
  }

  return p;
}

int intal_binsearch(char **arr, int n, const char* key) 
{
  int beg = 0;
  int end = n - 1;

  while(beg <= end) 
  {
    int mid = (beg + end) / 2;
    int cmp = intal_compare(arr[mid], (char*)key);
    if(cmp == 0) 
    {
      return mid;
    } else if(cmp > 0) 
    {
      end = mid - 1;
    } else 
    {
      beg = mid + 1;
    }
  }

  return -1;
}

int partition(char** arr, int l, int h)
{
  int i = l - 1;
  char* pivot = arr[h];

  for(int j = l; j < h; ++j) 
  {
    if(intal_compare(arr[j], pivot) < 0) 
    {
      ++i;
      char* temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  char* temp = arr[i + 1];
  arr[i + 1] = arr[h];
  arr[h] = temp;

  return (i + 1);
}

void quicksort(char** arr, int l, int h)
 {
  if(l < h) 
  {
    int pi = partition(arr, l, h);
    quicksort(arr, l, pi - 1);
    quicksort(arr, pi + 1, h);
  }
}

void intal_sort(char **arr, int n) 
{
  quicksort(arr, 0, n - 1);
}

char* coin_row_problem(char **arr, int n) 
{
  char** f = (char**)malloc((n + 1) * sizeof(char*));
  f[0] = (char*)malloc(2 * sizeof(char));
  f[0][0] = '0';
  f[0][1] = '\0';

  for(int i = 0; i < n; ++i)
  {
    f[i + 1] = (char*)malloc((strlen(arr[i]) + 1) * sizeof(char));
    strcpy(f[i + 1], arr[i]);
  }

  for(int i = 2; i < n + 1; ++i)
  {
    char* val = intal_add(arr[i -1], f[i - 2]);
    if(intal_compare(val, f[i - 1]) > 0)
    {
      char* temp = f[i];
      f[i] = val;
      free(temp);
    } else {
      free(f[i]);
      f[i] = (char*) malloc((strlen(f[i - 1]) + 1) * sizeof(char));
      strcpy(f[i], f[i - 1]);
      free(val);
    }
  }

  char* res = (char*)malloc((strlen(f[n]) + 1) * sizeof(char));
  strcpy(res, f[n]);

  for(int i = 0; i < n + 1; ++i) 
  {
    free(f[i]);
  }
  free(f);

  return res;
}
