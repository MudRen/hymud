 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
һ�������ʯ�����ɵĵ�·�����������������ʪ��ɽ���ﾹȻ����
�Ứ����˵��Ļ���ʯ��ӳ�������˸������Ĺ�â��Ϊ���ɽ��ƽ��
�˼������ص�ɫ�ʡ�
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"court3",
                "westup" : __DIR__"court1",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
