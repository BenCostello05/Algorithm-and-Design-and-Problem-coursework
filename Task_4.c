/*
Program Description: •	This program creates a report which summarises the number of issues reported for a product across all production lines.

Author: Ben Costello

Date: 03/04/24

*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define amount 13
#define SIZE 200

//Structure templates
struct resolution_code
{
    int code;
    char description[SIZE];
};

struct issue_code
{
    int code;
    char description[SIZE];
};

struct date_time
{
    int day;
    int hour;
    int minute;
};

struct QAlogs
{   
    int line_code;
    int batch_code;
    struct date_time date_time;
    int product_id;
    struct issue_code issue;
    struct resolution_code resolution;
    int employee_id;
};

//Function Signatures
int Merge_sort(struct QAlogs *,struct QAlogs *, int,int, int);
int Merge(struct QAlogs *, struct QAlogs *, int,int,int);
int summary(struct QAlogs *, int);

int main()
{

//Create structure variables
struct QAlogs prod_1[amount], temp[amount*4], prod_2[amount],prod_3[amount], prod_4[amount], all_prod[(amount*4)];

int low = 0;
int high = (amount*4)-1;
int mid = 0;
int i;
int j;


//Production line 1
prod_1[0].line_code = 1;
prod_1[0].batch_code = 56;
prod_1[0].date_time.day = 13;
prod_1[0].date_time.hour = 16;
prod_1[0].date_time.minute = 36;
prod_1[0].product_id = 36;
prod_1[0].issue.code = 89;
strcpy(prod_1[0].issue.description, "Incomplete");
prod_1[0].resolution.code = 72;
strcpy(prod_1[0].resolution.description, "Finish by hand");
prod_1[0].employee_id = 90;

prod_1[1].line_code = 1;
prod_1[1].batch_code = 23;
prod_1[1].date_time.day = 16;
prod_1[1].date_time.hour = 14;
prod_1[1].date_time.minute = 59;
prod_1[1].product_id = 23;
prod_1[1].issue.code = 56;
strcpy(prod_1[1].issue.description, "Broken");
prod_1[1].resolution.code = 89;
strcpy(prod_1[1].resolution.description, "Recycle");
prod_1[1].employee_id = 90;

prod_1[2].line_code = 1;
prod_1[2].batch_code = 12;
prod_1[2].date_time.day = 16;
prod_1[2].date_time.hour = 12;
prod_1[2].date_time.minute = 48;
prod_1[2].product_id = 23;
prod_1[2].issue.code = 56;
strcpy(prod_1[2].issue.description, "Broken");
prod_1[2].resolution.code = 89;
strcpy(prod_1[2].resolution.description, "Recycle");
prod_1[2].employee_id = 76;

prod_1[3].line_code = 1;
prod_1[3].batch_code = 45;
prod_1[3].date_time.day = 28;
prod_1[3].date_time.hour = 8;
prod_1[3].date_time.minute = 2;
prod_1[3].product_id = 36;
prod_1[3].issue.code = 89;
strcpy(prod_1[3].issue.description, "Incomplete");
prod_1[3].resolution.code = 72;
strcpy(prod_1[3].resolution.description, "Finish by hand");
prod_1[3].employee_id = 43;

prod_1[4].line_code = 1;
prod_1[4].batch_code = 12;
prod_1[4].date_time.day = 8;
prod_1[4].date_time.hour = 16;
prod_1[4].date_time.minute = 43;
prod_1[4].product_id = 23;
prod_1[4].issue.code = 12;
strcpy(prod_1[4].issue.description, "Damaged");
prod_1[4].resolution.code = 16;
strcpy(prod_1[4].resolution.description, "Repair");
prod_1[4].employee_id = 65;

prod_1[5].line_code = 1;
prod_1[5].batch_code = 34;
prod_1[5].date_time.day = 2;
prod_1[5].date_time.hour = 23;
prod_1[5].date_time.minute = 65;
prod_1[5].product_id = 67;
prod_1[5].issue.code = 10;
strcpy(prod_1[5].issue.description, "Packaging Damaged");
prod_1[5].resolution.code = 17;
strcpy(prod_1[5].resolution.description, "Repackaged");
prod_1[5].employee_id = 45;

prod_1[6].line_code = 1;
prod_1[6].batch_code = 18;
prod_1[6].date_time.day = 19;
prod_1[6].date_time.hour = 5;
prod_1[6].date_time.minute = 12;
prod_1[6].product_id = 32;
prod_1[6].issue.code = 78;
strcpy(prod_1[6].issue.description, "Colour not correct");
prod_1[6].resolution.code = 90;
strcpy(prod_1[6].resolution.description, "Recoloured");
prod_1[6].employee_id = 12;

prod_1[7].line_code = 1;
prod_1[7].batch_code = 56;
prod_1[7].date_time.day = 31;
prod_1[7].date_time.hour = 17;
prod_1[7].date_time.minute = 16;
prod_1[7].product_id = 123;
prod_1[7].issue.code = 95;
strcpy(prod_1[7].issue.description, "Parts Loose");
prod_1[7].resolution.code = 76;
strcpy(prod_1[7].resolution.description, "Retightend");
prod_1[7].employee_id = 48;

prod_1[8].line_code = 1;
prod_1[8].batch_code = 72;
prod_1[8].date_time.day = 1;
prod_1[8].date_time.hour = 9;
prod_1[8].date_time.minute = 57;
prod_1[8].product_id = 32;
prod_1[8].issue.code = 14;
strcpy(prod_1[8].issue.description, "Extra part");
prod_1[8].resolution.code = 20;
strcpy(prod_1[8].resolution.description, "Removed part");
prod_1[8].employee_id = 78;

prod_1[9].line_code = 1;
prod_1[9].batch_code = 100;
prod_1[9].date_time.day = 10;
prod_1[9].date_time.hour = 8;
prod_1[9].date_time.minute = 35;
prod_1[9].product_id = 89;
prod_1[9].issue.code = 105;
strcpy(prod_1[9].issue.description, "Label Error");
prod_1[9].resolution.code = 32;
strcpy(prod_1[9].resolution.description, "Relabelled");
prod_1[9].employee_id = 106;

prod_1[10].line_code = 1;
prod_1[10].batch_code = 389;
prod_1[10].date_time.day = 7;
prod_1[10].date_time.hour = 9;
prod_1[10].date_time.minute = 13;
prod_1[10].product_id = 46;
prod_1[10].issue.code = 76;
strcpy(prod_1[10].issue.description, "Inferior Quality");
prod_1[10].resolution.code = 3;
strcpy(prod_1[10].resolution.description, "Discarded");
prod_1[10].employee_id = 60;

prod_1[11].line_code = 1;
prod_1[11].batch_code = 145;
prod_1[11].date_time.day = 12;
prod_1[11].date_time.hour = 23;
prod_1[11].date_time.minute = 98;
prod_1[11].product_id = 23;
prod_1[11].issue.code = 64;
strcpy(prod_1[11].issue.description, "Malfunctioning");
prod_1[11].resolution.code = 16;
strcpy(prod_1[11].resolution.description, "Repair");
prod_1[11].employee_id = 65;

prod_1[12].line_code = 1;
prod_1[12].batch_code = 13;
prod_1[12].date_time.day = 12;
prod_1[12].date_time.hour = 13;
prod_1[12].date_time.minute = 54;
prod_1[12].product_id = 48;
prod_1[12].issue.code = 90;
strcpy(prod_1[12].issue.description, "Chemical leakage");
prod_1[12].resolution.code = 16;
strcpy(prod_1[12].resolution.description, "Destroyed");
prod_1[12].employee_id = 65;

//Production line 2
prod_2[0].line_code = 2;
prod_2[0].batch_code = 48;
prod_2[0].date_time.day = 12;
prod_2[0].date_time.hour = 6;
prod_2[0].date_time.minute = 36;
prod_2[0].product_id = 89;
prod_2[0].issue.code = 90;
strcpy(prod_2[0].issue.description, "Chemical Leakage");
prod_2[0].resolution.code = 16;
strcpy(prod_2[0].resolution.description, "Destroyed");
prod_2[0].employee_id = 67;

prod_2[1].line_code = 2;
prod_2[1].batch_code = 76;
prod_2[1].date_time.day = 12;
prod_2[1].date_time.hour = 6;
prod_2[1].date_time.minute = 23;
prod_2[1].product_id = 89;
prod_2[1].issue.code = 89;
strcpy(prod_2[1].issue.description, "Incomplete");
prod_2[1].resolution.code = 72;
strcpy(prod_2[1].resolution.description, "Finish by hand");
prod_2[1].employee_id = 12;

prod_2[2].line_code = 2;
prod_2[2].batch_code = 33;
prod_2[2].date_time.day = 14;
prod_2[2].date_time.hour = 10;
prod_2[2].date_time.minute = 12;
prod_2[2].product_id = 89;
prod_2[2].issue.code = 78;
strcpy(prod_2[2].issue.description, "Colour not correct");
prod_2[2].resolution.code = 90;
strcpy(prod_2[2].resolution.description, "Recoloured");
prod_2[2].employee_id = 45;

prod_2[3].line_code = 2;
prod_2[3].batch_code = 94;
prod_2[3].date_time.day = 14;
prod_2[3].date_time.hour = 15;
prod_2[3].date_time.minute = 36;
prod_2[3].product_id = 89;
prod_2[3].issue.code = 89;
strcpy(prod_2[3].issue.description, "Incomplete");
prod_2[3].resolution.code = 72;
strcpy(prod_2[3].resolution.description, "Finish by hand");
prod_2[3].employee_id = 90;

prod_2[4].line_code = 2;
prod_2[4].batch_code = 56;
prod_2[4].date_time.day = 14;
prod_2[4].date_time.hour = 16;
prod_2[4].date_time.minute = 36;
prod_2[4].product_id = 36;
prod_2[4].issue.code = 76;
strcpy(prod_2[4].issue.description, "Inferior Quality");
prod_2[4].resolution.code = 3;
strcpy(prod_2[4].resolution.description, "Discarded");
prod_2[4].employee_id = 2;

prod_2[5].line_code = 2;
prod_2[5].batch_code = 102;
prod_2[5].date_time.day = 8;
prod_2[5].date_time.hour = 18;
prod_2[5].date_time.minute = 21;
prod_2[5].product_id = 203;
prod_2[5].issue.code = 10;
strcpy(prod_2[5].issue.description, "Packaging Damaged");
prod_2[5].resolution.code = 17;
strcpy(prod_2[5].resolution.description, "Repackaged");
prod_2[5].employee_id = 72;

prod_2[6].line_code = 2;
prod_2[6].batch_code = 436;
prod_2[6].date_time.day = 2;
prod_2[6].date_time.hour = 16;
prod_2[6].date_time.minute = 23;
prod_2[6].product_id = 203 ;
prod_2[6].issue.code = 95;
strcpy(prod_2[6].issue.description, "Parts loose");
prod_2[6].resolution.code = 76;
strcpy(prod_2[6].resolution.description, "Retightend");
prod_2[6].employee_id = 34;

prod_2[7].line_code = 2;
prod_2[7].batch_code = 76;
prod_2[7].date_time.day = 12;
prod_2[7].date_time.hour = 22;
prod_2[7].date_time.minute = 10;
prod_2[7].product_id = 45;
prod_2[7].issue.code = 12;
strcpy(prod_2[7].issue.description, "Damaged");
prod_2[7].resolution.code = 16;
strcpy(prod_2[7].resolution.description, "Repair");
prod_2[7].employee_id = 405;

prod_2[8].line_code = 2;
prod_2[8].batch_code = 204;
prod_2[8].date_time.day = 19;
prod_2[8].date_time.hour = 16;
prod_2[8].date_time.minute = 36;
prod_2[8].product_id = 40;
prod_2[8].issue.code = 56;
strcpy(prod_2[8].issue.description, "Broken");
prod_2[8].resolution.code = 89;
strcpy(prod_2[8].resolution.description, "Recycle");
prod_2[8].employee_id = 65;

prod_2[9].line_code = 2;
prod_2[9].batch_code = 23;
prod_2[9].date_time.day = 6;
prod_2[9].date_time.hour = 19;
prod_2[9].date_time.minute = 2;
prod_2[9].product_id = 36;
prod_2[9].issue.code = 64;
strcpy(prod_2[9].issue.description, "Malfunctioning");
prod_2[9].resolution.code = 16;
strcpy(prod_2[9].resolution.description, "Repair");
prod_2[9].employee_id = 105;

prod_2[10].line_code = 2;
prod_2[10].batch_code = 56;
prod_2[10].date_time.day = 12;
prod_2[10].date_time.hour = 15;
prod_2[10].date_time.minute = 5;
prod_2[10].product_id = 28;
prod_2[10].issue.code = 14;
strcpy(prod_2[10].issue.description, "Extra part");
prod_2[10].resolution.code = 20;
strcpy(prod_2[10].resolution.description, "Removed part");
prod_2[10].employee_id = 76;

prod_2[11].line_code = 2;
prod_2[11].batch_code = 90;
prod_2[11].date_time.day = 1;
prod_2[11].date_time.hour = 18;
prod_2[11].date_time.minute = 42;
prod_2[11].product_id = 23;
prod_2[11].issue.code = 105;
strcpy(prod_2[11].issue.description, "Label error");
prod_2[11].resolution.code = 32;
strcpy(prod_2[11].resolution.description, "Relabelled");
prod_2[11].employee_id = 602;

prod_2[12].line_code = 2;
prod_2[12].batch_code = 34;
prod_2[12].date_time.day = 10;
prod_2[12].date_time.hour = 19;
prod_2[12].date_time.minute = 56;
prod_2[12].product_id = 24;
prod_2[12].issue.code = 95;
strcpy(prod_2[12].issue.description, "Parts loose");
prod_2[12].resolution.code = 76;
strcpy(prod_2[12].resolution.description, "Retightend");
prod_2[12].employee_id = 23;


//Production line 3
prod_3[0].line_code = 3;
prod_3[0].batch_code = 23;
prod_3[0].date_time.day = 14;
prod_3[0].date_time.hour = 12;
prod_3[0].date_time.minute = 15;
prod_3[0].product_id = 45;
prod_3[0].issue.code = 12;
strcpy(prod_3[0].issue.description, "Damaged");
prod_3[0].resolution.code = 16;
strcpy(prod_3[0].resolution.description, "Repair");
prod_3[0].employee_id = 204;

prod_3[1].line_code = 3;
prod_3[1].batch_code = 23;
prod_3[1].date_time.day = 14;
prod_3[1].date_time.hour = 12;
prod_3[1].date_time.minute = 12;
prod_3[1].product_id = 45;
prod_3[1].issue.code = 12;
strcpy(prod_3[1].issue.description, "Damaged");
prod_3[1].resolution.code = 16;
strcpy(prod_3[1].resolution.description, "Repair");
prod_3[1].employee_id = 56;

prod_3[2].line_code = 3;
prod_3[2].batch_code = 89;
prod_3[2].date_time.day = 14;
prod_3[2].date_time.hour = 18;
prod_3[2].date_time.minute = 2;
prod_3[2].product_id = 45;
prod_3[2].issue.code = 105;
strcpy(prod_3[2].issue.description, "Label error");
prod_3[2].resolution.code = 32;
strcpy(prod_3[2].resolution.description, "Relabelled");
prod_3[2].employee_id = 23;

prod_3[3].line_code = 3;
prod_3[3].batch_code = 58;
prod_3[3].date_time.day = 13;
prod_3[3].date_time.hour = 20;
prod_3[3].date_time.minute = 13;
prod_3[3].product_id = 45;
prod_3[3].issue.code = 89;
strcpy(prod_3[3].issue.description, "Incomplete");
prod_3[3].resolution.code = 72;
strcpy(prod_3[3].resolution.description, "Finish by hand");
prod_3[3].employee_id = 209;

prod_3[4].line_code = 3;
prod_3[4].batch_code = 13;
prod_3[4].date_time.day = 24;
prod_3[4].date_time.hour = 2;
prod_3[4].date_time.minute = 7;
prod_3[4].product_id = 45;
prod_3[4].issue.code = 89;
strcpy(prod_3[4].issue.description, "Incomplete");
prod_3[4].resolution.code = 72;
strcpy(prod_3[4].resolution.description, "Finish by hand");
prod_3[4].employee_id = 209;

prod_3[5].line_code = 3;
prod_3[5].batch_code = 316;
prod_3[5].date_time.day = 24;
prod_3[5].date_time.hour = 4;
prod_3[5].date_time.minute = 49;
prod_3[5].product_id = 90;
prod_3[5].issue.code = 78;
strcpy(prod_3[5].issue.description, "Colour not correct");
prod_3[5].resolution.code = 90;
strcpy(prod_3[5].resolution.description, "Recoloured");
prod_3[5].employee_id = 507;

prod_3[6].line_code = 3;
prod_3[6].batch_code = 211;
prod_3[6].date_time.day = 22;
prod_3[6].date_time.hour = 54;
prod_3[6].date_time.minute = 12;
prod_3[6].product_id = 75;
prod_3[6].issue.code = 95;
strcpy(prod_3[6].issue.description, "Parts loose");
prod_3[6].resolution.code = 76;
strcpy(prod_3[6].resolution.description, "Retightend");
prod_3[6].employee_id = 43;

prod_3[7].line_code = 3;
prod_3[7].batch_code = 301;
prod_3[7].date_time.day = 29;
prod_3[7].date_time.hour = 16;
prod_3[7].date_time.minute = 10;
prod_3[7].product_id = 68;
prod_3[7].issue.code = 14;
strcpy(prod_3[7].issue.description, "Extra part");
prod_3[7].resolution.code = 20;
strcpy(prod_3[7].resolution.description, "Removed part");
prod_3[7].employee_id = 20;

prod_3[8].line_code = 3;
prod_3[8].batch_code = 73;
prod_3[8].date_time.day = 15;
prod_3[8].date_time.hour = 13;
prod_3[8].date_time.minute = 16;
prod_3[8].product_id = 89;
prod_3[8].issue.code = 10;
strcpy(prod_3[8].issue.description, "Packaging Damaged");
prod_3[8].resolution.code = 17;
strcpy(prod_3[8].resolution.description, "Repackaged");
prod_3[8].employee_id = 59;

prod_3[9].line_code = 3;
prod_3[9].batch_code = 24;
prod_3[9].date_time.day = 18;
prod_3[9].date_time.hour = 9;
prod_3[9].date_time.minute = 58;
prod_3[9].product_id = 104;
prod_3[9].issue.code = 90;
strcpy(prod_3[9].issue.description, "Chemical leakage");
prod_3[9].resolution.code = 16;
strcpy(prod_3[9].resolution.description, "Destroyed");
prod_3[9].employee_id = 49;

prod_3[10].line_code = 3;
prod_3[10].batch_code = 30;
prod_3[10].date_time.day = 15;
prod_3[10].date_time.hour = 20;
prod_3[10].date_time.minute = 1;
prod_3[10].product_id = 45;
prod_3[10].issue.code = 56;
strcpy(prod_3[10].issue.description, "Broken");
prod_3[10].resolution.code = 89;
strcpy(prod_3[10].resolution.description, "Recycle");
prod_3[10].employee_id = 65;

prod_3[11].line_code = 3;
prod_3[11].batch_code = 13;
prod_3[11].date_time.day = 23;
prod_3[11].date_time.hour = 8;
prod_3[11].date_time.minute = 13;
prod_3[11].product_id = 32;
prod_3[11].issue.code = 76;
strcpy(prod_3[11].issue.description, "Inferior Quality");
prod_3[11].resolution.code = 3;
strcpy(prod_3[11].resolution.description, "Discarded");
prod_3[11].employee_id = 34;

prod_3[12].line_code = 3;
prod_3[12].batch_code = 503;
prod_3[12].date_time.day = 26;
prod_3[12].date_time.hour = 12;
prod_3[12].date_time.minute = 10;
prod_3[12].product_id = 76;
prod_3[12].issue.code = 64;
strcpy(prod_3[12].issue.description, "Malfunction");
prod_3[12].resolution.code = 16;
strcpy(prod_3[12].resolution.description, "Repair");
prod_3[12].employee_id = 32;


//Production line 4
prod_4[0].line_code = 4;
prod_4[0].batch_code = 34;
prod_4[0].date_time.day = 12;
prod_4[0].date_time.hour = 13;
prod_4[0].date_time.minute = 23;
prod_4[0].product_id = 97;
prod_4[0].issue.code = 89;
strcpy(prod_4[0].issue.description, "Incomplete");
prod_4[0].resolution.code = 72;
strcpy(prod_4[0].resolution.description, "Finish by hand");
prod_4[0].employee_id = 76;

prod_4[1].line_code = 4;
prod_4[1].batch_code = 76;
prod_4[1].date_time.day = 12;
prod_4[1].date_time.hour = 13;
prod_4[1].date_time.minute = 45;
prod_4[1].product_id = 97;
prod_4[1].issue.code = 89;
strcpy(prod_4[1].issue.description, "Incomplete");
prod_4[1].resolution.code = 72;
strcpy(prod_4[1].resolution.description, "Finish by hand");
prod_4[1].employee_id = 76;

prod_4[2].line_code = 4;
prod_4[2].batch_code = 54;
prod_4[2].date_time.day = 12;
prod_4[2].date_time.hour = 16;
prod_4[2].date_time.minute = 59;
prod_4[2].product_id = 12;
prod_4[2].issue.code = 76;
strcpy(prod_4[2].issue.description, "Inferior Quality");
prod_4[2].resolution.code = 3;
strcpy(prod_4[2].resolution.description, "Discarded");
prod_4[2].employee_id = 56;

prod_4[3].line_code = 4;
prod_4[3].batch_code = 102;
prod_4[3].date_time.day = 12;
prod_4[3].date_time.hour = 10;
prod_4[3].date_time.minute = 25;
prod_4[3].product_id = 12;
prod_4[3].issue.code = 76;
strcpy(prod_4[3].issue.description, "Inferior Quality");
prod_4[3].resolution.code = 3;
strcpy(prod_4[3].resolution.description, "Discarded");
prod_4[3].employee_id = 48;

prod_4[4].line_code = 4;
prod_4[4].batch_code = 108;
prod_4[4].date_time.day =13;
prod_4[4].date_time.hour = 17;
prod_4[4].date_time.minute = 8;
prod_4[4].product_id = 12;
prod_4[4].issue.code = 78;
strcpy(prod_4[4].issue.description, "Colour not correct");
prod_4[4].resolution.code = 90;
strcpy(prod_4[4].resolution.description, "Recoloured");
prod_4[4].employee_id = 201;

prod_4[5].line_code = 4;
prod_4[5].batch_code = 56;
prod_4[5].date_time.day = 18;
prod_4[5].date_time.hour = 15;
prod_4[5].date_time.minute = 43;
prod_4[5].product_id = 27;
prod_4[5].issue.code = 105;
strcpy(prod_4[5].issue.description, "Label error");
prod_4[5].resolution.code = 32;
strcpy(prod_4[5].resolution.description, "Relabelled");
prod_4[5].employee_id = 72;

prod_4[6].line_code = 4;
prod_4[6].batch_code = 43;
prod_4[6].date_time.day = 28;
prod_4[6].date_time.hour = 12;
prod_4[6].date_time.minute = 30;
prod_4[6].product_id = 65;
prod_4[6].issue.code = 95;
strcpy(prod_4[6].issue.description, "Parts loose");
prod_4[6].resolution.code = 76;
strcpy(prod_4[6].resolution.description, "Retightend");
prod_4[6].employee_id = 102;

prod_4[7].line_code = 4;
prod_4[7].batch_code = 76;
prod_4[7].date_time.day = 29;
prod_4[7].date_time.hour = 8;
prod_4[7].date_time.minute = 26;
prod_4[7].product_id = 105;
prod_4[7].issue.code = 10;
strcpy(prod_4[7].issue.description, "Packaging Damaged");
prod_4[7].resolution.code = 17;
strcpy(prod_4[7].resolution.description, "Repackaged");
prod_4[7].employee_id = 23;

prod_4[8].line_code = 4;
prod_4[8].batch_code = 97;
prod_4[8].date_time.day = 18;
prod_4[8].date_time.hour = 3;
prod_4[8].date_time.minute = 47;
prod_4[8].product_id = 106;
prod_4[8].issue.code = 90;
strcpy(prod_4[8].issue.description, "Chemical leakage");
prod_4[8].resolution.code = 16;
strcpy(prod_4[8].resolution.description, "Destroyed");
prod_4[8].employee_id = 64;

prod_4[9].line_code = 4;
prod_4[9].batch_code = 49;
prod_4[9].date_time.day = 26;
prod_4[9].date_time.hour = 15;
prod_4[9].date_time.minute = 8;
prod_4[9].product_id = 56;
prod_4[9].issue.code = 14;
strcpy(prod_4[9].issue.description, "Extra part");
prod_4[9].resolution.code = 20;
strcpy(prod_4[9].resolution.description, "Removed part");
prod_4[9].employee_id = 29;

prod_4[10].line_code = 4;
prod_4[10].batch_code = 208;
prod_4[10].date_time.day = 30;
prod_4[10].date_time.hour = 13;
prod_4[10].date_time.minute = 6;
prod_4[10].product_id = 49;
prod_4[10].issue.code = 64;
strcpy(prod_4[10].issue.description, "Malfunctioning");
prod_4[10].resolution.code = 16;
strcpy(prod_4[10].resolution.description, "Repair");
prod_4[10].employee_id = 97;

prod_4[11].line_code = 4;
prod_4[11].batch_code = 23;
prod_4[11].date_time.day = 19;
prod_4[11].date_time.hour = 8;
prod_4[11].date_time.minute = 23;
prod_4[11].product_id = 123;
prod_4[11].issue.code = 56;
strcpy(prod_4[11].issue.description, "Broken");
prod_4[11].resolution.code = 89;
strcpy(prod_4[11].resolution.description, "Recycle");
prod_4[11].employee_id = 42;

prod_4[12].line_code = 4;
prod_4[12].batch_code = 72;
prod_4[12].date_time.day = 19;
prod_4[12].date_time.hour = 12;
prod_4[12].date_time.minute = 52;
prod_4[12].product_id = 56;
prod_4[12].issue.code = 12;
strcpy(prod_4[12].issue.description, "Damaged");
prod_4[12].resolution.code = 16;
strcpy(prod_4[12].resolution.description, "Repair");
prod_4[12].employee_id = 96;


//Puts all data into one single list
for(i=0;i<amount;i++)//For production line 1
{
    all_prod[i] = prod_1[i];
}

for(i=amount;i<(amount*2);i++)//For production line 2
{
    all_prod[i] = prod_2[i - amount];
}

for(i=(amount*2);i<(amount*3);i++)//For production line 3
{
    all_prod[i] = prod_3[i - (amount*2)];
}

for(i=(amount*3);i<(amount*4);i++)//For production line 4
{
    all_prod[i] = prod_4[i - (amount*3)];
}

//Calls merge_sort function for all production lines
Merge_sort(all_prod,temp,low,high,mid);

//Resets the high variable
high = (amount*4)-1;

printf("\n\n\t Summary\n");
printf("Product ID \tNumber of issues");

//Calls the summary function
summary(all_prod,high);


}

//Merge sort function
//Takes in the array of structures put's it in as a parameter when called and sets it to the pointer products
int Merge_sort(struct QAlogs *products, struct QAlogs *temp,int low,int high, int mid)
{   

    //Base case - When it only has one structure in the array
    if(high <= low)
    {   
        return (products + low) -> product_id;
    }
    else
    {
        //Calculates the mid of the array of structures and rounds down
        mid = floor((low+high)/2);
        Merge_sort(products,temp,low,mid,mid);
        Merge_sort(products,temp,mid+1,high, mid);
        Merge(products,temp,low,mid,high);

    }//End if

    return 0;

}


//Merge function
//Puts the structures in the correct order of product ID and line ID
int Merge(struct QAlogs *products,struct QAlogs *tempA,int low,int mid,int high)
{   
    int i;
    int left = low;
    int right = mid + 1;
    int temp = left;

    while(left <= mid && right <= high)//Runs while there is still items in both arrays
    {
        if((products+left) -> product_id < (products+right) -> product_id)//Product ID check
        {
            *(tempA + temp++) = *(products+left++);
        }
        else if((products+left) -> product_id == (products+right) -> product_id)
        {
            if((products +left) -> line_code <= (products +right) -> line_code)//Line id check
            {
                *(tempA +temp++) = *(products+left++);

            }
            else
            {
                *(tempA+temp++) = *(products+right++);
            }//End line ID check
        }
        else
        {
            *(tempA + temp++) = *(products+right++);
        }//End product ID Check

    }//end while

    //If nothing is left in left array
    if (left>mid)
    {
        while(right<=high)
        {
            *(tempA+temp++) = *(products+right++);
        }
    }
    else//If nothing is left in right array
    {
        while(left<=mid)
        {
            *(tempA+temp++) =  *(products+left++);
        }
    }

    //Copies all the structures back into the original structure array in the correct order
    for (i = low; i <= high; i++)
    {
        *(products + i) = *(tempA + i);
    }
    return 0;

}

//Summary function - counts how many issues have occurred for a product
int summary(struct QAlogs *products,int high)
{
    int i;
    int count = 0;
    int j = 0;

    //Loops through all the product IDS' in the list
    for(i=0;i<= high;i++)
    {  

        //If the product ID is equal to the product ID we are on adds one to count
        if((products + i) -> product_id == (products + j) -> product_id)
        {
            count = count + 1;
        }
        else//If not equal means we are on a new product id
        {
            //Outputs the number of issues for that product ID
            printf("\n%7.d %15.d\n", (products+j) -> product_id,count);
            //Sets count to one as we have found one issue already for the new product id
            count = 1;
            //Sets j to the new product id
            j = i;
        }
    }

    //Outputs the final product id
    printf("\n%7.d %15.d\n", (products+j) -> product_id,count);

    return 0;
}

