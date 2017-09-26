{Catalin Drula}

{$r-,q-,s-}

program alpinist;

const dl:array [1..4] of integer=(-1,0,1,0);
      dc:array [1..4] of integer=(0,1,0,-1);

type bigvec=array [1..200,1..200] of byte;
     bigmat=array [1..128,1..200] of integer;
     info=^rec1;
     rec1=record
            l,c:byte;
            lg,tata:word;
            urm:info
            end;

var intra:^bigvec;
    A:array [1..2] of ^bigmat;
    l,c,l1,c1,i,j,n,naux,left,p,u:word;
    zero,nzero,aux,aux2:info;
    f:text;
procedure citire;
var f:text;
    i,j:integer;
    k:word;

begin
  zero:=nil;
  new(intra);
  new(A[1]);new(A[2]);
  fillchar(intra^,sizeof(intra^),0);
  assign(f,'alpin.in');
  reset(f);
  readln(f,naux);
  n:=naux*naux;
  read(f,A[1]^[1,1]);

  for i:=2 to naux do
    begin
      read(f,A[1]^[1,i]);
      if A[1]^[1,i]<A[1]^[1,i-1] then inc(intra^[1,i-1])
        else if A[1]^[1,i]>A[1]^[1,i-1] then inc(intra^[1,i])
    end;
  k:=naux;
  readln(f);
  for i:=2 to naux do
    begin
      k:=k+1;
      read(f,A[(i-1) shr 7+1]^[(i-1) and 127+1,1]);
      if A[(i-1) shr 7+1]^[(i-1) and 127+1,1]<
      A[(i-2) shr 7+1]^[(i-2) and 127+1,1] then inc(intra^[i-1,1])
        else if A[(i-1) shr 7+1]^[(i-1) and 127+1,1]>
        A[(i-2) shr 7+1]^[(i-2) and 127+1,1] then inc(intra^[i,1]);
      for j:=2 to naux do
        begin
          k:=k+1;
          read(f,A[(i-1) shr 7+1]^[(i-1) and 127+1,j]);
          if A[(i-1) shr 7+1]^[(i-1) and 127+1,j]<
             A[(i-1) shr 7+1]^[(i-1) and 127+1,j-1] then inc(intra^[i,j-1])
            else if A[(i-1) shr 7+1]^[(i-1) and 127+1,j-1]<
             A[(i-1) shr 7+1]^[(i-1) and 127+1,j] then inc(intra^[i,j]);
          if A[(i-1) shr 7+1]^[(i-1) and 127+1,j]<
             A[(i-2) shr 7+1]^[(i-2) and 127+1,j] then inc(intra^[i-1,j])
            else if A[(i-1) shr 7+1]^[(i-1) and 127+1,j]>
             A[(i-2) shr 7+1]^[(i-2) and 127+1,j] then inc(intra^[i,j]);
        end;
      readln(f)
    end;
  close(f);
end;

begin
  citire;
  left:=n;

  for i:=1 to naux do
    for j:=1 to naux do
      if intra^[i,j]=0 then
        begin
          new(aux);
          aux^.l:=i; aux^.c:=j;
          aux^.tata:=(i-1)*naux+j;
          aux^.lg:=0;
          aux^.urm:=zero;
          zero:=aux;
          dec(left)
        end;
  while left>0 do
    begin
      aux:=zero;
      nzero:=nil;
      while aux<>nil do
        begin
          l:=aux^.l; c:=aux^.c;
          for i:=1 to 4 do
            begin
              l1:= l+dl[i]; c1:= c+dc[i];
              if (l1>0) and (l1<=naux) and (c1>0) and (c1<=naux) and
              (A[(l1-1) shr 7+1]^[(l1-1) and 127+1,c1]>
               A[(l-1) shr 7+1]^[(l-1) and 127+1,c]) and (intra^[l1,c1]>0) then
                begin
                  dec(intra^[l1,c1]);
                  if intra^[l1,c1]=0 then
                    begin
                      left:=left-1;
                      new(aux2);
                      aux2^.l:=l1; aux2^.c:=c1;
                      aux2^.urm:=nzero;
                      aux2^.tata:=aux^.tata;
                      aux2^.lg:=aux^.lg+1;
                      nzero:=aux2
                    end;
                end;
            end;
          aux2:=aux;
          aux:=aux^.urm;
          dispose(aux2);
        end;
      zero:=nzero
    end;

  assign(f,'alpin.out');
  rewrite(f);
  aux:=zero;
  writeln(f,aux^.lg);
  p:=aux^.tata;
  u:=(aux^.l-1)*naux+aux^.c;
  writeln(f,(p-1) div naux+1,' ',(p-1) mod naux+1,' ',
  (u-1) div naux+1,' ',(u-1) mod naux+1);
  close(f)
end.

