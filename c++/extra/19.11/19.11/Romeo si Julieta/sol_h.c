/* Program solving the Romeo and Juliet problem, IPSC 99 */
/* reads input from file h.txt */

#include <stdio.h>
#define MAX 100     //maximum number of vertices
#define INFTY 10000 //infinity

int a[MAX][MAX]; //adjacency matrix of a graph (mtr costurilor)
int juliet[MAX];  //time when Juliet arrives to a node
int romeo[MAX];  //time when Juliet arrives to a node
int final[MAX];  //whether is the value final - selectat (0 - neselectat, 1 - selectat)
int stack[MAX];
int n;           //number of nodes
FILE *f;

void dijkstra(int start, int bestTime[])
{
  int i, j, min, minj, time;

  for(i = 0; i < n; i++){
    final[i] = 0;            //no value is final - selectat
    bestTime[i] = INFTY;
  }
  bestTime[start] = 0;

  for(i = 0; i < n; i++){

    //we find the node with the smallest non-final time
    min = INFTY;
    for(j = 0; j < n; j++){
      if(final[j] == 0 && bestTime[j] < min){
        min = bestTime[j];
        minj = j;
      }
    }//for j

    if(min == INFTY) printf("graph is not connected\n");

    //time for found node is marked final
    final[minj] = 1;

    //check the outgoing edges
    for(j = 0; j < n; j++){
      time = bestTime[minj] + a[minj][j];
      if(time < bestTime[j])
        bestTime[j] = time;
    }
  }
}

void mark(int goal, int bestTime[], int marker)
{
/* here we find all vertices not lying on any shortest path to goal
  and we change their bestTime to value marker
*/

  int stacktop; // nr elem in stiva ( un DF iterativ- implementeaza o stiva)
  int i,j,time;

  for (i = 0; i < n; i++)
    final[i] = 0; // selectat
  stacktop = 1;   //
  stack[0] = goal;
  final[goal] = 1;  //goal is on the shortest time

  while (stacktop)
  {
    stacktop--;             //pop the stack
    i = stack[stacktop];

    //expore node i
    for(j=0; j<n; j++)
    {
      time=bestTime[j]+a[j][i];
      if(time==bestTime[i] && !final[j])
      {
        final[j]=1;
        stack[stacktop++]=j;          //push the stack
      }
    }
  }

  //mark nodes not lying on the shortest path
  for(i=0; i<n; i++)
    if(!final[i]) bestTime[i]=marker;

}

void main(void)
{
   int i,j,min;
   int start, goal, time;
   int js, jg, rs, rg, m;

   f=fopen("h.txt","r");

   for(;;)
   {
     fscanf(f,"%d",&n);
     if(n<0) break;  // pt valoarea -1 care incheie fisierul
     fscanf(f,"%d",&m);
     fscanf(f,"%d %d %d %d",&js, &jg, &rs, &rg);
     js--; jg--; rs--; rg--;

     for(i=0; i<n; i++)
       for(j=0; j<n; j++)
         a[i][j]=INFTY;

     //read edges
     for(i=0; i<m; i++)
     {
       fscanf(f,"%d %d %d",&start, &goal, &time); // primul varf, al doilea vf, costul
       a[start-1][goal-1]=time;
       a[goal-1][start-1]=time;
     }

     dijkstra(js,juliet);
     dijkstra(rs,romeo);

     //mark nodes lying on some shortest path
     mark(jg,juliet,-1);
     mark(rg,romeo,-2);

     //find the first possible meeting point
     min=INFTY;
     for(i=0; i<n; i++)
       if(juliet[i]==romeo[i] && juliet[i]<min) // timpul in care Julieta ajunge la nodul i
          min=juliet[i];                        // egal cu timpul in care Romeo ajunge in i

     //write the result
     if(min==INFTY) min=-1;
     printf("%d\n",min);

   } //for(;;)

   fclose(f);
}
