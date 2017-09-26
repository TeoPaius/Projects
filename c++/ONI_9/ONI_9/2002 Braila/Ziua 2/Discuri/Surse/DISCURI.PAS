{$N+}
const fi='discuri.in'; fo='discuri.out';
type vect=array[1..10000]of real;
var n,i,j,nr,k:integer;
    sw:boolean;
    dd,dp:real;
    d,x:^vect;
    vc:array[1..10000]of boolean;
function dist(i,j:integer):real;
var r,rr:real;
begin
     r:=d^[i]; rr:=d^[j];
     dist:=x^[i]+sqrt((r+rr)*(r+rr)-(r-rr)*(r-rr));
end;
begin
     new(d); new(x);
     assign(input,fi); reset(input);
     readln(n);
     for i:=1 to n do readln(d^[i]);
     close(input);
     fillchar(vc,sizeof(vc),true);
     for i:=1 to n do begin
         dd:=d^[i]; k:=0;
         for j:=1 to i-1 do begin
             dp:=dist(j,i);
             if dd<=dp then begin
                dd:=dp; k:=j;
             end;
         end; x^[i]:=dd;
         for j:=k+1 to i-1 do vc[j]:=false;
     end; k:=0; dd:=0;
     for i:=1 to n do if dd<x^[i]+d^[i] then begin
         dd:=x^[i]+d^[i]; k:=i;
     end;
     for i:=k+1 to n do vc[i]:=false;
     nr:=0;
     for i:=1 to n do if not vc[i] then inc(nr);
     assign(output,fo); rewrite(output);
     writeln(nr);
     for i:=1 to n do if not vc[i] then writeln(i);
     close(output); dispose(d); dispose(x);
end.