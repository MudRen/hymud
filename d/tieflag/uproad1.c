 // searoad.c
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
С·�������۷���ɽ�壬һ·�ϵ�������ɽ���У�����������ͷ׵Ļ��䡣
��ľ�䣬����䣬��ʱ���Ƽ�̨ͤ¥��������Ӱ����������һȺ��Ů����������
����ɽ�С�
LONG
        );
        set("objects",([
                __DIR__"npc/qinggirl" : 1,
                __DIR__"npc/qinggirl1" : 1,
        ]) );
        set("exits", ([ 
                "southeast" : __DIR__"uproad2",
                "southwest" : __DIR__"uproad0",
        ]));
        set("outdoors", "tieflag");
        set("coor/x",1980);
        set("coor/y",-190);
        set("coor/z",0);
        setup();
}  
