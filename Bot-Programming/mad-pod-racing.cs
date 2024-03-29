// Solution for the Mad Pod Racing challange
// https://www.codingame.com/multiplayer/bot-programming/mad-pod-racing

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
        string[] inputs;

        // game loop
        while (true)
        {
            inputs = Console.ReadLine().Split(' ');
            int x = int.Parse(inputs[0]);
            int y = int.Parse(inputs[1]);
            int nextCheckpointX = int.Parse(inputs[2]); // x position of the next check point
            int nextCheckpointY = int.Parse(inputs[3]); // y position of the next check point
            int nextCheckpointDist = int.Parse(inputs[4]); // distance to the next checkpoint
            int nextCheckpointAngle = int.Parse(inputs[5]); // angle between your pod orientation and the direction of the next checkpoint
            inputs = Console.ReadLine().Split(' ');
            int opponentX = int.Parse(inputs[0]);
            int opponentY = int.Parse(inputs[1]);
            bool boost = true;
            string thrust;
            if(nextCheckpointAngle < -90 || nextCheckpointAngle > 90 || nextCheckpointDist < 500){
                thrust = "25";
            }
            else {
                thrust = "100";
            }
            if(boost){
                if(nextCheckpointDist > 5000 && (nextCheckpointAngle > -45 && nextCheckpointAngle < 45)){
                    thrust = "BOOST";
                    boost = false;
                }
            }
            Console.WriteLine(nextCheckpointX + " " + nextCheckpointY + " " + thrust);
        }
    }
}