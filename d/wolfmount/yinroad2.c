 inherit ROOM;
void create ()
{
        set ("short", "����С·");
        set ("long", @LONG
����һ��������ʪ��С·��λ�ڳ����֮���ϣ���Χɢ����һЩ��ԫ�ϱڣ�·
���Ӳݴ��������ڹٸ����ٹ���������ΰ�����ʮ�ֺá������ǳ��ƵĻ�ɫ����
��һ˿������
LONG);
        set("exits", ([ //sizeof() == 4
                "east" : __DIR__"yinroad1",
                "south" : __DIR__"yinroad3",
        ]));
       set("outdoors", "wolfmount");
        set("type", "road");
        set("coor/x",-650);
        set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
