void mx_printchar(char c);
void mx_printstr(const char *s);

static void draw_strings(int x_max, int y, int one_y, int one_x) {
        for (int i = 0; i < x_max; i++) {
            if (y % 2 == 0 && i == 0)
                mx_printchar('*');
            else if (y % 2 != 0 && i == 0)
                mx_printchar('+');
            if (i == one_x && y == one_y)
                mx_printchar('1');
            else
                mx_printchar('0');
            if (y % 2 == 0 && i + 1 == x_max)
                mx_printchar('*');
            else if (y % 2 != 0 && i + 1 == x_max)
                mx_printchar('+');
        }
}

static void draw_borders(int x_m) {
    for (int i = 0; i < x_m; i++) {
        if (x_m == 1)
            mx_printstr("<=>");
        else if (i == 0) {
                mx_printstr("<=");
                for (int j = 0; j < x_m - 2; j++) {
                    mx_printchar('-');
                }
            }
        else if (i == x_m - 2)
            mx_printchar('=');
        else if (i == x_m - 1)
            mx_printchar('>');
    }
}

void race00(int map_length, int map_width, int one_y, int one_x) {
    if (one_x >= 0 && one_x < map_width
     && one_y >= 0 && one_y < map_length
     && map_width > 0 && map_length > 0) {
        draw_borders(map_width);
        mx_printchar('\n');
            for (int i = 0; i < map_length; i++) {
                draw_strings(map_width, i, one_y, one_x);
                mx_printchar('\n');
            }
        draw_borders(map_width);
        mx_printchar('\n');
    }
}
