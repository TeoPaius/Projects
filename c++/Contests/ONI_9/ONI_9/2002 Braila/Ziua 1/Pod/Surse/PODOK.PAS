{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,P-,Q-,R-,S-,T-,V+,X+,Y+}
{$M 65384,0,655360}

Program Pod;

Type Huge = Array[0..100] Of Byte;

Var f: Text;
    n: Integer;
    Tip: Array[-2..301] Of Byte;
    Rez: Array[-2..301] Of Huge;
    Last: Array[-2..301] Of Integer;
    Afis: Array[1..300] Of Integer;

Procedure Adun(Var a: Huge; b: Huge);
Var i, Max: Integer;     {adunare numere mari}
Begin
  If a[0]>b[0] Then
  Begin
    For i := b[0] + 1 To a[0] Do b[i] := 0;
    Max := a[0];
  End
  Else
    Begin
      For i := a[0] + 1 To b[0] Do a[i] := 0;
      Max := b[0];
    End;
  For i := 1 To Max Do a[i] := a[i] + b[i];
  a[0] := Max;
  For i := 1 To Max-1 Do
    Begin
      Inc(a[i+1], a[i] Div 10);
      a[i] := a[i] Mod 10;
    End;
  While a[a[0]]>9 Do
    Begin
      Inc(a[0]);
      a[a[0]] := a[a[0]-1] Div 10;
      a[a[0]-1] := a[a[0]-1] Mod 10;
    End;
End;

Procedure ReadData;
Var i,aux,n1:Integer;
Begin
  Assign(f, 'POD.IN'); Reset(f);
  Readln(f, n);
  Inc(n);
  FillChar(Tip, SizeOf(Tip), 0);
  Read(f, n1);       {numar scanduri lipsa}
  For i := 1 To n1 Do
    Begin
      Read(f, Aux);  {scanduri lipsa tip=2}
      Tip[Aux] := 2;
    End;
  Readln(f);
  Read(f, n1);       {numar scanduri deteriorate}
  For i := 1 To n1 Do
    Begin
      Read(f, Aux);  {scanduri deteriorate tip=1}
      Tip[Aux] := 1;
    End;
  Close(f);
End;

Procedure WriteSol;
Var i, pr: Integer;
Begin
  Assign(f, 'POD.OUT'); ReWrite(f);
  If Rez[n][0]>0 Then
    Begin          {afisare numar de solutii}
      For i := Rez[n][0] DownTo 1 Do Write(f, Rez[n][i]);
      Writeln(f);
      pr := 1;
      While n>0 Do        {refac solutia}
        Begin
          If Last[n]>0 Then
            Begin Afis[pr] := Last[n]; Inc(pr); End;
          n := Last[n];
        End;            {o afisez}
      For i := pr-1 DownTo 1 Do Write(f, Afis[i],' ');
      Writeln(f);
    End
  Else Writeln(f, -1);    {nu am solutii}
  Close(f);
End;

Procedure Rezolva;
Var i,j:Integer;
Begin              {in Rez se construieste numarul de solutii}
  For i := 1 To n Do Fillchar(Rez[i], SizeOf(Rez[i]), 0);
  If Tip[1] <> 2 Then                        {initializari}
    Begin Rez[1][0] := 1; Rez[1][1] := 1; End;
  For i := 2 To 3 Do
    If Tip[i]=0 Then
      Begin Rez[i][0] := 1; Rez[i][1] := 1; End;
  For i := 1 To n Do             {cnstruire solutie}
    Begin
      If Tip[i]=0 Then
        Begin
          For j := i-3 To i-2 Do
            If Tip[j]=0 Then
              Begin
                Adun(Rez[i], Rez[j]);
                If(Rez[j][0]>0) Then Last[i] := j;
              End;
          If Tip[i-1]<>2 Then
            Begin
              Adun(Rez[i], Rez[i-1]);
              If(Rez[i-1][0]>0) Then Last[i] := i-1;
            End;
        End
      Else
        If Tip[i]=1 Then
          Begin
           If Tip[i-1]<>2 Then Adun(Rez[i], Rez[i-1]);
           If(Rez[i-1][0]>0) Then Last[i] := i-1;
          End;
    End;
  WriteSol;
End;

Begin
  ReadData;
  Rezolva;
End.