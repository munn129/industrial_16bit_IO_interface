/*
X#: input
Y#: output
*/

enum Port{
    PORT0 = 0,
    PORT1 = 1
};

enum IO_to_HW{
    ALL_LOW         = 0b00000000,
    LSB_ONE_HIGH    = (1 << 0),
    LSB_TWO_HIGH    = (1 << 1),
    LSB_THREE_HIGH  = (1 << 2),
    LSB_FOUR_HIGH   = (1 << 3),
    LSB_FIVE_HIGH   = (1 << 4),
    LSB_SIX_HIGH    = (1 << 5),
    LSB_SEVEN_HIGH  = (1 << 6),
    LSB_EIGHT_HIGH  = (1 << 7),
};

enum Input_from_HW{
    X0_HIGH     = (0 << 8) | LSB_ONE_HIGH,
    X1_HIGH     = (0 << 8) | LSB_TWO_HIGH,
    X2_HIGH     = (0 << 8) | LSB_THREE_HIGH,
    X3_HIGH     = (0 << 8) | LSB_FOUR_HIGH,
    X4_HIGH     = (0 << 8) | LSB_FIVE_HIGH,
    X5_HIGH     = (0 << 8) | LSB_SIX_HIGH,
    X6_HIGH     = (0 << 8) | LSB_SEVEN_HIGH,
    X7_HIGH     = (0 << 8) | LSB_EIGHT_HIGH,
    X8_HIGH     = (1 << 8) | LSB_ONE_HIGH,
    X9_HIGH     = (1 << 8) | LSB_TWO_HIGH,
    X10_HIGH    = (1 << 8) | LSB_THREE_HIGH,
    X11_HIGH    = (1 << 8) | LSB_FOUR_HIGH,
    X12_HIGH    = (1 << 8) | LSB_FIVE_HIGH,
    X13_HIGH    = (1 << 8) | LSB_SIX_HIGH,
    X14_HIGH    = (1 << 8) | LSB_SEVEN_HIGH,
    X15_HIGH    = (1 << 8) | LSB_EIGHT_HIGH
};

enum Output_to_HW{
    Y0_HIGH     = (0 << 8) | LSB_ONE_HIGH,
    Y1_HIGH     = (0 << 8) | LSB_TWO_HIGH,
    Y2_HIGH     = (0 << 8) | LSB_THREE_HIGH,
    Y3_HIGH     = (0 << 8) | LSB_FOUR_HIGH,
    Y4_HIGH     = (0 << 8) | LSB_FIVE_HIGH,
    Y5_HIGH     = (0 << 8) | LSB_SIX_HIGH,
    Y6_HIGH     = (0 << 8) | LSB_SEVEN_HIGH,
    Y7_HIGH     = (0 << 8) | LSB_EIGHT_HIGH,
    Y8_HIGH     = (1 << 8) | LSB_ONE_HIGH,
    Y9_HIGH     = (1 << 8) | LSB_TWO_HIGH,
    Y10_HIGH    = (1 << 8) | LSB_THREE_HIGH,
    Y11_HIGH    = (1 << 8) | LSB_FOUR_HIGH,
    Y12_HIGH    = (1 << 8) | LSB_FIVE_HIGH,
    Y13_HIGH    = (1 << 8) | LSB_SIX_HIGH,
    Y14_HIGH    = (1 << 8) | LSB_SEVEN_HIGH,
    Y15_HIGH    = (1 << 8) | LSB_EIGHT_HIGH
};
