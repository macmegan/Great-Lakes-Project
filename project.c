#include <stdio.h>

/* function declarations */
double yearavg (int x);
void compare (double x);
void date (int x);
void overall (void);

int main()
{	
	/* REQUIRED ELEMENT 1 */
	double avg_of_six;
	avg_of_six = (yearavg(2)+yearavg(3)+yearavg(4)+yearavg(5)+yearavg(6)+yearavg(7))/6;
	
	/* table of average yearly temps */
	/* passes to yearavg function */
	printf("        Average Yearly Temperatures\n");
	printf("Lake Superior         %0.2lf degrees celsius\n", yearavg(2));
	printf("Lake Michigan         %0.2lf degrees celsius\n", yearavg(3));
	printf("Lake Huron            %0.2lf degrees celsius\n", yearavg(4));
	printf("Lake Erie             %0.2lf degrees celsius\n", yearavg(5));
	printf("Lake Ontario          %0.2lf degrees celsius\n", yearavg(6));
	printf("Lake St. Clair        %0.2lf degrees celsius\n", yearavg(7));
	printf("All Lakes             %0.2lf degrees celsius\n\n", avg_of_six);
	
	/* REQUIRED ELEMENT 2 */
	compare(avg_of_six); /* passes to compare function */
	
	/* REQUIRED ELEMENT 3 */
	/* table of warmest and coldest days for each lake */
	/* passes to date function */
	printf("                 Warmest          Date      Coldest          Date  \n");
	printf("Lake Superior    "); date(2);
	printf("Lake Michigan    "); date(3);
	printf("Lake Huron       "); date(4);
	printf("Lake Erie        "); date(5);
	printf("Lake Ontario     "); date(6);
	printf("Lake St. Clair   "); date(7);
	
	/* REQUIRED ELEMENT 4 */
	/* table of warmest and coldest days for all lakes */
	/* passes to overall function*/
	printf("\n     Lake        Warmest Overall  Date      Coldest Overall  Date  \n");
	overall();

}

double yearavg (int x)
{
	/* variable declaration */
	double array[365][8];
	double average, total;
	int i, j;
	
	/* read in data file */
	FILE *data;
	data = fopen("lakes.txt","r");

	for(i = 0; i < 365; i++)
		for(j = 0; j < 8; j++)
			fscanf(data, "%lf", &array[i][j]);
	
	total = 0; /* initialize sum to 0 */
	
	/* add up temps in the same column */
	for(i = 0; i < 365; i++)
		total = total + array[i][x];
		
	/* calculate average and passes back to main */
	average = total/365;
	return(average);
	
	fclose(data);
}

void compare (double x)
{
	/* variable declaration */
	char sup[] = "Lake Superior";
	char mich[] = "Lake Michigan";
	char huron[] = "Lake Huron";
	char erie[] = "Lake Erie";
	char ont[] = "Lake Ontario";
	char stc[] = "Lake St. Clair";
	double coldest_lake, warmest_lake;
	int i;
	
	/* initialize values */	 
	coldest_lake = yearavg(2);
	warmest_lake = yearavg(2);
	
	/* determine coldest and warmest lake on average */
	for (i = 2; i < 8; i++)
		{
			if (yearavg(i) < coldest_lake)
				coldest_lake = yearavg(i);
			if (yearavg(i) > warmest_lake)
				warmest_lake = yearavg(i);
		}
	
	/* output coldest lake */
	if (coldest_lake == yearavg(2))
		printf("%s is coldest on average\n", sup);
	if (coldest_lake == yearavg(3))
		printf("%s is coldest on average\n", mich);	    
	if (coldest_lake == yearavg(4))
		printf("%s is coldest on average\n", huron);
	if (coldest_lake == yearavg(5))
		printf("%s is coldest on average\n", erie);
	if (coldest_lake == yearavg(6))
		printf("%s is coldest on average\n", ont);
	if (coldest_lake == yearavg(7))
		printf("%s is coldest on average\n", stc);
		
	/* output warmest lake */
	if (warmest_lake == yearavg(2))
		printf("%s is warmest on average\n", sup);
	if (warmest_lake == yearavg(3))
		printf("%s is warmest on average\n", mich);	    
	if (warmest_lake == yearavg(4))
		printf("%s is warmest on average\n", huron);
	if (warmest_lake == yearavg(5))
		printf("%s is warmest on average\n", erie);
	if (warmest_lake == yearavg(6))
		printf("%s is warmest on average\n", ont);
	if (warmest_lake == yearavg(7))
		printf("%s is warmest on average\n", stc);
		
	/* determine and output lakes warmer than average */
	printf("\nAbove Overall Average: ");
	if (x < yearavg(2))
		printf("%s, ", sup);
	if (x < yearavg(3))
		printf("%s, ", mich);
	if (x < yearavg(4))
		printf("%s, ", huron);
	if (x < yearavg(5))
		printf("%s, ", erie);
	if (x < yearavg(6))
		printf("%s, ", ont);
	if (x < yearavg(7))
		printf("%s ", stc);
	
	/* determine and output lakes colder than average */
	printf("\nBelow Overall Average: ");
	if (x > yearavg(2))
		printf("%s, ", sup);
	if (x > yearavg(3))
		printf("%s, ", mich);
	if (x > yearavg(4))
		printf("%s ", huron);
	if (x > yearavg(5))
		printf("%s, ", erie);
	if (x > yearavg(6))
		printf("%s, ", ont);
	if (x > yearavg(7))
		printf("%s ", stc);
		
	printf("\n\n");
}

void date (int x)
{
	/* variable declaration */
	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int warmest_date, coldest_date, warmest_month = 1, coldest_month = 1;
	int warmest_row, coldest_row;
	int i, j;
	double array[365][8];
	double warmest_temp, coldest_temp;
	
	/* read in file */
	FILE *data;
	data = fopen("lakes.txt","r");

	for(i = 0; i < 365; i++)
		for(j = 0; j < 8; j++)
			fscanf(data, "%lf", &array[i][j]);

	/* initialize values */
	warmest_temp = array[0][x];
	coldest_temp = array[0][x];
	
	/* determine warmest and coldest temps */
	for(i = 0; i < 365; i++)
		{
			if (array[i][x] > warmest_temp)
				{
					warmest_temp = array[i][x];
					warmest_row = i;
				}
			if (array[i][x] < coldest_temp)
				{
					coldest_temp = array[i][x];
					coldest_row = i;
				}
		}
	
	/* convert row number in data to day of the year */
	warmest_date = warmest_row + 1;
	coldest_date = coldest_row + 1;
	
	/* convert warmest day of the year to date */
	for(i = 0; i < 12; i++)
		{
			if (warmest_date > days_in_month[i])
				{
					warmest_date = warmest_date - days_in_month[i];
					warmest_month++;
				}
		}
	
	/* convert coldest day of the year to date */
	for(i = 0; i < 12; i++)
		{
			if (coldest_date > days_in_month[i])
				{
					coldest_date = coldest_date - days_in_month[i];
					coldest_month++;
				}
		}
	
	/* passes back to main and outputs values into a table */
	printf("%0.2lf celsius    %02d/0%d     %0.2lf celsius     %02d/0%d \n", warmest_temp, warmest_date, warmest_month, coldest_temp, coldest_date, coldest_month);
	
	fclose(data);
	
}

void overall (void)
{
	/* variable declaration */
	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int warmest_lake, coldest_lake;
	int warmest_row, coldest_row;
	int warmest_date, coldest_date;
	int warmest_month = 1, coldest_month = 1;
	int i, j;
	double array[365][8];
	double warmest_temp_overall, coldest_temp_overall;
	
	/* read in file */
	FILE *data;	
	data = fopen("lakes.txt","r");

	for(i = 0; i < 365 ; i++)
		for(j = 0; j < 8 ; j++)
			fscanf(data, "%lf", &array[i][j]);
	
	/* initialize values */
	warmest_temp_overall = array[0][2];
	coldest_temp_overall = array[0][2];
	
	/* determine warmest and coldest overall temps */
	for(i = 0; i < 365 ; i++)
		{
			for(j = 2; j < 8 ; j++)
				{
					if (array[i][j] > warmest_temp_overall)
						{
							warmest_temp_overall = array[i][j];
							warmest_row = i;
							warmest_lake = j;
						}
					if (array[i][j] < coldest_temp_overall)
						{
							coldest_temp_overall = array[i][j];
							coldest_row = i;
							coldest_lake = j;
						}
				}
		}
	
	/* determine and output lake with warmest day overall */
	if (warmest_lake == 2)
		printf("Lake Superior");
	if (warmest_lake == 3)
		printf("Lake Michigan");
	if (warmest_lake == 4)
		printf("Lake Huron");
	if (warmest_lake == 5)
		printf("Lake Erie");
	if (warmest_lake == 6)
		printf("Lake Ontario");
	if (warmest_lake == 7)
		printf("Lake St. Clair");
	
	/* converts warmest day of the year to date*/
	warmest_date = warmest_row + 1;
	
	for(i = 0; i < 12; i++)
		{
			if (warmest_date > days_in_month[i])
				{
					warmest_date = warmest_date - days_in_month[i];
					warmest_month++;
				}
		}
	
	/* output values for warmest day overall */	   
	printf("   %0.2lf celsius    %02d/0%d     ----------------------\n", warmest_temp_overall, warmest_date, warmest_month);
	
	/* determine and output lake with coldest day overall */
	if (coldest_lake == 2)
		printf("Lake Superior");
	if (coldest_lake == 3)
		printf("Lake Michigan");
	if (coldest_lake == 4)
		printf("Lake Huron");
	if (coldest_lake == 5)
		printf("Lake Erie");
	if (coldest_lake == 6)
		printf("Lake Ontario");
	if (coldest_lake == 7)
		printf("Lake St. Clair");
	
	/* converts warmest day of the year to date*/
	coldest_date = coldest_row + 1;
	
	for(i = 0; i < 12; i++)
		{
			if (coldest_date > days_in_month[i])
				{
					coldest_date = coldest_date - days_in_month[i];
					coldest_month++;
				}
		}
	
	/* outputs values for warmest day overall */
	printf("   ----------------------     %0.2lf celsius     %02d/0%d\n", coldest_temp_overall, coldest_date, coldest_month);
}
