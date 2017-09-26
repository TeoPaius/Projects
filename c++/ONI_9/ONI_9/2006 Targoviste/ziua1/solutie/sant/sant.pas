{$R-,S-}
Program Sant;
{NU l-am dat pe asta ca sursa deoarece intr-a IX-a INCA nu se face QuickSort}
Const MAXD=10000;
      MAXP=251;

Type Detinut = Record
                 NrOrd: Word;
                 min, max: Byte;
                 NrP: Byte
              End;
     MinMax = Record
                min, max: Byte
              End;

Var P                 : Array[1..MAXP] Of MinMax;
    D                 : Array[1..MAXD] Of Detinut;
    Fisier            : Text;
    NrPaznici, i, j, N, Prim, Ultim: Integer;
    min, max          : Byte;

Function Maxim(x, y: Byte): Byte;
Begin
  If x>y Then
    Maxim := x
  Else
    Maxim := y
End;

Function Minim(x, y: Byte): Byte;
Begin
  If x<y Then
    Minim := x
  Else
    Minim := y
End;

Function Cauta(min, max: Byte): Integer;
Var i: Integer;
Begin
  Cauta := -1;
  For i := 1 To NrPaznici Do
    Begin
      If (P[i].max>=min) And (P[i].max<=max) Then
        Begin Cauta := i; Break End
      Else
        If (P[i].min>=min) And (P[i].min<=max) Then
          Begin Cauta := i; Break End
        Else
          If (P[i].min<=min) And (P[i].max>=max) Then
            Begin Cauta := i; Break End
          Else
            If (P[i].max<min) Or (P[i].min>max) Then
              Cauta := -1
    End;
End;

Procedure Intersectie(j: Integer; min, max: Byte);
Begin
  P[j].min := Maxim(min, P[j].min);
  P[j].max := Minim(max, P[j].max)
End;

procedure QuickSortCresc(Lo, Hi: Integer);

  procedure Sort(Stanga, Dreapta: Integer);
  var i, j, x: integer;
      y: Detinut;
  begin
    i := Stanga; j := Dreapta; x := D[(Stanga+Dreapta) DIV 2].min;
    repeat
      while D[i].min < x do i := i + 1;
      while x < D[j].min do j := j - 1;
      if i <= j then
      begin
        y := D[i]; D[i] := D[j]; D[j] := y;
        i := i + 1; j := j - 1;
      end;
    until i > j;
    if Stanga < j then Sort(Stanga, j);
    if i < Dreapta then Sort(i, Dreapta);
  end;

begin {QuickSort};
  Sort(Lo,Hi);
end;

procedure QuickSortDescresc(Lo, Hi: Integer);

  procedure Sort(Stanga, Dreapta: Integer);
  var i, j, x: integer;
      y: Detinut;
  begin
    i := Stanga; j := Dreapta; x := D[(Stanga+Dreapta) DIV 2].max;
    repeat
      while D[i].max > x do i := i + 1;
      while x > D[j].max do j := j - 1;
      if i <= j then
      begin
        y := D[i]; D[i] := D[j]; D[j] := y;
        i := i + 1; j := j - 1;
      end;
    until i > j;
    if Stanga < j then Sort(Stanga, j);
    if i < Dreapta then Sort(i, Dreapta);
  end;

begin {QuickSort};
  Sort(Lo,Hi);
end;

procedure SorteazaQ(Lo, Hi: Integer);

  procedure Sort(Stanga, Dreapta: Integer);
  var i, j, x: integer;
      y: Detinut;
  begin
    i := Stanga; j := Dreapta; x := D[(Stanga+Dreapta) DIV 2].NrOrd;
    repeat
      while D[i].NrOrd < x do i := i + 1;
      while x < D[j].NrOrd do j := j - 1;
      if i <= j then
      begin
        y := D[i]; D[i] := D[j]; D[j] := y;
        i := i + 1; j := j - 1;
      end;
    until i > j;
    if Stanga < j then Sort(Stanga, j);
    if i < Dreapta then Sort(i, Dreapta);
  end;

begin {QuickSort};
  Sort(Lo,Hi);
end;


Begin
  Assign(Fisier, 'sant.in'); Reset(Fisier);
  ReadLn(Fisier, N);
  For i := 1 To N Do
    Begin
      ReadLn(Fisier, D[i].min, D[i].max);
      D[i].NrOrd := i
    End;
  Close(Fisier);

  QuickSortCresc(1, N);

  i := 1; j := i+1;
  While j<=N Do
    Begin
      While (D[j].min=D[i].min) And (j<=N) Do Inc(j);
      QuickSortDescresc(i, j-1);
      i := j; j := i+1
    End;

  P[1].min := D[1].min; P[1].max := D[1].max; NrPaznici := 1;
  NrPaznici := 1; D[1].Nrp := NrPaznici;
  For i := 2 To N Do
    Begin
      min := D[i].min; max := D[i].max;
      j := Cauta(min, max);
      If j>0 Then
        Begin
          Intersectie(j, min, max);
          D[i].NrP := NrPaznici
        End
      Else
        Begin
          Inc(NrPaznici);
          P[NrPaznici].min := min;
          P[NrPaznici].max := max;
          D[i].NrP := NrPaznici
        End
    End;
  Assign(Fisier, 'sant.out'); ReWrite(Fisier);
  WriteLn(Fisier, NrPaznici);
  Prim := 1; Ultim := 1;
  For i := 1 To NrPaznici Do
    Begin
      WriteLn(Fisier, i, ' ', P[i].min, ' ', P[i].max);
      While D[Ultim].NrP=i Do Inc(Ultim);
      SorteazaQ(Prim, Ultim-1);
      For j := Prim To Ultim-2 Do Write(Fisier, D[j].NrOrd, ' ');
      WriteLn(Fisier, D[Ultim-1].NrOrd);
      Prim := Ultim;
    End;
  Close(Fisier)
End.

