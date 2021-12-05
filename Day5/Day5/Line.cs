using System;
using System.Collections.Generic;
using System.Text;

namespace Day5
{
    struct Point
    {
        public int x;
        public int y;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return "(" + this.x.ToString() + "," + this.y.ToString() + ")";
        }
    }

    class Line
    {
        public Point start { get; }
        public Point end { get; }

        public Line(int x1, int y1, int x2, int y2)
        {
            this.start = new Point(x1, y1);
            this.end = new Point(x1, y1);
        }

        public Line(string line)
        {
            string[] tmp = line.Split(' ');
            if (tmp.Length != 3)
                throw new Exception("Invalid Input");

            string[] p1 = tmp[0].Split(',');
            string[] p2 = tmp[2].Split(',');

            this.start = new Point(Int32.Parse(p1[0]), Int32.Parse(p1[1]));
            this.end = new Point(Int32.Parse(p2[0]), Int32.Parse(p2[1]));
        }

        public override string ToString()
        {
            return this.start + " -> " + this.end;
        }
    }
}
