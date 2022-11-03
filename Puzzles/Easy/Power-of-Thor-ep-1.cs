// Solution to the puzzle Power of Thor - Episode 1
// https://www.codingame.com/training/easy/power-of-thor-episode-1

using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Player
{
    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        int lightX = int.Parse(inputs[0]); // the X position of the light of power
        int lightY = int.Parse(inputs[1]); // the Y position of the light of power
        int initialTx = int.Parse(inputs[2]); // Thor's starting X position
        int initialTy = int.Parse(inputs[3]); // Thor's starting Y position

        int ThorX = initialTx, ThorY = initialTy;

        // game loop
        while (true)
        {
            int remainingTurns = int.Parse(Console.ReadLine()); // The remaining amount of turns Thor can move. Do not remove this line.

            if(ThorX < lightX && ThorY < lightY){
                Console.WriteLine("SE");
                ThorX++;
                ThorY++;
            }
            else if(ThorX > lightX && ThorY < lightY){
                Console.WriteLine("SW");
                ThorX--;
                ThorY++;
            }
            else if(ThorX < lightX && ThorY > lightY){
                Console.WriteLine("NE");
                ThorX++;
                ThorY--;
            }
            else if(ThorX > lightX && ThorY > lightY){
                Console.WriteLine("NW");
                ThorX--;
                ThorY--;
            }
            else if(ThorX == lightX && ThorY > lightY){
                Console.WriteLine("N");
                ThorY--;
            }
            else if(ThorX == lightX && ThorY < lightY){
                Console.WriteLine("S");
                ThorY++;
            }
            else if(ThorX > lightX && ThorY == lightY){
                Console.WriteLine("W");
                ThorX++;
            }
            else {
                Console.WriteLine("E");
                ThorX--;
            }
        }
    }
}

