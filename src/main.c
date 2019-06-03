#include "../libs/lib_max/src/max.h"
#include "../libs/lib_avg/src/avg.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <getopt.h>
#include <vector>
#include <string>
#include <fstream>

char x86type[] = "/sys/class/thermal/thermal_zone10/type";
char x86temp[] = "/sys/class/thermal/thermal_zone10/temp";
char pchtype[] = "/sys/class/thermal/thermal_zone8/type";
char pchtemp[] = "/sys/class/thermal/thermal_zone8/temp";

void log_thermals(int timeout, char type[], char temp[]){
    FILE *f; 
    f=fopen(type,"rt"); 
    std::ofstream outfile ("log.txt");
    std::vector<int> vvv;
    std::string s="  ";
    char line[256];

    while (fgets(line, sizeof(line), f)) {
        printf("%s", line); 
        outfile << line << std::endl;
    }
    fclose(f);

    while(1){        
        f=fopen(temp,"rt");     
        while (fgets(line, sizeof(line), f)) {
        printf("%c%c°C\n", line[0],line[1]);
        }
        s[0]= line[0];
        s[1]= line[1];
        outfile << s << "°C" << std::endl;
        vvv.push_back(std::stoi(s));
        float av =avg(vvv);
        int mx = max(vvv);
        printf("max: %d°C, average: %.1f°C\n\n", mx,av);
        sleep(timeout); 
        fclose(f);
    }
}

int main(int argc, char **argv)
{
    int timeout = 1;
    int opt;
    while((opt = getopt(argc, argv, "t:m:")) != -1)  
    {  
        switch(opt)  
        {   
            case 't':  
                timeout = atoi(optarg); 
                break;  
            case 'm':  
                int mode = atoi(optarg);
                if(mode == 1) {
                    log_thermals(timeout, x86type, x86temp);
                } else if (mode == 2) {
                    log_thermals(timeout, pchtype, pchtemp);
                }
                break;
        }  
    }  
    return 0; 
} 