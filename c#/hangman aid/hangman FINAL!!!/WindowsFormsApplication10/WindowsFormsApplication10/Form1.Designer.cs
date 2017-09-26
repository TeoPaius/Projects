namespace WindowsFormsApplication10
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.pictureBox0 = new System.Windows.Forms.PictureBox();
            this.checkchar = new System.Windows.Forms.CheckBox();
            this.label_help = new System.Windows.Forms.Label();
            this.label_wins = new System.Windows.Forms.Label();
            this.label_losses = new System.Windows.Forms.Label();
            this.buton_closehelp = new WindowsFormsApplication10.Buton();
            this.buton_help = new WindowsFormsApplication10.Buton();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox0)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Control;
            this.textBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox1.CharacterCasing = System.Windows.Forms.CharacterCasing.Lower;
            this.textBox1.Cursor = System.Windows.Forms.Cursors.Arrow;
            resources.ApplyResources(this.textBox1, "textBox1");
            this.textBox1.Name = "textBox1";
            this.textBox1.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textBox1_KeyDown);
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.Name = "label1";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // pictureBox0
            // 
            resources.ApplyResources(this.pictureBox0, "pictureBox0");
            this.pictureBox0.Name = "pictureBox0";
            this.pictureBox0.TabStop = false;
            this.pictureBox0.Click += new System.EventHandler(this.pictureBox0_Click);
            // 
            // checkchar
            // 
            resources.ApplyResources(this.checkchar, "checkchar");
            this.checkchar.Name = "checkchar";
            this.checkchar.UseVisualStyleBackColor = true;
            this.checkchar.CheckStateChanged += new System.EventHandler(this.checkchar_CheckedChanged);
            // 
            // label_help
            // 
            resources.ApplyResources(this.label_help, "label_help");
            this.label_help.Name = "label_help";
            // 
            // label_wins
            // 
            resources.ApplyResources(this.label_wins, "label_wins");
            this.label_wins.Name = "label_wins";
            // 
            // label_losses
            // 
            resources.ApplyResources(this.label_losses, "label_losses");
            this.label_losses.Name = "label_losses";
            // 
            // buton_closehelp
            // 
            this.buton_closehelp.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(91)))), ((int)(((byte)(17)))), ((int)(((byte)(34)))));
            this.buton_closehelp.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(91)))), ((int)(((byte)(17)))), ((int)(((byte)(34)))));
            resources.ApplyResources(this.buton_closehelp, "buton_closehelp");
            this.buton_closehelp.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(254)))), ((int)(((byte)(199)))));
            this.buton_closehelp.Name = "buton_closehelp";
            this.buton_closehelp.UseVisualStyleBackColor = false;
            this.buton_closehelp.Click += new System.EventHandler(this.buton_closehelp_Click);
            // 
            // buton_help
            // 
            this.buton_help.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(91)))), ((int)(((byte)(17)))), ((int)(((byte)(34)))));
            this.buton_help.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(91)))), ((int)(((byte)(17)))), ((int)(((byte)(34)))));
            resources.ApplyResources(this.buton_help, "buton_help");
            this.buton_help.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(254)))), ((int)(((byte)(199)))));
            this.buton_help.Name = "buton_help";
            this.buton_help.UseVisualStyleBackColor = false;
            this.buton_help.Click += new System.EventHandler(this.buton_help_Click);
            // 
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.Controls.Add(this.label_losses);
            this.Controls.Add(this.label_wins);
            this.Controls.Add(this.label_help);
            this.Controls.Add(this.buton_closehelp);
            this.Controls.Add(this.buton_help);
            this.Controls.Add(this.checkchar);
            this.Controls.Add(this.pictureBox0);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox0)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.PictureBox pictureBox0;
        private System.Windows.Forms.CheckBox checkchar;
        public System.Windows.Forms.TextBox textBox1;
        private Buton buton_help;
        private Buton buton_closehelp;
        private System.Windows.Forms.Label label_help;
        private System.Windows.Forms.Label label_wins;
        private System.Windows.Forms.Label label_losses;

    }
}

