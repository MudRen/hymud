// Room: /d/jinghai/moon34.c

inherit ROOM;

void create()
{
	set("short", "�̷�");
	set("long", @LONG
�õ����ƺ�����һ��Ҳ�����ݣ�һ������͸е�һ����ɭɭ
��Ѫ��֮��ֱ�����ı�������θһ������������ǿѹסŻ
�µĸо�ɨ����һȦ������������˸��ֽв������ӵĿֲ��̾ߣ�
�����϶����������������ǵ����õģ����ǸϿ��뿪����ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"moon30",
]));

	setup();
	replace_program(ROOM);
}
