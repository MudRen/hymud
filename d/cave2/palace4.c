 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�ƿ��ţ����Ǽ仨�������õ����룬�������ӣ���������ֻ����
ɫ�Ĵ��룬������ֻ�յú��ļ�������������ϣ����ż����ˡ�
�⼸����Ȼ�������ˣ�������ȴ�ֺ�Ů�����ƣ�ÿ���˶��������
������� 
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"bedroom2",
                "south" : __DIR__"palace3",
                "east" : __DIR__"corridor",
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
