 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
���������������ϣ�˿�첻¶����Ϊ�ڴ˹�����һ��������Ԫ��ĵز�
�������еزؾ��������Ĵ�˫�䣬̻ǰ�أ�������װ����֮�ϡ�����
ׯ�ϡ�
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou5",
  "down" : __DIR__"zhonglou3",
]));
        set("coor/x",-190);
        set("coor/y",200);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}     
