// Room: /d/xiangyang/dangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǽ�Զ�������ĵ��̣�����������棬һ��д�š���
���̡��ĸ����ֵĺ��ң������߳߸ߵ���̴ľ�Ĺ�̨��ĥ�ù�
�����ˣ���һ��ȥ����һ��ѹ�ֺͱ���ĸо�����̨����ϰ�
��ͷҲ��̧��ֻ�˲��������̣���̨�Ϸ�����һ�黨ľ����
(paizi) ���ݽַ���˵���浱�̸��ļۻ�����������ҴӲ�
�ʻ������������˻���ʲô���գ���������ܲ���
LONG );
	set("item_desc", ([
		"paizi" : "
������Ը���Ų���Ƿ��\n",
	]));
	
set("roomif","$botten#��|��|��|����|�鿴����|�鿴�鼮|�鿴����|�鿴����:sell <��Ʒ>|buy <��Ʒ>|redeem <��Ʒ>|value <��Ʒ>|list armor|list book|list misc|list weapon$#");

	
	set("no_fight", 1);
	set("no_beg", 1);
	set("exits", ([
		"north" : __DIR__"westjie1",
		"south" : "quest/skills2/wakuang/shanhang",
	]));
	set("objects", ([
		__DIR__"npc/qiuhang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

