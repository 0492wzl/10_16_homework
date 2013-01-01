namespace os_diaodu
{
    partial class input_data
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
            this.FCFS = new System.Windows.Forms.RadioButton();
            this.SPF = new System.Windows.Forms.RadioButton();
            this.SUMMIT = new System.Windows.Forms.Button();
            this.RESET = new System.Windows.Forms.Button();
            this.b_c = new System.Windows.Forms.TextBox();
            this.b_s = new System.Windows.Forms.TextBox();
            this.a_s = new System.Windows.Forms.TextBox();
            this.a_c = new System.Windows.Forms.TextBox();
            this.c_s = new System.Windows.Forms.TextBox();
            this.c_c = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // FCFS
            // 
            this.FCFS.AutoSize = true;
            this.FCFS.Location = new System.Drawing.Point(119, 26);
            this.FCFS.Name = "FCFS";
            this.FCFS.Size = new System.Drawing.Size(47, 16);
            this.FCFS.TabIndex = 1;
            this.FCFS.TabStop = true;
            this.FCFS.Text = "FCFS";
            this.FCFS.UseVisualStyleBackColor = true;
            // 
            // SPF
            // 
            this.SPF.AutoSize = true;
            this.SPF.Location = new System.Drawing.Point(218, 26);
            this.SPF.Name = "SPF";
            this.SPF.Size = new System.Drawing.Size(41, 16);
            this.SPF.TabIndex = 2;
            this.SPF.TabStop = true;
            this.SPF.Text = "SPF";
            this.SPF.UseVisualStyleBackColor = true;
            // 
            // SUMMIT
            // 
            this.SUMMIT.Location = new System.Drawing.Point(110, 241);
            this.SUMMIT.Name = "SUMMIT";
            this.SUMMIT.Size = new System.Drawing.Size(56, 23);
            this.SUMMIT.TabIndex = 3;
            this.SUMMIT.Text = "SUMMIT";
            this.SUMMIT.UseVisualStyleBackColor = true;
            this.SUMMIT.Click += new System.EventHandler(this.SUMMIT_Click);
            // 
            // RESET
            // 
            this.RESET.Location = new System.Drawing.Point(218, 241);
            this.RESET.Name = "RESET";
            this.RESET.Size = new System.Drawing.Size(56, 23);
            this.RESET.TabIndex = 10;
            this.RESET.Text = "RESET";
            this.RESET.UseVisualStyleBackColor = true;
            this.RESET.Click += new System.EventHandler(this.RESET_Click);
            // 
            // b_c
            // 
            this.b_c.Location = new System.Drawing.Point(110, 140);
            this.b_c.Name = "b_c";
            this.b_c.Size = new System.Drawing.Size(56, 21);
            this.b_c.TabIndex = 5;
            this.b_c.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // b_s
            // 
            this.b_s.Location = new System.Drawing.Point(218, 140);
            this.b_s.Name = "b_s";
            this.b_s.Size = new System.Drawing.Size(56, 21);
            this.b_s.TabIndex = 7;
            this.b_s.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // a_s
            // 
            this.a_s.Location = new System.Drawing.Point(218, 89);
            this.a_s.Name = "a_s";
            this.a_s.Size = new System.Drawing.Size(56, 21);
            this.a_s.TabIndex = 6;
            this.a_s.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // a_c
            // 
            this.a_c.Location = new System.Drawing.Point(110, 89);
            this.a_c.Name = "a_c";
            this.a_c.Size = new System.Drawing.Size(56, 21);
            this.a_c.TabIndex = 4;
            this.a_c.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // c_s
            // 
            this.c_s.Location = new System.Drawing.Point(218, 190);
            this.c_s.Name = "c_s";
            this.c_s.Size = new System.Drawing.Size(56, 21);
            this.c_s.TabIndex = 9;
            this.c_s.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // c_c
            // 
            this.c_c.Location = new System.Drawing.Point(110, 190);
            this.c_c.Name = "c_c";
            this.c_c.Size = new System.Drawing.Size(56, 21);
            this.c_c.TabIndex = 8;
            this.c_c.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox1.Location = new System.Drawing.Point(29, 92);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(56, 14);
            this.textBox1.TabIndex = 11;
            this.textBox1.Text = "A进程：";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox2.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox2.Location = new System.Drawing.Point(29, 143);
            this.textBox2.Name = "textBox2";
            this.textBox2.ReadOnly = true;
            this.textBox2.Size = new System.Drawing.Size(56, 14);
            this.textBox2.TabIndex = 12;
            this.textBox2.Text = "B进程：";
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox3
            // 
            this.textBox3.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox3.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox3.Location = new System.Drawing.Point(29, 197);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(56, 14);
            this.textBox3.TabIndex = 13;
            this.textBox3.Text = "C进程：";
            this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox4
            // 
            this.textBox4.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox4.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox4.Location = new System.Drawing.Point(218, 69);
            this.textBox4.Name = "textBox4";
            this.textBox4.ReadOnly = true;
            this.textBox4.Size = new System.Drawing.Size(56, 14);
            this.textBox4.TabIndex = 14;
            this.textBox4.Text = "服务时间";
            this.textBox4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox5
            // 
            this.textBox5.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox5.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox5.Location = new System.Drawing.Point(110, 69);
            this.textBox5.Name = "textBox5";
            this.textBox5.ReadOnly = true;
            this.textBox5.Size = new System.Drawing.Size(56, 14);
            this.textBox5.TabIndex = 15;
            this.textBox5.Text = "到达时间";
            this.textBox5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox6
            // 
            this.textBox6.BackColor = System.Drawing.SystemColors.Menu;
            this.textBox6.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox6.Location = new System.Drawing.Point(12, 28);
            this.textBox6.Name = "textBox6";
            this.textBox6.ReadOnly = true;
            this.textBox6.Size = new System.Drawing.Size(101, 14);
            this.textBox6.TabIndex = 16;
            this.textBox6.Text = "调度算法处理方式";
            this.textBox6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // input_data
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(319, 296);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.c_s);
            this.Controls.Add(this.c_c);
            this.Controls.Add(this.RESET);
            this.Controls.Add(this.b_c);
            this.Controls.Add(this.b_s);
            this.Controls.Add(this.a_s);
            this.Controls.Add(this.a_c);
            this.Controls.Add(this.SUMMIT);
            this.Controls.Add(this.SPF);
            this.Controls.Add(this.FCFS);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "input_data";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "input_data";
            this.Load += new System.EventHandler(this.input_data_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button SUMMIT;
        private System.Windows.Forms.Button RESET;
        private System.Windows.Forms.TextBox b_c;
        private System.Windows.Forms.TextBox b_s;
        private System.Windows.Forms.TextBox c_s;
        private System.Windows.Forms.TextBox c_c;
        private System.Windows.Forms.RadioButton FCFS;
        private System.Windows.Forms.RadioButton SPF;
        private System.Windows.Forms.TextBox a_s;
        private System.Windows.Forms.TextBox a_c;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox textBox6;

    }
}