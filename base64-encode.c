void base64_encode(char *buffer, unsigned char* chsrc, uint32_t len, bool head)
{
    const char *base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    unsigned char char_array_3[3], char_array_4[4];
    int i = 0, j = 0, k = 0;
    unsigned char chdes1[65];
    unsigned char *chdes = chdes1;
    bool flag = true;
    uint32_t l = 0;

    while(len--)
    {
        if(head){
            char_array_3[i++] = chsrc[l++];
        }
        else{
            if(flag){
                char_array_3[i++] = chsrc[l+1];
                flag = false;
            } else {
                char_array_3[i++] = chsrc[l];
                l+=2;
                flag = true;
            }
        }
        if(3 == i)
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;
            for(i = 0; i < 4; i++){
                chdes[k++] = base64_chars[char_array_4[i]];
            }

            i = 0;
            if(k==60){
                // write to buffer
                k = 0;
            }
        }
    }
    if(i)
    {
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for(j = 0; j < (i+1); j++){
            chdes[k++] = base64_chars[char_array_4[j]];
        }

        while((3 > i++)){
            chdes[k++] = '=';
        }
    }
    // write to buffer
    return;
}
