using System;
using System.Collections.Generic;
using System.Linq;

namespace Day8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Day 8!");

            string[] lines = System.IO.File.ReadAllLines(@"input.txt");
            
            var elements = new List<SevenSegmentInput>();
            foreach (var item in lines)
                elements.Add(new SevenSegmentInput(item));

            // part 1
            int num_sum = 0;
            foreach (var item in elements)
            {
                num_sum += item.GetBasicValues().Length;
                //Console.WriteLine(string.Join(",", item.GetBasicValues()));
            }
            Console.WriteLine("Part1: " + num_sum);

            
            int num_sum_2 = 0;
            // part 2
            foreach (var item in elements)
            {
                var decoded = item.GetDecodedValues();
                //num_sum += item.GetDecodedValues().Length;
                int res = 0;
                int dec = 1;
                for (int i = decoded.Length-1; i >= 0; i--)
                {
                    res += dec * decoded[i];
                    dec *= 10;
                }
                Console.WriteLine(res);
                num_sum_2 += res;

                //Console.WriteLine(string.Join(item.GetDecodedValues()));
            }
            Console.WriteLine("Part2: " + num_sum_2);

        }
    }
}
