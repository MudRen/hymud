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
  "north" :__DIR__"men",
  "east" : __DIR__"shulin",
  "west" : __DIR__"shulin",
  "south" : __DIR__"road",
  
]));
        set("outdoors", "shanxi");
        set("coor/x",-500);
        set("coor/y",-390);
        set("coor/z",100);
        setup();
}
void init()
{
        add_action("do_go","go"); 
} 
int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
} 
