{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
const fin='cod.in';
      fou='cod.out';
var s:string;
    i,j,p,t,ss:longint;
    n,d:real;
    f:text;
begin
     assign(f,fin);
     reset(f);
     readln(f,s);
     close(f);
     for i:=1 to length(s)-1 do begin
         d:=1;n:=1;
         for j:=1 to i do begin
             n:=n*(27-j);
             d:=d*j;
         end;
         n:=n / d;
         ss:=ss+trunc(n);
     end;
     for t:=1 to length(s) do begin
         if t>1 then p:=ord(s[t-1])-96;
         for i:=p+1 to ord(s[t])-97 do begin
             d:=1;n:=1;
             for j:=1 to length(s)-t do begin
                 n:=n*(27-j-i);
                 d:=d*j;
             end;
             n:=n/ d;
             ss:=ss+trunc(n);
         end;
     end;
     assign(f,fou);
     rewrite(f);
     writeln(f,ss+1);
     close(f);
end.

