// Room: /d/jinghai/zhuque7.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
���ǿ����Ե��᷿���ݽǰڷ���һ��С�輸��������ͩľ��
������û�б��ʲô��ʲ�ˡ���Ȼ�ܼ��ӵ���ɨ��һ����Ⱦ��һ
�����ź���ɫ��ȹ����Ů���ڲ��Բ�ߣ������������æ���ߵ�
������ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhuque9",
  "northeast" : __DIR__"zhuque6",
]));
        set("objects",([
       __DIR__"npc/shinv1.c" : 1,
]));


	setup();
	replace_program(ROOM);
}
