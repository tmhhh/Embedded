namespace Temp_Humid
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
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.btnHumid = new System.Windows.Forms.Button();
            this.btnTemp = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(80, 135);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(203, 75);
            this.button1.TabIndex = 0;
            this.button1.Text = "Do am";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(80, 31);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(203, 71);
            this.button2.TabIndex = 1;
            this.button2.Text = "Nhiet do";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // btnHumid
            // 
            this.btnHumid.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnHumid.Location = new System.Drawing.Point(299, 137);
            this.btnHumid.Name = "btnHumid";
            this.btnHumid.Size = new System.Drawing.Size(438, 71);
            this.btnHumid.TabIndex = 2;
            this.btnHumid.UseVisualStyleBackColor = false;
            // 
            // btnTemp
            // 
            this.btnTemp.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnTemp.Location = new System.Drawing.Point(299, 31);
            this.btnTemp.Name = "btnTemp";
            this.btnTemp.Size = new System.Drawing.Size(438, 71);
            this.btnTemp.TabIndex = 3;
            this.btnTemp.UseVisualStyleBackColor = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnTemp);
            this.Controls.Add(this.btnHumid);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button btnHumid;
        private System.Windows.Forms.Button btnTemp;
    }
}

