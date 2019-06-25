/***
    FinalAssignment.c
    2015.7.18
    Takeru Kurokawa
***/

#include<stdio.h>
#include<stdlib.h>
#include<handy.h>
#include<time.h>

#define WIN 600

int main() {
  
  hgevent *event;
  int i;  //カウンタ変数
  int score = 100; //点数
  int fir; //親の数字
  int sec; //自分の数字
  int img1,img2,img3,img4; //画像
  int x,y; //マウスクリック時の座標格納用

  HgOpen(WIN,WIN);

  i = 0;
  while ( 1==1 ) {

    HgClear();

    //親の数字の乱数
    srand(time(NULL));
    fir = rand() % 13 + 1;
    
    img1 = HgImageLoad("background.jpg"); //背景
    HgImageDraw(0,0,img1);
    if ( fir % 3 == 0 ) {       //親の表になったトランプ画像
      img2 = HgImageLoad("heart.jpg"); 
    } else  if ( fir %4  == 1 ) {           
       img2 = HgImageLoad("diamond.jpg"); 
    } else  if ( fir % 2 == 0 ) {          
       img2 = HgImageLoad("spade.jpg");
    } else {                                 
       img2 = HgImageLoad("club.jpg");
    }
    HgImageDraw(260,400,img2);
    img3 = HgImageLoad("trumpBack.jpg"); //自分の伏せてあるトランプ画像
    HgImageDraw(260,200,img3);
    img4 = HgImageLoad("trumpSide.jpg"); //ラウンド数表示用画像
    HgImageDraw(10,520,img4);
    HgImageDraw(470,520,img4); //スコア表示用画像 


    HgSetFont(HG_T,40);  //"LOW"ボタンを表示
    HgSetFillColor(HG_WHITE);
    HgBoxFill(80,80,150,100,0);
    HgText(110,105,"LOW");
    
    HgBoxFill(370,80,150,100,0); //"HIGH"ボタンを表示
    HgText(393,105,"HIGH");

    if ( fir == 1 || fir == 11 || fir == 12 || fir == 13 ) { //親の数字を表示
      HgSetFont(HG_HI,30);
    } else {
      HgSetFont(HG_H,30);
    }
    if ( fir == 1 ) {
      HgText(285,440,"A");
    } else if ( fir == 11 ) {
      HgText(285,440,"J");
    } else if ( fir == 12 ) {
       HgText(285,440,"Q");
    } else if ( fir == 13 ) {
       HgText(285,440,"K");
    } else {
      HgText(285,440,"%d",fir);
    }
 
    HgSetFont(HG_H,10);  //"Round"を表示
    HgText(15,560,"Round");
    HgSetFont(HG_H,20); //回数を表示
    HgText(70,530,"%d回目",i+1);
    
    HgSetFont(HG_H,10);  //"Score"を表示
    HgText(475,560,"Score");
    if ( i == 0 ) {
       HgSetFont(HG_H,20);
       HgText(520,530,"0点");
    } else {
      HgSetFont(HG_H,20); //点数を表示
      HgText(520,530,"%d点",score);
    }

    //"HIGH"または"LOW"以外を選択時、もう一度クリックさせる
    HgSetEventMask(HG_MOUSE_DOWN);
    for ( ;; )  {
      event = HgEvent();
      x = event->x;
      y = event->y;
      if ( ( x>=80 && x<=230 && y>=80 && y<=180 ) || ( x>=370 && x<=520 && y>=80 && y<=180 ) ) break;
    }
    
    if ( fir % 3 == 0 ) {       //自分の表になったトランプ画像を表示
      img2 = HgImageLoad("heart.jpg"); 
    } else  if ( fir %4  == 1 ) {           
       img2 = HgImageLoad("diamond.jpg"); 
    } else  if ( fir % 2 == 0 ) {          
       img2 = HgImageLoad("spade.jpg");
    } else {                                 
       img2 = HgImageLoad("club.jpg");
    }
    HgImageDraw(260,200,img2);
    
   
    sec = rand() % 13 + 1;   //自分の数字を表示
    if ( sec == 1 || sec == 11 || sec == 12 || sec == 13 ) {
      HgSetFont(HG_HI,30);
    } else {
      HgSetFont(HG_H,30);
    } 
    if ( sec == 1 ) {
      HgText(285,240,"A");
    } else if ( sec == 11 ) {
       HgText(285,240,"J");
    } else if ( sec == 12 ) {
       HgText(285,240,"Q");
    } else if ( sec == 13 ) {
       HgText(285,240,"K");
    } else {
      HgText(285,240,"%d",sec);
    }
    

    
    if ( ( x>=80 && x<=230 ) && ( y>=80 && y<=180 ) ) { //"HIGH"を選択した場合
      if ( fir == sec ) {
	HgAlert(" DRAW! \n続けます","OK","",""); continue;
      } else if ( fir > sec ) {
	if ( i == 0 ) {
	  score = 100;
	  HgAlert("     YOU WIN !!\n現在%d点です\n続けます","OK","","",score);
	} else if ( !(i==0)) {
	  score = score  + 100 ;
	  HgAlert("       YOU WIN !!\n現在%d点です\n続けます","OK","","",score);
	}
      } else if ( fir < sec ) {
	if ( i == 0 ) {
	  HgAlert("       YOU LOSE...\n最終得点は0点です\n終了します","OK","",""); break;
	} else {
	  HgAlert("       YOU LOSE...\n最終得点は%dです\n終了します","OK","","",score); break;
	}
      }
    }
    
    
    
    if ( ( x>=370 && x<=520 ) && ( y>=80 && y<=180 ) ) { //"LOW"を選択した場合
      if ( fir == sec ) {
	HgAlert(" DRAW! \n続けます","OK","",""); continue;
      } else if ( fir < sec ) {
      if ( i ==0 ) {
	score = 100;
	HgAlert("       YOU WIN !!\n現在%d点です\n続けます","OK","","",score);
      } else if ( !(i ==0 ) ) {
	score = score + 100;
	HgAlert("       YOU WIN !!\n現在%d点です\n続けます","OK","","",score);
      }
      } else if ( fir > sec ) {
	if ( i== 0 ) {
	  HgAlert("       YOU LOSE...\n最終得点は0点です\n終了します","OK","",""); break;
	} else {
	  HgAlert("       YOU LOSE...\n最終得点は%d点です\n終了します","OK","","",score); break;
	}
      }
    }
    i++;
  }
	
  HgGetChar();
  HgClose();
  
  return 0;
  
}
