 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�ƽ��ǽ�ڹ�Ȼ��֮�ƶ����ֳ��˵��Ż����˻�δ��ȥ������
һƬ�Ի͵Ĺ����˳��������ɫ��ǽ�ں󣬾���Ȼȫ�����鱦��
��������鱦���κ������ζ��벻��������ô����鱦�� 
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
