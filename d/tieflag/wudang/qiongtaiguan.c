 inherit ROOM;
void create()
{
        set("short", "��̨��");
        set("long", @LONG
��̨���ַ�Ϊ��̨�Ϲۡ��йۺ��¹ۡ��Ϲ۽С������̨������
�۽С�������̨�����¹۽С�������̨�����ڵ��ز�Զ���ͱ�����һ
ʯ������Ի��̫������
LONG
        );
        set("exits", ([
                "north" : __DIR__"dishuiyan",
                "south" : __DIR__"wall",
        ]));
        set("objects", ([
                __DIR__"npc/taoist5" : 1,
                __DIR__"npc/taoist_2" : 1,
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",110);
        set("coor/y",-150);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}     
