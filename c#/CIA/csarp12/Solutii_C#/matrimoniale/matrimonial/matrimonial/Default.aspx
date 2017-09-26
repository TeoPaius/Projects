<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="matrimonial._Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
    <style type="text/css">
        .style1
        {
            text-align: left;
        }
        .style2
        {
            margin-top: 109px;
            height: 371px;
            position: absolute;
            left: 396px;
            top: -32px;
        }
        .style3
        {
            text-align: center;
        }
        .style4
        {
            height: 29px;
            position: absolute;
            left: 41px;
            top: 460px;
            width: 184px;
            right: 481px;
        }
        .style5
        {
            width: 221px;
            height: 26px;
            position: absolute;
            left: 40px;
            top: 555px;
        }
    </style>
</head>
<body bgcolor="#ffffcc">
    <form id="form1" runat="server">
    <div class="style1">
    
        <div class="style3">
        <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" 
            DeleteMethod="Delete" InsertMethod="Insert" 
            OldValuesParameterFormatString="original_{0}" SelectMethod="GetData" 
            TypeName="matrimonial.DataSet1TableAdapters.persTableAdapter" 
            UpdateMethod="Update">
            <DeleteParameters>
                <asp:Parameter Name="Original_Id" Type="Int32" />
            </DeleteParameters>
            <UpdateParameters>
                <asp:Parameter Name="Nume" Type="String" />
                <asp:Parameter Name="Prenume" Type="String" />
                <asp:Parameter Name="Varsta" Type="Int32" />
                <asp:Parameter Name="Sex" Type="String" />
                <asp:Parameter Name="Ocupatie" Type="String" />
                <asp:Parameter Name="Original_Id" Type="Int32" />
            </UpdateParameters>
            <InsertParameters>
                <asp:Parameter Name="Nume" Type="String" />
                <asp:Parameter Name="Prenume" Type="String" />
                <asp:Parameter Name="Varsta" Type="Int32" />
                <asp:Parameter Name="Sex" Type="String" />
                <asp:Parameter Name="Ocupatie" Type="String" />
            </InsertParameters>
        </asp:ObjectDataSource>
    
        <asp:Label ID="Label1" runat="server" Text="Agentie matrimoniala" Font-Bold="True"></asp:Label>
            <span lang="en-us">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span>
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" 
                AllowSorting="True" AutoGenerateColumns="False" BackColor="White" 
                BorderColor="#CC9966" BorderStyle="None" BorderWidth="1px" CellPadding="4" 
                CssClass="style2" DataKeyNames="Id" DataSourceID="ObjectDataSource1" 
                onselectedindexchanged="GridView1_SelectedIndexChanged" Width="546px">
                <FooterStyle BackColor="#FFFFCC" ForeColor="#330099" />
                <RowStyle BackColor="White" ForeColor="#330099" />
                <Columns>
                    <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" 
                        ShowSelectButton="True" />
                    <asp:BoundField DataField="Id" HeaderText="Id" InsertVisible="False" 
                        ReadOnly="True" SortExpression="Id" />
                    <asp:BoundField DataField="Nume" HeaderText="Nume" SortExpression="Nume" />
                    <asp:BoundField DataField="Prenume" HeaderText="Prenume" 
                        SortExpression="Prenume" />
                    <asp:BoundField DataField="Varsta" HeaderText="Varsta" 
                        SortExpression="Varsta" />
                    <asp:BoundField DataField="Sex" HeaderText="Sex" SortExpression="Sex" />
                    <asp:BoundField DataField="Ocupatie" HeaderText="Ocupatie" 
                        SortExpression="Ocupatie" />
                </Columns>
                <PagerStyle BackColor="#FFFFCC" ForeColor="#330099" HorizontalAlign="Center" />
                <SelectedRowStyle BackColor="#FFCC66" Font-Bold="True" ForeColor="#663399" />
                <HeaderStyle BackColor="#990000" Font-Bold="True" ForeColor="#FFFFCC" />
            </asp:GridView>
        </div>
        <div class="style3">
        </div>
    
        <br />
        <br />
        <br />
    
    </div>
    <p>
        &nbsp;</p>
    <p>
        <asp:Label ID="Label7" runat="server" Text="Formular de adaugare"></asp:Label>
    </p>
    <p>
        <asp:Label ID="Label2" runat="server" Text="Nume"></asp:Label>
        <span lang="en-us">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span>
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
    </p>
    <p>
        <asp:Label ID="Label3" runat="server" Text="Prenume"></asp:Label>
        <span lang="en-us">&nbsp;&nbsp;&nbsp;&nbsp; </span>
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
    </p>
    <p>
        <asp:Label ID="Label4" runat="server" Text="Varsta"></asp:Label>
        <span lang="en-us">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span>
        <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
    </p>
    <p>
        <asp:Label ID="Label5" runat="server" Text="Sex"></asp:Label>
        <span lang="en-us">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </span>
        <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
    </p>
    <p>
        <asp:Label ID="Label6" runat="server" Text="Ocupatie"></asp:Label>
        <span lang="en-us">&nbsp;&nbsp;&nbsp; </span>
        <asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
    </p>
    <p>
        <span lang="en-us">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        </span>
        <asp:Label ID="Label8" runat="server"></asp:Label>
    </p>
    <p>
        <asp:Button ID="Button2" runat="server" Text="Adaugare persoana" 
            onclick="Button2_Click" CssClass="style4" />
    <asp:Button ID="Button3" runat="server" Text="Varsta medie" CssClass="style5" 
            onclick="Button3_Click" />
    </p>
    <p>
        &nbsp;</p>
    </form>
</body>
</html>
