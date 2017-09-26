namespace BazaDeDataS21
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.iDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sPECIEDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sEXDataGridViewCheckBoxColumn = new System.Windows.Forms.DataGridViewCheckBoxColumn();
            this.dATANDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gREUTATEDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tabelAnimaleBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.databaseDataSet = new BazaDeDataS21.DatabaseDataSet();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.txtSpecia = new System.Windows.Forms.TextBox();
            this.txtGreutate = new System.Windows.Forms.TextBox();
            this.dtpDataNasterii = new System.Windows.Forms.DateTimePicker();
            this.sexCB = new System.Windows.Forms.CheckBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.tabelAnimaleTableAdapter = new BazaDeDataS21.DatabaseDataSetTableAdapters.TabelAnimaleTableAdapter();
            this.databaseDataSet1 = new BazaDeDataS21.DatabaseDataSet();
            this.sortBtn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabelAnimaleBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.databaseDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.databaseDataSet1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.iDDataGridViewTextBoxColumn,
            this.sPECIEDataGridViewTextBoxColumn,
            this.sEXDataGridViewCheckBoxColumn,
            this.dATANDataGridViewTextBoxColumn,
            this.gREUTATEDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.tabelAnimaleBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(21, 265);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(546, 209);
            this.dataGridView1.TabIndex = 0;
            // 
            // iDDataGridViewTextBoxColumn
            // 
            this.iDDataGridViewTextBoxColumn.DataPropertyName = "ID";
            this.iDDataGridViewTextBoxColumn.HeaderText = "ID";
            this.iDDataGridViewTextBoxColumn.Name = "iDDataGridViewTextBoxColumn";
            this.iDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // sPECIEDataGridViewTextBoxColumn
            // 
            this.sPECIEDataGridViewTextBoxColumn.DataPropertyName = "SPECIE";
            this.sPECIEDataGridViewTextBoxColumn.HeaderText = "SPECIE";
            this.sPECIEDataGridViewTextBoxColumn.Name = "sPECIEDataGridViewTextBoxColumn";
            // 
            // sEXDataGridViewCheckBoxColumn
            // 
            this.sEXDataGridViewCheckBoxColumn.DataPropertyName = "SEX";
            this.sEXDataGridViewCheckBoxColumn.HeaderText = "SEX";
            this.sEXDataGridViewCheckBoxColumn.Name = "sEXDataGridViewCheckBoxColumn";
            // 
            // dATANDataGridViewTextBoxColumn
            // 
            this.dATANDataGridViewTextBoxColumn.DataPropertyName = "DATA_N";
            this.dATANDataGridViewTextBoxColumn.HeaderText = "DATA_N";
            this.dATANDataGridViewTextBoxColumn.Name = "dATANDataGridViewTextBoxColumn";
            // 
            // gREUTATEDataGridViewTextBoxColumn
            // 
            this.gREUTATEDataGridViewTextBoxColumn.DataPropertyName = "GREUTATE";
            this.gREUTATEDataGridViewTextBoxColumn.HeaderText = "GREUTATE";
            this.gREUTATEDataGridViewTextBoxColumn.Name = "gREUTATEDataGridViewTextBoxColumn";
            // 
            // tabelAnimaleBindingSource
            // 
            this.tabelAnimaleBindingSource.DataMember = "TabelAnimale";
            this.tabelAnimaleBindingSource.DataSource = this.databaseDataSet;
            // 
            // databaseDataSet
            // 
            this.databaseDataSet.DataSetName = "DatabaseDataSet";
            this.databaseDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(32, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(43, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Specia:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 62);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(68, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "DataNasterii:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(24, 100);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(51, 13);
            this.label4.TabIndex = 4;
            this.label4.Text = "Greutate:";
            // 
            // txtSpecia
            // 
            this.txtSpecia.Location = new System.Drawing.Point(81, 13);
            this.txtSpecia.Name = "txtSpecia";
            this.txtSpecia.Size = new System.Drawing.Size(100, 20);
            this.txtSpecia.TabIndex = 5;
            // 
            // txtGreutate
            // 
            this.txtGreutate.Location = new System.Drawing.Point(81, 97);
            this.txtGreutate.Name = "txtGreutate";
            this.txtGreutate.Size = new System.Drawing.Size(100, 20);
            this.txtGreutate.TabIndex = 7;
            // 
            // dtpDataNasterii
            // 
            this.dtpDataNasterii.Location = new System.Drawing.Point(81, 62);
            this.dtpDataNasterii.Name = "dtpDataNasterii";
            this.dtpDataNasterii.Size = new System.Drawing.Size(200, 20);
            this.dtpDataNasterii.TabIndex = 8;
            // 
            // sexCB
            // 
            this.sexCB.AutoSize = true;
            this.sexCB.Location = new System.Drawing.Point(81, 39);
            this.sexCB.Name = "sexCB";
            this.sexCB.Size = new System.Drawing.Size(89, 17);
            this.sexCB.TabIndex = 9;
            this.sexCB.Text = "Sex Masculin";
            this.sexCB.UseVisualStyleBackColor = true;
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(196, 140);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 39);
            this.btnAdd.TabIndex = 10;
            this.btnAdd.Text = "Adaugati Animal";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // tabelAnimaleTableAdapter
            // 
            this.tabelAnimaleTableAdapter.ClearBeforeFill = true;
            // 
            // databaseDataSet1
            // 
            this.databaseDataSet1.DataSetName = "DatabaseDataSet";
            this.databaseDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // sortBtn
            // 
            this.sortBtn.Location = new System.Drawing.Point(49, 148);
            this.sortBtn.Name = "sortBtn";
            this.sortBtn.Size = new System.Drawing.Size(75, 23);
            this.sortBtn.TabIndex = 11;
            this.sortBtn.Text = "Sorteaza";
            this.sortBtn.UseVisualStyleBackColor = true;
            this.sortBtn.Click += new System.EventHandler(this.sortBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(680, 486);
            this.Controls.Add(this.sortBtn);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.sexCB);
            this.Controls.Add(this.dtpDataNasterii);
            this.Controls.Add(this.txtGreutate);
            this.Controls.Add(this.txtSpecia);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Subiectul 22";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabelAnimaleBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.databaseDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.databaseDataSet1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private DatabaseDataSet databaseDataSet;
        private System.Windows.Forms.BindingSource tabelAnimaleBindingSource;
        private DatabaseDataSetTableAdapters.TabelAnimaleTableAdapter tabelAnimaleTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sPECIEDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewCheckBoxColumn sEXDataGridViewCheckBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dATANDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gREUTATEDataGridViewTextBoxColumn;
        private DatabaseDataSet databaseDataSet1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtSpecia;
        private System.Windows.Forms.TextBox txtGreutate;
        private System.Windows.Forms.DateTimePicker dtpDataNasterii;
        private System.Windows.Forms.CheckBox sexCB;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button sortBtn;
    }
}

