 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ұ�ɫ��������������ʮɫ��������Ŀ����Ȼ��ȥ���ַ�
������һ���ء���ϸһ�����ŷ����⡰���ء���������������ɫ��
ͬ����С�����Сƿ�ӣ�ÿһ��ƿ�ӵ���ʽ������úܡ�
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
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
