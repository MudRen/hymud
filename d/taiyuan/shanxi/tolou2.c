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
  "northeast" :__DIR__"tolou3",
  //"east" : __DIR__"yuan1",
  //"west" : __DIR__"shulin1",
  "southwest" : __DIR__"tolou1",
  
]));
        set("outdoors", "shanxi");
set("coor/x",-490);
        set("coor/y",-300);
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
