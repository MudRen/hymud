 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
string stone();
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
秘道在这里突然变宽变大，形成了一个巨大的石室，室内长满了各种千奇
百怪的钟乳石，在光线的照耀下闪烁着迷人的色彩，如果没有光线你很难从这
里绕出去。石室一角有一个巨大的白石，象一张天然的书桌。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"lmidao1",
  "north" : __DIR__"lmidao3",
  "northeast" : __DIR__"lmidao4",
]));
        set("item_desc", ([
                "stone" : (: stone :),
                "白石" : (: stone :),
        ]) );
        set("marks/finished", 0);
        set("coor/x",100);
        set("coor/y",12070);
        set("coor/z",0);
        setup();
} 
void init(){
   add_action("do_write", "write");
} 
string stone(){
        object me;
        me = this_player();
        if(query("marks/finished")){
                tell_object(me, "一块表面十分平滑的白石，上面平铺了一张宣纸，上面写了些字：\n\n"); 
                tell_object(me, "               楼外垂杨千万缕，\n");
                tell_object(me, "               欲系青春，少住春还去。\n");
                tell_object(me, "               犹自风前飘柳絮，随春且看归何处。\n\n");
                tell_object(me, "               绿满山川闻杜宇。\n");
                tell_object(me, "               便做无情，莫也愁人苦。\n");
           tell_object(me, "               把酒送春春不语，黄昏却下潇潇雨。\n\n");
                tell_object(me, "纸边摆着现成的笔墨。\n");
        } else {
                tell_object(me, "一块表面十分平滑的白石，上面平铺了一张宣纸，上面写了些字：\n\n"); 
                tell_object(me, "               楼外垂杨千万缕，\n");
                tell_object(me, "               欲系青春，少住春还去。\n");
                tell_object(me, "               犹自风前飘柳□，随春且看归何处。\n\n");
                tell_object(me, "               绿满山川闻杜宇。\n");
                tell_object(me, "               便做无情，莫也愁人苦。\n");
                tell_object(me, "               把酒送□□不语，黄昏却下潇潇雨。\n\n");
                tell_object(me, "其中似乎少了三个字，纸边摆着现成的笔墨。 \n");
        }
        return "";
}  
int do_write(string arg){
        object  me, room;
   
        me = this_player();
        if(query("marks/finished")){
      return 0;
        } else {
      if(!arg || (arg != "xu chun chun" && arg != "絮春春")) {
         return 0;
      }
      tell_object(me, "你略一沉吟，提笔在空格上填了几个字，又把笔放了下去。\n");
      message("vision", me->name()+"略一沉吟，从白石上提笔写了几个字，又把笔放了回去。\n",environment(me), me); 
      set("marks/finished",1);
      me->set_temp("marks/guest", 1);
      tell_object(me, "你只觉得后脑勺似乎被什么东西叮了一下。\n");
      me->unconcious();
      message("vision", "你只觉得眼前一花，似有一个人影掠过，"+ me->name() +"以失去了踪影。\n", environment(me),me);
      room = find_object("/d/qingping/shenshui/woshi2");
      if(!objectp(room)) room=load_object("/d/qingping/shenshui/woshi2");
      me->move(room);
   }
   return 1;
}   
void reset(){
        ::reset();
        if(query("marks/finished") == 365){
           set("marks/finished", 0);
        } else if(query("marks/finished") == 0) {
                return;
        } else {
                add("marks/finished", 1);
        }
}       
