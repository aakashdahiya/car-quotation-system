//  module 1- Choosing the brand
//  module 2- Choosing the specs. of the car
//  module 3- Calculating the price by getting car info like purchase date and car condition
//  module 4- Storing users info like name and mobile

// Limitation 1 - A specific brand can only have 25 cars at max
// Limitation 2 - The user will be shown car names in module 2, instede of putting in the car name by themself

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define max_len 50
#define current_year 2023

// Global Variable --> Ending with g
int basepriceg;              // constantily changing
char userbrandg[max_len];    // Brand of user's car
int brandidg;                // helps to identify the brand in module 2 (only for bkend)
char usercarg[max_len];      // Name of user's car
char usercarcolorg[max_len]; // color of users car
int usercaryear;
int usesrownertypeg; // Filling it with the type of owner like first owner or second
float km_driven;
// user details - Name and Mobile

char usernameg[max_len];
char usercity[max_len];
long long int usermobileg;

// struct names starting with z

struct cardetails
{
    char z_brandname[max_len];
    char z_carname[max_len];
    float z_carkilometers;
    char z_carcolor[max_len];
    int z_caryear;   // registration year
    int z_ownertype; // type of owner 1st owner and like second error
    int z_carprice;  // calculated price
};

struct cardetails car[max_len];
int carCount = 0;

// Below structure will store the user personal details
struct userdetails
{
    char z_username[max_len];
    char z_usercity[max_len];
    long long int z_usermobile;
};

struct userdetails user[max_len];

void moduleStoringData()
{
    carCount--;

    FILE *fptr;
    fptr = fopen("car_data.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fptr, "%s %s %s %d %d %d %f\n", car[carCount].z_brandname, car[carCount].z_carname, car[carCount].z_carcolor, car[carCount].z_caryear, car[carCount].z_ownertype, car[carCount].z_carprice, car[carCount].z_carkilometers);

    // Close the file
    fclose(fptr);

    FILE *fptr2;
    fptr2 = fopen("user_data.txt", "a");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fptr, "%s %s %lld\n", user[carCount].z_username, user[carCount].z_usercity, user[carCount].z_usermobile);

    // Close the file
    fclose(fptr2);
}

int combinedCount = 0; // This index will be used to reterive the data of the user respective to their car details

void menuchoice();

void invalindInput()
{
    printf("\033[0;91m");
    printf("\n+--------------------+");
    printf("\n|  INVALID INPUT :/  |");
    printf("\n+  TRY AGAIN --------+");
    printf("\033[0m");
}

void statementAnswerCarQestion()
{
    system("clear");
    printf("\033[0;93m");
    printf("\n+----------------------------------------------------------------------+");
    printf("\n| PLEASE ANSWER A FEW QUESTIONS TO GET THE BEST PRICE FOR YOUR OLD CAR |");
    printf("\n+----------------------------------------------------------------------+");
    printf("\033[0m");
}

void module1() // choosing the users car brand
{

    char userbrand[max_len];
    char *carbrands[] = {
        "mahindra",
        "hyundai",
        "maruti",
        "tata",
        "audi",
        "bmw",
        "kia",
        "land_rover",
        "honda",
        "renault",
        "mg",
        "datsun",
        "jeep",
        "nissan",
        "ford",
        "skoda",
        "volvo",
        "porsche"};
    int lenth_of_brand = sizeof(carbrands) / sizeof(carbrands[0]); // counting no of brands

    printf("\n+---------------------------------+");
    printf("\n| PLEASE ENTER YOUR CAR BRAND:  -> ");
    scanf("%s", userbrand);

    for (int i = 0; i < lenth_of_brand; i++)
    {
        if (strcmp(userbrand, carbrands[i]) == 0)
        {
            strcpy(userbrandg, userbrand);
            brandidg = i + 1;
            break;
        }
        if (i == lenth_of_brand - 1)
        {
            system("clear");
            printf("\n-------------------------------------------+");
            printf("\n|  WE DEAL ONLY IN THESE FOLLOWING BRANDS  |");
            printf("\n+------------------------------------------+\n");
            for (int j = 0; j < lenth_of_brand; j++)
            {
                printf("\nPress -> [%d] for %s", j + 1, carbrands[j]);
            }
            printf("\n\nType -> 99 to EXIT\n");

            int user_choice;

            while (user_choice != 99)
            {
                while (1)
                {
                    printf("\n\n Re-enter a valid value: ");
                    scanf("%d", &user_choice);

                    if (user_choice >= 1 && user_choice <= lenth_of_brand)
                    {
                        strcpy(userbrandg, carbrands[user_choice - 1]);
                        brandidg = user_choice;
                        break;
                    }
                    else if (user_choice == 99)
                    {
                        printf("Initiating Exit");
                        break;
                    }
                    else
                    {
                        invalindInput();
                    }
                }

                break;
            }
        }
    }
    // system("clear");
}

void module2() // choosing users car
{
    //     mahindra ID  -1
    //     hyundai  ID  -2
    //     maruti   ID  -3
    //     tata     ID  -4
    //     audi     ID  -5
    //     bmw      ID  -6

    // In the array of cars respectice to there brands their base price is also mentioned
    // like at index even eg(inxed 0) like sorpio & on odd index their base price

    char usercar[max_len];
    char *access_array[max_len];
    int lengthofbrand;
    int userchoice;

    // printf("\nPlease enter your car name: ");
    // scanf("%s", &usercar);
    // printf("\n Car selected is: %s\n", usercar);

    char *mahindracars[] = {
        "Scorpio",
        "1500000",
        "Bolero",
        "700000",
        "Scorpio_N",
        "2200000",
        "XUV_700",
        "2500000",
        "XUV_300",
        "700000",
        "Thar",
        "17000000"};
    char *hyundaicars[] = {
        "Creta",
        "2000000",
        "Verna",
        "1700000",
        "Venue",
        "1500000",
        "i_10",
        "7000000",
        "i_20",
        "1000000"};
    char *maruticars[] = {
        "Swift",
        "900000",
        "Wagonar",
        "700000",
        "Claz",
        "1200000",
        "Celerio",
        "600000"};
    char *tatacars[] = {
        "Nexon",
        "1500000",
        "Harrier",
        "2200000",
        "Safari",
        "2300000",
        "Punch",
        "800000",
        "Tiago",
        "900000"};
    char *audicars[] = {
        "A3",
        "3500000",
        "A4",
        "4000000",
        "A6",
        "5000000",
        "A8",
        "6000000",
        "Q3",
        "3500000",
        "Q6",
        "5000000"};
    char *bmwcars[] = {
        "X3",
        "420000",
        "X5",
        "580000",
        "X6",
        "650000",
        "Series_3",
        "4300000",
        "Series_5",
        "7000000"};
    char *kiacars[] = {
        "seltos",
        "2200000",
        "sonnet",
        "1000000",
        "carnival",
        "3500000"};
    char *landrovercars[] = {
        "Range_Rover_Evoque",
        "8000000",
        "Range_Rover_Sports",
        "12500000",
        "Defender",
        "16000000"};

    char *hondacars[] = {
        "Amaze",
        "1200000",
        "city",
        "1400000",
        "Civic",
        "2600000",
        "jazz",
        "900000"};

    char *renaultcars[] = {
        "triber",
        "730000",
        "Kwid",
        "600000",
        "Duster",
        "1400000"};

    char *mgcars[] = {
        "Hector",
        "1900000",
        "ZS EV",
        "2450000",
        "Hector Plus",
        "2100000"};

    char *datsuncars[] = {
        "Go plus",
        "700000",
        "Go",
        "500000",
        "Reddi Go",
        "400000"};

    char *jeep[] = {
        "Compass",
        "2500000",
        "Compass Trailhawk",
        "3200000",
        "Grand Cherokee",
        "8000000",
        "Wrangler",
        "7000000"};

    char *nissan[] = {
        "Kicks",
        "1419000",
        "GTR",
        "20000000"};

    char *ford[] = {
        "EcoSport",
        "1180000",
        "Aspire",
        "871000",
        "Endeavour",
        "3800000",
        "Freestyle",
        "886000"};

    char *skoda[] = {
        "Rapid",
        "1180000",
        "Ocatavia",
        "3600000",
        "Karoq",
        "2500000"};

    char *volvo[] = {
        "XC_60",
        "5990000",
        "XC_90",
        "15000000",
        "XC_40",
        "4000000"};

    char *porsche[] = {
        "911",
        "30800000",
        "Cayenne",
        "19800000",
        "Macan",
        "8500000"};

    char *volkswagencars[] = {
        "Polo",
        "974000",
        "vento",
        "1346000",
        "T_Roc",
        "1900000",
        "Virtus",
        "1850000"};

    int brandid = brandidg;
    switch (brandid)
    {

    case 1:
        lengthofbrand = sizeof(mahindracars) / sizeof(mahindracars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = mahindracars[i];
        }
        break;
    case 2:
        lengthofbrand = sizeof(hyundaicars) / sizeof(hyundaicars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = hyundaicars[i];
        }
        break;
    case 3:
        lengthofbrand = sizeof(maruticars) / sizeof(maruticars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = maruticars[i];
        }
        break;
    case 4:
        lengthofbrand = sizeof(tatacars) / sizeof(tatacars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = tatacars[i];
        }
        break;
    case 5:
        lengthofbrand = sizeof(audicars) / sizeof(audicars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = audicars[i];
        }
        break;
    case 6:
        lengthofbrand = sizeof(bmwcars) / sizeof(bmwcars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = bmwcars[i];
        }
        break;
    case 7:
        lengthofbrand = sizeof(kiacars) / sizeof(kiacars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = kiacars[i];
        }
        break;
    case 8:
        lengthofbrand = sizeof(landrovercars) / sizeof(landrovercars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = landrovercars[i];
        }
        break;
    case 9:
        lengthofbrand = sizeof(hondacars) / sizeof(hondacars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = hondacars[i];
        }
        break;
    case 10:
        lengthofbrand = sizeof(renaultcars) / sizeof(renaultcars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = renaultcars[i];
        }
        break;
    case 11:
        lengthofbrand = sizeof(mgcars) / sizeof(mgcars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = mgcars[i];
        }
        break;
    case 12:
        lengthofbrand = sizeof(datsuncars) / sizeof(datsuncars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = datsuncars[i];
        }
        break;
    case 13:
        lengthofbrand = sizeof(jeep) / sizeof(jeep[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = jeep[i];
        }
        break;
    case 14:
        lengthofbrand = sizeof(nissan) / sizeof(nissan[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = nissan[i];
        }
        break;
    case 15:
        lengthofbrand = sizeof(ford) / sizeof(ford[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = ford[i];
        }
        break;
    case 16:
        lengthofbrand = sizeof(skoda) / sizeof(skoda[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = skoda[i];
        }
        break;

    case 17:
        lengthofbrand = sizeof(volvo) / sizeof(volvo[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = volvo[i];
        }
        break;
    case 18:
        lengthofbrand = sizeof(porsche) / sizeof(porsche[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = porsche[i];
        }
        break;
    case 19:
        lengthofbrand = sizeof(volkswagencars) / sizeof(volkswagencars[0]);
        for (int i = 0; i < lengthofbrand; i++)
        {
            access_array[i] = volkswagencars[i];
        }
        break;

    default:
        printf("\n Error: Could not find brand");
        break;
    }

    printf("\n+-------------------------------------+");
    printf("\n|   SELECT YOUR CAR FROM BELOW LIST   |");
    printf("\n+-------------------------------------+\n");

    int max_width = 0;
    for (int i = 0; i < lengthofbrand; i += 2)
    {
        int width = strlen(access_array[i]);
        if (width > max_width)
        {
            max_width = width;
        }
    }

    printf("\n+-----------------------------------------+");
    for (int i = 0; i < lengthofbrand; i += 2)
    {
        printf("\n|     Press -> [%d] for %s %-*s     |", i + 1, userbrandg, max_width, access_array[i]);
    }
    printf("\n+-----------------------------------------+");

    printf("\nTo exit (Press-99)\n");

    while (1)
    {
        printf("\n\nPLEASE ENTER YOUR CHOICE: ");
        scanf("%d", &userchoice);
        if (userchoice % 2 != 0 && userchoice <= lengthofbrand)
        {
            strcpy(usercarg, access_array[userchoice - 1]);
            basepriceg = atoi(access_array[userchoice]);
            // printf("\nBase price of your car is: %d", basepriceg);
            break;
        }
        else if (userchoice == 99)
        {
            printf("Inititating Exit Values");
            break;
        }
        else
        {
            invalindInput();
        }
    }
}

// Starting module 3 - The user will choose his car conditions based on which final price will be calculated
void module3()
{
    int registery_year;         // year in which the car was bought
    int age_of_car_years;       // 2023-registery_year
    int baseprice = basepriceg; // The will be the duplicate of the global variable basepriceg

    statementAnswerCarQestion();
    while (1)
    {
        printf("\n\nEnter your car REGESTRATION YEAR (EG. 2019): ");
        scanf("%d", &registery_year);
        if (registery_year < 1995 || registery_year > 2023)
        {
            invalindInput();
        }
        else
        {
            usercaryear = registery_year;
            break;
        }
    }
    statementAnswerCarQestion();
    while (1)
    {
        printf("\n\nEnter KILOMETERS DRIVEN till now: ");
        scanf("%f", &km_driven);
        if (km_driven > 199999)
        {
            invalindInput();
        }
        else
            break;
    }

    // system("clear");
    statementAnswerCarQestion();
    printf("\n\nPlease enter the COLOR of your car: ");
    scanf("%s", usercarcolorg);

    statementAnswerCarQestion();
    while (1)
    {
        printf("\n\n+-------------------------------------------------------------------+");
        printf("\n|  Please enter the number corresponding to the CURRENT OWNER TYPE  |");
        printf("\n|  First Owner type -> [1] Second Owner type -> [2] and so on ...   |");
        printf("\n+-------------------------------------------------------------------+");

        printf("\n\nTYPE HERE (1,2,3,4,5): ");
        scanf("%d", &usesrownertypeg);

        if (usesrownertypeg > 5 || usesrownertypeg <= 0)
        {
            system("clear");
            invalindInput();
            continue;
        }
        else
            break;
    }

    age_of_car_years = current_year - registery_year;

    // manipulating price of car according to the age of car in months
    if (age_of_car_years >= 0 && age_of_car_years < 1)
    {
        basepriceg = basepriceg - (7.0 / 100 * basepriceg);
        // basepriceg = basepriceg - (7.0 / basepriceg * 100);
    }
    else if (age_of_car_years >= 1 && age_of_car_years < 2)
    {
        basepriceg = basepriceg - (15.0 / 100 * basepriceg);
    }
    else if (age_of_car_years >= 2 && age_of_car_years < 3)
    {
        basepriceg = basepriceg - (20.0 / 100 * basepriceg);
    }
    else if (age_of_car_years >= 3 && age_of_car_years < 4)
    {
        basepriceg = basepriceg - (28.0 / 100 * basepriceg);
    }
    else if (age_of_car_years >= 4 && age_of_car_years < 5)
    {
        basepriceg = basepriceg - (40.0 / 100 * basepriceg);
    }
    else if (age_of_car_years >= 5 && age_of_car_years < 6)
    {
        basepriceg = basepriceg - (50.0 / 100 * basepriceg);
    }
    else
    {
        basepriceg = basepriceg - (75.0 / 100 * basepriceg);
    }

    // manipulating bp according to kms driven
    if (km_driven >= 0 && km_driven < 5000) // a+=1 ; a=a+1
    {
        basepriceg = basepriceg - (5.0 / 100 * basepriceg);
    }
    else if (km_driven >= 5000 && km_driven < 10000)
    {
        basepriceg = basepriceg - (10.0 / 100 * basepriceg);
    }
    else if (km_driven >= 10000 && km_driven < 20000)
    {
        basepriceg = basepriceg - (20.0 / 100 * basepriceg);
    }
    else if (km_driven >= 20000 && km_driven < 30000)
    {
        basepriceg = basepriceg - (25.0 / 100 * basepriceg);
    }
    else if (km_driven >= 30000 && km_driven < 50000)
    {
        basepriceg = basepriceg - (35.0 / 100 * basepriceg);
    }
    else if (km_driven >= 50000 && km_driven < 75000)
    {
        basepriceg = basepriceg - (45.0 / 100 * basepriceg);
    }
    else
    {
        basepriceg = basepriceg - (55.0 / 100 * basepriceg);
    }

    basepriceg = basepriceg - (usesrownertypeg * 1.5 / 100 * basepriceg);
}

void module4() // collecting user info
{
    system("clear");
    int inn = 0;
    printf("\n\033[0;93m+------------------------+");
    printf("\n|  YOU ARE ALMOST THERE  |");
    printf("\n+------------------------+\n\033[0m");

    int tempMobile;
    printf("\n\nEnter your mobile no: +91 ");
    scanf("%lld", &usermobileg);

    while (1)
    {
        if (usermobileg / 1000000000LL > 0 && usermobileg / 1000000000LL < 10)
        {
            break;
        }

        else
        {
            invalindInput();
            printf("\n\nPlease enter a correct 10 digit number: ");
            scanf("%lld", &usermobileg);
            continue;
        }
    }

    printf("\nPlease enter your name: ");
    scanf("%s", usernameg);

    printf("\nPlease enter your city: ");
    scanf("%s", usercity);

    system("clear");

    char anim[48] = {'|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\', '|', '/', '-', '\\'};
    printf("\n");
    for (int i = 0; i < 48; i++)
    {
        printf("\rCALCULATING YOUR CAR PRICE %c                                                   ", anim[i]);
        fflush(stdout);
        usleep(100000);
    }

    // Print the final price in light blue color

    char carPriceAnimation[100];
    sprintf(carPriceAnimation, "\033[1;36m Your %s %s is valued at: ₹%d", userbrandg, usercarg, basepriceg);

    // char *carPriceAnimation = ("Your %s %s is valued at: ₹%d", userbrandg, usercarg, basepriceg);

    printf("\n\n+-------------------------------------------------------+\n");
    int delay = 50000; // microseconds

    for (int i = 0; i < strlen(carPriceAnimation); i++)
    {
        printf("%c", carPriceAnimation[i]);
        fflush(stdout);
        usleep(delay);
    }

    // printf("\n\033[1;34m\nYour %s %s is valued at: ₹%d\033[0m\n", userbrandg, usercarg, basepriceg);
    printf("\n\033[0;37m+-------------------------------------------------------+");

    usleep(250000);

    while (1)
    {
        int userans;
        printf("\n\n\033[4;33m Would you like you sell your car at this price?:\033[0m  ");
        printf("\n\n+------------------------+");
        printf("\n|  Press -> [1] for Yes  |");
        printf("\n|  Press -> [0] for No   |");
        printf("\n+------------------------+");

        printf("\nEnter your choice: ");
        scanf("%d", &userans);

        if (userans == 1)
        {
            // storing car details in user array
            strcpy(car[carCount].z_brandname, userbrandg);
            strcpy(car[carCount].z_carname, usercarg);
            strcpy(car[carCount].z_carcolor, usercarcolorg);
            car[carCount].z_caryear = usercaryear;
            car[carCount].z_ownertype = usesrownertypeg;
            car[carCount].z_carprice = basepriceg;
            car[carCount].z_carkilometers = km_driven;

            // storing user details in user array
            char presstocontine[max_len];
            strcpy(user[carCount].z_username, usernameg);
            strcpy(user[carCount].z_usercity, usercity);

            user[carCount].z_usermobile = usermobileg;

            carCount++;

            moduleStoringData();

            system("clear");
            printf("\n\n+---------------------------------------------------+");
            printf("\033[0;92m");
            printf("\n|  THANKS FOR YOUR TIME WE WILL CONTACT YOU SHORTLY  |");
            printf("\033[0m");
            printf("\n+----------------------------------------------------+");

            char message[] = "\n\nRedirecting to the home page...";
            int len = sizeof(message) / sizeof(char);
            int animation_len = 5;

            printf("%s", message);

            for (int i = 0; i < animation_len; i++)
            {
                printf(".");
                fflush(stdout); // flush the buffer to display the animation in real-time
                sleep(1);
            }

            printf("\n");
            break;
        }
        else if (userans == 0)
        {
            system("clear");
            printf("\n\n+------------------------------------------+");
            printf("\033[0;92m");
            printf("\n|  THANKS FOR YOUR TIME! Have a nice day:)  |");
            printf("\033[0m");
            printf("\n+-------------------------------------------+");
            char message[] = "\n\nRedirecting to the home page...";
            int len = sizeof(message) / sizeof(char);
            int animation_len = 5;

            printf("%s", message);

            for (int i = 0; i < animation_len; i++)
            {
                printf(".");
                fflush(stdout); // flush the buffer to display the animation in real-time
                sleep(1);
            }

            printf("\n");
            break;
        }
        else
        {
            invalindInput();
        }
    }

    // fgets(userans, sizeof(userans), stdin);
    // // remove the newline character
    // strtok(userans, "\n");

    // strcpy(cars[carCount].make, "Toyota");
    //  strcpy(cars[carCount].model, "Camry");
    //  cars[carCount].year = 2019;
    //  strcpy(cars[carCount].owner, "John Doe");
    //  cars[carCount].price = 30000;

    // char z_brandname[max_len];
    // char z_carname[max_len];
    // char z_carcolor[max_len];
    // int z_caryear;   // registration year
    // int z_ownertype; // type of owner 1st owner and like second error
    // int z_carprice;  // calculated price
}

void moudle5()
{
    printf("\nPritnig all the records entered till now: \n");
    for (int i = 0; i < carCount; i++)
    {
        printf("\n[%d] Car Brand is %s", i, car[i].z_brandname);
        printf("\n[%d] Car name is %s ", i, car[i].z_carname);
        printf("\n[%d] is Car color is %s", i, car[i].z_carcolor);
        printf("\n[%d] is car year is %d", i, car[i].z_caryear);
        printf("\n[%d] is car owner is %d ", i, car[i].z_ownertype);
        printf("\n[%d] is car price is %d ", i, car[i].z_carprice);
    }
}

void userend()
{
    system("clear");
    printf("\n+----------------+");
    printf("\n|  Welcome User  |");
    printf("\n+----------------+");
    module1();
    system("clear");
    module2();
    module3();
    module4();
}

// declaring two structs with their respective array to read data from the file for the car and userdetails respectively

// to store car details
struct readcardetails
{
    char z_brandname[max_len];
    char z_carname[max_len];
    char z_carcolor[max_len];
    int z_caryear;   // registration year
    int z_ownertype; // type of owner 1st owner and like second error
    int z_carprice;  // calculated price
    float z_carkilometers;
};

struct readcardetails carRead[max_len];
int readCarCount = 0;

// to store user derails
struct showUserDataFromFile
{
    char username[max_len];
    char usercity[max_len];
    long long int usermobile;
};

struct showUserDataFromFile userReadArray[max_len];
int userReadCount = 0;

int count = 0; // common index for storing and reteriving user and car details

void readingCarFile()
{
    char c;

    FILE *fp;
    fp = fopen("car_data.txt", "r");

    while ((c = getc(fp)) != EOF)
    {
        if (c == '\n')
        {
            count++;
        }
    }

    fclose(fp);
    fp = fopen("car_data.txt", "r"); // Reopen the file for reading
    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%s %s %s %d %d %d %f",
               carRead[i].z_brandname,
               carRead[i].z_carname,
               carRead[i].z_carcolor,
               &carRead[i].z_caryear,
               &carRead[i].z_ownertype,
               &carRead[i].z_carprice,
               &carRead[i].z_carkilometers);
    }
    fclose(fp); // Close the file after reading
}

void readingUserFile()
{
    count = 0;
    char c;

    FILE *fp;
    fp = fopen("user_data.txt", "r");

    while ((c = getc(fp)) != EOF)
    {
        if (c == '\n')
        {
            count++;
        }
    }

    fclose(fp);
    fp = fopen("user_data.txt", "r"); // Reopen the file for reading
    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%s %s %lld",
               userReadArray[i].username,
               userReadArray[i].usercity,
               &userReadArray[i].usermobile);
    }
    fclose(fp); // Close the file after reading
}

void pressToContinue()
{
    char homecheck[max_len];
    printf("\n\nPress any key to go back to Home Page: ");
    scanf("%s", homecheck);
    // system("clear");
}

void displayCarData() // car
{

    printf("\033[0;92m");
    printf("\n%5s | %10s | %20s | %20s | %10s | %15s | %10s | %15s", "ID.", "Brand", "Car Name", "Kilometers Driven", "Color", "Make Year", "Owner Type", "Quotation\n");
    printf("\033[0m");
    for (int i = 0; i < count; i++)
    {
        printf("\n%5d | %10s | %20s | %20f | %10s | %15d | %10d | %15d", i + 1,
               carRead[i].z_brandname,
               carRead[i].z_carname,
               carRead[i].z_carkilometers,
               carRead[i].z_carcolor,
               carRead[i].z_caryear,
               carRead[i].z_ownertype,
               carRead[i].z_carprice);
    }
}

void displayUserData()
{

    printf("\033[0;92m");
    printf("\n%5s | %20s | %20s | %20s ", "ID.", "User Name", "User City", "Mobile No.\n");
    printf("\033[0m");
    for (int i = 0; i < count; i++)
    {
        printf("\n%5d | %20s | %20s | %20lld ", i + 1,
               userReadArray[i].username,
               userReadArray[i].usercity,
               userReadArray[i].usermobile);
    }
}

void adminShowingRecordOfSpecificBrand()
{
    while (1)
    {
        char checkBrand[max_len];
        printf("\nEnter the car brand you want to search: ");
        scanf("%s", checkBrand);
        int checkCount;
        int countMatches = 0;

        for (int i = 0; i <= count; i++)
        {
            if (strcmp(checkBrand, carRead[i].z_brandname) == 0)
            {
                countMatches++;
            }
        }
        if (countMatches > 0)
        {
            printf("\033[2K\r"); // Clear the last statement
            printf("\nTotal no of matcehs are %d\n", countMatches);

            printf("\033[0;92m");
            printf("\n%5s | %20s | %20s | %20s ", "ID.", "User Name", "Car Name", "Car Price\n");
            printf("\033[0m");

            for (int i = 0; i < count; i++)
            {
                if (strcmp(checkBrand, carRead[i].z_brandname) == 0)
                {
                    printf("\n%5d | %20s | %20s | %20d ", i + 1,
                           userReadArray[i].username, carRead[i].z_carname, carRead[i].z_carprice);
                }
            }
            char cont[max_len];
            printf("\n\nPress any key to Exit : ");
            scanf("%s", cont);
            system("clear");
            break;
        }
        else
        {
            printf("\nDesired Brand not found!");
            pressToContinue();
            break;
        }
    }
}

void showingRecoedByID()
{
    while (1)
    {
        printf("\nEnter the unique ID: ");
        int uniqueID;
        scanf("%d", &uniqueID);
        uniqueID--;
        if (uniqueID < count)
        {
            printf("\033[0;92m");
            printf("\n%10s | %10s | %10s | %20s | %10s ", "User Name", "Car Name", "Usesr Type", "User Mobile", "Car Price\n");
            printf("\033[0m");

            printf("\n%10s | %10s | %10d | %20lld | %10d ", userReadArray[uniqueID].username, carRead[uniqueID].z_carname, carRead[uniqueID].z_ownertype, userReadArray[uniqueID].usermobile, carRead[uniqueID].z_carprice);
            pressToContinue();
            break;
        }
        else
        {
            printf("Records of %d are not available", uniqueID);
            pressToContinue();
            break;
        }
    }
}

void showingCombinedRecord()
{
    displayCarData();
    printf("\n\n");
    displayUserData();
}

void adminend()
{
    system("clear");
    printf("\n\033[1;92m+-----------------+");
    printf("\n|  Welcome Admin  |");
    printf("\n+-----------------+\033[0m");

    printf("\n\n+--------------------------------------------------------------------+");
    printf("\n|  Press ->[1] to see all the Car records  --------------------------|");
    printf("\n|  Press ->[2] to see all the User records  -------------------------|");
    printf("\n|  Press ->[3] to see records of a Specific Brand -------------------|");
    printf("\n|  Press ->[4] to see car records by user ID ------------------------|");
    printf("\n|  Press ->[5] to see records of both the user and their cars -------|");
    printf("\n+--------------------------------------------------------------------+");
    printf("\nType 99 exit");

    int adminans;

    printf("\n\nEnter your choice: ");
    scanf("%d", &adminans);

    readingCarFile();
    readingUserFile();

    switch (adminans)
    {
    case 1:
        system("clear");
        printf("\n\n+-------------------------------+");
        printf("\n|  Showing all the car records  |");
        printf("\n+-------------------------------+\n");
        displayCarData();
        pressToContinue();
        break;
    case 2:
        system("clear");
        printf("\n\n+--------------------------------+");
        printf("\n|  Showing all the user records  |");
        printf("\n+--------------------------------+\n");
        displayUserData();
        pressToContinue();
        break;
    case 3:
        system("clear");
        printf("\n\n+------------------------------------------+");
        printf("\n|  Showing records of a specific car brand  |");
        printf("\n+-------------------------------------------+\n");
        adminShowingRecordOfSpecificBrand();
        break;
    case 4:
        system("clear");
        printf("\n\n+-------------------------------+");
        printf("\n|  Showing records by Uniqe ID  |");
        printf("\n+--------------------------------+\n");
        showingRecoedByID();
        break;
    case 5:
        system("clear");
        printf("\n\n+---------------------------------------------+");
        printf("\n|  Showing records by of Users with their cars |");
        printf("\n+----------------------------------------------+\n");
        showingCombinedRecord();
        pressToContinue();
        break;
    case 99:
        printf("\nExiting");
        break;
    default:
        printf("\nInvalid Input");
        break;
    }
}

void menuchoice()
{
    // system("clear");
    printf("\033[1;92m\n+----------------------------------+");
    printf("\n|  OLD CAR PRICE QUOTATION SYSTEM  |");
    printf("\n+----------------------------------+\033[0m");

    printf("\n\n+----------------------+");
    printf("\n|         MENU         |");
    printf("\n|----------------------|");
    printf("\n|  USER  PRESS -> [1]  |");
    printf("\n|  ADMIN PRESS -> [2]  |");
    printf("\n+----------------------+");

    printf("\n\nEnter your choice: ");
    int menuchoice;
    scanf("%d", &menuchoice);

    if (menuchoice == 1)
    {
        userend();
    }
    else if (menuchoice == 2)
    {
        adminend();
    }
    else
    {
        printf("\nInvalid Input\n Try again");
    }
}

int main()
{
    while (1)
    {
        system("clear");
        menuchoice();
    }
    return 0;
}
