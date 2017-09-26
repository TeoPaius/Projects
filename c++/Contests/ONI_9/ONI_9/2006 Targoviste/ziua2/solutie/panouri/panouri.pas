{ Complexitate O(N) }
{$Q+,R+,S+}
program panouri;

const FileIn  = 'panouri.in';
const FileOut = 'panouri.out';
var a:array[0..15001] of integer;  {toate tipurile de panouri de pe autostrada}
    b:array[1..1001] of integer;
    fr:array[0..15001] of integer;
(*
 	b[i] = 1 => panoul de tip i apartine firmei
        frecventa, fr[i] = x,  daca b[i] = 1
        panoul de tip i apartine firmei si daca numarul i apare
        de x ori in subsecventa a[s..f])
*)
    m, n, s, f, i, nr, x : integer;
    best : integer;
    min, max : integer;
    fout : text;

procedure ReadData;
var fin : text;
begin
     assign(fin, FileIn); reset(fin);
     readln(fin, n, m);
     for i := 1 to n do
         readln(fin, a[i]);
     for i := 1 to m do
     begin
          readln(fin, x);
          b[x] := 1;
     end;
     close(fin);
end;

procedure Solve;
begin
     s  := 1; f := 1;
     nr := 0;
     if b[a[s]] = 1 then
        begin
             fr[a[s]] := 1;
             nr := 1;
        end;
                                    {cautam cel mai mic al 2-lea indice f astfel ca in a[s..f]}
                                    {sa fie continute toate numerele din b}
      while (f < n) and (nr < m) do
      begin
           inc(f);
           if b[a[f]] = 1 then { este panou al firmei }
              begin
                   if fr[a[f]] = 0  {  o singura aparitie in secventa}
                      then inc(nr);
      	           inc(fr[a[f]]);
              end;
      end;

      if nr < m then  {nu exista solutie}
         begin
              assign(fout, FileOut); rewrite(fout);
              writeln(fout, -1);
              close(fout);
         end;
      while (b[a[s]] = 0) or ((b[a[s]] = 1) and (fr[a[s]] > 1)) do
         begin
               dec(fr[a[s]]);
               inc(s);
         end;
                                    { marim s cat se poate astfel ca in secventa a[s..f] sa apara }
                                    { toate tipurile de panouri ale firmei}
      best := 25001;

      if best > f - s then
      begin
         best := f - s;
        min := s; max := f;
      end;

      for f := f + 1 to n do
      begin
           if (b[a[f]] = 1) then
              inc(fr[a[f]]);
               while (b[a[s]] = 0) or ((b[a[s]] = 1) and (fr[a[s]] > 1)) do
                     begin
                          dec(fr[a[s]]);
                          inc(s);
                     end;            { la fiecare marire a indicelui f incercam  }
                                     { sa marim pe cat posibil si indicele s }

               if best > f - s then
               begin
                  best := f - s;
                 min := s; max := f;
               end;
    end;


    writeln(fout, best);
{    writeln(fout, min, ' ', max); }
    close(fout);

end;

begin
    assign(fout, FileOut); rewrite(fout);
    ReadData;
    Solve;
end.
