// Room: /d/jinghai/moon18.c

inherit ROOM;

void create()
{
	set("short", "ɽկ�ͷ�");
	set("long", @LONG
������һ���ª��С�ͷ�������կ�п�������ʱ��ס������
�����ڰ���򵥣�ֻ��ľ����̨���ʹ�ľ[����]�������衣��Ϊ
�������˴�ɨ�����ڷǳ��ɾ����ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"moon8",
]));

        set("objects",([
        __DIR__"npc/guan3" : 1,
]));


	setup();
	replace_program(ROOM);
}
