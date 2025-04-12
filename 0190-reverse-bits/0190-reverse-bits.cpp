class Solution {
private:
    unordered_map<uint8_t, uint8_t> look_up;
    uint8_t reverseByte(uint8_t n) {
        uint8_t modified_n = n;
        if (!look_up.count(n)) {
            uint8_t r = 0;
            for (int i = 0; i < 8; i++) {
                r = (r << 1) + (modified_n & 1);
                modified_n = modified_n >> 1;
            }
            look_up[n] = r;
        }
        return look_up[n];
    }
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        for (int i = 0; i < 4; i++) {
            uint8_t byte = (n >> 8*i) & 0b11111111;
            r = (r << 8) + reverseByte(byte);
        }
        return r;
    }
};
/*
get the right most bit of n: right_most
left shit r and add right_most to the r
right shift n

建立 look up table，8 bits 為一組，每次呼叫的時候都把 32 bits 拆成 4 組 8 bits，就可以查表，省去重複計算
*/