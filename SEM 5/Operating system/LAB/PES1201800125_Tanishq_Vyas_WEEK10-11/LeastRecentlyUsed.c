#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int length;
    int num_frames;

    printf("Enter the length of the reference string : ");
    scanf("%d", &length);

    char ref_string[length*2];

    char hold;
    printf("Enter the Reference string : ");
    // scanf("%[^\n]%*c", ref_string);

    int reference_str[length];

    for (int i = 0; i < length; i++)
    {
        scanf("%d ", &reference_str[i]);
    }
    scanf("%c", &hold);
    scanf("%c", &hold);

    printf("Enter the Number of Frames : ");
    scanf("%d", &num_frames);
    

    int memory[num_frames];
    for (int i = 0; i < num_frames; i++)
    {
        memory[i] = -1;
    }
    


    // LRU
    int fault_count = 0;

    printf("\n\n The Page Replacement Process Is : \n");
    for (int i = 0; i < length; i++)
    {
        // Get Current Requested Page
        int cur_page = reference_str[i];
        int page_found = 0;

        // Look for page in memory
        for(int j = 0; j < num_frames; j++)
        {
            if(memory[j] == cur_page)
            {
                page_found = 1;
                break;
            }
        }


        // If page is not found
        if(!page_found)
        {
            // Increase Fault Count
            fault_count++;

            // Cached status : to check for any empty slot
            int is_cached = 0;

            // <-----------Cache the page --------------->
            for(int j = 0; j < num_frames; j++)
            {
                if(memory[j] == -1)
                {
                    memory[j] = cur_page;
                    break;
                }
            }

            // If no empty slot is found then remove the LRU page
            if(!is_cached)
            {
                int check_count = 0;
                int check_status[num_frames];
                for(int m = 0; m < num_frames; m++)
                {
                    check_status[m] = 0;
                }

                for(int cur = i-1; cur >= 0; cur--)
                {
                    int val = reference_str[cur];

                    for(int n= 0; n < num_frames; n++)
                    {
                        if(val == memory[n])
                        {
                            check_status[n] = 1;
                            check_count++;
                            break;
                        }
                    }

                    if(check_count == num_frames-1)
                        break;
                }


                // Put the page where check status = 0
                for(int cur = 0; cur < num_frames; cur++)
                {
                    if(check_status[cur] == 0)
                    {
                        memory[cur] = cur_page;
                        break;
                    }
                }
            }

            // Print the current Memory snap
            for(int j = 0; j < num_frames; j++)
            {
                printf("%d\t", memory[j]);
            }
            printf("\tPage Fault Num : %d\n", fault_count);

        }

        // When page is present in Cache
        else
        {
            // Print the current Memory snap
            for(int j = 0; j < num_frames; j++)
            {
                printf("%d\t", memory[j]);
            }
            printf("\n");
            
        }

    }

    printf("\n Total Page Faults : %d\n", fault_count);

    return 0;
}
