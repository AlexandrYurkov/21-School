using System;
using System.Globalization;

namespace d00
{
    class Program
    {
     /*   static double Result(double sum, double rate, int term, int selectedMonth, double payment)
        {
            double i = rate / 12 / 100;
            double AnPlat= sum * i * Math.Pow((1 + i), term)/(Math.Pow((i + 1), term) -1);
            double ObDolg = Math.Round((AnPlat * term), 2);
            double NumOfMon = Math.Log((payment / (payment - i * AnPlat)), i +1);
            return (NumOfMon);
        }*/
        static void Main(string[] args)
        {
          /*double Res = 0;
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
                System.Console.WriteLine("Error: введите правильные данные!");
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
            Console.WriteLine("Результа экономии " + Res);*/
                     DateTime dt = new DateTime(2021,5,15);

            for (int i = 0; i < 13; i++)
        {
            DateTime dtnew = dt.AddDays(i);
            Console.WriteLine(dtnew);

        }
        }
    }
}
