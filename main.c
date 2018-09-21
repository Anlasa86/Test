/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: equipo19
 *
 * Created on 10 de agosto de 2018, 01:04 PM
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_POINTS 5
#define NUM_COMMANDS 2


/*
 * 
 */


int main(int argc, char** argv) {
    char * commandsForGnuplot[] = {"set title \"TITLEEEEE\"", "plot 'data.temp'"};
    double xvals[NUM_POINTS] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double yvals[NUM_POINTS] = {5.0 ,3.0, 1.0, 3.0, 5.0};
    FILE * temp = fopen("data.temp", "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     */
    float d = 16.5;
    printf("hola: %f", floor(d));
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    int i;
    for (i=0; i < NUM_POINTS; i++)
    {
    fprintf(temp, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
    fflush(gnuplotPipe);
    }

    for (i=0; i < NUM_COMMANDS; i++)
    {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    fflush(gnuplotPipe);
    }

    printf("Hola dos");
//    fclose(gnuplotPipe);
//    fflush(gnuplotPipe);
    return (EXIT_SUCCESS);
}


    


