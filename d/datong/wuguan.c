// Room: /open/dt/wuguan.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��ͬ�ش��߹أ�������ǿ������ͬ�˲�����Ůû�в�����
���ġ�������ƽʱ�����������ϰ��������������ֽ���Ҳ��
���������д���ԣ����Էǳ������֡���ݵ�������һ��Ц����
�����ӣ���û���˿����������˶��ֹ��У�����Ҷ���Ϊ����һ
����ز�¶�����ָ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu4",
]));

	setup();
	replace_program(ROOM);
}
