using System;
using System.Collections.Generic;

namespace Day5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello Day5!");

            //string[] lines = System.IO.File.ReadAllLines(@"input_small.txt");
            string[] lines = System.IO.File.ReadAllLines(@"input.txt");

            List<Line> list_lines = new List<Line>();

            VentMap vmap = new VentMap();

            foreach (var item in lines)
            {
                list_lines.Add(new Line(item));
                vmap.DrawLine(new Line(item));
            }

            //vmap.DrawMap();

            Console.WriteLine("Count: " + vmap.GetCrosses().ToString());


        }
    }
}
