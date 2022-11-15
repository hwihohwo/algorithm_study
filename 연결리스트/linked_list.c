
#include <stdio.h>

#define MX 1000005

int dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if (nxt[addr] != -1)
    pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

void erase(int addr){
  dat[addr] = -1;
  nxt[pre[addr]] = nxt[addr];
  if (nxt[addr] != -1)
    pre[nxt[addr]] = pre[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    printf("%d ", dat[cur]);
    cur = nxt[cur];
  }
  printf("\n\n");
}

void insert_test(){
  printf("****** insert_test *****\n");
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  printf("****** erase_test *****\n");
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  for (int i = 0; i < MX; i++)
    pre[i] = -1;
  for (int i = 0; i < MX; i++)
    nxt[i] = -1;;
  insert_test();
  erase_test();
}