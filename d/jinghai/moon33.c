// Room: /d/jinghai/moon33.c

inherit ROOM;

void create()
{
	set("short", "���ֺ��η�");
	set("long", @LONG
������һ��������ʪ��Сʯ�ң�ֻ��һյС�͵Ƹ�����ʯ��
�Ϸ�������տ���Ҳ��ֻ�м����Ʋ�ϯ���ڵ��ϡ����ﳱʪ����
��������̦�����Ӷ���������һ���ִܴ��������������������
���ˡ����ƣ�����صò����ط����Ƿ��ӡ��ſ��Ϲ�һ��Сľ��
����д�� [��]��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"moon31",
]));
        set("objects",([
//        __DIR__"npc/qiufan1" : 1,
]));



	setup();
	replace_program(ROOM);
}
