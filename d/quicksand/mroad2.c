 inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ�������߳�����Сɽ·����Ȼ����ȴ�ǹ�һ����ͨ�С�С·
˳��ɽ�н�Ϊƽ̹�ش�����������չ��������һ�����ʵľ��¡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mroad",
  
  "south" : __DIR__"cliff",
]));
        set("outdoors", "quicksand"); 
        set("coor/x",-1130);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
