// Room: /d/jinghai/jhd8.c

inherit ROOM;

void create()
{
	set("short", "��ǰ�յ�");
	set("long", @LONG
����һƬ��ʯ�̳ɵ�СԺ�䡣֮���Խ���Ժ������Ϊ������
���޴�ĺ�ɼ����Χ��������һ��С·���ѵ�û����۽��ӵİ�
״���У���Ψһû�б���ɼռ�ݵ�������Ǿ��������ĸ�ۡ����
֮���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"jhd7",
  "west" : __DIR__"jhd9",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
