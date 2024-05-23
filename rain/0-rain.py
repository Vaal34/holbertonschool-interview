def rain(walls):
    ecart = 0
    wall1 = 0
    eau = 0

    for wall in walls:
        if(wall != 0):
            if wall1 != 0:
                if wall < wall1:
                    eau = eau + (wall * ecart)
                else:
                    eau = eau + (wall1 * ecart)
            wall1 = wall
            ecart = 0
        else:
            ecart += 1
    return eau