 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ϊ�����֣�ΪŮ������������������Ҳ�ͻķ��ˣ�����
���ʯ���ɴ���������ˡ����ж�����ġ���������������һ��������
������ɮ�ڳ��۱����ر��������о������б��ģ�������ۡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bei4",
]));
        set("objects", ([
                __DIR__"npc/bookmonk" : 1,
       ]) );
        set("coor/x",-180);
        set("coor/y",180);
        set("coor/z",40);
        setup();
        replace_program(ROOM);
}       
