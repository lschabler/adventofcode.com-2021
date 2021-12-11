using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

namespace Day10
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Day10!");
            //string file_name = "input_small.txt";
            string file_name = "input.txt";

            var lines = File.ReadAllLines(file_name);

            var lines_remove_basic = lines;
            for (var i = 0; i < lines_remove_basic.Length; i += 1)
            {
                var line = lines_remove_basic[i];
                while (line.Length > 0)
                {
                    Match match = Regex.Match(line, @"\[\]|\<\>|\{\}|\(\)",
                        RegexOptions.IgnoreCase);
                    if (!match.Success) break;

                    line = line.Replace("[]", "");
                    line = line.Replace("()", "");
                    line = line.Replace("{}", "");
                    line = line.Replace("<>", "");
                }
                char last = line[line.Length - 1];

                //Console.WriteLine(line + "last=" + last);
                lines_remove_basic[i] = line;
            }

            int part1_result = 0;

            // part1 find wrong closing
            for (var i = 0; i < lines_remove_basic.Length; i += 1)
            {
                var line = lines_remove_basic[i];
                
                Match match = Regex.Match(line, @"\]|\>|\}|\)",
                     RegexOptions.IgnoreCase);
                if (!match.Success) continue;

                /*
                    ): 3 points.
                    ]: 57 points.
                    }: 1197 points.
                    >: 25137 points
                */ 
                switch (match.Value)
                {
                    case ")":
                        part1_result += 3;
                        break;
                    case "]":
                        part1_result += 57;
                        break;
                    case "}":
                        part1_result += 1197;
                        break;
                    case ">":
                        part1_result += 25137;
                        break;
                    default:
                        break;
                }

                //Console.WriteLine(line + ", " + match.Value);
            }
            Console.WriteLine("Part1 Result:" + part1_result);

            List<long> total_scores = new List<long>();

            // part2 find wrong closing
            for (var i = 0; i < lines_remove_basic.Length; i += 1)
            {
                var line = lines_remove_basic[i];

                Match match = Regex.Match(line, @"\]|\>|\}|\)",
                     RegexOptions.IgnoreCase);
                if (match.Success) continue;

                Console.WriteLine(line);
                long total_score = 0;
                for (int char_pos = line.Length-1; char_pos >=0 ; char_pos--)
                {
                    total_score *= 5;
                    switch (line[char_pos].ToString())
                    {
                        case "(":
                            total_score += 1;
                            break;
                        case "[":
                            total_score += 2;
                            break;
                        case "{":
                            total_score += 3;
                            break;
                        case "<":
                            total_score += 4;
                            break;
                        default:
                            break;
                    }
                }
                total_scores.Add(total_score);
            }
            total_scores.Sort();
            Console.WriteLine(total_scores[total_scores.Count / 2]);



        }
    }
}
