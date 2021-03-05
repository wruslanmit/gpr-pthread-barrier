//============================================================================
// Name        : main_gpr_thread_barrier.cpp
// Author      : wruslanmit@gmail.com
// Version     : 1.0 Fri 05 Mar 2021 09:50:05 AM +08
// 
// Description : Compiling C++ codes in GNAT Studio
/*
-- GNAT Studio Community 2020 (20200427) hosted on x86_64-pc-linux-gnu
-- GNAT 9.3.0 targetting x86_64-linux-gnu
-- SPARK Community 2020 (20200818) GNAT Studio (c) 2001-2020 AdaCore
-- AppIDE: /home/wruslan/opt/GNAT/2020/bin/gnatstudio
--
-- Env	: Linux HPEliteBook8470p-Ub2004-rt38 5.4.66-rt38 
-- #1 SMP PREEMPT_RT Sat Sep 26 16:51:59 +08 2020 x86_64 x86_64 x86_64 GNU/Linux
--
*/
//============================================================================
#include <stdio.h>
#include <time.h> 		// For high-res timer clock_gettime with (nanoseconds)
#include <sys/time.h>	// For local date-time with (microseconds)
#include <unistd.h>     // getcwd()
#include <limits.h>     // perror()

#include <iostream>
using namespace std;

// ========================================================
// include file folder names with prefix: mod_ 
// ========================================================
// WRY Date-Time stamp nanosecond display
#include "mod-dtstamp/dtstamp.hpp"

// WRY Uniform random number generators (integers, doubles)
#include "mod-random-int-dbl/random_int_dbl.hpp"


// ========================================================
int main(int argc, char* argv[]) {
// ========================================================
  WRY_starting_salutation();
  DTStamp(); printf("Running main_gpr_thread_barrier.cxx \n");
  
  printf("=============================================================\n");
  start_timer(1);
		DTStamp();
		printf("CHECK 1: Check environment, date, time and clock.\n");
		display_date_only();
		current_working_directory();
		DTStamp(); printf("Current runfile  : %s \n", argv[0]);
		display_resolution_date_time();
  stop_timer(1);
  
  printf("=============================================================\n");
	start_timer(2);
		DTStamp();
		printf("CHECK 2.1: Display generation of uniform random integers.\n");
		long int int_count = 10;		// Number of randoms to generate
		long int int_min = -1000;		// Min value of random integer
     long int int_max = +1000;		// Max value of random integer
    
     // EXECUTE ...
		srand((unsigned)time(NULL));
		display_random_integers(int_count, int_min, int_max);

		DTStamp();
		printf("CHECK 2.2: Check randomness of generated of uniform random integers.\n");
		int int_bins_check = 10;			       // Number of bins to collect randoms
     long int int_count_check = 1000000;  // Number of randoms to generate
     // Generate random integer values in range (int_min_check, int_max_check) 
		long int int_min_check = 0;          
     long int int_max_check = +1000;   
   
    // EXECUTE ...
    srand((unsigned)time(NULL));
    check_randomness_of_integers(int_bins_check, int_count_check, int_min_check, int_max_check);
	stop_timer(2);
  
  
  printf("=============================================================\n");
	start_timer(3);
		DTStamp();
		printf("CHECK 3.1: Display generation of uniform random doubles.\n");
		long int dbl_count = 10;			// Number of randoms to generate
		double   dbl_min = -1001.44445;		// Min value of random integer
		double   dbl_max = +2001.66665;		// Max value of random integer
 
     // EXECUTE ...
     srand((unsigned)time(NULL));
		display_random_doubles(dbl_count, dbl_min, dbl_max);

		DTStamp();
		printf("CHECK 3.2: Check randomness of generated of uniform random doubles.\n");
		int dbl_bins_check = 10;			// Number of bins to collect randoms
		long int dbl_count_check = 1000000;	// Number of randoms to generate
		double   dbl_min_check = 0.0;
		double   dbl_max_check = +1000.0;
		
     // EXECUTE
     srand((unsigned)time(NULL));
		check_randomness_of_doubles(dbl_bins_check, dbl_count_check, dbl_min_check, dbl_max_check);
		stop_timer(3);
     printf("=============================================================\n");
  
  
  
  
  WRY_ending_salutation();
  printf("=============================================================\n");
	return (0);
}
