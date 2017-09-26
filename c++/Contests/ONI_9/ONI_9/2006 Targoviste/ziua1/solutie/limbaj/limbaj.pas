var sval: array['a'..'z'] of longint;
var niv,l: array[0..10000] of boolean;
var n,nr_niv: integer;

procedure citeste;
var f: text;
     i: integer;
     ln: string;
     c:char;
begin
assign(f,'limbaj.in'); reset(f);
for c:='a' to 'z' do read(f,sval[c]); readln(f);
nr_niv:=0;
while not eof(f) do
      begin
      readln(f,ln);
      if copy(ln,0,2)='if' then begin
         inc(nr_niv,1);
         readln(f,ln);
         case ln[1] of
         '<': niv[nr_niv]:=sval[ln[2]]<sval[ln[3]];
         '>': niv[nr_niv]:=sval[ln[2]]>sval[ln[3]];
         '=': niv[nr_niv]:=sval[ln[2]]=sval[ln[3]];
         end;
         readln(f,ln);
      end;
      if copy(ln,0,2)='da' then l[nr_niv]:=true;
      if copy(ln,0,2)='nu' then l[nr_niv]:=false;
      if (ln[2]='=') and ((nr_niv=0) or (l[nr_niv]=niv[nr_niv])) then
                     sval[ln[1]]:=sval[ln[3]];
      if copy(ln,0,2)='fi' then
                           dec(nr_niv,1);
      end;
close(f);
end;

procedure scrie;
var f: text;
var i: char;
begin
assign(f,'limbaj.out'); rewrite(f);
for i:='a' to 'z' do
    write(f,sval[i],' ');
close(f);
end;

begin
citeste;
scrie;
end.