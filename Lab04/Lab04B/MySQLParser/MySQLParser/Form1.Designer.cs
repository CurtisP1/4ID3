namespace MySQLParser
{
    partial class MySQLParser
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            txt_DatabaseIP = new TextBox();
            lbl_DatabaseIP = new Label();
            btn_QueryDatabase = new Button();
            grid_DataView = new DataGridView();
            lbl_DatabaseUser = new Label();
            txt_DatabaseUser = new TextBox();
            lbl_DatabaseName = new Label();
            lbl_DatabasePass = new Label();
            txt_DatabasePass = new TextBox();
            txt_DatabaseName = new TextBox();
            txt_QueryDatabase = new TextBox();
            ((System.ComponentModel.ISupportInitialize)grid_DataView).BeginInit();
            SuspendLayout();
            // 
            // txt_DatabaseIP
            // 
            txt_DatabaseIP.Location = new Point(183, 74);
            txt_DatabaseIP.Name = "txt_DatabaseIP";
            txt_DatabaseIP.Size = new Size(176, 27);
            txt_DatabaseIP.TabIndex = 0;
            // 
            // lbl_DatabaseIP
            // 
            lbl_DatabaseIP.AutoSize = true;
            lbl_DatabaseIP.Location = new Point(35, 77);
            lbl_DatabaseIP.Name = "lbl_DatabaseIP";
            lbl_DatabaseIP.Size = new Size(88, 20);
            lbl_DatabaseIP.TabIndex = 1;
            lbl_DatabaseIP.Text = "Database IP";
            // 
            // btn_QueryDatabase
            // 
            btn_QueryDatabase.Location = new Point(35, 178);
            btn_QueryDatabase.Name = "btn_QueryDatabase";
            btn_QueryDatabase.Size = new Size(164, 29);
            btn_QueryDatabase.TabIndex = 2;
            btn_QueryDatabase.Text = "Query Database";
            btn_QueryDatabase.UseVisualStyleBackColor = true;
            btn_QueryDatabase.Click += btn_QueryDatabase_Click;
            // 
            // grid_DataView
            // 
            grid_DataView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            grid_DataView.Location = new Point(35, 224);
            grid_DataView.Name = "grid_DataView";
            grid_DataView.RowHeadersWidth = 51;
            grid_DataView.RowTemplate.Height = 29;
            grid_DataView.Size = new Size(701, 188);
            grid_DataView.TabIndex = 3;
            // 
            // lbl_DatabaseUser
            // 
            lbl_DatabaseUser.AutoSize = true;
            lbl_DatabaseUser.Location = new Point(402, 77);
            lbl_DatabaseUser.Name = "lbl_DatabaseUser";
            lbl_DatabaseUser.Size = new Size(142, 20);
            lbl_DatabaseUser.TabIndex = 4;
            lbl_DatabaseUser.Text = "Database Username";
            // 
            // txt_DatabaseUser
            // 
            txt_DatabaseUser.Location = new Point(550, 74);
            txt_DatabaseUser.Name = "txt_DatabaseUser";
            txt_DatabaseUser.Size = new Size(167, 27);
            txt_DatabaseUser.TabIndex = 5;

            // 
            // lbl_DatabaseName
            // 
            lbl_DatabaseName.AutoSize = true;
            lbl_DatabaseName.Location = new Point(35, 126);
            lbl_DatabaseName.Name = "lbl_DatabaseName";
            lbl_DatabaseName.Size = new Size(116, 20);
            lbl_DatabaseName.TabIndex = 6;
            lbl_DatabaseName.Text = "Database Name";

            // 
            // lbl_DatabasePass
            // 
            lbl_DatabasePass.AutoSize = true;
            lbl_DatabasePass.Location = new Point(402, 126);
            lbl_DatabasePass.Name = "lbl_DatabasePass";
            lbl_DatabasePass.Size = new Size(137, 20);
            lbl_DatabasePass.TabIndex = 7;
            lbl_DatabasePass.Text = "Database Password";
            // 
            // txt_DatabasePass
            // 
            txt_DatabasePass.Location = new Point(550, 123);
            txt_DatabasePass.Name = "txt_DatabasePass";
            txt_DatabasePass.Size = new Size(167, 27);
            txt_DatabasePass.TabIndex = 8;
            // 
            // txt_DatabaseName
            // 
            txt_DatabaseName.Location = new Point(183, 123);
            txt_DatabaseName.Name = "txt_DatabaseName";
            txt_DatabaseName.Size = new Size(176, 27);
            txt_DatabaseName.TabIndex = 9;
            // 
            // txt_QueryDatabase
            // 
            txt_QueryDatabase.Location = new Point(216, 180);
            txt_QueryDatabase.Name = "txt_QueryDatabase";
            txt_QueryDatabase.Size = new Size(501, 27);
            txt_QueryDatabase.TabIndex = 10;
            // 
            // MySQLParser
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(txt_QueryDatabase);
            Controls.Add(txt_DatabaseName);
            Controls.Add(txt_DatabasePass);
            Controls.Add(lbl_DatabasePass);
            Controls.Add(lbl_DatabaseName);
            Controls.Add(txt_DatabaseUser);
            Controls.Add(lbl_DatabaseUser);
            Controls.Add(grid_DataView);
            Controls.Add(btn_QueryDatabase);
            Controls.Add(lbl_DatabaseIP);
            Controls.Add(txt_DatabaseIP);
            Name = "MySQLParser";
            Text = "MySQLParser";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)grid_DataView).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox txt_DatabaseIP;
        private Label lbl_DatabaseIP;
        private Button btn_QueryDatabase;
        private DataGridView grid_DataView;
        private Label lbl_DatabaseUser;
        private TextBox txt_DatabaseUser;
        private Label lbl_DatabaseName;
        private Label lbl_DatabasePass;
        private TextBox txt_DatabasePass;
        private TextBox txt_DatabaseName;
        private TextBox txt_QueryDatabase;
    }
}