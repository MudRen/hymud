 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����Ħ��������Ե����Ҿ��������������ҵ����壬ɽ�嶸��
�������ɮ���ڴ��й�������ɽ�����󣬰�����������������֮��
�����ʺϲ�����
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"damo",
  //"north" : __DIR__"qingliang2",
]));
        set("outdoors", "songshanfy");
        set("coor/x",-240);
        set("coor/y",420);
        set("coor/z",80);

        setup();
        //replace_program(ROOM);
}
