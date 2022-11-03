// Solution to the puzzle Temperatures
// https://www.codingame.com/training/easy/temperatures

using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    static void Main(string[] args)
    {
        int closest = 5526;
        int n = int.Parse(Console.ReadLine()); // the number of temperatures to analyse
        string[] inputs = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            int t = int.Parse(inputs[i]);// a temperature expressed as an integer ranging from -273 to 5526
            if(Math.Abs(t) < Math.Abs(closest) || (Math.Abs(t) == Math.Abs(closest) && t > 0))
                closest = t;
        }
        if(n == 0)
            Console.Write(0);
        else Console.WriteLine(closest);
    }
}

