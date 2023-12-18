void connectRegions(World *world, Region *region, int r1, int r2, int door1, int door2) {
    Region *region0 = &regions[r1];
    Region *region1 = &regions[r2];

    Position start = region0->doors[door1];
    Position end = region1->doors[door2];

    while (start.x != end.x || start.y != end.y) {
        world->data[start.y][start.x] = '=';

        if (start.x < end.x)
            start.x++;
        else if (start.x > end.x)
            start.x--;

        if (start.y < end.y)
            start.y++;
        else if (start.y > end.y)
            start.y--;
    }
}