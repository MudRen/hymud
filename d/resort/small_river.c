 inherit ROOM;
void create()
{
        set("short", "С����ˮ");
        set("long", @LONG
һ���峺��СϪ�Ϻ����һ��ľ�š��ŵ��Ǳ���һƬïʢ�����֡�
��������÷������ӳ֮�У�һ�����ɵ�ׯԺ�������֡�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gate",
  "east" : __DIR__"another_sky",
]));
        set("outdoors", "resort"); 
        set("coor/x",-1230);
        set("coor/y",30);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}   
