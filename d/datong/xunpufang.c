// Room: /open/dt/xunpufang.c

inherit ROOM;

void create()
{
	set("short", "Ѳ����");
	set("long", @LONG
���ڴ�ͬ������֮�����أ�����Ѳ���ǵĲ�����Ҳ�����꣬ÿ
�춼Ҫץһ���ڽ�ͷ��ܵ�������������������Ҳ���������ˣ�
�����ǵ�˵��ֻ�����������ն��ѣ�Ѳ���Ƕ���ﰮ���µ�������
Ҳͷ�۵ý���ץ�ɣ�����ȴʵû��ɦ�Ź�һ���̿ͣ���ץ�ɣ�����
�����ڽ�ͷ��ȭŪ��Ҳʵ�ڲ��񻰡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tanhuanglu2",
]));

	setup();
	replace_program(ROOM);
}
