{$R-,S-}
Program sant;

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

Procedure Ordoneaza;
Var i, j, pKMmin: Integer;
    KMmax, KMmin: Byte;
    Aux: Detinut;
Begin
  For i := 1 To N-1 Do
    Begin
      KMmin := D[i].min; KMmax := D[i].max; pKMmin := i;
      For j := i+1 To N Do
        If D[j].min<KMmin Then
          Begin
            KMmax := D[j].max; KMmin := D[j].min; pKMmin := j
          End
        Else
          If D[j].min=KMmin Then
            If D[j].max>KMmax Then
            Begin
              KMmax := D[j].max; KMmin := D[j].min; pKMmin := j
            End;
       Aux := D[pKMmin]; D[pKMmin] := D[i]; D[i] := Aux
    End
End;

Procedure Sorteaza(p, u: Integer);
Var i, j, min, pozm: Integer;
    aux: Detinut;
Begin
  For i := p To u-1 Do
    Begin
      min := D[i].NrOrd; pozm := i;
      For j := i+1 To u Do
        If D[j].NrOrd<min Then
          Begin
            min := D[j].NrOrd; pozm := j
          End;
      Aux := D[i]; D[i] :=D[pozm]; D[pozm] := Aux
    End;
End;

Begin
  Assign(Fisier, 'sant.in'); Reset(Fisier);
  ReadLn(Fisier, N);
  For i := 1 To N Do
    Begin
      ReadLn(Fisier, D[i].min, D[i].max);
      D[i].NrOrd := i
    End;
  Ordoneaza;
  P[1].min := D[1].min; P[1].max := D[1].max;
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
  Close(Fisier);
  Assign(Fisier, 'sant.out'); ReWrite(Fisier);
  WriteLn(Fisier, NrPaznici);
  Prim := 1; Ultim := 1;
  For i := 1 To NrPaznici Do
    Begin
      WriteLn(Fisier, i, ' ', P[i].min, ' ', P[i].max);
      While D[Ultim].NrP=i Do Inc(Ultim);
      Sorteaza(Prim, Ultim-1);
      For j := Prim To Ultim-2 Do Write(Fisier, D[j].NrOrd, ' ');
      WriteLn(Fisier, D[Ultim-1].NrOrd);
      Prim := Ultim;
    End;
  Close(Fisier)
End.
