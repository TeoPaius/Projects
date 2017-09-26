namespace Subiectul1
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
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.idDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.numeDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nrBlDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nrApDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.angajatDataGridViewCheckBoxColumn = new System.Windows.Forms.DataGridViewCheckBoxColumn();
            this.tabelBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dataSet = new Subiectul1.DataSet();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.numeTB = new System.Windows.Forms.TextBox();
            this.blocTB = new System.Windows.Forms.TextBox();
            this.apTB = new System.Windows.Forms.TextBox();
            this.addBtn = new System.Windows.Forms.Button();
            this.angBtn = new System.Windows.Forms.Button();
            this.angTB = new System.Windows.Forms.CheckBox();
            this.tabelTableAdapter = new Subiectul1.DataSetTableAdapters.TabelTableAdapter();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabelBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25.61036F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 74.38964F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 128F));
            this.tableLayoutPanel1.Controls.Add(this.dataGridView1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.label1, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.label2, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.label3, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.label4, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.numeTB, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.blocTB, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.apTB, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.addBtn, 2, 4);
            this.tableLayoutPanel1.Controls.Add(this.angBtn, 1, 5);
            this.tableLayoutPanel1.Controls.Add(this.angTB, 1, 4);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 6;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 40F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(542, 437);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idDataGridViewTextBoxColumn,
            this.numeDataGridViewTextBoxColumn,
            this.nrBlDataGridViewTextBoxColumn,
            this.nrApDataGridViewTextBoxColumn,
            this.angajatDataGridViewCheckBoxColumn});
            this.tableLayoutPanel1.SetColumnSpan(this.dataGridView1, 3);
            this.dataGridView1.DataSource = this.tabelBindingSource;
            this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridView1.Location = new System.Drawing.Point(3, 3);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.Size = new System.Drawing.Size(536, 231);
            this.dataGridView1.TabIndex = 1;
            // 
            // idDataGridViewTextBoxColumn
            // 
            this.idDataGridViewTextBoxColumn.DataPropertyName = "Id";
            this.idDataGridViewTextBoxColumn.HeaderText = "Id";
            this.idDataGridViewTextBoxColumn.Name = "idDataGridViewTextBoxColumn";
            this.idDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // numeDataGridViewTextBoxColumn
            // 
            this.numeDataGridViewTextBoxColumn.DataPropertyName = "Nume";
            this.numeDataGridViewTextBoxColumn.HeaderText = "Nume";
            this.numeDataGridViewTextBoxColumn.Name = "numeDataGridViewTextBoxColumn";
            this.numeDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // nrBlDataGridViewTextBoxColumn
            // 
            this.nrBlDataGridViewTextBoxColumn.DataPropertyName = "Nr_Bl";
            this.nrBlDataGridViewTextBoxColumn.HeaderText = "Nr_Bl";
            this.nrBlDataGridViewTextBoxColumn.Name = "nrBlDataGridViewTextBoxColumn";
            this.nrBlDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // nrApDataGridViewTextBoxColumn
            // 
            this.nrApDataGridViewTextBoxColumn.DataPropertyName = "Nr_Ap";
            this.nrApDataGridViewTextBoxColumn.HeaderText = "Nr_Ap";
            this.nrApDataGridViewTextBoxColumn.Name = "nrApDataGridViewTextBoxColumn";
            this.nrApDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // angajatDataGridViewCheckBoxColumn
            // 
            this.angajatDataGridViewCheckBoxColumn.DataPropertyName = "Angajat";
            this.angajatDataGridViewCheckBoxColumn.HeaderText = "Angajat";
            this.angajatDataGridViewCheckBoxColumn.Name = "angajatDataGridViewCheckBoxColumn";
            this.angajatDataGridViewCheckBoxColumn.ReadOnly = true;
            // 
            // tabelBindingSource
            // 
            this.tabelBindingSource.DataMember = "Tabel";
            this.tabelBindingSource.DataSource = this.dataSet;
            // 
            // dataSet
            // 
            this.dataSet.DataSetName = "DataSet";
            this.dataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 277);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Nr. Bloc:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(3, 237);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Nume:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(3, 317);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Nr. Ap";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(3, 357);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Angajat";
            // 
            // numeTB
            // 
            this.numeTB.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numeTB.Location = new System.Drawing.Point(109, 240);
            this.numeTB.Name = "numeTB";
            this.numeTB.Size = new System.Drawing.Size(301, 20);
            this.numeTB.TabIndex = 6;
            // 
            // blocTB
            // 
            this.blocTB.Dock = System.Windows.Forms.DockStyle.Fill;
            this.blocTB.Location = new System.Drawing.Point(109, 280);
            this.blocTB.Name = "blocTB";
            this.blocTB.Size = new System.Drawing.Size(301, 20);
            this.blocTB.TabIndex = 7;
            // 
            // apTB
            // 
            this.apTB.Dock = System.Windows.Forms.DockStyle.Fill;
            this.apTB.Location = new System.Drawing.Point(109, 320);
            this.apTB.Name = "apTB";
            this.apTB.Size = new System.Drawing.Size(301, 20);
            this.apTB.TabIndex = 8;
            // 
            // addBtn
            // 
            this.addBtn.Dock = System.Windows.Forms.DockStyle.Fill;
            this.addBtn.Location = new System.Drawing.Point(416, 360);
            this.addBtn.Name = "addBtn";
            this.addBtn.Size = new System.Drawing.Size(123, 34);
            this.addBtn.TabIndex = 10;
            this.addBtn.Text = "Adaugare";
            this.addBtn.UseVisualStyleBackColor = true;
            this.addBtn.Click += new System.EventHandler(this.addBtn_Click);
            // 
            // angBtn
            // 
            this.angBtn.Dock = System.Windows.Forms.DockStyle.Fill;
            this.angBtn.Location = new System.Drawing.Point(109, 400);
            this.angBtn.Name = "angBtn";
            this.angBtn.Size = new System.Drawing.Size(301, 34);
            this.angBtn.TabIndex = 11;
            this.angBtn.Text = "Locatari angajati";
            this.angBtn.UseVisualStyleBackColor = true;
            this.angBtn.Click += new System.EventHandler(this.angBtn_Click);
            // 
            // angTB
            // 
            this.angTB.AutoSize = true;
            this.angTB.Location = new System.Drawing.Point(109, 360);
            this.angTB.Name = "angTB";
            this.angTB.Size = new System.Drawing.Size(61, 17);
            this.angTB.TabIndex = 12;
            this.angTB.Text = "angajat";
            this.angTB.UseVisualStyleBackColor = true;
            // 
            // tabelTableAdapter
            // 
            this.tabelTableAdapter.ClearBeforeFill = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(542, 437);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "Form1";
            this.Text = "1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabelBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox numeTB;
        private System.Windows.Forms.TextBox blocTB;
        private System.Windows.Forms.TextBox apTB;
        private System.Windows.Forms.Button addBtn;
        private System.Windows.Forms.Button angBtn;
        private DataSet dataSet;
        private System.Windows.Forms.BindingSource tabelBindingSource;
        private DataSetTableAdapters.TabelTableAdapter tabelTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn numeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nrBlDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nrApDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewCheckBoxColumn angajatDataGridViewCheckBoxColumn;
        private System.Windows.Forms.CheckBox angTB;
    }
}

