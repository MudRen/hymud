 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @long
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï
�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ
�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
long
        );
        set("exits", ([ 
  "east" :__DIR__"alou",
  //"east" : __DIR__"yuan1",
  //"west" : __DIR__"shulin1",
  "west" : __DIR__"tolou4",
  
]));
        set("outdoors", "shanxi");
        set("coor/x",-480);
        set("coor/y",-270);
        set("coor/z",100);
        setup();
}
/*
void init()
{
        add_action("do_go","go"); 
} 
int do_go()
{
if(random(10)){
this_player()->move(this_object());
return 1;
}
} */  
