// Room: /open/dt/chensihuojia.c

inherit ROOM;

void create()
{
	set("short", "��˼����");
	set("long", @LONG
Ļ��ʦү��˼����λ�����ˣ������ŷ����֮�к����С�
������ԡ�����˵����˵�ٸ��ֲٰ�����ɱ��Ȩ��ʦү���֮��
�������أ���������ռ����������Լӿ��ѣ�����ʹ֮����������
��֮�ڹ����о��ˣ���֮������������Ч��������ˣ���λ��
ʦү��Ȼ�е��̰�ƣ���Ϊ���гƹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hongchanglu6",
]));

	setup();
	replace_program(ROOM);
}
