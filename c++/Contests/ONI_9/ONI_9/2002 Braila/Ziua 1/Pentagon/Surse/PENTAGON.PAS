type corp=array[1..200] of string[200];
var c:corp;
    f:text;
    s:array[1..200] of byte;
    m,n,i:byte;

Procedure numara;
var i,j:byte;
    cod:boolean;
    nr:byte;
begin
     for j:=1 to n do
         begin
         nr:=0;
         cod:=c[1,j]='1';
         for i:=1 to m do
             if c[i,j]='1' then
                begin
                if not cod then
                       begin
                       cod:=true;
                       inc(s[nr]);
                       nr:=0;
                       end
                end
                else
                begin
                  if cod then
                         begin
                         nr:=1;
                         cod:=false;
                         end
                         else
                      inc(nr);
                end;
         if not cod then
                       begin
                       cod:=true;
                       inc(s[nr]);
                       end
         end;
end;
begin
assign(f,'pentagon.in');
reset(f);
readln(f,m,n);
for i:=1 to m do
    readln(f,c[i]);
close(f);
numara;
assign(f,'pentagon.out');
rewrite(f);
for i:=1 to m do
    if s[i]<>0 then
       writeln(f,i,' ',s[i]);
close(f);
end.