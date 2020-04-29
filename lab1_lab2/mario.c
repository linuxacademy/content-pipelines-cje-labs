#include <stdio.h>

void build_pyramid(int);

int main()
{
        int height;
        int integer_check;
        do
        {
            printf("Please enter an integer: ");
		        scanf("%d", &height);
        } while( (height < 1 ||  height > 40 ));
        
        build_pyramid(height);
        return 0;
}
void build_pyramid(int levels){
        char space = ' ';
        char hash = '#';
        
                //used to print # in multiples of 2 on each level
                int hash_multiplier = 1;
                while( levels > 0 )
                {
                        //Print spaces
                        for(int i = 1; i < levels; i++)
                        {
                                printf("%c",space);
                        }
                        //Print hashes - increase by multiples of 2(2 for loops) on each level
                        for(int j = 0; j<hash_multiplier;j++)
                        {
                                printf("%c",hash);
                        }

                        //Print single space
                        printf("%c%c",space,space);

                        //Keep printing hashes after single space
                        for(int j=0;j< hash_multiplier; j++)
                        {
                                printf("%c",hash);
                        }
                        //Print newline before continuing with next level of loop
                        printf("\n");
                        //Decreasing levels as printing pyramid lines
                        levels--;
                        //hash_multiplier increment
                        hash_multiplier++;
                }
        
}
