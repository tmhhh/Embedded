using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Threading;

namespace Temp_Humid
{
    public partial class Form1 : Form
    {
        private string strData;
        public Form1()
        {
            InitializeComponent();
            DispatcherTimer timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromSeconds(10);
            timer.Tick += timer_Tick;
            timer.Start();
        }
        void timer_Tick(object sender, EventArgs e)
        {
            try
            {
                String Str = "https://api.thingspeak.com/channels/";
                String End = "/feeds.json?results=1";
                String Mid = "1238163";  //Channel ID Go's Here - Must be set to public

                String All1 = String.Join(Mid, Str, End);


                WebRequest request = WebRequest.Create(All1);
                HttpWebResponse responce = (HttpWebResponse)request.GetResponse();
                Stream datastream = responce.GetResponseStream();
                StreamReader reader = new StreamReader(datastream);
                strData = reader.ReadToEnd();
            }
            catch (Exception)
            {


            }

            //MessageBox.Show(strData);

            try
            {
             

                int start = strData.LastIndexOf("field1");
                btnTemp.Text= strData.Substring(start+9,5);

            }
            catch (Exception)
            {
            }

            try
            {
                int start2 = strData.LastIndexOf("field2");
                btnHumid.Text = strData.Substring(start2 + 9,5);

            }
            catch (Exception)
            {

            }

            //try
            //{
            //    int start3 = strData.LastIndexOf("field3");
            //    Segments3 = strData.Substring(start3 + 9, 2);

            //}
            //catch (Exception)
            //{


            //}

            //try
            //{
            //    int start4 = strData.LastIndexOf("field4");
            //    Segments4 = strData.Substring(start4 + 9, 2);

            //}
            //catch (Exception)
            //{


            //}

            //try
            //{
            //    int start5 = strData.LastIndexOf("field5");
            //    Segments5 = strData.Substring(start5 + 9, 2);

            //}
            //catch (Exception)
            //{


            //}

            //try
            //{
            //    int start6 = strData.LastIndexOf("field6");
            //    Segments6 = strData.Substring(start6 + 9, 2);

            //}
            //catch (Exception)
            //{


            //}

            //try
            //{
            //    int start7 = strData.LastIndexOf("field7");
            //    Segments7 = strData.Substring(start7 + 9, 2);

            //}
            //catch (Exception)
            //{


            //}

            //try
            //{
            //    int start8 = strData.LastIndexOf("field8");
            //    Segments8 = strData.Substring(start8 + 9, 8);
            //}
            //catch (Exception)
            //{


            //}

            //try
            //{
            //    var convertDouble = Convert.ToDouble(Segments);
            //    Field1.Value = convertDouble;


            //}
            //catch (Exception)
            //{

            //}

            //try
            //{
            //    var convertDouble2 = Convert.ToDouble(Segments2);
            //    Field2.Value = convertDouble2;

            //}
            //catch (Exception)
            //{

            //}

            //try
            //{
            //    var convertDouble3 = Convert.ToDouble(Segments3);
            //    Field3.Value = convertDouble3;

            //}
            //catch (Exception)
            //{
            //}

            //try
            //{
            //    var convertDouble4 = Convert.ToDouble(Segments4);
            //    Field4.Value = convertDouble4;

            //}
            //catch (Exception)
            //{

            //    throw;
            //}

            //try
            //{
            //    var convertDouble5 = Convert.ToDouble(Segments5);
            //    Field5.Value = convertDouble5;

            //}
            //catch (Exception)
            //{
            //}

            //try
            //{
            //    var convertDouble6 = Convert.ToDouble(Segments6);
            //    Field6.Value = convertDouble6;

            //}
            //catch (Exception)
            //{
            //}

            //try
            //{
            //    var convertDouble7 = Convert.ToDouble(Segments7);
            //    Field7.Value = convertDouble7;

            //}
            //catch (Exception)
            //{
            //}

            //try
            //{
            //    var convertDouble8 = Convert.ToDouble(Segments8);
            //    Field8.Value = convertDouble8;
            //}
            //catch (Exception)
            //{
            //}

        }
    }
}
    