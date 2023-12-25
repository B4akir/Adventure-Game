int connectDoors(World *world, int r1, int r2, int door1, int door2, World *world2)
{

    Region *region0 = &regions[r1];
    Region *region1 = &regions[r2];


  
    Position temp;
    Position end;
    Position previous;

    int count = 0;

    temp.x =region0->doors[door1].x;
    temp.y = region0->doors[door1].y;

    end.x= region1->doors[door2].x;
    end.y= region1->doors[door2].y;


    previous = temp;

    while (temp.x!= end.x || temp.y != end.y)
    {
        /* step left */
        if ((abs((temp.x - 1) - end.x) < abs(temp.x - end.x)) && (world2->data[temp.y][temp.x-1] == ' '))
        {
            previous.x = temp.x;
            temp.x = temp.x - 1;
               world->data[temp.y][temp.x] = '=';

        /* step right */
        } else if ((abs((temp.x + 1) - end.x) < abs(temp.x - end.x)) && (world2->data[temp.y][temp.x + 1] == ' '))
        {
            previous.x = temp.x;
            temp.x = temp.x + 1;
               world->data[temp.y][temp.x] = '=';
        /* step down */
        } else if ((abs((temp.y + 1) - end.y) < abs(temp.y - end.y)) && (world2->data[temp.y + 1][temp.x]  == ' '))
        {
            previous.y = temp.y;
            temp.y = temp.y + 1;
               world->data[temp.y][temp.x] = '=';
        /* step up */
        } else if ((abs((temp.y - 1) - end.y) < abs(temp.y - end.y)) && (world2->data[temp.y - 1][temp.x]  == ' '))
        {
            previous.y = temp.y;
            temp.y = temp.y - 1;
               world->data[temp.y][temp.x] = '=';
        } else
        {
            if (count == 0)
            {
                temp = previous;
                count++;
                continue;
            }
            else
            {
                return 0;
            }
        }

     


    }

    return 1;
}
