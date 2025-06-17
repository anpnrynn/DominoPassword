using System;
using System.Diagnostics;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Windows.Forms;
using static System.Runtime.InteropServices.JavaScript.JSType;
using static System.Windows.Forms.AxHost;

namespace DominoPassword
{
    public partial class Form1 : Form
    {


        //Die Rahul Gandhi, you stealing french bastard!!!

        private string initdata     = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz!$'*+,-./:;<=>?^_`~$'*+,-./:;<=>?^_`";
        private string initdata_1_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz!$'*+,-./:;<=>?^_`~$'*+,-./:;<=>?^_`";
        private string initdata_2_0 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`~!@#$%^&*()_+-={}|[]\\\\:\\\";'<>?,./^&*()_+-={}|[]\";";
        private string initdata_2_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`~!@#$%^&*()_+-={}|[]\\\\:\\\";'<>?,./^&*()_+-={}|[]\";"; // 108 characters

        private string shuffledData = "";
        private int[] toggleStatus = new int[128];

        private string rotate(string srotate, int n)
        {
            string s1 = srotate.Substring(0, n);
            string s2 = srotate.Substring(n, srotate.Length - n);
            return s2 + s1;
        }


        private void copyto(ref char[] array, char[] copyfrom, int offset, int n)
        {
            int i = 0;
            while( i < copyfrom.Length)
            {
                array[offset+i] = copyfrom[i];
                i++;
            }
        }
        private char[] rotate_array(ref char[] srotate, int n)
        {
            char[] s1 = srotate.Take(n).ToArray();
            char[] s2 = srotate.Skip(n).ToArray();
            copyto(ref srotate, s2, 0, s2.Length);
            copyto(ref srotate, s1, s2.Length, s1.Length );
            return srotate;
        }

        private char[] trirotate_array(ref char[] srotate, int m, int n)
        {
            char[] s1 = srotate.Take(m).ToArray();
            char[] s2 = srotate.Skip(m).ToArray().Take(n).ToArray();
            char[] s3 = srotate.Skip(m + n).ToArray();

            copyto(ref srotate, s2, 0, s2.Length);
            copyto(ref srotate, s3, s2.Length, s3.Length);
            copyto(ref srotate, s1, s2.Length+s3.Length, s1.Length);
            return srotate;
        }

        string gen2_1_3wayrotate(string srotate, int count, int n)
        {
            string s1 = srotate.Substring(0, count);
            string s2 = srotate.Substring(count, n);
            string s3 = srotate.Substring(count + n, srotate.Length - count - n);
            //string s2 = srotate.Substring(count, srotate.Length - count);
            //memcpy(tmpdata, data, count);
            //memcpy(data, &data[count], n - count);
            //memcpy(&data[n - count], tmpdata, count);
            return s2 + s3 + s1;
        }

        string gen2_1_rotate(string srotate, int count, int n)
        {
            string s1 = srotate.Substring(0, count);
            string s2 = srotate.Substring(count, n-count);
            //string s3 = srotate.Substring(count+n, srotate.Length-count-n);
            //string s2 = srotate.Substring(count, srotate.Length - count);
            //memcpy(tmpdata, data, count);
            //memcpy(data, &data[count], n - count);
            //memcpy(&data[n - count], tmpdata, count);
            return s2 + s1;
        }

        private string swapchars(string s, int m, int n, int o = 0)
        {
            StringBuilder sb = new StringBuilder(s);
            char c = s[m];
            sb[m] = s[n];
            sb[n] = c;
            return sb.ToString();
        }

        private char[] swapchars_array(char[] s, int m, int n, int o = 0)
        {
            //StringBuilder sb = new StringBuilder(s);
            char c = s[m];
            s[m] = s[n];
            s[n] = c;
            return s;
        }

        private char[] swapchars_array_skip(char[] s, int skip, int m, int n, int o = 0)
        {
            //StringBuilder sb = new StringBuilder(s);
            char c = s[skip+m];
            s[skip + m] = s[skip + n];
            s[skip + n] = c;
            return s;
        }

        static int[] rotatevalues = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0 };
        //static int[] rotatevalues = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0 };
        private int gen1_1_rotatevalue(int pin, int[] shiftkeys)
        {
            int i = 0;
            
            while (shiftkeys[i] != 0)
            {
                if (pin < shiftkeys[i])
                {
                    return 0;
                }
                else
                {

                    if (pin % shiftkeys[i] == 0)
                    {
                        return rotatevalues[i];
                    }
                }
                i++;
            }
            return 0;
        }


        int gen2_1_rotatevalue(int pin, int[] shiftkeys)
        {
            int i = 0;
            
            while (shiftkeys[i] != 0)
            {
                if (pin < shiftkeys[i])
                {
                    return 0;
                }
                else
                {
                    if (pin % shiftkeys[i] == 0)
                    {
                        return rotatevalues[i];
                    }
                }
                i++;
            }
            return 0;
        }

        private void shuffle(string s, int pin)
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
                stemp = rotate(stemp, 23);
            }
            shuffledData = stemp;
        }

        private int[] shiftkeys = { 3500, 301390, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


        void gen1_1_shuffle( string s, int pin ) {
            Debug.WriteLine("String length is : " + s.Length);
            int n = 108;
            int k = 1;
            int j = 0;
            char[] schar = s.ToCharArray();
            int [] random = { 23, 13, 17, 7, 11 };
            for ( ;  j<pin; j++ ) {
                char[] s1 = schar.Take(n / 2).ToArray();
                char[] s2 = schar.Skip(n / 2).ToArray();

                for (int i = 0; i<n/4; i++ ){
                    if(k % 2  == 0 ){
                        s1 = swapchars_array(s1, i, n/2-i-1, n/2 );
                        s1 = swapchars_array_skip(s1, random[3], i, n/2-i-1-random[2], n/2 );
                        s2 = swapchars_array(s2, i, n/2-i-1, n/2 );
                        s1 = swapchars_array_skip(s1, random[4], i, n/2-i-1-random[4], n/2 );
                    } else {
                        s1 = swapchars_array(s1, i, n/2-i-2, n/2 );
                        s1 = swapchars_array_skip(s1, random[3], i, n/2-i-2-random[3], n/2 );
                        s2 = swapchars_array(s2, i, n/2-i-2, n/2 );
                        s1 = swapchars_array_skip(s1, random[4], i, n/2-i-2-random[4], n/2 );
                    }

                    s1 = swapchars_array(s1, i, random[1] + i, n / 2);
                    s2 = swapchars_array(s2, i, random[2] + i, n / 2);
                    k++;
                }

                rotate_array(ref s1, random[1]);
                rotate_array(ref s2, random[2]);
                copyto(ref schar, s1, 0, s1.Length);
                copyto(ref schar, s2, s1.Length, s2.Length);
                trirotate_array(ref schar, random[0], n - random[0]);
                trirotate_array(ref schar, random[3], n - random[3]);
                trirotate_array(ref schar, random[3], random[4]);

                int nrotate = 0;
                if ((nrotate = gen1_1_rotatevalue(pin, shiftkeys)) != 0)
                {
                    trirotate_array( ref schar, nrotate, n-nrotate);
                }
            }
            //shuffledData = ;
            int p = 0;
            Debug.WriteLine("Shuffled data: ");
            while ( p < 108) { 
                Debug.Write(schar[p]);
                p++;
            }
            Debug.WriteLine("");
            shuffledData = new string(schar);
            Debug.WriteLine("Exit string length is: " + shuffledData.Length);
            return;
        }


        void gen2_shuffle( string s , int pin) {
            int n = 108;
            int k = 1;
            string stemp = s;
            int []random = { 23, 13, 17 };
            for (int j = 0; j<pin; j++ ) {
                string s1 = stemp.Substring(0, n / 2);
                string s2 = stemp.Substring(n / 2, n / 2);
                for (int i = 0; i<n/4; i++ ){
                    if(k % 2  == 0 ){
                        s1 = swapchars(s1, i, n/2-i-1, n/2 );
                        s2 = swapchars(s2, i, n/2-i-1, n/2 );
                    } else { 
                        s1 = swapchars(s1, i, n/2-i-2, n/2 );
                        s2 = swapchars(s2, i, n/2-i-2, n/2 );
                    }
                    k++;
                }  
                s1 = gen2_1_rotate(s1,   random[1], n / 2);
                s2 = gen2_1_rotate(s2,   random[2], n / 2);
                stemp = s1 + s2;
                stemp = gen2_1_rotate(stemp, random[0], n);  
            }
            shuffledData = stemp;
            return;
        }


        void gen2_1_shuffle( string s, int pin ) {
            gen1_1_shuffle(s, pin); //init string is different, but the algorithm is the same
            return;
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
            if( listBox1.SelectedIndex == 0 )
            {
                shuffle(initdata, int.Parse(textBox1.Text));
            }
            else if (listBox1.SelectedIndex == 1)
            {
                gen1_1_shuffle(initdata_1_1, int.Parse(textBox1.Text));
            }
            else if (listBox1.SelectedIndex == 2)
            {
                gen2_shuffle(initdata_2_0, int.Parse(textBox1.Text));
            }
            else if (listBox1.SelectedIndex == 3)
            {
                gen2_1_shuffle(initdata_2_1, int.Parse(textBox1.Text));
            }   
            
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
