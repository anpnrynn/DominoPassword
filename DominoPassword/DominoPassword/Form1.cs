using System;
using System.Diagnostics;
using System.Text;

namespace DominoPassword
{
    public partial class Form1 : Form
    {


        //Die Rahul Gandhi, you stealing french bastard!!!

        private string initdata = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz!$'*+,-./:;<=>?^_`~$'*+,-./:;<=>?^_`";

        private string shuffledData = "";
        private int[] toggleStatus = new int[128];

        private string rotate(string srotate, int n)
        {
            string s1 = srotate.Substring(0, n);
            string s2 = srotate.Substring(n, srotate.Length - n);
            return s2 + s1;
        }

        private string swapchars(string s, int m, int n)
        {
            StringBuilder sb = new StringBuilder(s);
            char c = s[m];
            sb[m] = s[n];
            sb[n] = c;
            return sb.ToString();
        }

        private string shuffle(string s, int pin)
        {
            string stemp = s;
            int n = stemp.Length;
            int k = 1;
            for (int j = 0; j < pin; j++)
            {
                string s1 = stemp.Substring(0, n / 2);
                string s2 = stemp.Substring(n / 2, n / 2);

                for (int i = 0; i < n / 4; i++)
                {
                    if (k % 2 == 0)
                    {
                        s1 = swapchars(s1, i, n / 2 - i - 1);
                        s2 = swapchars(s2, i, n / 2 - i - 1);
                    }
                    else
                    {
                        s1 = swapchars(s1, i, n / 2 - i - 2);
                        s2 = swapchars(s2, i, n / 2 - i - 2);
                    }

                    k++;
                }
                s1 = rotate(s1, 13);
                s2 = rotate(s2, 17);
                stemp = s1 + s2;

                if (s == stemp)
                {
                    //console.log("strings match: " + stemp);
                }
                stemp = rotate(stemp, 23);
            }



            if (stemp.Length != s.Length)
            {

                Debug.WriteLine("INFO: lengths don't match ");
                Debug.WriteLine(stemp);
                Debug.WriteLine(s);
            }
            else
            {
                Debug.WriteLine("INFO: lengths match ");
                Debug.WriteLine(stemp);
            }

            string extendstring = stemp;
            //Debug.WriteLine("INFO: Origstring = "+ s);
            //Debug.WriteLine("INFO: Cryptostring = "+ extendstring);
            shuffledData = extendstring;
            //setShuffledData(shuffledData);
            return extendstring;
        }

        public Form1()
        {
            InitializeComponent();
            int i = 0;
            while (i < 128)
            {
                toggleStatus[i] = 0;
                i++;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        int pattern = 1;

        private void button38_Click(object sender, EventArgs e)
        {
            pattern--;
            if (pattern < 1) pattern = 1;
            label2.Text = "Pattern: " + pattern.ToString() + "/3";
            resetColor();
        }

        private void button39_Click(object sender, EventArgs e)
        {
            pattern++;
            if (pattern > 3) pattern = 3;
            label2.Text = "Pattern: " + pattern.ToString() + "/3";
            resetColor();
        }

        private void button37_Click(object sender, EventArgs e)
        {
            try {
                int.Parse(textBox1.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Please enter a valid number for the pin.");
                return;
            }
            catch (OverflowException)
            {
                MessageBox.Show("The number is too large. Please enter a smaller number.");
                return;
            }   
            shuffledData = shuffle(initdata, int.Parse(textBox1.Text) );
        }


        private void resetColor()
        {
            int i = 1;
            int n = i + 36;
            while( i < n )
            {
                Button button = tableLayoutPanel1.Controls["button" + i] as Button;
                Debug.WriteLine("Button: " + button.Name + " : " + i);
                if (button != null)
                {
                    int ti = (pattern - 1) * 36 + i - 1;
                    Debug.WriteLine("Button: " + button.Name + " : " + toggleStatus[ti]);
                    if (toggleStatus[ti] == 1)
                    {
                        switch (pattern)
                        {
                            case 1:
                                button.BackColor = Color.Red;
                                break;
                            case 2:
                                button.BackColor = Color.Green;
                                break;
                            case 3:
                                button.BackColor = Color.Blue;
                                break;
                            default:
                                button.BackColor = SystemColors.ButtonFace;// Reset to default color
                                break;
                        }
                    }
                    else
                        button.BackColor = SystemColors.ButtonFace; // Reset to default color
                }
                else
                {
                    MessageBox.Show("Invalid button index: " + i + " : " + button.Name);
                }
                i++;
            }
        }

        private void changeColor(object sender)
        {
            Button button = sender as Button;
            Debug.WriteLine("Button: " + button.Name + " : " + pattern);
            switch (pattern)
            {
                case 1:
                    ((Button)sender).BackColor = Color.Red;
                    break;
                case 2:
                    ((Button)sender).BackColor = Color.Green;
                    break;
                case 3:
                    ((Button)sender).BackColor = Color.Blue;
                    break;
                default:
                    ((Button)sender).BackColor = SystemColors.ButtonFace;
                    break;
            }
        }

        private void clearColor()
        {
            int i = 1;
            int n = i + 36;
            while (i < n)
            {
                Button button = tableLayoutPanel1.Controls[i - 1] as Button;
                Debug.WriteLine("Button: " + button.Name + " : " + i);
                button.BackColor = SystemColors.ButtonFace; // Reset to default color
                i++;
            }
        }

        private void patternButton_Click(object sender, int buttonId, int pattern)
        {
            if (shuffledData == "")
                return;
            string value = ((Button)sender).Name.Substring(6); // Extract the number from the button name
            int index = (pattern-1)*36 + int.Parse(value)-1; // Convert to zero-based index
            if (index >= 0 && index <= 108)
            {
                textBox2.Text += shuffledData[index];
                //int n =  (index % 36 )+ 1;
                toggleStatus[index] = 1; // Toggle the status
            }
            else
            {
                MessageBox.Show("Invalid button index: " + index);
                return;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 1, pattern);
            changeColor(sender);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 2, pattern);
            changeColor(sender);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 3, pattern);
            changeColor(sender);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 4, pattern);
            changeColor(sender);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 5, pattern);
            changeColor(sender);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 6, pattern);
            changeColor(sender);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 7, pattern);
            changeColor(sender);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 8, pattern);
            changeColor(sender);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 9, pattern);
            changeColor(sender);
        }

        private void button10_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 10, pattern);
            changeColor(sender);
        }

        private void button11_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 11, pattern);
            changeColor(sender);
        }

        private void button12_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 12, pattern);
            changeColor(sender);
        }

        private void button13_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 13, pattern);
            changeColor(sender);
        }

        private void button14_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 14, pattern);
            changeColor(sender);
        }

        private void button15_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 15, pattern);
            changeColor(sender);
        }

        private void button16_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 16, pattern);
            changeColor(sender);
        }

        private void button17_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 17, pattern);
            changeColor(sender);    
        }

        private void button18_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 18, pattern);
            changeColor(sender);
        }

        private void button19_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 19, pattern);
            changeColor(sender);
        }

        private void button20_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 20, pattern);
            changeColor(sender);
        }

        private void button21_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 21, pattern);
            changeColor(sender);
        }

        private void button22_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 22, pattern);
            changeColor(sender);
        }

        private void button23_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 23, pattern);
            changeColor(sender);
        }

        private void button24_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 24, pattern);
            changeColor(sender);
        }

        private void button25_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 25, pattern);
            changeColor(sender);
        }

        private void button26_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 26, pattern);
            changeColor(sender);
        }

        private void button27_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 27, pattern);
            changeColor(sender);
        }

        private void button28_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 28, pattern);
            changeColor(sender);
        }

        private void button29_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 29, pattern);
            changeColor(sender);

        }

        private void button30_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 30, pattern);
            changeColor(sender);
        }

        private void button31_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 31, pattern);
            changeColor(sender);
        }

        private void button32_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 32, pattern);
            changeColor(sender);
        }

        private void button33_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 33, pattern);
            changeColor(sender);
        }

        private void button34_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 34, pattern);
            changeColor(sender);
        }

        private void button35_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 35, pattern);
            changeColor(sender);
        }

        private void button36_Click(object sender, EventArgs e)
        {
            patternButton_Click(sender, 36, pattern);
            changeColor(sender);
        }

        private void button40_Click(object sender, EventArgs e)
        {
            int i = 0;
            while( i < 128){
                toggleStatus[i] = 0;
                i++;
            }
            shuffledData = "";
            clearColor();
            textBox1.Text = "";
            textBox2.Text = ""; 
        }
    }
}
