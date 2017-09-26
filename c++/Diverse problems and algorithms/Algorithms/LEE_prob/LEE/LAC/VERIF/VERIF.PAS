{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}

{ Varianta pt. evaluatorul automat al lui Peter }


uses crt;
type matrice=array[0..101,0..101] of 0..2;
var i,j,m,n,min_c,min_e,l,c,x,y,j1,i1,z1,z2:integer;
    f,g,h:text;
    s,fe,s1,f0,g0,h0:string;
    a,b:matrice;
    okmin,ok_drum:boolean;

procedure eroare(s:string;p:integer);
var g:text;
begin
   Assign(g,fe); ReWrite(g);
   writeln(g,'PCT=',p,'!! ',s);
   close(g);
   halt;
end;



procedure scriu(x,y:integer;var b:matrice);
begin
   if b[x,y]=0  { pun 2 in valorile 0 invecinate cu pct. curent de val 0 }
      then
         begin
            b[x,y]:=2;
            scriu(x+1,y,b);
            scriu(x-1,y,b);
            scriu(x,y+1,b);
            scriu(x,y-1,b);
            scriu(x+1,y-1,b);
            scriu(x+1,y+1,b);
            scriu(x-1,y+1,b);
            scriu(x-1,y-1,b);
         end;
end;

begin
   clrscr;
   { f=iesire comisie, g=iesire elev, h=intrare }
   h0:=paramstr(1);
   g0:=paramstr(2);
   f0:=paramstr(3);
   fe:=paramstr(4);
{   val(paramstr(5),test,cod);}
   assign(f,f0); reset(f);
   assign(h,h0); reset(h);
   assign(g,g0);

{Fisier vid------------------------------------}
   {$I-}
   reset(g);
   {$I+}
   if ioresult<>0
      then
            eroare('Fisier elev inexistent',0);

   okmin:=true;
   readln(f,min_c); close(f);
{Prima linie nu are "min" numeric------------------------------------}
   {$I-}
   readln(g,min_e);
   {$I+}
   if (ioresult<>0) or (min_e<0)
      then
            eroare('Nenumar in linia 1',0);

{Coord ne-naturale-------------------------------------}

   for i:=1 to min_e do
      begin
         {$I-}
         readln(g,z1,z2);
{         writeln(z1:4,z2:4);}
         {$I+}
         if (ioresult<>0) or (z1<=0) or(z2<=0)
            then
                  eroare('Coordonatele nu sunt naturale.',0);
      end;
{Linii vide ------------------------------------------}

   reset(g);
   readln(g,min_e);
   for i:=1 to min_e do
      begin
         {$I-}
         readln(g,s);
         {$I+}
         if (ioresult<>0) or (s='')
            then
                  eroare('Coordonate nenumerice, sau linie vida.',0);
      end;


{"min" incorect--------------------------------------}
   reset(g);
   readln(g,min_e);
   if min_c<min_e
      then
         begin
            okmin:=false;
            str(min_e,s1);
            s1:='Nr pontoane eronat(prea mare:'+s1+')';
            eroare(s1,0);
         end
      else
         if min_c>min_e
            then
             begin
              str(min_e,s1);
              s1:='SOLUTIE MAI BUNA DECAT A COMISIEI ?!? nr pontoane elev='+s1;
              eroare(s1,0);
             end;
{            else writeln('OK dpdv al nr de pontoane.');}

{Drum incorect------------------------------------}
   if okmin
      then
         begin
            readln(h,m,n);
            for i:=1 to m do
               begin
                  for j:=1 to n do
                     read(h,a[i,j]);
                  readln(h);
               end;

{            writeln('Matricea citita din IN:');
            for i:=1 to m do
               begin
                  for j:=1 to n do
                     write(a[i,j]:2);
                  writeln;
               end;}
            for i:=1 to min_e do
               begin
                  readln(g,l,c);
                  if (l<=m) and (c<=n)
                     then a[l,c]:=0;
               end;
{            writeln('Matricea completata cu pontoanele elevului:');
            for i:=1 to m do
               begin
                  for j:=1 to n do
                     write(a[i,j]:2);
                  writeln;
               end;
}
            ok_drum:=false;
            for i:=0 to n-1 do a[0,i]:=1;
            for i:=0 to n+1 do begin a[0,i]:=1;a[m+1,i]:=1 end;  { gen bordura }
               for i:=0 to m+1 do begin a[i,0]:=1;a[i,n+1]:=1 end;
            for j:=1 to n do
               begin
                  b:=a;
                  if b[1,j]=0
                     then
                        begin
                           scriu(1,j,b);
                           for j1:=1 to n do
                              if b[m,j1]=2
                                 then OK_drum:=true;
                          { writeln('Dupa Fill-ul de la col ',j);
                           for i1:=1 to m do
                              begin
                                 for j1:=1 to n do write(b[i1,j1]:2);
                                 writeln;
                              end;
                           readln; }
                        end;
               end;
            if ok_drum then eroare('Problema corect rezolvata. ',10)
                       else eroare('Drum incorect',0);
         end;
   readln;
end.


