// Room: some place in ��ţ����
// hill.c

inherit ROOM;

void create()
{
  set ("short", "ʨ�չ�");
  set ("long", @LONG
�����ǣ�����ʨ�չ���ʨ�����������ǰ������ǹ�����������ţ�����
��С��ŮҲ���������˸ɾ�������϶������Ľ�ɽ�������Щ���֡�
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill1",
"south" : "/d/qujing/pansi/ling1",
]));

        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/xiaozuanfeng" : 1]));
        set("no_clean_up", 0);
	set("outdoors", "xy28");
        setup();
        replace_program(ROOM);
}

