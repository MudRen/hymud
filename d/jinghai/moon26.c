// Room: /d/jinghai/moon26.c

inherit ROOM;

void create()
{
	set("short", "ս���װ���");
	set("long", @LONG
���ļ����Ͼ��Ǽ�ʸ��ʯ���µİ߲��ۼ����װ�һ��վ��
һ�ź��ˮ�£���Ȼ����ζ��������ǻ���վ�ñ�ֱ����������
������ˮկ���ǿ���Щ��һ��һ��ƴ�����������ģ��ں��ϣ���
��˭�������������ǵ�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"moon16",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
