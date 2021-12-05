using System;
using System.Collections.Generic;
using System.Text;

namespace Day5
{
    class VentMap
    {
        List<List<string>> map = new List<List<string>>();

        public VentMap()
        {
            
        }

        public void DrawLine(Line line)
        {
            // Vertical
            if (line.start.x == line.end.x)
            {
                Console.WriteLine("Draw V:" + line);
                int start = line.start.y;
                int end = line.end.y;
                if (line.start.y > line.end.y)
                {
                    end = line.start.y;
                    start = line.end.y;
                }

                for (int i = start; i <= end; i++)
                    DrawPoint(new Point(line.start.x, i));
            }

            // Horizontal
            else if (line.start.y == line.end.y)
            {
                Console.WriteLine("Draw H:" + line);
                int start = line.start.x;
                int end = line.end.x;
                if (line.start.x > line.end.x)
                {
                    end = line.start.x;
                    start = line.end.x;
                }

                for (int i = start; i <= end; i++)
                    DrawPoint(new Point(i,line.start.y));               
            }
            // 45°
            else
            {
                //Console.WriteLine("Skip for Part1:" + line);
                Console.WriteLine("Draw 45:" + line);
                Point low = line.start;
                Point high = line.end;
                if (line.start.y < line.end.y)
                {
                    low = line.end;
                    high = line.start;
                }
                
                if(low.x > high.x)
                {
                    int abs = low.x - high.x;
                    for (int i = 0; i <= abs; i++)
                        DrawPoint(new Point(low.x - i, low.y - i));
                }
                else
                {
                    int abs = high.x - low.x;
                    for (int i = 0; i <= abs; i++)
                        DrawPoint(new Point(low.x + i, low.y - i));
                }
            }

        }

        private void DrawPoint(Point p)
        {
            // increase map if necessary
            for (int i = map.Count; i <= p.y + 1; i++)
                map.Add(new List<string>());

            for (int y=0; y < map.Count; y++)
            {
                for (int x = map[y].Count; x <= p.x + 1; x++)
                    map[y].Add(".");
            }

            try
            { 
                if (map[p.y][p.x] == ".")
                    map[p.y][p.x] = "1";
                else
                    map[p.y][p.x] = Convert.ToString(int.Parse(map[p.y][p.x]) + 1);
            }
            catch (Exception)
            {
                Console.WriteLine(map.Count);
                Console.WriteLine(map[p.y].Count);
                throw;
            }


        }

        public void DrawMap()
        {
            foreach (var item in map)
            {
                foreach (var p in item)
                {
                    Console.Write(p);
                }
                Console.WriteLine();
            }
        }

        public int GetCrosses()
        {
            int count = 0;
            foreach (var item in map)
            {
                foreach (var p in item)
                {
                    if (p == ".")
                      continue;
                    if (int.Parse(p) > 1)
                        count++;
                }
            }

            return count;
        }
    }
}
