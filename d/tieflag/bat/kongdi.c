 inherit ROOM;
 
void create()
{
        set("short", "�յ�");
        set("long",@LONG
����һƬ�յ�,���ܶ�����ʯ,�Ӳݴ�����������һ��ɽ����
LONG);
        set("exits", ([
        "northup"   : __DIR__"renjiandao1",
        "east" : __DIR__"anbian",
    ]) );
        set("objects", ([
            __DIR__"npc/dizi": 1+random(2),
        ]) );
        set("outdoors", "bat");
        set("coor/x",3290);
        set("coor/y",0);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}    
