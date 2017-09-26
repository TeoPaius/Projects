 #include <stdio.h>
 #include <conio.h>
 #include <mem.h>
 #include <stdlib.h>

 extern unsigned _stklen = 50000;

 typedef int Huge[200];

  FILE *f=fopen("coduri.in","rt");
  FILE *g=fopen("coduri.out", "rt");

  int n;
  Huge A[25];

void error(int p, char s[100])
{
  printf("%d %s", p, s);
  exit(0);

}

 void Atrib0(Huge H)
 {
   H[0]=0;
 }

 void AtribValue(Huge H, unsigned long X)
 {
   H[0]=0;
 while (X)
  {
   H[++H[0]]=X%10;
   X/=10;
  }
 }

 void AtribHuge(Huge H, Huge X)
 {
  int i;
  for(i=0;i<=X[0];i++) H[i]=X[i];
 }

 void MultHuge(Huge A, Huge B, Huge C)
 {
 int i,j,T=0;
 C[0]=A[0]+B[0]-1;
 for(i=1;i<=A[0]+B[0];) C[i++]=0;
 for(i=1;i<=A[0];i++)
  for(j=1;j<=B[0];j++)
   C[i+j-1]+=A[i]*B[j];
 for(i=1;i<=C[0];i++)
  {
   T=(C[i]+=T)/10;
   C[i]%=10;
  }
  if (T) C[++C[0]]=T;
 }

 void Add(Huge A, Huge B)
 {
 int i,T=0;
 if (B[0]>A[0])
  {
   for(i=A[0]+1;i<=B[0];) A[i++]=0;
   A[0]=B[0];
  }
   else
  for(i=B[0]+1;i<=A[0];) B[i++]=0;
 for(i=1;i<=A[0];i++)
  {
   A[i]+=B[i]+T;
   T=A[i]/10;
   A[i]%=10;
   }
  if (T) A[++A[0]]=T;
 }

 void Shl(Huge H, int Count)
 {
 memmove(&H[Count+1],&H[1], sizeof(int)*H[0]);
 memset(&H[1],0,sizeof(int)*Count);
 H[0]+=Count;
 }

 void Shr(Huge H, int Count)
 {
 memmove(&H[1],&H[Count+1], sizeof(int)*(H[0]-Count));
 H[0]-=Count;
 }

 void Mult(Huge H, unsigned long X)
 {
 int i;
 unsigned long T=0;
 for(i=1; i<=H[0];i++)
  {
   H[i]=H[i]*X+T;
   T=H[i]/10;
   H[i]=H[i]%10;
   }
 while (T)
  {
   H[++H[0]]=T%10;
   T/=10;
  }
 }

int Sgn(Huge H1, Huge H2)
{
 int i;
 while(!H1[H1[0]] && H1[0]) H1[0]--;
 while (!H2[H2[0]] && H2[0]) H2[0]--;
 if (H1[0]!=H2[0])
  return H1[0]<H2[0] ? -1 : 1;
 i=H1[0];
 while(H1[i]==H2[i] && i) i--;
 return H1[i]<H2[i] ? -1 : H1[i]==H2[i] ? 0 : 1;
}


 void FindDigit(Huge L, Huge NewL2, Huge NewL3, Huge OldL, Huge OldL2, Huge OldL3, Huge Target)
 {
 Huge Aux;
 L[1]=10;
 do
  {
   L[1]--;
   AtribHuge(NewL3, OldL3); Shl(NewL3, 3);
   AtribHuge(Aux, OldL2);Mult(Aux, 300*L[1]);
   Add(NewL3, Aux);
   AtribHuge(Aux, OldL);Mult(Aux, 30*L[1]*L[1]);
   Add(NewL3, Aux);
   AtribValue(Aux, L[1]*L[1]*L[1]);
   Add(NewL3, Aux);
  }
 while (Sgn(NewL3, Target)==1);
 AtribHuge(NewL2, OldL2);
 Shl(NewL2,2);
 AtribHuge(Aux, OldL); Mult(Aux, 20*L[1]);
 Add(NewL2, Aux);
 AtribValue(Aux, L[1]*L[1]);
 Add(NewL2, Aux);

 AtribHuge(OldL2, NewL2);
 AtribHuge(OldL,L);
 AtribHuge(OldL3, NewL3);
}

void CubeRoot(Huge A, Huge X)
{
Huge Target, OldX, OldX2, OldX3, NewX2, NewX3;
int i;
OldX[0]=OldX2[0]=OldX3[0]=X[0]=0;
for(i=1;i<=(A[0]+2)/3;i++)
 {
  AtribHuge(Target,A);
  Shr(Target,3*((A[0]+2)/3-i));
  Shl(X,1);
  FindDigit(X,NewX2, NewX3, OldX, OldX2, OldX3, Target);
  }
}

void SquareRoot(Huge N, Huge R)
{
	Huge T, OldR, Temp, Temp2;
	int d, i;

	if (N[0] % 2) N[++N[0]] = 0;
	memset(T, 0, sizeof(Huge));
	memset(R, 0, sizeof(Huge));
	memset(OldR, 0, sizeof(Huge));
	for (i = 0; i < (N[0] >> 1); i++)
	{
		Shl(T, 2);
		T[2] = N[N[0] - 2 * i];
		T[1] = N[N[0] - 2 * i - 1];
		for (d = 9; d >= 0; d--)
		{
			// if ((R * 10 + d) ^ 2 <= T) break
			// (R * 10 + d) ^ 2 = R * R * 100 + R * 2 * 10 * d + d * d
			memcpy(Temp, OldR, sizeof(Huge));
			Shl(Temp, 2);
			memcpy(Temp2, R, sizeof(Huge));
			Mult(Temp2, 20);
			Mult(Temp2, d);
			Add(Temp, Temp2);
			memset(Temp2, 0, sizeof(Temp2));
			Temp2[0] = Temp2[1] = 1;
			Mult(Temp2, d);
			Mult(Temp2, d);
			Add(Temp, Temp2);
			if (Sgn(Temp, T) <= 0)
				break;
		}
		memcpy(OldR, Temp, sizeof(Huge));
		Shl(R, 1);
		R[1] = d;
	}
}

int ReadHuge(Huge A)
{
  char c;
  int i;
  A[0]=0;
  do
    {
      A[++A[0]]=(c=fgetc(g))-'0';
      if ((c<'0'||c>'9')&&(c!='\n')) return 0;
      if (A[0]>30) return 0;
    }
  while (c!='\n');
  A[0]--;
  for (i=1; i<=A[0]/2; i++)
    A[i]=(A[i]^A[A[0]+1-i])^(A[A[0]+1-i]=A[i]);
  return 1;
}

int Distincte()
{
  int i, j;
  for (i=1; i<n; i++)
    for (j=i+1; j<=n; j++)
      if (!Sgn(A[i], A[j])) error(0, "Codurile nu sunt distincte");
  return 1;
}

void main()
{
  Huge X, Y, Z, S2, S3;
  int c,i;
  fscanf(f, "%d", &n);
  fclose(f);
  for (i=1; i<=n; i++)
     if (!ReadHuge(A[i])) error(0, "Fisier de iesire cu format incorect!");
  fclose(g);
  if (!Distincte())
    error(0, "Codurile nu sunt distincte!");
  Atrib0(S2); Atrib0(S3);
  for (i=1; i<=n; i++)
    {
      MultHuge(A[i], A[i], X); Add(S2, X);
    }
  for (i=1; i<=n; i++)
    {
      MultHuge(A[i], A[i], X); MultHuge(A[i], X, Y);
      Add(S3, Y);
    }
  CubeRoot(S2, X);
  MultHuge(X, X, Y); MultHuge(Y, X, Z);
  if (Sgn(S2, Z)) error(0, "Suma patratelor nu este cub");
  SquareRoot(S3, X);
  MultHuge(X, X, Y);
  if (Sgn(S3, Y)) error(0, "Suma cuburilor nu este patrat perfect");
  error(10, "OK!");
}
