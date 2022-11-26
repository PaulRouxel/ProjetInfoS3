#include "header.h"

///FONCTION PERMETTANT DE CONVERTIR LES PIXELS (62;962) EN COORDONNEES (0,45)
int xPixeltoCoor(int xPixel) //pour traduire les pixels en coordonnes en X
{
    if((xPixel>=62)&&(xPixel<82)) //retourne la case en question
        return 0;
    else if((xPixel>=82)&&(xPixel<102))  //retourne la case en question
        return 1;
    else if((xPixel>=102)&&(xPixel<122))  //retourne la case en question
        return 2;
    else if((xPixel>=122)&&(xPixel<142))  //retourne la case en question
        return 3;
    else if((xPixel>=142)&&(xPixel<162))  //retourne la case en question
        return 4;
    else if((xPixel>=162)&&(xPixel<182))  //retourne la case en question
        return 5;
    else if((xPixel>=182)&&(xPixel<202))  //retourne la case en question
        return 6;
    else if((xPixel>=202)&&(xPixel<222))  //retourne la case en question
        return 7;
    else if((xPixel>=222)&&(xPixel<242)) //retourne la case en question
        return 8;
    else if((xPixel>=242)&&(xPixel<262))  //retourne la case en question
        return 9;
    else if((xPixel>=262)&&(xPixel<282))  //retourne la case en question
        return 10;
    else if((xPixel>=282)&&(xPixel<302))  //retourne la case en question
        return 11;
    else if((xPixel>=302)&&(xPixel<322))  //retourne la case en question
        return 12;
    else if((xPixel>=322)&&(xPixel<342))  //retourne la case en question
        return 13;
    else if((xPixel>=342)&&(xPixel<362))  //retourne la case en question
        return 14;
    else if((xPixel>=362)&&(xPixel<382))  //retourne la case en question
        return 15;
    else if((xPixel>=382)&&(xPixel<402))  //retourne la case en question
        return 16;
    else if((xPixel>=402)&&(xPixel<422))  //retourne la case en question
        return 17;
    else if((xPixel>=422)&&(xPixel<442))  //retourne la case en question
        return 18;
    else if((xPixel>=442)&&(xPixel<462))  //retourne la case en question
        return 19;
    else if((xPixel>=462)&&(xPixel<482))  //retourne la case en question
        return 20;
    else if((xPixel>=482)&&(xPixel<502))  //retourne la case en question
        return 21;
    else if((xPixel>=502)&&(xPixel<522))  //retourne la case en question
        return 22;
    else if((xPixel>=522)&&(xPixel<542)) //retourne la case en question
        return 23;
    else if((xPixel>=542)&&(xPixel<562))  //retourne la case en question
        return 24;
    else if((xPixel>=562)&&(xPixel<582))  //retourne la case en question
        return 25;
    else if((xPixel>=582)&&(xPixel<602))  //retourne la case en question
        return 26;
    else if((xPixel>=602)&&(xPixel<622))  //retourne la case en question
        return 27;
    else if((xPixel>=622)&&(xPixel<642))  //retourne la case en question
        return 28;
    else if((xPixel>=642)&&(xPixel<662))  //retourne la case en question
        return 29;
    else if((xPixel>=662)&&(xPixel<682))  //retourne la case en question
        return 30;
    else if((xPixel>=682)&&(xPixel<702))  //retourne la case en question
        return 31;
    else if((xPixel>=702)&&(xPixel<722))  //retourne la case en question
        return 32;
    else if((xPixel>=722)&&(xPixel<742))  //retourne la case en question
        return 33;
    else if((xPixel>=742)&&(xPixel<762))  //retourne la case en question
        return 34;
    else if((xPixel>=762)&&(xPixel<782))  //retourne la case en question
        return 35;
    else if((xPixel>=782)&&(xPixel<802))  //retourne la case en question
        return 36;
    else if((xPixel>=802)&&(xPixel<822))  //retourne la case en question
        return 37;
    else if((xPixel>=822)&&(xPixel<842)) //retourne la case en question
        return 38;
    else if((xPixel>=842)&&(xPixel<862))  //retourne la case en question
        return 39;
    else if((xPixel>=862)&&(xPixel<882))  //retourne la case en question
        return 40;
    else if((xPixel>=882)&&(xPixel<902))  //retourne la case en question
        return 41;
    else if((xPixel>=902)&&(xPixel<922))  //retourne la case en question
        return 42;
    else if((xPixel>=922)&&(xPixel<942))  //retourne la case en question
        return 43;
    else if((xPixel>=942)&&(xPixel<962))  //retourne la case en question
        return 44;

    else
    {
        return -1;
        allegro_message("error xPixeltoCoor");
    }

}

///FONCTION PERMETTANT DE CONVERTIR LES PIXELS (34;734) EN COORDONNEES (0;35)
int yPixeltoCoor(int yPixel)  //pour traduire les pixels en coordonnes en Y
{
    if((yPixel>=34)&&(yPixel<54))
        return 0;
    else if((yPixel>=54)&&(yPixel<74))  //retourne la case en question
        return 1;
    else if((yPixel>=74)&&(yPixel<94))  //retourne la case en question
        return 2;
    else if((yPixel>=94)&&(yPixel<114))  //retourne la case en question
        return 3;
    else if((yPixel>=114)&&(yPixel<134))  //retourne la case en question
        return 4;
    else if((yPixel>=134)&&(yPixel<154))  //retourne la case en question
        return 5;
    else if((yPixel>=154)&&(yPixel<174))  //retourne la case en question
        return 6;
    else if((yPixel>=174)&&(yPixel<194))  //retourne la case en question
        return 7;
    else if((yPixel>=194)&&(yPixel<214))  //retourne la case en question
        return 8;
    else if((yPixel>=214)&&(yPixel<234))  //retourne la case en question
        return 9;
    else if((yPixel>=234)&&(yPixel<254))  //retourne la case en question
        return 10;
    else if((yPixel>=254)&&(yPixel<274))  //retourne la case en question
        return 11;
    else if((yPixel>=274)&&(yPixel<294))  //retourne la case en question
        return 12;
    else if((yPixel>=294)&&(yPixel<314))  //retourne la case en question
        return 13;
    else if((yPixel>=314)&&(yPixel<334))  //retourne la case en question
        return 14;
    else if((yPixel>=334)&&(yPixel<354))  //retourne la case en question
        return 15;
    else if((yPixel>=354)&&(yPixel<374))  //retourne la case en question
        return 16;
    else if((yPixel>=374)&&(yPixel<394))  //retourne la case en question
        return 17;
    else if((yPixel>=394)&&(yPixel<414))  //retourne la case en question
        return 18;
    else if((yPixel>=414)&&(yPixel<434))  //retourne la case en question
        return 19;
    else if((yPixel>=434)&&(yPixel<454))  //retourne la case en question
        return 20;
    else if((yPixel>=454)&&(yPixel<474))  //retourne la case en question
        return 21;
    else if((yPixel>=474)&&(yPixel<494))  //retourne la case en question
        return 22;
    else if((yPixel>=494)&&(yPixel<514))  //retourne la case en question
        return 23;
    else if((yPixel>=514)&&(yPixel<534))  //retourne la case en question
        return 24;
    else if((yPixel>=534)&&(yPixel<554))  //retourne la case en question
        return 25;
    else if((yPixel>=554)&&(yPixel<574))  //retourne la case en question
        return 26;
    else if((yPixel>=574)&&(yPixel<594))  //retourne la case en question
        return 27;
    else if((yPixel>=594)&&(yPixel<614))  //retourne la case en question
        return 28;
    else if((yPixel>=614)&&(yPixel<634))  //retourne la case en question
        return 29;
    else if((yPixel>=634)&&(yPixel<654))  //retourne la case en question
        return 30;
    else if((yPixel>=654)&&(yPixel<674))  //retourne la case en question
        return 31;
    else if((yPixel>=674)&&(yPixel<694))  //retourne la case en question
        return 32;
    else if((yPixel>=694)&&(yPixel<714))  //retourne la case en question
        return 33;
    else if((yPixel>=714)&&(yPixel<734))  //retourne la case en question
        return 34;

    else
    {
        return 0;
        allegro_message("Error yPixeltoCoor");
    }
}

///FONCTION PERMETTANT DE CONVERTIR LES COORDONNEES (0,45) EN PIXELS (62,962)
int xCoortoPixel(int xCoor) //pour traduire les coordonnes en pixels en X
{
    if(xCoor==0)
        return 63;
    else if(xCoor==1)  //retourne la case en pixels
        return 83;
    else if(xCoor==2)  //retourne la case en pixels
        return 103;
    else if(xCoor==3)  //retourne la case en pixels
        return 123;
    else if(xCoor==4)  //retourne la case en pixels
        return 143;
    else if(xCoor==5)  //retourne la case en pixels
        return 163;
    else if(xCoor==6)  //retourne la case en pixels
        return 183;
    else if(xCoor==7)  //retourne la case en pixels
        return 203;
    else if(xCoor==8)
        return 223;
    else if(xCoor==9)  //retourne la case en pixels
        return 243;
    else if(xCoor==10)  //retourne la case en pixels
        return 263;
    else if(xCoor==11)  //retourne la case en pixels
        return 283;
    else if(xCoor==12)  //retourne la case en pixels
        return 303;
    else if(xCoor==13)  //retourne la case en pixels
        return 323;
    else if(xCoor==14)  //retourne la case en pixels
        return 343;
    else if(xCoor==15)  //retourne la case en pixels
        return 363;
    else if(xCoor==16)
        return 383;
    else if(xCoor==17)  //retourne la case en pixels
        return 403;
    else if(xCoor==18)  //retourne la case en pixels
        return 423;
    else if(xCoor==19)  //retourne la case en pixels
        return 443;
    else if(xCoor==20)  //retourne la case en pixels
        return 463;
    else if(xCoor==21)  //retourne la case en pixels
        return 483;
    else if(xCoor==22)  //retourne la case en pixels
        return 503;
    else if(xCoor==23)  //retourne la case en pixels
        return 523;
    else if(xCoor==24)
        return 543;
    else if(xCoor==25)  //retourne la case en pixels
        return 563;
    else if(xCoor==26)  //retourne la case en pixels
        return 583;
    else if(xCoor==27)  //retourne la case en pixels
        return 603;
    else if(xCoor==28)  //retourne la case en pixels
        return 623;
    else if(xCoor==29)  //retourne la case en pixels
        return 643;
    else if(xCoor==30)  //retourne la case en pixels
        return 663;
    else if(xCoor==31)  //retourne la case en pixels
        return 683;
    else if(xCoor==32)  //retourne la case en pixels
        return 703;
    else if(xCoor==33)  //retourne la case en pixels
        return 723;
    else if(xCoor==34)  //retourne la case en pixels
        return 743;
    else if(xCoor==35)  //retourne la case en pixels
        return 763;
    else if(xCoor==36)  //retourne la case en pixels
        return 783;
    else if(xCoor==37)  //retourne la case en pixels
        return 803;
    else if(xCoor==38)  //retourne la case en pixels
        return 823;
    else if(xCoor==39)  //retourne la case en pixels
        return 843;
    else if(xCoor==40)  //retourne la case en pixels
        return 863;
    else if(xCoor==41)  //retourne la case en pixels
        return 883;
    else if(xCoor==42)  //retourne la case en pixels
        return 903;
    else if(xCoor==43)  //retourne la case en pixels
        return 923;
    else if(xCoor==44)  //retourne la case en pixels
        return 943;

    else
    {
        return 0;
        allegro_message("Error xCoortoPixel");
    }
}

///FONCTION PERMETTANT DE CONVERTIR LES COORDONNEES (0,35) EN PIXELS (34,734)
int yCoortoPixel(int yCoor)  //pour traduire les coordonnes en pixels en Y
{

    if(yCoor==0)
        return 35;
    else if(yCoor==1)  //retourne la case en pixels
        return 55;
    else if(yCoor==2)  //retourne la case en pixels
        return 75;
    else if(yCoor==3)  //retourne la case en pixels
        return 95;
    else if(yCoor==4)  //retourne la case en pixels
        return 115;
    else if(yCoor==5)  //retourne la case en pixels
        return 135;
    else if(yCoor==6)  //retourne la case en pixels
        return 155;
    else if(yCoor==7)  //retourne la case en pixels
        return 175;
    else if(yCoor==8)  //retourne la case en pixels
        return 195;
    else if(yCoor==9)  //retourne la case en pixels
        return 215;
    else if(yCoor==10)  //retourne la case en pixels
        return 235;
    else if(yCoor==11)  //retourne la case en pixels
        return 255;
    else if(yCoor==12)  //retourne la case en pixels
        return 275;
    else if(yCoor==13)  //retourne la case en pixels
        return 295;
    else if(yCoor==14)  //retourne la case en pixels
        return 315;
    else if(yCoor==15)  //retourne la case en pixels
        return 335;
    else if(yCoor==16)
        return 355;
    else if(yCoor==17)  //retourne la case en pixels
        return 375;
    else if(yCoor==18)  //retourne la case en pixels
        return 395;
    else if(yCoor==19)  //retourne la case en pixels
        return 415;
    else if(yCoor==20)  //retourne la case en pixels
        return 435;
    else if(yCoor==21)  //retourne la case en pixels
        return 455;
    else if(yCoor==22)  //retourne la case en pixels
        return 475;
    else if(yCoor==23)  //retourne la case en pixels
        return 495;
    else if(yCoor==24)
        return 515;
    else if(yCoor==25)  //retourne la case en pixels
        return 535;
    else if(yCoor==26)  //retourne la case en pixels
        return 555;
    else if(yCoor==27)  //retourne la case en pixels
        return 575;
    else if(yCoor==28)  //retourne la case en pixels
        return 595;
    else if(yCoor==29)  //retourne la case en pixels
        return 615;
    else if(yCoor==30)  //retourne la case en pixels
        return 635;
    else if(yCoor==31)  //retourne la case en pixels
        return 655;
    else if(yCoor==32)  //retourne la case en pixels
        return 675;
    else if(yCoor==33)  //retourne la case en pixels
        return 695;
    else if(yCoor==34)  //retourne la case en pixels
        return 715;

    else
    {
        return 0;
        allegro_message("Error yCoortoPixel");
    }
}


