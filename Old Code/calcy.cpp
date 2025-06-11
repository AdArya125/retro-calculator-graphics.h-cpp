#include <graphics.h>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
#include <fstream>

#include "calcy_graphics.h"
#define pi 3.14159
using namespace std;

// This was a project made by a couple of teenagers, so don't judge the comments and the stupid variable names (the code, you may pass judgement upon)

int page = 1, position = 0, rc = 0, rc1 = 0;
fstream STORAGE("CALCYDATA.DAT", ios::binary | ios::out);
int trigpop = 0, ifdec = 0, id = 0;
int sinchk = 0, coschk = 0, tanchk = 0, asinchk = 0, acoschk = 0, atanchk = 0, Sqrtchk = 0, powchk = 0, logchk = 0; // id=++

const int x = 200, y = 40; // UPPER LEFT COORDINATES OF BOX

int xc = x + 40, yc = y + 70;

float cx, cy, r;
char ch;

//*************
const int size = 50;
char infix[size], postfix[size], Stack[size];
int artop = -1;
//**************

class CALCY
{
public:
  unsigned long int Pno;
  unsigned long int Sno;
  int pos; // dare not think it's position
  int n;
  int id;
  CALCY *next;
  CALCY()
  {
    Pno = 0;
    Sno = 0;
    pos = 1;
    n = 0;
    id = 1;
    next = NULL;
  }
  CALCY(int a)
  {
    id = 100;
  }
  CALCY(CALCY &S)
  {
    Pno = S.Pno;
    Sno = S.Sno;
    pos = S.pos;
    n = S.n;
    id = S.id;
  } // not more than 5

  void Clear()
  {
    id++;
    Pno = 0;
    Sno = 0;
    pos = 1;
    n = 0;
    ifdec = 0;
    logchk = 0;
    Sqrtchk = 0;
    sinchk = 0;
    coschk = 0;
    tanchk = 0;
    asinchk = 0;
    acoschk = 0;
    atanchk = 0;
  }

  void PUSH(CALCY *);
  void DISPLAY(CALCY *);
  void SEARCH(CALCY *, int);

} S, S1, *top, *newptr, *save, *ptr, *start, zoro;

void CALCY::PUSH(CALCY *np)
{
  if (start == NULL)
    start = np;
  else
  {
    save = start;
    start = np;
    np->next = save; // STACK PUSH
  }
}

void CALCY::DISPLAY(CALCY *np) // TEST DISPLAY...FINISH LATER
{
  while (np != NULL)
  {
    cout << np->id << "-->";
    np = np->next;
  }
}

void CALCY::SEARCH(CALCY *np, int id) // top pointer =np
{
  np = top;
  // cout<<"\ntop - "<<top<<"  start - "<<start;
  //_getch();
  //  CALCY *temp=np;
  if (np == NULL)
    cout << "svgfhdgfndf\n"; // BEST CODE EVER BRO
  while (np != NULL)
  {
    cout << np->id;
    if (np->id == id)
    {
      cout << "\n stack found : )\n"; // return pointer for no conv.
      {
        zoro.Pno = np->Pno;
        zoro.Sno = np->Sno;
        zoro.pos = np->pos;
        zoro.n = np->n;
        zoro.id = np->id;
      }

      //       *zoro=*np;
      //      *np=*temp;
      return;
    }
    np = np->next;
  }
  _getch();
  cout << "\n stack not found"; // CONSOLE TEST,IRRELEVENT OF THE GRAPH
  //*np=*temp;
}
///********************
struct Stack
{
  int top;
  unsigned capacity;
  long double *array;
};

struct Stack *createStack(unsigned capacity)
{ // Stack* stack=new Stack;
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  if (!stack)
    return NULL;
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (long double *)malloc(stack->capacity * sizeof(long double));

  if (!stack->array)
    return NULL;
  return stack;
}
///*******************

char BODMAS[70], COPY[70]; // GENIUS NAMING
int BODMASINDEX = -1;      // I'LL NOT OFFEND YOUR INTELLIGENCE
int ac[70];
long double cal[70]; // 4 crore k lie ,display
long double result;  // 4 crore k lie

void highlight();
void box();
long double Converter(CALCY);
void Converter(long double);
void SQRT();
void OPERATIONS(char);
void ALLCLR();
void Pi();
void BACKSPACE();
void push(CALCY *);
void extract(CALCY &, char);
void input();
// void text();
void selection();
void TRIGNO();
float dtr(float);
float rtd(float);
void adf(float, float, float, float, float, float);
void sharingan();
void Compute();
void deletion(long double, int);
void Power(double);
///*************
int isEmpty(struct Stack *stack);
char peek(struct Stack *stack);
char pop(struct Stack *stack);
void push(struct Stack *stack, char op);
long double evaluatePostfix(char *);
int precedence(char);
char pop();
char topelement();
void push(char ch);
int braces(char *);
void Postfix();
void ultimate();

CALCY *NEW_NODE();

void flchk()
{
  int i, j;
  cout << endl;
  cout << strlen(BODMAS) << endl;
  for (i = 0; BODMAS[i] != '\0'; i++)
  {
    j = (int)BODMAS[i];
    //  if (isdigit(BODMAS[i]))
    cout << j << '_';
    //  else cout<<BODMAS[i]<<'_';
  } // outtextxy(20,20,"gvfbk");
  cout << endl; // S.DISPLAY(start);
  ultimate();
}

int main()
{
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode, "..\\bgi");
  STORAGE.clear();
  top = NULL;
  sharingan();
  setcolor(WHITE);
  highlight();
  selection();
  STORAGE.close();
  return 0;
}

int isEmpty(struct Stack *stack)
{
  return stack->top == -1;
}

char peek(struct Stack *stack)
{
  return stack->array[stack->top];
}
char pop(struct Stack *stack)
{
  if (!isEmpty(stack))
    return stack->array[stack->top--];
  return '$';
}
void push(struct Stack *stack, char op)
{
  stack->array[++stack->top] = op;
}

long double evaluatePostfix(char *exp) // LITERALLY WHAT NAME SUGGESTS
{                                      //_getch();
  for (int i = 0; i < strlen(exp); i++)
  {
    if (exp[i] < 10 && exp[i] > 0)
      exp[i] += 48; //'0'=48
  }
  puts(exp);
  _getch();

  struct Stack *stack = createStack(strlen(exp));
  int i;
  if (!stack)
    return -1;
  for (i = 0; exp[i]; ++i)
  {
    if (isdigit(exp[i]))
      push(stack, exp[i] - '0');
    else
    {
      int a1 = pop(stack);
      // cout<<"\n a1 -"<<a1<<endl;
      //_getch();
      S1.SEARCH(start, a1);
      long double val1 = Converter(zoro);
      cout << "\n val1 - " << val1 << endl;
      _getch();

      int a2 = pop(stack);
      S1.SEARCH(start, a2);
      long double val2 = Converter(zoro);
      cout << "\n"
           << a1 << "   -    " << a2;
      _getch();
      switch (exp[i])
      {
      case '+':
        push(stack, val2 + val1);
        break;
      case '-':
        push(stack, val2 - val1);
        break;
      case '*':
        push(stack, val2 * val1);
        break;
      case '/':
        push(stack, val2 / val1);
        break;
      }
    }
  }
  return pop(stack);
}
void ultimate() // naming skills 100
{
  top = start;
  Postfix();
  cout << "\n***********" << evaluatePostfix(postfix) << endl; // display
}
void Postfix()
{
  char ele, elem, st[2];
  int prep, pre, popped, j = 0, chk = 0;
  strcpy(postfix, " ");
  //_getch();
  // system("cls");
  strcpy(infix, BODMAS);
  // gets(infix);
  for (int i = 0; infix[i] != '\0'; i++)
  {
    if (infix[i] != '(' && infix[i] != ')' && infix[i] != '-' && infix[i] != '^' && infix[i] != '*' && infix[i] != '/' && infix[i] != '+')
      postfix[j++] = infix[i];
    else if (infix[i] == '(')
    {
      elem = infix[i];
      push(elem);
    }
    else if (infix[i] == ')')
    {
      while ((popped = pop()) != '(')
      {
        postfix[j++] = popped;
      }
    }
    else
    {
      elem = infix[i];
      pre = precedence(elem);

      ele = topelement();
      prep = precedence(ele);
      if (pre > prep)
        push(elem);
      else
      {
        while (prep >= pre)
        {
          if (ele == '#')
            break;
          popped = pop();
          ele = topelement();
          postfix[j++] = popped;
          prep = precedence(ele);
        }
        push(elem);
      }
    }
  }

  while ((popped = pop()) != '#')
    postfix[j++] = popped;
  postfix[j] = '\0';
  cout << "\n postfix:";
  for (int i = 0; postfix[i] != '\0'; i++)
  {
    int x = postfix[i];
    cout << x;
  }
  // cout<<postfix<<endl;
  _getch();
}
int precedence(char ch)
{
  switch (ch)
  {
  case '^':
    return 5;
  case '/':
    return 4;
  case '*':
    return 4;
  case '+':
    return 3;
  case '-':
    return 3;
  default:
    return 0;
  }
}
char pop()
{
  char ret;
  if (artop != -1)
  {
    ret = Stack[artop];
    artop--;
    return ret;
  }
  else
    return '#';
}
char topelement()
{
  char ch;
  if (artop != -1)
    ch = Stack[artop];
  else
    ch = '#';
  return ch;
}
void push(char ch)
{
  if (artop != size - 1)
  {
    artop++;
    Stack[artop] = ch;
  }
}
///***************
CALCY *NEW_NODE()
{
  ptr = new CALCY(S);
  ptr->next = NULL;
  return ptr;
}
void Power(double y = 2)
{
  long double x;
  x = Converter(S);
  x = pow(x, y);
  Converter(x);
  cout << x;
}

void Compute()
{
  OPERATIONS('=');
  long double x, y, z = COPY[position];
  int FLAG = 0, i;
  for (i = position; i <= BODMASINDEX; i++)
  {
    if (COPY[i] == 47)
    {
      FLAG = 1;
      extract(S, COPY[i - 1]);
      x = Converter(S);
      extract(S, COPY[i + 1]);
      y = Converter(S);
      z = x / y;
    }
    else if (COPY[i] == 42)
    {
      FLAG = 1;
      extract(S, COPY[i - 1]);
      x = Converter(S);
      extract(S, COPY[i + 1]);
      y = Converter(S);
      z = x * y;
    }
    else if (COPY[i] == 43)
    {
      FLAG = 1;
      extract(S, COPY[i - 1]);
      x = Converter(S);
      extract(S, COPY[i + 1]);
      y = Converter(S);
      z = x + y;
    }
    else if (COPY[i] == 45)
    {
      FLAG = 1;
      extract(S, COPY[i - 1]);
      x = Converter(S);
      extract(S, COPY[i + 1]);
      y = Converter(S);
      z = x - y;
    }
    if (FLAG == 1)
      deletion(z, i);
  }
}

void deletion(long double z, int l)
{
  int i, j, v;
  char temp;
  for (int i = l - 1; i <= l + 1; i++)
    COPY[i] = ' ';
  Converter(z);
  z = S.id;
  COPY[l - 1] = z;
  for (i = l; i < BODMASINDEX + 1; i++)
  {
    if (COPY[i] != ' ')
    {
      for (j = position; j <= BODMASINDEX; j++, i++)
      {
        temp = COPY[i];
        COPY[i] = COPY[j];
        COPY[j] = temp;
      }

      BODMASINDEX -= 2;

      if (BODMASINDEX == 1)
      {
        v = COPY[0];
      }
      if ((BODMASINDEX == 0))
        outtextxy(20, 20, "gvfbk");
      Compute();
    }
  }
}

float dtr(float x) // degree to radian
{
  float y;
  y = pi * x / 180;
  return y;
}
float rtd(float x) // radian to degree
{
  float y;
  y = x * 180 / pi;
  return y;
}
void adf(float upx, float upy, float dwx, float dwy, float x, float d1)
{
  float r, i, m = 0, n = 0;
  float th, ar[8];
  float a = (d1 * cos(x));
  float b = (d1 * sin(x));
  float d2 = (sqrt((pow(abs(cx + (a)-upx), 2)) + (pow(abs(cy + (b)-upy), 2))));
  r = d2 - d1;

  th = (acos(d1 / d2));
  x = rtd(x);
  th = rtd(th);

  for (i = 0; i < (r / 7); ++i)
  {
    arc(cx + a, cy + b, 0, 360, d2 + i);
    setcolor(WHITE);
    setcolor(BLACK);

    arc(cx - a, cy - b, 360, 0, d2 + i);
    setcolor(WHITE);

    setcolor(BLACK);
  }
  setfillstyle(SOLID_FILL, BLACK);
  circle(cx, cy, r / 2);
  floodfill(cx, cy, BLACK);

  return;
}
void sharingan()
{
  int gd = DETECT;
  int gm;
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  float x, y = 0, u = 0, i, z;

  cx = 250;
  cy = 200;
  r = 100;

  getch();

  while (z < 1) // WAPAS 10 KARNA H //shyd nahi :P
  {
    z++;
    for (i = 0, y = -120; i < 12; i++, y = u, y += 5)
    {
      cleardevice();

      setcolor(RED);
      setfillstyle(SOLID_FILL, RED);
      circle(cx, cy, r);
      floodfill(cx, cy, RED);

      u = y;
      x = dtr(y);
      setcolor(BLACK);
      adf((cx + (r * sin(x))), (cy - (r * cos(x))), (cx - (r * sin(x))), (cy + (r * cos(x))), x, (2 * r));

      y += 60;
      x = dtr(y);
      adf((cx + (r * sin(x))), (cy - (r * cos(x))), (cx - (r * sin(x))), (cy + (r * cos(x))), x, (2 * r));
      y += 60;
      x = dtr(y);
      adf((cx + (r * sin(x))), (cy - (r * cos(x))), (cx - (r * sin(x))), (cy + (r * cos(x))), x, (2 * r));
      y = u;

      delay(50);
    }
    delay(0);
  } // POINTLESS

  cleardevice();
  return;
}

void TRIGNO()
{
  long double x;
  x = Converter(S);
  if (sinchk == 1)
  {
    x = sin(x);
    Converter(x);
  }
  else if (coschk == 1)
  {
    x = cos(x);
    Converter(x);
  }
  else if (tanchk == 1)
  {
    x = tan(x);
    Converter(x);
  }
  else if (asinchk == 1) // DEGREE?RADIAN?
  {
    x = asin(x);
    Converter(x);
  }
  else if (acoschk == 1)
  {
    x = acos(x);
    Converter(x);
  }
  else if (atanchk == 1)
  {
    x = atan(x);
    Converter(x);
  }
}
void SQRT()
{
  long double x;
  x = Converter(S);
  x = sqrt(x);
  Converter(x);
}

void OPERATIONS(char c)
{
  long double x;
  if (c == 40)
  {
    if ((BODMAS[BODMASINDEX] == '+') ||
        (BODMAS[BODMASINDEX] == '-') ||
        (BODMAS[BODMASINDEX] == '*') ||
        (BODMAS[BODMASINDEX] == '/') ||
        (BODMASINDEX == -1))
    {
      BODMASINDEX++;
      BODMAS[BODMASINDEX] = '(';
    }
  } /*
   if(c==41)
   {rc--;
   }*/
  if (Converter(S) == 0)
  {
    if (c == '-')
      S.pos = 1 - S.pos;
  }
  else
  {
    if (Sqrtchk == 1)
      SQRT();
    if ((sinchk == 1) || (coschk == 1) || (tanchk == 1) || (asinchk == 1) || (acoschk == 1) || (atanchk == 1))
      TRIGNO();
    if (logchk == 1)
    {
      x = Converter(S);
      x = log10(x);
      Converter(x);
    }

    if ((BODMAS[BODMASINDEX] != ')') || (BODMASINDEX == -1))
    {
      newptr = NEW_NODE();
      S.PUSH(newptr);
      BODMASINDEX++;
      BODMAS[BODMASINDEX] = S.id;
      COPY[BODMASINDEX] = S.id;
    }
    S.Clear();

    if (c != '=')
    {
      BODMASINDEX++;
      BODMAS[BODMASINDEX] = c;
    }
  }
}

void ALLCLR()
{
  STORAGE.close();
  STORAGE.open("CALCYDATA.DAT", ios::binary | ios::out);
  S.Clear();
  strcpy(BODMAS, " ");
  BODMASINDEX = -1;
  S.id = 1;
  ifdec = 0;
  Sqrtchk = 0;
  sinchk = 0;
  coschk = 0;
  tanchk = 0;
  asinchk = 0;
  acoschk = 0;
  atanchk = 0;
}

void Pi()
{
  S.Pno = 3;
  S.Sno = 14159;
  S.n = 5;
}

void BACKSPACE()
{
  if (S.Sno != 0)
  {
    S.Sno /= 10;
    S.n--;
  }
  else
    S.Pno /= 10;
}

long double Converter(CALCY A)
{
  long double F = 0;
  F += A.Pno;
  F += (A.Sno / pow(10, A.n)); // converting a no from structure to a double variable
  cout << "F is:" << F << endl;
  cout << "p is:" << A.Pno << endl;
  cout << "s is:" << A.Sno << endl;

  return F;
}

void Converter(long double x)
{
  long int i;
  i = x;
  S.Pno = i;
  x -= i; // X=0?
  i = x * 100000;
  S.Sno = i;
}

void extract(CALCY &A, char ch) // ch id define krega
{
  STORAGE.seekg(0, ios::cur);

  cout << "tellg: " << STORAGE.tellg() << endl;
  cout << "ss" << sizeof(A) << endl;
  cout << "ch is:" << ch << endl;
  while (!STORAGE.eof())
  {
    STORAGE.read((char *)&A, sizeof(A));
    cout << "ie the no is : \n S:" << A.Sno << "\n P: " << A.Pno << "\n id: " << A.id << endl;
    if (A.id == ch)
      return;
  }
}

// DISPLAY FUNC,CHAR PE FUNC,CHCK,ALL CLEAR
void input()
{
  if (xc <= x)
  {
    if (yc <= (y + 90))
      sinchk = 1 - sinchk;
    else if (yc <= (y + 130))
      coschk = 1 - coschk;
    else if (yc <= (y + 170))
      tanchk = 1 - tanchk;
    else if (yc <= (y + 210))
      asinchk = 1 - asinchk;
    else if (yc <= (y + 250))
      acoschk = 1 - acoschk;
    else if (yc <= (y + 290))
      atanchk = 1 - atanchk;
  }
  else if (xc <= (x + 80))
  {
    if (yc <= (y + 90))
      trigpop = 1 - trigpop;
    else if (yc <= (y + 130))
      ;
    // x^y
    else if (yc <= (y + 170))
      ;
    // fact
    else if (yc <= (y + 210))
      Power();
    else if (yc <= (y + 250))
      Pi();
    else if (yc <= (y + 290))
      OPERATIONS('(');
  }
  else if (xc <= (x + 160))
  {
    if (yc <= (y + 90))
    {
      if (ifdec)
      {
        S.n++;
        S.Sno = S.Sno * 10 + 1;
      }
      else
        S.Pno = S.Pno * 10 + 1;
    }
    else if (yc <= (y + 130))
    {
      if (ifdec)
      {
        S.n++;
        S.Sno = S.Sno * 10 + 4;
      }
      else
        S.Pno = S.Pno * 10 + 4;
    }
    else if (yc <= (y + 170))
    {
      if (ifdec)
      {
        S.n++;
        S.Sno = S.Sno * 10 + 7;
      }
      else
        S.Pno = S.Pno * 10 + 7;
    }
    else if (yc <= (y + 210))
      ALLCLR();
    else if (yc <= (y + 250))
      Sqrtchk = 1 - Sqrtchk;
    else if (yc <= (y + 290))
      OPERATIONS(')');
  }
  else if (xc <= (x + 240))
  {
    if (yc <= (y + 90))
    {
      if (ifdec)
      {
        S.n++;
        S.Sno = S.Sno * 10 + 2;
      }
      else
        S.Pno = S.Pno * 10 + 2;
    }
    else if (yc <= (y + 130))
    {
      if (ifdec)
      {
        S.n++;
        S.Sno = S.Sno * 10 + 5;
      }
      else
        S.Pno = S.Pno * 10 + 5;
    }
    else if (yc <= (y + 170))
    {
      if (ifdec)
      {
        S.n++;
        S.Sno = S.Sno * 10 + 8;
      }
      else
        S.Pno = S.Pno * 10 + 8;
    }
    else if (yc <= (y + 210))
    {
      if (ifdec)
      {
        S.n++;
        S.Sno = S.Sno * 10;
      }
      else
        S.Pno = S.Pno * 10;
    }
    else if (yc <= (y + 250))
      ifdec = 1;
    else if (yc <= (y + 290))
      powchk = 1; // Power();
  }
  else if (xc <= (x + 320))
  {
    if (yc <= (y + 90))
    {
      if (!ifdec)
        S.Pno = S.Pno * 10 + 3;
      else
        S.Sno = S.Sno * 10 + 3;
    }
    else if (yc <= (y + 130))
    {
      if (!ifdec)
        S.Pno = S.Pno * 10 + 6;
      else
        S.Sno = S.Sno * 10 + 6;
    }
    else if (yc <= (y + 170))
    {
      if (!ifdec)
        S.Pno = S.Pno * 10 + 9;
      else
        S.Sno = S.Sno * 10 + 9;
    }
    else if (yc <= (y + 210))
      BACKSPACE();
    else if (yc <= (y + 250))
      Compute();
    else if (yc <= (y + 290)) // if daalte h toh
      powchk = 1 - powchk;
  }
  else if (xc <= (x + 400))
  {
    if (yc <= (y + 90))
      OPERATIONS('+');
    else if (yc <= (y + 130))
      OPERATIONS('-');
    else if (yc <= (y + 170))
      OPERATIONS('*');
    else if (yc <= (y + 210))
      OPERATIONS('/');
    else if (yc <= (y + 250))
      S.pos = 1 - S.pos;
    else if (yc <= (y + 290))
      ;
    //  cHECK
  }
}

void box()
{
  line(x, y, x + 400, y);
  line(x, y + 50, x + 400, y + 50);
  line(x, y + 90, x + 400, y + 90);
  line(x, y + 130, x + 400, y + 130);
  line(x, y + 170, x + 400, y + 170);
  line(x, y + 210, x + 400, y + 210);
  line(x, y + 250, x + 400, y + 250);
  line(x, y + 290, x + 400, y + 290); // horizontal lines
  line(x, y, x, y + 290);
  line(x + 80, y + 50, x + 80, y + 290);
  line(x + 160, y + 50, x + 160, y + 290);
  line(x + 240, y + 50, x + 240, y + 290);
  line(x + 320, y + 50, x + 320, y + 290);
  line(x + 400, y, x + 400, y + 290);

  if (trigpop == 1)
  {
    line(x - 80, y + 170, x, y + 170);
    line(x - 80, y + 50, x, y + 50);
    line(x - 80, y + 90, x, y + 90);
    line(x - 80, y + 130, x, y + 130);
    line(x - 80, y + 50, x - 80, y + 290);
    line(x - 80, y + 290, x, y + 290);
    line(x - 80, y + 170, x, y + 170);
    line(x - 80, y + 210, x, y + 210);
    line(x - 80, y + 250, x, y + 250);
  }

  if (powchk == 1)
    for (int i = 0; i < 5; i++)
    {
      line(x, y + 325 + i, x + 400, y + 325 + i);
      line(x, y + 410 - i, x + 400, y + 410 - i);
      line(x + i, y + 325, x + i, y + 410);
      line(x + 400 - i, y + 325, x + 400 - i, y + 410);
    }
  text(); // CALLED TWICE IN ONE RUN,PLEASE CHECK
          // Power();
  // getch();
}

void highlight()
{
  cleardevice();
  box();
  setfillstyle(SOLID_FILL, 15);
  floodfill(xc - 15, yc - 15, WHITE);
  text();
  selection();
}

void selection()
{
  setactivepage(page);
  setvisualpage(1 - page);

  char ch;
  ch = getch();
  while (TRUE)
  {
    if (powchk == 1)
    {
      while (TRUE)
        if (ch == 89 || ch == 121 || ch == 13) // Y or y or enter
        {
          STORAGE.close();
          closegraph();
          exit(0);
        }
        else if (ch == 78 || ch == 110 || ch == 27) // N or n or esc
        {
          cleardevice();
          page = 1 - page;
          powchk = 0;
          highlight();
        }
    }

    if (ch == 'v')
      flchk(); // CHECK FUNCTION(TEMPORARY)

    if (ch == 72) // up key
    {
      if (yc > (y + 70))
        yc -= 40;
      else
        yc = y + 270;
    }
    else if (ch == 75) // left key
    {
      if (trigpop)
      {
        if ((xc > x))
          xc -= 80;
        else
          xc = x + 360;
      }
      else if (xc != x + 40)
        xc -= 80;
      else
        xc = x + 360;
    }
    else if (ch == 77) // right key
    {
      if (!(xc >= (x + 360)))
        xc += 80;
      else
      {
        if (trigpop)
          xc = x - 40;
        else
          xc = x + 40;
      }
    }
    else if (ch == 80) // down key
    {
      if (trigpop)
      {
        if (xc < x)
        {
          if (yc < (y + 250))
            yc += 40;
          else
            yc = y + 70;
        }
        else if (!(yc >= (y + 250)))
          yc += 40;
        else
          yc = y + 70;
      }
      else if (!(yc >= (y + 250)))
        yc += 40;
      else
        yc = y + 70;
    }
    else if (ch == 13) // CR Carriage Return(enter key)
      input();
    else if (ch == 49) // 1
    {
      xc = x + 100;
      yc = y + 70;
      input();
    }
    else if (ch == 50) // 2
    {
      xc = x + 180;
      yc = y + 70;
      input();
    }
    else if (ch == 51) // 3
    {
      xc = x + 260;
      yc = y + 70;
      input();
    }
    else if (ch == 52) // 4
    {
      xc = x + 100;
      yc = y + 110;
      input();
    }
    else if (ch == 53) // 5
    {
      xc = x + 180;
      yc = y + 110;
      input();
    }
    else if (ch == 54) // 6
    {
      xc = x + 260;
      yc = y + 110;
      input();
    }
    else if (ch == 55) // 7
    {
      xc = x + 100;
      yc = y + 150;
      input();
    }
    else if (ch == 56) // 8
    {
      xc = x + 180;
      yc = y + 150;
      input();
    }
    else if (ch == 57) // 9
    {
      xc = x + 260;
      yc = y + 150;
      input();
    }
    else if (ch == 48) // 0
    {
      xc = x + 180;
      yc = y + 190;
      input();
    }
    else if (ch == 8) // backspace
    {
      xc = x + 260;
      yc = y + 190;
      BACKSPACE();
    }
    else if ((ch == 67) || (ch == 99)) // all clear
    {
      xc = x + 100;
      yc = y + 190;
      ALLCLR();
    }
    else if ((ch == 84) || (ch == 116)) // Trignometry
    {
      xc = x + 20;
      yc = y + 70;
      trigpop = 1 - trigpop;
    }
    else if (ch == 43) // +
    {
      xc = x + 340;
      yc = y + 70;
      OPERATIONS('+');
    }
    else if (ch == 45) //  -
    {
      xc = x + 340;
      yc = y + 110;
      OPERATIONS('-');
    }
    else if (ch == 42) //  *
    {
      xc = x + 340;
      yc = y + 150;
      OPERATIONS('*');
    }
    else if (ch == 47) //  -
    {
      xc = x + 340;
      yc = y + 190;
      OPERATIONS('/');
    }
    else if (ch == 27) //  power
    {
      xc = x + 180;
      yc = y + 270;
      powchk = 1 - powchk;
    }
    else if (ch == 61)
    { // xc
      // yc
      OPERATIONS('=');
    }

    page = 1 - page;
    highlight();

    ch = getch();
  }
}
/*
void text()
{
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    {if(trigpop==1)
         outtextxy(x+30,y+64,"X");                             //key 1
    else outtextxy(x+10,y+64,"TRIGNO");}             //key 1
    outtextxy(x+110,y+64,"1");                                 //key 2
    outtextxy(x+190,y+64,"2");                                 //key 3
    outtextxy(x+270,y+64,"3");                                 //key 4
    outtextxy(x+350,y+64,"+");                                 //key 5
    outtextxy(x+20,y+104,"x^y");                              //key 6
    outtextxy(x+110,y+104,"4");                                //key 7
    outtextxy(x+190,y+104,"5");                                //key 8
    outtextxy(x+270,y+104,"6");                                //key 9
    outtextxy(x+350,y+104,"-");                                 //key 10
    outtextxy(x+30,y+144,"x!");                                 //key 11
    outtextxy(x+110,y+144,"7");                                //key 12
    outtextxy(x+190,y+144,"8");                                //key 13
    outtextxy(x+270,y+144,"9");                                //key 14
    outtextxy(x+350,y+144,"*");                                //key 15
    outtextxy(x+20,y+184,"x^2");                              //key 16
    outtextxy(x+105,y+184,"AC");                             //key 17
    outtextxy(x+190,y+184,"0");                                //key 18
    outtextxy(x+265,y+184,"<--");                             //key 19
    outtextxy(x+350,y+184,"/");                                 //key 20
    outtextxy(x+25,y+224,"Pi");                                 //key 21
    outtextxy(x+95,y+224,"SQRT");                         //key 22
    outtextxy(x+190,y+224,".");                                //key 23
    outtextxy(x+270,y+224,"=");                               //key 24
    outtextxy(x+340,y+224,"+/-");                             //key 25
    outtextxy(x+30,y+264,"(");                                  //key 26
    outtextxy(x+110,y+264,")");                                //key 27
    outtextxy(x+330,y+264,"CHECK");                    //key 30
    outtextxy(x+256,y+264,"log10");

    circle(x+195,y+275,10);                 //POWER
    line(x+195,y+275,x+195,y+263);          // KEY(28)
    line(x+196,y+275,x+196,y+263);
    line(x+194,y+275,x+194,y+263);
    circle(x+195,y+275,9);

   if(trigpop==1)
    {outtextxy(x-60,y+64,"Sin");        //key 31
     outtextxy(x-60,y+104,"Cos");       //key 32
     outtextxy(x-60,y+144,"Tan");       //key 33
     outtextxy(x-72,y+184,"Sin^-1");    //key 34           //sine inverse button
     outtextxy(x-72,y+224,"Cos^-1");    //key 35           //cosine inverse button
     outtextxy(x-72,y+264,"Tan^-1");    //key 36           //tangent inverse button

    }
   if(powchk==1)
   {outtextxy(x+40,y+350,"DO YOU REALLY WANT TO EXIT ?");
   outtextxy(x+38,y+370,"(Y for yes/N for no)");
   }

}



*/
