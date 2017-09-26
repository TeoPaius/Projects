namespace Atestat12
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
            this.fotbalDataGridView = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxGazda = new System.Windows.Forms.TextBox();
            this.textBoxOaspeti = new System.Windows.Forms.TextBox();
            this.addButton = new System.Windows.Forms.Button();
            this.sortButton = new System.Windows.Forms.Button();
            this.numericDI = new System.Windows.Forms.NumericUpDown();
            this.numericEtapa = new System.Windows.Forms.NumericUpDown();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.fotbalBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.database1DataSet = new Atestat12.Database1DataSet();
            this.fotbalTableAdapter = new Atestat12.Database1DataSetTableAdapters.FotbalTableAdapter();
            this.tableAdapterManager = new Atestat12.Database1DataSetTableAdapters.TableAdapterManager();
            ((System.ComponentModel.ISupportInitialize)(this.fotbalDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericDI)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericEtapa)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fotbalBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // fotbalDataGridView
            // 
            this.fotbalDataGridView.AutoGenerateColumns = false;
            this.fotbalDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.fotbalDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn4,
            this.dataGridViewTextBoxColumn5,
            this.dataGridViewTextBoxColumn6});
            this.fotbalDataGridView.DataSource = this.fotbalBindingSource;
            this.fotbalDataGridView.Location = new System.Drawing.Point(12, 12);
            this.fotbalDataGridView.Name = "fotbalDataGridView";
            this.fotbalDataGridView.Size = new System.Drawing.Size(645, 220);
            this.fotbalDataGridView.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 253);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(21, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "DI:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 334);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Gazde:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 371);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(46, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Oaspeti:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 296);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 13);
            this.label5.TabIndex = 6;
            this.label5.Text = "Etapa:";
            // 
            // textBoxGazda
            // 
            this.textBoxGazda.Location = new System.Drawing.Point(112, 331);
            this.textBoxGazda.Name = "textBoxGazda";
            this.textBoxGazda.Size = new System.Drawing.Size(100, 20);
            this.textBoxGazda.TabIndex = 9;
            // 
            // textBoxOaspeti
            // 
            this.textBoxOaspeti.Location = new System.Drawing.Point(112, 368);
            this.textBoxOaspeti.Name = "textBoxOaspeti";
            this.textBoxOaspeti.Size = new System.Drawing.Size(100, 20);
            this.textBoxOaspeti.TabIndex = 10;
            // 
            // addButton
            // 
            this.addButton.Location = new System.Drawing.Point(262, 366);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(75, 23);
            this.addButton.TabIndex = 11;
            this.addButton.Text = "Adauga";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // sortButton
            // 
            this.sortButton.Location = new System.Drawing.Point(467, 366);
            this.sortButton.Name = "sortButton";
            this.sortButton.Size = new System.Drawing.Size(75, 23);
            this.sortButton.TabIndex = 12;
            this.sortButton.Text = "Sorteaza";
            this.sortButton.UseVisualStyleBackColor = true;
            this.sortButton.Click += new System.EventHandler(this.sortButton_Click);
            // 
            // numericDI
            // 
            this.numericDI.Location = new System.Drawing.Point(112, 251);
            this.numericDI.Name = "numericDI";
            this.numericDI.Size = new System.Drawing.Size(54, 20);
            this.numericDI.TabIndex = 13;
            // 
            // numericEtapa
            // 
            this.numericEtapa.Location = new System.Drawing.Point(112, 294);
            this.numericEtapa.Name = "numericEtapa";
            this.numericEtapa.Size = new System.Drawing.Size(54, 20);
            this.numericEtapa.TabIndex = 14;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.DataPropertyName = "DI";
            this.dataGridViewTextBoxColumn1.HeaderText = "DI";
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.DataPropertyName = "Etapa";
            this.dataGridViewTextBoxColumn2.HeaderText = "Etapa";
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.DataPropertyName = "Gazde";
            this.dataGridViewTextBoxColumn3.HeaderText = "Gazde";
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.DataPropertyName = "Oaspeti";
            this.dataGridViewTextBoxColumn4.HeaderText = "Oaspeti";
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.DataPropertyName = "Gol_gazd";
            this.dataGridViewTextBoxColumn5.HeaderText = "Gol_gazd";
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.DataPropertyName = "Gol_oasp";
            this.dataGridViewTextBoxColumn6.HeaderText = "Gol_oasp";
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            // 
            // fotbalBindingSource
            // 
            this.fotbalBindingSource.DataMember = "Fotbal";
            this.fotbalBindingSource.DataSource = this.database1DataSet;
            // 
            // database1DataSet
            // 
            this.database1DataSet.DataSetName = "Database1DataSet";
            this.database1DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // fotbalTableAdapter
            // 
            this.fotbalTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.FotbalTableAdapter = this.fotbalTableAdapter;
            this.tableAdapterManager.UpdateOrder = Atestat12.Database1DataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(676, 414);
            this.Controls.Add(this.numericEtapa);
            this.Controls.Add(this.numericDI);
            this.Controls.Add(this.sortButton);
            this.Controls.Add(this.addButton);
            this.Controls.Add(this.textBoxOaspeti);
            this.Controls.Add(this.textBoxGazda);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.fotbalDataGridView);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.fotbalDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericDI)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericEtapa)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fotbalBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.database1DataSet)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Database1DataSet database1DataSet;
        private System.Windows.Forms.BindingSource fotbalBindingSource;
        private Database1DataSetTableAdapters.FotbalTableAdapter fotbalTableAdapter;
        private Database1DataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.DataGridView fotbalDataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxGazda;
        private System.Windows.Forms.TextBox textBoxOaspeti;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button sortButton;
        private System.Windows.Forms.NumericUpDown numericDI;
        private System.Windows.Forms.NumericUpDown numericEtapa;
    }
}

