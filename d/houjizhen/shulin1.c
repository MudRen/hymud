// shulin1.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
����С�򱱱ߵ�һƬ���֣����о����ĵģ������Ի���һ�����������
����������ﾭ����Ұ�޳�û������������䣬ң��ͺ�,��Ϊ��ž���
���������˼������ء�
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
            "south" : "/d/xuzhou/xiaolu1",
	    "west" : __DIR__"shulin2",
          ]));

	setup();
	replace_program(ROOM);
}   