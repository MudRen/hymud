 inherit ROOM;
void create()
{
  set("short","阳关大道");
  set("long",@LONG
这是一条东西大道，笔直宽阔，道旁是绿油油的麦田，
西边有一片果林，东边是一座山。这已是山东地界。
LONG
  );
  set("exits",([
         "east" :__DIR__"shanjiao",
         	"west" :"/d/laowu/road2",
               ])); 
        set("outdoors", "qianfo");
  set("coor/x",10);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
} 
