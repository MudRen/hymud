 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @long
̫�����ڽ��ϣ�·�����Ž�⡣����ͨ��С������ģ������ǵ��̣��Ƽҡ��ֵ�
�����ǳ´��ĵĳ��ׯ�������м������ӣ�����������д�š���ˮ����ϸ�У�������
�롱������С���Ϻ��ټ����ϵ��εĵ���֮һ��
long

        );
        set("exits", ([ 
        "east" : __DIR__"road2",
        "west" : __DIR__"road4",
        "north": __DIR__"silkshop",
        "south": __DIR__"endeyuan",
        ]));
        set("objects", ([
//         __DIR__"npc/mahuihui":     1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1120);
        set("coor/y",180);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
