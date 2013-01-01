namespace os_diaodu
{
    partial class about
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
            this.about_close = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // about_close
            // 
            this.about_close.Location = new System.Drawing.Point(175, 173);
            this.about_close.Name = "about_close";
            this.about_close.Size = new System.Drawing.Size(75, 23);
            this.about_close.TabIndex = 0;
            this.about_close.Text = "close";
            this.about_close.UseVisualStyleBackColor = true;
            this.about_close.Click += new System.EventHandler(this.about_close_Click);
            // 
            // about
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(276, 208);
            this.Controls.Add(this.about_close);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "about";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "about";
            this.Load += new System.EventHandler(this.about_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button about_close;
    }
}