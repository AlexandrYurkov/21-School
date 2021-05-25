using System;
using System.Globalization;

namespace d00
{
    class Program
    {
        static int Data(int term)
        {
            int[] Days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            int day = 0;
            int m = 5;
            for (int i = 0; i < term; i++, ++m)
            {
                if (m > 11)
                    m = 0;
                day += Days[m];
            }
            return (day);
        }
        static double Result(double sum, double rate, int term, int selectedMonth, double payment)
        {
            double i = rate / 12 / 100; // ежемесечная процентная ставка
            double AnPlat = Math.Round(sum * i * Math.Pow((1 + i), term) / (Math.Pow((i + 1), term) - 1), 2); // планируемый платеж в месяц
            double ObDolg = Math.Round((AnPlat * term), 2); // Общий долг с учетом процентов
            double NumOfMon = Math.Log(AnPlat / ((AnPlat) - (i * ObDolg)), i + 1);// Перерасчет месецем при погашении общей суммы долга
            int Dt = 31;// количество дней в месяце
            double percent = Math.Round((sum * rate/100 *Dt / 365), 2);//формула процентов для ежемесячного платежа
            double t = AnPlat / percent;
           
           //Console.WriteLine(t);
            return (percent);
        }
        static void Main(string[] args)
        {
            double Res = 0;
            if (args.Length == 3)
            {
                double sum = double.Parse(args[0]);
                double rate = double.Parse(args[1]);
                int term = Int32.Parse(args[2]);
                int selectedMonth = 1;
                double payment = 1;
                Res = Result(sum, rate, term, selectedMonth, payment);
            }
            else if (args.Length != 5)
            {
                Console.WriteLine("Error: введите правильные данные!");
            }
            else
            {
                double sum = double.Parse(args[0]);
                double rate = double.Parse(args[1]);
                int term = Int32.Parse(args[2]);
                int selectedMonth = Int32.Parse(args[3]);
                double payment = double.Parse(args[4]);
                Res = Result(sum, rate, term, selectedMonth, payment);
            }
            Console.WriteLine("Результа экономии " + Res);
            //      DateTime dt = new DateTime(2021,5,15);

            /*       for (int i = 0; i < 13; i++)
               {
                   DateTime dtnew = dt.AddDays(i);
                   Console.WriteLine(dtnew);

               }*/
        }
    }
}
