program factorial;
const t=5;
type matrice=array[0..10,0..2] of longint;
var  n:longint;
     b,nr,i:longint;
     d:matrice;
     fin,fout:text;
procedure desc(b:longint);
var i:longint;
begin
     nr:=0;
     i:=2;
     while b>1 do
           begin
                if b mod i=0 then
                   begin
                        d[nr,0]:=i;
                        d[nr,1]:=0;
                        while b mod i=0 do
                              begin
                                   d[nr,1]:=d[nr,1]+1;
                                   b:=b div i
                              end;
                        nr:=nr+1;
                   end;
                i:=i+1;
           end;
end;
function cifra:longint;
var i,aux:longint;
    j,p:longint;
begin
     p:=1;
     for j:=0 to nr-1 do
         d[j,2]:=0;
     for i:=1 to n do
         begin
              aux:=i;
              for j:=0 to nr-1 do
                  while aux mod d[j,0]=0 do
                        begin
                             d[j,2]:=d[j,2]+1;
                             aux:=aux div d[j,0];
                        end;
              p:=(p*(aux mod b))mod b;
         end;
     cifra:=p;
end;
function minim:longint;
var i:longint;
    min:longint;
begin
     min:=d[0,2] div d[0,1];
     for i:=1 to nr-1 do
         if d[i,2] div d[i,1]<min
            then min:=d[i,2] div d[i,1];
     minim:=min;
end;
function calcul:longint;
var i,j,p:longint;
    min:longint;
begin
     p:=cifra;
     min:=minim;
     for i:=0 to nr-1 do
         for j:=1 to d[i,2]-d[i,1]*min do
             p:=(p*(d[i,0] mod b))mod b;
     calcul:=p;
end;
procedure scrie;
var x:longint;
begin
     x:=calcul;
     if x<10
        then writeln(fout,x)
        else writeln(fout,chr(ord('A')+x-10))
end;
begin
     assign(fin,'fact.in');
     reset(fin);
     assign(fout,'fact.out');
     rewrite(fout);
     for i:=1 to 5 do
         begin
              readln(fin,n,b);
              desc(b);
              scrie;
         end;
     close(fin);
     close(fout)
end.