 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��̶");
        set("long", @LONG
̶��ɲ�����״������ɫ��̶ˮ�������ף�̶�ߺ����̹ǣ�һ����������ˮ��
����̶��������һ�㱡���İ�ɫ������̶�ߵ�ʯͷ�������ˣ�ʯ���г���һЩ��
֪����ֲ�
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"jiulong",
        ]));
    set("outdoors", "huangshan");
    set("coor/x",-560);
    set("coor/y",-470);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}  
