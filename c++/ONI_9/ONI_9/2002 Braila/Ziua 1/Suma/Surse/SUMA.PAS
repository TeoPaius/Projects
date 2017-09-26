const fi='suma.in'; fo='suma.out';
var s,n,d:longint;
procedure sol(n,i:longint);
begin
     writeln(n);
     if i>0 then
     while i>0 do
     if i<=n then begin
        writeln(i); i:=0;
     end else begin
         writeln(n); dec(i,n); dec(n);
     end;
end;
begin
     assign(input,fi); reset(input);
     read(s); close(input);
     assign(output,fo); rewrite(output);
     n:=trunc((sqrt(1+8*s)-1)/2);
     if (n*(n+1))div 2<s then inc(n);
     d:=(n*(n+1))div 2-s;
     if d mod 2=0 then sol(n,d div 2)
     else begin
          inc(n);
          d:=(n*(n+1))div 2-s;
          if d mod 2=0 then sol(n,d div 2)
          else begin
               inc(n);
               d:=(n*(n+1))div 2-s;
               sol(n,d div 2);
          end;
     end; close(output);
end.