// houting.c
inherit ROOM;
void create()
{
	set("short", "�����̺���");
	set("long", @LONG
���������̵����³���--Ǳ����.������С,ǰ�������Ŵ�����,
���߰������С��.
LONG );
	set("exits", ([
		"south" : __DIR__"dating",
		"north" : __DIR__"midao",
	]));
set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects", ([
		CLASS_D("shenlong")+"/yin": 1,
           "quest/menpai/shenlong/shi" : 1,
"/d/shenlong/obj/shenshe" : 2,
	]));
	set("outdoors","shenlong");
	setup();
	replace_program(ROOM);
}

