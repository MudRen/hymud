inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
�㴩���̼ұ��ĺ�Ժ������һ����ͤǰ����ͤ����ɫ������
�ɡ����˻�ͤ����һ�����ĵĻ��������������橣���������ʯ
��������̦���Ե�ƽ���������С�
LONG);
	set("exits", ([
		"west"  : __DIR__"shang_houyuan",
	]));
	        set("objects", ([
                __DIR__"npc/shang2" : 3,
        ]));
	setup();
	replace_program(ROOM);
}
