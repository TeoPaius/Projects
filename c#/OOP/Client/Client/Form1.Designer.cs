namespace Client
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
            this.Message_Tb = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.Chat_Tb = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Message_Tb
            // 
            this.Message_Tb.Location = new System.Drawing.Point(47, 36);
            this.Message_Tb.Name = "Message_Tb";
            this.Message_Tb.Size = new System.Drawing.Size(100, 20);
            this.Message_Tb.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(202, 36);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Chat_Tb
            // 
            this.Chat_Tb.Location = new System.Drawing.Point(47, 162);
            this.Chat_Tb.Multiline = true;
            this.Chat_Tb.Name = "Chat_Tb";
            this.Chat_Tb.Size = new System.Drawing.Size(205, 124);
            this.Chat_Tb.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(420, 329);
            this.Controls.Add(this.Chat_Tb);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Message_Tb);
            this.Name = "Form1";
            this.Text = "Client";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Message_Tb;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox Chat_Tb;
    }
}

