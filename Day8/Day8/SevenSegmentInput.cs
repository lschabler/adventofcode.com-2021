using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Day8
{
    class SevenSegmentInput
    {
        string[] seven_segment_;
        string[] output_value_;
        int[] output_solved_;

        public SevenSegmentInput(string input)
        {
            var parts = input.Split('|');
            seven_segment_ = parts[0].Split(' ').Where(x => !string.IsNullOrEmpty(x)).ToArray();
            output_value_ = parts[1].Split(' ').Where(x => !string.IsNullOrEmpty(x)).ToArray();
            output_solved_ = new int[output_value_.Length];
        }

        // Part 1, digits 1, 4, 7, and 8
        public int[] GetBasicValues()
        {
            var ret = new List<int>();

            int index = 0;
            foreach (var item in output_value_)
            {
                output_solved_[index] = -1;

                if (item.Length == 2)
                {
                    ret.Add(1);
                    output_solved_[index] = 1;
                }  
                else if (item.Length == 4)
                {
                    ret.Add(4);
                    output_solved_[index] = 4;
                } 
                else if (item.Length == 3)
                {
                    ret.Add(7);
                    output_solved_[index] = 7;
                } 
                else if (item.Length == 7)
                {
                    ret.Add(8);
                    output_solved_[index] = 8;
                }
                index++;
            }

            return ret.ToArray();
        }

        public int[] GetDecodedValues()
        {
            int[] seven_solved = new int[seven_segment_.Length];
            SortedDictionary<int, string> canditates = new SortedDictionary<int, string>();
            // parse 1, 4, 7, and 8
            for (int i = 0; i < seven_segment_.Length; i++)
            {
                seven_solved[i] = -1;
                if (seven_segment_[i].Length == 2)
                {
                    seven_solved[i] = 1;
                    canditates[1] = seven_segment_[i];
                }              
                if (seven_segment_[i].Length == 4)
                {
                    seven_solved[i] = 4;
                    canditates[4] = seven_segment_[i];
                }
                if (seven_segment_[i].Length == 3)
                {
                    seven_solved[i] = 7;
                    canditates[7] = seven_segment_[i];
                }
                if (seven_segment_[i].Length == 7)
                {
                    seven_solved[i] = 8;
                    canditates[8] = seven_segment_[i];

                }

            }
            
            // find 3 or 6
            for (int i = 0; i < seven_segment_.Length; i++)
            {
                if (seven_solved[i] >= 0) continue;
                var cand = canditates[1];
                var seven = seven_segment_[i];
                int index1 = seven.IndexOf(cand[0]);
                int index2 = seven.IndexOf(cand[1]);
                // find 2
                if (seven.Length == 5 && index1 > -1 && index2 > -1)
                {
                    seven_solved[i] = 3;
                    canditates[3] = seven;
                }
                if (seven.Length == 6 && (index1 == -1 || index2 == -1))
                {
                    seven_solved[i] = 6;
                    canditates[6] = seven;
                }

                //int index1 = str.IndexOf('F');
            }

            
            // 0 9 -> 6
            for (int i = 0; i < seven_segment_.Length; i++)
            {
                if (seven_solved[i] >= 0) continue;
                var seven = seven_segment_[i];
                if (seven.Length != 6) continue;
                var cand = canditates[3];
                int count = 0;
                foreach (var item in cand)
                {
                    if (seven.IndexOf(item)>=0)
                        count++;
                }
                if(count == cand.Length)
                {
                    seven_solved[i] = 9;
                    canditates[9] = seven;
                }
                else
                {
                    seven_solved[i] = 0;
                    canditates[0] = seven;
                }
            }

            // 2 5 -> 5
            for (int i = 0; i < seven_segment_.Length; i++)
            {
                if (seven_solved[i] >= 0) continue;
                var seven = seven_segment_[i];
                if (seven.Length != 5) continue;
                var cand = canditates[9];
                int count = 0;
                foreach (var item in cand)
                {
                    if (seven.IndexOf(item) >= 0)
                        count++;
                }
                if (count == cand.Length-1) // 5
                {
                    seven_solved[i] = 5;
                    canditates[5] = seven;
                }
                else
                {
                    seven_solved[i] = 2;
                    canditates[2] = seven;
                }

            }

            string[] output_sorted = new string[output_value_.Length];
            for (int i = 0; i < output_value_.Length; i++)
            {
                string out_val = output_value_[i];
                var sorted = string.Concat(out_val.OrderBy(x => x));
                output_sorted[i] = sorted;
            }

            for (int i = 0; i < canditates.Keys.Count; i++)
            {
                var item = canditates.Keys.ElementAt(i);
                string code = canditates[item];
                var sorted = string.Concat(code.OrderBy(x=>x));
                canditates[item] = sorted;

                for (int j = 0; j < output_sorted.Length; j++)
                {
                    if (output_sorted[j] == sorted)
                    {
                        output_solved_[j] = i;
                        //Console.WriteLine("Found: " + i + " " + sorted);
                    }
                        
                }
            }

            return output_solved_;
        }
    }
}
