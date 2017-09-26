
{ Dumitru Bogdan }

{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 65000,0,655360}
program alpin;

const ni='alpin.in';
      no='alpin.out';
      nmax=200;

type sir_integer=array [1..nmax] of integer;
     p_sir_integer=^sir_integer;
     mat_integer=array [1..nmax] of p_sir_integer;
     sir_word=array [1..nmax] of word;
     p_sir_word=^sir_word;
     mat_word=array [1..nmax] of p_sir_word;
     sir_byte=array [1..nmax] of byte;
     p_sir_byte=^sir_byte;
     mat_byte=array [1..nmax] of p_sir_byte;

var a:mat_integer;
    lng:mat_word;
    sl,sc:mat_byte;
    n,i,j,ii,jj,max:longint;
    are:boolean;
    f:text;

procedure aloca;
begin
     for i:=1 to n do begin
        new(a[i]);
        new(lng[i]);
        for j:=1 to n do
           lng[i]^[j]:=0;
        new(sl[i]);
        new(sc[i]);
                      end;
end;

procedure load;
begin
     assign(f,ni);reset(f);
     readln(f,n);
     aloca;
     for i:=1 to n do begin
        for j:=1 to n do
           read(f,a[i]^[j]);
        readln(f);
                      end;
     close(f);
end;

procedure init;
begin
     for i:=1 to n do
        for j:=1 to n do begin
           are:=false;
           if 1<=i-1 then
             if a[i-1]^[j]<a[i]^[j] then are:=true;
           if i+1<=n then
             if a[i+1]^[j]<a[i]^[j] then are:=true;
           if 1<=j-1 then
             if a[i]^[j-1]<a[i]^[j] then are:=true;
           if j+1<=n then
             if a[i]^[j+1]<a[i]^[j] then are:=true;
           if not are then begin
             lng[i]^[j]:=1;
             sl[i]^[j]:=i;
             sc[i]^[j]:=j;
                           end;
                         end;
end;

procedure rec;
begin
     if 1<=i-1 then
       if a[i-1]^[j]<a[i]^[j] then begin
         if lng[i-1]^[j]=0 then begin
           i:=i-1;
           rec;
           i:=i+1;
                                end;
         if lng[i-1]^[j]+1>lng[i]^[j] then begin
           lng[i]^[j]:=lng[i-1]^[j]+1;
           sl[i]^[j]:=sl[i-1]^[j];
           sc[i]^[j]:=sc[i-1]^[j];
                                           end;
                                   end;
     if i+1<=n then
       if a[i+1]^[j]<a[i]^[j] then begin
         if lng[i+1]^[j]=0 then begin
           i:=i+1;
           rec;
           i:=i-1;
                                end;
         if lng[i+1]^[j]+1>lng[i]^[j] then begin
           lng[i]^[j]:=lng[i+1]^[j]+1;
           sl[i]^[j]:=sl[i+1]^[j];
           sc[i]^[j]:=sc[i+1]^[j];
                                           end;
                                   end;
     if 1<=j-1 then
       if a[i]^[j-1]<a[i]^[j] then begin
         if lng[i]^[j-1]=0 then begin
           j:=j-1;
           rec;
           j:=j+1;
                                end;
         if lng[i]^[j-1]+1>lng[i]^[j] then begin
           lng[i]^[j]:=lng[i]^[j-1]+1;
           sl[i]^[j]:=sl[i]^[j-1];
           sc[i]^[j]:=sc[i]^[j-1];
                                           end;
                                   end;
     if j+1<=n then
       if a[i]^[j+1]<a[i]^[j] then begin
         if lng[i]^[j+1]=0 then begin
           j:=j+1;
           rec;
           j:=j-1;
                                end;
         if lng[i]^[j+1]+1>lng[i]^[j] then begin
           lng[i]^[j]:=lng[i]^[j+1]+1;
           sl[i]^[j]:=sl[i]^[j+1];
           sc[i]^[j]:=sc[i]^[j+1];
                                           end;
                                   end;
end;

procedure work;
begin
     for i:=1 to n do
        for j:=1 to n do
           if lng[i]^[j]=0 then rec;
end;

procedure alege;
begin
     for i:=1 to n do
        for j:=1 to n do
           if lng[i]^[j]>max then begin
             max:=lng[i]^[j];
             ii:=i;
             jj:=j;
                                  end;
end;

procedure scrie;
begin
     assign(f,no);rewrite(f);
     writeln(f,max-1);
     writeln(f,sl[ii]^[jj],' ',sc[ii]^[jj],' ',ii,' ',jj);
     close(f);
end;

begin {programul principal}
     load;
     init;
     work;
     alege;
     scrie;
end.

