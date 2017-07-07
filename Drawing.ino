void comet() {
    for (int j = 0; j < NUMPIXELS; j++) {
        for (int i = 0 ; i < NUMPIXELS; i++) {
            if (i < j) {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            } else {
                pixels.setPixelColor(i, pixels.Color(
                        colors[3*i]*2,
                        colors[3*i+1]*2,
                        colors[3*i+2]*2));
            }
        }


        if (rotate) dna_rotate_LEDs();
        delay(delay_time);
        pixels.show();
    }

    for (int j = 0; j < NUMPIXELS; j++) {
        for (int i = 0 ; i < NUMPIXELS; i++) {
            if (i < j) {
                pixels.setPixelColor(i, pixels.Color(
                        colors[3*i]*2,
                        colors[3*i+1]*2,
                        colors[3*i+2]*2));
            } else {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            }
        }


        if (rotate) dna_rotate_LEDs();
        delay(delay_time);
        pixels.show();
    }
}

void one_two_blink() {
    for(int i = 0; i < NUMPIXELS; i++){
        if (i%2 == 0) {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        } else {
            pixels.setPixelColor(i, pixels.Color(
                colors[3*i],
                colors[3*i+1],
                colors[3*i+2]));
        }
    }

    if (rotate == 2) dna_rotate_LEDs();

    delay(delay_time);
    pixels.show();

    for(int i = 0; i < NUMPIXELS; i++){
        if (i%2 == 0) {

            pixels.setPixelColor(i, pixels.Color(
                colors[3*i],
                colors[3*i+1],
                colors[3*i+2]));
        } else {

            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
    }

    if (rotate == 2) dna_rotate_LEDs();

    delay(delay_time);
    pixels.show();
}

void single_blink() {
    for (int t = 0; t < NUMPIXELS; t++) {
        for (int i = 0; i < NUMPIXELS; i++) {
            if (i == t) {
                pixels.setPixelColor(i, pixels.Color(
                        colors[3*i],
                        colors[3*i+1],
                        colors[3*i+2]));
            } else {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            }
        }
        delay(delay_time);
        pixels.show();
    }

    for (int t = 0; t < NUMPIXELS; t++) {
        for (int i = 0; i < NUMPIXELS; i++) {
            if (i == t) {
                pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            } else {
                pixels.setPixelColor(i, pixels.Color(
                    colors[3*i],
                    colors[3*i+1],
                    colors[3*i+2]));
            }
        }

        delay(delay_time);
        pixels.show();
    }
}


void on_off_wave() {
    for (int divisor = 1; divisor < 32; divisor+=2) {
        for (int j = 0; j < NUMPIXELS; j++) {
            pixels.setPixelColor(j, pixels.Color(
                    colors[3*j]/divisor,
                    colors[3*j+1]/divisor,
                    colors[3*j+2]/divisor));
        }

        if (rotate == 2) dna_rotate_LEDs();

        delay(delay_time);
        pixels.show();
    }

    for (int divisor = 32; divisor > 1; divisor-=2) {
        for (int j = 0; j < NUMPIXELS; j++) {
            pixels.setPixelColor(j, pixels.Color(
                    colors[3*j]/divisor,
                    colors[3*j+1]/divisor,
                    colors[3*j+2]/divisor));
        }

        if (rotate == 2) dna_rotate_LEDs();

        delay(delay_time);
        pixels.show();
    }
}

uint8_t t_state[15] =  {7, 7, 7, 7, 4, 3, 2, 1, 0, 1, 2, 3, 4, 7, 7};
void gaussian_wave() {
    for (int i = 0; i < NUMPIXELS; i++) {

        for (int t = 0; t < 15; t++) {
            for (int pixel = 0; pixel < NUMPIXELS; pixel++) {
                pixels.setPixelColor(pixel, pixels.Color(
                            colors[3*i]>>t_state[(t + pixel) % 15],
                            colors[3*i+1]>>t_state[(t + pixel) % 15],
                            colors[3*i+2]>>t_state[(t + pixel) % 15]));
            }

            delay(delay_time);
            pixels.show();
        }

    }
}

void none() {
    for(int i = 0; i < NUMPIXELS; i++){
        pixels.setPixelColor(i, pixels.Color(
                                    colors[3*i],
                                    colors[3*i+1],
                                    colors[3*i+2]));
    }

    delay(delay_time);
    pixels.show();
}

void dna_rotate_LEDs() {
    for (int j = 0; j < 3; j++) {

        uint8_t start = colors[0];
        for (int i = 0; i < 3*NUMPIXELS; i++) {
            colors[i] = colors[i+1];
        }
        colors[3*NUMPIXELS - 1] = start;
    }
}

