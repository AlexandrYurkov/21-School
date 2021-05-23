using System;

namespace d00
{
    class Program
    {
        static double Result(double sum, double rate, int term, int selectedMonth, double payment)
        {
            return (1);
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
            Console.WriteLine("Результа экономии " + Res);
        }
    }
}
