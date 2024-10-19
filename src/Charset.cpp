#include<Charset.h>

void Charset::setListener(listener l){
    Charset::listenerFunc = l;
}
void Charset::processCharset(int pX, int pY, int padding, std::vector<std::vector<int>>& arr) {
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 5; y++){
            if(arr[y][x] != 0){
                if (listenerFunc) {
                    listenerFunc(x + padding + pX, y + pY);
                }
            }
        }
    }
}
void Charset::drawText(int pX, int pY, string text){
    int startPadding = 0;
    for (int i = 0; i < text.size(); i++)
    {
        char sign = text[i];
        
        switch (sign)
        {
        case '0':
            processCharset(pX, pY, startPadding, zero);
            break;
        case '1':
            processCharset(pX, pY, startPadding, one);
            startPadding--;
            break;
        case '2':
            processCharset(pX, pY, startPadding, two);
            break;
        case '3':
            processCharset(pX, pY, startPadding, three);
            break;
        case '4':
            processCharset(pX, pY, startPadding, four);
            break;
        case '5':
            processCharset(pX, pY, startPadding, five);
            break;
        case '6':
            processCharset(pX, pY, startPadding, six);
            break;
        case '7':
            processCharset(pX, pY, startPadding, seven);
            break;
        case '8':
            processCharset(pX, pY, startPadding, eight);
            break;
        case '9':
            processCharset(pX, pY, startPadding, nine);
            break;
        case 'x':
            processCharset(pX, pY, startPadding, char_x);
            break;
        case 'y':
            processCharset(pX, pY, startPadding, char_y);
            break;
        case 'i':
            processCharset(pX, pY, startPadding, char_i);
            break;
        case ' ':
            startPadding-= 3;
            break;
        case '.':
            if (startPadding != 0) startPadding--;
            processCharset(pX, pY, startPadding, char_point);
            startPadding--;
            break;
        case ':':
            if (startPadding != 0) startPadding--;
            processCharset(pX, pY, startPadding, char_double_points);
            startPadding--;
            break;
        default: break;
        }
        startPadding += 4;
    }

}