// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��Բ����������������¥����˵�����˲�֪�����˲�����������ѧʿ��
�ε��ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ��麣�ڵ�
�ѻ����Ӵ�����¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ�����
�ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG );
	set("exits", ([
		"west" : __DIR__"beidajie2",
		"up" : __DIR__"zuixianlou2",
	]));
set("roomif","$botten#�鿴|����:list|buy <��Ʒѡȡ>$#");

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
