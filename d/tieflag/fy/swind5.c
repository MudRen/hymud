 inherit ROOM;
void create()
{
        set("short", "���ű�");
        set("long", @LONG
������ɢ���Ű������������ա��ֵ����ߵ�������Զ����������˵���������
�����Ƴ�ʱ���̣��������ˣ��ҿ����������鵤��ҩ��������������������еĽ�
�Ҿ������͵ġ������õĶ������Ϲ�Ǯׯ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sgate",
  "north" : __DIR__"swind4",
  "east" : __DIR__"nanbank",
  "west" : __DIR__"pusheng",
]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
