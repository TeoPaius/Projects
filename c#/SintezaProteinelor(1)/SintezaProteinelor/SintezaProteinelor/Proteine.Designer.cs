namespace SintezaProteinelor
{
    partial class Proteine
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
            this.arnmTxt = new System.Windows.Forms.TextBox();
            this.trsBtn = new System.Windows.Forms.Button();
            this.outTxt = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.adnTxt = new System.Windows.Forms.TextBox();
            this.arntTxt = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // arnmTxt
            // 
            this.arnmTxt.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.arnmTxt.Location = new System.Drawing.Point(15, 41);
            this.arnmTxt.Name = "arnmTxt";
            this.arnmTxt.Size = new System.Drawing.Size(211, 20);
            this.arnmTxt.TabIndex = 0;
            this.arnmTxt.Text = "AUG";
            this.arnmTxt.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.inpTxt_KeyPress);
            // 
            // trsBtn
            // 
            this.trsBtn.Location = new System.Drawing.Point(243, 92);
            this.trsBtn.Name = "trsBtn";
            this.trsBtn.Size = new System.Drawing.Size(75, 23);
            this.trsBtn.TabIndex = 1;
            this.trsBtn.Text = "Transforma";
            this.trsBtn.UseVisualStyleBackColor = true;
            this.trsBtn.Click += new System.EventHandler(this.trsBtn_Click);
            // 
            // outTxt
            // 
            this.outTxt.Location = new System.Drawing.Point(12, 233);
            this.outTxt.Name = "outTxt";
            this.outTxt.Size = new System.Drawing.Size(293, 20);
            this.outTxt.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(105, 217);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(98, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Proteina rezultata : ";
            // 
            // adnTxt
            // 
            this.adnTxt.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.adnTxt.Location = new System.Drawing.Point(15, 95);
            this.adnTxt.Name = "adnTxt";
            this.adnTxt.Size = new System.Drawing.Size(211, 20);
            this.adnTxt.TabIndex = 5;
            this.adnTxt.Text = "TAC";
            this.adnTxt.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.adnTxt_KeyPress);
            // 
            // arntTxt
            // 
            this.arntTxt.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.arntTxt.Location = new System.Drawing.Point(15, 160);
            this.arntTxt.Name = "arntTxt";
            this.arntTxt.Size = new System.Drawing.Size(211, 20);
            this.arntTxt.TabIndex = 6;
            this.arntTxt.Text = "UAC";
            this.arntTxt.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.arntTxt_KeyPress);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(89, 25);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "ARNm";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(89, 79);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "ADN";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(92, 141);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(33, 13);
            this.label4.TabIndex = 9;
            this.label4.Text = "ARNt";
            // 
            // Proteine
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(317, 277);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.arntTxt);
            this.Controls.Add(this.adnTxt);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.outTxt);
            this.Controls.Add(this.trsBtn);
            this.Controls.Add(this.arnmTxt);
            this.Name = "Proteine";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox arnmTxt;
        private System.Windows.Forms.Button trsBtn;
        private System.Windows.Forms.TextBox outTxt;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox adnTxt;
        private System.Windows.Forms.TextBox arntTxt;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}

