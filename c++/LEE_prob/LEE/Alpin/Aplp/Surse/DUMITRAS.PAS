const c=51;cm=32000;
type matrice=array[1..c,0..c] of integer;
var f:text;m,n,i,j,k,o:integer;
    a,max:matrice;
    t:array[1..c,1..c,1..2] of integer;
    v:array[0..cm] of byte;

procedure cit;
begin
     assign(f,'harta.in');reset(f);readln(f,m,n);
     for i:=1 to m do
     begin for j:=1 to n do read(f,a[i,j]);readln(f) end;
     close(f)
end;

procedure pa(a:matrice);
begin
     assign(f,'harta1.out');rewrite(f);
     fillchar(v,sizeof(v),0);
     for i:=1 to m do
     begin
          a[i,n+1]:=a[i,n]+1; k:=1;j:=2;
          while j<=n do
          begin
                while a[i,j]=a[i,k] do inc(j);
                if j<=n then
                begin  inc(k);a[i,k]:=a[i,j];inc(j)   end
          end;
          a[i,0]:=k;
          for k:=1 to m do for j:=1 to a[k,0] do inc(v[a[k,j]]);
     end;

     k:=0;j:=0;
     for i:=0 to 32000 do  if v[i]>j then begin j:=v[i];k:=i end;
     writeln(f,k);

     for i:=1 to m do
          for j:=1 to a[i,0] do
              if a[i,j]=k then write(f,i,' ');
     writeln(f);  close(f)
end;

function cauta(lin,ce:integer):integer;
var p,u,m,o:integer;
begin
     p:=1;u:=n;o:=0;
     repeat
           m:=(u+p) div 2;
           if a[lin,m]<ce then begin o:=m;p:=m+1 end
                      else if a[lin,m]>=ce then u:=m-1
{                           else begin o:=m;p:=u+1 end}
     until u<p;
     cauta:=o
end;

procedure recurs(l,c:integer);
begin
     if t[l,c,1]>0 then recurs(t[l,c,1],t[l,c,2]);
     writeln(f,l,' ',c)
end;

procedure pb;
var ii:integer;
begin
     assign(f,'harta2.out');rewrite(f);
     for i:=1 to m do for j:=1 to n do begin max[i,j]:=1;t[i,j,1]:=0 end;
     for i:=2 to m do
     for j:=1 to n do
     begin
          o:=1;
          for ii:=1 to i-1 do
          begin   k:=cauta(ii,a[i,j]);
                  if max[ii,k]+1>o then
                  begin o:=max[ii,k]+1;t[i,j,1]:=ii;t[i,j,2]:=k end
          end;
          max[i,j]:=o
     end;

     ii:=1;k:=1;
     for i:=1 to m do for j:=1 to n do if max[i,j]>=max[ii,k] then
              begin ii:=i;k:=j end;
     recurs(ii,k);  close(f)
end;

begin
     cit;
     pa(a);
     pb
end.
