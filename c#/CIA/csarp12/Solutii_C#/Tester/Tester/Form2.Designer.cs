namespace Tester
{
    partial class Form2
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
            this.txtIntrebare = new System.Windows.Forms.TextBox();
            this.pnlRaspunsuri = new System.Windows.Forms.Panel();
            this.btnAnterior = new System.Windows.Forms.Button();
            this.btnUrmator = new System.Windows.Forms.Button();
            this.btnValidare = new System.Windows.Forms.Button();
            this.btnFinalizare = new System.Windows.Forms.Button();
            this.lblAfisare = new System.Windows.Forms.Label();
            this.btnInchidere = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtIntrebare
            // 
            this.txtIntrebare.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtIntrebare.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.txtIntrebare.Location = new System.Drawing.Point(56, 12);
            this.txtIntrebare.Multiline = true;
            this.txtIntrebare.Name = "txtIntrebare";
            this.txtIntrebare.Size = new System.Drawing.Size(787, 70);
            this.txtIntrebare.TabIndex = 0;
            // 
            // pnlRaspunsuri
            // 
            this.pnlRaspunsuri.Location = new System.Drawing.Point(56, 106);
            this.pnlRaspunsuri.Name = "pnlRaspunsuri";
            this.pnlRaspunsuri.Size = new System.Drawing.Size(476, 235);
            this.pnlRaspunsuri.TabIndex = 1;
            // 
            // btnAnterior
            // 
            this.btnAnterior.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAnterior.ForeColor = System.Drawing.SystemColors.Highlight;
            this.btnAnterior.Location = new System.Drawing.Point(114, 372);
            this.btnAnterior.Name = "btnAnterior";
            this.btnAnterior.Size = new System.Drawing.Size(151, 34);
            this.btnAnterior.TabIndex = 2;
            this.btnAnterior.Text = "Previous";
            this.btnAnterior.UseVisualStyleBackColor = true;
            this.btnAnterior.Click += new System.EventHandler(this.btnAnterior_Click);
            // 
            // btnUrmator
            // 
            this.btnUrmator.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUrmator.ForeColor = System.Drawing.SystemColors.Highlight;
            this.btnUrmator.Location = new System.Drawing.Point(392, 372);
            this.btnUrmator.Name = "btnUrmator";
            this.btnUrmator.Size = new System.Drawing.Size(151, 34);
            this.btnUrmator.TabIndex = 3;
            this.btnUrmator.Text = "Next";
            this.btnUrmator.UseVisualStyleBackColor = true;
            this.btnUrmator.Click += new System.EventHandler(this.btnUrmator_Click);
            // 
            // btnValidare
            // 
            this.btnValidare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnValidare.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.btnValidare.Location = new System.Drawing.Point(844, 384);
            this.btnValidare.Name = "btnValidare";
            this.btnValidare.Size = new System.Drawing.Size(156, 33);
            this.btnValidare.TabIndex = 4;
            this.btnValidare.Text = "Validare raspuns";
            this.btnValidare.UseVisualStyleBackColor = true;
            this.btnValidare.Click += new System.EventHandler(this.btnValidare_Click);
            // 
            // btnFinalizare
            // 
            this.btnFinalizare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnFinalizare.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.btnFinalizare.Location = new System.Drawing.Point(868, 197);
            this.btnFinalizare.Name = "btnFinalizare";
            this.btnFinalizare.Size = new System.Drawing.Size(132, 33);
            this.btnFinalizare.TabIndex = 5;
            this.btnFinalizare.Text = "Finalizare test";
            this.btnFinalizare.UseVisualStyleBackColor = true;
            this.btnFinalizare.Click += new System.EventHandler(this.btnFinalizare_Click);
            // 
            // lblAfisare
            // 
            this.lblAfisare.AutoSize = true;
            this.lblAfisare.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAfisare.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.lblAfisare.Location = new System.Drawing.Point(578, 128);
            this.lblAfisare.Name = "lblAfisare";
            this.lblAfisare.Size = new System.Drawing.Size(0, 24);
            this.lblAfisare.TabIndex = 6;
            // 
            // btnInchidere
            // 
            this.btnInchidere.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnInchidere.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.btnInchidere.Location = new System.Drawing.Point(868, 49);
            this.btnInchidere.Name = "btnInchidere";
            this.btnInchidere.Size = new System.Drawing.Size(132, 33);
            this.btnInchidere.TabIndex = 7;
            this.btnInchidere.Text = "Inchidere";
            this.btnInchidere.UseVisualStyleBackColor = true;
            this.btnInchidere.Click += new System.EventHandler(this.btnInchidere_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1013, 443);
            this.Controls.Add(this.btnInchidere);
            this.Controls.Add(this.lblAfisare);
            this.Controls.Add(this.btnFinalizare);
            this.Controls.Add(this.btnValidare);
            this.Controls.Add(this.btnUrmator);
            this.Controls.Add(this.btnAnterior);
            this.Controls.Add(this.pnlRaspunsuri);
            this.Controls.Add(this.txtIntrebare);
            this.Name = "Form2";
            this.Text = "CIA 2012 - faza judeteana";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtIntrebare;
        private System.Windows.Forms.Panel pnlRaspunsuri;
        private System.Windows.Forms.Button btnAnterior;
        private System.Windows.Forms.Button btnUrmator;
        private System.Windows.Forms.Button btnValidare;
        private System.Windows.Forms.Button btnFinalizare;
        private System.Windows.Forms.Label lblAfisare;
        private System.Windows.Forms.Button btnInchidere;
    }
}